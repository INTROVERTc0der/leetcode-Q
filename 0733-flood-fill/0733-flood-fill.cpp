class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> pq;
        //priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({sr,sc});
        int target=image[sr][sc];
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        visited[sr][sc]=true;
        while(!pq.empty()){
            auto top=pq.front();
            pq.pop();
            int row=top.first;
            int col=top.second;
            int dx[]={0,-1,0,+1};
            int dy[]={-1,0,+1,0};
            image[row][col]=color;
            for(int i=0;i<4;i++){
                int newx=row+dx[i];
                int newy=col+dy[i];
                
                if(newx<=image.size()-1 && newy<=image[0].size()-1 && newx>=0&& newy>=0 && image[newx][newy]==target && visited[newx][newy]==false){
                    visited[newx][newy]=true;
                    pq.push({newx,newy});
                }
            }
        }
        return image;
    }
};