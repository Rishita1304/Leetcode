class MyCircularDeque {
public:
    int f;
    int r;
    int size;
    vector<int> dq;

    MyCircularDeque(int k) {
        f = -1;
        r = -1;
        size = k;
        dq.resize(size);
    }
    
    bool insertFront(int value) {
        if(f==-1){
            f=0; r=0;
            dq[f] = value;
            return true;
        }
        else{
            if(isFull()) return false;
            if(f==0) f = size-1;
            else f-=1;
            dq[f] = value;
        }
        return true;
    }
    
    bool insertLast(int value) {
        if(r==-1){
            r=0;f=0;
            dq[r] = value;
            return true;
        }
        else{
            if(isFull()) return false;
            else{
                r = (r+1)%size;
                dq[r] = value;
            }
            return true;
        }
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        else{
           if(r==f){
               r=-1; f=-1;
               return true;
           } 
           f = (f+1)%size;
        }
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        else{
            if(r==f){
                r=-1;f=-1;
                return true;
            }
            if(r==0) r= size-1;
            else r-=1;
        }
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return dq[f];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return dq[r];
    }
    
    bool isEmpty() {
        return (f == -1 && r == -1);
    }
    
    bool isFull() {
        return ((r+1)%size == f);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */