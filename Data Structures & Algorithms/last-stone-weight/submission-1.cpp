class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> minHeap;
        for(auto i : stones){minHeap.push(i);}
        while(minHeap.size()>1){
        int a=minHeap.top();
        minHeap.pop();
        int b=minHeap.top();
        minHeap.pop();
        if(a!=b){
            minHeap.push(a-b);
        }
        }
        if(!minHeap.empty()){
        int a=minHeap.top();
        return a;}
        return 0;
    }
};
