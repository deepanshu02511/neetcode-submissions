class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> a;
        int mr=prices[prices.size()-1];
        for(int i=prices.size()-1;i>=0;i--)
        {
            a.push_back(mr);
            mr=max(prices[i],mr);
        }
        reverse(a.begin(),a.end());
        int ans=0;
        for(int i=0;i<a.size();i++)
        {   cout<<a[i]<<endl;
            ans=max(ans,a[i]-prices[i]);
        }
        return ans;
    }
};
