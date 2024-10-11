class Solution {
public:
    ListNode* MergeLL(ListNode* L1, ListNode* L2){
        ListNode* temp = new ListNode(-1);
        ListNode* curr = temp;

        while(L1 && L2){
            if(L1->val <= L2->val){
                curr->next = L1;
                curr = curr->next;
                L1 = L1->next;
            }
            else {
                curr->next = L2;
                curr = curr->next;
                L2 = L2->next;
            }
        }
        if(L1) curr->next = L1;
        else curr->next = L2;
        return temp->next;
    }

    ListNode* Middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* middle = Middle(head);
        ListNode* L2 = middle->next;
        middle->next = NULL;
        ListNode* L1 = head;

        L1 = sortList(L1);
        L2 = sortList(L2);

        return MergeLL(L1,L2);
    }
};
