#pragma once
#include "imgui/imgui.h"
#include <dxgi.h>
#include <string>

typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);

namespace Globals
{
	inline bool showMenu = false;
	inline Present oPresent;
	inline ImGuiStyle* style;
	inline std::string window = "main";
}