class Solution {
public:
    vector<int> NGE(vector<int>& nums) {
        vector<int> nge(nums.size());
        stack<int> st;

        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? nums.size() : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> PSE(vector<int>& nums) {
        vector<int> pse(nums.size());
        stack<int> st;

        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nge = NGE(arr);
        vector<int> pse = PSE(arr);

        long long total = 0, mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) {
            int left = i - pse[i];
            int right = nge[i] - i;
            total = (total + (long long)arr[i] * left * right) % mod;
        }
        return total;
    }
};
