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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = new ListNode;
        ListNode* slow = new ListNode;
        ListNode* temp = new ListNode;
        temp = head;
        slow = head;
        fast = head;
        int cnt =0;
        while(temp != NULL){
             cnt++;
             temp = temp->next;
        }
        if(cnt%2 != 0){
            //odd length
            while(fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }

        }else{
            while(fast != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        return slow;
    }
};