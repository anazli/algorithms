#include<iostream>
#include<string>

using namespace std;

bool is_palindrome(const string& str)
{
    int N = str.size();
    string sbstr;
    if(N == 0 || N == 1)
        return true;
    else if(str[0] != str[N-1])
        return false;
    else
        sbstr = str.substr(1, N-2);  //1 for str[0] and 1 for str[N-1], so -2

    return is_palindrome(sbstr);
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "Enter a word!\n";
        return EXIT_FAILURE;
    }

    string str = argv[1];

    if(is_palindrome(str))
        cout << str << " is a palindrome!\n";
    else
        cout << str << " is not a palindrome!\n";

    return 0;
}