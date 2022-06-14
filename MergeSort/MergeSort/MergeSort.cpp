#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e6 + 10;
int f[N], tmp[N];
int n;

void MergeSort(int f[], int l, int r)
{
	if (l >= r)
	{
		return;
	}
	int mid = l + r >> 1;
	MergeSort(f, l, mid);
	MergeSort(f, mid + 1, r);
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r)
	{
		if (f[i] <= f[j])
		{
			tmp[k++] = f[i++];
		}
		else
			tmp[k++] = f[j++];
	}
	while (i <= mid)
	{
		tmp[k++] = f[i++];
	}
	while (j <= r)
	{
		tmp[k++] = f[j++];
	}
	for (int i = l, j = 0; i <= r; i++,j++)
	{
		f[i] = tmp[j];
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> f[i];
	}
	MergeSort(f, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << f[i] << ' ';
	}
	cout << endl;
	return 0;
}
