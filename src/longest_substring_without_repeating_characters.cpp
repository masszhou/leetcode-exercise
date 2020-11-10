// summary:
// 1. maintain a non-repeat buffer, which support hash index
// 2. sliding window search, a slightly similar philosophy with simple DP

#include <string>
#include <iostream>
#include <map>

using namespace std;

void printout(map<char, int> buffer)
{
    for (auto each : buffer){
        std::cout << each.first << ", ";
    }
    std::cout << std::endl;
}

int lengthOfLongestSubstring(string s) {
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

void test(string ss)
{
    int max_len = lengthOfLongestSubstring(ss);
    std::cout << ss << ": " << max_len << std::endl;
}

int main(int argc, char* argv[])
{
    test("abcabcbbabcdeaaaaaaaa");
    std::cout << "=========" << std::endl;
    test("aa");
    std::cout << "=========" << std::endl;
    test(" ");
    std::cout << "=========" << std::endl;
    test("au");
    std::cout << "=========" << std::endl;
    test("dvdf");
}