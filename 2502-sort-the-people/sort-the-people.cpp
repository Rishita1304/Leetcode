class Solution {
public:
    bool cmp(pair<string, int>& a, 
        pair<string, int>& b){
            return a.second < b.second; 
        }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> mp;
        vector<string> v;
        for(int i=0;i<names.size();i++){
            mp[heights[i]] = names[i];
        }
        for(auto i=mp.rbegin(); i!=mp.rend(); ++i) v.push_back(i->second);
        return v;
    }
};