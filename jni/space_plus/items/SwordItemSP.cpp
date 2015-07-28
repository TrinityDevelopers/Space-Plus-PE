#include "SwordItemSP.h"

SwordItemSP::SwordItemSP(std::string assetName) : Item(IDGenSP::findNextItemID()) {
	setMaxStackSize(1);
	tier = SPItems::TOOL_STEEL;
	f1 = tier.damageVsEntity + 4.0F;
	setMaxDamage(tier.maxUses);
    setNameID(assetName);
    setTexture(assetName, 0);
	setCategory(3);
}