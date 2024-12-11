class Solution {
public:
    int findSubarray(vector<int> &arr) {
        int n = arr.size();
        int cnt = 0;
        map<int, int> mpp;
        mpp[0] = 1; 
        int prefixsum = 0;

        for (int i = 0; i < n; i++) {
            prefixsum += arr[i];
            if(mpp.count(prefixsum)){
                cnt+=mpp[prefixsum];
                mpp[prefixsum]++;
            }else{
                mpp[prefixsum] = 1;
            }
        }
        return cnt;
    }
};
