//based on the https://www.geeksforgeeks.org/optimal-page-replacement-algorithm/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct vector {
    int weight;
    int reference_bit;
    int value;
};
// Function to check whether a page exists 
// in a frame or not 
int search(struct vector *vectors, int key, int fr_size) {
    for (int j = 0; j < fr_size; ++j) {
        if (vectors[j].value == key)
            return j; 
    }
    return -1; 
}

void add_page(struct vector *vectors, int value, int index) {
    struct vector vector;
    vector.value = value;
    vector.reference_bit = 1; 
    vector.weight = 0; 

    vectors[index] = vector;
}

// Function to find the frame that will not be used 
int predict(struct vector *vectors, int fr_size) {
    int farthest = 0;
    for (int i = 0; i < fr_size; i++) {
        if (vectors[i].weight < vectors[farthest].weight)
            farthest = i;
    }
    return farthest;
}

void shift_page_weight(struct vector *vectors, int fr_size) {

    for (int j = 0; j < fr_size; j++) {
        vectors[j].weight = vectors[j].weight >> 1;

        if (vectors[j].reference_bit == 1)
            vectors[j].weight = vectors[j].weight >> 1 | INT_MAX - (INT_MAX >> 1);
        vectors[j].reference_bit = false;

    }
}

void optimalPage(int fr_size){
    FILE *fp = fopen("input.txt", "r");

    int current_size = 0;
    int value_to_find = 0;
    unsigned int total_count = 0;
    int hit = 0;
    int miss = 0;

    struct vector *vectors = malloc(sizeof(struct vector) * fr_size);

    while (fscanf(fp, " %d", &value_to_find) != EOF) {
        total_count++;
        int my_index = search(vectors, value_to_find, fr_size);
        if (my_index != -1) {
            hit++;
            vectors[my_index].reference_bit = 1;
        } else {
            miss++;
            if (current_size != fr_size) {
                add_page(vectors, value_to_find, current_size);
                current_size++;
            } else {
                add_page(vectors, value_to_find, predict(vectors, fr_size));
            }
        }
        shift_page_weight(vectors, fr_size);
    }
    
    printf("Miss: %d\n", miss);
    printf("Hit: %d\n", hit);
    
    double ratio =   (double) hit /  miss;

    printf("Hit/Miss: %f\n",  ratio);
}

int main() {
    unsigned int fr_size;
    scanf("%u", &fr_size);
    optimalPage(fr_size);
    return 0;
}
