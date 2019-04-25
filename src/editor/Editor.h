//
// Created by jwvan on 2019-04-06.
//

#ifndef ROGUEGAME_EDITOR_H
#define ROGUEGAME_EDITOR_H

#include "SceneWindow.h"
#include "Logger.h"
#include "FileViewer.h"

namespace Editor {

    struct PosTexCoord0Vertex
    {
        float m_x;
        float m_y;
        float m_z;
        float m_u;
        float m_v;

        static void init()
        {
            ms_decl
                    .begin()
                    .add(bgfx::Attrib::Position,  3, bgfx::AttribType::Float)
                    .add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
                    .end();
        }

        static bgfx::VertexDecl ms_decl;
    };

    struct EditorManager {
        static void Init();
        static void Update();

        static bool IsEditMode;
        static SceneWindow SceneWindow;
        static Logger logger;
        static FileViewer FileViewer;

        static void screenSpaceQuad(float _textureWidth, float _textureHeight, float _width = 1.0f, float _height = 1.0f)
        {
            if (3 == bgfx::getAvailTransientVertexBuffer(3, PosTexCoord0Vertex::ms_decl) )
            {
                bgfx::TransientVertexBuffer vb;
                bgfx::allocTransientVertexBuffer(&vb, 3, PosTexCoord0Vertex::ms_decl);
                PosTexCoord0Vertex* vertex = (PosTexCoord0Vertex*)vb.data;

                const float minx = -_width;
                const float maxx =  _width;
                const float miny = 0.0f;
                const float maxy = _height*2.0f;

                auto texelHalf = 0.0f;
                const float texelHalfW = texelHalf/_textureWidth;
                const float texelHalfH = texelHalf/_textureHeight;
                const float minu = -1.0f + texelHalfW;
                const float maxu =  1.0f + texelHalfH;

                const float zz = 0.0f;

                float minv = texelHalfH;
                float maxv = 2.0f + texelHalfH;

                if (bgfx::getCaps()->originBottomLeft)
                {
                    float temp = minv;
                    minv = maxv;
                    maxv = temp;

                    minv -= 1.0f;
                    maxv -= 1.0f;
                }

                vertex[0].m_x = minx;
                vertex[0].m_y = miny;
                vertex[0].m_z = zz;
                vertex[0].m_u = minu;
                vertex[0].m_v = minv;

                vertex[1].m_x = maxx;
                vertex[1].m_y = miny;
                vertex[1].m_z = zz;
                vertex[1].m_u = maxu;
                vertex[1].m_v = minv;

                vertex[2].m_x = maxx;
                vertex[2].m_y = maxy;
                vertex[2].m_z = zz;
                vertex[2].m_u = maxu;
                vertex[2].m_v = maxv;

                bgfx::setVertexBuffer(0, &vb);
            }
        }
    };
}


#endif //ROGUEGAME_EDITOR_H
