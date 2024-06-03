class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int cnt=0;
        int n = meetings.size();
        int last = 1;
        for(int meet=0;meet<n;meet++){
            int s = meetings[meet][0], e = meetings[meet][1];
            if(s>last)
            {
                cnt+= (meet==0) ? (s-last) : (s - last - 1);
            }
            last = max(last,e);
        }
        if(days>last)
            cnt+= (days - last);
        return cnt;
    }
};