#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

void print(const vector<int>& v);
void merge(vector<int>& v, int p, int q, int r);
void merge_sort(vector<int>& v, int p, int r);

int main()
{
    vector<int> v = {14, 7, 3, 12, -9, 11, -6, 2, 0};
    int N = v.size();

    cout << "Array before sorting:" << endl;
    print(v);

    cout << "Applying the merge sort algorithm..." << endl;
    merge_sort(v, 0, N-1);

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

//merge the two subvectors into the vector by comparing their
//values
void merge(vector<int>& v, int p, int q, int r)
{
    vector<int> firstHalf;
    vector<int> secondHalf;

    int k = p;
    int i;
    int j;

    for(i = 0 ; k <= q ; ++i, ++k)
        firstHalf.push_back(v[k]);
    for(j = 0 ; k <= r ; ++j, ++k)
        secondHalf.push_back(v[k]);

    k = p;
    i = 0;
    j = 0;

    while(i < firstHalf.size() && j < secondHalf.size())
    {
        if(firstHalf[i] < secondHalf[j])
        {
            v[k] = firstHalf[i];
            i++;
        }
        else
        {
            v[k] = secondHalf[j];
            j++;
        }
        k++;
    }

    while(i < firstHalf.size())
    {
        v[k] = firstHalf[i];
        i++;
        k++;
    }

    while(j < secondHalf.size())
    {
        v[k] = secondHalf[j];
        j++;
        k++;
    }
}

//recursively divide the vector into two sub vectors
//until we reach the base case (n=1)
void merge_sort(vector<int>& v, int p, int r)
{
    if(p < r)
    {
        int mid = int(floor(double(r + p)/2.));
        merge_sort(v, p, mid);
        merge_sort(v, mid+1, r);
        merge(v, p, mid, r);
    }
    else
        return;
}