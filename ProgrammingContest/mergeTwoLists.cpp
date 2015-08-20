#include <iostream>
#include <cassert>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    
    Solution() {};
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1 && !l2){
            return NULL;
        }else if(!l1) {
            return l2;
        } else if(!l2){
            return l1;
        }else {
            
            if(l1->val < l2->val){
                ListNode* node = new ListNode(l1->val);
                node->next = mergeTwoLists(l1->next, l2);
                return node;
            }else if(l2->val < l1->val){
                ListNode* node = new ListNode(l2->val);
                node->next = mergeTwoLists(l1, l2->next);
                return node;
            }else {
                ListNode* node = new ListNode(l1->val);
                ListNode* node2 = new ListNode(l2->val);
                node->next = node2;
                node2->next = mergeTwoLists(l1->next, l2->next);
                return node;
            }
        }
    }
    
    
};

int main() {
    
    ListNode node1(1);
    ListNode node2(2);
    node1.next = &node2;

    ListNode node3(3);
    ListNode node4(4);
    node3.next = &node4;
    
    Solution s;
    ListNode* result;
    
    result = s.mergeTwoLists(&node1, &node3);
    
    assert( result->val == 1);
    assert( result->next->val == 2);
    assert( result->next->next->val == 3);
    assert( result->next->next->next->val == 4);
    
    return 0;
}

