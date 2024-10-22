class Solution {
public:
    void solve(string ans, string target , int index , bool flag , vector<string>& answer){
        //base case
        if(ans.size()==target.size() && ans[ans.size()-1]==target[target.size()-1])return ;

        //if flag is true
        //need to add a new character 
        if(flag){
            ans.push_back('a');
            if(ans[index]==target[index]){
                answer.push_back(ans);
                solve(ans, target,index+1,flag,answer);
            }
            else{
                answer.push_back(ans);
                solve(ans, target,index,false,answer);
            }
        }
        else{
            ans[index]=ans[index]+1;
            if(ans[index]==target[index]){
                answer.push_back(ans);
                solve(ans,target,index+1,true,answer);
            }
            else{
                answer.push_back(ans);
                solve(ans,target,index,flag,answer);
            }
        }

    }
    vector<string> stringSequence(string target) {
        vector<string>answer;
        solve("",target,0,true,answer);
        return answer;
    }
};