// summary:
// 1. practice DP with table, bottom to up

#include <vector>
#include <string>
#include <iostream>
using namespace std;

string count_first_longest_palindromic_str(string s){
    int str_len = s.size();
    string s_out;

    // define a sub string index table
    // true -> sub str is palindrom
    vector<vector<bool> > dp(str_len, vector<bool>(str_len, false));  
    
    if (s.empty())
        return string("");

    int max_p_len = 1;
    s_out = s[0];
    // step = 0, substr len = 1, every single char is a minimum palindrom 
    for (int i = 0; i < str_len; i++){
        dp[i][i] = true;
    }


    // step = 1, substr len = 2
    for (int i = 0; i < str_len-1; i++){ // start
        int j = i+1;  // end
        bool condition_1 = s[i] == s[j];
        if (condition_1){
            dp[i][j] = true;
            max_p_len = 2;
            s_out=s.substr(i, 2);
        }
    }
    
    // step = 2, substr len > 2
    for (int step = 2; step < str_len; step ++){
        for (int i=0; i < str_len - step ; i++){  // start
            int j = i+step;  // end
            bool condition_1 = s[i] == s[j]; 
            bool condition_2 = dp[i+1][j-1];
            if (condition_1 && condition_2){
                dp[i][j] = true;
                if ((j-i+1) > max_p_len){
                    max_p_len =  (j-i+1);
                    s_out = s.substr(i, j-i+1);
                }
            }
        }
    }
    return s_out;
}

void test(){
    string s = "babad";
    string res = count_first_longest_palindromic_str(s);
    cout << res << endl;
}

void test2(){
    string s = "bb";
    string res = count_first_longest_palindromic_str(s);
    cout << res << endl;
}

int main(int argc, char* argv[])
{
    test();
    test2();
    return 0;
}