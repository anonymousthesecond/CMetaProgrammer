#ifndef CODE_TEMPLATE_H
#define CODE_TEMPLATE_H

typedef struct {
    char* template_str;
} CodeTemplate;

CodeTemplate* create_template(const char* template_str);
void set_value(CodeTemplate* template, const char* key, const char* value);
char* render_template(CodeTemplate* template);

#endif
