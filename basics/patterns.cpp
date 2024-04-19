#include <iostream>
using namespace std;

void pattern1(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << '*' << " ";
		}
		cout << endl;
	}
}
void pattern2(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}
void pattern3(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j << " ";
		}
		cout << endl;
	}
}
void pattern4(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i << " ";
		}
		cout << endl;
	}
}
void pattern5(int n)
{
	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}
void pattern6(int n)
{
	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j << " ";
		}
		cout << endl;
	}
}
void pattern7(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n - i; j++)
		{
			cout << " ";
		}
		for (int k = 1; k <= 2 * i - 1; k++)
		{
			cout << "*";
		}
		cout << endl;
	}

	// int gap = n - 1, stars = 1;
	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= gap; j++)
	// 	{
	// 		cout << " ";
	// 	}
	// 	for (int j = 1; j <= stars; j++)
	// 	{
	// 		cout << "*";
	// 	}
	// 	cout << endl;
	// 	gap--;
	// 	stars += 2;
	// }
}
void pattern8(int n)
{
	// int gap = 0, stars = 2 * n - 1;
	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= gap; j++)
	// 	{
	// 		cout << " ";
	// 	}
	// 	for (int j = 1; j <= stars; j++)
	// 	{
	// 		cout << "*";
	// 	}
	// 	cout << endl;
	// 	gap++;
	// 	stars -= 2;
	// }

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * n - (2 * i + 1); j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void pattern9(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < (2 * i + 1); j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * n - (2 * i + 1); j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void pattern10(int n)
{
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		int stars = i;
		if (i > n)
			stars = 2 * n - i;
		for (int j = 1; j <= stars; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void pattern11(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			((i + j) % 2 == 0) ? cout << 1 << " " : cout << 0 << " ";
		}
		cout << endl;
	}

	// int start = 1;
	// for (int i = 0; i < n; i++)
	// {
	// 	if (i % 2 == 0)
	// 		start = 1;
	// 	else
	// 		start = 0;
	// 	for (int j = 0; j <= i; j++)
	// 	{
	// 		cout << start << " ";
	// 		start = 1 - start;
	// 	}
	// 	cout << endl;
	// }
}
void pattern12(int n)
{
	int gap = 4 * n - 3;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j << " ";
		}
		for (int j = 1; j <= gap; j++)
		{
			cout << " ";
		}
		for (int j = i; j > 0; j--)
		{
			cout << j << " ";
		}
		gap -= 4;
		cout << endl;
	}
}
void pattern13(int n)
{
	int num = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << num << " ";
			num++;
		}
		cout << endl;
	}
}
void pattern14(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (char ch = 'A'; ch <= 'A' + i; ch++)
		{
			cout << ch << " ";
		}
		cout << endl;
	}
}
void pattern15(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (char ch = 'A'; ch < 'A' + n - i; ch++)
		{
			cout << ch << " ";
		}
		cout << endl;
	}
}
void pattern16(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << (char)(i + 65) << " ";
		}
		cout << endl;
	}
}
void pattern17(int n)
{
	int gap = 2 * (n - 1);
	for (int i = 1; i <= n; i++)
	{
		// spaces
		for (int j = 1; j <= gap; j++)
		{
			cout << " ";
		}
		gap -= 2;
		// alphabets
		char ch = 'A';
		int breakpoint = (2 * i - 1) / 2;
		for (int j = 1; j <= 2 * i - 1; j++)
		{
			cout << ch << " ";
			if (j <= breakpoint)
				ch++;
			else
				ch--;
		}
		cout << endl;
	}
}
void pattern18(int n)
{
	for (int i = 1; i <= n; i++)
	{
		char ch = 'A' + n - 1;
		for (int j = 1; j <= i; j++)
		{
			cout << ch << " ";
			ch--;
		}
		cout << endl;
	}
}
void pattern19(int n)
{
	int gap = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			cout << '*' << " ";
		}
		for (int j = 0; j < gap; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < n - i; j++)
		{
			cout << '*' << " ";
		}
		gap += 4;
		cout << endl;
	}

	gap = 4 * (n - 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << '*' << " ";
		}
		for (int j = 0; j < gap; j++)
		{
			cout << " ";
		}
		for (int j = 0; j <= i; j++)
		{
			cout << '*' << " ";
		}
		gap -= 4;
		cout << endl;
	}
}
void pattern20(int n)
{
	int gap = 4 * (n - 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << '*' << " ";
		}
		for (int j = 0; j < gap; j++)
		{
			cout << " ";
		}
		for (int j = 0; j <= i; j++)
		{
			cout << '*' << " ";
		}
		gap -= 4;
		cout << endl;
	}

	gap = 4;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			cout << '*' << " ";
		}
		for (int j = 0; j < gap; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < n - i; j++)
		{
			cout << '*' << " ";
		}
		gap += 4;
		cout << endl;
	}

	// for (int i = 0; i < 2 * n; i++)
	// {
	// 	for (int j = 0; j < 2 * n; j++)
	// 	{
	// 		if (i < n && (j < i || j >= 2 * n - i -1 ))
	// 			cout << "*"
	// 				 << " ";
	// 		else if (i > n && (j > i || j <= 2 * n - i))
	// 			cout << "*"
	// 				 << " ";
	// 		else
	// 			cout << " ";
	// 	}
	// 	cout << endl;
	// }
}
void pattern21(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << endl;
	}
}
void pattern22(int n)
{
	for (int i = 0; i < 2 * n - 1; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++)
		{
			int top = i, left = j, right = 2 * (n - 1) - j, bottom = 2 * (n - 1) - i;
			cout << n - min(min(top, bottom), min(right, left)) << " ";
		}
		cout << endl;
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		pattern19(n);
	}
}
