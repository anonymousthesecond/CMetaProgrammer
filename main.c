#include "CodeTemplate.h"
#include "CodeBuilder.h"
#include "CodeGenerator.h"
#include <stdio.h>

int main() {
    // Example usage
    CodeBuilder* builder = create_builder();

    generate_function("add", "int a, int b", "return a + b;", builder);
    char* generated_code = get_code(builder);
    printf("%s\n", generated_code);

    free_builder(builder);
    free(generated_code);

    return 0;
}
