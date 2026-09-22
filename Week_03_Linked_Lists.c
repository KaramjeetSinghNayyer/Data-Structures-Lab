#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data ;
    struct Node * next;
};

// We initialise the linked list with head == NULL 

struct Node* createNode(int data){
    struct Node * node = (struct Node *)malloc(sizeof(struct Node));
    if(node == NULL) return NULL;

    node->data = data;
    node->next = NULL;
    return node;
}

//method to initialize the linked list
//**had is the oijnter to the ointer if the strucrt Niode data structure and returns a pointer to the Node data structure */
void initializeList(struct Node **head){
    *head = NULL;
}
//method to initialise list given a head ptr and a data value for the 1st node 
struct Node** initialiseList2(struct Node** head , int data){
    struct Node * temp = createNode(data);
    if(temp != NULL) {
        *head = temp;
    }
    return head;
}
//method to check if the linked list is empty or not 
int isEmpty(struct Node * head){
    return head == NULL;
}

//method to clear the linked list and release all the memory occupied by the nodes
void clearList(struct Node **head){
    struct Node * temp = *head ;
    while (temp!=NULL){
        struct Node *temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
    *head = NULL;
}

//method to delete the LL and clear all the memory allocated to every node including the head node 
void deleteList(struct Node ** head){
    struct Node * temp = *head;
    while(temp!= NULL){
        struct Node * temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
    free(head);
}



