class Solution {
    List<String> answer = new ArrayList<>();
    
    public void solve(String ans, String target, int index, boolean flag) {
        // Base case
        if (ans.length() == target.length() && ans.charAt(ans.length() - 1) == target.charAt(target.length() - 1)) 
            return;
        
        // If flag is true
        if (flag) {
            ans += "a";
            if (ans.charAt(index) == target.charAt(index)) {
                answer.add(ans);
                solve(ans, target, index + 1, flag);
            } else {
                answer.add(ans);
                solve(ans, target, index, false);
            }
        } else {
            // Create new string with incremented character
            ans = ans.substring(0, index) + (char)(ans.charAt(index) + 1);
            
            if (ans.charAt(index) == target.charAt(index)) {
                answer.add(ans);
                solve(ans, target, index + 1, true);
            } else {
                answer.add(ans);
                solve(ans, target, index, flag);
            }
        }
    }
    
    public List<String> stringSequence(String target) {
        solve("", target, 0, true);
        return answer;
    }
}
