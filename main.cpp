//Bo Ying Liu

//Design your own linked list class to hold a series of integers. The class should have member functions for appending, inserting, and deleting nodes. Don’t forget to add a destructor that destroys the list. Demonstrate the class with a driver program.//



#include <iostream>
using namespace std;

struct ListNode {
    float value;
    ListNode *next;
};
ListNode *head;

class LinkedList {
public:
    int insertNode(float num);
    int appendNode(float num);
    void deleteNode(float num);
    void destroyList();
    void displayList();
    LinkedList(void) {head = NULL;}
    ~LinkedList(void) {destroyList();}
};

int LinkedList::appendNode(float num)
{
    ListNode *newNode, *nodePtr = head;
    newNode = new ListNode;
    if(newNode == NULL) {
        cout << "Error allocating memory for new list member!\n";
        return 1;
    }
    newNode->value = num;
    newNode->next = NULL;
    if(head == NULL) {
        cout << "List was empty - " << newNode->value;
        cout << " is part of list's first node.\n";
        head = newNode;
    }
    else {
        while(nodePtr->next != NULL)
            nodePtr = nodePtr->next;
        nodePtr->next = newNode;
    }
    return 0;
}

//insert node from linkedlist
int LinkedList::insertNode(float num)
{
    struct ListNode *newNode, *nodePtr = head, *prevNodePtr = NULL;
    
    newNode = new ListNode;
    if(newNode == NULL) {
        cout << "Error allocating memory for new list member!\n";
        return 1;
    }
    newNode->value = num;
    newNode->next = NULL;
    if(head==NULL) {
        cout << "List was empty - " << newNode->value;
        cout << " is part of list's first node.\n";
        head = newNode;
    }
    else {
        while((nodePtr != NULL) && (nodePtr->value < num)) {
            prevNodePtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        if(prevNodePtr==NULL)
            newNode->next = head;
        else
            newNode->next = nodePtr; prevNodePtr->next = newNode;
    }
    return 0;
}


//delete node from linked list
void LinkedList::deleteNode(float num)
{
    struct ListNode *nodePtr = head, *prevNodePtr = NULL;
    
    if(head==NULL) {
        cout << "The list was empty!\n";
        return;
    }
    if(head->value == num) {
        head = nodePtr->next;
        delete [] nodePtr;
    }
    else {
        while((nodePtr!= NULL)&&(nodePtr->value != num)) {
            prevNodePtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        if(nodePtr==NULL)
            cout << "The value " << num << " is not in this list!\n";
        else {
            prevNodePtr->next = nodePtr->next;
            delete [] nodePtr;
        }
    }
}
//destroy list
void LinkedList::destroyList()
{
    struct ListNode *nodePtr = head, *nextNode = nodePtr;
    
    if(head==NULL) {
        cout << "The list is empty!\n";
        return;
    }
    while (nodePtr != NULL) {
        nextNode = nodePtr->next;
        delete [] nodePtr;
        nodePtr = nextNode;
    }
}

//display list
void LinkedList::displayList()
{
    struct ListNode *nodePtr = head;
    if (nodePtr == NULL)
        cout << "The list is empty!\n";
    else {
        while (nodePtr != NULL) {
            cout << nodePtr->value << endl;
            nodePtr = nodePtr->next;
        }
    }
}


int main()
{
    int num;
    char answer;
    LinkedList temp;
    
    
    //do loop to create an integer list
    do {
        cout << "Please enter a value to put in the list --> ";
        cin >> num;
        temp.insertNode(num);
        cout << endl;
        
        //choose Y to continue add integer into the list
        cout << "Would you like to put another value into your list? (Y/N)";
        cin >> answer;
        
    } while(toupper(answer)=='Y');
    
    cout << "I will now display your list!\n";
    cout << endl;
    temp.displayList();
    
    //insert value to the list
    cout << "Please enter a value to insert in the list --> ";
    cin >> num;
    temp.insertNode(num);
    cout << "I will now display your updated list!\n";
    cout << endl;
    temp.displayList();
    
    //deleting node from list
    cout << "Now deleting the node, enter a value to delete";
    cin>>num;
    cout<<" Here are the list now";
    
    temp.deleteNode(num);
    temp.displayList();
    
    temp.destroyList();
    
    
}
