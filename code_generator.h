#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include "CodeBuilder.h"

void generate_function(const char* name, const char* arguments, const char* body, CodeBuilder* builder);
void generate_struct(const char* name, const char** fields, int num_fields, CodeBuilder* builder);

#endif
