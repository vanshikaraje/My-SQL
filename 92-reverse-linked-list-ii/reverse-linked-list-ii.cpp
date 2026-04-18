class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == NULL || left == right) return head;

        ListNode* curr = head;
        ListNode* prev = NULL;

        // Step 1: move to left
        for(int i = 1; i < left; i++) {
            prev = curr;
            curr = curr->next;
        }

        // pointers for reconnection
        ListNode* connection = prev; // node before left
        ListNode* tail = curr;       // start of reverse

        // Step 2: reverse (right - left + 1 nodes)
        for(int i = 0; i < right - left + 1; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: reconnect

        // connect left part
        if(connection != NULL) {
            connection->next = prev;
        } else {
            head = prev; // when left = 1
        }

        // connect right part
        tail->next = curr;

        return head;
    }
};