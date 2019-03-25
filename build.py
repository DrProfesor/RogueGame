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
        current_component = ""

        is_update = False
        update_priority = ""
        update_comp = ""

        for line in f:
            if "}" in line:
                inside_component = False
            if inside_component:
                field = line.strip()
                field = field.replace(";", "")
                field_parts = field.split(" ")
                field_data = {"type": field_parts[0], "name": field_parts[1]}
                components[current_component].append(field_data)
            if is_component:
                is_component = False
                line = line.strip()
                parts = line.split(" ")
                component_name = parts[1]
                components[component_name] = []
                current_component = component_name
                inside_component = True
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


with open(dir_path + "/src/entity/Generated.h", 'w') as wr:
    source = "#ifndef ROGUEGAME_CAMERA_H\n#define ROGUEGAME_CAMERA_H\n"

    source += line("#include <map>")
    source += line("#include <string>")
    source += line("#include \"../dev/Logger.h\"")
    for inc, v in includes.items():
        source += line("#include \"" + inc + "\"")

    source += "" \
"#ifdef __GNUG__ // GCC\n \
\n \
#include <cxxabi.h> \n\
#include <cstdlib> \n\
\n\
static const char * readable_name( const char* mangled_name )\n\
{\n\
    int status ;\n\
    char* temp = __cxxabiv1::__cxa_demangle( mangled_name, nullptr, nullptr, &status ) ;\n\
    if(temp)\n\
    {\n\
        std::string result(temp) ;\n\
        std::free(temp) ;\n\
        return result.c_str() ;\n\
    }\n\
    else return mangled_name ;\n\
}\n\
\n\
#else // not GCC\n\
\n\
inline std::string readable_name( const char* mangled_name ) { return mangled_name ; }\n\
\n\
#endif // __GNUG__\n\n"

    source += line_indent("namespace Entities {")

    for comp, comp_data in components.items():
        source += line("static std::map<unsigned int, " + comp + "*> " + comp + "s;")

    source += "\n"
    source += line("template<typename T>")
    source += begin_proc("AddComponent", "T*", "Entity e")
    first = True
    for comp, comp_data in components.items():
        _if = ""
        if first:
            _if += "if"
            first = False
        else:
            _if = "else if"
        source += line_indent(_if + " (std::strcmp(readable_name(typeid(T).name()), \"Entities::" + comp + "\") == 0) {")
        source += line("auto nc = new " + comp + "();")
        source += line(comp + "s[e.Id] = nc;")
        source += line("return (T*)nc;")
        source += line_outdent("}")
    source += line_indent("else {")
    source += line("Logger::Log((std::string(\"Unhandled component:\") + readable_name(typeid(T).name())).c_str());")
    source += line ("return nullptr;")
    source += line_outdent("}")
    source += end_proc()

    source += line("template<typename T>")
    source += begin_proc("AddComponent", "T*", "unsigned int e")
    source += line("return AddComponent<T>(Entities::AllEntities[e]);")
    source += end_proc()

    source += line("template<typename T>")
    source += begin_proc("GetComponent", "T*", "Entity e")
    first = True
    for comp, comp_data in components.items():
        _if = ""
        if first:
            _if += "if"
            first = False
        else:
            _if = "else if"
        source += line_indent(_if + " (std::strcmp(readable_name(typeid(T).name()), \"Entities::" + comp + "\") == 0) {")
        source += line("return (T*)" + comp + "s[e.Id];")
        source += line_outdent("}")
    source += line_indent("else {")
    source += line("Logger::Log((std::string(\"Unhandled component:\") + readable_name(typeid(T).name())).c_str());")
    source += line ("return nullptr;")
    source += line_outdent("}")
    source += end_proc()

    source += line("template<typename T>")
    source += begin_proc("GetComponent", "T*", "unsigned int e")
    source += line("return GetComponent<T>(Entities::AllEntities[e]);")
    source += end_proc()

    render_procs = {}
    update_procs = {}
    for comp, fd in update_functions.items():
        if fd["priority"] == "RENDER":
            render_procs[comp] = fd
        else:
            update_procs[comp] = fd

    source += line("using namespace Entities;")
    source += begin_proc("UpdateEntities", "void", "")
    for comp, function_data in update_procs.items():
        source += line_indent("for (auto kp : " + comp + "s) {")
        source += line(function_data["func"] + "(kp.first, kp.second);")
        source += line_outdent("}")
    for comp, function_data in render_procs.items():
        source += line_indent("for (auto kp : " + comp + "s) {")
        source += line(function_data["func"] + "(kp.first, kp.second);")
        source += line_outdent("}")
    source += end_proc()

    source += "\n}"
    source += "\n\n#endif"

    wr.write(source)