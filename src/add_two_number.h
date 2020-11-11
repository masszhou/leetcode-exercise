//
// Created by zzhou on 11.11.20.
//

#ifndef LEETCODE_ADD_TWO_NUMBER_H
#define LEETCODE_ADD_TWO_NUMBER_H
#include <vector>
#include <iostream>

using std::vector;

namespace leetcode{

// summary
// 1. do add like bit operation with string or linked list, since the results need to be unlimited by system.
class AddTwoNumbers
{
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    static ListNode* solve(ListNode* l1, ListNode* l2){
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

    static void test(){
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

        std::cout << ">>>> AddTwoNumbers: (units, tens, hundreds)" << std::endl;
        printout(n1_head);
        std::cout << "+" << std::endl;
        printout(n2_head);
        std::cout << "=" << std::endl;

        ListNode* res_head = AddTwoNumbers::solve(n1_head, n2_head);
        AddTwoNumbers::printout(res_head);
    }

    static void printout(ListNode* n_head){
        ListNode* n_cur = n_head;
        while (n_cur != nullptr){
            std::cout << n_cur->val << ", ";
            n_cur = n_cur->next;
        }
        std::cout << std::endl;
    }
};

} // leetcode

#endif //LEETCODE_ADD_TWO_NUMBER_H
