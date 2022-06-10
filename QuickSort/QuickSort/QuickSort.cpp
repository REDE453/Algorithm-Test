#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 1e6 + 10;
int f[N];
int n;

void QuickSort(int f[], int l, int r)
{
	if (l >= r)
	{
		return;
	}
	int i = l - 1, j = r + 1, x = f[l + r >> 1];
	while (i < j)
	{
		do i++; while (f[i] < x);
		do j--; while (f[j] > x);
		if (i < j)
		{
			swap(f[i], f[j]);
		}
	}
	QuickSort(f, l, j);
	QuickSort(f, j + 1, r);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> f[i];
	}
	QuickSort(f, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << f[i] << ' ';
	}
	cout << endl;
	return 0;
}