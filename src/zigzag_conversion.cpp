#include <string>
#include <vector>
#include <iostream>
using namespace std;

void printout(vector<string>& n)
{
    for (auto each : n){
        std::cout << each << ",";
    }
    std::cout << std::endl;
}

string zigzag_conversion(string s, int numRows)
{
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

    printout(row_str);

    string res;
    for (auto each : row_str)
        res += each;
    return res;
}

void test()
{
    string res = zigzag_conversion("PAYPALISHIRING", 4);
    std::cout << res << std::endl;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}