#include<iostream>
using namespace std;



 struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
      
        ListNode* fast = head, * slow = head;
        while (fast && fast->next)
        //&&的逻辑短路效应
        //&&左边为假，右边不会执行：防止next已经是nullptr，next->next指向野指针
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};