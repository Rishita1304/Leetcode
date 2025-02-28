class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        stack<int> s;

        for(int i=0;i<n;i++){
            if(s.empty() || a[i]>0) s.push(a[i]); //empty or +ve curr value
            else{ // -ve curr value
                while(!s.empty() && s.top()>0 && s.top()<abs(a[i])) 
                    s.pop(); //stack filled and top +ve and cur -ve bigger
                    
                if(!s.empty() && s.top()>0 && s.top()==abs(a[i])) s.pop(); //top and curr equal opp
                else if(s.empty() || s.top()<0) s.push(a[i]); //push only if the above condition is not true
            }
        }



        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top()); s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};