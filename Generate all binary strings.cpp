




class Solution{
public: 
    void strings(int n, vector<string>& v, int index, string temp){
        if(index == n){
            v.push_back(temp);
            return;
        }
        
        temp.push_back('0');
        strings(n, v, index + 1, temp);
        temp.pop_back();
        
        temp.push_back('1');
        if(index == 0 || temp[index-1] != '1') // Prevent consecutive '1's
            strings(n, v, index + 1, temp);
    }

    vector<string> generateBinaryStrings(int num){
        vector<string> ans;
        int index = 0;
        string temp;
        strings(num, ans, index, temp);
        return ans;
    }
};
