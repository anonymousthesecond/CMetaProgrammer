#include "CodeBuilder.h"
#include <stdlib.h>
#include <string.h>

CodeBuilder* create_builder() {
    CodeBuilder* builder = (CodeBuilder*)malloc(sizeof(CodeBuilder));
    if (builder) {
        builder->code_lines = NULL;
        builder->num_lines = 0;
        builder->indent = 0;
    }
    return builder;
}

void add_line(CodeBuilder* builder, const char* line) {
    builder->code_lines = (char**)realloc(builder->code_lines, (builder->num_lines + 1) * sizeof(char*));
    if (builder->code_lines) {
        builder->code_lines[builder->num_lines] = (char*)malloc((builder->indent + strlen(line) + 1) * sizeof(char));
        if (builder->code_lines[builder->num_lines]) {
            sprintf(builder->code_lines[builder->num_lines], "%*s%s", builder->indent, "", line);
            builder->num_lines++;
        }
    }
}

void indent(CodeBuilder* builder) {
    builder->indent += 4;
}

void dedent(CodeBuilder* builder) {
    if (builder->indent >= 4) {
        builder->indent -= 4;
    }
}

char* get_code(CodeBuilder* builder) {
    int total_length = 1; // Account for null terminator
    for (int i = 0; i < builder->num_lines; i++) {
        total_length += strlen(builder->code_lines[i]);
    }
    char* code = (char*)malloc(total_length * sizeof(char));
    if (code) {
        code[0] = '\0';
        for (int i = 0; i < builder->num_lines; i++) {
            strcat(code, builder->code_lines[i]);
            strcat(code, "\n");
        }
    }
    return code;
}

void free_builder(CodeBuilder* builder) {
    if (builder) {
        for (int i = 0; i < builder->num_lines; i++) {
            free(builder->code_lines[i]);
        }
        free(builder->code_lines);
        free(builder);
    }
}
