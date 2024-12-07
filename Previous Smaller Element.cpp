


vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> nge(A.size());
        stack<int> st;

        for (int i = 0 ; i < A.size(); i++) {
            while (!st.empty() && st.top() >= A[i]) {
                st.pop();
            }
            if (st.empty()) {
                nge[i] = -1;
            } else {
                nge[i] = st.top();
            }
            st.push(A[i]);
        }
        return nge;
}
