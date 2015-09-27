#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>
#include "Constants.h"
#include "SpacePlusCore.h"
#include "space_plus/util/SPCoreUtil.h"
#include "space_plus/recipe/RecipeManagerSP.h"
#include "mcpe/recipe/Recipes.h"

#define LOG_TAG "SpacePlusPE"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

class EntityRenderer;
class HumanoidMobRenderer;
class Mob;

ItemInstance* armorItemRendered;

static void (*_EntityRenderer$bindTexture)(EntityRenderer*, const std::string&, int);
static void EntityRenderer$bindTexture(EntityRenderer* self, const std::string& texture, int data) {
	if(texture.find("armor/") != std::string::npos /*&& !(SPCoreUtil::armorTextures[armorItemRendered->getId()].empty())*/) 
		_EntityRenderer$bindTexture(self, "mob/test_heavy_armor.png"/*SPCoreUtil::armorTextures[armorItemRendered->getId()]*/, data);
	else
		_EntityRenderer$bindTexture(self, texture, data);
}

static void (*_HumanoidMobRenderer$prepareArmor)(HumanoidMobRenderer*, Mob&, int, float);
static void HumanoidMobRenderer$prepareArmor(HumanoidMobRenderer* self, Mob& mob, int armorIndex, float f1) {
	//armorItemRendered = mob.getArmor(armorIndex);
	
	_HumanoidMobRenderer$prepareArmor(self, mob, armorIndex, f1);
}

static void (*_Item$initCreativeItems)();
static void Item$initCreativeItems() {
	_Item$initCreativeItems();
	
	SpacePlusCore::instance->preInit();
}

static void (*_Recipes$init)();
static void Recipes$init() {
	_Recipes$init();
	
	RecipeManagerSP::loadRecipes();
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	void* handle = dlopen("libminecraftpe.so", RTLD_LAZY);
	void* bl_handle = dlopen("libmcpelauncher.so", RTLD_LAZY);
	
	void* bindTexture_symbol = dlsym(handle, "_ZN14EntityRenderer11bindTextureERKSsi");
	void* prepareArmor_symbol = dlsym(handle, "_ZN19HumanoidMobRenderer12prepareArmorER3Mobif");
	
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction(bindTexture_symbol, (void*) &EntityRenderer$bindTexture, (void**) &_EntityRenderer$bindTexture);
	MSHookFunction(prepareArmor_symbol, (void*) &HumanoidMobRenderer$prepareArmor, (void**) &_HumanoidMobRenderer$prepareArmor);
	MSHookFunction((void*) &Recipes::init, (void*) &Recipes$init, (void**) &_Recipes$init);
	
	recipeTypeDefinition4 = (std::vector<Recipes::Type>(*)(char, ItemInstance, char, ItemInstance, char, ItemInstance, char, ItemInstance)) dlsym(handle, "_Z10definitionI12ItemInstanceS0_S0_S0_ESt6vectorIN7Recipes4TypeESaIS3_EEcT_cT0_cT1_cT2_");
	recipeTypeDefinition3 = (std::vector<Recipes::Type>(*)(char, ItemInstance, char, ItemInstance, char, ItemInstance)) dlsym(handle, "_Z10definitionI12ItemInstanceS0_S0_ESt6vectorIN7Recipes4TypeESaIS3_EEcT_cT0_cT1_");
	recipeTypeDefinition2 = (std::vector<Recipes::Type>(*)(char, ItemInstance, char, ItemInstance)) dlsym(handle, "_Z10definitionI12ItemInstanceS0_ESt6vectorIN7Recipes4TypeESaIS3_EEcT_cT0_");
	recipeTypeDefinition1 = (std::vector<Recipes::Type>(*)(char, ItemInstance)) dlsym(handle, "_Z10definitionI12ItemInstanceESt6vectorIN7Recipes4TypeESaIS3_EEcT_");
	
	return JNI_VERSION_1_2;
}
