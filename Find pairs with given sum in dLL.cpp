class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>> ans;
        
        Node* left = head;
        while(head->next){
            head = head->next;
        }
        Node* right = head;
        
        while(left->data < right->data){
            int sum = left->data + right->data;
            if(sum == target){
                pair<int,int> p = {left->data,right->data};
                ans.push_back(p);
                left = left->next;
                right = right->prev;
            }
            else if(sum> target) right = right->prev;
            else left = left->next;
        }
        return ans;
    }
};
