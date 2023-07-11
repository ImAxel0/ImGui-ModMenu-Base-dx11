#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_stdlib.h"
#include "globals.hpp"
#include "config.hpp"
#include "gui utils.hpp"

void GUI()
{
	Globals::style = &ImGui::GetStyle();
	Globals::style->WindowTitleAlign = ImVec2(0.5, 0.5); // align title in the center
	Globals::style->WindowBorderSize = 3.0f; // size of the border, change to your liking

	// rounded borders, change to your liking
	Globals::style->WindowRounding = 8.0f;
	Globals::style->FrameRounding = 8.0f;
	Globals::style->ChildRounding = 8.0f;

	// menu colors, change to your liking
	Globals::style->Colors[ImGuiCol_Border] = ImColor(62, 63, 65);
	Globals::style->Colors[ImGuiCol_TitleBg] = ImColor(62, 63, 65);
	Globals::style->Colors[ImGuiCol_TitleBgActive] = ImColor(62, 63, 65);
	Globals::style->Colors[ImGuiCol_ChildBg] = ImColor(24, 24, 24); // menu background color
		// buttons color
	Globals::style->Colors[ImGuiCol_Button] = ImColor(40, 40, 40);
	Globals::style->Colors[ImGuiCol_ButtonHovered] = ImColor(50, 50, 50);
		// sliders, checkboxes, text input and others background color
	Globals::style->Colors[ImGuiCol_FrameBg] = ImColor(40, 40, 40);
	Globals::style->Colors[ImGuiCol_FrameBgActive] = ImColor(40, 40, 40);
	Globals::style->Colors[ImGuiCol_FrameBgHovered] = ImColor(40, 40, 40);

	ImGui::SetNextWindowSize(ImVec2(480, 620)); // size of the menu, change to your liking
	ImGui::Begin("My Menu", &Globals::showMenu, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_MenuBar /*needed to append a menu bar*/); // the menu itself

	ImGui::BeginMenuBar(); // the top menu bar
	ImGui::Text("I'm the menu bar"); // here goes the things to put in the menu bar e.g buttons, checkboxes etc.
	ImGui::EndMenuBar();

	ImGui::BeginChild("main", ImGui::GetContentRegionAvail(), false, ImGuiWindowFlags_NoResize); // main container (window)

	if (Globals::window == "main") // the main window
	{
		/* COMMON WIDGETS */
		if (ImGui::Button("A button", ImVec2(ImGui::GetContentRegionAvail().x, NULL)))
		{
			// here goes the code to execute when the button is pressed
		}

		ImGui::Checkbox("A standard checkbox", &Config::checkbox_State); // simply toggle the boolean

		if (ImGui::Checkbox("An execute once x click checkbox", &Config::checkbox_State))
		{
			if (Config::checkbox_State)
			{
				// here goes the code to execute only once when the checkbox is clicked and set to ON
			}

			// here goes the code to execute only once when the checkbox is clicked and set to OFF
		}

		/* SLIDERS */
		ImGui::SliderInt("A slider of type INT", &Config::slider_Int, 0, 10); // a slider which takes an integer value

		ImGui::SliderFloat("A slider of type FLOAT", &Config::slider_Float, 0, 10, "%.1f" /*decimal precision*/); // a slider which takes a float value

		ImGui::SliderInt3("A triple INT slider", Config::slider_TripleInt, 0, 10); // a triple integer slider

		ImGui::VSliderInt("A vertical INT slider", ImVec2(25, 80), &Config::slider_Int, 0, 10); // a vertical slide of type integer

		/* DROPDOWN SELECTION */
		if (ImGui::BeginCombo("A dropdown selection", Config::dropdown_Selection.c_str())) // dropdown selection box with a selection of 10 numbers as example
		{
			for (int i{}; i < 10; ++i)
			{
				if (ImGui::Selectable(std::to_string(i).c_str()))
				{
					Config::dropdown_Selection = std::to_string(i); // here goes the code to execute when you select an option from the dropdown list
				}
			}
			ImGui::EndCombo();
		}

		// how to disable a widget
		ImGui::BeginDisabled();
		ImGui::Button("A disabled button");
		ImGui::EndDisabled();

		/* INPUTS */
		ImGui::InputText("Text input box", &Config::text_Input); // an input text box

			/* you can use something like this to execute a code when enter is pressed after inserting the text

				if (ImGui::InputText("Text input", &Config::text_Input, ImGuiInputTextFlags_EnterReturnsTrue))
				{
					// here goes the code to execute after pressing enter
				}
			*/

		ImGui::InputInt("An INT input", &Config::slider_Int); // box which takes an integer input

		ImGui::InputFloat("A FLOAT input", &Config::slider_Float, 0, 0, "%.1f"); // box which takes a float input

		ImGui::InputInt3("A triple INT input", Config::slider_TripleInt); // box which takes 3 integers input

		/* miscellaneous*/
		ImGui::SetNextItemWidth(200); // used for input text and other widgets
		ImGui::InputText("A custom width input text box", &Config::text_Input);

		ImGui::Text("Hover me");
		if (ImGui::IsItemHovered(ImGuiHoveredFlags_None)) // execute when previous element is hovered
			InfoBox("I'm a window to display info about something"); // a function to display an information box

		TextCentered("a centered text"); // function to center text

		if (ImGui::Button("Change window", ImVec2(ImGui::GetContentRegionAvail().x, NULL))) // change view to another window
			SetWindow("another window");

		ImGui::SetCursorPos(ImVec2(100, 520)); // used for buttons and other widgets
		ImGui::SmallButton("A custom positioned button");
	}

	if (Globals::window == "another window") // another window which replaces the previous main one
	{
		if (ImGui::SmallButton("Return to previous window"))
			SetWindow("main");

		ImGui::Text("You are in a subwindow, here you can add whatever you want");
	}

	ImGui::EndChild();
	ImGui::End();
}