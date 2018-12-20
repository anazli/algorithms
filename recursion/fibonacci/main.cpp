#include<iostream>

using namespace std;

int fibonacci(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "Which element of the Fibonacci series do you want?\n";
        return EXIT_FAILURE;
    }   
    int N = strtol(argv[1], nullptr, 10);
    cout << "The " << N << "th element of the Fibonacci series is "
         << fibonacci(N) << endl;
    return 0;
}