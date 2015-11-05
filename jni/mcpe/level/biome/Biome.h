#pragma once

class BiomeDecorator;
class Random;
class TilePos;
class TileSource;
class LevelChunk;

class Biome
{
public:
	enum BiomeType
	{
		BEACH = 0;
		DESERT;
		EXTREME_HILLS;
		FOREST = 4;
		HELL;
		ICE;
		JUNGLE;
		MESA;
		MUSHROOM;
		OCEAN;
		PLAINS;
		RIVER;
		SAVANNA;
		STONE_BEACH;
		SWAMP;
		TAIGA;
		SKY;
	};
	
public:
	static Biome* plains;
	static Biome* hell;
	static Biome* ocean;
	static Biome* desert;
	static Biome* forest;
	static Biome* birchForest;
	static Biome* roofedForest;
	static Biome* taiga;
	static Biome* redwoodTaiga;
	static Biome* taigaCold;
	static Biome* iceFlats;
	static Biome* jungle;
	static Biome* extremeHills;
	static Biome* savanna;
	static Biome* savannaRock;
	static Biome* mesaRock;
	static Biome* deepOcean;
	static Biome* desertHills;
	static Biome* forestHills;
	static Biome* birchForestHills;
	static Biome* taigaHills;
	static Biome* redwoodTaigaHills;
	static Biome* taigaColdHills;
	static Biome* iceMountains;
	static Biome* jungleHills;
	static Biome* mesa;
	static Biome* extremeHillsWithTrees;
	static Biome* jungle;
	static Biome* extremeHills;
	static Biome* savanna;
	static Biome* savannaRock;
	static Biome* mesaRock;
	
public:
	static Biome* DEFAULT;
	static Biome* biomes[256];

public:
	Biome(int, Biome::BiomeType, BiomeDecorator *);
	virtual void setColor(int);
	virtual void setColor(int, bool);
	virtual ~Biome();
	virtual void getTreeFeature(Random *);
	virtual void getGrassFeature(Random *);
	virtual void getTemperature();
	virtual void adjustScale(float);
	virtual void adjustDepth(float);
	virtual void getSkyColor(float);
	virtual void getMobs(int);
	virtual void getCreatureProbability();
	virtual void getFoliageColor();
	virtual void getRandomFlowerTypeAndData(Random &, const TilePos &);
	virtual void decorate(TileSource *, Random &, const TilePos &, bool, float);
	virtual void buildSurfaceAt(Random &, LevelChunk &, const TilePos &, float);
	virtual void getGrassColor(const TilePos &);
	virtual void refreshBiome(unsigned int);
	virtual void getTemperatureCategory() const;
	virtual void isSame(Biome *);
	virtual void isHumid();
	virtual void createMutatedCopy(int);
};
