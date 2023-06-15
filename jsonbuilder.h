#pragma once

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

extern char *json_esc(char *str);
extern char *json_kv(char *k, char *v, bool quote_v);
extern char *json_kvi(char *k, long long v);
extern char *json_concat(char *a, char *b, bool quote);
extern char *json_blk(char *a, bool sqr);

#define json_iconcat(x, y, q)            \
  do {                                   \
    char *next_x = json_concat(x, y, q); \
    free(x);                             \
    free(y);                             \
    x = next_x;                          \
  } while (0)

#define json_iblk(x, sq)            \
  do {                              \
    char *next_x = json_blk(x, sq); \
    free(x);                        \
    x = next_x;                     \
  } while (0)
