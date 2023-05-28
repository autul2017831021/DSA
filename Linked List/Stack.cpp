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

///IsEMPTY
bool isEmpty(Node** head){
    return (*head) == NULL;
}

/// PUSH
void push(Node** head, int value){
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

/// POP
void pop(Node** head){
    if(isEmpty(head)){
        cout<<"Stack Is Empty"<<endl;
        return;
    }
    Node* deleteThisNode = *head;
    (*head) = (*head)->next;
    free(deleteThisNode);
    return;
}
/// TOP
int top(Node** head){
    if(isEmpty(head)){
        cout<<"Stack Is Empty"<<endl;
        return -1;
    }
    return (*head)->data;
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
    int num_nodes,index_to_delete,num;
    cout<<"Number Of Nodes ";
    cin>>num_nodes;

    struct Node* head = NULL;

    for(int i=1;i<=num_nodes;i++){
        cin>>num;
        push(&head,num);
    }

    forward_traverse(&head);

    while(scanf("%d",&num) != EOF){
        if(num>0)push(&head,num);
        if(num<0)break;
        if(isEmpty(&head))break;
        int x = top(&head);
        cout<<"TOP : "<<x<<endl;
        pop(&head);
    }
}


