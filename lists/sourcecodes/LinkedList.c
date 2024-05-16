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
    // if list is NULL return
    if (list == NULL){
        printf("List does not exit.\n");
        return;
    }

    // dummy node implementation assumed
    nodeptr newNode = (nodeptr) (malloc(sizeof(node)));
        if (newNode == NULL){
            printf("Out of memory!!!...can add new node\n");
            return;
        }
        else {
            newNode->next = NULL;
            newNode->element = x;
            newNode->length = 0;

            if (list->length == 0){
                // first node of the list
                newNode ->next = list->next;
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

//inserting at the end of the list
void insertEnding(ElementType x, LinkedList list){
    //dummy node implementation assumed

    if (list == NULL){
        printf("List does not exit.\n");
        return;
    }
    // making new node
    nodeptr newNode = (nodeptr) malloc(sizeof(node));
    if (newNode == NULL){
        printf("Sufficient not available.\n");
        return;
    }
    newNode->element =  x;
    newNode->next = NULL;
    newNode->length = 0;

    // traversing the list
    nodeptr currNode = list;
    while(currNode->next != NULL){
        currNode = currNode->next;
    }

    // adding the new node to the list
    currNode->next = newNode;

    // increamenting the list size
    list->length++;
}

// inserting at a current positon
void insertIndex(ElementType x, LinkedList list, int indx){
    if (list == NULL){
        printf("List does not exit.\n");
        return;
    }

    if (indx == 0){
        insertBegning(x,list);
    }
    else if ((indx) >= (list->length)){
        insertEnding(x,list);
    }
    else{
        // traversing to correct location
        nodeptr tempNode = list;
        while((--indx)>=0)
            tempNode = tempNode->next;
        
        insertBegning(x,tempNode);
    }
    
}

// to check if the list is empty
// @retun 0 is list not empty else 1
int isEmpty(LinkedList list){
    if (list == NULL){
        printf("List does not exit.\n");
        return -1;
    }
    return (list->length == 0);
}

// for finding the length of the list
// @return length of the list is not null else -1
int getLength(LinkedList list){
    if (list != NULL){
        return list->length;
    }
    return -1;
}


// finding element in the list(not sorted) - linear search
// @return index of first occurance of element x
int findIndex(ElementType x, LinkedList list){
    
    int pos = -1;

    if (!isEmpty(list)){
        // traversing the node and finding the element x
        nodeptr currNode = list;
       
        while((currNode = currNode->next)!= NULL){
           pos++;
           if (currNode->element == x)
            return pos;
        }
    }
    return -1; // element not found
}

// finding the previoud node of the node to delete
// @return pointer to the previous node fo the first occurance in the list 
nodeptr findPrevious(ElementType x, LinkedList list){
    
    if (!isEmpty(list)){
        // traversing the node and finding the previous node
        nodeptr currNode = list;
       
        while((currNode->next)!= NULL){
            // checking if the element of the next node == X
            if ((currNode->next)->element == x)
                return currNode;
            currNode = currNode->next;
        }
    }
    return NULL; // element not found
}


// deleting the first occurence of an element
void deleteElement(ElementType x,LinkedList list){
    if(!isEmpty(list)){
        // finding the previous node
        nodeptr previousNode = findPrevious(x,list);
        
        if (previousNode != NULL){
            // making a temp pointer point to the node to delete 
            nodeptr toDelete = previousNode->next;
            // removing the link and making new link
            previousNode->next = toDelete->next;
            // freeing the node
            free(toDelete);
            list->length--;
        }
        else{
            printf("Element doesn't exits.\n");
        }
        return;
    }
    return;
}

// deleting the whole list
void deleteList(LinkedList* l){
    printf("in delete%p\n",*l);
    printf("checking: %d",*l == NULL);
    if (*l == NULL){
        printf("List does not exit.\n");
        return;
    }
    LinkedList list = *l;
    if(!isEmpty(list)){
        // freeing all the node except the header
        ElementType et;
        nodeptr toDelete =  list; // points at the header
        int i = 0;
        while((toDelete->next) != NULL){   
            // checking if there is node attached to the header
            // idea: standing at the header node, we check if there another node
            // linked to it, if it is we delete that node
            // making toDelete point to the 1st node
            toDelete =  toDelete->next;
            // link header to the 2nd node
            list->next = toDelete->next;
            // free the node
            free(toDelete);
            // making toDelete point to the header
            toDelete = list;
            //decrementing the length
            list->length--;
        }
    }
    // lastly we free the header
    free(list);
    *l = NULL; 
    printf("out of print\n");
}

// printing the list
void printList(LinkedList list){
    if (list == NULL){
        printf("List does not exit.\n");
        return;
    }

    nodeptr currNode= list->next;
    
    while(currNode != NULL){
        printf("%d", currNode->element);
        currNode = currNode->next;

        if (currNode != NULL){
            printf(" -> ");
        }
        
    }
    printf("\n");
    return;
}