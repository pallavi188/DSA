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
    bool isPalindrome(ListNode* head) {
       if(!head) return true;
       vector<int>temp;
       ListNode* t1 = head;
       while(t1 != NULL){
          temp.push_back(t1->val);
          t1 = t1->next;
       }
       int n = temp.size();
       int i=0,j=n-1;
       while(i<j){
        if(temp[i] != temp[j])return false;
        else{
            i++;
            j--;
        }
       }
       return true;
    }
};