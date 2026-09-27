/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while (t1 != NULL && t2 != NULL) {
            if (t1->val <= t2->val) {
                ListNode* temp = new ListNode(t1->val);
                curr->next = temp;
                curr = curr->next;
                t1 = t1->next;
            } else {
                ListNode* temp2 = new ListNode(t2->val);
                curr->next = temp2;
                curr = curr->next;
                t2 = t2->next;
            }
        }
        while (t1 != NULL) {
            ListNode* temp = new ListNode(t1->val);
            curr->next = temp;
            curr = curr->next;
            t1 = t1->next;
        }
        while (t2 != NULL) {
            ListNode* temp2 = new ListNode(t2->val);
            curr->next = temp2;
            curr = curr->next;
            t2 = t2->next;
        }
        return dummy->next;
    }
};