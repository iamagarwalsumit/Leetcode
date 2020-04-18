/*
    Created by
    Sumit Agarwal
    https://leetcode.com/problems/valid-parenthesis-string/
*/

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int l = 0, h = 0;
        for(auto c:s){
            if(c=='(') {
                ++l;
                ++h;
            }
            if(c==')'){
                --l;
                --h;
            }
            if(c=='*'){
                --l;
                ++h;
            }
            if(h < 0) break;
            l = max(l,0);
        }
        return (l==0);
    }
};