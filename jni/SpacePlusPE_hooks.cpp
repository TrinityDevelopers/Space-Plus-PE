#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>
#include "Constants.h"
#include "space_plus/proxy/ClientProxyCore.h"
#include "space_plus/items/SPItems.h"

#define LOG_TAG "SpacePlusPE"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

static void (*_Item$initItems)();
static void Item$initItems() {
	_Item$initItems();
	
	SPItems::initItems();
}

static void (*_Item$initCreativeItems)();
static void Item$initCreativeItems() {
	SPItems::initCreativeItems();
	
	_Item$initCreativeItems();
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	void* handle = dlopen("libminecraftpe.so", RTLD_LAZY);
	void* bl_handle = dlopen("libmcpelauncher.so", RTLD_LAZY);
	
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	
	ClientProxyCore::bl_armorRenders = (std::array <std::string, 4096>*) dlsym(bl_handle, "bl_armorRenders");
	
	return JNI_VERSION_1_2;
}
