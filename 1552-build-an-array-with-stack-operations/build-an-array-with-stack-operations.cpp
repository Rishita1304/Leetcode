class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int a = 1;
        for(int i=0; i<target.size();i++){
            while(a<target[i]){
                ans.push_back("Push");
                ans.push_back("Pop");
                a++;
            }
            ans.push_back("Push");
            a++; 
        }
        return ans;
    }
};