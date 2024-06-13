class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int cnt=0;
        for(int i=0;i<seats.size();i++){
            int num = abs(students[i] - seats[i]);
            cnt+=num;
        }
        return cnt;
    }
};