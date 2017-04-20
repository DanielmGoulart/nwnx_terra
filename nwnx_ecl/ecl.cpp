#include "stdafx.h"
#include "NWNXECL.h"

CNWNXECL Feats;

extern "C" __declspec(dllexport) CNWNXBase* GetClassObject()
{
	return &Feats;
}

BOOL APIENTRY DllMain (HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}
