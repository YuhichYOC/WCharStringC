#ifndef INCLUDE_STDIO_H
#define INCLUDE_STDIO_H
#include <stdio.h>
#endif

#ifndef INCLUDE_STDLIB_H
#define INCLUDE_STDLIB_H
#include <stdlib.h>
#endif

#ifndef INCLUDE_STRING_H
#define INCLUDE_STRING_H
#include <string.h>
#endif

#ifndef INCLUDE_ERRNO_H
#define INCLUDE_ERRNO_H
#include <errno.h>
#endif

#ifndef INCLUDE_LOCALE_H
#define INCLUDE_LOCALE_H
#include <locale.h>
#endif

#ifndef INCLUDE_WCHAR_H
#define INCLUDE_WCHAR_H
#include <wchar.h>
#endif

#ifndef DECLARE_WCHARSTRING_H
#define DECLARE_WCHARSTRING_H

typedef struct _wchar_string {
    int length;
    char * value;
    struct _wchar_string * (* assign)(struct _wchar_string *, char *);
    struct _wchar_string * (* wassign)(struct _wchar_string *, wchar_t *);
    struct _wchar_string * (* append)(struct _wchar_string *, char *);
    struct _wchar_string * (* wappend)(struct _wchar_string *, wchar_t *);
    int (* getLength)(struct _wchar_string *);
    char * (* getValue)(struct _wchar_string *);
    void (* dispose)(struct _wchar_string *);
} WCharString;

WCharString * WCharString_init();

#endif;
