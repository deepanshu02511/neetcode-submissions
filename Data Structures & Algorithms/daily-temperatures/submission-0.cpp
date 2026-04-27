class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans;
        for(int i=temperatures.size()-1;i>=0;i--)
        {
            int cnt=0;
            bool aa=1;
            while(aa)
            {
                if(st.empty()){
                    ans.push_back(0);
                    cnt=0;
                    st.push(temperatures[i]);
                    aa=0;
                }
                else{
                int a=st.top();
                cnt++;
                if(a<=temperatures[i])
                {
                    st.pop();
                }
                else
                {
                    ans.push_back(cnt);
                    while(cnt--){
                    st.push(temperatures[i]);}
                    aa=0;
                }
                }
            }

        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};
