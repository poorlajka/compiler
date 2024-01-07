#pragma once

#include <stdlib.h>

typedef struct vec_instance_t* vec_t;

void vec_init(vec_t vec, size_t initialCapacity);

void vec_free(vec_t vec);

void vec_push(vec_t vec, int element);

int vec_get(vec_t vec, size_t index);

