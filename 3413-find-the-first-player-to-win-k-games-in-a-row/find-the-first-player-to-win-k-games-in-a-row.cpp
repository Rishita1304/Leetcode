class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int count=0;
        int max_i=0;
        for(int i=1;i<n && count<k; i++){
            if(skills[i]<skills[max_i]) count++;
            else{
                count=1;
                max_i=i;
            }
        }
        return max_i;
    }
};