/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //base case
        if(head==NULL) return true;

        //create a visited map 
        unordered_map<ListNode* ,bool> visited;
        ListNode* temp=head;
        int index=0;
        
        while(temp!=NULL){
            if(visited.find(temp)!=visited.end()){
                cout<<temp->val<<endl;
                return true;

            }
            else{
                visited[temp]=true;
                temp=temp->next;
            }
        }
        return false;
    }
};