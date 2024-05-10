class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto i:arr){
            pq.push({abs(i-x), i});
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            int it = pq.top().second;
            pq.pop();
            ans.push_back(it);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};