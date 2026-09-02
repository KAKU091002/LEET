class Solution {
private:
void dfs(int row,int col,int newcolor,vector<vector<int>>& image,vector<vector<int>>& ans,int delrow[],int delcol[],int inicolor){
    int n=image.size();
    int m=image[0].size();

    ans[row][col]=newcolor;
    for(int i=0;i<4;i++)
    {
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&image[nrow][ncol]==inicolor&&ans[nrow][ncol]!=newcolor)
        {
            dfs(nrow,ncol,newcolor,image,ans,delrow,delcol,inicolor);
        }
    }

}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor=image[sr][sc];
        int newcolor=color;
        vector<vector<int>> ans=image;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};

        dfs(sr,sc,newcolor,image,ans,delrow,delcol,inicolor);
        return ans;
    }
};