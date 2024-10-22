/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, unordered_map<int,long long>& hash ,int level){
        //base case
        if(root==NULL)return;
        //if(root->left==NULL && root->right==NULL)return;

        hash[level]+=root->val;
        solve(root->left,hash,level+1);
        solve(root->right,hash,level+1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        unordered_map<int,long long>hash;
        solve(root,hash,1);
        
        priority_queue<long long,vector<long long>,greater<long long>> q;
        for(auto p : hash){
            cout<<"level : "<<p.first<<" sum : "<<p.second<<endl;
            if(q.size()<k){
                q.push(p.second);
            }
            else{
                if(p.second>q.top()){
                    q.pop();
                    q.push(p.second);
                }
            }
        }
        if(q.size()<k)return -1;
        return q.top();
    }
};