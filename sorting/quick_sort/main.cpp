#include<iostream>
#include<cmath>
#include<vector>

using namespace std;


void print(const vector<int>& v);
void swap(vector<int>& v, int id1, int id2);
int divide(vector<int>& v, int p, int r);
void quick_sort(vector<int>& v, int p, int r);

int main()
{
    vector<int> v = {9, 7, 5, 11, -12, 2, 14, 0, -6, 3, 10, 6};
    int N = v.size();

    cout << "Array before sorting:" << endl;
    print(v);

    cout << "Applying the quick sort algorithm..." << endl;
    quick_sort(v, 0, N-1);

    cout << "Array after sorting:" << endl;
    print(v);

    return 0;
}


void print(const vector<int>& v)
{
    int N = v.size();
    for(int i = 0 ; i < N ; ++i)
        cout << v[i] << " ";

    cout << endl;
}


void swap(vector<int>& v, int id1, int id2)
{
    int temp = v[id1];
    v[id1] = v[id2];
    v[id2] = temp;
}

int divide(vector<int>& v, int p, int r)
{
    int q,j;
    for(j = p, q = p ; j < r ; ++j)
    {
        if(v[j] <= v[r])
        {
            swap(v, q, j);
            q++;
        }
    }
    swap(v, q, r);

    return q;
}

void quick_sort(vector<int>& v, int p, int r)
{
    if(p < r)
    {
        int pivot = divide(v, p, r);
        quick_sort(v, p, pivot-1);
        quick_sort(v, pivot+1, r);
    }
}