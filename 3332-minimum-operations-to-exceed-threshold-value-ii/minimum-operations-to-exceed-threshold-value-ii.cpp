class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pr;
        int c = 0;
        for(auto n:nums){
            pr.push(n);
        }

    while(pr.size()>=2){
        if(pr.top()>=k) return c;
        c++;
        long x = pr.top(); pr.pop();
        long y = pr.top(); pr.pop();
        pr.push(min(x,y)* 2+max(x,y));
    }
    
    return c;
    }
};