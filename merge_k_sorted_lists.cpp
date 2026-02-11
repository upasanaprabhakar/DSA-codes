// Approach 1: Using Linked Lists
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* c = new ListNode(100);
        ListNode* temp = c;
        while (a != NULL && b != NULL) {
            if (a->val <= b->val) {
                temp->next = a;
                a = a->next;
                temp = temp->next;
            } else {
                temp->next = b;
                b = b->next;
                temp = temp->next;
            }
        }
        if (a == NULL)
            temp->next = b;
        else
            temp->next = a;
        return c->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if (arr.size() == 0)
            return NULL;
        while (arr.size() > 1) {
            ListNode* a = arr[0];
            arr.erase(arr.begin());
            ListNode* b = arr[0];
            arr.erase(arr.begin());
            ListNode* c = merge(a, b);
            arr.push_back(c);
        }
        return arr[0];
    }
};

//Approach 2 : Using Min Heap 
class Solution {
public:
    struct Compare{
        bool operator() (ListNode* a , ListNode* b){
            return a->val> b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        //push all list heads
        for(ListNode* list : lists){
            if(list != NULL){
                pq.push(list);
            }
        }

        //create dummy node
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        //process heap
        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if(node->next != NULL){
                pq.push(node->next);
            }
        }
        return dummy->next;
    }
};