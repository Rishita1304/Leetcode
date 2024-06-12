#define ll long long
class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        ll n = grades.size(), low=0, high=grades.size(), maxi=0;
        while(low<=high){
            ll mid = (low+high)>>1;
            ll x = (ll)(mid*(mid+1))/2;
            if(x<=n){
                maxi = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return maxi;
    }
};