#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cl-flag-parser.h"


char* cl_flag_parser_parse(int argc, char** argv, bool* flags) {
    char* file_path = NULL;
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-i") == 0 || strcmp(argv[i], "--input") == 0) {
            if (file_path != NULL) {
                printf("Error: multiple cl input flags used!\n");
                printf("Exiting...\n");
                exit(1);
            }
            flags[Input] = true;
            file_path = argv[++i];
        }
        else if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--output") == 0) {
            flags[Output] = true;
        }
    }
    return file_path;
}