class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int target=image[sr][sc];
        vector<vector<int>>visited(image.size(),vector<int>(image[0].size(),0));
        visited[sr][sc]=1;
        while(!q.empty()){
            auto[tr,tc] = q.front();
            q.pop();
            vector<int> x={0,1,0,-1};
            vector<int> y={1,0,-1,0};
            image[tr][tc]=color;
            for(int i=0;i<4;i++){
                int newx = tr + x[i];
                int newy = tc + y[i];
                if(newx>=0 && newx<image.size() && newy>=0 && newy<image[0].size() && image[newx][newy]==target && visited[newx][newy]==0){
                    visited[newx][newy]=1;
                    q.push({newx,newy});
                }
            }
        }
        return image;
    }
};