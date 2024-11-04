class Solution {
public:
    string compressedString(string word) {
        string comp="";
        int i=1;
        char last=word[0];
        int count=1;
        while(i<word.size()){
            if(last==word[i] && count<8){
                count++;
            }
            else if(last==word[i] && count==8){
                count++;
                comp+=to_string(count);
                comp+=last;
                count=0;
            }
            else if(last!=word[i]){
                if(count>0){
                    comp+=to_string(count);
                    comp+=last;
                }
                count=1;
                last=word[i];
            }
            i++;
        }
        //last one to add
                if(count>0){
                    comp+=to_string(count);
                    comp+=last;
                }
        return comp;
    }
};