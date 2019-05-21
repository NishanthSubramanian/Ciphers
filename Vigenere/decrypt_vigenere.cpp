#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

//Generate repetitive key
string generateKey(string str, string key)
{
    int x = str.size();
    for (int i = 0;; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

//Decrypt to original text
string originalText(string cipherText, string key)
{
    string original;
    for (int i = 0; i < cipherText.size(); i++)
    {
        int x = (cipherText[i] - key[i] + 26) % 26;
        x += 'A';
        original.push_back(x);
    }
    return original;
}
int main()
{
    int i, j, k;
    char current_char;
    fstream file;
    file.open("decrypt_vigenere_input.txt", ios::in | ios::out);
    string s;

    //Read from input file
    while (getline(file, s))
        ;
    
    fstream file2;
    file2.open("vigenere_key.txt", ios::in | ios::out);
    string key;

    //Read key 
    while (getline(file2, key))
        ;

    
    fstream decrypted_vigenere_file;
    string generated_key = generateKey(s, key);
    string decrypted_vigenere = originalText(s, generated_key);
    decrypted_vigenere_file.open("decrypt_vigenere_output.txt", ios::out);

    //write to output file
    decrypted_vigenere_file << decrypted_vigenere;
    return 0;
}
