#pragma once
#include "imgui/imgui.h"
#include <string>

// function to set a new active window view
inline void SetWindow(std::string window_string)
{			
	Globals::window = window_string;
}

// function to display an information box
void InfoBox(std::string info)
{
	ImGui::BeginTooltip();
	ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
	ImGui::TextUnformatted(info.c_str());
	ImGui::PopTextWrapPos();
	ImGui::EndTooltip();
}

// function to center a text in width
void TextCentered(std::string text) {
	auto windowWidth = ImGui::GetContentRegionAvail().x;
	auto textWidth = ImGui::CalcTextSize(text.c_str()).x;

	ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
	ImGui::Text(text.c_str());
}
