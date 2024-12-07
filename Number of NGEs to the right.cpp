

class Solution {
public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        vector<int> nge(arr.size());
        stack<int> st;

        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                nge[i] = -1;
            } else {
                nge[i] = st.top();
            }
            st.push(arr[i]);
        }

        vector<int> ans(queries);
        for (int i = 0; i < queries; i++) {
            int index = indices[i];
            int count = 0;
            for (int j = index + 1; j < n; j++) {
                if (arr[j] > arr[index]) {
                    count++;
                }
            }
            ans[i] = count;
        }
        return ans;
    }
};
