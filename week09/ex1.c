#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct page {
    int weight;
    int r;
    int value;
};
// Function to check whether a page exists 
// in a frame or not 
int search(struct page *pages, int key, int fr_size) {
    for (int j = 0; j < fr_size; ++j) {
        if (pages[j].value == key)
            return j; 
    }
    return -1; 
}

void add_page(struct page *pages, int value, int index) {
    struct page page;
    page.value = value;
    page.r = 1; 
    page.weight = 0; 

    pages[index] = page;
}

// Function to find the frame that will not be used 
int predict(struct page *pages, int fr_size) {
    int farthest = 0;
    for (int i = 0; i < fr_size; i++) {
        if (pages[i].weight < pages[farthest].weight)
            farthest = i;
    }
    return farthest;
}

void shift(struct page *pages, int fr_size) {

    for (int j = 0; j < fr_size; j++) {
        pages[j].weight = pages[j].weight >> 1;

        if (pages[j].r == 1)
            pages[j].weight = pages[j].weight >> 1 | INT_MAX - (INT_MAX >> 1);
        pages[j].r = false;

    }
}

void optimalPage(int fr_size){
    FILE *fp = fopen("input.txt", "r");

    int current_size = 0;
    int value_to_find = 0;
    unsigned int total_count = 0;
    int hit = 0;
    int miss = 0;

    struct page *pages = malloc(sizeof(struct page) * fr_size);

    while (fscanf(fp, " %d", &value_to_find) != EOF) {
        total_count++;
        int my_index = search(pages, value_to_find, fr_size);
        if (my_index != -1) {
            hit++;
            pages[my_index].r = 1;
        } else {
            miss++;
            if (current_size != fr_size) {
                add_page(pages, value_to_find, current_size);
                current_size++;
            } else {
                add_page(pages, value_to_find, predict(pages, fr_size));
            }
        }
        shift(pages, fr_size);
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
