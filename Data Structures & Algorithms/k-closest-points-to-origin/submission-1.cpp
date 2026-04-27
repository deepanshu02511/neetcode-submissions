class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<int> ans;
        for(auto i : points)
        {
            ans.push_back(i[0]*i[0]+i[1]*i[1]);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<ans.size();i++)
        {
            pq.push({ans[i],i});
        }
        vector<vector<int>> a;
        int i=0;
        while(i<k && !pq.empty())
        {
            a.push_back(points[pq.top().second]);
            pq.pop();
            i++;
        }
        return a;


    }
};
