#ifndef ROGUEGAME_CAMERA_H
#define ROGUEGAME_CAMERA_H
#include <map>
#include <string>
#include <iostream>
#include "../editor/Logger.h"
#include "../editor/ImGuiUtils.h"
#include "Entities.h"
using namespace Editor;
#ifdef __GNUG__ // GCC
 
 #include <cxxabi.h> 
#include <cstdlib> 

static std::string readable_name( const char* mangled_name )
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
	static std::map<unsigned int, Transform*> Transforms;
	static std::map<unsigned int, Camera*> Cameras;
	static std::map<unsigned int, MeshRenderer*> MeshRenderers;
	static std::map<unsigned int, Material*> Materials;

	template<typename T>
	T* EntityManager::AddComponent(Entity e) {
		e = AllEntities[e.Id];
		if (std::is_same<T, Transform>::value) {
			auto nc = new Transform();
			Transforms[e.Id] = nc;
			nc->Entity = e;
			e.Components.push_back(nc);
			AllEntities[e.Id] = e;
			return (T*)nc;
		}
		else if (std::is_same<T, Camera>::value) {
			auto nc = new Camera();
			Cameras[e.Id] = nc;
			nc->Entity = e;
			e.Components.push_back(nc);
			AllEntities[e.Id] = e;
			return (T*)nc;
		}
		else if (std::is_same<T, MeshRenderer>::value) {
			auto nc = new MeshRenderer();
			MeshRenderers[e.Id] = nc;
			nc->Entity = e;
			e.Components.push_back(nc);
			AllEntities[e.Id] = e;
			return (T*)nc;
		}
		else if (std::is_same<T, Material>::value) {
			auto nc = new Material();
			Materials[e.Id] = nc;
			nc->Entity = e;
			e.Components.push_back(nc);
			AllEntities[e.Id] = e;
			return (T*)nc;
		}
		else {
			std::cout << std::string("Unhandled component:") << typeid(T).name() << std::endl;
			return nullptr;
		}
	}

	template<typename T>
	T* EntityManager::AddComponent(unsigned int e) {
		return EntityManager::AddComponent<T>(EntityManager::AllEntities[e]);
	}

	template<typename T>
	T* EntityManager::GetComponent(Entity e) {
		if (std::is_same<T, Transform>::value) {
			return (T*)Transforms[e.Id];
		}
		else if (std::is_same<T, Camera>::value) {
			return (T*)Cameras[e.Id];
		}
		else if (std::is_same<T, MeshRenderer>::value) {
			return (T*)MeshRenderers[e.Id];
		}
		else if (std::is_same<T, Material>::value) {
			return (T*)Materials[e.Id];
		}
		else {
			std::cout << std::string("Unhandled component:") << typeid(T).name() << std::endl;
			return nullptr;
		}
	}

	template<typename T>
	T* EntityManager::GetComponent(unsigned int e) {
		return EntityManager::GetComponent<T>(EntityManager::AllEntities[e]);
	}

	void EntityManager::UpdateEntities() {
		for (auto kp : Transforms) {
			Update_Transform(kp.first, kp.second);
		}
		for (auto kp : MeshRenderers) {
			Update_MeshRender(kp.first, kp.second);
		}
	}

	void EntityManager::ImGuiEditableComponent(Component * comp) {
		auto transform = dynamic_cast<Transform*>(comp);
		if (transform) {
			ImGuiUtils::InputField_vec3("Position", &transform->Position);
			ImGuiUtils::InputField_quat("Rotation", &transform->Rotation);
			ImGuiUtils::InputField_vec3("Scale", &transform->Scale);
		}
		auto camera = dynamic_cast<Camera*>(comp);
		if (camera) {
			ImGuiUtils::InputField_ViewId("View", &camera->View);
			ImGuiUtils::InputField_int("Width", &camera->Width);
			ImGuiUtils::InputField_int("Height", &camera->Height);
			ImGuiUtils::InputField_FrameBufferHandle("FrameBuffer", &camera->FrameBuffer);
			ImGuiUtils::InputField_TextureHandle("TextureHandle", &camera->TextureHandle);
			ImGuiUtils::InputField_CameraMode("Mode", &camera->Mode);
			ImGuiUtils::InputField_float("FieldOfView", &camera->FieldOfView);
			ImGuiUtils::InputField_float("Near", &camera->Near);
			ImGuiUtils::InputField_float("Far", &camera->Far);
		}
		auto meshrenderer = dynamic_cast<MeshRenderer*>(comp);
		if (meshrenderer) {
			ImGuiUtils::InputField_ModelHandle("Model", &meshrenderer->Model);
		}
		auto material = dynamic_cast<Material*>(comp);
		if (material) {
			ImGuiUtils::InputField_ProgramHandle("Shader", &material->Shader);
			ImGuiUtils::InputField_TextureHandle("Texture", &material->Texture);
			ImGuiUtils::InputField_UniformHandle("Uniforms", &material->Uniforms);
		}
	}

	template Transform* EntityManager::GetComponent<Transform>(unsigned int e);
	template Transform* EntityManager::GetComponent<Transform>(Entity e);
	template Transform* EntityManager::AddComponent<Transform>(unsigned int e);
	template Transform* EntityManager::AddComponent<Transform>(Entity e);
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

}	//Transform
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
	//{'type': 'float', 'name': 'FieldOfView'}
	//{'type': 'float', 'name': 'Near'}
	//{'type': 'float', 'name': 'Far'}
	//MeshRenderer
	//{'type': 'ModelHandle', 'name': 'Model'}
	//Material
	//{'type': 'ProgramHandle', 'name': 'Shader'}
	//{'type': 'TextureHandle', 'name': 'Texture'}
	//{'type': 'UniformHandle', 'name': 'Uniforms'}


#endif