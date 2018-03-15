// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__E30B2003_188B_4EB4_AB99_3F3734D6CE6C__INCLUDED_)
#define AFX_STDAFX_H__E30B2003_188B_4EB4_AB99_3F3734D6CE6C__INCLUDED_

#pragma once

#ifdef __GNUC__
//
#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif
#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif
#endif

#ifndef __FILET__
#define __DUILIB_STR2WSTR(str)	L##str
#define _DUILIB_STR2WSTR(str)	__DUILIB_STR2WSTR(str)
#ifdef _UNICODE
#define __FILET__	_DUILIB_STR2WSTR(__FILE__)
#define __FUNCTIONT__	_DUILIB_STR2WSTR(__FUNCTION__)
#else
#define __FILET__	__FILE__
#define __FUNCTIONT__	__FUNCTION__
#endif
#endif

#define _CRT_SECURE_NO_DEPRECATE

// Remove pointless warning messages
#ifdef _MSC_VER
#pragma warning (disable : 4511) // copy operator could not be generated
#pragma warning (disable : 4512) // assignment operator could not be generated
#pragma warning (disable : 4702) // unreachable code (bugs in Microsoft's STL)
#pragma warning (disable : 4786) // identifier was truncated
#pragma warning (disable : 4996) // function or variable may be unsafe (deprecated)
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS // eliminate deprecation warnings for VS2005
#endif
#endif // _MSC_VER
#ifdef __BORLANDC__
#pragma option -w-8027		   // function not expanded inline
#endif

// Required for VS 2008 (fails on XP and Win2000 without this fix)
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif

#include "UIlib.h"

#include <ocidl.h>
#include <olectl.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))

#define lengthof(x) (sizeof(x)/sizeof(*x))
#define MAX max
#define MIN min
#define CLAMP(x,a,b) (MIN(b,MAX(a,x)))

#if !defined(T2BSTR)
extern __inline char* WcharToChar(wchar_t* wc)
{
    int len= WideCharToMultiByte(CP_ACP,0,wc,wcslen(wc),NULL,0,NULL,NULL);
    char * m_char=new char[len+1];
    WideCharToMultiByte(CP_ACP,0,wc,wcslen(wc),m_char,len,NULL,NULL);
    m_char[len]='\0';
    return m_char;
}
extern __inline wchar_t* CharToWchar(char* c)
{
    int len = MultiByteToWideChar(CP_ACP,0,c,strlen(c),NULL,0);
    wchar_t * m_wchar=new wchar_t[len+1];
    MultiByteToWideChar(CP_ACP,0,c,strlen(c),m_wchar,len);
    m_wchar[len]= L'\0';
    return m_wchar;
}
extern __inline BSTR T2BSTR(LPCTSTR lpT, BSTR bstrValue)
{
#if !defined(UNICODE) && !defined(_UNICODE)
    wchar_t * pW = CharToWchar((LPSTR)lpT);
    if(pW)
    {
        wcscpy(bstrValue, pW);
        free(pW);
    }
    return bstrValue;
#else
    return lpT;
#endif
}

#endif // T2BSTR
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__E30B2003_188B_4EB4_AB99_3F3734D6CE6C__INCLUDED_)
