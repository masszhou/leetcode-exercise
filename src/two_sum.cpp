//
// Created by zzhou on 03.11.20.
//
#include <map>
#include <vector>

using namespace std;

/// One Pass with HashMap
vector<int> twoSum(vector<int>& nums, int target){
        map<int, int> buffer;
        for(int i=0; i<nums.size(); i++){
            if (buffer.count(target - nums[i])){
                return {i , buffer[target - nums[i]]};
            }
            buffer[nums[i]] = i;
        }
        return {};
}

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res = new ListNode();
    while (l1->next != nullptr && l2->next != nullptr)
    {
        /* code */
    }

}

int main(int argc, char* argv[]){

}
