class Solution {
public:
    void fill(string word, vector<int> &count){
        for(auto ch:word){
            count[ch-'a']++;
        }
    }
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int> count(26,0);
        fill(words[0], count);
        for(int i=1;i<words.size();i++){
            vector<int> temp(26,0);
            fill(words[i], temp);
            for(int j=0;j<26;j++){
                count[j] = min(count[j], temp[j]);
            }
        }
        for(int i=0;i<26;i++){
            int ch = count[i];
            char s = char(i+97);
            string n = "";
            n+=s;
            while(ch--){
                ans.push_back(n);
            }
        }
        return ans;
    }
};