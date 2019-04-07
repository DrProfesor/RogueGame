/*
 * This is free and unencumbered software released into the public domain. 
 */

#include "Application.hpp"

#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
#	define GLFW_EXPOSE_NATIVE_X11
#	define GLFW_EXPOSE_NATIVE_GLX
#elif BX_PLATFORM_OSX
#	define GLFW_EXPOSE_NATIVE_COCOA
#	define GLFW_EXPOSE_NATIVE_NSGL
#elif BX_PLATFORM_WINDOWS
#	define GLFW_EXPOSE_NATIVE_WIN32
#	define GLFW_EXPOSE_NATIVE_WGL
#endif // BX_PLATFORM_
#include <bx/math.h>
#include <bgfx/platform.h>
#include <GLFW/glfw3native.h>
#include <glm/glm.hpp>
#include <fstream>

#include "../entity/Entities.h"
#include "bigg_assets.h"
#include "bigg_shaders.hpp"
#include "bigg_imgui.hpp"
#include "../input/Input.h"
#include "../physics/Time.h"
#include <imgui.h>

using namespace app;
using namespace Entities;

// application
Application * Application::Instance;

Application::Application()
{
	mWidth = 1920;
	mHeight = 1080;
	mMousePressed[ 0 ] = false;
	mMousePressed[ 1 ] = false;
	mMousePressed[ 2 ] = false;
	mMouseWheel = 0.0f;

	Instance = this;
}

int Application::Init( int argc, char** argv, bgfx::RendererType::Enum type, uint16_t vendorId, uint16_t deviceId, bgfx::CallbackI* callback, bx::AllocatorI* allocator )
{
	// Initialize the glfw
	if ( !glfwInit() )
	{
		return -1;
	}

	// Create a window
	glfwWindowHint( GLFW_CLIENT_API, GLFW_NO_API );
	mWindow = glfwCreateWindow( GetWidth(), GetHeight(), "", NULL, NULL );
	if ( !mWindow )
	{
		glfwTerminate();
		return -1;
	}

	// Setup input callbacks
	glfwSetWindowUserPointer( mWindow, this );
	glfwSetKeyCallback( mWindow, keyCallback );
	glfwSetMouseButtonCallback( mWindow, mouseButtonCallback );
	glfwSetScrollCallback( mWindow, scrollCallback );
	glfwSetCharCallback( mWindow, charCallback );

	glfwSetKeyCallback( mWindow, keyCallback );
	glfwSetCharCallback( mWindow, charCallback );
	glfwSetCharModsCallback( mWindow, charModsCallback );
	glfwSetMouseButtonCallback( mWindow, mouseButtonCallback );
	glfwSetCursorPosCallback( mWindow, cursorPosCallback );
	glfwSetCursorEnterCallback( mWindow, cursorEnterCallback );
	glfwSetScrollCallback( mWindow, scrollCallback );
	glfwSetDropCallback( mWindow, dropCallback );

	// Setup bgfx
	bgfx::PlatformData platformData;
	memset( &platformData, 0, sizeof( platformData ) );
	bgfx::Init init;

#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
	platformData.nwh = (void*)(uintptr_t)glfwGetX11Window(mWindow);
	platformData.ndt = glfwGetX11Display();
#elif BX_PLATFORM_OSX
	platformData.nwh = glfwGetCocoaWindow(mWindow);
#elif BX_PLATFORM_WINDOWS
	platformData.nwh = glfwGetWin32Window(mWindow);
#endif // BX_PLATFORM_
	bgfx::setPlatformData( platformData );

	// Init bgfx

	init.type = type;
	init.vendorId = vendorId;
	init.deviceId = deviceId;
	init.callback = callback;
	init.allocator = allocator;
	bgfx::init(init);

	Input::Init(mWindow);

	// Setup ImGui
	imguiInit();

	// Initialize the application
	Reset();

    {// init the main camera
        MainCamera = EntityManager::Instantiate();
        auto c = EntityManager::AddComponent<Camera>(MainCamera);
        EntityManager::AddComponent<Entities::Transform>(MainCamera);
        c->View = 1;
        c->TextureHandle = bgfx::createTexture2D(mWidth, mHeight, false, 1, bgfx::TextureFormat::BGRA8, BGFX_TEXTURE_RT);
        c->FrameBuffer = bgfx::createFrameBuffer(1, &c->TextureHandle);
    }

	return 0;
}

bool Application::Update()
{
	if (glfwWindowShouldClose( mWindow )) return false;

	// Events
	glfwPollEvents();
	imguiEvents( Physics::Time::deltaTime );

	// Begin frame
	bgfx::touch(0);
    bgfx::touch(1);
	ImGui::NewFrame();


	return true;
}

void Application::PostUpdate()
{
	// End frame
	ImGui::Render();
	bgfx::frame();

	// Handle resize TODO move?
	int w, h;
	glfwGetWindowSize( mWindow, &w, &h );
	if ( w != mWidth || h != mHeight )
	{
		mWidth = w;
		mHeight = h;
		Reset( mReset );
	}

    Input::Update();
}

void Application::Shutdown()
{
	imguiShutdown();
	bgfx::shutdown();
	glfwTerminate();
}

void Application::Reset( uint32_t flags )
{
	mReset = flags;
	bgfx::reset( mWidth, mHeight, mReset );
	imguiReset( uint16_t( GetWidth() ), uint16_t( GetHeight() ) );

    bgfx::setViewClear( 0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x303030ff, 1.0f, 0 );
    bgfx::setViewRect( 0, 0, 0, uint16_t( GetWidth() ), uint16_t( GetHeight() ) );

    bgfx::setViewClear( 1, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x6dbae0ff, 1.0f, 0 );
    bgfx::setViewRect( 1, 0, 0, uint16_t( GetWidth() ), uint16_t( GetHeight() ) );
}

uint32_t Application::GetWidth()
{
	return mWidth;
}

uint32_t Application::GetHeight()
{
	return mHeight;
}

// TODO move these to input
void Application::keyCallback( GLFWwindow* window, int key, int scancode, int action, int mods )
{
	ImGuiIO& io = ImGui::GetIO();
	if ( action == GLFW_PRESS )
	{
		io.KeysDown[ key ] = true;
	}
	if ( action == GLFW_RELEASE )
	{
		io.KeysDown[ key ] = false;
	}
	io.KeyCtrl = io.KeysDown[ GLFW_KEY_LEFT_CONTROL ] || io.KeysDown[ GLFW_KEY_RIGHT_CONTROL ];
	io.KeyShift = io.KeysDown[ GLFW_KEY_LEFT_SHIFT ] || io.KeysDown[ GLFW_KEY_RIGHT_SHIFT ];
	io.KeyAlt = io.KeysDown[ GLFW_KEY_LEFT_ALT ] || io.KeysDown[ GLFW_KEY_RIGHT_ALT ];
	io.KeySuper = io.KeysDown[ GLFW_KEY_LEFT_SUPER ] || io.KeysDown[ GLFW_KEY_RIGHT_SUPER ];
	if ( !io.WantCaptureKeyboard )
	{
	    Input::keyCallback(window, key, scancode, action, mods);
	}
}

void Application::charCallback( GLFWwindow* window, unsigned int codepoint )
{
	ImGuiIO& io = ImGui::GetIO();
	if ( codepoint > 0 && codepoint < 0x10000 )
	{
		io.AddInputCharacter( ( unsigned short )codepoint );
	}

	Input::charCallback(window, codepoint);
}

void Application::charModsCallback( GLFWwindow* window, unsigned int codepoint, int mods )
{
    Input::charModsCallback(window, codepoint, mods);
}

void Application::mouseButtonCallback( GLFWwindow* window, int button, int action, int mods )
{
	ImGuiIO& io = ImGui::GetIO();
	if ( action == GLFW_PRESS && button >= 0 && button < 3 )
	{
	}
	if ( !io.WantCaptureMouse )
	{
	    Input::mouseButtonCallback(window, button, action, mods);
	}
}

void Application::cursorPosCallback( GLFWwindow* window, double xpos, double ypos )
{
    Input::cursorPosCallback(window, xpos, ypos);
}

void Application::cursorEnterCallback( GLFWwindow* window, int entered )
{
    Input::cursorEnterCallback(window, entered);
}

void Application::scrollCallback( GLFWwindow* window, double xoffset, double yoffset )
{
	Application* app = ( Application* )glfwGetWindowUserPointer( window );
	app->mMouseWheel += (float)yoffset;

	Input::scrollCallback(window, xoffset, yoffset);
}

void Application::dropCallback( GLFWwindow* window, int count, const char** paths )
{
    Input::dropCallback(window, count, paths);
}

void Application::imguiEvents( float dt )
{
	ImGuiIO& io = ImGui::GetIO();
	io.DeltaTime = dt;
	int w, h;
	int displayW, displayH;
	glfwGetWindowSize( mWindow, &w, &h );
	glfwGetFramebufferSize( mWindow, &displayW, &displayH );
	io.DisplaySize = ImVec2( ( float )w, ( float )h );
	io.DisplayFramebufferScale = ImVec2( w > 0 ? ( ( float )displayW / w ) : 0, h > 0 ? ( ( float )displayH / h ) : 0 );
	if ( glfwGetWindowAttrib( mWindow, GLFW_FOCUSED ) )
	{
		double mouse_x, mouse_y;
		glfwGetCursorPos( mWindow, &mouse_x, &mouse_y );
		io.MousePos = ImVec2( ( float )mouse_x, ( float )mouse_y );
	}
	else
	{
		io.MousePos = ImVec2( -1, -1 );
	}
	for (int i = 0; i < 3; i++)
	{
		io.MouseDown[ i ] = mMousePressed[ i ] || glfwGetMouseButton( mWindow, i ) != 0;
		mMousePressed[ i ] = false;
	}
	io.MouseWheel = mMouseWheel;
	mMouseWheel = 0.0f;
	glfwSetInputMode( mWindow, GLFW_CURSOR, io.MouseDrawCursor ? GLFW_CURSOR_HIDDEN : GLFW_CURSOR_NORMAL );
	io.ClipboardUserData = mWindow;
#ifdef _WIN32
	//io.ImeWindowHandle = glfwGetWin32Window( mWindow );
#endif
}

// glm utils

glm::tmat4x4<float, glm::defaultp> app::perspective( float fovy, float aspect, float zNear, float zFar )
{
	glm::tmat4x4<float, glm::defaultp> mtx;
#	if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED
	bx::mtxProjLh( &mtx[ 0 ][ 0 ], glm::degrees( fovy ), aspect, zNear, zFar, bgfx::getCaps()->homogeneousDepth );
#	else
	bx::mtxProjRh( &mtx[ 0 ][ 0 ], glm::degrees( fovy ), aspect, zNear, zFar, bgfx::getCaps()->homogeneousDepth );
#	endif
	return mtx;
}

glm::tmat4x4<float, glm::defaultp> app::ortho( float left, float right, float bottom, float top, float zNear, float zFar, float offset )
{
	glm::tmat4x4<float, glm::defaultp> mtx;
#	if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED
	bx::mtxOrthoLh( &mtx[ 0 ][ 0 ], left, right, bottom, top, zNear, zFar, offset, bgfx::getCaps()->homogeneousDepth );
#	else
	bx::mtxOrthoRh( &mtx[ 0 ][ 0 ], left, right, bottom, top, zNear, zFar, offset, bgfx::getCaps()->homogeneousDepth );
#	endif
	return mtx;
}
