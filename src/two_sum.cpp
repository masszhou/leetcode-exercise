//
// Created by zzhou on 03.11.20.
// summary:
// 1. use hashtable as buffer to reduce search complexity to O(n)
// 2. hash key is a nature set
// 3. use complementary set to reduce search space
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

int main(int argc, char* argv[]){

}
