class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int init = 0;
        int maxi = 0;
        int curr = 0;
        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0){
                init+=customers[i];
            }
            else if(i<minutes){
                curr+=customers[i];
            }
        }
        maxi = curr;
        for(int i=minutes; i<customers.size();i++){
            curr+=customers[i]*grumpy[i];
            curr-=customers[i-minutes]*grumpy[i-minutes];
            maxi=max(maxi, curr);
        }
        return init+maxi;
    }
};