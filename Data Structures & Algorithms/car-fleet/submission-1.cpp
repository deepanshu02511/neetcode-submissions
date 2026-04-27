class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double,int>> time;
        for(int i=0;i<speed.size();i++)
        {
            time.push_back({ 1.0 * (target - position[i]) / speed[i], position[i] });
        }
        sort(time.begin(), time.end(), [](const pair<double,int>& a, const pair<double,int>& b) {
            return a.second < b.second;
        });
        int ans=1;
        stack<double> st;
        st.push(time[time.size()-1].first);
        int i=time.size()-2;
        while(i>=0)
        {
            cout<<st.top()<<"hi "<<time[i].first<<endl;
            if(st.top()>=time[i].first)
            {
                i--;
            }
            else
            {
                ans++;
                st.pop();
                st.push(time[i].first);
            }
        }
        return ans;
    }
};
