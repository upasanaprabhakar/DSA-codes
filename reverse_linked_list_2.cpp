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
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            if(left==right) return head;
            ListNode* a=NULL;
            ListNode* b=NULL;
            ListNode* c=NULL;
            ListNode* d=NULL;
            ListNode* temp=head;
            int n=1;
            while(temp){
                if(n==left-1) a=temp;
                if(n==left) b=temp;
                if(n==right) c=temp;
                if(n==right+1) d=temp;
                temp=temp->next;
                n++;
            }
            if(a) a->next=NULL;
            c->next=NULL;
            c=reverseList(b);
            if(a) a->next=c;
            b->next=d;
            if(a) return head;
            return c;
        }
    };