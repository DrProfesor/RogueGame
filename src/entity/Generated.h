#ifndef ROGUEGAME_CAMERA_H
#define ROGUEGAME_CAMERA_H
#include <map>
#include <string>
#include "../dev/Logger.h"
#include "Entities.h"
#ifdef __GNUG__ // GCC
 
 #include <cxxabi.h> 
#include <cstdlib> 

static const char * readable_name( const char* mangled_name )
{
    int status ;
    char* temp = __cxxabiv1::__cxa_demangle( mangled_name, nullptr, nullptr, &status ) ;
    if(temp)
    {
        std::string result(temp) ;
        std::free(temp) ;
        return result.c_str() ;
    }
    else return mangled_name ;
}

#else // not GCC

inline std::string readable_name( const char* mangled_name ) { return mangled_name ; }

#endif // __GNUG__

namespace Entities {
	static std::map<unsigned int, TransformComponent*> TransformComponents;
	static std::map<unsigned int, Camera*> Cameras;
	static std::map<unsigned int, MeshRenderer*> MeshRenderers;
	static std::map<unsigned int, Material*> Materials;

	template<typename T>
	T* AddComponent(Entity e) {
		auto name = readable_name(typeid(T).name());
		auto sName = name.substr(name.find('::') + 2, name.size() - 1);
		auto comparableName = sName.c_str();
		if (std::strcmp(comparableName, "TransformComponent") == 0) {
			auto nc = new TransformComponent();
			TransformComponents[e.Id] = nc;
			nc->Entity = e;
			return (T*)nc;
		}
		else if (std::strcmp(comparableName, "Camera") == 0) {
			auto nc = new Camera();
			Cameras[e.Id] = nc;
			nc->Entity = e;
			return (T*)nc;
		}
		else if (std::strcmp(comparableName, "MeshRenderer") == 0) {
			auto nc = new MeshRenderer();
			MeshRenderers[e.Id] = nc;
			nc->Entity = e;
			return (T*)nc;
		}
		else if (std::strcmp(comparableName, "Material") == 0) {
			auto nc = new Material();
			Materials[e.Id] = nc;
			nc->Entity = e;
			return (T*)nc;
		}
		else {
			std::cout << std::string("Unhandled component:") << sName << std::endl;
			return nullptr;
		}
	}

	template<typename T>
	T* AddComponent(unsigned int e) {
		return AddComponent<T>(Entities::AllEntities[e]);
	}

	template<typename T>
	T* GetComponent(Entity e) {
		auto name = readable_name(typeid(T).name());
		auto sName = name.substr(name.find('::') + 2, name.size() - 1);
		auto comparableName = sName.c_str();
		if (std::strcmp(comparableName, "TransformComponent") == 0) {
			return (T*)TransformComponents[e.Id];
		}
		else if (std::strcmp(comparableName, "Camera") == 0) {
			return (T*)Cameras[e.Id];
		}
		else if (std::strcmp(comparableName, "MeshRenderer") == 0) {
			return (T*)MeshRenderers[e.Id];
		}
		else if (std::strcmp(comparableName, "Material") == 0) {
			return (T*)Materials[e.Id];
		}
		else {
			std::cout << std::string("Unhandled component:") << sName << std::endl;
			return nullptr;
		}
	}

	template<typename T>
	T* GetComponent(unsigned int e) {
		return GetComponent<T>(Entities::AllEntities[e]);
	}

	using namespace Entities;
	void UpdateEntities() {
		for (auto kp : TransformComponents) {
			Update_Transform(kp.first, kp.second);
		}
		for (auto kp : MeshRenderers) {
			Update_MeshRender(kp.first, kp.second);
		}
	}


}	//TransformComponent
	//{'type': 'vec3', 'name': 'Position'}
	//{'type': 'quat', 'name': 'Rotation'}
	//{'type': 'vec3', 'name': 'Scale'}
	//Camera
	//{'type': 'ViewId', 'name': 'View'}
	//{'type': 'int', 'name': 'Width'}
	//{'type': 'int', 'name': 'Height'}
	//{'type': 'CameraMode', 'name': 'Mode'}
	//{'type': '//', 'name': 'persp'}
	//{'type': 'float', 'name': 'FieldOfView'}
	//{'type': 'float', 'name': 'Near'}
	//{'type': 'float', 'name': 'Far'}
	//MeshRenderer
	//{'type': 'ModelHandle', 'name': 'Model'}
	//Material
	//{'type': 'bgfx::ProgramHandle', 'name': 'Shader'}
	//{'type': 'bgfx::TextureHandle', 'name': 'Texture'}
	//{'type': 'bgfx::UniformHandle', 'name': 'Uniforms'}


#endif