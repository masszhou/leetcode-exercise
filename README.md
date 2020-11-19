# my leetcode summary

# 1. Two Sum
* use hash table as buffer to reduce search complexity to O(n)
* hash key is a nature set, exclude duplicate elements
* use complementary set to reduce search space

# 2. Add Two Number
* do add alike bit/char operation with string or linked list, since the results need to be unlimited by system.
 
# 3. Longest Substring Without Repeating Characters
* maintain a non-repeat buffer, which support hash index
* sliding window search, a slightly similar philosophy with simple DP

# 4. Media of Two Sorted Arrays
* ideal should find the split boundary without merge two list, if the list is huge
* **[shortcut]** here I only used a lazy implementation, merged lists then sort.

# 5. Longest Palindromic Substring
* practice DP with table, bottom to up

# 6. ZigZag Conversion
* zigzag
  
# 7. Reverse Integer
* be careful for corner case, signed integer overflow when: -2147483648 * -1

# 8. String to Integer (atoi)
* [reference solution](https://leetcode.com/problems/string-to-integer-atoi/discuss/4642/8ms-C%2B%2B-solution-easy-to-understand)
* **[shortcut]** use std.find_first_not_of() to get valid sub string
* use longlong as buffer
* check int32 range
* char zero = '0'; // ascii decimal = 48
* char nine = '9'; // ascii decimal = 57