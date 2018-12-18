#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int binary_search(const vector<int>&, const int&, int&);

int main()
{
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
                         43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};


    int iterations = 0;
    int wanted = 3001;

    int indx = binary_search(primes, wanted, iterations);

    if(indx == -1)
        cout << "The number:" << wanted << " is not in the vector!" << endl;
    else
        cout << wanted << " found at position " << indx << " after "
             << iterations << " iterations!" << endl;

    return 0;
}


int binary_search(const vector<int>& v, const int& wanted, int& i)
{
    vector<int>::size_type mn = 0;
    vector<int>::size_type mx = v.size()-1;

    vector<int>::size_type guess = 0;

    while(mx >= mn)
    {
        guess = (int)floor((mn + mx)/2);

        if(v[guess] == wanted)
            return guess;
        if(v[guess] < wanted)
            mn = guess + 1;
        else if(v[guess] > wanted)
            mx = guess - 1;
        i++;
    } 

    return -1;

}