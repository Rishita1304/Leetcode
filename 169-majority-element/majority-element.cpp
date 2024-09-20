class Solution {
public: 
    //moore voting algorithm
    
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int element;
        for(int i=0;i<nums.size();i++){
            if(cnt == 0){
                element = nums[i];
                cnt++;
            }
            else if(nums[i] == element) cnt++;
            else cnt--;
        }
        return element;
    }
};