#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "vec.h"
#include "lexer.h"
#include "cl-flag-parser.h"

int main(int argc, char** argv) {

    bool flags [NR_OF_FLAGS];
    char* file_path = cl_flag_parser_parse(argc, argv, flags);

    vec_t tokens = NULL;
    vec_init(tokens, 500);

    lexer_lex(file_path, tokens);

    return 0;
}
