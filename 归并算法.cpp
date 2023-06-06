#include <iostream>
#include<fstream>
using namespace std;

const int N = 200000;
int a[N] = {};
int b[N] = {};
long long cnt = 0;

void merge(int left, int mid, int right)
{
	int i = left, j = mid, k = left, times = 0;
	memcpy(b + left, a + left, (right - left) * sizeof(int));	// 复制内存
	// 单独用一个while循环计算“重要逆序对”，计算方法与逆序对基本相同
	while (i < mid && j < right)
	{
		if (b[i] > 2 * b[j])				
		{
			cnt += j - i - times;
			times++;
			j++;
		}
		else
		{
			i++;
		}
	}
	// 归并过程
	i = left, j = mid;
	while (i < mid && j < right)
	{
		if (b[i] < b[j])
		{
			a[k++] = b[i++];
		}
		else
		{
			a[k++] = b[j++];
		}
	}
	while (i < mid)
	{
		a[k++] = b[i++];
	}
	while (j < right)
	{
		a[k++] = b[j++];
	}
}

void merge_sort(int left, int right)
{
	if (right - left == 1)
	{
		return;
	}
	int mid = (left + right) / 2;
	merge_sort(left, mid);
	merge_sort(mid, right);
	merge(left, mid, right);
}




int main() {
    fstream fin("input.txt");


    int number = 0;
    while (!fin.eof())
    {
        fin >> a[number++];
    }
    cout << "序列为：";
    for (int i = 0; i < number; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "序列项目总数为：" << number << endl;

	merge_sort(0, number);
    cout << "重要的逆序数为：" << cnt << endl;
    fin.close();
    return 0;
}