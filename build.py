import os

dir_path = os.path.dirname(os.path.realpath(__file__))

components = {}
update_functions = {}
includes = {}

for root, dirs, files in os.walk(dir_path + "/src"):
    for file in files:
        filePath = root + '/' + file
        f = open(filePath, 'r')

        is_component = False
        inside_component = False
        depth = 0
        current_component_depth = 0
        current_component = ""

        is_update = False
        update_priority = ""
        update_comp = ""

        for line in f:
            if "}" in line:
                inside_component = False
                depth -= 1
            if "{" in line:
                depth += 1
            if inside_component:
                if depth != current_component_depth: continue
                if "(" in line: continue
                if "//" in line: continue

                field = line.strip()
                field = field.replace(";", "")
                field_parts = field.split(" ")

                if len(field_parts) < 2: continue

                type = field_parts[0]
                type_parts = type.split("::")
                if len(type_parts) > 1:
                    type = type_parts[len(type_parts)-1]

                field_data = {"type": type, "name": field_parts[1]}
                components[current_component].append(field_data)
            if is_component:
                is_component = False
                line = line.strip()
                parts = line.split(" ")
                component_name = parts[1]
                components[component_name] = []
                current_component = component_name
                inside_component = True
                current_component_depth = depth
            if is_update:
                is_update = False
                lineParts = line.split("(")
                lineParts = lineParts[0].split(" ")
                fun_name = lineParts[len(lineParts)-1].strip(" ")
                update_functions[update_comp] = {"func": fun_name, "priority": update_priority}
                includes[file] = True
            if "@component_update" in line:
                is_update = True
                parts = line.split("(")
                parts = parts[1].split(")")
                parts = parts[0].split(",")
                update_priority = parts[0].strip(" ")
                update_comp = parts[1].strip(" ")
            elif "@component" in line:
                is_component = True

indent_level = 0


def print_indents():
    ret = ""
    for i in range(0, indent_level):
        ret += "\t"
    return ret


def begin_proc(name, returnType, *params):
    global indent_level
    ret = ""
    ret += print_indents()
    ret += returnType + " " + name + "("
    first = True
    for param in params:
        if first:
            first = True
            ret += param
        else:
            ret += ", " + param
    ret += ") {\n"
    indent_level += 1
    return ret


def end_proc():
    global indent_level
    ret = ""
    indent_level -= 1
    ret += print_indents()
    ret += "}\n\n"
    return ret


def line(*args):
    ret = ""
    ret += print_indents()
    for arg in args:
        ret += arg
    ret += "\n"
    return ret


def line_indent(*args):
    ret = ""
    global indent_level
    ret += print_indents()
    for arg in args:
        ret += arg
    ret += "\n"
    indent_level += 1
    return ret


def line_outdent(*args):
    ret = ""
    global indent_level
    indent_level -= 1
    ret += print_indents()
    for arg in args:
        ret += arg
    ret += "\n"
    return ret


with open(dir_path + "/src/entity/Generated.cpp", 'w') as wr:
    source = "#ifndef ROGUEGAME_CAMERA_H\n#define ROGUEGAME_CAMERA_H\n\n"
    source += line("#include <map>")
    source += line("#include <string>")
    source += line("#include <iostream>")
    source += line("#include \"../utils/ImGuiUtils.h\"")
    source += line("#include \"../utils/Json.h\"")
    source += line("#include \"../utils/JsonExtensions.h\"")
    for inc, v in includes.items():
        source += line("#include \"" + inc + "\"")

    source += line("")
    source += line("using namespace Utils;")
    source += line("")

    source += line_indent("namespace Entities {")

    for comp, comp_data in components.items():
        source += line("static std::map<unsigned int, " + comp + "*> " + comp + "s;")

    source += "\n"
    source += line("template<typename T>")
    source += begin_proc("EntityManager::AddComponent", "T*", "Entity e")

    source += line("e = AllEntities[e.Id];")
    first = True
    for comp, comp_data in components.items():
        _if = ""
        if first:
            _if += "if"
            first = False
        else:
            _if = "else if"
        source += line_indent(_if + " (std::is_same<T, " + comp + ">::value) {")
        source += line("auto nc = new " + comp + "();")
        source += line(comp + "s[e.Id] = nc;")
        source += line("nc->Entity = e;")
        source += line("e.Components.push_back(nc);")
        source += line("AllEntities[e.Id] = e;")
        source += line("return (T*)nc;")
        source += line_outdent("}")
    source += line_indent("else {")
    source += line("std::cout << std::string(\"Unhandled component:\") << typeid(T).name() << std::endl;")
    source += line("return nullptr;")
    source += line_outdent("}")
    source += end_proc()

    source += line("template<typename T>")
    source += begin_proc("EntityManager::AddComponent", "T*", "unsigned int e")
    source += line("return EntityManager::AddComponent<T>(EntityManager::AllEntities[e]);")
    source += end_proc()

    source += line("template<typename T>")
    source += begin_proc("EntityManager::GetComponent", "T*", "Entity e")
    first = True
    for comp, comp_data in components.items():
        _if = ""
        if first:
            _if += "if"
            first = False
        else:
            _if = "else if"
        source += line_indent(_if + " (std::is_same<T, " + comp + ">::value) {")
        source += line("return (T*)" + comp + "s[e.Id];")
        source += line_outdent("}")
    source += line_indent("else {")
    source += line("std::cout << std::string(\"Unhandled component:\") << typeid(T).name() << std::endl;")
    source += line("return nullptr;")
    source += line_outdent("}")
    source += end_proc()

    source += line("template<typename T>")
    source += begin_proc("EntityManager::GetComponent", "T*", "unsigned int e")
    source += line("return EntityManager::GetComponent<T>(EntityManager::AllEntities[e]);")
    source += end_proc()

    render_procs = {}
    update_procs = {}
    for comp, fd in update_functions.items():
        if fd["priority"] == "RENDER":
            render_procs[comp] = fd
        else:
            update_procs[comp] = fd

    source += begin_proc("EntityManager::UpdateEntities", "void", "")
    for comp, function_data in update_procs.items():
        source += line_indent("for (auto kp : " + comp + "s) {")
        source += line(function_data["func"] + "(kp.first, kp.second);")
        source += line_outdent("}")
    for comp, function_data in render_procs.items():
        source += line_indent("for (auto kp : " + comp + "s) {")
        source += line(function_data["func"] + "(kp.first, kp.second);")
        source += line_outdent("}")
    source += end_proc()

    for comp, comp_data in components.items():
        source += line("template " + comp + "* EntityManager::GetComponent<"+comp+">(unsigned int e);")
        source += line("template " + comp + "* EntityManager::GetComponent<"+comp+">(Entity e);")
        source += line("template " + comp + "* EntityManager::AddComponent<"+comp+">(unsigned int e);")
        source += line("template " + comp + "* EntityManager::AddComponent<"+comp+">(Entity e);")

        source += line_indent("template <> inline void EntityManager::AddComponent(Entity e, " + comp + " & comp) {")
        source += line("e = AllEntities[e.Id];")
        source += line("auto nc = new " + comp + "(comp);")
        source += line(comp + "s[e.Id] = nc;")
        source += line("nc->Entity = e;")
        source += line("e.Components.push_back(nc);")
        source += line("AllEntities[e.Id] = e;")
        source += end_proc()

    source += begin_proc("EntityManager::ImGuiEditableComponent", "void", "Component * comp")
    for comp, comp_data in components.items():
        source += line("auto " + comp.lower() + " = dynamic_cast<" + comp + "*>(comp);")
        source += line_indent("if ("+comp.lower()+") {")
        for cd in comp_data:
            source += line("ImGuiUtils::InputField_" + cd["type"] + "(\"" + cd["name"] + "\", &" + comp.lower() + "->" + cd["name"] + ");")
        source += line_outdent("}")
    source += end_proc()

    source += begin_proc("EntityManager::CreateEntityFromSerialized", "void", "std::string input")
    source += line("auto json = nlohmann::json::parse(input);")
    source += line("auto entity = Instantiate();")
    for comp, comp_data in components.items():
        source += line_indent("if (json.contains(\"" + comp + "\")) {")
        source += line("auto newComp = json.at(\"" + comp + "\").get<" + comp + ">();")
        source += line("AddComponent(entity, newComp);")
        source += line_outdent("}")
    source += end_proc()

    source += begin_proc("EntityManager::SerializeEntity", "std::string", "Entity e")
    source += line("nlohmann::json json;")
    for comp, comp_data in components.items():
        source += line("auto " + comp.lower() + "It = " + comp + "s.find(e.Id);")
        source += line_indent("if (" + comp.lower() + "It != " + comp + "s.end()) {")
        source += line("json[\"" + comp + "\"] = *" + comp + "s[e.Id];")
        source += line_outdent("}")
    source += line("return json.dump();")
    source += end_proc()

    source += "\n}"

    for comp, comp_data in components.items():
        source += line("//" + comp)
        for cd in comp_data:
            source += line("//" + str(cd))

    source += "\n\n#endif"

    wr.write(source)
