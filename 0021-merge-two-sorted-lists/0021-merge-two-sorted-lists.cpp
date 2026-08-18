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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* ans = new ListNode(500);
        ListNode* temp = ans;
        while(a != NULL && b!=NULL){
            
            if(a->val <= b->val){
                temp->next = a;
                a = a->next;
            }
            else{
                temp->next = b;
                b = b->next;
            }
            
            temp = temp->next;
        } 
        if(a==NULL){
              temp->next = b;
            } 
            else if(b==NULL){
                temp->next = a;
            } 
        return ans->next;
    }
};