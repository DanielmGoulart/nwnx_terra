#if !defined(NWNXHOOKS_H_)
#define NWNXHOOKS_H_


class NWNXhooks{
public:
	NWNXhooks();
	static int override_setmode;

private:
	DWORD SetExperience;
	DWORD CanLevelUp;
	DWORD AIActionDropItem;
	DWORD RemoveGold;
	//static void __fastcall CNWSCreature__ResolveRangedSpecialAttack(CNWSCreature * cre, void*, CNWSObject * obj, int arg1 );

	BOOL HookFunctions();

};

#endif