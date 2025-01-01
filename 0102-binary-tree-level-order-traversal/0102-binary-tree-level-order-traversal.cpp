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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>>ans;
        vector<int>subans;
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            if(t==NULL){
                ans.push_back(subans);
                subans.clear();
                if(q.empty()){
                    break;
                }
                else{
                    q.push(NULL);
                }
            }
            else{
                subans.push_back(t->val);
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
        }
        return ans;
    }
};