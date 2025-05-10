class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* head1 = head->next;
        while (a != NULL && b != NULL) {
            if (b->next == NULL)
                break;
            if (b == NULL)
                break;
            a->next = b->next;
            a = a->next;
            b->next = a->next;
            b = b->next;
        }
        a->next = head1;
        return head;
    }
};