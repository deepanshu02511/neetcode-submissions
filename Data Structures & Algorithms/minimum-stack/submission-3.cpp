class MinStack {
public:
    stack<int> stk;
    stack<int> minstk;
    int mi=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        mi=min(val,mi);
        if(!minstk.empty()){
        minstk.push(mi);}
        else{minstk.push(val);mi=val;}
    }
    
    void pop() {
        int a=stk.top();
        stk.pop();
        minstk.pop();
        if(!minstk.empty())
        {mi=minstk.top();}
            
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
    }
};
