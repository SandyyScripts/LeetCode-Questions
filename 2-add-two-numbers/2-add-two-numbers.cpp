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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* dummy_head=new ListNode(0);
        ListNode* temp=dummy_head;
        int carry=0;
        while(l1!=NULL || l2!=NULL){
            int l1_v=(l1!=NULL)? l1->val:0;
            int l2_v=(l2!=NULL)? l2->val:0;
            
            int curr_sum=l1_v+l2_v+carry;
            carry=curr_sum/10;
            int last_digit=curr_sum%10;
            ListNode* new_node=new ListNode(last_digit);
            temp->next=new_node;
            
            if(l1!=NULL){
                l1=l1->next;
            }
            if(l2!=NULL){
                l2=l2->next;
            }
            temp=temp->next;
        }
        if(carry>0){
            ListNode* new_node=new ListNode(carry);
            temp->next=new_node;
            temp=temp->next;
        }
        return dummy_head->next;
    }
};