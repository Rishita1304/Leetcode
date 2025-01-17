class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xr = 0;
        for (int d : derived) {
            xr ^= d;
        }
        return xr == 0;
    }
};