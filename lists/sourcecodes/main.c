#include <stdio.h>
// #include "../headers/LinkedList.h"
#include "../headers/DoubleLinkedList.h"

void main(int argc,char ** argv){
    DoubleLinkedList list1 = NULL;
    // LinkedList list1 = NULL;

    printf("ADD: %p\n",list1);
    list1 = createNewLinkedList();
    insertBegning(10,list1);
    printList(list1);
    printf("\n");
    insertEnding(9,list1);
    printList(list1);printf("\n");
    insertBegning(11,list1);
    printList(list1);printf("\n");
    insertEnding(90,list1);
    printList(list1);printf("\n");
    insertIndex(1,list1,3);
    printList(list1);printf("\n");
    insertIndex(2,list1,2);
    printList(list1);printf("\n");
    insertIndex(1,list1,30);
    printList(list1);printf("\n");
    insertIndex(1,list1,0);
    printList(list1);printf("\n");
    printf("length: %d",list1->length);
    printf("find : %d",findIndex(900,list1));
    printf("find : %d",findIndex(9,list1));
    printf("findprevious: %p\n",findPrevious(0,list1));
    printf("findprevious: %p, element: %d\n",findPrevious(0,list1),findPrevious(11,list1)->element);
    printf("ADD: %p\n",list1);
    deleteList(&list1);
    printf("ADD: %p\n",list1);
    list1 = createNewLinkedList();
    insertBegning(0,list1);
    insertEnding(4,list1);
    printList(list1);
    deleteList(&list1);
    deleteList(&list1);
    printf("address: %p, length: %d",list1,getLength(list1));
    printf("inserting at the begning");
    insertBegning(10,list1);
    printf("inserted at the begning.\n");
    printList(list1);
    
    printf("length: %d\n",getLength(list1));
    //printf("next: %p",list1->next);
    deleteElement(9,list1);
    printList(list1);
    list1 = NULL;
    // LinkedList list1 = NULL;

    printf("ADD: %p\n",list1);
    printf("-----------------------------------------------------\n");
    list1 = createNewLinkedList();
    insertBegning(10,list1);
    printList(list1);  printf("\n");
    insertEnding(9,list1);
    printList(list1);printf("\n");
    insertBegning(11,list1);
    printList(list1);printf("\n");
    insertEnding(90,list1);
    printList(list1);printf("\n");
    insertIndex(1,list1,3);
    printList(list1);printf("\n");
    insertIndex(2,list1,2);
    printList(list1);printf("\n");
    insertIndex(1,list1,30);
    printList(list1);printf("\n");
    insertIndex(1,list1,0);
    printList(list1);printf("\n");
    deleteElement(9,list1);
    printList(list1); printf("\n");
    deleteElement(10,list1);
    printList(list1);printf("\n");
    printf("index: %d",findIndex(10,list1));
    printf("address of 10: %p",findPrevious(10,list1)); printf("\n");
    deleteElement(10,list1);
    printList(list1); printf("\n");
}