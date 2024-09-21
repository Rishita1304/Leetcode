class Solution {
public:
    vector<int> ans;
    void solve(int i, int n){
        if(i>n) return;
        int curr = i;
        ans.push_back(curr);
        for(int j=0;j<=9; j++){
            int tmp = curr*10 + j;
            solve(tmp,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<=9;i++){
            solve(i,n);
        }
        return ans;
    }
};