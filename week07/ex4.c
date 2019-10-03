#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *my_realloc(int *ptr, size_t new_size) {
    if (new_size == 0) {
        free(ptr);
        return ptr;
    }
    int *new_ptr = malloc(new_size);
    if (ptr != NULL) {
        memcpy(new_ptr, ptr, new_size);
        free(ptr);
    }

    return new_ptr;
}

int main() {
    int count = 0;
    scanf("%d", &count);

    int *array = malloc(1 * sizeof(int));
    array = my_realloc(array, count * sizeof(int));

    for (int i = 0; i < count; ++i) {
        array[i] = i;
        printf("\n", i);
    }

    free(array);
    return 0;
} 
