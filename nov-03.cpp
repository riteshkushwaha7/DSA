// 796. Rotate String

class Solution {
public:
    void shift(string &s){
        char temp = s[0];
        s.erase(0,1);

        s.push_back(temp);
    }

    bool rotateString(string s, string goal) {
        int n = s.size();
        if(goal.size()!=n) return false;

        if(s==goal) return true;

        for(int i = 1; i<=n; i++){
            shift(s);
            if(s==goal) return true;
        }
        return false;
    }
};
