#define mod 1000000007
class Solution {
public:
    long long countGoodNumbers(long long n) {
        long long even = n/2+n%2;
        long long odd = n/2;
        return (myPow(5, even) * myPow(4,odd))%mod;
    }
    long long myPow(long long x, long long n){
        if(n==0) return 1;
        long long ans = myPow(x, n/2);
        ans *= ans;
        ans %= mod;
        if(n%2==1){
            ans*=x;
            ans%=mod;
        }
        return ans;
    }
};