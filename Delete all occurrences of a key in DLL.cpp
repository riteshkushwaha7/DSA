class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* temp = *head_ref;
        while(temp){
            if(temp->data == x){
                if(temp==*head_ref) {
                    *head_ref = temp->next;
                }
                Node* front = temp->next;
                Node* back = temp->prev;
                if(front) front->prev = back;
                if(back) back->next = front;
                
                //free(temp);
                
                temp = front;
            }
            else{
            temp = temp->next;
            }
        }
    }
};
