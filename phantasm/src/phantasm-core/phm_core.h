#pragma once
#ifndef _PMH_CORE_H_
#define _PMH_CORE_H_

#ifdef PHANTASMCORE_EXPORTS
#define PHM_CORE_API __declspec(dllexport) 
#else
#define PHM_CORE_API __declspec(dllimport) 
#endif

#endif // _PMH_CORE_H_
