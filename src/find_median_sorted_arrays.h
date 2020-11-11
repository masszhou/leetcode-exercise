//
// Created by zzhou on 11.11.20.
//

#ifndef LEETCODE_FIND_MEDIAN_SORTED_ARRAYS_H
#define LEETCODE_FIND_MEDIAN_SORTED_ARRAYS_H
#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;

namespace leetcode{

// summary:
// 1. ideal should find the split boundary without merge two list, if the list is huge
// 2. here I only used a lazy implementation, merged lists then sort.
class FindMedianSortedArrays
{
public:
    static double solve_lazy(vector<int>& nums1, vector<int>& nums2){
        double res;
        vector<int> num_all;
        num_all.reserve(nums1.size() + nums2.size());
        num_all.insert(num_all.end(), nums1.begin(), nums1.end());
        num_all.insert(num_all.end(), nums2.begin(), nums2.end());
        sort(num_all.begin(), num_all.end());

        if (num_all.empty()){
            res = 0.0;
        }else if (num_all.size() % 2 == 0){
            res = static_cast<double>(num_all[num_all.size()/2]) + static_cast<double>(num_all[num_all.size()/2-1]);
            res /= 2.0;
        }else{
            res = num_all[(num_all.size()-1)/2];
        }
        return res;
    }

    static void test(){
        std::cout << ">>>> FindMedianSortedArrays:" << std::endl;
        vector<int> n1 = {1, 2, 5, 6};
        FindMedianSortedArrays::printout(n1);
        vector<int> n2 = {3, 4};
        FindMedianSortedArrays::printout(n2);

        double res = FindMedianSortedArrays::solve_lazy(n1, n2);
        std::cout << "res = " << res << std::endl;
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

#endif //LEETCODE_FIND_MEDIAN_SORTED_ARRAYS_H
