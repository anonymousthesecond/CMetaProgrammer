#include "CodeGenerator.h"

void generate_function(const char* name, const char* arguments, const char* body, CodeBuilder* builder) {
    add_line(builder, "void ");
    add_line(builder, name);
    add_line(builder, "(");
    add_line(builder, arguments);
    add_line(builder, ") {");
    indent(builder);
    add_line(builder, body);
    dedent(builder);
    add_line(builder, "}");
}

void generate_struct(const char* name, const char** fields, int num_fields, CodeBuilder* builder) {
    add_line(builder, "typedef struct {");
    indent(builder);
    for (int i = 0; i < num_fields; i++) {
        add_line(builder, fields[i]);
    }
    dedent(builder);
    add_line(builder, "} ");
    add_line(builder, name);
    add_line(builder, ";");
}
