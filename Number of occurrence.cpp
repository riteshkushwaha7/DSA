class Solution {
  public:
      int lb(vector<int> &nums, int target, int n){
        int start = 0;
        int end = n-1;
        int ans = n;

        while(start<=end){
            int mid = (start + end)/2;

            if(nums[mid]>=target){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }

    int ub(vector<int> &nums, int target, int n){
        int start = 0;
        int end = n-1;
        int ans = n;

        while(start<=end){
            int mid = (start + end)/2;

            if(nums[mid]>target){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
    int count(vector<int>& arr, int target) {
        int n = arr.size();
        int l = lb(arr,target,n);
        if(l==n || arr[l]!=target) return 0;
        else return abs(l-ub(arr,target,n));
    }
};
