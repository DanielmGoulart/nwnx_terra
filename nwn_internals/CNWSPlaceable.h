#ifndef _NX_NWN_STRUCT_CNWSPLACEABLE_
#define _NX_NWN_STRUCT_CNWSPLACEABLE_

struct CNWSPlaceable_s {
    CNWSObject                  obj;
    CExoLocString              *plc_firstname;
    unsigned 				__int32 field_1C8;
    CExoString                  plc_displayname;
    uint32_t                    plc_displayname_update;
    uint32_t                    plc_appearance;
    CExoLocString               plc_desc_base;
    CExoLocString               plc_desc_override;
    uint32_t                    plc_faction;
    char                        plc_conv[16];
    uint8_t                     plc_type;
    uint8_t                     field_201;
    uint8_t                     field_202;
    uint8_t                     field_203;
    uint32_t                    plc_is_ground_pile;
    nwn_objid_t                 plc_sitter;
    uint32_t                    plc_hardness;
    float                       plc_bearing;
    uint32_t                    plc_locked;
    uint32_t                    plc_key_name;
    uint32_t                    field_21C;
    uint32_t                    plc_key_req_message;
    uint32_t                    field_224;
    uint32_t                    plc_key_required;
    uint8_t                    plc_auto_remove_key;
    uint8_t                     c1;
    uint8_t                     c2;
    uint8_t                     c3;
    uint8_t                     plc_open_lock_dc;
    uint8_t                     plc_close_lock_dc;
    uint8_t                     field_232;
    uint8_t                     field_233;
    uint32_t                    plc_trap_creator;
    uint8_t                     plc_detect_dc;
    uint8_t                     field_239;
    uint8_t                     field_23A;
    uint8_t                     field_23B;
    uint32_t                    plc_trapped;
    uint32_t                    plc_disarm_dc;
    uint32_t                    plc_disarmable;
    uint32_t                    field_248;
    uint32_t                    plc_oneshot;
    uint32_t                    plc_recoverable;
    uint32_t                    plc_flagged;
    uint8_t                     plc_basetype;
    uint8_t                     field_259;
    uint8_t                     field_25A;
    uint8_t                     field_25B;
    uint32_t                    plc_active;
    uint32_t                    plc_trap_faction;
	CExoString 					OnClosed;
	CExoString 					OnDamaged;
	CExoString 					OnDeath;
	CExoString 					OnDisarm;
	CExoString 					OnHeartbeat;
	CExoString 					OnInvDisturbed;
	CExoString 					OnLock;
	CExoString 					OnMeleeAttacked;
	CExoString 					OnOpen;
	CExoString 					OnDialog;
	CExoString 					OnSpellCastAt;
	CExoString 					OnUnlock;
	CExoString 					OnUsed;
	CExoString 					OnUserDefined;
	CExoString 					OnTrapTriggered;
	CExoString 					OnClick;
    uint8_t                     plc_save_fort;
    uint8_t                     plc_save_will;
    uint8_t                     plc_save_reflex;
    uint8_t                     field_2E7;
    uint32_t                    plc_creature_list;
    uint32_t                    field_2EC;
    uint32_t                    field_2F0;
    uint32_t                    plc_has_inventory;
    uint32_t                    plc_usable;
    uint32_t                    plc_pickable;
    uint32_t                    plc_lockable;
    uint32_t                    plc_die_when_empty;
    uint32_t                    field_308;
    uint32_t                    field_30C;
    nwn_objid_t                 plc_lootable_creature;
    uint32_t                    plc_is_bodybag;
    uint32_t                    field_318;
    uint32_t                    field_31C;
    nwn_objid_t                 plc_last_opener;
    nwn_objid_t                 plc_last_closer;
    nwn_objid_t                 plc_last_user;
    nwn_objid_t                 plc_last_clicker;
    nwn_objid_t                 plc_last_triggerer;
    nwn_objid_t                 plc_last_disarmer;
    nwn_objid_t                 plc_last_locker;
    nwn_objid_t                 plc_last_unlocker;
    CItemRepository            *plc_inventory;
    uint32_t                    field_344;
    uint32_t                    field_348;
    uint32_t                    field_34C;
    uint32_t                    field_350;
    uint32_t                    field_354;
    uint32_t                    field_358;
    uint32_t                    field_35C;
    uint32_t                    field_360;
    uint32_t                    field_364;
    uint32_t                    field_368;
    uint32_t                    field_36C;
    uint32_t                    field_370;
    uint32_t                    field_374;
    uint32_t                    field_378;
    uint32_t                    field_37C;
    uint32_t                    plc_LightState;
    uint32_t                    plc_light_state_change;
    uint8_t                     plc_bodybag;
    uint8_t                     field_389;
    uint8_t                     field_38A;
    uint8_t                     field_38B;
    uint32_t                    plc_static;
    uint32_t                    plc_never_static;

	CNWSPlaceable_s(nwn_objid_t oID);
	int32_t	AcquireItem(CNWSItem **a2, nwn_objid_t oid_From, int a4, int a5, int bSendFeedBack);
	void 	AddToArea(CNWSArea *Area, Vector v, int a2);
	int 	LoadPlaceable(CResGFF *ResGFF, CResStruct *ResStruct, CExoString *Tag);
	int 	SavePlaceable(CResGFF *ResGFF, void *ResStruct);
	void 	SetScriptName(int iScript, CExoString ScriptName);
};


#endif