class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>ans;
        vector<int>a;

        dfs(0,n-1,a,graph,ans);

        return ans;
    }

    void dfs(int src,int dst,vector<int>a,vector<vector<int>>&graph,vector<vector<int>>& ans)
    {
        a.push_back(src);

        if(src==dst)
        {ans.push_back(a);}
        else
        {for(auto &neigh:graph[src])
        {dfs(neigh,dst,a,graph,ans);}}
        a.pop_back();
    }
};