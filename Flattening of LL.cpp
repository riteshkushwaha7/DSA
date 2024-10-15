class Solution {
public:
    Node* flatten(Node* root) {
        vector<int> store;
        Node* curr = root;
        

        while (curr) {
            store.push_back(curr->data);
            Node* lower = curr->bottom;
            while (lower) {
                store.push_back(lower->data);
                lower = lower->bottom;
            }
            curr = curr->next;
        }


        sort(store.begin(), store.end());


        int n = store.size();
        Node* head = new Node(-1); 
        curr = head;

        for (int i = 0; i < n; i++) {
            curr->bottom = new Node(store[i]);
            curr = curr->bottom;
        }

        return head->bottom; 
        
    }
};
