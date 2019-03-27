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
	static std::map<unsigned int, Camera*> Cameras;
	static std::map<unsigned int, Transform*> Transforms;
	static std::map<unsigned int, MeshRenderer*> MeshRenderers;
	static std::map<unsigned int, Material*> Materials;

	template<typename T>
	T* AddComponent(Entity e) {
		auto name = readable_name(typeid(T).name());
		auto sName = name.substr(name.find('::') + 2, name.size() - 1);
		auto comparableName = sName.c_str();
		if (std::strcmp(comparableName, "Camera") == 0) {
			auto nc = new Camera();
			Cameras[e.Id] = nc;
			return (T*)nc;
		}
		else if (std::strcmp(comparableName, "Transform") == 0) {
			auto nc = new Transform();
			Transforms[e.Id] = nc;
			return (T*)nc;
		}
		else if (std::strcmp(comparableName, "MeshRenderer") == 0) {
			auto nc = new MeshRenderer();
			MeshRenderers[e.Id] = nc;
			return (T*)nc;
		}
		else if (std::strcmp(comparableName, "Material") == 0) {
			auto nc = new Material();
			Materials[e.Id] = nc;
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
		if (std::strcmp(comparableName, "Camera") == 0) {
			return (T*)Cameras[e.Id];
		}
		else if (std::strcmp(comparableName, "Transform") == 0) {
			return (T*)Transforms[e.Id];
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
		for (auto kp : MeshRenderers) {
			Update_MeshRender(kp.first, kp.second);
		}
	}


}

#endif