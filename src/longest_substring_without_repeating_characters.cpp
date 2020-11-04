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

    for (int i=0; i<s.size(); i++){  // i 0-7
        buffer[s[i]] = i;
        for (int j = i+1; j < s.size(); j++){
            // use hash table to search buffered substr
            if (buffer.count(s[j]) != 0){
                max_len = (j-i) > max_len ? (j-i) : max_len;
                break;
            }else{
                buffer[s[j]] = j;
                max_len = (j+1-i) > max_len ? (j+1-i) : max_len;
            }            
        }
        buffer.clear();
    }
    return max_len;
}

void test(string ss)
{
    int max_len = lengthOfLongestSubstring(ss);
    std::cout << max_len << std::endl;
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
}