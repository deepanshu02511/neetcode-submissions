class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> a,b;
        int ll=0,rl=height.size()-1;
        for(int i=0;i<height.size();i++)
        {
            if(height[ll]<height[i]){a.push_back(ll);ll=i;}
            else{a.push_back(ll);}
            if(height[rl]<height[height.size()-1-i]){b.push_back(rl);rl=height.size()-1-i;}
            else{
                
                b.push_back(rl);
            }
        }
        reverse(b.begin(),b.end());
        int ans=0;
        for(int i=0;i<a.size();i++)
        {
            int aa=min(height[a[i]],height[b[i]])-height[i];
            if(aa>0){ans+=aa;}
        }
        return ans;
    }
};
