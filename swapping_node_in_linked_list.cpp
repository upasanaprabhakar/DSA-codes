class Solution {
    public:
        ListNode* swapNodes(ListNode* head, int k) {
            ListNode* a=NULL;
            ListNode* b=NULL;
            int n=0;
            ListNode* temp= head;
            while(temp){
                temp=temp->next;
                n++;
            }
            temp = head;
            for(int i=1;i<=n;i++){
                if(i==k) a=temp;
                if(i==(n-k+1)) b=temp;
                temp = temp->next;
            }
            int x=a->val;
            a->val=b->val;
            b->val=x;
            return head;
        }
    };