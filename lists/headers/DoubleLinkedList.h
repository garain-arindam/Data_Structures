#ifndef LINKED_LIST
#define LINKED_LIST

#ifndef INTERGER
    #define INTERGER
    typedef int ElementType;
    #define FS "%d"
#endif

// structure for node of the list
struct Node{
    ElementType element;
    int length;
    struct Node* next;
    struct Node* previous;
};
typedef struct Node node;
typedef node* nodeptr;
typedef nodeptr DoubleLinkedList;

// operations
DoubleLinkedList createNewLinkedList(); // creating an empty list
void insertBegning(ElementType, DoubleLinkedList); // inserting an element at the starting of the list
void insertEnding(ElementType, DoubleLinkedList); // inserting an element at the ending of the list
void insertPosition(ElementType, DoubleLinkedList, int); // inserting an element at a particular position
int isEmpty(DoubleLinkedList); // to check if the list is empty
int getLength(DoubleLinkedList); // for finding the length of the list
void printList(DoubleLinkedList); // for displaying the list
int findIndex(ElementType, DoubleLinkedList); // finding index of an element
nodeptr findPrevious(ElementType, DoubleLinkedList); // finding pointer to an element
void deleteElement(ElementType,DoubleLinkedList); // deleting an element
void deleteList(DoubleLinkedList*); // deleting the whole list

#endif