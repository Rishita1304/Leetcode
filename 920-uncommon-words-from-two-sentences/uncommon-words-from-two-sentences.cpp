class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;
        string word;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != ' '){
                word.push_back(s1[i]);
            }
            if(s1[i] == ' ' ||i == s1.size()-1){
                m[word]++;
                word = "";
            }
        }
        for(int i=0; i<s2.size(); i++){
            if(s2[i] != ' '){
                word.push_back(s2[i]);
            }
            if(s2[i] == ' ' ||i == s2.size()-1){
                m[word]++;
                word = "";
            }
        }     
        vector<string> ans;
        for(auto c:m){
            if(c.second == 1){
                ans.push_back(c.first);
            }
        }   
        return ans;
    }
};