//
// Created by kgca44323 on 2024-05-13.
//

#ifndef RENDERER_HELPERLIBRARY_H
#define RENDERER_HELPERLIBRARY_H

#include <string>
#include <optional>

class HelperLibrary
{
public:
	static std::optional<std::string> LoadTextFile(const std::string& fileName);
};

#endif // RENDERER_HELPERLIBRARY_H
