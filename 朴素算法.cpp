#include <iostream>
#include<fstream>
using namespace std;

const int N = 200000;
int a[N] = { 0 };
int cnt = 0;

int main() {
    fstream fin("input.txt");

    int number=0;
    while (!fin.eof())
    {
        fin >> a[number++];
    }
    cout << "����Ϊ��";
    for (int i = 0; i < number; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "������Ŀ����Ϊ��"<<number << endl;
    for (int i = 0; i < number; ++i) {
        for (int j = i + 1; j < number; ++j) {
            if (a[i] > 2 * a[j]) {
                ++cnt;
            }
        }
    }
    cout <<"��Ҫ��������Ϊ��" <<cnt << endl;
    fin.close();
    return 0;
}