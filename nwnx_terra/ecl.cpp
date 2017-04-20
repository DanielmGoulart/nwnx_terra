#include "stdafx.h"
#include "NWNXTerra.h"

CNWNXTerra Terra;

extern "C" __declspec(dllexport) CNWNXBase* GetClassObject()
{
	return &Terra;
}

BOOL APIENTRY DllMain (HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}
