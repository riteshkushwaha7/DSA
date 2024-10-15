class Solution {
public:
    ListNode* kth(ListNode* temp, int k) {
        if (k == 1) return temp;
        ListNode* curr = temp;
        int count = 1;
        while (count != k && curr) {
            curr = curr->next;
            count++;
        }
        return curr;
    }

    ListNode* reverse(ListNode* temp) {
        ListNode* curr = temp;
        ListNode* prev = NULL;
        while (curr) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        
        while (temp) {
            ListNode* kthnode = kth(temp, k);
            if (kthnode == NULL) {
                if (prev) prev->next = temp;
                break;
            }
            ListNode* nextNode = kthnode->next;
            kthnode->next = NULL;
            ListNode* reversed = reverse(temp);
            if (temp == head) {
                head = reversed;
            } else {
                prev->next = reversed;
            }
            prev = temp;
            temp = nextNode;
        }
        return head;
    }
};
