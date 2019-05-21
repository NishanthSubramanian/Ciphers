#include <bits/stdc++.h>

using namespace std;
int a = 5;
int b = 7;
int m = 26;
void finfreq(string s)
{
    int i = 0;
    int count[26] = {0};
    while (s[i] != '\0')
    {
        if (isalpha(s[i]))
        {
            count[s[i] - 'a']++;
        }
        i++;
    }
    int max1 = count[0];
    int max2 = count[0];
    int maxindex1 = 0;
    int maxindex2 = 0;
    for (i = 0; i < 26; i++)
    {
        if (count[i] > max2 && count[i] < max1)
        {
            max2 = count[i];
            maxindex2 = i;
        }
        else if (count[i] > max1)
        {
            max2 = max1;
            max1 = count[i];
            maxindex2 = maxindex1;
            maxindex1 = i;
        }
    }
    char most_freq = 'A' + max1;
    char second_most_freq = 'A' + max2;
    cout << most_freq << endl << second_most_freq << endl;
}
int main()
{
    int i = 0, j, k, flag = 0, a_inv = 0;
    string s = "WBGBUW";
    finfreq(s);
    string result;
    for (j = 0; j < m; j++)
    {
        flag = (a * j) % m;
        if (flag == 1)
            a_inv = j;
    }
    // cout << a_inv << endl;
    while (s[i] != '\0')
    {
        if (s[i] != ' ')
            result[i] = (char)((((a_inv * ((s[i] + 'A' - b))) % m)) + 'A');
        else
            result[i] = s[i];
        i++;
    }
    for (i = 0; i < s.length(); i++)
        cout << result[i];
    cout << endl;
    return 0;
}