#include "bits/stdc++.h"
using namespace std;


int main () {
    // ->string to integer 

    //use stoi() if the resultant number fits 32 bit integer
    string s1 = "12345";
    int smallNumber = stoi(s1);

    //use stoll() for bigger numbers
    string s2 = "1234454353353";
    int bigNumber = stoll(s2);

    //integer to string
    int num = 1234;
    string snum = to_string(num);

    // char to digit conversion
    // difference of char with '0' gives digit
    char c = '2';
    int d = c - '0';

    //digit to char conversion
    int d = 2;
    char c = '0' + d;

    // generating alphabet with the position in alphabets
    // a : 0, b:1 , ... . z:25

    int pos = 3;
    char c = 'a' + 3; // c = 'd'

    // this is used in storing alphabet frequency in vector or array
    vector<int>freq(26);
    string s = "abcdeeeaadf";
    for(auto&c:s) freq[c-'a']++; // 'a' - 'a' = 0, 'a' frequency is stored at v[0]
}
