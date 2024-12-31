class Solution {
  public:
    void func(int ind,int sum, vector<int> &arr, int N, vector<int> &sumsubset){
        if(ind ==N){
            sumsubset.push_back(sum);
            return;
        }
        func(ind+1, sum+arr[ind], arr,N, sumsubset);
        func(ind+1, sum, arr, N, sumsubset);
    }
    vector<int> subsetSums(vector<int>& arr) {
        int N = arr.size();
        vector<int> sumsubset;
        func(0,0,arr,N,sumsubset);
        sort(sumsubset.begin(),sumsubset.end());
        return sumsubset;
    }
};
