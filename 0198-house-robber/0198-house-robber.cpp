class Solution {
public:

        int ftopdown(const vector<int>&nums,int i,vector<int>&dp)
        {
            if(dp[i]!=-1)
            {
                return dp[i];
            }
            if(i==nums.size()||i==nums.size()+1)
            {
                return dp[i]=0;
            }

            int rob=nums[i]+ftopdown(nums,i+2,dp);

            int donotrob=ftopdown(nums,i+1,dp);

            return dp[i]=max(rob,donotrob);

        }
        int rob(vector<int>&nums)
        {
            vector<int >dp(nums.size()+2,-1);
            return ftopdown(nums,0,dp);
        }
    
};