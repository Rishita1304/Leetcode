class Solution {
public:
    bool canSortArray(vector<int>& v) {
        int n=v.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n-1;j++) {
                int k=v[j];
                int c=0;
                while(k>0) {
                    k=(k&(k-1));
                    c++;
                }
                k=v[j+1];
                int c1=0;
                while(k>0) {
                    k=(k&(k-1));
                    c1++;
                }
                if(c==c1 && v[j]>v[j+1])
                    swap(v[j],v[j+1]);
                }    
        }
        for(int i=1;i<n;i++) {
            if(v[i]<v[i-1])
                return false;
        }
        return true;
    }
};