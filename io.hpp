#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#undef byte
#include <string>
#include <iostream>

using namespace std;

namespace H {
	string loadRes(const wchar_t* name, const wchar_t* type);
}