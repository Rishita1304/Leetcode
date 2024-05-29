class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        long long cnt=0;
        while(target!=1){
            if(maxDoubles==0) return cnt+target-1;
            if(target%2==0 && maxDoubles>0){
                maxDoubles--;
                target/=2;
            }
            else target--;
            cnt++;
        }
        return cnt;
    }
};