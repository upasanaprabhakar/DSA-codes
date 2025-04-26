class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* prev=NULL;
            ListNode* curr=head;
            ListNode* Next=NULL;
            while(curr!=NULL){
                Next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=Next;
            }
            return prev;
        }
        bool isPalindrome(ListNode* head) {
            ListNode* slow=head;
            ListNode* fast=head;
            while(fast->next && fast->next->next){
                slow=slow->next;
                fast=fast->next->next;
            }
            ListNode* newhead= reverseList(slow->next);
            ListNode* a= head;
            ListNode* b= newhead;
            while(b){
                if(a->val!=b->val) return false;
                a=a->next;
                b=b->next;
            }
            return true;
        }
    };