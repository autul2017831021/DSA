void delete_by_index(Node** head, int index){
    if((*head) == nullptr)return;
    // If Head Is Getting Deleted
    if(index == 0){
        Node* deleteThisNode = *head;
        (*head) = (*head)->next;
        free(deleteThisNode);
        // delete deleteThisNode;
        return;
    }
    // Anything But Head
    int i = 0;
    Node* current = *head;
    while(current != NULL){
        i++;
        if(i==index && current->next != NULL){
            Node* deleteThisNode = current->next;
            current->next = deleteThisNode->next; /// current->next->next;
            free(deleteThisNode);
            // delete deleteThisNode;
            break;
        }
        current = current->next;
    }
}