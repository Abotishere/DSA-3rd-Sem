#include <stdio.h>
#include <stdlib.h>

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
    // invalid input
    if (n < 1){
        printf("Invalid position. Please enter a valid position.\n");
        return;
    }

    node* node1 = createNew(dat);

    // when list is empty
    if (!head){
        // this way no matter what the value of n be
        // node1 will always be the first node
        printf("List is empty. Creating list.\n");
        head = node1;
        printf("%d inserted as first element.\n",dat);
        return;
    }

    //when n = 1 (first position)
    if (n == 1){
        head->prev = node1;
        node1->next = head;
        head = node1;
        return;
    }

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
    (ptr->next)->prev = node1;
    ptr->next = node1;
    return;
}
