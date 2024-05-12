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
    struct Node* next;
    int length;
};
typedef struct Node node;
typedef node* nodeptr;
typedef nodeptr LinkedList;

// operations
LinkedList createNewLinkedList(); // creating an empty list
void insertBegning(ElementType, LinkedList); // inserting an element at the starting of the list
void insertEnding(ElementType, LinkedList); // inserting an element at the ending of the list
void insertIndex(ElementType, LinkedList, int); // inserting an element at a particular position
int isEmpty(LinkedList); // to check if the list is empty
int getLength(LinkedList); // for finding the length of the list
void printList(LinkedList); // for displaying the list
int findIndex(ElementType, LinkedList); // finding index of an element
nodeptr findPrevious(ElementType, LinkedList); // finding pointer to an element
void deleteElement(ElementType,LinkedList); // deleting an element
void deleteList(LinkedList*); // deleting the whole list

#endif