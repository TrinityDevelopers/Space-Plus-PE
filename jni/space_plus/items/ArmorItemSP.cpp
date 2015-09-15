#include "ArmorItemSP.h"

ArmorItemSP::ArmorItemSP(int armorIndex, std::string assetSuffix) : ArmorItem(SPCoreUtil::findNextItemID(0), SPItems::ARMOR_STEEL, 0, armorIndex) {
    setNameID("steel_" + assetSuffix);
    setIcon("steel_" + assetSuffix, 0);
	setCategory(3);
	setArmorTexture(armorIndex);
}

void ArmorItemSP::setArmorTexture(int armorType) {
	switch(armorType){
		case 0:
			SPCoreUtil::armorTextures[this->id] = "armor/steel_1.png";
			break;
		case 1:
			SPCoreUtil::armorTextures[this->id] = "armor/steel_2.png";
			break;
		case 2:
			SPCoreUtil::armorTextures[this->id] = "armor/steel_3.png";
			break;
		case 3:
			SPCoreUtil::armorTextures[this->id] = "armor/steel_2.png";
			break;
	}
}
