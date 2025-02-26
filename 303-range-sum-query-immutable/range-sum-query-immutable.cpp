class NumArray {
    vector<int> temp;
public:
    NumArray(vector<int>& nums) {
        temp.push_back(0);
        for(int n:nums){
            temp.push_back(temp.back() + n);
        }
    }
    
    int sumRange(int left, int right) {
        return temp[right+1] - temp[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */