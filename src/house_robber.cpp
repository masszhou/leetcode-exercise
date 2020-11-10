// basic DP, bottom to up
#include <vector>
#include <iostream>
using namespace std;


void printout(vector<int>& n)
{
    for (auto each : n){
        std::cout << each << ",";
    }
    std::cout << std::endl;
}

int rob(vector<int>& nums)
{
    if (nums.size() == 0)
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
    printout(buffer);

    return buffer.back();
}

void test()
{
    vector<int> nums = {4, 9, 7, 1};
    int val = rob(nums);
    cout << val << endl;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}