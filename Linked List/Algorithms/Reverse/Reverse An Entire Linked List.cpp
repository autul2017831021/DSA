void reverse(Node** head){
    if(*head == nullptr)return;
    Node* parent = NULL;
    Node* curr = *head;
    Node* succ = *head;
    while(succ != nullptr){
        curr = succ;
        succ = succ->next;
        curr->next = parent;
        parent = curr;
    }
    *head = curr;
    // return curr; // if head needs to be returned
}