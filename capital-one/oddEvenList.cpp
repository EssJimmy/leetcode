#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;

        ListNode oddHead(0);
        ListNode evenHead(0);
        ListNode* odd = &oddHead;
        ListNode* even = &evenHead;
        
        int isOdd = 0;
        while(head){
            if(!(isOdd % 2)){
                odd->next = head;
                odd = odd->next;
            }
            else {
                even->next = head;
                even = even->next;
            }

            head = head->next;
            isOdd++;
        }

        odd->next = evenHead.next;
        even->next = nullptr;
        return oddHead.next;
    }
};