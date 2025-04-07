class Solution {
    public:
    ListNode* reverse(ListNode*head){
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*nex=NULL;
        while(curr){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
           
    }
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode*a=NULL;
            ListNode*b=head;
            ListNode*c=head;
            ListNode*d=NULL;
            
            while(c){
                for(int i=1;i<k;i++){
                    if(c==NULL) return head;
                    c=c->next;
                }
            if(c==NULL) return head;
            d=c->next;
            c->next=NULL;
            c=reverse(b);
            if(a==NULL) head=c;
            else a->next=c;
            b->next=d;
            a=b;
            b=d;
            c=b;
            
            }
            return head;
        }
    };