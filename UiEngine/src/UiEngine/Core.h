#pragma once

#ifdef UI_PLATFORM_WINDOWS
    #define	UI_API
#elif UI_PLATFORM_LINUX
	#define UI_API __attribute__((visibility("default")))
#endif

#define BIT(x) (1 << x)