#pragma once

#include <vector>
#include <string>
class Model;
class Matrix;
class TextureOffset;

// Size : 128
class ModelPart
{
public:
	float rotationPointX;	// 0
	float rotationPointY;	// 4
	float rotationPointZ;	// 8
	float rotateAngleX;		// 12
	float rotateAngleY;		// 16
	float rotateAngleZ;		// 20
	bool mirror;			// 24
	float offsetX;			// 28
	float offsetY;			// 32
	float offsetZ;			// 36
	std::vector<ModelPart *> childModels;	// 40
	int textureWidth;		// 52
	int textureHeight;		// 56
	char filler1[4];		// 60
	int textureOffsetX;		// 64
	int textureOffsetY;		// 68
	bool isHidden;			// 72
	char filler2[76];		// 76
	Model *baseModel;		// 152

public:
	ModelPart(ModelPart &&);
	ModelPart(int, int, int, int);
	ModelPart(Model *, int, int, int, int);
	~ModelPart();
	void addBox(float, float, float, int, int, int, float);
	void addBoxMapTex(float, float, float, int, int, int, TextureOffset);
	void addChild(ModelPart *);
	void compile(float);
	void draw(float);
	void mimic(const ModelPart *);
	void operator=(ModelPart &&);
	void render(float);
	void reset(void);
	void setModel(Model *);
	void setNeverRender(bool);
	void setPos(float, float, float);
	void setTexSize(int, int);
	void texOffs(int, int);
	void translateTo(Matrix &, float);
};
