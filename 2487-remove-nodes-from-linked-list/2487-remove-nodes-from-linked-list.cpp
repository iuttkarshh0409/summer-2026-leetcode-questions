class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;

        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);

        int maxVal = head->val;
        ListNode* curr = head;

        while (curr->next) {
            if (curr->next->val < maxVal) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
                maxVal = curr->val;
            }
        }

        return reverse(head);
    }
};