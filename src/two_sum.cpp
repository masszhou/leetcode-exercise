//
// Created by zzhou on 03.11.20.
// 核心思想：
// 1. 用 hashtable 做buffer提高检索速度到O(n)
// 2. map的键值即 hashtable hashkey 有不重复元素集合的功能
// 3. 善用补集提高2倍搜索速度
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
