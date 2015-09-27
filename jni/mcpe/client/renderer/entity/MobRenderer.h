#pragma once

#include "EntityRenderer.h"

class Model;
class Mob;
class Matrix;
class ItemInstance;

// Size : 108
class MobRenderer : public EntityRenderer
{
public:
	bool wtf;			// 104
	Model *mainModel;	// 108
	Model *armorModel;	// 112
	char filler1[28];	// 116

public:
	MobRenderer(Model *, float);
	virtual ~MobRenderer();
	virtual void render(Entity &, const Vec3 &, float, float);
	virtual void renderDebug(Entity &, Options &);
	virtual void prepareArmor(Mob &, int, float);
	virtual void prepareCarriedItem(Mob &, ItemInstance *);
	virtual void setupPosition(Entity &, const Vec3 &, Matrix &);
	virtual void setupRotations(Entity &, float, float, Matrix &, float);
	virtual void getAttackAnim(Mob &, float);
	virtual void getBob(Mob &, float);
	virtual void getFlipDegrees(Mob &);
	virtual void scale(Mob &, Matrix &, float);
	virtual void additionalRendering(Mob &, float);
	virtual void bindMobTexture(Mob &);
};
