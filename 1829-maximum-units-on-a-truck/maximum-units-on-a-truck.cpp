class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;
        int i=0;
        int n = boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(), compare);
        while(i<n && truckSize){
            if(truckSize>=boxTypes[i][0]){
                int temp = boxTypes[i][0] * boxTypes[i][1];
                ans += temp;
                truckSize -= boxTypes[i][0];
                i++;
            }
            else{
                int temp = truckSize*boxTypes[i][1];
                ans+=temp;
                break;
            }
        }
        return ans;
    }
};