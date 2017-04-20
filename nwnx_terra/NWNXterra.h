#if !defined(NWNXFEATS_H_)
#define NWNXFEATS_H_

#include <NWNXBase.h>
#include <nwn_internals.h>
#include "NWNXhooks.h"


class CNWNXTerra: public CNWNXBase{
public:
	CNWNXTerra();
	~CNWNXTerra();

	// overloaded functions
    BOOL OnCreate (const char* LogDir);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    BOOL OnRelease();

private:
	NWNXhooks *pHooks;

};

#endif