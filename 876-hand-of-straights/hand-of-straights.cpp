class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        if(hand.size()==1 || groupSize==1) return true;

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto h:hand) pq.push(h);

        int curr=0, prev = -1;
        vector<int> temp;
        
        while(!pq.empty()){
            int t = pq.top(); pq.pop();
            if(prev==-1 || t-prev==1){
                prev = t;
                curr++;
            }
            else temp.push_back(t);
            if(curr==groupSize){
                curr=0; prev=-1;
                for(auto i:temp) pq.push(i);
                temp = {};
            }
        }
        return curr? false : true;
    }
};