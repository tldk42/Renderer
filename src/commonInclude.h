//
// Created by kgca44323 on 2024-05-13.
//

#ifndef RENDERER_COMMONINCLUDE_H
#define RENDERER_COMMONINCLUDE_H

#ifdef WIN32
	#include <windows.h>
#endif

#include <memory>
#include <vector>

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <spdlog/spdlog.h>

#include "Helper/HelperLibrary.h"

#define CLASS_PTR(klassName)                            \
	class klassName;                                    \
	using klassName##UPtr = std::unique_ptr<klassName>; \
	using klassName##Ptr = std::shared_ptr<klassName>;  \
	using klassName##WPtr = std::weak_ptr<klassName>;

#endif // RENDERER_COMMONINCLUDE_H
