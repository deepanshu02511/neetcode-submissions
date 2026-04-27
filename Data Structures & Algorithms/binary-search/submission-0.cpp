class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        int mid=(j+i)/2;
        while(j>=i)
        {
            if(nums[mid]==target){return mid;}
            else if(nums[mid]>target)
            {
                j=mid-1;
            }
            else{i=mid+1;}
            mid=(j+i)/2;
        }
        return -1;
    }
};
