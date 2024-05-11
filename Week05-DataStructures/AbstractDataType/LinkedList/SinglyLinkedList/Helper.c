#include "Helper.h"

List createList() {
    List init = (struct ListRecord *) malloc(sizeof(struct ListRecord));
	if (init == NULL)
		printf("Out of memory!\n");
    else
	    makeEmptyList(init);

	return init;
}



void makeEmptyList(List list) {
    list->head = (struct Node *) malloc(sizeof(struct Node));
        if (list->head == NULL)
            printf("Out of memory!\n");

    list->head->next = NULL;
    list->tail = list->head;
    list->size = 0;
}


int listSize(List list) {
    return (list->size);
}


int headOfList(List list) {
    return (list && list->head && list->head->next) ? list->head->next->value : -1;
}



int tailOfList(List list) {
    return ((list) && (list->tail) && (list->tail != list->head)) ? list->tail->value : -1;
}


int isEmptyList(List list) {
    return (list->size == 0);
}

/*
struct Node *findValueOnList(List list,int key) {
    Node* iterator; // In fact, double pointer
    iterator = list->head;
    while(iterator->next != NULL) {
        printf("--> %d ", iterator->value);
    }
}
*/


void displayList(List list) {
    if (list == NULL || list->head == NULL) {
        printf("List or list head is NULL\n");
        return;
    }

    Node iterator = list->head->next; // Start from the first actual node (skip dummy head)

    printf("Head");
    while (iterator != NULL) {
        printf(" --> %d", iterator->value);
        iterator = iterator->next;
    }
    printf(" -- as tail\n");
}



void insertAtGivenIndex(List list, int index, int value) {
    if (index < 0 || index > list->size) {
        printf("[Error]: Please enter a valid index. Index value should be between 0 and %d\n", list->size);
        return; // Properly exit if index is invalid
    }

    int i;
    Node newnode = (Node) malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Failed to allocate memory for new node.\n");
        return;
    }
    newnode->value = value;
    newnode->next = NULL;

    Node *current = &list->head->next;
    for (i = 0; i < index; i++) {
        current = &(*current)->next;
    }

    // Insert new node at the correct position
    newnode->next = *current;
    *current = newnode;

    // Adjust the tail if needed
    if (index == list->size) {
        list->tail = newnode;
    }

    list->size += 1;
}



void deleteFromList(List list, int value) {

}


int getValueAtGivenIndex(List *list, int index) {
    if (index < 0 || index >= (*list)->size) {
        return -1; // Index out of bounds
    }

    Node current = (*list)->head->next; // Pointing to the first actual data node
    int i;
    for (i = 0; i < index; i++) {
        if (current == NULL) return -1; // Safety check if list is malformed
        
        current = current->next; // Move to the next node
    }
    return current ? current->value : -1; // Return the value if current is not NULL
}




void append(List list, int value) {
    Node newnode = (struct Node*) malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Failed to allocate memory for new node.\n");
        return;
    }
    newnode->value = value;
    newnode->next = NULL;
    
    if (isEmptyList(list)) {
        list->head->next = newnode; // Linking the first node after dummy
    } else {
        list->tail->next = newnode; // Appending to the end of the list
    }
    list->tail = newnode; // Updating the tail pointer
    list->size += 1;
}


