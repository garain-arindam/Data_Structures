#include <stdio.h>
#include "../headers/LinkedList.h"

void main(int argc,char ** argv){
    LinkedList list1 = createNewLinkedList();
    insertBegning(10,list1);
    insertBegning(11,list1);
    printList(list1);
}