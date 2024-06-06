class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gr) {
        if(hand.size()%gr!=0) return false;
        if(hand.size()==1 && gr==1) return true;
        map<int,int> mp;
        for(auto i:hand){
            mp[i]++;
        }
        while(!mp.empty()){
            int curr = mp.begin()->first;
            for(int i=0;i<gr;i++){
                if(mp[curr+i]==0) return false;
                mp[curr+i]--;
                if(mp[curr+i]<1) mp.erase(curr+i);
            }
        }
        return true;
    }
};