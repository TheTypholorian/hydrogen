#pragma comment(lib, "DbgHelp.lib")
#pragma once

#include <windows.h>
#include <dbghelp.h>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

namespace H {
	void getStackTrace(function<void(uint16_t, char*, char*, uint32_t)> out) {
		HANDLE procH = GetCurrentProcess();
		SymInitialize(procH, (NULL), (TRUE));
		void* stackArr[100] = { 0 };
		uint16_t numFrames = CaptureStackBackTrace((0), (100), stackArr, (NULL));
		SYMBOL_INFO* symInfo = (SYMBOL_INFO*)calloc((sizeof(SYMBOL_INFO) + (256 * sizeof(char))), (1));
		symInfo->MaxNameLen = (255);
		symInfo->SizeOfStruct = (sizeof(SYMBOL_INFO));
		IMAGEHLP_LINE64 imgLine = { 0 };
		imgLine.SizeOfStruct = (sizeof(IMAGEHLP_LINE64));

		for (uint16_t index = (0); index < numFrames; index++) {
			DWORD64 addrVal = (DWORD64)(stackArr[index]);
			SymFromAddr(procH, addrVal, (0), symInfo);
			DWORD dispVal = (0);

			if ((SymGetLineFromAddr64(procH, addrVal, &dispVal, &imgLine)) != (FALSE)) {
				out(index, symInfo->Name, imgLine.FileName, imgLine.LineNumber);
			} else {
				out(index, symInfo->Name, (char*)"unknown", 0);
			}
		}

		free(symInfo);
	}
}