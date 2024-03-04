#include "CodeTemplate.h"
#include <stdlib.h>
#include <string.h>

CodeTemplate* create_template(const char* template_str) {
    CodeTemplate* template = (CodeTemplate*)malloc(sizeof(CodeTemplate));
    if (template) {
        template->template_str = strdup(template_str);
    }
    return template;
}

void set_value(CodeTemplate* template, const char* key, const char* value) {
    char* key_start = strstr(template->template_str, key);
    if (key_start) {
        char* key_end = key_start + strlen(key);
        memmove(key_start + strlen(value), key_end, strlen(key_end) + 1);
        strncpy(key_start, value, strlen(value));
    }
}

char* render_template(CodeTemplate* template) {
    return strdup(template->template_str);
}
