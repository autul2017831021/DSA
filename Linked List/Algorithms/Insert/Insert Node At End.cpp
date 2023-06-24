void insert(Node** head, int value){
    Node* newNode = new Node(value);
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
