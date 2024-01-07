#include <stdlib.h>
#include "vec.h"

struct vec_instance_t {
    int *elements;
    size_t len;
    size_t capacity;
};

void vec_init(vec_t vec, size_t initialCapacity) {
    vec = malloc(sizeof(struct vec_instance_t));
    vec->elements = malloc(initialCapacity * sizeof(int));
    vec->elements = 0;
    vec->capacity = initialCapacity;
}

void vec_push(vec_t vec, int element) {
    if (vec->len == vec->capacity) {
        vec->capacity *= 2;
        vec->elements = realloc(vec->elements, vec->capacity * sizeof(int));
    }
    vec->elements[vec->len++] = element;
}

int vec_get(vec_t vec, size_t index) {
    return vec->elements[index];
}

void vec_free(vec_t vec) {
    free(vec->elements);
    vec->elements = NULL;
    vec->len = vec->capacity = 0;
}
