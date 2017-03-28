/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
 * 
 * val: value to store in the node.
 * next: pointer to the next node
 *
 * returns: pointer to a new node
 */
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
 * 
 * list: pointer to pointer to Node
 */
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
 * 
 * list: pointer to pointer to Node
 *
 * returns: int or -1 if the list is empty
 */
int pop(Node **list) {
    Node *current = *list;
    if (current == NULL) {
        return -1;
    }
    *list = current->next;
    // FILL THIS IN!
    return current->val;
}


/* Adds a new element to the beginning of the list.
 * 
 * list: pointer to pointer to Node
 * val: value to add
 */
void push(Node **list, int val) {
    // FILL THIS IN!
    Node *current = *list;
    Node *newFirst = make_node(val, current);
    *list = newFirst;
}




/* Removes the first element with the given value
 * 
 * Frees the removed node.
 *
 * list: pointer to pointer to Node
 * val: value to remove
 *
 * returns: number of nodes removed
 */
int remove_by_value(Node **list, int val) {
    // FILL THIS IN!
    Node *current = *list;
    if (current->val == val) {
        *list = current->next;
        free(current);
        return 1;
    }
    while (current->next != NULL) {
        if (current->next->val == val) {
            //Need to remove this node, point current to next next
            Node *afterNode = current->next->next;
            free(current->next);
            current->next = afterNode;
            return 1;

        }
        current = current->next;
    }
    return 0;
}


/* Reverses the elements of the list.
 *
 * Does not allocate or free nodes.
 * 
 * list: pointer to pointer to Node
 */
void reverse(Node **list) {
    Node* previous = NULL;
    Node* current = *list;
    Node* next;

    while (current != NULL)
    {
        next = current->next;  
        current->next = previous;   
        previous = current;
        current = next;
    }
    *list = previous;

    // FILL THIS IN!
}

void extend( Node **front, Node **end) {
 Node *current = *front;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = *end;

}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node *tail = make_node(1, NULL);
    tail->next = make_node(2, NULL);
    tail->next->next = make_node(3, NULL);
    tail->next->next->next = make_node(4, NULL);

    Node **list = &head;
    Node **back = &tail;
    extend(list, back);
    print_list(list);

    int retval = pop(list);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);
}


void printSorted(int *sortedArray, int size) {
    int i;
    int currentValue;
    int lastValue = *sortedArray;
    for (i = 1; i < size; i++) {
        currentValue = *(sortedArray + i);
        if (i == size - 1 && currentValue != lastValue) {
            printf(" %i ", lastValue);
            printf(" %i ", currentValue);
        }
        else if(currentValue != lastValue) {
            printf(" %i ", lastValue);
        } else {
            
        }
        lastValue = currentValue;
    }
}
