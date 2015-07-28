#include "ArmorItemSP.h"

ArmorItemSP::ArmorItemSP(int armorIndex, std::string assetSuffix) : ArmorItem(IDGenSP::findNextItemID(), SPItems::ARMOR_STEEL, SpacePlusCore::proxy->getTitaniumArmorRenderIndex(), armorIndex) {
    setNameID("steel_" + assetSuffix);
    setIcon("steel_" + assetSuffix, 0);
	setCategory(3);
	setArmorTexture(armorIndex);
}

void ArmorItemSP::setArmorTexture(int armorType) {
	switch(armorType){
		case 0:
			ClientProxyCore::bl_armorRenders[this->id] = "armor/steel_1.png";
			break;
		case 1:
			ClientProxyCore::bl_armorRenders[this->id] = "armor/steel_2.png";
			break;
		case 2:
			ClientProxyCore::bl_armorRenders[this->id] = "armor/steel_3.png";
			break;
		case 3:
			ClientProxyCore::bl_armorRenders[this->id] = "armor/steel_2.png";
			break;
	}
}
