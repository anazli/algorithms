#include<iostream>

using namespace std;

int factorial(int n)
{
    if(n == 0)
        return 1;

    return n * factorial(n-1);
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "Enter a valid positive number!\n";
        return EXIT_FAILURE;
    }

    int n = strtol(argv[1], 0, 10);

    if(n < 0)
    {
        cout << "Enter a positive number!\n";
       return EXIT_FAILURE;
    }

    cout << "The factorial of number " << n << " is " << factorial(n) << endl;

    return 0;
}