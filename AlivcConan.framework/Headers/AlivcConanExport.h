#ifndef CONAN_EXPORT_H
#define CONAN_EXPORT_H


#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
    #define CONAN_EXTERN __attribute__ ((dllexport))
  #else
    #define CONAN_EXTERN __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
  #endif
#else
#if __GNUC__ >= 4
#define CONAN_EXTERN __attribute__ ((visibility ("default")))
#else
#define CONAN_EXTERN
#endif
#endif

#endif // CONAN_EXPORT_H
