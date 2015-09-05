#pragma once

#include "Item.h"

// Size : 88
class ArmorItem : public Item
{
public:
	// Size : 20
	class ArmorMaterial
	{
	public:
		int i1;		// 0
		int defense;// 4
		int i3;		// 8
		int i4;		// 12
		int i5;		// 16
		int i6;

	public:
		ArmorMaterial(int, int, int, int, int, int);
		int getDefenseForSlot(int);
		int getEnchantValue();
		int getHealthForSlot(int);
	};

public:
	static ArmorMaterial CHAIN;
	static ArmorMaterial CLOTH;
	static ArmorMaterial DIAMOND;
	static ArmorMaterial GOLD;
	static ArmorMaterial IRON;
	static int healthPerSlot[5];

public:
	int armorType;					// 72
	int defence;					// 76
	int renderIndex;				// 80
	ArmorMaterial *armorMaterial;	// 84

public:
	ArmorItem(int, const ArmorItem::ArmorMaterial &, int, int);
	virtual ~ArmorItem();
	virtual bool isArmor() const;
	virtual bool isValidRepairItem(const ItemInstance&, const ItemInstance&); 
	virtual int getEnchantSlot() const; 
	virtual int getEnchantValue() const; 
	ItemInstance getTierItem();
};
