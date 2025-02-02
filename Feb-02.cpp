class Solution {
public:
    bool sorted(vector<int> nums,vector<int> &temp){
        temp = nums;
        sort(temp.begin(),temp.end());
        return temp == nums;
    }
    bool check(vector<int>& nums) {
        vector<int> temp;
        for(int i = 0; i<nums.size(); i++){
            if(sorted(nums,temp)) return true;
            else{
                int n = nums[0];
                nums.erase(nums.begin());
                nums.push_back(n);
            }
        }
        return false;
    }
};
