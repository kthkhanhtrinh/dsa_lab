template <class T>
void SLinkedList<T>::bubbleSort()
{   
    if (head == NULL) return;

    bool swapped; 
    do
    {
        swapped = false; 
        Node* j = head;

        while (j->next) {
            if (j->data > j->next->data) {
                swap(j->data, j->next->data);
                swapped = true; 
            }
            j = j->next; 
        }
        if(swapped)
            this->printList();

    } while (swapped); 
}