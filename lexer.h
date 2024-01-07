#pragma once

#include "vec.h"

typedef enum {
    GREATER_THAN,
    LESS_THAN,
    NR_OF_TOKENS,
} token_t;

typedef struct {
    int line;
    int column;
} token_pos_t;

typedef struct {
    token_t type;
    token_pos_t pos;
    pool_p;
} token_info_t;

void lexer_lex(char* file_path, vec_t tokens);