/* 题目是find the minimum number of characters that needs to be added to make a string be a palindrome */
/* 比如abc,最少要加2个character变成abcba或者cbabc */
#include <iostream>
#include <vector>
using namespace std;
int recursion(string str, int left, int right)
{
    if(left==right || left>right)
        return 0;
    if(str[left] != str[right]) {
        /* min is necessary for cases like "bba" */
        return 1+min(recursion(str, left+1, right), recursion(str, left, right-1));
    }else {
        left++;
        right--;
        return recursion(str, left, right);
    }
}

/* 状态方程： dp[i][j] 表示字符串s.substring(i, j + 1)变成palindrome需要插入的最小值 */
int iterative(string str, int left, int right)
{
    int n = str.length();
    vector< vector<int> > dp(n, vector<int>(n));
    for(int i = 0; i<str.length(); i++) {
        dp[i][i] = 0;
        if (i < str.length()-1) {
            dp[i][i+1] = str[i]==str[i+1]?0:1;
        }
    }
        //dp主体,
        for(int i = str.length() - 3; i >= 0; i--) {
            for(int j = i + 2; j < str.length(); j++) {
                if (str[i] == str[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
    return dp[0][n - 1];
}

int main()
{
    string str;
    while(cin>>str) {
        int left = 0;
        int right = str.length()-1;
        cout<<recursion(str, left, right)<<endl;
        cout<<iterative(str, left, right)<<endl<<endl;
    }
    return 0;
}
