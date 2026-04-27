class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,bool> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i]-1)!=mp.end())
            {
                mp[nums[i]]=0;
            }
            else
            {
                mp[nums[i]]=1;
                if(mp.find(nums[i]+1)!=mp.end())
                {
                    mp[nums[i]+1]=0;
                }
            }
        }
        int len=0;
        for(auto i : mp)
        {   int cnt=1;
            if(i.second==1)
            {   
                for(int j=i.first;;j++)
                {
                    if(mp.find(j+1)!=mp.end())
                    {
                        cnt++;
                    }
                    else{
                        break;
                    }
                }
                
            }
            len=max(cnt,len);
        }
        return len;
    }
};
