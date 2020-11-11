//
// Created by zzhou on 11.11.20.
//

#ifndef LEETCODE_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
#define LEETCODE_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
#include <map>
#include <iostream>

using std::map;
using std::string;

namespace leetcode{

// summary:
// 1. maintain a non-repeat buffer, which support hash index
// 2. sliding window search, a slightly similar philosophy with simple DP
class LongestSubStringWithoutRepeatingCharacters
{
public:
    static int solve(string s){
        if (s.size() <= 1){
            return s.size();
        }

        map<char, int> buffer;
        int max_len = 1;  // if not empty, there is at least 1 char
        int j = 0;  // pointer to first buffer element
        for (int i=0; i < s.size(); i++){
            while (buffer.find(s[i]) != buffer.end()){ // there current element is a repeated element
                buffer.erase(s[j]);  // delete buffer from start until no repeat
                j += 1;
            }
            buffer[s[i]] = i;
            max_len = (i-j+1) > max_len ? (i-j+1) : max_len;
        }

        return max_len;
    }

    static void test(){
        std::cout << ">>>> LongestSubStringWithoutRepeatingCharacters:" << std::endl;
        string ss = "abcabcbbabcdeaaaaaaaa";
        int max_len = LongestSubStringWithoutRepeatingCharacters::solve(ss);
        std::cout << ss << ": " << max_len << std::endl;
    }
};

} // leetcode

#endif //LEETCODE_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
