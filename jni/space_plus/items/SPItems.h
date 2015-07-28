#pragma once

#include <vector>
#include <Constants.h>
#include "space_plus/util/SPCoreUtil.h"
#inlcude "mcpe/item/Item.h"
#include "mcpe/item/ArmorItem.h"
#include "mcpe/item/ItemInstance.h"
#include "PickaxeItemSP.h"
#include "AxeItemSP.h"
#include "SpadeItemSP.h"
#include "HoeItemSP.h"
#include "SwordItemSP.h"
#include "ArmorItemSP.h"

class SPItems {
public:
    static Item* steelPickaxe;
    static Item* steelAxe;
    static Item* steelHoe;
    static Item* steelSpade;
    static Item* steelSword;
    static Item* steelHelmet;
    static Item* steelChestplate;
    static Item* steelLeggings;
    static Item* steelBoots;

    static ArmorItem::ArmorMaterial ARMOR_STEEL(30, 3, 8, 6, 3);
    static Item::Tier TOOL_STEEL(3, 768, 5.0F, 2.0F, 8);

    static std::vector<Item*> hiddenItems = new std::vector<Item*>();

    static void initItems();
	static void initCreativeItems();
};
