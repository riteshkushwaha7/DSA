// Add 1 to a LinkedList
class Solution {
public:
    Node* reverse(Node* head) {
        if (!head || !head->next) return head;

        Node* curr = head->next;
        Node* prev = head;
        prev->next = nullptr; 

        while (curr) {
            Node* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        head = prev;
        return head;
    }

    Node* addOne(Node* head) {
        head = reverse(head);

        Node* temp = head;
        int carry = 1;

        while (temp) {
            temp->data += carry;

            if (temp->data < 10) {
                carry = 0;
                break;
            } else {
                temp->data = 0;
                carry = 1;
            }
            if (!temp->next && carry == 1) {
                temp->next = new Node(1);
                carry = 0;
                break;
            }
            temp = temp->next;
        }

        return reverse(head);
    }
};
