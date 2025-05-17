class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        
        Node* node = new Node(data);
        
        int c = 0;
        Node* temp = head;
        while(c < pos ){
            temp = temp -> next;
            c++;
        }
        
        
        node -> next = temp -> next;
        if(temp -> next != NULL){
            temp -> next -> prev = node;
        }
        node -> prev = temp;
        temp -> next = node;
        
            
        return head;
        
    }
};