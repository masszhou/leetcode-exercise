//
// Created by zzhou on 11.11.20.
//

#include "two_sum.h"
#include "add_two_number.h"
#include "longest_substring_without_repeating_characters.h"
#include "find_median_sorted_arrays.h"
#include "longest_palindromic_substring.h"
#include "zigzag_conversion.h"
#include "reverse_integer.h"
#include "string_to_integer.h"

#include "house_robber.h"

int main(int argc, char* argv[]){

    leetcode::TwoSum::test();
    leetcode::AddTwoNumbers::test();
    leetcode::LongestSubStringWithoutRepeatingCharacters::test();
    leetcode::FindMedianSortedArrays::test();
    leetcode::LongestPalidromicSubString::test();
    leetcode::ZigZagConversion::test();
    leetcode::ReverseInteger::test();
    leetcode::StringToInteger::test();

    leetcode::HouseRobber::test();

    return 0;
}