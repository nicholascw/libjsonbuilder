#include "json_builder.h"

char *json_esc(char *str) {
  if (!str) return NULL;
  char *r = malloc(strlen(str) * 2 + 1);
  if (!r) return NULL;
  char *ptr_r = r;
  for (char *i = str; i < str + strlen(str); i++) {
    if (!i) break;
    char i_cpy = 0;
#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
    switch (*i) {
      case '\b':
        i_cpy = 'b';
        goto quo;
      case '\f':
        i_cpy = 'f';
        goto quo;
      case '\n':
        i_cpy = 'n';
        goto quo;
      case '\r':
        i_cpy = 'r';
        goto quo;
      case '\t':
        i_cpy = 't';
        goto quo;
      quo:
      case '"':
      case '\\':
        *ptr_r++ = '\\';
      default:
        *ptr_r++ = i_cpy ? i_cpy : *i;
    }
  }
  *ptr_r = '\0';
  return r;
}

char *json_kv(char *k, char *v, bool quote_v) {
  if (!(k && v && strlen(k) > 0)) return NULL;
  char *k_esc = json_esc(k);
  char *r;
  int len = asprintf(&r, quote_v ? "\"%s\":\"%s\"" : "\"%s\":%s", k_esc, v);
  return len > 0 && r ? r : NULL;
}

char *json_kvi(char *k, long long v) {
  char *str_v;
  int len = asprintf(&str_v, "%lld", v);
  if (len <= 0 || !str_v) return NULL;
  return json_kv(k, str_v, false);
}

char *json_concat(char *a, char *b, bool quote) {
  char *str_v;
  int len = asprintf(&str_v, quote ? "\"%s\",\"%s\"" : "%s,%s", a, b);
  if (len <= 0 || !str_v) return NULL;
  return str_v;
}

char *json_blk(char *a, bool sqr) {
  char *str_v;
  int len = asprintf(&str_v, sqr ? "[%s]" : "{%s}", a);
  if (len <= 0 || !str_v) return NULL;
  return str_v;
}
