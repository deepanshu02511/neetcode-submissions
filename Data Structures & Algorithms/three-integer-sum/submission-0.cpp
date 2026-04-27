class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,int> mp;

        for(int x : nums) {
            mp[x]++;
        }

        vector<pair<int,pair<int,int>>> tsum;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                tsum.push_back({nums[i] + nums[j], {nums[i], nums[j]}});
            }
        }

        set<vector<int>> uniqueTriplets;

        for(auto t : tsum) {
            int a = -(t.first);

            if(mp.find(a) != mp.end()) {

                // Check count properly
                int count = mp[a];
                if(a == t.second.first) count--;
                if(a == t.second.second) count--;

                if(count > 0) {
                    vector<int> temp = {a, t.second.first, t.second.second};
                    
                    sort(temp.begin(), temp.end()); // normalize
                    
                    uniqueTriplets.insert(temp); // set removes duplicates
                }
            }
        }

        // Convert set → vector
        vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
        return ans;
    }
};