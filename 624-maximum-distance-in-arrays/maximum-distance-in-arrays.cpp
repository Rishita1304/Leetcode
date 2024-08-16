class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int global_min = arrays[0][0];
        int global_max = arrays[0].back();
        int max_distance = 0;
        
        for (int i = 1; i < arrays.size(); ++i) {
            const auto& arr = arrays[i];
            
            int curr_min = arr[0];
            int curr_max = arr.back();
            
            max_distance = max(max_distance, curr_max - global_min);
            max_distance = max(max_distance, global_max - curr_min);
            
            global_min = min(global_min, curr_min);
            global_max = max(global_max, curr_max);
        }
        
        return max_distance;
    }
};