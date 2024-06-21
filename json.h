#include <stdio.h>
#include "for_each.h"

// _Generic is great but shit at the same time
#define FORMATTER(X) (_Generic((X), \
        int : "%d",                  char : "%c",  \
        float : "%f",                unsigned int : "%u",  \
        unsigned long : "%lu",       long long : "%lld",  \
        unsigned long long : "%llu", double : "%lf",  \
        long double : "%Lf",         char* : "\"%s\"", \
        long : "%ld",                default : "%x" \
        ))

#define STRINGIFY(var) ",""\""#var"\":""%s"
#define FMT_SPEC_NAME_COMMA(var) ,var##_FMT_STRING
#define FMT_SPEC(var) char* var##_FMT_STRING = FORMATTER(var);
#define ADD_FMT_SPEC_LEN +4 //max length of the spec in the FORMATTER MACRO
#define FMT_STRING(var, ...) "\""#var"\":""%s" FOR_EACH(STRINGIFY, __VA_ARGS__) //needed so i dont have to worry about a trailing comma

// the dumb shit of creating format strings had to be done because _Generic is a function and not a funny looking macro as it should be
#define JSON_FMT_STRING(name, ...) \
    "";{\
        FOR_EACH(FMT_SPEC, __VA_ARGS__)\
        char __FMT_SRING__[] = "{"FMT_STRING( __VA_ARGS__)"}";\
        char __OUTBUFFER__[sizeof(__FMT_SRING__)FOR_EACH_COUNT(ADD_FMT_SPEC_LEN, __VA_ARGS__)];\
        snprintf(__OUTBUFFER__, sizeof(__OUTBUFFER__), __FMT_SRING__ FOR_EACH(FMT_SPEC_NAME_COMMA, __VA_ARGS__)); \
        name = __OUTBUFFER__;\
    }

// the snprintf in this macro will change to a simple find a replace so you dont have to include stdio
// you know for when you need this for an embedded system



