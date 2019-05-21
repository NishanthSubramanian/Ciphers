#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    fstream file;
    file.open("decrypt_caesar_input.txt", ios::in | ios::out);
    int count[26] = {0};
    char current_char, s;
    int number_of_lines = 0;
    while (!file.eof())
    {
        //read from input file
        file.get(current_char);

        if (isalpha(current_char))
        {
            count[current_char - 'a']++;
        }
    }
    int max = count[0];
    int max1 = 0, i;
    for (i = 0; i < 26; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
            max1 = i;
        }
    }
    char most_freq = 'a' + max1;
    //frequency analysis done
    //Since e is the most frequent alphabet
    int shift = 'e' - 'a' - max1 + 26;
    cout << "Shift is : " << shift;
    file.close();
    file.open("decrypt_caesar_input.txt", ios::in);
    fstream decrypted_text_file;
    decrypted_text_file.open("decrypt_caesar_output.txt", ios::out);

    while (!file.eof())
    {
        //read from input file
        file.get(current_char);
        if (isalpha(current_char))              //check is valid alphabet
        {
            //reverse shifting
            if (current_char + shift > 'z')
            {
                s = current_char + shift - 26;
                decrypted_text_file << s;
            }
            else
            {
                s = current_char + shift;
                decrypted_text_file << s;
            }
        }
        else
        {
            //write to output file
            decrypted_text_file << current_char;
        }
    }
}
