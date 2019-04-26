//
// Created by jwvan on 2019-04-24.
//

#include <iostream>
#include "FileViewer.h"
#include "../assets/Assets.h"

#define ASSET_DIR "/../assets"

namespace Editor {
    FileViewer::FileViewer()
    {

    }

    void RecurseIntoPath(fs::path path)
    {
        fs::directory_iterator dir(path);
        for (fs::path entry : dir)
        {
            bool fileNodeOpen;
            bool isDir = std::filesystem::is_directory(entry);
            if (isDir)
                fileNodeOpen = ImGui::TreeNodeEx(entry.filename().string().c_str(), ImGuiTreeNodeFlags_CollapsingHeader & (~ImGuiTreeNodeFlags_NoTreePushOnOpen));
            else
                fileNodeOpen = ImGui::TreeNodeEx(entry.filename().string().c_str(), ImGuiTreeNodeFlags_Leaf);

            if (ImGui::BeginDragDropSource(ImGuiDragDropFlags_None))
            {
                //ImGui::SetDragDropPayload("Asset", &ast, sizeof(AssetPayload));
                ImGui::Text(entry.filename().string().c_str());
                ImGui::EndDragDropSource();
            }

            if (fileNodeOpen)
            {
                if (isDir)
                    RecurseIntoPath(entry);

                ImGui::TreePop();
            }
        }
    }

    void FileViewer::Update()
    {
        if (ImGui::Begin("File Browser"))
        {
            fs::path path = std::filesystem::current_path();
            path += ASSET_DIR;

            RecurseIntoPath(path);
        }
        ImGui::End();
    }
}