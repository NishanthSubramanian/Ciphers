#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file;
    char current_char, s;
    int shift;
    cout << "enter shift";
    cin >> shift;
    cout << shift << endl;
    file.open("produce_caesar_input.txt", ios::in);
    fstream encrypted_text_file;
    encrypted_text_file.open("produce_caesar_output.txt", ios::out);

    while (!file.eof())
    {
        //read from input file
        file.get(current_char);

        if (isalpha(current_char))              //check is valid alphabet
        {
            //shifting
            if (current_char - shift < 'a')     
            {
                s = current_char - shift + 26;
                encrypted_text_file << s;
            }
            else
            {
                s = current_char - shift;
                encrypted_text_file << s;
            }
        }
        else
        {
            //write to output file
            encrypted_text_file << current_char;
        }
    }
}
