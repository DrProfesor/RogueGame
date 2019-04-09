//
// Created by jwvan on 2019-04-08.
//

#ifndef ROGUEGAME_JSONEXTENSIONS_H
#define ROGUEGAME_JSONEXTENSIONS_H

#include "Json.h"
#include "../entity/Entities.h"

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>
#include <bgfx/bgfx.h>

using nlohmann::json;

namespace glm {
    void to_json(json &j, const vec3 &val) {
        j = json{{"x", val.x},
                 {"y", val.y},
                 {"z", val.z}};
    }

    void from_json(const json &j, vec3 &val) {
        j.at("x").get_to(val.x);
        j.at("y").get_to(val.y);
        j.at("z").get_to(val.z);
    }

    void to_json(json &j, const quat &val) {
        j = json{{"x", val.x},
                 {"y", val.y},
                 {"z", val.z},
                 {"w", val.w}};
    }

    void from_json(const json &j, quat &val) {
        j.at("x").get_to(val.x);
        j.at("y").get_to(val.y);
        j.at("z").get_to(val.z);
        j.at("w").get_to(val.w);
    }
}

namespace Entities {
    void to_json(json &j, const Transform &val) {
        j = json{
            {"Position", {
                {"x", val.Position.x},
                {"y", val.Position.y},
                {"z", val.Position.z}
            }},
            {"Rotation", {
                {"x", val.Rotation.x},
                {"y", val.Rotation.y},
                {"z", val.Rotation.z},
                {"w", val.Rotation.w},
            }},
            {"Scale", {
                {"x", val.Scale.x},
                {"y", val.Scale.y},
                {"z", val.Scale.z}
            }}
        };
    }

    void from_json(const json &j, Transform &val) {
        auto pos = j.at("Position");
        pos.at("x").get_to<float>(val.Position.x);
        pos.at("y").get_to<float>(val.Position.y);
        pos.at("z").get_to<float>(val.Position.z);

        auto rot = j.at("Rotation");
        rot.at("x").get_to<float>(val.Rotation.x);
        rot.at("y").get_to<float>(val.Rotation.y);
        rot.at("z").get_to<float>(val.Rotation.z);
        rot.at("w").get_to<float>(val.Rotation.w);

        auto scl = j.at("Scale");
        scl.at("x").get_to<float>(val.Scale.x);
        scl.at("y").get_to<float>(val.Scale.y);
        scl.at("z").get_to<float>(val.Scale.z);
    }

    void to_json(json &j, const Camera &val) {
        j = json {
            {"ViewId", (int)val.View},
            {"Width", val.Width},
            {"Height", val.Height},
            {"Mode", val.Mode},
            {"FieldOfView", val.FieldOfView},
            {"Near", val.Near},
            {"Far", val.Far},
            {"FrameBuffer", "Create"},
            {"Texture", "Create"}
        };
    }

    void from_json(const json &j, Camera &val) {
        val.View = (ViewId) j.at("ViewId").get<int>();
        j.at("Width").get_to<int>(val.Width);
        j.at("Height").get_to<int>(val.Height);
        j.at("Mode").get_to<CameraMode>(val.Mode);
        j.at("FieldOfView").get_to<float>(val.FieldOfView);
        j.at("Near").get_to<float>(val.Near);
        j.at("Far").get_to<float>(val.Far);

        val.TextureHandle = bgfx::createTexture2D(val.Width, val.Height, false, 1, bgfx::TextureFormat::BGRA8, BGFX_TEXTURE_RT);
        val.FrameBuffer = bgfx::createFrameBuffer(val.View, &val.TextureHandle);
    }

    void to_json(json &j, const MeshRenderer &val) {
        j = json {
            {"Model", "Create"}
        };
    }

    void from_json(const json &j, MeshRenderer &val) {
        val.Model = Assets::GetModel(Assets::LoadModel("knight", R"(D:\Dev\RogueGame\assets\models\Knight2\maria_prop_j_j_ong.fbx)")[0]);
    }

    void to_json(json &j, const Material &val) {
        j = json {
                {"Model", "Create"}
        };
    }

    void from_json(const json &j, Material &val) {
        val.Shader = Utils::LoadShader("cubes");
    }
}

#endif //ROGUEGAME_JSONEXTENSIONS_H
