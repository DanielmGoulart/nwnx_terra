#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void			(__thiscall *CNWSCombatRound__ClearAllAttacks)(CNWSCombatRound* pTHIS) = (void (__thiscall*)(CNWSCombatRound* pTHIS))0x00530980;
CNWSItem *		(__thiscall *CNWSCombatRound__GetCurrentAttackWeapon)(CNWSCombatRound *pTHIS, uint32_t a2) = (CNWSItem* (__thiscall*)(CNWSCombatRound *pTHIS, uint32_t a2))0x00532C90;
void			(__thiscall *CNWSCombatRound__StartCombatRound)(CNWSCombatRound *pTHIS, nwn_objid_t oidDefender) = (void (__thiscall *)(CNWSCombatRound *pTHIS, nwn_objid_t oidDefender))0x0052FA00;
int				(__thiscall *CNWSCombatRound__GetWeaponAttackType)(CNWSCombatRound *pTHIS) = (int(__thiscall*)(CNWSCombatRound *pTHIS))0x00532DB0;
void			(__thiscall *CNWSCombatRound__AddSpecialAttack)(CNWSCombatRound *pTHIS, short int iSpecialAttack) = (void(__thiscall*)(CNWSCombatRound *pTHIS,short int iSpecialAttack))0x00531000;

void CNWSCombatRound_s::ClearAllAttacks() {
	CNWSCombatRound__ClearAllAttacks(this);
}

CNWSItem *CNWSCombatRound_s::GetCurrentAttackWeapon(uint32_t a2) {
	return CNWSCombatRound__GetCurrentAttackWeapon(this, a2);
}

void CNWSCombatRound_s::StartCombatRound(nwn_objid_t oidDefender) {
	return CNWSCombatRound__StartCombatRound(this, oidDefender);
}

CNWSCombatAttackData *CNWSCombatRound_s::GetAttack(int a2) {
	if (a2<50) return &this->AttackData[a2];
	else return &this->AttackData[49];
}

int CNWSCombatRound_s::GetWeaponAttackType() {
	return CNWSCombatRound__GetWeaponAttackType(this);
}

void CNWSCombatRound_s::AddSpecialAttack(short int a2){
	return CNWSCombatRound__AddSpecialAttack(this,a2);
}