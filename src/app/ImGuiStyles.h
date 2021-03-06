//
// Created by jwvan on 2019-04-25.
//

#ifndef ROGUEGAME_IMGUISTYLES_H
#define ROGUEGAME_IMGUISTYLES_H

#include <imgui.h>

void ChangeStyleColors(ImGuiStyle& style,float satThresholdForInvertingLuminance,float shiftHue)  {
    if (satThresholdForInvertingLuminance>=1.f && shiftHue==0.f) return;
    for (int i = 0; i < ImGuiCol_COUNT; i++)	{
        ImVec4& col = style.Colors[i];
        float H, S, V;
        ImGui::ColorConvertRGBtoHSV( col.x, col.y, col.z, H, S, V );
        if( S <= satThresholdForInvertingLuminance)  { V = 1.0 - V; }
        if (shiftHue) {H+=shiftHue;if (H>1) H-=1.f;else if (H<0) H+=1.f;}
        ImGui::ColorConvertHSVtoRGB( H, S, V, col.x, col.y, col.z );
    }
}

static inline ImVec4 ImColorLerp(const ImVec4& a, const ImVec4& b, float t) {
    return ImVec4(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t, a.w + (b.w - a.w) * t);
}


static inline void CreateDefaultTabColorsFor(ImGuiStyle& style,ImGuiCol baseHoveredColor=ImGuiCol_HeaderHovered,float hoveredLerp=0.5f,const ImVec2& tabsLerps=ImVec2(0.15f,0.8f),const ImVec2& unfocusedTabsLerp=ImVec2(0.1f,0.5f))  {
    IM_ASSERT(baseHoveredColor+1<ImGuiCol_COUNT);
    style.Colors[ImGuiCol_TabHovered]           = ImColorLerp(style.Colors[baseHoveredColor], style.Colors[baseHoveredColor+1], hoveredLerp);

    style.Colors[ImGuiCol_Tab]                  = ImColorLerp(style.Colors[ImGuiCol_WindowBg],style.Colors[ImGuiCol_TabHovered], tabsLerps.x);
    style.Colors[ImGuiCol_TabActive]            = ImColorLerp(style.Colors[ImGuiCol_TitleBgActive],style.Colors[ImGuiCol_TabHovered], tabsLerps.y);

    style.Colors[ImGuiCol_TabUnfocused]         = ImColorLerp(style.Colors[ImGuiCol_WindowBg],style.Colors[ImGuiCol_Tab],unfocusedTabsLerp.x);
    style.Colors[ImGuiCol_TabUnfocusedActive]   = ImColorLerp(style.Colors[ImGuiCol_WindowBg],style.Colors[ImGuiCol_TabActive],unfocusedTabsLerp.y);
}

void SetStyleDark()
{
    ImGuiStyle& style = ImGui::GetStyle();
    float hspacing = 8.f;
    float vspacing = 6.f;
    style.DisplaySafeAreaPadding = ImVec2(0, 0);
    style.WindowPadding = ImVec2(hspacing/2, vspacing);
    style.FramePadding = ImVec2(hspacing, vspacing);
    style.ItemSpacing = ImVec2(hspacing, vspacing);
    style.ItemInnerSpacing = ImVec2(hspacing, vspacing);
    style.IndentSpacing = 20.0f;

    style.WindowRounding = 0.0f;
    style.FrameRounding = 0.0f;

    style.WindowBorderSize = 0.0f;
    style.FrameBorderSize = 1.0f;
    style.PopupBorderSize = 1.0f;

    style.ScrollbarSize = 20.0f;
    style.ScrollbarRounding = 0.0f;
    style.GrabMinSize = 5.0f;
    style.GrabRounding = 0.0f;

    ImVec4 white = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    ImVec4 transparent = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    ImVec4 dark = ImVec4(0.00f, 0.00f, 0.00f, 0.20f);
    ImVec4 darker = ImVec4(0.00f, 0.00f, 0.00f, 0.50f);

    ImVec4 background = ImVec4(0.95f, 0.95f, 0.95f, 1.00f);
    ImVec4 text = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
    ImVec4 border = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
    ImVec4 grab = ImVec4(0.69f, 0.69f, 0.69f, 1.00f);
    ImVec4 header = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
    ImVec4 active = ImVec4(0.00f, 0.47f, 0.84f, 1.00f);
    ImVec4 hover = ImVec4(0.00f, 0.47f, 0.84f, 0.20f);

    style.Colors[ImGuiCol_Text] = text;
    style.Colors[ImGuiCol_WindowBg] = background;
    style.Colors[ImGuiCol_ChildBg] = background;
    style.Colors[ImGuiCol_PopupBg] = white;

    style.Colors[ImGuiCol_Border] = border;
    style.Colors[ImGuiCol_BorderShadow] = transparent;

    style.Colors[ImGuiCol_Button] = header;
    style.Colors[ImGuiCol_ButtonHovered] = hover;
    style.Colors[ImGuiCol_ButtonActive] = active;

    style.Colors[ImGuiCol_FrameBg] = white;
    style.Colors[ImGuiCol_FrameBgHovered] = hover;
    style.Colors[ImGuiCol_FrameBgActive] = active;

    style.Colors[ImGuiCol_MenuBarBg] = header;
    style.Colors[ImGuiCol_Header] = header;
    style.Colors[ImGuiCol_HeaderHovered] = hover;
    style.Colors[ImGuiCol_HeaderActive] = active;

    style.Colors[ImGuiCol_CheckMark] = text;
    style.Colors[ImGuiCol_SliderGrab] = grab;
    style.Colors[ImGuiCol_SliderGrabActive] = darker;

    //style.Colors[ImGuiCol_CloseButton] = transparent;
    //style.Colors[ImGuiCol_CloseButtonHovered] = transparent;
    //style.Colors[ImGuiCol_CloseButtonActive] = transparent;

    style.Colors[ImGuiCol_ScrollbarBg] = header;
    style.Colors[ImGuiCol_ScrollbarGrab] = grab;
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = dark;
    style.Colors[ImGuiCol_ScrollbarGrabActive] = darker;

    // These were missing:
    style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.94f, 0.94f, 0.94f, 1.00f);
    style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.94f, 0.94f, 0.94f, 0.20f);
    style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);

    ChangeStyleColors(style,.1f,0.f);

    style.TabBorderSize = 0;
    style.TabRounding = (int)(style.WindowRounding+style.ChildRounding)/2;
    CreateDefaultTabColorsFor(style);
}

struct ImVec3 { float x, y, z; ImVec3(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) { x = _x; y = _y; z = _z; } };

void imgui_easy_theming(ImVec3 color_for_text, ImVec3 color_for_head, ImVec3 color_for_area, ImVec3 color_for_body, ImVec3 color_for_pops)
{
    ImGuiStyle& style = ImGui::GetStyle();

    style.Colors[ImGuiCol_Text] = ImVec4( color_for_text.x, color_for_text.y, color_for_text.z, 1.00f );
    style.Colors[ImGuiCol_TextDisabled] = ImVec4( color_for_text.x, color_for_text.y, color_for_text.z, 0.58f );
    style.Colors[ImGuiCol_WindowBg] = ImVec4( color_for_body.x, color_for_body.y, color_for_body.z, 0.95f );
    style.Colors[ImGuiCol_ChildWindowBg] = ImVec4( color_for_area.x, color_for_area.y, color_for_area.z, 0.58f );
    style.Colors[ImGuiCol_Border] = ImVec4( color_for_body.x, color_for_body.y, color_for_body.z, 0.00f );
    style.Colors[ImGuiCol_BorderShadow] = ImVec4( color_for_body.x, color_for_body.y, color_for_body.z, 0.00f );
    style.Colors[ImGuiCol_FrameBg] = ImVec4( color_for_area.x, color_for_area.y, color_for_area.z, 1.00f );
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 0.78f );
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 1.00f );
    style.Colors[ImGuiCol_TitleBg] = ImVec4( color_for_area.x, color_for_area.y, color_for_area.z, 1.00f );
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4( color_for_area.x, color_for_area.y, color_for_area.z, 0.75f );
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 1.00f );
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4( color_for_area.x, color_for_area.y, color_for_area.z, 0.47f );
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4( color_for_area.x, color_for_area.y, color_for_area.z, 1.00f );
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 0.21f );
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 0.78f );
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 1.00f );
    //style.Colors[ImGuiCol_ComboBg] = ImVec4( color_for_area.x, color_for_area.y, color_for_area.z, 1.00f );
    style.Colors[ImGuiCol_CheckMark] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 0.80f );
    style.Colors[ImGuiCol_SliderGrab] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 0.50f );
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 1.00f );
    style.Colors[ImGuiCol_Button] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 0.50f );
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 0.86f );
    style.Colors[ImGuiCol_ButtonActive] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 1.00f );
    style.Colors[ImGuiCol_Header] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 0.76f );
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 0.86f );
    style.Colors[ImGuiCol_HeaderActive] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 1.00f );
    style.Colors[ImGuiCol_Column] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 0.32f );
    style.Colors[ImGuiCol_ColumnHovered] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 0.78f );
    style.Colors[ImGuiCol_ColumnActive] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 1.00f );
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 0.15f );
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 0.78f );
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 1.00f );
//    style.Colors[ImGuiCol_CloseButton] = ImVec4( color_for_text.x, color_for_text.y, color_for_text.z, 0.16f );
//    style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4( color_for_text.x, color_for_text.y, color_for_text.z, 0.39f );
//    style.Colors[ImGuiCol_CloseButtonActive] = ImVec4( color_for_text.x, color_for_text.y, color_for_text.z, 1.00f );
    style.Colors[ImGuiCol_PlotLines] = ImVec4( color_for_text.x, color_for_text.y, color_for_text.z, 0.63f );
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 1.00f );
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4( color_for_text.x, color_for_text.y, color_for_text.z, 0.63f );
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 1.00f );
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4( color_for_head.x, color_for_head.y, color_for_head.z, 0.43f );
    style.Colors[ImGuiCol_PopupBg] = ImVec4( color_for_pops.x, color_for_pops.y, color_for_pops.z, 0.92f );
    style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4( color_for_area.x, color_for_area.y, color_for_area.z, 0.73f );
}

void SetupImGuiStyle2()
{
    static ImVec3 color_for_text = ImVec3(236.f / 255.f, 240.f / 255.f, 241.f / 255.f);
    static ImVec3 color_for_head = ImVec3(41.f / 255.f, 128.f / 255.f, 185.f / 255.f);
    static ImVec3 color_for_area = ImVec3(57.f / 255.f, 79.f / 255.f, 105.f / 255.f);
    static ImVec3 color_for_body = ImVec3(44.f / 255.f, 62.f / 255.f, 80.f / 255.f);
    static ImVec3 color_for_pops = ImVec3(33.f / 255.f, 46.f / 255.f, 60.f / 255.f);
    imgui_easy_theming(color_for_text, color_for_head, color_for_area, color_for_body, color_for_pops);
}

#endif //ROGUEGAME_IMGUISTYLES_H
