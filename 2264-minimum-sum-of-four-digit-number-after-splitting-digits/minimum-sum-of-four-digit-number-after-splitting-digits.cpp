class Solution {
public:
    int minimumSum(int num) {
        vector<int> ans;
        while(num>0){
            int temp = num%10;
            ans.push_back(temp);
            num/=10;
        }
        sort(ans.begin(), ans.end());
        int n1 = ans[0]*10; n1 += ans[3];
        int n2 = ans[1]*10; n2 += ans[2];
        return n1+n2;
    }
};