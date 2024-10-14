class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> max_heap;
        for(auto i: nums){
            max_heap.push(i);
        }
        long long sum = 0;
        while(k--){
            if(max_heap.empty()) return sum;
            long long temp = max_heap.top();
            max_heap.pop();
            sum += temp;
            long long new_temp = ceil((double)temp/3);
            max_heap.push(new_temp);
        }
        return sum;
    }
};