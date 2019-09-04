#include <stdio.h>
#include <stdlib.h>

//based on Information from course ITP 2

typedef struct node {  
    int val;
    struct node * next; 
} node_t; 

void print_list(node_t *head){ 
    node_t * p = head; 

    while (p!=NULL){
        printf("%d\n",p->val);  
        p=p->next; 
    }
}
void add_start(node_t **head,int val){ 

    node_t * p;
    p = malloc(sizeof(node_t));
    p->val = val; 
    p->next = *head; 

    *head = p;

}
int add_index(node_t **head, int val, int pos){ 
    if(pos==0){ 
        add_start(head,val); 
        return 1; 
    }
    node_t * p = *head; 
    node_t * q;
    for(int i=0; i<pos; i++){
        if(p==NULL)return 0; 
        p=p->next;
    } 
    
    q = malloc(sizeof(node_t));
    q ->val = val;
    q ->next = p->next; 
    p->next = q; 
    return 1; 
}


int main(){
    node_t * head = NULL;
    head = malloc(sizeof(node_t)); 
    if (head == NULL) {
        return 1; 
    }

    head->val = 1; 
    head->next = NULL;
    
    return 0;   
}
