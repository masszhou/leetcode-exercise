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
    while (l1->next != nullptr && l2->next != nullptr){
        mod = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val) / 10;

        digit_curr->val = mod;
        ListNode* next_digit = new ListNode();
        digit_curr->next = next_digit;
        digit_curr = next_digit;
        l1 = l1->next;
        l2 = l2->next;
    }
    // calculate the last overlapped element
    mod = (l1->val + l2->val + carry) % 10;
    carry = (l1->val + l2->val) / 10;
    digit_curr->val = mod;
    digit_curr->next = new ListNode();
    digit_curr = digit_curr->next;

    // calculate non overlaped
    if (l1->next !=0){
        while (l1->next !=0 ){
            mod = (l1->val + carry) % 10;
            carry = (l1->val) / 10;
            digit_curr->val = mod;
            ListNode* next_digit = new ListNode();
            digit_curr->next = next_digit;
            digit_curr = next_digit;
            l1 = l1->next;
        }
    }else if(l2->next !=0){
        while (l2->next !=0 ){
            mod = (l2->val + carry) % 10;
            carry = (l2->val) / 10;
            digit_curr->val = mod;
            ListNode* next_digit = new ListNode();
            digit_curr->next = next_digit;
            digit_curr = next_digit;
            l2 = l2->next;
        }
    }
    // last digit
    if (carry!=0){
        digit_curr->next = new ListNode(carry, nullptr); // assert carray = 1
    }

    return digit_head;
}

int main(int argv, char* argc[])
{
    ListNode* n1_head = new ListNode(9);
    ListNode* n1_cur = n1_head;
    for (int i=0; i<10; i++){
        n1_cur->next = new ListNode(9);
        n1_cur = n1_cur->next;
    }

    ListNode* n2_head = new ListNode(9);
    ListNode* n2_cur = n2_head;
    for (int i=0; i<4; i++){
        n2_cur->next = new ListNode(9);
        n2_cur = n2_cur->next;
    }

    n1_cur = n1_head;
    while (n1_cur != nullptr){
        std::cout << n1_cur->val << ", ";
        n1_cur = n1_cur->next;
    }
    std::cout << std::endl;

    n2_cur = n2_head;
    while (n2_cur != nullptr){
        std::cout << n2_cur->val << ", ";
        n2_cur = n2_cur->next;
    }
    std::cout << std::endl;

    ListNode* res_head = addTwoNumbers(n1_head, n2_head);
    ListNode* res_cur = res_head;
    while (res_cur != nullptr){
        std::cout << res_cur->val << ", ";
        res_cur = res_cur->next;
    }
    std::cout << std::endl;
}