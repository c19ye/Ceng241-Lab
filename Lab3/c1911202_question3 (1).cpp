#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char const *argv[])
{
    int vowel{}, consonant{}, digit{}, whites{};
    string line;
    cout << "Enter a line of string: ";
    getline(cin, line);

    for (size_t i = 0; i < line.size(); i++)
    {
        if (!isdigit(line[i]))
            line[i] = tolower(line[i]);
        if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u')
            vowel++;
        if (isdigit(line[i]))
            digit++;
        if (line[i] == ' ')
            whites++;
    }
    cout << "Vowels: " << vowel << endl
         << "Consonants: " << line.size() - (vowel + digit + whites) << endl
         << "Digits: " << digit << endl
         << "White spaces: " << whites;
    return 0;
}
