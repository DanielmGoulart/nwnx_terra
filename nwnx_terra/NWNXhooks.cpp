#include "NWNXTerra.h"
#include "stdafx.h"
#include <math.h>
#include <nwn_const.h>

#include "detours\detours.h"

#pragma region NWServer Calls
DWORD CNWSObject__DoDamageImmunityOffset = 0x004E1A00;
__declspec( naked ) int __fastcall CNWSObject__DoDamageImmunity(CNWSObject *cre, void *, CNWSCreature *Attacker,  int DamageDelivered, int DamageFlags, int _bMaxDamage, int bFeedback){__asm{ jmp dword ptr [CNWSObject__DoDamageImmunityOffset] }}
DWORD CNWSObject__DoDamageResistanceOffset = 0x004E07D0;
__declspec( naked ) int __fastcall CNWSObject__DoDamageResistance(CNWSObject *pTHIS, void*, CNWSCreature *attacker, int nDamage, signed int damageType, int a5, int a6, int a7){__asm{ jmp dword ptr [CNWSObject__DoDamageResistanceOffset] }}
#pragma endregion

#pragma region Globals
bool g_GetDamageRollFlag = false;
#pragma endregion

NWNXhooks::NWNXhooks(){
	HookFunctions();
}

__int16 (__fastcall *CNWSCreatureStats__GetDamageRoll)(CNWSCreatureStats *creStats, void *, CNWSObject *Defender, int bOffHand, int AttackResult, int SneakAttack, int DeathAttack, int a7);
__int16 __fastcall CNWSCreatureStats__GetDamageRoll_Hook(CNWSCreatureStats *creStats, void *, CNWSObject *Defender, int bOffHand, int AttackResult, int SneakAttack, int DeathAttack, int a7){
	g_GetDamageRollFlag = true;
	__int16 ret = CNWSCreatureStats__GetDamageRoll(creStats, nullptr, Defender, bOffHand, AttackResult, SneakAttack, DeathAttack, a7);
	g_GetDamageRollFlag = false;
	
	char cClassPos = 0;
	do{
		if(creStats->cs_classes[cClassPos].cl_class == CLASS_TYPE_BLACKGUARD){
			int nDamage = creStats->cs_cha_mod;

			int nHalfLevel = creStats->cs_classes[cClassPos].cl_level/2;

			if(nDamage > nHalfLevel){
				nDamage = nHalfLevel;
			}

			CNWSCombatAttackData *CurrAttack = creStats->cs_original->cre_combat_round->GetAttack(creStats->cs_original->cre_combat_round->CurrentAttack);
			if(CurrAttack->AttackResult == 3 || CurrAttack->AttackResult == 10){
				nDamage *= creStats->GetCriticalHitMultiplier(0);
			}

			nDamage = CNWSObject__DoDamageImmunity(Defender, nullptr, creStats->cs_original, nDamage, DAMAGE_TYPE_NEGATIVE, a7, 1);
			nDamage = CNWSObject__DoDamageResistance(Defender, nullptr, creStats->cs_original, nDamage, DAMAGE_TYPE_NEGATIVE, a7, 1, 0);

			if(nDamage > 0)
				CurrAttack->Damage_Negative += (nDamage + 1);


		}
		cClassPos++;
	}while(cClassPos < creStats->cs_classes_len);

	return ret;
}

int (__fastcall *CNWSCreatureStats__GetAttackModifierVersus) (CNWSCreatureStats * creStats, void*, CNWSCreature *cre);
int __fastcall CNWSCreatureStats__GetAttackModifierVersus_Hook (CNWSCreatureStats * creStats, void*, CNWSCreature *cre){
	int nRet =  CNWSCreatureStats__GetAttackModifierVersus(creStats, nullptr, cre);
	
	nRet += creStats->GetFavoredEnemyBonus(cre);

	return nRet;
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

	detour_hook( 0x004764D0, CNWSCreatureStats__GetDamageRoll_Hook, CNWSCreatureStats__GetDamageRoll);
	detour_hook( 0x00470F00, CNWSCreatureStats__GetAttackModifierVersus_Hook, CNWSCreatureStats__GetAttackModifierVersus);


	DetourTransactionCommit();

	return TRUE;
}

