class Solution {
public:
    bool canPlaceFlowers(vector<int>& flo, int n) {
        if(n == 0) return true;
            
        for(int i = 0; i<flo.size(); i++){
            if( flo[i] == 0  //check curr is 0
            && (i == 0 || flo[i-1] == 0) // left is 0
            && (i == flo.size()-1 || flo[i+1] == 0)){ //right is 0
                flo[i] = 1;
                n--;
            }
            if(n==0) return true;
            
        }
        return false;
    }
};