#include "stdafx.h"
#include "NWNXterra.h"
#include "IniFile.h"

CNWNXTerra::CNWNXTerra(){

}

CNWNXTerra::~CNWNXTerra(){
	OnRelease();
	delete pHooks;
}

BOOL CNWNXTerra::OnCreate (const char* LogDir){
	char buf[256];

	// initialize the base class
	sprintf (buf, "%s\\nwnx_terra.txt", LogDir);
	if (!CNWNXBase::OnCreate (buf))
		return FALSE;
	
	// write copy information to the log file
	_log (0,"NWNX2 Terra 0.0.1.\n");
	_log (0,"Created by zelkin\n\n");
	
	pHooks = new NWNXhooks();

	return TRUE;
}

char* CNWNXTerra::OnRequest(char* gameObject, char* Request, char* Parameters){


	return NULL;
}

BOOL CNWNXTerra::OnRelease( ){

	Log( 0,"o Shutting down\n" );
	
	return CNWNXBase::OnRelease();
}