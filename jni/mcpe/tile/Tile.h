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
	static Tile *activatorRail;
	static Tile *bed;
	static Tile *beetroot;
	static Tile *bookshelf;
	static Tile *brownMushroom;
	static Tile *brownMushroomBlock;
	static Tile *cactus;
	static Tile *cake;
	static Tile *calmLava;
	static Tile *calmWater;
	static Tile *carrots;
	static Tile *clay;
	static Tile *chest;
	static Tile *cloth;
	static Tile *coalBlock;
	static Tile *coalOre;
	static Tile *cobbleWall;
	static Tile *cocoa;
	static Tile *crops;
	static Tile *deadBush;
	static Tile *diamondBlock;
	static Tile *diamondOre;
	static Tile *dirt;
	static Tile *door_iron;
	static Tile *door_wood;
	static Tile *doublePlant;
	static Tile *emeraldBlock;
	static Tile *emeraldOre;
	static Tile *endPortalFrame;
	static Tile *endStone;
	static Tile *farmland;
	static Tile *fence;
	static Tile *fenceGateAcacia;
	static Tile *fenceGateBigOak;
	static Tile *fenceGateBirch;
	static Tile *fenceGateJungle;
	static Tile *fenceGateOak;
	static Tile *fenceGateSpruce;
	static Tile *fire;
	static Tile *furnace;
	static Tile *furnace_lit;
	static Tile *glass;
	static Tile *glowingObsidian;
	static Tile *goldBlock;
	static Tile *goldOre;
	static Tile *goldenRail;
	static Tile *grass;
	static Tile *grassPathBlock;
	static Tile *gravel;
	static Tile *hardenedClay;
	static Tile *hayBlock;
	static Tile *ice;
	static Tile *info_reserved6;
	static Tile *info_updateGame1;
	static Tile *info_updateGame2;
	static Tile *invisible_bedrock;
	static Tile *ironBlock;
	static Tile *ironFence;
	static Tile *ironOre;
	static Tile *ladder;
	static Tile *lapisBlock;
	static Tile *lapisOre;
	static Tile *lava;
	static Tile *leaves;
	static Tile *leaves2;
	static Tile *lightGem;
	static Tile *litPumpkin;
	static Tile *log;
	static Tile *log2;
	static Tile *melon;
	static Tile *melonStem;
	static Tile *mobSpawner;
	static Tile *monsterStoneEgg;
	static Tile *mossStone;
	static Tile *mycelium;
	static Tile *netherBrick;
	static Tile *netherFence;
	static Tile *netherReactor;
	static Tile *netherrack;
	static Tile *obsidian;
	static Tile *packedIce;
	static Tile *podzol;
	static Tile *potatoes;
	static Tile *pumpkin;
	static Tile *pumpkinStem;
	static Tile *quartzBlock;
	static Tile *rail;
	static Tile *redBrick;
	static Tile *redFlower;
	static Tile *redMushroom;
	static Tile *redMushroomBlock;
	static Tile *redStoneDust;
	static Tile *redStoneOre;
	static Tile *redStoneOre_lit;
	static Tile *redstoneBlock;
	static Tile *reeds;
	static Tile *rock;
	static Tile *sand;
	static Tile *sandStone;
	static Tile *sapling;
	static Tile *sign;
	static Tile *snow;
	static Tile *sponge;
	static Tile *stainedClay;
	static Tile *stairs_brick;
	static Tile *stairs_netherBricks;
	static Tile *stairs_quartz;
	static Tile *stairs_sandStone;
	static Tile *stairs_stone;
	static Tile *stairs_stoneBrickSmooth;
	static Tile *stairs_wood;
	static Tile *stoneBrick;
	static Tile *stoneBrickSmooth;
	static Tile *stoneSlab;
	static Tile *stoneSlabHalf;
	static Tile *stonecutterBench;
	static Tile *tallgrass;
	static Tile *thinGlass;
	static Tile *tnt;
	static Tile *topSnow;
	static Tile *torch;
	static Tile *trapdoor;
	static Tile *unbreakable;
	static Tile *vine;
	static Tile *wallSign;
	static Tile *water;
	static Tile *waterlily;
	static Tile *web;
	static Tile *wood;
	static Tile *woodSlab;
	static Tile *woodSlabHalf;
	static Tile *woodStairsAcacia;
	static Tile *woodStairsBigOak;
	static Tile *woodStairsBirch;
	static Tile *woodStairsDark;
	static Tile *woodStairsJungle;
	static Tile *woolCarpet;
	static Tile *workBench;
	static Tile *yellowFlower;

public:
	static SoundType SOUND_SILENT;
	static SoundType SOUND_SAND;
	static SoundType SOUND_CLOTH;
	static SoundType SOUND_GLASS;
	static SoundType SOUND_METAL;
	static SoundType SOUND_STONE;
	static SoundType SOUND_GRASS;
	static SoundType SOUND_GRAVEL;
	static SoundType SOUND_WOOD;
	static SoundType SOUND_NORMAL;

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
	int renderPass; // 76
	bool canBuildOver; // 80
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
	char fill[8]; // 128
	std::string descriptionId; // 136

public:
	Tile(int, const Material *);
	Tile(int, TextureUVCoordinateSet, const Material *);
	Tile(int, std::string const&, const Material *);
	virtual ~Tile(); // 2
	virtual void onFertilized(TileSource*, int, int, int); // 4
	virtual AABB const& getShape(TileSource*, int, int, int, AABB&, bool); // 5
	virtual AABB const& getShape(unsigned char, AABB&, bool); // 6
	virtual bool isObstructingChests(TileSource*, int, int, int); // 7
	virtual bool shouldRenderFace(TileSource*, int, int, int, signed char, AABB const&) const; // 8
	virtual TextureUVCoordinateSet const& getTexture(signed char); // 9
	virtual TextureUVCoordinateSet const& getTexture(signed char, int); // 10
	virtual TextureUVCoordinateSet const& getTexture(TileSource*, int, int, int, signed char); // 11
	virtual void getTessellatedUVs(); // 12
	virtual void getCarriedTexture(signed char, int); // 13
	virtual AABB* getAABB(TileSource*, int, int, int, AABB&, int, bool, int); // 14
	virtual void addAABBs(TileSource*, int, int, int, AABB const*, std::vector<AABB, std::allocator<AABB> >&); // 15
	virtual bool isPathfindable(TileSource*, int, int, int); // 17
	virtual bool mayPick(); // 18
	virtual bool mayPick(int, bool); // 19
	virtual bool mayPlace(TileSource*, int, int, int, signed char); // 20
	virtual bool mayPlace(TileSource*, int, int, int); // 21
	virtual int getTickDelay(); // 22
	virtual void tick(TileSource*, int, int, int, Random*); // 23
	virtual void animateTick(TileSource*, int, int, int, Random*); // 24
	virtual void destroy(TileSource*, int, int, int, int); // 25
	virtual void playerWillDestroy(Player*, int, int, int, int); // 26
	virtual void neighborChanged(TileSource*, int, int, int, int, int, int); // 27
	virtual void onPlace(TileSource*, int, int, int); // 28
	virtual void onRemove(TileSource*, int, int, int); // 29
	virtual void getSecondPart(TileSource&, TilePos const&, TilePos&); // 30
	virtual void onGraphicsModeChanged(bool, bool); // 31
	virtual int getResource(int, Random*); // 32
	virtual int getResourceCount(Random*); // 33
	virtual void getDestroyProgress(Player*); // 34
	virtual void spawnResources(TileSource*, int, int, int, int, float); // 35
	virtual void spawnBurnResources(TileSource*, float, float, float); // 36
	virtual float getExplosionResistance(Entity*); // 37
	virtual void clip(TileSource*, int, int, int, Vec3 const&, Vec3 const&, bool, int); // 38
	virtual void wasExploded(TileSource*, int, int, int); // 39
	virtual bool use(Player*, int, int, int); // 40
	virtual void stepOn(Entity*, int, int, int); // 41
	virtual void fallOn(TileSource*, int, int, int, Entity*, float); // 42
	virtual int getPlacementDataValue(Mob*, int, int, int, signed char, float, float, float, int); // 43
	virtual void prepareRender(TileSource*, int, int, int); // 44
	virtual void attack(Player*, int, int, int); // 45
	virtual void handleEntityInside(TileSource*, int, int, int, Entity*, Vec3&); // 46
	virtual int getColor(int); // 47
	virtual int getColor(TileSource*, int, int, int); // 48
	virtual bool isSignalSource(); // 49
	virtual bool getSignal(TileSource*, int, int, int); // 50
	virtual int getSignal(TileSource*, int, int, int, int); // 51
	virtual int getDirectSignal(TileSource*, int, int, int, int); // 52
	virtual bool entityInside(TileSource*, int, int, int, Entity*); // 53
	virtual void playerDestroy(Player*, int, int, int, int); // 54
	virtual bool canSurvive(TileSource*, int, int, int); // 55
	virtual Tile* setNameId(std::string const&); // 60
	virtual std::string getName(ItemInstance const*) const; // 56
	virtual void triggerEvent(TileSource*, int, int, int, int, int); // 61
	virtual TextureUVCoordinateSet getTextureNum(int); // 62
	virtual void getMobToSpawn(TileSource&, TilePos const&) const; // 63
	virtual int getIconYOffset() const; // 64
	virtual void setShape(float, float, float, float, float, float); // 65
	virtual Tile* setSoundType(Tile::SoundType const&); // 66
	virtual Tile* setLightBlock(Brightness); // 67
	virtual Tile* setLightEmission(float); // 68
	virtual Tile* setExplodeable(float); // 69
	virtual Tile* setDestroyTime(float); // 70
	virtual void setTicking(bool); // 71
	virtual void getSpawnResourcesAuxValue(int); // 72
	virtual Tile* init(); // 73
	
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
	void setCategory(int);
	void transformToValidBlockId(TileID);
	void transformToValidBlockId(TileID, int, int, int);
};
