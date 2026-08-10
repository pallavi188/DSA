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
    ListNode* reverseList(ListNode* head) {
      ListNode* temp = new ListNode();
      ListNode* prev = new ListNode();
      ListNode* front = new ListNode();
      temp = head;
      prev = NULL;
      front = NULL;
      while(temp != NULL){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
      }
      return prev;
    }
};