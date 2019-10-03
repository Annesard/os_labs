#include <stdio.h>
#include <stdlib.h>

int main() {
    int count = 0;
    scanf("%d", &count);

    int *array = malloc(count * sizeof(int));

    for (int i = 0; i < count; ++i) {
        array[i] = i;
        printf("%d\n", i);
    }

    free(array);
    return 0;
} 
