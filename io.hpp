#include <windows.h>
#include <string>
#include <iostream>

using namespace std;

namespace H {
	string loadRes(const wchar_t* name, const wchar_t* type) {
		HMODULE hModule = GetModuleHandle(NULL);
		HRSRC hRes = FindResource(hModule, name, type);
		if (!hRes) {
			wcerr << L"Unable to find resource " << name << " (" << GetLastError() << ")" << endl;
			return "";
		}

		HGLOBAL hData = LoadResource(hModule, hRes);
		if (!hData) {
			wcerr << L"Unable to load resource " << name << " (" << GetLastError() << ")" << endl;
			return "";
		}

		DWORD size = SizeofResource(hModule, hRes);
		LPVOID data = LockResource(hData);
		if (!data) {
			wcerr << L"Unable to lock resource " << name << " (" << GetLastError() << ")" << endl;
			return "";
		}

		return string((char*)data, size);
	}
}