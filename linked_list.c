# include <stdio.h>
# include <stdlib.h>

typedef struct node {
    int data;
    struct node* nextp;
} node;

void display(node* s) {
    for(node* p = s; p != NULL; p = p->nextp) {
        printf("%d\t", p -> data);
    }
    printf("\n");
}

void free_nodes(node* s) {
    node* current = s;
    node* next;

    while (current != NULL) {
        next = current->nextp; 
        printf("Removing %d\n", current->data);
        free(current); 
        current = next; 
    }
    printf("\n");
}

node* insert_first(node* s, int num) {
    node* new = (node*) malloc(sizeof(node));
    new -> data = num;
    new -> nextp = s;
    return new;
}

void insert_last(node* s, int num) {
    node* new = (node*) malloc(sizeof(node));
    new -> data = num;
    new -> nextp = NULL;
    node* last = s;
    while(last -> nextp != NULL) {
        last = last -> nextp;
    }
    last -> nextp = new;
}

node* delete_first(node* s) {
    node* new = s -> nextp;
    free(s);
    return new;
}

void delete_last(node* s) {
    node* current = s;
    node* next = current -> nextp;
    while(next -> nextp != NULL) {
        current = next;
        next = current -> nextp;
    }
    current -> nextp = NULL;
    free(next);
}

int main() {
    node* s;
    s = (node*) malloc(sizeof(node));
    s -> data = 100;
    s -> nextp = (node*) malloc(sizeof(node));
    s -> nextp -> data = 200;
    s -> nextp -> nextp = (node*) malloc(sizeof(node));
    s -> nextp -> nextp -> data = 300;
    s -> nextp -> nextp -> nextp = NULL;
    display(s);
    s = insert_first(s, 1);
    display(s);
    insert_last(s, 400);
    display(s);
    s = delete_first(s);
    display(s);
    delete_last(s);
    display(s);
    free_nodes(s);
}

