class FrontMiddleBackQueue {
public:
    vector<int> v;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        v.insert(v.begin(),val);
    }
    
    void pushMiddle(int val) {
        int m = v.size()/2;
        v.insert(v.begin()+m,val);
    }
    
    void pushBack(int val) {
        v.push_back(val);
    }
    
    int popFront() {
        if(v.size()==0){
            return -1;
        }
        int c=v[0];
        v.erase(v.begin());
        return c;
    }
    
    int popMiddle() {
        if(v.size()==0){
            return -1;
        }
        int m=(v.size()-1)/2;
        int c=v[m];
        v.erase(v.begin()+m);
        return c;
    }
    
    int popBack() {
        if(v.size()==0){
            return -1;
        }
        int c=v[v.size()-1];
        v.pop_back();
        return c;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */