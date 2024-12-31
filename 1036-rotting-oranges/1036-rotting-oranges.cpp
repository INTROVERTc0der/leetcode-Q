class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }
            }
        }
        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};
        int maxtime=0;
        while(!q.empty()){
            auto [t,cell]=q.front();
            int r=cell.first;
            int c=cell.second;
            q.pop();
            for(int i=0;i<4;i++){
                int newx=r+dx[i];
                int newy=c+dy[i];
                if(newx>=0 && newx<grid.size() && newy>=0 && newy<grid[0].size() && grid[newx][newy]==1){
                    grid[newx][newy]=2;
                    maxtime=max(maxtime,t+1);
                    q.push({t+1,{newx,newy}});
                }
            }
        }
                for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
    
        return maxtime;
    }
};