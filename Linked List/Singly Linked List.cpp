#include<bits/stdc++.h>
using namespace std;
#define nl printf("\n")
#define sp printf(" ")

struct Node{
    int data;
    Node* next;
};

Node* createNode(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/// INSERT AT END
void insert_at_end_my_way(Node** head, int value){
    cout<<"insert -> "<<value<<" : ";
    Node* current = *head;
    Node* parentNode = *head;
    while(true){
        if(current == NULL){
            cout<<"NULL"<<endl;
            Node* newNode = createNode(value);
            if(*head == NULL){
                *head = newNode;
            }
            else{
                parentNode->next = newNode;
            }
            break;
        }
        cout<<current->data<<" ";
        parentNode = current;
        current = current->next;
    }
}

void insert_at_end(Node** head, int value){
    Node* newNode = createNode(value);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node* lastNode = *head;
    while(lastNode->next != NULL){
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

/// INSERT AT BEGINNING
void insert_at_beginning(Node** head, int value){
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

/// DELETE
void delete_by_index(Node** head, int index){
    if((*head) == nullptr)return;
    if(index == 0){
        Node* deleteThisNode = *head;
        (*head) = (*head)->next;
        free(deleteThisNode);
        return;
    }
    int i = 0;
    Node* current = *head;
    while(current != NULL){
        i++;
        if(i==index && current->next != NULL){
            Node* deleteThisNode = current->next;
            current->next = deleteThisNode->next; /// current->next->next;
            free(deleteThisNode);
            break;
        }
        current = current->next;
    }
}

/// SORT
/// Ascending
void sort_by_ascending(Node** head,int value){
    if((*head) == NULL || value<(*head)->data){
        insert_at_beginning(head,value);
        return;
    }
    Node* curr = *head;
    Node* parentNode = *head;
    while(curr != NULL){
        if(value < curr->data){
            Node* newNode = createNode(value);
            parentNode->next = newNode;
            newNode->next = curr;
            return;
        }
        parentNode = curr;
        curr = curr->next;
    }
    Node* newNode = createNode(value);
    parentNode->next = newNode;
}

/// SORT
/// Descending
void sort_by_descending(Node** head,int value){
    if((*head) == NULL || value>(*head)->data){
        insert_at_beginning(head,value);
        return;
    }
    Node* curr = *head;
    Node* parentNode = *head;
    while(curr != NULL){
        if(value > curr->data){
            Node* newNode = createNode(value);
            parentNode->next = newNode;
            newNode->next = curr;
            return;
        }
        parentNode = curr;
        curr = curr->next;
    }
    Node* newNode = createNode(value);
    parentNode->next = newNode;
}

/// TRAVERSE
void forward_traverse(Node** head){
    cout<<"Forward Traverse : ";
    Node* current = *head;
    while(current != NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}


int main() {
    int num_nodes,index_to_delete;
    cout<<"Number Of Nodes ";
    cin>>num_nodes;

    struct Node* head = NULL;

//    head = (Node*)malloc(sizeof(Node));
//    head->data = 1;
//    head->next = NULL;
//
//    head->next = new Node;
//    head->next->data = 2;
//    head->next->next = NULL;
//
//    head->next->next = new Node;
//    head->next->next->data = 3;
//    head->next->next->next = NULL;
//
//    head->next->next->next = new Node;
//    head->next->next->next->data = 1;
//    head->next->next->next->next = NULL;

    for(int i=1;i<=num_nodes;i++){
        int num;
        cin>>num;
        //insert_at_end_my_way(&head,num);
        //insert_at_end(&head,num);
        //insert_at_beginning(&head,num);
        //sort_by_ascending(&head,num);
        //sort_by_descending(&head,num);
    }

    forward_traverse(&head);

    while(scanf("%d",&index_to_delete) != EOF){
        delete_by_index(&head,index_to_delete);
        forward_traverse(&head);
        if(head == NULL)break;
    }
}

