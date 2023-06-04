#pragma once
#include <string>
#include <imgui.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>

#include "Application.h"

namespace UiEngine
{
	class Image
	{
	public:
		Image();
		~Image();
		inline GLuint GetTextureID() {return image_texture;};
		void ShowVideoFromImage(unsigned char* imgData, int* width, int* height);
		bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);
	private:
		GLuint image_texture;
	};
}