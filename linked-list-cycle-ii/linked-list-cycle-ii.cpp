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
    ListNode *detectCycle(ListNode *head) {
        int length=0;
        ListNode * first=head;
        ListNode * second=head;
        while(second && second->next ){
           first=first->next;
            second=second->next->next;
            if(first==second){
                first=head;
                while(first!=second){
                    first=first->next;
                    second=second->next;
                }
                return second;
            }          
        }
        
        return NULL;
    }
};