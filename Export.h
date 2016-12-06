#ifndef _EXPORT_H
#define _EXPORT_H

#ifdef ENGINE_EXPORTS

#ifndef ENGINE_DLLCLASS_EXPORTS
#define ENGINE_DLLCLASS_EXPORTS __declspec(dllexport) 
#endif
#else
#ifndef ENGINE_DLLCLASS_EXPORTS
#define ENGINE_DLLCLASS_EXPORTS __declspec(dllimport) 
#endif

#endif

#endif