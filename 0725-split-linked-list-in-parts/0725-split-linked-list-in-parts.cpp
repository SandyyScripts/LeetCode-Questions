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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int length = 0;
        ListNode* curr=head;
        while(curr){
            curr=curr->next;
            length++;
        }
        int base_len=length/k,remainder=length%k;
        curr=head;
        for(int i=0;i<k;i++){
            ans.push_back(curr);
            int limit=base_len-1;
            if(remainder>0) limit++;
            for(int j=0;j<limit;j++){
                curr=curr->next;
            }
            if(remainder>0) remainder--;
            if(curr){
                ListNode* x=curr->next;
                curr->next=NULL;
                curr=x;
            }
        }
        return ans;
    }
};