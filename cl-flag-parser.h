#pragma once

typedef enum {
    Output,
    Input,
    NR_OF_FLAGS,
} cl_flag_t;

char* cl_flag_parser_parse(int argc, char** argv, bool* flags);