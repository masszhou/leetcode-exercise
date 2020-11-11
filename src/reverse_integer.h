//
// Created by zzhou on 11.11.20.
//

#ifndef LEETCODE_REVERSE_INTEGER_H
#define LEETCODE_REVERSE_INTEGER_H
#include <vector>
#include <string>
#include <iostream>

using std::string;

namespace leetcode{

// Given a 32-bit signed integer, reverse digits of an integer.
// -2^31 <= x <= 2^31 -1
// 2^31 = 2147483648

// summary:
// 1. be careful for corner case, signed integer overflow: -2147483648 * -1
class ReverseInteger
{
public:
    static int solve(int x){
        string res;
        if (x == -2147483648){ // corner case, since signed integer overflow: -2147483648 * -1, 2^31 = 2147483648
            return 0;
        }else if (x < 0){
            x *= -1;
            res += "-";
        }
        if (x%10 == 0){
            x /=10;
        }
        string s = std::to_string(x);
        for (std::string::reverse_iterator rit=s.rbegin(); rit!=s.rend(); ++rit)
            res += *rit;

        long tmp = std::stol(res);
        if (tmp<-2147483648 || tmp > 2147483648)
            tmp = 0;
        return static_cast<int>(tmp);
    }

    static void test(){
        int x = -2147483648;
        int64_t res = ReverseInteger::solve(x);
        std::cout << res << std::endl;
    }
};

} // leetcode
#endif //LEETCODE_REVERSE_INTEGER_H
