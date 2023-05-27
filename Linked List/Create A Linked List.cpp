#include<bits/stdc++.h>
using namespace std;
#define nl printf("\n")
#define sp printf(" ")

struct Node{
    int data;
    Node* next;
};

void insert(Node** head, int value){

}

void forward_traverse(Node** head){
    Node* current = *head;
    while(current != NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
    nl;
}


int main() {
    struct Node* head = NULL;

    head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;

    head->next = new Node;
    head->next->data = 2;
    head->next->next = NULL;

    head->next->next = new Node;
    head->next->next->data = 3;
    head->next->next->next = NULL;

    head->next->next->next = new Node;
    head->next->next->next->data = 1;
    head->next->next->next->next = NULL;

    forward_traverse(&head);
}

