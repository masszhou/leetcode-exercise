//
// Created by zzhou on 11.11.20.
//


#include <vector>
#include <iostream>

using std::vector;

namespace leetcode{

// summary:
// 1. fundamental DP practice, bottom to up
class HouseRobber
{
public:
    static int solve(vector<int>& nums){
        if (nums.empty())
            return 0;
        else if (nums.size() == 1){
            return nums[0];
        }

        vector<int> buffer;
        buffer.emplace_back(nums[0]);
        if (nums[0] < nums[1])
            buffer.emplace_back(nums[1]);
        else
            buffer.emplace_back(nums[0]);

        for (int i=2; i<nums.size(); i++){
            if ((nums[i] + buffer[i-2])>buffer[i-1]){
                buffer.emplace_back(nums[i] + buffer[i-2]);
            }else{
                buffer.emplace_back(buffer[i-1]);
            }
        }
        return buffer.back();
    }

    static void test(){
        vector<int> nums = {4, 9, 7, 1};
        int val = leetcode::HouseRobber::solve(nums);
        std::cout << ">>>> HouseRobber:" << std::endl;
        std::cout << "{4, 9, 7, 1}, output = " << val << std::endl;
    }
};

} // leetcode

int main(int argc, char* argv[]){

    leetcode::HouseRobber::test();

    return 0;
}