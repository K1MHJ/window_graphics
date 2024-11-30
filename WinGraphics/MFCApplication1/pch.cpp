// pch.cpp: source file corresponding to the pre-compiled header

#include "pch.h"

// When you are using pre-compiled headers, this source file is necessary for compilation to succeed.
void DebugMsg(const char* format, ...)
{
#ifdef _DEBUG
	char str[128];
	va_list args;
	va_start(args, format);
	vsprintf_s(str, 128, format, args);
	OutputDebugStringA(str);
	va_end(args);
#endif
}
void DebugMsg_W(const WCHAR* format, ...)
{
#ifdef _DEBUG
	WCHAR str[128];
	va_list args;
	va_start(args, format);
	vswprintf_s(str, 128, format, args);
	OutputDebugStringW(str);
	va_end(args);
#endif
}
