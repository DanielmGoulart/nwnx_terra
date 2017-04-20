#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

char (__thiscall *CNWSpell__GetSpellLevel)(CNWSpell *pTHIS, unsigned char a1) = (char(__thiscall*)(CNWSpell *pTHIS, unsigned char a1))0x00502AC0;

char CNWSpell::GetSpellLevel(char a1){
	return CNWSpell__GetSpellLevel(this, a1);
}