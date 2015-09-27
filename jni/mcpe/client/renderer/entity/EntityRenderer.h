#pragma once

#include <string>
#include "EntityShaderManager.h"

class EntityRenderDispatcher;
class Vec3;
class Vec2;
class Font;
class Options;

// Size : 68
class EntityRenderer : public EntityShaderManager
{
public:
	static EntityRenderDispatcher *entityRenderDispatcher;

public:
	bool wtf;									// 40
	mce::MaterialPtr entity_alphatest2;			// 44
	mce::MaterialPtr entity_alphatest_glint;	// 56
	mce::MaterialPtr name_tag;					// 68
	mce::MaterialPtr name_tag_depth_tested;		// 80
	mce::MaterialPtr name_tag_depth_tested2;	// 92

public:
	EntityRenderer();
	virtual ~EntityRenderer();
	virtual void render(Entity &, const Vec3 &, float, float) = 0;
	virtual void postRender(Entity &, const Vec3 &, float, float);
	virtual void renderDebug(Entity &, Options &);
	virtual void renderWaterHole(Entity &, const Vec3 &, const Vec2 &, float);
	void bindTexture(const std::string &, int);
	static void _emitFlame(Entity &, float);
	static void _emitSmoke(Entity &, float);
	static void init(EntityRenderDispatcher *);
	static bool isFancy();
	static Font *getFont();
};
