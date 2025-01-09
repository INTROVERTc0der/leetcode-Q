class Solution {
public:
    int solve(vector<int>& heaters,int pos){
        int Min=INT_MAX;
        for(int i=0;i<heaters.size();i++){
            Min=min(Min,abs(pos-heaters[i]));
        }
        return Min;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
         vector<int> near(houses.size()+1);
         for(int i=0;i<houses.size();i++){
            near[i]=solve(heaters,houses[i]);
         }
         int Max=INT_MIN;
         for(int i=0;i<near.size();i++){
            if(near[i]>Max) Max=near[i];
         }
         return Max;
    }
};