#include <stdio.h>
#include <stdlib.h>
#include "../headers/LinkedList.h"


// making an empty list
LinkedList createNewLinkedList(){
    // allocate free space
    LinkedList newList;
    newList = (LinkedList) malloc(sizeof(node));

    // report error if no space
    if (newList == NULL){
        printf("Out of memory!!!... cann't create list\n");
    }
    else {
        printf("List created successfully.\n");
        newList->length = 0;
        newList->next = NULL;
    }
    // return the pointer
    return newList;
}

// inserting node at the begning
void insertBegning(ElementType x, LinkedList list){
    
    // dummy node implementation assumed
    nodeptr newNode = (nodeptr) (malloc(sizeof(node)));
        if (newNode == NULL){
            printf("Out of memory!!!...can add new node\n");
            return;
        }
        else {
            newNode->next = NULL;
            newNode->element = x;

            if (list->length == 0){
                // first node of the list
                list->next = newNode;
            }
            else{
                // inserting node at the begning
                newNode->next = list->next;
                list->next = newNode;
            }
            // increasing the length of the list
            list->length++;
            return;           
        }
    
}

// printing the list
void printList(LinkedList list){
    
    int i = list->length;
    nodeptr currNode= list->next;
    
    while(i-- >= 0){
        printf("%d", currNode->element);
        if (i > 0)
            printf(" -> ");
    }
    
    return;
}