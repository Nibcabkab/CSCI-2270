node * ReverseLinkedList(node *head){
    node* cursor = NULL;
    node* next;
    while (head)
    {
        next = head->next;
        head->next = cursor;
        cursor = head;
        head = next;
    }
    return cursor;
}

node * DeleteNode(node *head, int value){
    node* temp = NULL;
    temp = head;
    while(temp->next != NULL){
        if(value == head->value){
            head = head->next;
            delete temp;
        }
        else{
            if(temp->value == value){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
        }
        temp = temp->next;
    }
    if(temp->value == value){
        temp->prev->next = temp->next;
        delete temp;
    }
    return head;
}
