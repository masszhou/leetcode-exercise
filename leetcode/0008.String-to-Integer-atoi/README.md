# 8. String to Integer (atoi)
* [reference solution](https://leetcode.com/problems/string-to-integer-atoi/discuss/4642/8ms-C%2B%2B-solution-easy-to-understand)
* **[shortcut]** use std.find_first_not_of() to get valid sub string
* use longlong as buffer
* check int32 range
* char zero = '0'; // ascii decimal = 48
* char nine = '9'; // ascii decimal = 57