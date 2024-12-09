


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums) {
        vector<int> nge(nums.size());
        stack<int> st;

        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? nums.size() : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> prevGreaterElement(vector<int>& nums) {
        vector<int> pge(nums.size());
        stack<int> st;

        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int> nge = nextGreaterElement(arr);
        vector<int> pge = prevGreaterElement(arr);

        long long total = 0;
        for (int i = 0; i < arr.size(); i++) {
            int left = i - pge[i];
            int right = nge[i] - i;
            total += (long long)arr[i] * left * right;
        }
        return total;
    }

    vector<int> nextSmallerElement(vector<int>& nums) {
        vector<int> nse(nums.size());
        stack<int> st;

        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? nums.size() : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> prevSmallerElement(vector<int>& nums) {
        vector<int> pse(nums.size());
        stack<int> st;

        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = nextSmallerElement(arr);
        vector<int> pse = prevSmallerElement(arr);

        long long total = 0;
        for (int i = 0; i < arr.size(); i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            total += (long long)arr[i] * left * right;
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};
