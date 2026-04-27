class KthLargest {
public:
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kk;
    KthLargest(int k, vector<int>& nums) {
        for(auto i : nums){minHeap.push(i);}
        while(minHeap.size()>k){minHeap.pop();}
        kk=k;
    }
    
    int add(int val) {
        if(minHeap.size()<kk){minHeap.push(val);int a= minHeap.top();
        return a;}
        if(val<=minHeap.top()){return minHeap.top();}
        minHeap.pop();
        minHeap.push(val);
        int a= minHeap.top();
        return a;
    }
};
