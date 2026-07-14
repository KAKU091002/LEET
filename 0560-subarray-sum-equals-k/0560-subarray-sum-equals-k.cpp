class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ps=0;
        int count=0; 
        int remove;
        unordered_map<int,int>X;
        X[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            ps+=nums[i];
            remove=ps-k;
            count+=X[remove];
            X[ps]+=1;
        }
        return count;
    }
};