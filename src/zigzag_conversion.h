//
// Created by zzhou on 11.11.20.
//

#ifndef LEETCODE_ZIGZAG_CONVERSION_H
#define LEETCODE_ZIGZAG_CONVERSION_H
#include <vector>
#include <iostream>

using std::vector;
using std::string;

namespace leetcode{

// summary:
// 1. fundamental DP practice, bottom to up
class ZigZagConversion
{
public:
    static string solve(string s, int numRows){
        if (numRows == 1)
            return s;
        vector<string> row_str(numRows, "");
        int flip = 1;
        int step = numRows - 1;
        for (int i = 0; i < s.size(); i++){
            if ((i%step == 0)&&(i>0))
                flip *= -1;
            int row_idx = flip > 0 ? (i%(step)) : step - (i%(step));
            row_str[row_idx] += s[i];
        }

        string res;
        for (auto each : row_str)
            res += each;
        return res;
    }

    static void test(){
        string res = ZigZagConversion::solve("PAYPALISHIRING", 4);
        std::cout << ">>>> TwoSum:" << std::endl;
        std::cout << "PAYPALISHIRING, n_rows= 4 -> " << res << std::endl;
    }
};

} // leetcode
#endif //LEETCODE_ZIGZAG_CONVERSION_H
