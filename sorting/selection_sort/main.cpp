#include<iostream>
#include<vector>

using namespace std;

void print(const vector<int>& v);
void swap(vector<int>& v, int id1, int id2);
int arg_min(const vector<int>& v, int start);
void selection_sort(vector<int>& v);

int main()
{
    vector<int> v = {10,3,6,7,2,0,4,5,9,8,1};
    vector<int> v1 = {10,3,-6,7,2,0,4,5,-9,8,-1};

    cout << "Array before sorting:\n";
    print(v1);

    cout << "Applying the selection sort algorithm..." << endl;
    selection_sort(v1);

    cout << "Array after sorting:\n";
    print(v1);

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


int arg_min(const vector<int>& v, int start)
{
    int N = v.size();
    int min = v[start];
    int min_indx = start;
    for(int i = min_indx+1 ; i < N ; ++i)
    {
        if(v[i] < min)
        {
            min = v[i];
            min_indx = i;
        }
    }

    return min_indx;
}


void selection_sort(vector<int>& v)
{
    int N = v.size();
    for(int i = 0 ; i < N ; ++i)
    {
        int min_id = arg_min(v, i);
        swap(v, i, min_id);
    }

}