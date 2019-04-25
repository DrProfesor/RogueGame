#ifndef ROGUEGAME_CAMERA_H
#define ROGUEGAME_CAMERA_H

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "../utils/ImGuiUtils.h"
#include "../utils/Json.h"
#include "../utils/JsonExtensions.h"
#include "../utils/MapUtils.h"
#include "../physics/Physics.h"
#include "Entities.h"

using namespace Utils;
using namespace Physics;

namespace Entities {
	static std::map<unsigned int, Transform*> Transforms;
	static std::map<unsigned int, Camera*> Cameras;
	static std::map<unsigned int, MeshRenderer*> MeshRenderers;
	static std::map<unsigned int, Material*> Materials;
	static std::map<unsigned int, Collider*> Colliders;

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
		else if (std::is_same<T, Collider>::value) {
			auto nc = new Collider();
			Colliders[e.Id] = nc;
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
		else if (std::is_same<T, Collider>::value) {
			return (T*)Colliders[e.Id];
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

	void EntityManager::Destroy(Entity e) {
		if (contains(Transforms, e.Id)) {
			auto comp = Transforms[e.Id];
			Transforms.erase(e.Id);
			delete comp;
		}
		if (contains(Cameras, e.Id)) {
			auto comp = Cameras[e.Id];
			Cameras.erase(e.Id);
			delete comp;
		}
		if (contains(MeshRenderers, e.Id)) {
			auto comp = MeshRenderers[e.Id];
			MeshRenderers.erase(e.Id);
			delete comp;
		}
		if (contains(Materials, e.Id)) {
			auto comp = Materials[e.Id];
			Materials.erase(e.Id);
			delete comp;
		}
		if (contains(Colliders, e.Id)) {
			auto comp = Colliders[e.Id];
			Colliders.erase(e.Id);
			delete comp;
		}
		AllEntities.erase(e.Id);
	}

	void EntityManager::UpdateEntities() {
	}

	template Transform* EntityManager::GetComponent<Transform>(unsigned int e);
	template Camera* EntityManager::GetComponent<Camera>(unsigned int e);
	template MeshRenderer* EntityManager::GetComponent<MeshRenderer>(unsigned int e);
	template Material* EntityManager::GetComponent<Material>(unsigned int e);
	template Collider* EntityManager::GetComponent<Collider>(unsigned int e);
	template Transform* EntityManager::GetComponent<Transform>(Entity e);
	template Camera* EntityManager::GetComponent<Camera>(Entity e);
	template MeshRenderer* EntityManager::GetComponent<MeshRenderer>(Entity e);
	template Material* EntityManager::GetComponent<Material>(Entity e);
	template Collider* EntityManager::GetComponent<Collider>(Entity e);
	template Transform* EntityManager::AddComponent<Transform>(unsigned int e);
	template Camera* EntityManager::AddComponent<Camera>(unsigned int e);
	template MeshRenderer* EntityManager::AddComponent<MeshRenderer>(unsigned int e);
	template Material* EntityManager::AddComponent<Material>(unsigned int e);
	template Collider* EntityManager::AddComponent<Collider>(unsigned int e);
	template Transform* EntityManager::AddComponent<Transform>(Entity e);
	template Camera* EntityManager::AddComponent<Camera>(Entity e);
	template MeshRenderer* EntityManager::AddComponent<MeshRenderer>(Entity e);
	template Material* EntityManager::AddComponent<Material>(Entity e);
	template Collider* EntityManager::AddComponent<Collider>(Entity e);
	template <> inline void EntityManager::AddComponent(Entity e, Transform & comp) { e = AllEntities[e.Id]; auto nc = new Transform(comp); Transforms[e.Id] = nc; nc->Entity = e; e.Components.push_back(nc); AllEntities[e.Id] = e; } 
	template <> inline void EntityManager::AddComponent(Entity e, Camera & comp) { e = AllEntities[e.Id]; auto nc = new Camera(comp); Cameras[e.Id] = nc; nc->Entity = e; e.Components.push_back(nc); AllEntities[e.Id] = e; } 
	template <> inline void EntityManager::AddComponent(Entity e, MeshRenderer & comp) { e = AllEntities[e.Id]; auto nc = new MeshRenderer(comp); MeshRenderers[e.Id] = nc; nc->Entity = e; e.Components.push_back(nc); AllEntities[e.Id] = e; } 
	template <> inline void EntityManager::AddComponent(Entity e, Material & comp) { e = AllEntities[e.Id]; auto nc = new Material(comp); Materials[e.Id] = nc; nc->Entity = e; e.Components.push_back(nc); AllEntities[e.Id] = e; } 
	template <> inline void EntityManager::AddComponent(Entity e, Collider & comp) { e = AllEntities[e.Id]; auto nc = new Collider(comp); Colliders[e.Id] = nc; nc->Entity = e; e.Components.push_back(nc); AllEntities[e.Id] = e; } 
	template <> std::map<unsigned int, Transform*> EntityManager::GetComponents() { return Transforms; }
	template <> std::map<unsigned int, Camera*> EntityManager::GetComponents() { return Cameras; }
	template <> std::map<unsigned int, MeshRenderer*> EntityManager::GetComponents() { return MeshRenderers; }
	template <> std::map<unsigned int, Material*> EntityManager::GetComponents() { return Materials; }
	template <> std::map<unsigned int, Collider*> EntityManager::GetComponents() { return Colliders; }
	
	void EntityManager::ImGuiEditableComponent(Component * comp) {
		auto transform = dynamic_cast<Transform*>(comp);
		if (transform) {
			ImGuiUtils::InputField_vec3("Position", &transform->Position, comp->Entity);
			ImGuiUtils::InputField_quat("Rotation", &transform->Rotation, comp->Entity);
			ImGuiUtils::InputField_vec3("Scale", &transform->Scale, comp->Entity);
		}
		auto camera = dynamic_cast<Camera*>(comp);
		if (camera) {
			ImGuiUtils::InputField_ViewId("View", &camera->View, comp->Entity);
			ImGuiUtils::InputField_int("Width", &camera->Width, comp->Entity);
			ImGuiUtils::InputField_int("Height", &camera->Height, comp->Entity);
			ImGuiUtils::InputField_FrameBufferHandle("FrameBuffer", &camera->FrameBuffer, comp->Entity);
			ImGuiUtils::InputField_TextureHandle("TextureHandle", &camera->TextureHandle, comp->Entity);
			ImGuiUtils::InputField_CameraMode("Mode", &camera->Mode, comp->Entity);
			ImGuiUtils::InputField_float("FieldOfView", &camera->FieldOfView, comp->Entity);
			ImGuiUtils::InputField_float("Near", &camera->Near, comp->Entity);
			ImGuiUtils::InputField_float("Far", &camera->Far, comp->Entity);
		}
		auto meshrenderer = dynamic_cast<MeshRenderer*>(comp);
		if (meshrenderer) {
			ImGuiUtils::InputField_string("ModelId", &meshrenderer->ModelId, comp->Entity);
			ImGuiUtils::InputField_ModelHandle("Model", &meshrenderer->Model, comp->Entity);
			ImGuiUtils::InputField_bool("Render", &meshrenderer->Render, comp->Entity);
		}
		auto material = dynamic_cast<Material*>(comp);
		if (material) {
			ImGuiUtils::InputField_vec4("Colour", &material->Colour, comp->Entity);
			ImGuiUtils::InputField_string("ShaderId", &material->ShaderId, comp->Entity);
			ImGuiUtils::InputField_ProgramHandle("Shader", &material->Shader, comp->Entity);
			ImGuiUtils::InputField_string("TextureId", &material->TextureId, comp->Entity);
			ImGuiUtils::InputField_TextureHandle("Texture", &material->Texture, comp->Entity);
			ImGuiUtils::InputField_UniformHandle("Sampler", &material->Sampler, comp->Entity);
			ImGuiUtils::InputField_UniformHandle("BaseColour", &material->BaseColour, comp->Entity);
		}
		auto collider = dynamic_cast<Collider*>(comp);
		if (collider) {
		}
	}

	
	void EntityManager::ImGui_EditableComponent(Component * comp) {
		auto transform = dynamic_cast<Transform*>(comp);
		if (transform) {
			ImGuiUtils::ImGui_Component(transform, comp->Entity);
		}
		auto camera = dynamic_cast<Camera*>(comp);
		if (camera) {
			ImGuiUtils::ImGui_Component(camera, comp->Entity);
		}
		auto meshrenderer = dynamic_cast<MeshRenderer*>(comp);
		if (meshrenderer) {
			ImGuiUtils::ImGui_Component(meshrenderer, comp->Entity);
		}
		auto material = dynamic_cast<Material*>(comp);
		if (material) {
			ImGuiUtils::ImGui_Component(material, comp->Entity);
		}
		auto collider = dynamic_cast<Collider*>(comp);
		if (collider) {
			ImGuiUtils::ImGui_Component(collider, comp->Entity);
		}
	}

	void EntityManager::ImGuiAddComponentMenuItems(Entity e) {
		if (!contains(Transforms, e.Id)) {
			if (ImGui::MenuItem("Transform")) {
				AddComponent<Transform>(e);
			}
		}
		if (!contains(Cameras, e.Id)) {
			if (ImGui::MenuItem("Camera")) {
				AddComponent<Camera>(e);
			}
		}
		if (!contains(MeshRenderers, e.Id)) {
			if (ImGui::MenuItem("MeshRenderer")) {
				AddComponent<MeshRenderer>(e);
			}
		}
		if (!contains(Materials, e.Id)) {
			if (ImGui::MenuItem("Material")) {
				AddComponent<Material>(e);
			}
		}
		if (!contains(Colliders, e.Id)) {
			if (ImGui::MenuItem("Collider")) {
				AddComponent<Collider>(e);
			}
		}
	}

	Entity EntityManager::CreateEntityFromSerialized(std::string input) {
		auto json = nlohmann::json::parse(input);
		auto entity = Instantiate();
		if (json.contains("Transform")) {
			auto newComp = json.at("Transform").get<Transform>();
			AddComponent(entity, newComp);
		}
		if (json.contains("Camera")) {
			auto newComp = json.at("Camera").get<Camera>();
			AddComponent(entity, newComp);
		}
		if (json.contains("MeshRenderer")) {
			auto newComp = json.at("MeshRenderer").get<MeshRenderer>();
			AddComponent(entity, newComp);
		}
		if (json.contains("Material")) {
			auto newComp = json.at("Material").get<Material>();
			AddComponent(entity, newComp);
		}
		if (json.contains("Collider")) {
			auto newComp = json.at("Collider").get<Collider>();
			AddComponent(entity, newComp);
		}
		return entity;
	}

	std::string EntityManager::SerializeEntity(Entity e) {
		nlohmann::json json;
		auto transformIt = Transforms.find(e.Id);
		if (transformIt != Transforms.end()) {
			json["Transform"] = *Transforms[e.Id];
		}
		auto cameraIt = Cameras.find(e.Id);
		if (cameraIt != Cameras.end()) {
			json["Camera"] = *Cameras[e.Id];
		}
		auto meshrendererIt = MeshRenderers.find(e.Id);
		if (meshrendererIt != MeshRenderers.end()) {
			json["MeshRenderer"] = *MeshRenderers[e.Id];
		}
		auto materialIt = Materials.find(e.Id);
		if (materialIt != Materials.end()) {
			json["Material"] = *Materials[e.Id];
		}
		auto colliderIt = Colliders.find(e.Id);
		if (colliderIt != Colliders.end()) {
			json["Collider"] = *Colliders[e.Id];
		}
		return json.dump();
	}


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
	//{'type': 'string', 'name': 'ModelId'}
	//{'type': 'ModelHandle', 'name': 'Model'}
	//{'type': 'bool', 'name': 'Render'}
	//Material
	//{'type': 'vec4', 'name': 'Colour'}
	//{'type': 'string', 'name': 'ShaderId'}
	//{'type': 'ProgramHandle', 'name': 'Shader'}
	//{'type': 'string', 'name': 'TextureId'}
	//{'type': 'TextureHandle', 'name': 'Texture'}
	//{'type': 'UniformHandle', 'name': 'Sampler'}
	//{'type': 'UniformHandle', 'name': 'BaseColour'}
	//Collider


#endif