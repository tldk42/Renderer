//
// Created by kgca44323 on 2024-05-13.
//

#include "HelperLibrary.h"
#include <spdlog/spdlog.h>
#include <fstream>
#include <sstream>

std::optional<std::string> HelperLibrary::LoadTextFile(const std::string& fileName)
{
	std::ifstream fin(fileName);

	if (!fin.is_open())
	{
		SPDLOG_ERROR("failed to open file: {}", fileName);
		return {};
	}

	// text에 입력받은 파일 버퍼 읽어들이고 반환
	std::stringstream text;
	text << fin.rdbuf();

	return text.str();
}
