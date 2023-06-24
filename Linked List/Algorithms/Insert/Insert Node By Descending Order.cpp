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