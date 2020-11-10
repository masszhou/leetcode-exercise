// summary
// 1. do add like bit operation with string or linked list, since the results need to be unlimited by system.

#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* digit_head = new ListNode();
    ListNode* digit_curr = digit_head;
    int carry = 0;
    int mod = 0;
    // calculate the one before last overlapped element
    while (true) {
        mod = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        digit_curr->val = mod;

        if (l1->next != nullptr && l2->next != nullptr){
            digit_curr->next = new ListNode();
            digit_curr = digit_curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }else{
            digit_curr->next = nullptr;
            break;
        }
    } 

    // calculate non overlaped
    if (l1->next != nullptr){
        do {
            l1 = l1->next;
            mod = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            digit_curr->next = new ListNode(mod);
            digit_curr = digit_curr->next;
        } while (l1->next != nullptr);
    }else if(l2->next !=0){
        do {
            l2 = l2->next;
            mod = (l2->val + carry) % 10;
            carry = (l2->val  + carry) / 10;
            digit_curr->next = new ListNode(mod);
            digit_curr = digit_curr->next;
        } while (l2->next != nullptr);
    }

    if (carry!=0){
        digit_curr->next = new ListNode(carry, nullptr); // assert carray = 1
    }

    return digit_head;
}

void printout(ListNode* n_head){
    ListNode* n_cur = n_head;
    while (n_cur != nullptr){
        std::cout << n_cur->val << ", ";
        n_cur = n_cur->next;
    }
    std::cout << std::endl;
}

void test1(){
    ListNode* n1_head = new ListNode(2);
    ListNode* n1_cur = n1_head;
    n1_cur->next = new ListNode(4);
    n1_cur = n1_cur->next;
    n1_cur->next = new ListNode(3);
    n1_cur = n1_cur->next;

    ListNode* n2_head = new ListNode(5);
    ListNode* n2_cur = n2_head;
    n2_cur->next = new ListNode(6);
    n2_cur = n2_cur->next;
    n2_cur->next = new ListNode(4);
    n2_cur = n2_cur->next;

    printout(n1_head);
    printout(n2_head);

    ListNode* res_head = addTwoNumbers(n1_head, n2_head);
    printout(res_head);
}

void test2(){
    ListNode* n1_head = new ListNode(9);
    ListNode* n1_cur = n1_head;
    for (int i = 0; i < 8; i++){
        n1_cur->next = new ListNode(9);
        n1_cur = n1_cur->next;
    }

    ListNode* n2_head = new ListNode(9);
    ListNode* n2_cur = n2_head;
    for (int i = 0; i < 5; i++){
        n2_cur->next = new ListNode(9);
        n2_cur = n2_cur->next;
    }

    printout(n1_head);
    printout(n2_head);

    ListNode* res_head = addTwoNumbers(n1_head, n2_head);
    printout(res_head);
}

int main(int argv, char* argc[])
{
    test1();
    test2();
}