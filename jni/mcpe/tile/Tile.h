#pragma once

#include <string>
#include <memory>
#include "../tileentity/TileEntityType.h"
#include "../client/renderer/texture/TextureUVCoordinateSet.h"
#include "../client/renderer/texture/TextureAtlasTextureItem.h"
#include "../util/AABB.h"
#include "../CommonTypes.h"

class TextureAtlas;
class Material;
class TileSource;
class Random;
class Player;
class TilePos;
class Entity;
class Vec3;
class Mob;
class ItemInstance;
typedef int TileType;

// Size : 140
class Tile
{
public:
	// Size : 12
	class SoundType
	{
	public:
		float volume;			// 0
		float frequency;		// 4
		std::string breakSound; // 8
		std::string stepOnSound;  // 12
	public:
		SoundType(const std::string &, float, float);
		~SoundType();
	};

public:
	static Tile* activatorRail;
	static Tile* anvil;
	static Tile* bed;
	static Tile* beetroot;
	static Tile* bookshelf;
	static Tile* brewing_stand;
	static Tile* brownMushroom;
	static Tile* brownMushroomBlock;
	static Tile* cactus;
	static Tile* cake;
	static Tile* calmLava;
	static Tile* calmWater;
	static Tile* carrots;
	static Tile* chest;
	static Tile* clay;
	static Tile* cloth;
	static Tile* coalBlock;
	static Tile* coalOre;
	static Tile* cobbleWall;
	static Tile* cocoa;
	static Tile* deadBush;
	static Tile* diamondBlock;
	static Tile* diamondOre;
	static Tile* dirt;
	static Tile* door_iron;
	static Tile* door_wood;
	static Tile* doublePlant;
	static Tile* emeraldBlock;
	static Tile* emeraldOre;
	static Tile* enchantingTable;
	static Tile* endPortalFrame;
	static Tile* endStone;
	static Tile* farmland;
	static Tile* fence;
	static Tile* fenceGateAcacia;
	static Tile* fenceGateBigOak;
	static Tile* fenceGateBirch;
	static Tile* fenceGateJungle;
	static Tile* fenceGateOak;
	static Tile* fenceGateSpruce;
	static Tile* fire;
	static Tile* flowerPot;
	static Tile* furnace;
	static Tile* furnace_lit;
	static Tile* glass;
	static Tile* glowingObsidian;
	static Tile* goldBlock;
	static Tile* goldOre;
	static Tile* goldenRail;
	static Tile* grass;
	static Tile* grassPathBlock;
	static Tile* gravel;
	static Tile* hardenedClay;
	static Tile* hayBlock;
	static Tile* ice;
	static Tile* info_reserved6;
	static Tile* info_updateGame1;
	static Tile* info_updateGame2;
	static Tile* invisible_bedrock;
	static Tile* ironBlock;
	static Tile* ironFence;
	static Tile* ironOre;
	static Tile* ladder;
	static Tile* lapisBlock;
	static Tile* lapisOre;
	static Tile* lava;
	static Tile* leaves;
	static Tile* leaves2;
	static Tile* lightGem;
	static Tile* litPumpkin;
	static Tile* log;
	static Tile* log2;
	static Tile* melon;
	static Tile* melonStem;
	static Tile* mobSpawner;
	static Tile* monsterStoneEgg;
	static Tile* mossStone;
	static Tile* mycelium;
	static Tile* netherBrick;
	static Tile* netherFence;
	static Tile* netherReactor;
	static Tile* netherWart;
	static Tile* netherrack;
	static Tile* obsidian;
	static Tile* packedIce;
	static Tile* podzol;
	static Tile* portal;
	static Tile* potatoes;
	static Tile* pumpkin;
	static Tile* pumpkinStem;
	static Tile* quartzBlock;
	static Tile* quartzOre;
	static Tile* rail;
	static Tile* redBrick;
	static Tile* redFlower;
	static Tile* redMushroom;
	static Tile* redMushroomBlock;
	static Tile* redStoneDust;
	static Tile* redStoneOre;
	static Tile* redStoneOre_lit;
	static Tile* redstoneBlock;
	static Tile* reeds;
	static Tile* rock;
	static Tile* sand;
	static Tile* sandStone;
	static Tile* sapling;
	static Tile* sign;
	static Tile* skull;
	static Tile* snow;
	static Tile* soulSand;
	static Tile* sponge;
	static Tile* stainedClay;
	static Tile* stairs_brick;
	static Tile* stairs_netherBricks;
	static Tile* stairs_quartz;
	static Tile* stairs_sandStone;
	static Tile* stairs_stone;
	static Tile* stairs_stoneBrickSmooth;
	static Tile* stairs_wood;
	static Tile* stoneBrick;
	static Tile* stoneBrickSmooth;
	static Tile* stoneSlab;
	static Tile* stoneSlabHalf;
	static Tile* stonecutterBench;
	static Tile* tallgrass;
	static Tile* thinGlass;
	static Tile* tnt;
	static Tile* topSnow;
	static Tile* torch;
	static Tile* trapdoor;
	static Tile* unbreakable;
	static Tile* vine;
	static Tile* wallSign;
	static Tile* water;
	static Tile* waterlily;
	static Tile* web;
	static Tile* wheat;
	static Tile* wood;
	static Tile* woodSlab;
	static Tile* woodSlabHalf;
	static Tile* woodStairsAcacia;
	static Tile* woodStairsBigOak;
	static Tile* woodStairsDark;
	static Tile* woodStairsBirch;
	static Tile* woodStairsJungle;
	static Tile* woolCarpet;
	static Tile* workBench;
	static Tile* yellowFlower;

public:
	static SoundType SOUND_ANVIL;
	static SoundType SOUND_CLOTH;
	static SoundType SOUND_GLASS;
	static SoundType SOUND_GRASS;
	static SoundType SOUND_GRAVEL;
	static SoundType SOUND_LADDER;
	static SoundType SOUND_METAL;
	static SoundType SOUND_NORMAL;
	static SoundType SOUND_SAND;
	static SoundType SOUND_SILENT;
	static SoundType SOUND_SNOW;
	static SoundType SOUND_STONE;
	static SoundType SOUND_WOOD;

public:
	static bool shouldTick[255];
	static float translucency[255];
	static bool solid[255];
	static float lightEmission[255];
	static uint_fast8_t lightBlock[255];
	static Tile *tiles[255];

public:
	static TextureAtlas *_terrainTextureAtlas;
	static const char *TILE_DESCRIPTION_PREFIX;

public:
	//void **vtable;					// 0
	bool replaceable; // 4
	AABB hitbox; // 8
	TextureUVCoordinateSet tex; // 36
	unsigned char id; // 68
	const Tile::SoundType* soundType; // 72
	bool canBuildOver; // 76
	int renderPass; // 80
	int renderType; // 84
	int tileType; // 88
	int tileEntityType; // 92
	float thickness; // 96
	bool canSlide; // 100
	bool canInstaTick; // 101
	float gravity; // 104
	Material* material; // 108
	float friction; // 112
	float destroyTime; // 116
	float explosionResistance; // 120
	int category; // 124
	bool fancy;  // 128
	unsigned int textureIsotropic; // 132
	std::string descriptionId; // 136

public:
	Tile(int, const Material *);
	Tile(int, TextureUVCoordinateSet, const Material *);
	Tile(int, std::string const&, const Material *);
	virtual ~Tile();
	virtual void onFertilized(TileSource*, int, int, int);
	virtual AABB const& getVisualShape(TileSource*, int, int, int, AABB&, bool);
	virtual AABB const& getVisualShape(unsigned char, AABB&, bool);
	virtual AABB const& getCollisionShape(AABB&, TileSource&, int, int, int);
	virtual bool isObstructingChests(TileSource*, int, int, int);
	virtual bool shouldRenderFace(TileSource*, int, int, int, signed char, const AABB&) const;
	virtual TextureUVCoordinateSet const& getTexture(signed char);
	virtual TextureUVCoordinateSet const& getTexture(signed char, int);
	virtual TextureUVCoordinateSet const& getTexture(TileSource*, int, int, int, signed char);
	virtual void getTessellatedUVs();
	virtual void getCarriedTexture(signed char, int);
	virtual AABB* getAABB(TileSource*, int, int, int, AABB&, int, bool, int);
	virtual void addAABBs(TileSource*, int, int, int, const AABB*, std::vector<AABB, std::allocator<AABB>>&);
	virtual void addCollisionShapes(TileSource&, int, int, int, const AABB*, std::vector<AABB, std::allocator<AABB>>&);
	virtual int getRenderLayer(TileSource*, TilePos const&) const; 
	virtual float getThickness() const;
	virtual bool isCropTile() const;
	virtual bool isContainerTile() const;
	virtual bool isCraftingTile() const;
	virtual bool isInteractiveTile() const;
	virtual bool isPathfindable(Entity*, const TilePos&, int, int, int);
	virtual bool mayPick();
	virtual bool mayPick(TileSource*, int, bool); 
	virtual bool mayPlace(TileSource*, int, int, int, signed char);
	virtual bool mayPlace(TileSource*, int, int, int);
	virtual void tryToPlace(TileSource*, TilePos const&, unsigned char); 
	virtual void tick(TileSource*, int, int, int, Random*);
	virtual void animateTick(TileSource*, int, int, int, Random*);
	virtual void destroy(TileSource*, int, int, int, int, Entity*);
	virtual void playerWillDestroy(Player*, int, int, int, int);
	virtual void neighborChanged(TileSource*, int, int, int, int, int, int);
	virtual void onPlace(TileSource*, int, int, int);
	virtual void onRemove(TileSource*, int, int, int);
	virtual void getSecondPart(TileSource&, TilePos const&, TilePos&);
	virtual void onGraphicsModeChanged(bool, bool);
	virtual int getResource(Random*, int, int); 
	virtual int getResourceCount(Random*, int, int); 
	virtual void getDestroyProgress(Player*);
	virtual void spawnResources(TileSource*, int, int, int, int, float, int); 
	virtual void spawnBurnResources(TileSource*, float, float, float);
	virtual float getExplosionResistance(Entity*);
	virtual void clip(TileSource*, int, int, int, const Vec3&, const Vec3&, bool, int);
	virtual void wasExploded(TileSource*, int, int, int, Entity*);
	virtual bool use(Player*, int, int, int);
	virtual void stepOn(Entity*, int, int, int);
	virtual void fallOn(TileSource*, int, int, int, Entity*, float);
	virtual int getPlacementDataValue(Mob*, int, int, int, signed char, float, float, float, int);
	virtual void prepareRender(TileSource*, int, int, int);
	virtual void attack(Player*, int, int, int);
	virtual void handleEntityInside(TileSource*, int, int, int, Entity*, Vec3&);
	virtual int getColor(int);
	virtual int getColor(TileSource*, int, int, int);
	virtual bool isSeasonTinted(TileSource*, TilePos const&) const;
	virtual bool isSignalSource();
	virtual bool getSignal(TileSource*, int, int, int);
	virtual int getSignal(TileSource*, int, int, int, int);
	virtual int getDirectSignal(TileSource*, int, int, int, int);
	virtual bool entityInside(TileSource*, int, int, int, Entity*);
	virtual void playerDestroy(Player*, int, int, int, int);
	virtual bool canSurvive(TileSource*, int, int, int);
	virtual int getExperienceDrop(Random*) const;
	virtual bool canBeBuiltOver(TileSource&, int, int, int) const;
	virtual Tile* setNameId(const std::string&);
	virtual std::string getName(const ItemInstance*) const;
	virtual void triggerEvent(TileSource*, int, int, int, int, int);
	virtual TextureUVCoordinateSet getTextureNum(int);
	virtual void getMobToSpawn(TileSource&, const TilePos&) const;
	virtual int getIconYOffset() const;
	virtual bool shouldStopFalling(Entity*);
	virtual float calcGroundFriction(Mob*, const TilePos&) const;
	virtual bool canHaveExtraData() const;
	virtual void setVisualShape(float, float, float, float, float, float);
	virtual Tile* setSoundType(const Tile::SoundType&);
	virtual Tile* setLightBlock(Brightness);
	virtual Tile* setLightEmission(float);
	virtual Tile* setExplodeable(float);
	virtual Tile* setDestroyTime(float);
	virtual Tile* setFriction(float);
	virtual void setTicking(bool);
	virtual void getSpawnResourcesAuxValue(int);
	virtual Tile* init();
	virtual bool _canBeSilkTouched() const;
	virtual ItemInstance* getSilkTouchItemInstance(int);
	
	static void initTiles();
	static Tile *getLightEmission(TileID);
	static TextureAtlasTextureItem getTextureItem(const std::string &);
	static TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string &, int);
	static Material *getTileMaterial(int);
	static bool isFaceVisible(TileSource *, int, int, int, signed char);
	static bool isTileType(const FullTile &, TileType);
	static void setTextureAtlas(std::shared_ptr<TextureAtlas>);
	static void teardownTiles();
	void _getTypeToSpawn(TileSource &, int, const TilePos &) const;
	void addAABB(const AABB &, const AABB *, std::vector<AABB> &);
	void destroyEffect(TileSource &, const TilePos &, const Vec3 &);
	float getShadeBrightness() const;
	bool isLiquidTile() const;
	bool isObstructingChests(TileSource *, const TilePos &);
	void popResource(TileSource *, int, int, int, const ItemInstance &);
	Tile* setCategory(int);
	void transformToValidBlockId(TileID);
	void transformToValidBlockId(TileID, int, int, int);
};
