class Solution {
public:

string centerExpansion(const string& str, int left, int right) {
    while (left >= 0 && right < str.size() && str[left] == str[right]) {
        left--;
        right++;
    }
    // Substring from (left+1) to (right-1), inclusive
    return str.substr(left + 1, right - left - 1);
}

string solve(string& str) {
    string result = "";
    for (int i = 0; i < str.size(); i++) {
        // Odd-length palindrome
        string result1 = centerExpansion(str, i, i);
        // Even-length palindrome
        string result2 = centerExpansion(str, i, i + 1);

        // Update result if a longer palindrome is found
        if (result1.size() > result.size()) {
            result = result1;
        }
        if (result2.size() > result.size()) {
            result = result2;
        }
    }
    return result;
}
// this soln can be done in n2 rather than n3 as done below using DP 



//     bool ispalindrom(string &s,int i,int j){
//         while(j>i){
//             if(s[i]!=s[j]){
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }
//     string longestPalindrome(string s) {
//         string ans;
//         int maxlen=INT_MIN;
//         for(int i=0;i<s.size();i++){
//             for(int j=i;j<s.size();j++){
//                 if(ispalindrom(s,i,j)){
//                     // if(j-i>maxlen){
//                     //     maxlen=j-i;
//                     //     ans=s.substr(i,j-i+1);
//                     // }
//                     string t=s.substr(i,j-i+1);
//                     ans=t.size()>ans.size() ? t:ans;
//                 }
                
//             }
//         }
//         return ans;
//     }
// };


//doing it using DP //apply LCS and take S and reverse of S 

    string longcomsubseqR(string text1,string text2,int index1,int index2){
        if(index1==text1.length()) return "";
        if(index2==text2.length()) return "";
        
        string ans="";
        if(text1[index1]==text2[index2]){
            ans+= text1[index1]+longcomsubseqR(text1,text2,index1+1,index2+1);
        }
        else{
            string a=longcomsubseqR(text1,text2,index1+1,index2);
            string b=longcomsubseqR(text1,text2,index1,index2+1);
            int lengthA=a.size();
            int lengthB=b.size();
            if(lengthA>lengthB) ans=a;
            else ans=b;  
            //ans= 0+max(longcomsubseqR(text1,text2,index1+1,index2),longcomsubseqR(text1,text2,index1,index2+1));
        }

        return ans;
    }


    string longestPalindrome(string s) {
        // int n=s.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;++j){
        //         bool t=solve(dp,s,i,j);
        //     }
        // }
        // return s.substr(start,maxlen);



        // string r=s;
        // reverse(s.begin(),s.end());
    
   
        
        // return longcomsubseqR(s,r,0,0);\\\

        return solve(s);
    }
};