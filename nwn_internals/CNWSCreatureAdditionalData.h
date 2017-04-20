#ifndef _NX_NWN_STRUCT_CNWSCREATUREADDITIONALDATA_
#define _NX_NWN_STRUCT_CNWSCREATUREADDITIONALDATA_

struct CNWSCreatureAdditionalData_s{
	nwn_objid_t blood_pact_target;
	nwn_objid_t blood_pact_source;
	int blood_pool;
	nwn_objid_t critical_focus_target;
	int critical_focus_bonus;
};

#endif /* _NX_NWN_STRUCT_CNWSCREATUREADDITIONALDATA_ */