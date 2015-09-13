#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>
#include "Constants.h"
#include "SpacePlusCore.h"

#define LOG_TAG "SpacePlusPE"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

static void (*_Item$initCreativeItems)();
static void Item$initCreativeItems() {
	SpacePlusCore::instance->preInit();
	
	_Item$initCreativeItems();
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	void* handle = dlopen("libminecraftpe.so", RTLD_LAZY);
	void* bl_handle = dlopen("libmcpelauncher.so", RTLD_LAZY);
	
	MSHookFunction((void*) Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	
	bl_armorRenders = (std::string**) dlsym(bl_handle, "bl_armorRenders");
	
	return JNI_VERSION_1_2;
}
