#pragma once
#include <string>

#include "mcpe/item/HoeItem.h"
#include "space_plus/util/SPCoreUtil.h"
#include "SPItems.h"

class HoeItemSP : public HoeItem {
public:
	static int hoeId;
	
    HoeItemSP(std::string);
};
