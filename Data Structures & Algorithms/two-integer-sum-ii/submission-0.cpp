class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0;i<numbers.size();i++)
        {
            for(int j=0;j<numbers.size() && j!=i;j++)
            {
                if(numbers[i]+numbers[j]==target)
                {
                    vector<int> a={i+1,j+1};
                    sort(a.begin(),a.end());
                    return a;
                }
            }
        }
    }
};
