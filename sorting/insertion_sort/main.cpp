#include<iostream>
#include<vector>

using namespace std;


void print(const vector<int>& v);
void insert(vector<int>& v, int right, int value);
void insertion_sort(vector<int>& v);

int main()
{
	vector<int> v = {3,5,7,11,13,2,-1,0,9,6,-6};

	print(v);
    insertion_sort(v);
	print(v);


	return 0;
}


void print(const vector<int>& v)
{
	for(int j = 0 ; j < v.size() ; ++j)
		cout << v[j] << " ";
	cout << endl;
}


void insert(vector<int>& v, int right, int value)
{
	int i;
	for(i = right ; v[i] >= value &&  i >= 0 ; --i)
	{
		v[i+1] = v[i];
	}
		++i;
	v[i] = value;
}


void insertion_sort(vector<int>& v)
{
    int N = v.size();
	for(int i = 0 ; i < N-1 ; i++)
		insert(v, i, v[i+1]);
}