//
// Created by zzhou on 11.11.20.
//

#include <vector>
#include <iostream>

using std::vector;
using std::string;

namespace leetcode{

// summary:
// refs to https://leetcode.com/problems/string-to-integer-atoi/discuss/4642/8ms-C%2B%2B-solution-easy-to-understand
// 1. use std.find_first_not_of() to get valid sub string
// 2. use longlong as buffer
// 3. check int32 range
// 4. char zero = '0'; // ascii decimal = 48
// 5. char nine = '9'; // ascii decimal = 57
class StringToInteger
{
public:
    static int32_t solve(string s){
        int indicator = 1;
        int i = s.find_first_not_of(" ");
        if (i==-1) // corner case: empty string
            return 0;
        if (s[i] == '-'){
            indicator = -1;
            i+=1;
        } else if (s[i] == '+'){
            i+=1;
        }
        int64_t res = 0;
        while (s[i]>='0' && s[i] <='9'){
            res = res * 10 + static_cast<int>(s[i]-'0');
            if (res > INT32_MAX && indicator > 0)
                return INT32_MAX;
            if (res * indicator < INT32_MIN && indicator < 0)
                return INT32_MIN;
            i+=1;
        }
        return res * indicator;
    }

    static void test(){
        std::cout << ">>>> StringToInteger:" << std::endl;
        int res;
        res = StringToInteger::solve("42");
        std::cout << "42 -> " << res << std::endl;
        res = StringToInteger::solve("-91283472332");
        std::cout << "-91283472332 -> " << res << std::endl;
        res = StringToInteger::solve("         ");
        std::cout << "          -> " << res << std::endl;
    }
};

} // leetcode


int main(int argc, char* argv[]){

    leetcode::StringToInteger::test();

    return 0;
}