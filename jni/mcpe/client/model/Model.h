#pragma once

#include <vector>

#include "../AppPlatformListener.h"
#include "../renderer/MaterialPtr.h"

class Entity;
class Mob;
class AABB;

// Size : 120
class Model : public AppPlatformListener
{
public:
	// void **vtable;						// 0
	char filler1[16];						// 4
	mce::MaterialPtr entity;				// 20
	mce::MaterialPtr entity_alphatest;		// 32
	mce::MaterialPtr entity_alphablend;		// 44
	mce::MaterialPtr entity_static;			// 56
	mce::MaterialPtr entity_emissive;		// 68
	mce::MaterialPtr entity_emissive_alpha;	// 80
	mce::MaterialPtr entity_change_color;	// 92
	mce::MaterialPtr entity_glint;			// 104
	mce::MaterialPtr entity_alphatest_glint;// 116
	std::vector<ModelPart*> modelParts;		// 128
	filler2[8];								// 136

public:
	Model();
	virtual ~Model();
	virtual void onAppSuspended();
	virtual void clear();
	virtual void render();
	virtual void render(Entity &, float, float, float, float, float, float);
	virtual void setupAnim(float, float, float, float, float, float);
	virtual void prepareMobModel(Mob &, float, float, float);
	AABB *getAABB() const;
};
