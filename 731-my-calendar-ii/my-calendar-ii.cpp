class MyCalendarTwo {
public:
    map<int, int> m;
    MyCalendarTwo() {
        
    }
    bool canAdd(){
        int cnt=0;
        for(auto i:m){
            cnt += i.second;
            if(cnt > 2) return false;
        }
        return true;
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        if(canAdd()) return true;
        else{
            m[start]--;
            m[end]++;
            return false;
        }
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */