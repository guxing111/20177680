#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;



bool sign = false;/* 构造完成标志 */



int num[9][9];/* 创建数独矩阵 */



/* 函数声明 */

void Input();

void Output();

bool Check(int n, int key);

int DFS(int n);

int len;



int main()

{

	cout << "请输入一个N*N的数独矩阵，空位以0表示:" << endl;

	cin >> len;

	Input();

	DFS(0);

	Output();

	system("pause");

}



void Input()

{

	char temp[9][9];

	for (int i = 0; i < len; i++)

	{

		for (int j = 0; j < len; j++)

		{

			cin >> temp[i][j];

			num[i][j] = temp[i][j] - '0';

		}

	}

}


void Output()

{

	cout << endl;

	for (int i = 0; i < len; i++)

	{

		for (int j = 0; j < len; j++)

		{

			cout << num[i][j] << " ";

		}

		cout << endl;

	}

}



bool Check(int n, int key)

{

	
	for (int i = 0; i < len; i++)

	{

	
		int j = n / len;

		if (num[j][i] == key) return false;

	}

	
	for (int i = 0; i < len; i++)

	{

		
		int j = n % len;

		if (num[i][j] == key) return false;

	}



	

	return true;

}



int DFS(int n)

{


	if (n > len* len - 1)

	{

		sign = true;

		return 0;

	}

	if (num[n / len][n % len] != 0)

	{

		DFS(n + 1);

	}

	else

	{

		for (int i = 1; i <= len; i++)

		{

			
			if (Check(n, i) == true)

			{

				num[n / len][n % len] = i;

				
				DFS(n + 1);

				
				if (sign == true) return 0;

				
				num[n / len][n % len] = 0;

			}

		}

	}

}