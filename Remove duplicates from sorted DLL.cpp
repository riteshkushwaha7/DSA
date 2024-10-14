class Solution {
public:
    Node * removeDuplicates(struct Node *head) {
        if (!head) return nullptr;

        Node* curr = head->next;
        Node* back = head;

        while (curr) {
            if (curr->data == back->data) {
                Node* front = curr->next;
                back->next = front;
                if (front) {
                    front->prev = back;
                }
                delete curr;
                curr = front;
            } else {
                back = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
