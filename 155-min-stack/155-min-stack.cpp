class MinStack {
private:
    vector<int> ans;
    int minnum;
    void FindMin(){
        int min=INT_MAX;
        for(int i=0;i<ans.size();i++){
            if(min>ans[i]){
                min=ans[i];
            }
        }
        minnum=min;
    }
public:
    MinStack() {
        minnum=INT_MAX; 
    }
    void push(int val) {
        ans.push_back(val);
        if(val<minnum){
            minnum=val;
        }
    }
    
    void pop() {
        int val=ans.back();
        ans.pop_back();
        if(val==minnum){
            FindMin();
        }
    }
    
    int top() {
        return ans.back();
    }
    
    int getMin() {
        return minnum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */