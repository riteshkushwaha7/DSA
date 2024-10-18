class Solution {
public:
    
    Node* segregate(Node* head) {
        
        Node dummyZero(0), dummyOne(0), dummyTwo(0);
        Node* z = &dummyZero;
        Node* o = &dummyOne;
        Node* t = &dummyTwo;

        Node* curr = head;
        
        
        while (curr) {
            if (curr->data == 0) {
                z->next = curr;
                z = z->next;
            } else if (curr->data == 1) {
                o->next = curr;
                o = o->next;
            } else {
                t->next = curr;
                t = t->next;
            }
            curr = curr->next;
        }
        
        
        z->next = dummyOne.next ? dummyOne.next : dummyTwo.next;
        o->next = dummyTwo.next;
        t->next = nullptr;  

        return dummyZero.next;
    }
};
