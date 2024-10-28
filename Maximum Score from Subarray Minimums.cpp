class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        int maxi = INT_MIN;
        int a = arr[0];
        for(int i = 1; i<arr.size(); i++){
            int b = arr[i];
            maxi = max(maxi,a+b);
            a = b;
        }
        return maxi;
    }
};
