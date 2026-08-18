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
private: 
    ListNode* merge(ListNode* a, ListNode* b){
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
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        if(lists.size()==1) return lists[0];
        ListNode* head3;
        while(lists.size()!=1){
            ListNode* head1 = lists[0];
            lists.erase(lists.begin());
            ListNode* head2 = lists[0];
            lists.erase(lists.begin());

            head3 = merge(head1, head2);
            lists.push_back(head3);
        }
        return head3;
    }
};