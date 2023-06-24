void insert(Node** head, int value){
    Node* newNode = new Node(value);
    newNode->next = *head;
    *head = newNode;
}