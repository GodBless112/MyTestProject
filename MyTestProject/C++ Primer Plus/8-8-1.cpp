#include <iostream>
using namespace std;
void show(const char* ch, int n = 0);
int Count;
int main()
{
	int i;
	Count = 0;
	const char*ch = "Alpha Go\n";
	cin >> i;
	while (i >= 0)
	{
		cout << "����n: " << endl;
		show(ch, i);
		i--;
	}
	cout << "Ĭ�ϲ���nΪ0�� " << endl;
	show(ch);
	while (1);
	return 0;
}
void show(const char *ch, int n)
{
	Count++;
	cout << "��" << Count << "�ε���" << endl;
	if (n != 0)
	{
		for (int i = 0; i < Count; i++)
			cout << ch;
	}
	else if (n == 0)
	{
		cout << ch << endl;
	}
}
