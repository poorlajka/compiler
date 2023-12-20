#include <stdio.h>
#include <regex.h>

#define ASSIGN '=';
#define EQUAL '==';
#define NOT_EQUAL '!=';
#define DOT '.';
#define COMMA ',';
#define COLON ':';
#define SEMICOLON ';';
#define GREATER_THAN '>';
#define GREATER_THAN_OR_EQUAL '>';
#define LESS_THAN '<';
#define LESS_THAN_OR_EQUAL '<';
#define AND 'and';
#define OR 'or';
#define NOT 'not';
#define PLUS '+';
#define MINUS '-';
#define LET 'let';
#define MUT 'mut';
#define FUNCTION 'function';
#define INTEGER 'integer';
#define FLOAT 'float';
#define CHAR "char"

# define MAX_TOKENS 666

typedef enum {
    GREATER_THAN,
    END,
} token_t;

typedef struct {
    token_t tokens[MAX_TOKENS];
    size_t len = 0;
} token_stream_t;

void add_token(token_stream_t* token_stream, token_t token) {
    token_stream->tokens[token_stream->len++] = token;
}

void compile_regexps(regex_t* regexps) {
    ;
}

typedef enum {
    Fail,
    Success,
    Continue,
} match_result_t;

typedef struct {
    match_result_t match_result;
    token_t token;
} regex_match_t;

void tokenize(FILE* fp, token_stream_t* token_stream) {
    regex_t regexps[token_t.END];
    compile_regexps(&regexps);

    int buffer_len = 4096;
    int buffer[buffer_len];

    int expression_len = 0;
    int expression[buffer_len*5]

    while (fgets(buffer, buffer_len, fp)) {

        for (int i = 0; i < buffer_len; ++i) {
            expression[expression_len++] = buffer[i];
            regex_match_t match = match_expression(regexps, expression, expression_len);

            switch (match.match_result) {
                case Fail: {
                    break;
                }
                case Success: {
                    add_token(token_stream, match.token);
                    expression_len = 0;
                    break;
                }
                case Continue: {
                    break;
                }
            }
        }
    }
}


regex_match_t match_expression(regex_t* regexps, char* expression, int expression_len) {
    for (token_t token = 0; token < token_t.END; ++token) {

        if (regexec(&regexps[token], buffer, 0, NULL, 0) != REG_NOMATCH) {
            return token;
        }
        else {
            buffer_len++;
        }
    }

}