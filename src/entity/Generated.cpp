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
#include "Entities.h"

using namespace Utils;

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
		AllEntities.erase(e.Id);
	}

	void EntityManager::UpdateEntities() {
		for (auto kp : Transforms) {
			Update_Transform(kp.first, kp.second);
		}
		for (auto kp : MeshRenderers) {
			Update_MeshRender(kp.first, kp.second);
		}
	}

	template Transform* EntityManager::GetComponent<Transform>(unsigned int e);
	template Camera* EntityManager::GetComponent<Camera>(unsigned int e);
	template MeshRenderer* EntityManager::GetComponent<MeshRenderer>(unsigned int e);
	template Material* EntityManager::GetComponent<Material>(unsigned int e);
	template Transform* EntityManager::GetComponent<Transform>(Entity e);
	template Camera* EntityManager::GetComponent<Camera>(Entity e);
	template MeshRenderer* EntityManager::GetComponent<MeshRenderer>(Entity e);
	template Material* EntityManager::GetComponent<Material>(Entity e);
	template Transform* EntityManager::AddComponent<Transform>(unsigned int e);
	template Camera* EntityManager::AddComponent<Camera>(unsigned int e);
	template MeshRenderer* EntityManager::AddComponent<MeshRenderer>(unsigned int e);
	template Material* EntityManager::AddComponent<Material>(unsigned int e);
	template Transform* EntityManager::AddComponent<Transform>(Entity e);
	template Camera* EntityManager::AddComponent<Camera>(Entity e);
	template MeshRenderer* EntityManager::AddComponent<MeshRenderer>(Entity e);
	template Material* EntityManager::AddComponent<Material>(Entity e);
	template <> inline void EntityManager::AddComponent(Entity e, Transform & comp) { e = AllEntities[e.Id]; auto nc = new Transform(comp); Transforms[e.Id] = nc; nc->Entity = e; e.Components.push_back(nc); AllEntities[e.Id] = e; } 
	template <> inline void EntityManager::AddComponent(Entity e, Camera & comp) { e = AllEntities[e.Id]; auto nc = new Camera(comp); Cameras[e.Id] = nc; nc->Entity = e; e.Components.push_back(nc); AllEntities[e.Id] = e; } 
	template <> inline void EntityManager::AddComponent(Entity e, MeshRenderer & comp) { e = AllEntities[e.Id]; auto nc = new MeshRenderer(comp); MeshRenderers[e.Id] = nc; nc->Entity = e; e.Components.push_back(nc); AllEntities[e.Id] = e; } 
	template <> inline void EntityManager::AddComponent(Entity e, Material & comp) { e = AllEntities[e.Id]; auto nc = new Material(comp); Materials[e.Id] = nc; nc->Entity = e; e.Components.push_back(nc); AllEntities[e.Id] = e; } 
	
	void EntityManager::ImGuiEditableComponent(Component * comp) {
		auto transform = dynamic_cast<Transform*>(comp);
		if (transform) {
		}
		auto camera = dynamic_cast<Camera*>(comp);
		if (camera) {
		}
		auto meshrenderer = dynamic_cast<MeshRenderer*>(comp);
		if (meshrenderer) {
		}
		auto material = dynamic_cast<Material*>(comp);
		if (material) {
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
		return json.dump();
	}


}	//Transform
	//Camera
	//MeshRenderer
	//Material


#endif