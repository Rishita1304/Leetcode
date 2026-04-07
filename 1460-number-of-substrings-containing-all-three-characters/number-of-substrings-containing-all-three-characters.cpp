class Solution {
public:
    int numberOfSubstrings(string s) {
        int last[3] = {-1,-1,-1};
        int cnt= 0;
        
        for(int i=0;i<s.size();i++){
            last[s[i]-'a'] = i;
            if(last[0] != -1 && last[1] != -1 && last[2] != -1){
                int ind = min(last[0], min(last[1], last[2]));
                cnt += (ind+1);
            }
        }
        return cnt;












        // int n = s.size();
        // int i=0,j=0,ans=0;
        // vector<int> v(3,0);
        // for(int j=0;j<n;j++){
        //     v[s[j]-'a']++;
        //     while(v[0]>0 && v[1]>0 && v[2]>0 && i<=j){
        //         v[s[i]-'a']--;
        //         ans+=(n-j);
        //         i++;
        //     }
        // }
        // return ans;
    }
};