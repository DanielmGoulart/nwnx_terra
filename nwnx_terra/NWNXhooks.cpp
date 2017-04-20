#include "NWNXTerra.h"
#include "stdafx.h"
#include <madCHook.h>
#include <math.h>

#include "detours\detours.h"

//CNWSCreature * asCNWCreature (CNWSObject* ob)
//{
//	if (ob->obj_generic.obj_type == OBJECT_TYPE_CREATURE) return (CNWSCreature *) ob;
//	return NULL;
//}

int NWNXhooks::override_setmode = 0;

NWNXhooks::NWNXhooks(){

	HookFunctions();
}

#define detour_hook(addr, hook, pfunc)							\
	*(DWORD*)&pfunc = addr;										\
	if(DetourAttach(&(PVOID&)pfunc, hook) == 0)					\
		_log(1,"* " #pfunc " Hooked to address %x\n", addr);	\
	else														\
		_log(1,"x " #pfunc " Failed\n")							\


BOOL NWNXhooks::HookFunctions(){

	DetourTransactionBegin();	
	DetourUpdateThread(GetCurrentThread());



	DetourTransactionCommit();

	return TRUE;
}

