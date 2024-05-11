class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        for(auto p:paths){
            s.insert(p[0]);
        }

        for(auto p:paths){
            string d = p[1];
            if(s.find(d)==s.end()) return d;
        }
        return "";
    }
};