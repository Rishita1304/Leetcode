class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        string c = s+s;
        return c.find(goal) != string::npos;
    }
};