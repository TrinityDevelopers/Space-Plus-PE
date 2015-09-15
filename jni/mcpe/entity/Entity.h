#pragma once

#include <string>
#include <memory>
#include <vector>
#include "SynchedEntityData.h"
#include "../util/AABB.h"

class Level;
class TileSource;
class Random;
class Vec3;
class Material;
class Player;
class EntityDamageSource;
class CompoundTag;
class ItemInstance;
class EntityPos;
class EntityLink;
class TilePos;
class Vec2;
class EntityUniqueID;
class Entity;
class EntityEvent;
class DimensionId;
class ChangeDimensionPacket;
class AABB;
#include "../util/Vec3.h"

// Size : 324
class Entity
{
public:
	static std::string RIDING_TAG;
	static uint entityCounter;

public:
	// void **vtable;
	char synchedData[20]; // 4
	float x; // 24
	float y; // 28
	float z; // 32
	Vec3 chunkPos; // 36
	TileSource& region; // 48
	int added; // 52
	int idk; // 56
	Level* level; // 60
	float oldX; // 64
	float oldY; // 68
	float oldZ; // 72
	float velX; // 76
	float velY; // 80
	float velZ; // 84
	float yaw; // 88
	float pitch; // 92
	char filler[248]; //96
	bool inWater; //344

	/*float prevRotationPitch;	// 92
	float prevRotationYaw;		// 96
	char filler4[40];			// 100
	AABB boundingBox;			// 140
	char filler5[4];			// 168
	float width;				// 172
	float height;				// 176
	char filler6[32];			// 180
	int ticksExisted;			// 212
	char filler7[8];			// 216
	int fireResistance;			// 224
	char filler8[4];			// 228
	int entityRendererId;		// 232 //320
	std::vector<Entity *> riddenByEntities;	// 236
	char filler9[4];			// 248
	Entity *ridingEntity;		// 252
	char filler10[48];			// 256
	bool inWater;				// 304 //344
	char filler11[16];			// 308*/

public:
	Entity(Level &);
	Entity(TileSource &);
	virtual ~Entity();
	virtual void _postInit();
	virtual void reset();
	virtual int getOwnerEntityType();
	virtual void remove();
	virtual void setPos(float, float, float);
	virtual void setPos(const Vec3&);
	virtual Vec3& getPos() const;
	virtual Vec3& getPosOld() const;
	virtual Vec3& getPosExtrapolated(float) const;
	virtual Vec3& getVelocity() const;
	virtual void setRot(float, float);
	virtual void move(float, float, float);
	virtual void checkTileCollisions();
	virtual void moveTo(float, float, float, float, float);
	virtual void moveRelative(float, float, float);
	virtual void lerpTo(const Vec3&, const Vec2&, int);
	virtual void lerpMotion(float, float, float);
	virtual void turn(float, float);
	virtual void interpolateTurn(float, float);
	virtual void* getAddPacket();
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual void* positionRider(Entity&) const;
	virtual float getRidingHeight();
	virtual float getRideHeight() const;
	virtual int getRideUseAnimation() const;
	virtual void startRiding(Entity&);
	virtual void addRider(Entity&);
	virtual void removeRider(Entity&);
	virtual bool intersects(float, float, float, float, float, float);
	virtual bool isFree(float, float, float, float);
	virtual bool isFree(float, float, float);
	virtual bool isInWall();
	virtual bool isInvisible();
	virtual bool canShowNameTag();
	virtual void setNameTagVisible(bool);
	virtual void* getNameTag() const;
	virtual void setNameTag(const std::string&);
	virtual bool isInWater() const;
	virtual bool isInWaterOrRain();
	virtual bool isInLava();
	virtual bool isUnderLiquid(const Material*) const;
	virtual float getShadowRadius() const;
	virtual void makeStuckInWeb();
	virtual float getHeadHeight() const;
	virtual float getShadowHeightOffs();
	virtual bool isSkyLit(float);
	virtual float getBrightness(float);
	virtual bool interactPreventDefault();
	virtual void interactWithPlayer(Player*);
	virtual bool canInteractWith(Player*);
	virtual std::string getInteractText(Player*);
	virtual void playerTouch(Player*);
	virtual void push(Entity&);
	virtual void push(float, float, float);
	virtual bool isImmobile();
	virtual bool isSilent();
	virtual bool isPickable();
	virtual bool isPushable();
	virtual bool isShootable();
	virtual bool isSneaking() const;
	virtual bool isAlive();
	virtual bool isOnFire() const;
	virtual bool isCreativeModeAllowed();
	virtual bool isSurfaceMob() const;
	virtual bool shouldRenderAtSqrDistance(float);
	virtual void hurt(EntityDamageSource&, int);
	virtual void animateHurt();
	virtual void doFireHurt(int);
	virtual void onLightningHit();
	virtual void handleEntityEvent(EntityEvent);
	virtual int getPickRadius();
	virtual void spawnAtLocation(int, int);
	virtual void spawnAtLocation(int, int, float);
	virtual void spawnAtLocation(const ItemInstance&, float);
	virtual void awardKillScore(Entity*, int);
	virtual void setEquippedSlot(int, int, int);
	virtual void setEquippedSlot(int, const ItemInstance&);
	virtual void save(CompoundTag&);
	virtual void saveWithoutId(CompoundTag&);
	virtual void load(const CompoundTag&);
	virtual void loadLinks(const CompoundTag&, std::vector<EntityLink, std::allocator<EntityLink>>&);
	virtual int getEntityTypeId() const = 0;
	virtual void queryEntityRenderer();
	virtual void getSourceUniqueID();
	virtual void setOnFire(int);
	virtual AABB getHandleWaterAABB() const;
	virtual void handleInsidePortal();
	virtual int getPortalCooldown() const;
	virtual int getPortalWaitTime() const;
	virtual DimensionId getDimensionId() const;
	virtual void changeDimension(DimensionId);
	virtual void changeDimension(ChangeDimensionPacket&);
	virtual Player* getControllingPlayer() const;
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float);
	virtual void setSize(float, float);
	virtual void setPos(EntityPos*);
	virtual void outOfWorld();
	virtual void markHurt();
	virtual void burn(int);
	virtual void lavaHurt();
	virtual void readAdditionalSaveData(const CompoundTag*) = 0;
	virtual void addAdditionalSaveData(CompoundTag*) = 0;
	virtual void playStepSound(int, int, int, int);
	virtual void checkInsideTiles(float);
	virtual void pushOutOfTiles(float, float, float);
	virtual void _updateWaterState();
	virtual void _doWaterSplashEffect();
	virtual void _updatePortalState();
	virtual void onTileCollision(int);
	virtual void playSound(const std::string&, float, float);
	virtual void onSynchedDataUpdate(int);
	virtual bool canAddRider(Entity&) const;
	virtual void sendMotionPacketIfNeeded();
	virtual void stopRiding(bool);
	virtual void* buildDebugInfo(std::string&) const;
	void _findRider(Entity &) const;
	void _init();
	void _manageRiders(TileSource &);
	void _sendLinkPacket(const TileSource &) const;
	void _tryPlaceAt(const Vec3 &);
	void _updateOwnerChunk();
	void distanceSqrToBlockPosCenter(const TilePos &);
	void distanceTo(Entity *);
	void distanceTo(float, float, float);
	void distanceToSqr(Entity *);
	void distanceToSqr(float, float, float);
	void enableAutoSendPosRot(bool);
	void getCenter(float);
	void getInterpolatedPosition(float) const;
	void getInterpolatedPosition2(float) const;
	void getInterpolatedRotation(float) const;
	void getLinks() const;
	void getRandomPointInAABB(Random &);
	Vec2 &getRotation() const;
	void getStatusFlag(int) const;
	void getUniqueID() const;
	void getViewVector(float) const;
	void getViewVector2(float) const;
	bool hasUniqueID() const;
	bool isControlledByLocalInstance() const;
	bool isInClouds() const;
	bool isInstanceOf(int) const;
	bool isMob() const;
	bool isRide() const;
	bool isRider(Entity &) const;
	bool isRiding() const;
	void moveTo(const Vec3 &, const Vec2 &);
	bool operator==(Entity &);
	void removeAllRiders();
	void saveLinks() const;
	void sendMotionToServer();
	void setRegion(TileSource &);
	void setUniqueID(EntityUniqueID);
	void shouldRender();
};
