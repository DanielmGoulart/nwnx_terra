#include "NWNXECL.h"
#include "stdafx.h"
#include <madCHook.h>
#include <math.h>

//CNWSCreature * asCNWCreature (CNWSObject* ob)
//{
//	if (ob->obj_generic.obj_type == OBJECT_TYPE_CREATURE) return (CNWSCreature *) ob;
//	return NULL;
//}

int NWNXhooks::override_setmode = 0;

NWNXhooks::NWNXhooks(){
	SetExperience = 0x0047D350;
	CanLevelUp = 0x00483B00;
	AIActionDropItem = 0x004C6B80;
	RemoveGold = 0x004AA6F0;
	HookFunctions();
}

int (__fastcall *CNWSCreatureStats__CanLevelUpNext)(CNWSCreatureStats *creStats, void *);

int __fastcall CNWSCreatureStats__CanLevelUp(CNWSCreatureStats *creStats, void *){
	int nLevel = creStats->GetLevel(0);

	int nBackupXP = 0;
	int nECL = creStats->cs_original->obj.obj_vartable.GetInt( CExoString( "nwnx_ecl" ) );
	
	if(nECL > 0){
		//_log(1, "* Tem ECL \n");
		nBackupXP = (*NWN_Rules)->ru_xp_level[nLevel];

		int nECLMod = nLevel + nECL;
		if(nECLMod > 40)
			nECLMod = 40;

		(*NWN_Rules)->ru_xp_level[nLevel] = (*NWN_Rules)->ru_xp_level[nECLMod];
	}

	int nRet = CNWSCreatureStats__CanLevelUpNext(creStats, NULL);

	if(nECL > 0){
		(*NWN_Rules)->ru_xp_level[nLevel] = nBackupXP;
	}

	return nRet;
}

void (__fastcall *CNWSCreatureStats__SetExperienceNext) ( CNWSCreatureStats * cre, void *, unsigned int nXPAmount, int nLevelup);

void __fastcall CNWSCreatureStats__SetExperience( CNWSCreatureStats * cre, void *, unsigned int nXPAmount, int nLevelup){
	int nLevel = cre->GetLevel(0);
	
	//XP lock
	int nAllowed = 0;
	nAllowed = cre->cs_original->obj.obj_vartable.GetInt( CExoString( "alow_xpmod" ) );
	int nRess = 0;
	nRess = cre->cs_original->obj.obj_vartable.GetInt( CExoString( "ress_bypass" ) );
	
	if(nLevel > 9 && nLevelup && !nAllowed && !nRess){
		return;
	}

	//ECL
	int nBackupXP = 0;
	int nECL = cre->cs_original->obj.obj_vartable.GetInt( CExoString( "nwnx_ecl" ) );
	
	if(nECL > 0){
		//_log(1, "* Tem ECL \n");
		nBackupXP = (*NWN_Rules)->ru_xp_level[nLevel];

		int nECLMod = nLevel + nECL;
		if(nECLMod > 40)
			nECLMod = 40;

		(*NWN_Rules)->ru_xp_level[nLevel] = (*NWN_Rules)->ru_xp_level[nECLMod];
	}

	CNWSCreatureStats__SetExperienceNext(cre, NULL, nXPAmount, nLevelup);

	if(nECL > 0){
		(*NWN_Rules)->ru_xp_level[nLevel] = nBackupXP;
	}

	return;
}

int g_funcActionDropItem = 0;
int g_goldDropped = 0;
int (__fastcall *CNWSCreature__AIActionDropItemNext)(CNWSCreature *cre, void*, int a2);

int __fastcall CNWSCreature__AIActionDropItem(CNWSCreature *cre, void*, int a2){
	int nIsGold = 0;
	if(a2)
		nIsGold = *(int*)(a2 + 68);

	g_funcActionDropItem = 1;
	int ret = CNWSCreature__AIActionDropItemNext(cre, NULL, a2);
	g_funcActionDropItem = 0;

	if(ret == 0x00000002 && nIsGold == 1 && g_goldDropped){
		nwn_objid_t oGold = *(nwn_objid_t*)(a2 + 52);
		cre->obj.obj_vartable.SetObject(CExoString("gold_obj"), oGold);
		(*NWN_VirtualMachine)->Runscript(&CExoString("nwnx_ondropgold"), cre->obj.obj_generic.obj_id );
	}

	g_goldDropped = 0;
	return ret;
}

void (__fastcall *CNWSCreature__RemoveGoldNext)(CNWSCreature *cre, void*, int a2, int a3);

void __fastcall CNWSCreature__RemoveGold(CNWSCreature *cre, void*, int a2, int a3){
	if(g_funcActionDropItem){
		g_goldDropped = 1;
	}
	CNWSCreature__RemoveGoldNext(cre, NULL, a2, a3);
}

BOOL NWNXhooks::HookFunctions(){

	if (HookCode((PVOID) SetExperience, CNWSCreatureStats__SetExperience, (PVOID*)&CNWSCreatureStats__SetExperienceNext))
			_log(1, "* SetExperience hooked\n");

	if (HookCode((PVOID) CanLevelUp, CNWSCreatureStats__CanLevelUp, (PVOID*)&CNWSCreatureStats__CanLevelUpNext))
			_log(1, "* CanLevelUp hooked\n");

	if (HookCode((PVOID) AIActionDropItem, CNWSCreature__AIActionDropItem, (PVOID*)&CNWSCreature__AIActionDropItemNext))
			_log(1, "* AIActionDropItem hooked\n");

	if (HookCode((PVOID) RemoveGold, CNWSCreature__RemoveGold, (PVOID*)&CNWSCreature__RemoveGoldNext))
			_log(1, "* RemoveGold hooked\n");

	return TRUE;
}

