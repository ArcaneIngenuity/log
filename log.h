#ifndef COM_ARCANEINGENUITY_LOG_H

#include <stdio.h>
#include <stdarg.h>

#ifndef LOG_TAG
	#define LOG_TAG unknown
#endif//

#include <stdarg.h> //for vprintf -- to console

#ifdef _WIN32
	//define something for Windows (32-bit and 64-bit, this part is common)
	#define LOGI(...) (printf(__VA_ARGS__))
	#define LOGW(...) (printf(__VA_ARGS__))
	#ifdef _WIN64
		//define something for Windows (64-bit only)
	#endif
#elif __APPLE__
	#include "TargetConditionals.h"
	#if TARGET_OS_IPHONE
		#if TARGET_IPHONE_SIMULATOR
		#else //actual device
		#endif
		// iOS Simulator
	#elif TARGET_OS_MAC
		// Mac OS
		#define DESKTOP 1
	#else
		// Unsupported platform
	#endif
#elif __ANDROID__
	#include <android/log.h>
	#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "LOG_TAG", __VA_ARGS__))
	#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "LOG_TAG", __VA_ARGS__))
#elif __linux
	// linux
	#define LOGI(...) (printf(__VA_ARGS__))
	#define LOGW(...) (printf(__VA_ARGS__))
#elif __unix // all unices not caught above
	// Unix
#elif __posix
	// POSIX
#endif

#endif//COM_ARCANEINGENUITY_LOG_H