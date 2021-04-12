//
// Created by zzhou on 11.11.20.
//

#include <vector>
#include <map>
#include <iostream>

using std::vector;
using std::map;

namespace leetcode{

// summary:
// 1. use hashtable as buffer to reduce search complexity to O(n)
// 2. hash key is a nature set
// 3. use complementary set to reduce search space
class TwoSum
{
public:
    static vector<int> solve(vector<int>& nums, int target){
        map<int, int> buffer;
        for(int i=0; i<nums.size(); i++){
            if (buffer.count(target - nums[i])){
                return {i , buffer[target - nums[i]]};
            }
            buffer[nums[i]] = i;
        }
        return {};
    }

    static void test(){
        vector<int >nums = {2,7,11,15};
        int target = 9;
        vector<int> res = TwoSum::solve(nums, target);
        std::cout << ">>>> TwoSum:" << std::endl;
        std::cout << "input: {2,7,11,15} with target 9, output = " << std::endl;
        TwoSum::printout(res);
    }

    static void printout(vector<int>& n)
    {
        for (auto each : n){
            std::cout << each << ",";
        }
        std::cout << std::endl;
    }
};

} // leetcode

int main(int argc, char* argv[]){

    leetcode::TwoSum::test();

    return 0;
}