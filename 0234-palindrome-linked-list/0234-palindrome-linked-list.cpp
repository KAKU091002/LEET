class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Find middle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != NULL) {
            slow = slow->next;
        }

        // Reverse second half
        ListNode* NewHead = reverseLinkedList(slow);

        ListNode* first = head;
        ListNode* second = NewHead;

        // Compare
        while (second != NULL) {
            if (first->val != second->val) {
                reverseLinkedList(NewHead);
                return false;
            }

            first = first->next;
            second = second->next;
        }

        // Restore list
        reverseLinkedList(NewHead);

        return true;
    }
};