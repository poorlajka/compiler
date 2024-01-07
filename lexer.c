#include <stdio.h>
#include "vec.h"
#include "dfa.h"
#include "lexer.h"

void lexer_lex(char* file_path, vec_t tokens) {

    token_pos_t file_pos = { .line = 1, .column = 1, };
    dfa_state_t state = DFA_STATE_BEGIN;

    FILE* fp;
    fp = fopen(file_path, "r");
    char input;

    //TODO DO FUCKING BUFFERING CUZ THIS MAKES ME SAD
    while (input = fgetc(fp) != EOF) {
        state = dfa_state_transition(state, input); 

        if (dfa_state_is_accepting(state)) {
            vec_push(tokens, (token_info_t) { 
                .type = state, 
                .pos = file_pos 
            });
        }
        else if  (dfa_state_is_invalid(state)) {

        }

        if (input == "\n") {
            file_pos.column++;
        }
        file_pos.line++;

        /*
        if state is valid exit state {
            push token to vector
            reset state to DFA_STATE_BEGIN
            continue looping
        }
        if state is valid state {
            continue looping
        }
        if state is invalid {
            report error
            try to recover error
            continue looping
        }
    */
    }

}