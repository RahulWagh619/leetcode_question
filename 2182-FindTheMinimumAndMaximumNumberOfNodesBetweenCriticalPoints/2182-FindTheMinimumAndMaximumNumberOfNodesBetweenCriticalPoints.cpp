// Last updated: 8/13/2025, 3:33:54 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
int getlength(ListNode*head){
    int count=0;
    ListNode*temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans;
        vector<int>cp;
        vector<int>def={-1,-1};
        if(head==NULL)return def;
        int len=getlength(head);
        ListNode*prev=head;
        ListNode*curr=head->next;
        if(curr==NULL)return def;
        ListNode*forward=head->next->next;
        if(forward==NULL)return def;
        int i=1;
        while(forward!=NULL){
            if(curr->val>forward->val && curr->val>prev->val){
                cp.push_back(i);
            }
            if(curr->val<forward->val && curr->val<prev->val){
                cp.push_back(i);
            }
            prev=prev->next;
            curr=curr->next;
            forward=forward->next;
            i++;
        }
        if(cp.size()==0||cp.size()==1)return def;
        int mini=INT_MAX;
        int maxi=cp[cp.size()-1]-cp[0];
       for(int i=0;i<cp.size()-1;i++){
        int dis=cp[i+1]-cp[i];
        mini=min(mini,dis);
       }
       ans.push_back(mini);
       ans.push_back(maxi);
        return ans;    
    }
};