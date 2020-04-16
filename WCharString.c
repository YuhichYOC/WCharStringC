#include "WCharString.h"

char * mfw(wchar_t * value) {
    int wl = sizeof(wchar_t) * (wcslen(value) + 1);
    int l = wcslen(value) + 1;
    char * ret = (char *) malloc(l);
    setlocale(LC_ALL, "Japanese");
    wcstombs(ret, value, wl);
    return ret;
}

char * charClone(char * value) {
    int l = strlen(value) + 1;
    char * ret = (char *) malloc(l);
    for (int i = 0; l > i; ++i) { ret[i] = 0; }
    for (int j = 0; l > j; ++j) { ret[j] = value[j]; }
    return ret;
}

wchar_t * wfm(char * value) {
    int l = strlen(value) + 1;
    int wl = sizeof(wchar_t) * l;
    wchar_t * ret = (wchar_t *) malloc(wl);
    setlocale(LC_ALL, "Japanese");
    mbstowcs(ret, value, wl);
    return ret;
}

WCharString * WCharString_assign(WCharString * ws, char * arg) {
    int l = strlen(arg);
    ws->length = l + 1;
    ws->value = (char *) realloc(ws->value, ws->length);
    for (int i = 0; l > i; ++i) { ws->value[i] = 0; }
    for (int j = 0; l > j; ++j) { ws->value[j] = arg[j]; }
    return ws;
}

WCharString * WCharString_wassign(WCharString * ws, wchar_t * arg) {
    char * value = mfw(arg);
    int l = strlen(value);
    ws->length = l + 1;
    ws->value = (char *) realloc(ws->value, ws->length);
    for (int i = 0; l > i; ++i) { ws->value[i] = 0; }
    for (int j = 0; l > j; ++j) { ws->value[j] = value[j]; }
    free(value);
    return ws;
}

WCharString * WCharString_append(WCharString * ws, char * arg) {
    int prevLength = ws->length;
    int appendLength = strlen(arg);
    ws->value = (char *) realloc(ws->value, prevLength + appendLength);
    for (int i = 0; appendLength > i; ++i) { ws->value[prevLength - 1 + i] = arg[i]; }
    ws->length += appendLength;
    ws->value[ws->length - 1] = 0;
    return ws;
}

WCharString * WCharString_wappend(WCharString * ws, wchar_t * arg) {
    char * value = mfw(arg);
    int prevLength = ws->length;
    int appendLength = strlen(value);
    ws->value = (char *) realloc(ws->value, prevLength + appendLength);
    for (int i = 0; appendLength > i; ++i) { ws->value[prevLength - 1 + i] = value[i]; }
    ws->length += appendLength;
    ws->value[ws->length - 1] = 0;
    free(value);
    return ws;
}

int WCharString_getLength(WCharString * ws) {
    return ws->length;
}

char * WCharString_getValue(WCharString * ws) {
    return charClone(ws->value);
}

wchar_t * WCharString_wgetValue(WCharString * ws) {
    return wfm(ws->value);
}

void WCharString_dispose(WCharString * ws) {
    free(ws->value);
    free(ws);
}

WCharString * WCharString_init() {
    WCharString * ret = (WCharString *) malloc(sizeof(WCharString));
    ret->length = 0;
    ret->value = (char *) malloc(1);
    ret->value[0] = 0;
    ret->assign = WCharString_assign;
    ret->wassign = WCharString_wassign;
    ret->append = WCharString_append;
    ret->wappend = WCharString_wappend;
    ret->getLength = WCharString_getLength;
    ret->getValue = WCharString_getValue;
    ret->wgetValue = WCharString_wgetValue;
    ret->dispose = WCharString_dispose;
    return ret;
}
