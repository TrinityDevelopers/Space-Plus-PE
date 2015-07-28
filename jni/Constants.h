#pragma once
#include <string>

class Constants {
public:
	static const std::string MOD_ID_CORE;
	static const std::string MOD_ID_SIMPLE;
	
	static const int LOCAL_MAJ_VERSION = 0;
	static const int LOCAL_MIN_VERSION = 0;
	static const int LOCAL_BUILD_VERSION = 1;
	
	static const bool IS_DEV_MODE = true;
	static const std::string CONFIG_CATEGORY_DIMENSIONS;
    static const std::string CONFIG_CATEGORY_ENTITIES;
    static const std::string CONFIG_CATEGORY_SCHEMATIC;
    static const std::string CONFIG_CATEGORY_GENERAL;
    static const std::string CONFIG_CATEGORY_ACHIEVEMENTS;
};