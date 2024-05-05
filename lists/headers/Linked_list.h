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
    struct Node * next;
};
typedef struct Node node;
typedef node* nodeptr;
typedef nodeptr LinkedList;

// operations
nodeptr createNewLinkedList(); // creating an empty list
void insert(ElementType, LinkedList); // inserting element in the list
int isEmpty(LinkedList); // to check if the list is empty
void printList(LinkedList); // for displaying the list
int find(ElementType, LinkedList); // finding an element
void deleteElement(ElementType,LinkedList); // deleting an element
void deleteList(LinkedList); // deleting the whole list

#endif