class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        
        if(x == 1){
            Node* temp =  head;
            head = head -> next;
            head -> prev = NULL;
            return head;
            delete(temp);
        }
        
        int i = 1;
        Node* current = head;
        
        while(i < x){
            current = current -> next;
            i++;
        }
        
        
       if (current->next != NULL) {
            current->next->prev = current->prev;  
        }
        if (current->prev != NULL) {
            current->prev->next = current->next; 
        }
        return head;
        
        
    }
};