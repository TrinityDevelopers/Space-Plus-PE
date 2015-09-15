#pragma once

#include "Entity.h"

class Item;
class MobEffectInstance;
class PathNavigation;
class LookControl;
class MoveControl;
class JumpControl;
class BodyControl;
class Sensing;
class MobEffect;
class EntityUniqueID;
class Attribute;
class ItemEntity;

// Size : 3178
class Mob : public Entity
{
public:
	char filler1[12];			// 348
	ItemInstance* armor0;		// 360
	ItemInstance* armor1;		// 380
	ItemInstance* armor2;		// 400
	ItemInstance* armor3;		// 420
	char filler2[40];			// 424
	float rotationYawHead;		// 464
	float prevRotationYawHead;	// 468
	char filler3[328];			// 472
	LookControl *lookControl;	// 800
	MoveControl *moveControl;	// 801
	JumpControl *jumpControl;	// 802
	BodyControl *bodyControl;	// 803
	PathNavigation *navigator;	// 804
	Sensing *sensing;			// 805
	char filler4[2319];			// 809
	std::string skinPath;		// 3128
	char filler5[61];			// 3132
	bool isJumping;				// 3193
	char filler6[51];			// 3197
	Mob* target;				// 3248
	char filler7[53];			// 3252
	bool shouldDspawn;			// 3305

public:
	Mob(Level &);
	Mob(TileSource &);
	virtual ~Mob();
	virtual void lerpTo(const Vec3 &, const Vec2 &, int);
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual float getHeadHeight() const;
	virtual bool isImmobile();
	virtual bool isPickable();
	virtual bool isPushable();
	virtual bool isShootable();
	virtual bool isSneaking();
	virtual bool isAlive();
	virtual void hurt(EntityDamageSource &, int);
	virtual void animateHurt();
	virtual void doFireHurt(int);
	virtual void handleEntityEvent(EntityEvent);
	virtual void setOnFire(int);
	virtual void causeFallDamage(float);
	virtual void outOfWorld();
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void playStepSound(int, int, int, int);
	virtual void* buildDebugInfo(std::string &);
	virtual void postInit();
	virtual void knockback(Entity *, int, float, float);
	virtual void die(EntityDamageSource &);
	virtual void resolveDeathLoot(int);
	virtual bool canSee(Entity *);
	virtual void onLadder();
	virtual void spawnAnim();
	virtual std::string getTexture();
	virtual bool isSleeping();
	virtual void setSneaking(bool);
	virtual bool isSprinting() const;
	virtual void setSprinting(bool);
	virtual float getVoicePitch();
	virtual void playAmbientSound();
	virtual void getItemInHandIcon(const ItemInstance *, int);
	virtual void getSpeed();
	virtual void getJumpPower() const;
	virtual void heal(int);
	virtual void hurtEffects(const EntityDamageSource &, int);
	virtual void getMeleeWeaponDamageBonus(Mob *);
	virtual void getMeleeKnockbackBonus();
	virtual void actuallyHurt(int, const EntityDamageSource &);
	virtual bool isInvertedHealAndHarm() const;
	virtual void pick(float, float, bool);
	virtual void travel(float, float);
	virtual void updateWalkAnim();
	virtual void aiStep();
	virtual void pushEntities();
	virtual void lookAt(Entity *, float, float);
	virtual bool canSpawn();
	virtual bool isLookingAtAnEntity();
	virtual void finalizeMobSpawn();
	virtual void shouldDespawn() const;
	virtual void getAttackAnim(float);
	virtual bool isBaby() const;
	virtual bool isTamable() const;
	virtual ItemInstance *getCarriedItem();
	virtual void setCarriedItem(const ItemInstance &);
	virtual void getItemUseDuration();
	virtual void swing();
	virtual void ate();
	virtual float getMaxHeadXRot();
	virtual Mob *getLastHurtByMob();
	virtual void setLastHurtByMob(Mob *);
	virtual Player *getLastHurtByPlayer();
	virtual void setLastHurtByPlayer(Player *);
	virtual Entity *getLastHurtMob();
	virtual void setLastHurtMob(Entity *);
	virtual Mob *getTarget();
	virtual void setTarget(Mob *);
	virtual bool canAttack(Mob *, bool);
	virtual bool isAlliedTo(Mob *);
	virtual void doHurtTarget(Entity *);
	virtual bool canBeControlledByRider();
	virtual void teleportTo(float, float, float);
	virtual void getMutableAttribute(const Attribute &);
	virtual void getAttribute(const Attribute &);
	virtual void getEquipmentCount();
	virtual void getArmorValue();
	virtual void getArmorCoverPercentage();
	virtual void hurtArmor(int);
	virtual void setArmor(const ItemInstance*);
	virtual ItemInstance* getArmor(int) const;
	virtual void getAllArmor() const;
	virtual void getAllArmor();
	virtual void getArmorTypeHash();
	virtual void dropHeldItem();
	virtual void dropAllGear(int);
	virtual void drop(const ItemInstance *, bool);
	virtual void sendInventory() const;
	virtual bool removeWhenFarAway();
	virtual int getDeathLoot();
	virtual void dropDeathLoot();
	virtual void jumpFromGround();
	virtual void pickUpItem(ItemEntity *);
	virtual void updateAi();
	virtual void newServerAiStep();
	virtual void serverAiMobStep();
	virtual float getSoundVolume();
	virtual const char *getAmbientSound();
	virtual std::string getHurtSound();
	virtual std::string getDeathSound();
	virtual std::string getStepSound();
	virtual void getDamageAfterArmorAbsorb(const EntityDamageSource &, int);
	virtual void getDamageAfterMagicAbsorb(const EntityDamageSource &, int);
	virtual bool useNewAi();
	virtual float getWalkingSpeedModifier();
	virtual bool canBeAffected(const MobEffectInstance &);
	virtual void onEffectAdded(const MobEffectInstance &);
	virtual void onEffectUpdated(const MobEffectInstance &);
	virtual void onEffectRemoved(const MobEffectInstance &);
	virtual void registerAttributes();
	void _ctor(TileSource &);
	void _ctor();
	void _doSprintParticleEffect();
	void _init();
	void _sendDirtyMobData();
	void _updateSprintingState();
	void addEffect(const MobEffectInstance &);
	void checkDespawn(Mob *);
	void checkDespawn();
	void getAllEffects();
	int getAmbientSoundInterval();
	int getMaxHealth();
	void getCurrentSwingDuration();
	void getEffect(MobEffect *);
	JumpControl *getJumpControl();
	LookControl *getLookControl();
	MoveControl *getMoveControl();
	PathNavigation *getNavigation();
	Sensing *getSensing();
	void getYHeadRot();
	bool hasAnyEffects();
	bool hasEffect(MobEffect *);
	void removeAllEffects();
	void removeEffect(int);
	void removeEffectNoUpdate(int);
	void removeEffectParticles();
	void setInvisible(bool);
	void setJumping(bool);
	void setSpeed(float);
	void setYHeadRot(float);
	void setYya(float);
	void tickEffects();
	void updateAttackAnim();
	void updateInvisibilityStatus();
	void updateMobId(EntityUniqueID &);
};
