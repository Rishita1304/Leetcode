class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCount = 0, tenCount = 0, twentyCount = 0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                fiveCount++;
            }
            else if(bills[i]==10){
                if(fiveCount<1) return false;
                else{
                    tenCount++;
                    fiveCount--;
                }    
            }
            else{
                if((fiveCount<3 && tenCount==0) || fiveCount<1 ) return false;
                else if(tenCount>0){
                    tenCount--;
                    fiveCount--;
                }
                else{
                    fiveCount-=3;
                }
            }
        }
        return true;
    }
};