#pragma once


// Windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define OS_WINDOWS
#endif

// Defines
#define MU_ABSTRACT =0

// Typedefs
#if defined(OS_WINDOWS) && defined(_MSC_EXTENSIONS)
  /*alternately __int128*/
  #define MU_LONG __int64 
#else
  #define MU_LONG unsigned long long
#endif
