class Solution {
public:
    // void sortColors(vector<int>& nums) {
    //     int zero=0,one=0,two=0;
    //     for(int i=0;i<nums.size();i++){
    //         if(nums[i]==0) zero++;
    //         else if(nums[i]==1) one++;
    //         else two++;
    //     }
    //     int k=0;
    //     while(zero--){
    //         nums[k++] = 0;
    //     }
    //     while(one--){
    //         nums[k++] = 1;
    //     }
    //     while(two--){
    //         nums[k++] = 2;
    //     }
    // }


    //dutch national flag algo
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){
            if(nums[mid]==0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};