#include <bits/stdc++.h>

using namespace std;
int main()
{
    int i = 0, j, k;
    string s = "zggzxp";
    string result;
    while (s[i] != '\0')
    {
        result[i] = 'a' + 'z' - s[i];
        i++;
    }
    for (i = 0; i < s.length(); i++)
        cout << result[i];
    cout << endl;
    return 0;
}