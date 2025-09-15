#include <stdio.h>

typedef struct node{
    int data;
    struct node * prev;
    struct node * next;
} node;

node* head = NULL;

node* createNew(int dat){
    node* new = (node*) malloc(sizeof(node));
    if (!new){
        printf("New node allocation failed. Try again.\n");
        return NULL;
    }
    new->data = dat;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

void insert(int dat, int n){
    node* node1 = createNew(dat);
    // n th position
    node* ptr = head;
    for(int i = 1; i < n - 1; i++){
        ptr = ptr->next;
        if (ptr == NULL){
            printf("Position out of order.\n");
            return;
        }
    }
    node1->prev = ptr;
    node1->next = ptr->next;
    ptr->next = ptr;
    return;
}