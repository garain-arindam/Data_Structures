#include <stdio.h>
#include <stdlib.h>
#include "../headers/DoubleLinkedList.h"


// creating an empty list
// @return point to an empty double linked list or void*
DoubleLinkedList createNewLinkedList(){
    DoubleLinkedList newList = malloc(sizeof(node));
    if (newList == NULL){
        printf("Out of memeory!!!\n");
    }
    else{
        printf("List created successfully.\n");
        newList->next = NULL;
        newList->previous = NULL;
        newList->length = 0;
    }
    return newList;
}

// inserts at the begning of the list
void insertBegning(ElementType x, DoubleLinkedList list){
    // dummy node implementaiton assumed

    if (list == NULL){
        printf("List does not exit.\n");
    }
    else{
        DoubleLinkedList newNode = malloc(sizeof(node));
        if (newNode == NULL){
            printf("Out of memery.\n");
            return;
        }
        newNode->element = x;
        newNode->length = 0;
        // adding node to the current list
        newNode->next = list->next;
        newNode->previous = list;
        list->next = newNode;

        list->length++;
    }
    return;
}

// inserts at the ending
void insertEnding(ElementType x, DoubleLinkedList list){
    // dummy node implementation assumed

    if (list == NULL){
        printf("List does not exit.\n");
    }
    else{
        DoubleLinkedList newNode = malloc(sizeof(node));
        if (newNode == NULL){
            printf("Out of memery.\n");
            return;
        }
        newNode->element = x;
        newNode->length = 0;

        // adding node to the current list
        nodeptr tempNode = list;
            // traversing to the end of the list
        while ((tempNode->next) != NULL){
            tempNode =  tempNode->next;
        }
        // adding node to the list 
        newNode->previous = tempNode;
        newNode->next = NULL;
        tempNode->next = newNode;
        // increasing the length of the list
        list->length++;
    }
    return;
}

// inserting at a current index
void insertIndex(ElementType x, DoubleLinkedList list, int indx){
    if (list == NULL){
        printf("List does not exit.\n");
    }
    else{
        if (indx == 0)
        {
            insertBegning(x,list);
        }
        else if(indx >= (list->length)){
            insertEnding(x,list);
        }
        else{
            nodeptr tempPtr = list;
            while((--indx) > 0)
                tempPtr = tempPtr->next;
            
            // inserting the element
            insertBegning(x, tempPtr);

            // adjusting the length
            tempPtr->length--;
            list->length++;

        }
        
    }
}

// checks if the list is empty
// @return 0 if empty, 1 if not empty else -1 if the list does not exit
int isEmpty(DoubleLinkedList list){
    if (list == NULL){
        printf("List does not exit.\n");
        return -1;
    }    
    return list->length == 0;
}

// give the length of the list
//  @return length of the list if not null else -1
int getLength(DoubleLinkedList list){
    if (list == NULL){
        printf("List does not exit.\n");
        return -1;
    }
    return list->length;
}

// printing the list
void printList(DoubleLinkedList list){
    if (list == NULL){
        printf("List does not exit\n");
    }
    else{
        nodeptr trav = list;
        while (trav->next != NULL){
            trav = trav->next;
            printf(FS,trav->element);
            if (trav->next != NULL)
                printf(" <-> ");
        }
    }
    return;
}

// Finds the index of the specified element
// @return index of x
int findIndex(ElementType x, DoubleLinkedList list){
    if (list == NULL){
        printf("List does not exit\n");
        return -1;
    }
    else{
        nodeptr trav = list; // for traversing the list
        int indx = 0;
        while ( (trav = trav->next) != NULL){
            if (trav->element == x)
                return indx;
            indx++;
        }           
        return -1;
    }
}

// Find the previous node of the node containing the element x
// @return pointer to previous node contating x
nodeptr findPrevious(ElementType x, DoubleLinkedList list){
    if (list == NULL){
        printf("List does not exit.\n");
        return NULL;
    }
    else{
        nodeptr previousNode = list;
        while(previousNode->next != NULL){
            if(((previousNode->next)->element) == x)
                break;
            previousNode = previousNode->next;
        }
        return previousNode;
    }
}