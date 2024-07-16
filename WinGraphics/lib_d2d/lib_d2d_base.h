#pragma once

#ifndef LIB_EXT_D2D

	#ifndef BUILD_LIB
		#pragma comment(lib, "lib_d2d.lib")
		#define LIB_EXT_D2D __declspec(dllimport)

	#else

		#define LIB_EXT_D2D __declspec(dllexport)

	#endif


#endif
