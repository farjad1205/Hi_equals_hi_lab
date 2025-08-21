#include <iostream>
#include <String>
#include <cctype>
using namespace std;

char toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        ch += 32; // from uppercase to lowercase the ascii codes differ by 32 (26 letters + special char)
    }
    return char(ch);
}

int strcmp_case_insensitive(string str1, string str2)
{
    // create temps to covert to lower case
    string temp1 = "";
    string temp2 = "";

    // convert both strings to lower case
    for (char c : str1)
    {
        c = toLower(c);
        temp1 += to_string(c);
    }
    for (char c : str2)
    {
        c = toLower(c);
        temp2 += to_string(c);
    }

    if (temp1 == temp2)
    {
        return 0; // strings are equal
    }
    else if (temp1 < temp2)
    {
        return -1; // str1 is less than str2
    }
    else
    {
        return 1; // str1 is greater than str2
    }
}

int main()
{
    // cout << toLower('A') << endl;

    cout << "The comparison for" << " String one " << "and" << " string two"
         << " returns " << strcmp_case_insensitive("String one", "string two") << endl;

    cout << "The comparison for" << " String one " << "and" << " string one"
         << " returns " << strcmp_case_insensitive("String one", "string one") << endl;

    cout << "The comparison for" << " String two " << "and" << " string one"
         << " returns " << strcmp_case_insensitive("String two", "string one") << endl;

    cout << "The comparison for" << " String " << "and" << " string one"
         << " returns " << strcmp_case_insensitive("String", "string one") << endl;

    cout << "The comparison for" << " empty string " << "and" << " string one"
         << " returns " << strcmp_case_insensitive("", "string one") << endl;

    cout << "The comparison for" << " speci@l Char! " << "and" << " string one"
         << " returns " << strcmp_case_insensitive("speci@l Char!", "string one") << endl;
}