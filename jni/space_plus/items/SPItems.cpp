#include "SPItems.h"

Item* SPItems::steelPickaxe = NULL;
Item* SPItems::steelAxe = NULL;
Item* SPItems::steelHoe = NULL;
Item* SPItems::steelSpade = NULL;
Item* SPItems::steelSword = NULL;
Item* SPItems::steelHelmet = NULL;
Item* SPItems::steelChestplate = NULL;
Item* SPItems::steelLeggings = NULL;
Item* SPItems::steelBoots = NULL;

ArmorItem::ArmorMaterial SPItems::ARMOR_STEEL = ArmorItem::ArmorMaterial(30, 3, 8, 6, 3);
Item::Tier SPItems::TOOL_STEEL = Item::Tier(3, 768, 5.0F, 2.0F);

void SPItems::initItems() {
    //SPItems::steelPickaxe = new PickaxeItemSP("steel_pickaxe");
    /*SPItems::steelAxe = new AxeItemSP("steel_axe");
    SPItems::steelHoe = new HoeItemSP("steel_hoe");
    SPItems::steelSpade = new SpadeItemSP("steel_shovel");*/
    SPItems::steelSword = new SwordItemSP("steel_sword");
    /*SPItems::steelHelmet = new ArmorItemSP(0, "helmet");
    SPItems::steelChestplate = new ArmorItemSP(1, "chestplate");
    SPItems::steelLeggings = new ArmorItemSP(2, "leggings");
    SPItems::steelBoots = new ArmorItemSP(3, "boots");*/

    //SPCoreUtil::registerSpacePlusItem("heavyDutyPickaxe", SPItems::steelPickaxe);
    /*SPCoreUtil::registerSpacePlusItem("heavyDutyShovel", SPItems::steelSpade);
    SPCoreUtil::registerSpacePlusItem("heavyDutyAxe", SPItems::steelAxe);
    SPCoreUtil::registerSpacePlusItem("heavyDutyHoe", SPItems::steelHoe);*/
    SPCoreUtil::registerSpacePlusItem("heavyDutySword", SPItems::steelSword);
    /*SPCoreUtil::registerSpacePlusItem("heavyDutyHelmet", SPItems::steelHelmet);
    SPCoreUtil::registerSpacePlusItem("heavyDutyChestplate", SPItems::steelChestplate);
    SPCoreUtil::registerSpacePlusItem("heavyDutyLeggings", SPItems::steelLeggings);
    SPCoreUtil::registerSpacePlusItem("heavyDutyBoots", SPItems::steelBoots);*/
}

void SPItems::initCreativeItems() {
	/*Item::addCreativeItem(SPItems::steelPickaxe, 0);
	Item::addCreativeItem(SPItems::steelAxe, 0);
	Item::addCreativeItem(SPItems::steelHoe, 0);
	Item::addCreativeItem(SPItems::steelSpade, 0);*/
	Item::addCreativeItem(SPItems::steelSword, 0);
	/*Item::addCreativeItem(SPItems::steelHelmet, 0);
	Item::addCreativeItem(SPItems::steelChestplate, 0);
	Item::addCreativeItem(SPItems::steelLeggings, 0);
	Item::addCreativeItem(SPItems::steelBoots, 0);*/
}