


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                st.push(nums[i]);
            } else {
                while (!st.empty() && st.top() > 0 && st.top() < abs(nums[i])) {
                    st.pop();
                }
                if(!st.empty() && st.top() > 0 && st.top() == abs(nums[i])){
                    st.pop();
                    continue;
                }
                else if (!st.empty() && st.top() > abs(nums[i])) continue;
                st.push(nums[i]);
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            int top = st.top(); st.pop();
            ans.push_back(top);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
