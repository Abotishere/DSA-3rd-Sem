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

void insert(int dat){
    
}