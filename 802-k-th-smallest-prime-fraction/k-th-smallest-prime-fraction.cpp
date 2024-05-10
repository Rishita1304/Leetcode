class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        if(arr.size()==2) return arr;
        priority_queue<pair<double,pair<int,int>>, vector<pair<double,pair<int,int>>>, greater<pair<double,pair<int,int>>>> pq;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                pq.push({(double)arr[i]/arr[j], {arr[i],arr[j]}});
            }
        }
        pair<int,int> result;
        for(int i=0;i<k;i++){
            result = pq.top().second;
            pq.pop();
        }
        return {result.first,result.second};
    }
};