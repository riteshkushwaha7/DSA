
// Check If N and Its Double Exist


class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        if(arr.size()==1) return false;
        for(int i = 0; i<arr.size(); i++){
            for(int j = i+1; j<arr.size(); j++){
                if(arr[i]*2==arr[j] || arr[j]*2==arr[i]) return true;
            }
        }
        return false;
    }
};
