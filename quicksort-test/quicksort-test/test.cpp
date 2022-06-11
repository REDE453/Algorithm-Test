//给定一个长度为 n 的整数数列，以及一个整数 k，请用快速选择算法求出数列从小到大排序后的第 k 个数。
//
//输入格式
//第一行包含两个整数 n 和 k。
//
//第二行包含 n 个整数（所有整数均在 1∼109 范围内），表示整数数列。
//
//输出格式
//输出一个整数，表示数列的第 k 小数。
//
//数据范围
//1≤n≤100000,
//1≤k≤n
//输入样例：
//5 3
//2 4 1 5 3
//输出样例：
//3
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 100010;
int f[N];
int n, k;

void quicksort(int f[], int l, int r)
{
	if (l >= r)
	{
		return;
	}
	int x = f[(l + r )>> 1], i = l - 1, j = r + 1;
	while (i < j)
	{
		do i++;
		while (f[i] < x);
		do j--;
		while (f[j] > x);
		if (i < j)
		{
			swap(f[i], f[j]);
		}
	}
	quicksort(f, l, j);
	quicksort(f, j + 1, r);
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> f[i];
	}
	quicksort(f, 0, n - 1);
	cout << f[k - 1] << endl;
	return 0;
}