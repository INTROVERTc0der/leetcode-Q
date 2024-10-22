class Solution {
public:
        void solve(int first , int last , string& s,int& k,vector<int>& hash,int& count,bool flag){
        //base case 
        if(last==s.size())return;

        //check for the condition 
        if(flag) hash[s[last]-'a']++;
        if(hash[s[last]-'a']==k){
            count+=(s.size()-last);
            hash[s[first]-'a']--;
            first++;
            solve(first,last,s,k,hash,count,false);
        }
        else{
            solve(first,last+1,s,k,hash,count,true);
        }
    }
    int numberOfSubstrings(string s, int k) {
        vector<int> hash (26,0);
        int count=0;
        solve(0,0,s,k,hash,count,true);
        return count;
    }
};