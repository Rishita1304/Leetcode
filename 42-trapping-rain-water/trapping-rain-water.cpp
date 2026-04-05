class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int lmax = height[l];
        int r = height.size() - 1;
        int rmax = height[r];

        int total = 0;

        while(l<r){
            if(height[l]>lmax) lmax = height[l];
            if(height[r]>rmax) rmax = height[r];
            if(lmax < rmax){
                total += lmax - height[l];
                l++;
            }
            else{
                total += rmax - height[r];
                r--;
            }
        }
        return total;
    }
};