class Solution {
public:
    void solve(int fact,vector<int> &v, int k, string &s){
        if(v.size()==0) {
            return;
        }
        s = s+to_string(v[k/fact]);
        v.erase(v.begin()+k/fact);
        if(v.size()!=0) solve(fact/v.size(),v,k%fact,s); 

    }
    string getPermutation(int n, int k) {
        int fact =1;
        vector<int> v;
        for( int i=1; i<n;i++){
            fact *= i;
            v.push_back(i);
        }v.push_back(n);
        k--;
        string s="";
        solve(fact,v,k,s);
        return s;
    }
};