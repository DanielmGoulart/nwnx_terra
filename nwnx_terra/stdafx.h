#define _CRT_SECURE_NO_WARNINGS

#if !defined(AFX_STDAFX_H__CB9F33DF_9FB8_475D_9950_1A13C9BF6C24__INCLUDED_)
#define AFX_STDAFX_H__CB9F33DF_9FB8_475D_9950_1A13C9BF6C24__INCLUDED_

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <windows.h>

#include "LogFile.h"

#define _log(a,b,...) LogFile::Instance(".\\logs.0\\nwnx_terra.txt").LOG(a, b, __VA_ARGS__)

#endif