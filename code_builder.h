#ifndef CODE_BUILDER_H
#define CODE_BUILDER_H

#include "CodeTemplate.h"

typedef struct {
    char** code_lines;
    int num_lines;
    int indent;
} CodeBuilder;

CodeBuilder* create_builder();
void add_line(CodeBuilder* builder, const char* line);
void indent(CodeBuilder* builder);
void dedent(CodeBuilder* builder);
char* get_code(CodeBuilder* builder);
void free_builder(CodeBuilder* builder);

#endif
