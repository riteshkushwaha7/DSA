class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;

        ListNode* curr = head;
        int length = 1;  

        while (curr->next) {
            curr = curr->next;
            length++;
        }

        curr->next = head;  
        k = k % length;
        k = length - k;  

        while (k--) {
            curr = curr->next;
        }

        head = curr->next;
        curr->next = nullptr;

        return head;
    }
};
