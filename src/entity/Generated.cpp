#ifndef ROGUEGAME_CAMERA_H
#define ROGUEGAME_CAMERA_H
#include <map>
#include <string>
#include <iostream>
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
	T* EntityManager::AddComponent(Entity e) {
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
	T* EntityManager::AddComponent(unsigned int e) {
		return EntityManager::AddComponent<T>(EntityManager::AllEntities[e]);
	}

	template<typename T>
	T* EntityManager::GetComponent(Entity e) {
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
	T* EntityManager::GetComponent(unsigned int e) {
		return EntityManager::GetComponent<T>(EntityManager::AllEntities[e]);
	}

	void EntityManager::UpdateEntities() {
		for (auto kp : TransformComponents) {
			Update_Transform(kp.first, kp.second);
		}
		for (auto kp : MeshRenderers) {
			Update_MeshRender(kp.first, kp.second);
		}
	}

	template TransformComponent* EntityManager::GetComponent<TransformComponent>(unsigned int e);
	template TransformComponent* EntityManager::GetComponent<TransformComponent>(Entity e);
	template TransformComponent* EntityManager::AddComponent<TransformComponent>(unsigned int e);
	template TransformComponent* EntityManager::AddComponent<TransformComponent>(Entity e);
	template Camera* EntityManager::GetComponent<Camera>(unsigned int e);
	template Camera* EntityManager::GetComponent<Camera>(Entity e);
	template Camera* EntityManager::AddComponent<Camera>(unsigned int e);
	template Camera* EntityManager::AddComponent<Camera>(Entity e);
	template MeshRenderer* EntityManager::GetComponent<MeshRenderer>(unsigned int e);
	template MeshRenderer* EntityManager::GetComponent<MeshRenderer>(Entity e);
	template MeshRenderer* EntityManager::AddComponent<MeshRenderer>(unsigned int e);
	template MeshRenderer* EntityManager::AddComponent<MeshRenderer>(Entity e);
	template Material* EntityManager::GetComponent<Material>(unsigned int e);
	template Material* EntityManager::GetComponent<Material>(Entity e);
	template Material* EntityManager::AddComponent<Material>(unsigned int e);
	template Material* EntityManager::AddComponent<Material>(Entity e);

}	//TransformComponent
	//{'type': 'vec3', 'name': 'Position'}
	//{'type': 'quat', 'name': 'Rotation'}
	//{'type': 'vec3', 'name': 'Scale'}
	//Camera
	//{'type': 'ViewId', 'name': 'View'}
	//{'type': 'int', 'name': 'Width'}
	//{'type': 'int', 'name': 'Height'}
	//{'type': 'FrameBufferHandle', 'name': 'FrameBuffer'}
	//{'type': 'TextureHandle', 'name': 'TextureHandle'}
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