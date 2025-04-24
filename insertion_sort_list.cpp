class Solution {
    public:
        ListNode* insertionSortList(ListNode* head) {
            ListNode* dummy=new ListNode(-1);
            ListNode* temp=dummy;
            ListNode* curr=head;
            ListNode* nex=NULL;
            while(curr){
               nex=curr->next;
               temp=dummy;
               while(temp->next && temp->next->val<curr->val)
                temp=temp->next;
                curr->next=temp->next;
                temp->next=curr;
                curr=nex;
               
    
               
            }
            return dummy->next;
        }
    };