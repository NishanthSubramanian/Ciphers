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

//Produce a ciphertext by shifting
string cipherText(string cipherText, string key)
{
    string original;
    for (int i = 0; i < cipherText.size(); i++)
    {
        int x = (cipherText[i] + key[i]) % 26;
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
    file.open("produce_vigenere_input.txt", ios::in | ios::out);
    string s;

    //read input from file
    while (getline(file, s))
        ;
    
    fstream file2;
    //read the key
    file2.open("vigenere_key.txt", ios::in | ios::out);
    string key;
    while (getline(file2, key))
        ;
        
    fstream produce_vigenere_file;
    string generated_key = generateKey(s, key);                             //generate key (repeat if necessary)
    string produce_vigenere = cipherText(s, generated_key);
    produce_vigenere_file.open("produce_vigenere_output.txt", ios::out);

    //write to output file
    produce_vigenere_file << produce_vigenere;
    return 0;
}
