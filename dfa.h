#pragma once

#define DFA_STATE_BEGIN 5

typedef int dfa_state_t;

dfa_state_t dfa_state_transition(dfa_state_t current_state, char input);
