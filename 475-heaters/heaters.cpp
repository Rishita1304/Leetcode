class Solution {
public:
    int solve(int house, vector<int>& heaters){
        int l = 0;
        int r = heaters.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(heaters[mid]==house) return 0;
            if(heaters[mid]<house) l=mid+1;
            if(heaters[mid] > house) r = mid - 1;
        }
        return min(heaters[l]-house, house-heaters[r]);
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans=0;
        sort(heaters.begin(), heaters.end());
        for(auto h:houses){
            if(h<=heaters.front()){
                ans = max(ans, heaters.front()-h);
                continue;
            }
            if(h>=heaters.back()){
                ans = max(ans, h-heaters.back());
                continue;
            }
            ans = max(ans, solve(h,heaters));
        }
        return ans;
    }
};