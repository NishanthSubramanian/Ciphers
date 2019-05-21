#include <bits/stdc++.h>

using namespace std;
int main()
{
    int i = 0, j, k;
    string s = "nggnpx";
    string result;
    while (s[i] != '\0')
    {
        if(s[i]+13 < 'z')
            result[i] = 13 + s[i];
        else
            result[i] = s[i]-13;
        i++;
    }
    for (i = 0; i < s.length(); i++)
        cout << result[i];
    cout << endl;
    return 0;
}