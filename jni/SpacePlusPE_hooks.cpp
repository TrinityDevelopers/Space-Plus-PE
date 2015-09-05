#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>
#include "Constants.h"
#include "SpacePlusCore.h"

#define LOG_TAG "SpacePlusPE"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

class Minecraft;

static void (*_Minecraft$init)(Minecraft*, const std::string&);
static void Minecraft$init(Minecraft* self, const std::string& string) {
	_Minecraft$init(self, string);
	
	SpacePlusCore::instance->preInit();
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	void* handle = dlopen("libminecraftpe.so", RTLD_LAZY);
	void* bl_handle = dlopen("libmcpelauncher.so", RTLD_LAZY);
	void* Minecraft$init_symbol = dlsym(handle, "_ZN9Minecraft4initERKSs");
	
	MSHookFunction(Minecraft$init_symbol, (void*) &Minecraft$init, (void**) &_Minecraft$init);
	
	bl_armorRenders = (std::string**) dlsym(bl_handle, "bl_armorRenders");
	
	return JNI_VERSION_1_2;
}
