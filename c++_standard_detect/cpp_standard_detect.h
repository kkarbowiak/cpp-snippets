#ifndef CPP_STD_DETECT_H
#define CPP_STD_DETECT_H

#if defined(_MSVC_LANG)
    #if _MSVC_LANG >= 202002L
        #define CPP_20_PRESENT
    #elif _MSVC_LANG >= 201703L
        #define CPP_17_PRESENT
    #elif _MSVC_LANG >= 201402L
        #define CPP_14_PRESENT
    #else
        #define CPP_11_PRESENT
    #endif
#elif defined(__cplusplus)
    #if __cplusplus >= 202302L
        #define CPP_23_PRESENT
    #elif __cplusplus >= 202002L
        #define CPP_20_PRESENT
    #elif __cplusplus >= 201703L
        #define CPP_17_PRESENT
    #elif __cplusplus >= 201402L
        #define CPP_14_PRESENT
    #elif __cplusplus >= 201103L
        #define CPP_11_PRESENT
    #elif __cplusplus >= 199711L
        #define CPP_98_PRESENT
    #elif __cplusplus == 1L
        #define CPP_PRE98_PRESENT
    #endif
#endif

#endif /* CPP_STD_DETECT_H */
