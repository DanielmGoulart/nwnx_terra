#include "stdafx.h"
#include "NWNXECL.h"
#include "IniFile.h"

CNWNXECL::CNWNXECL(){

}

CNWNXECL::~CNWNXECL(){
	OnRelease();
	delete pHooks;
}

BOOL CNWNXECL::OnCreate (const char* LogDir){
	char buf[256];

	// initialize the base class
	sprintf (buf, "%s\\nwnx_ecl.txt", LogDir);
	if (!CNWNXBase::OnCreate (buf))
		return FALSE;
	
	// write copy information to the log file
	_log (0,"NWNX2 ECL 0.0.1.\n");
	_log (0,"Created by zelkin\n\n");
	
	pHooks = new NWNXhooks();

	return TRUE;
}

char* CNWNXECL::OnRequest(char* gameObject, char* Request, char* Parameters){


	return NULL;
}

BOOL CNWNXECL::OnRelease( ){

	Log( 0,"o Shutting down\n" );
	
	return CNWNXBase::OnRelease();
}