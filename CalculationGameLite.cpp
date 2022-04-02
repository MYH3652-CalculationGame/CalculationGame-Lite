/*
计算游戏 精简版 V0.0.2
作者: Huang Mingyang
Copyright(c) 2022 Huang Mingyang. All rights reserved.
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <windows.h>
#include <time.h>

using namespace std;

void begin();
void last();
void random(int&, int&, int);
bool Qadd(int, int);//加法
bool Qsub(int, int);//减法
bool Qmul(int, int);//乘法
bool Qdiv(int, int);//除法

int main()
{
	begin();//开始
	last();//上一次分数
	SYSTEMTIME sys;
	GetLocalTime(&sys);//获取系统时间
	int a, range = 10, rightsum = 0, wrongsum = 0;
	//range:题目取值范围 rightsum:做对的题数 wrongsum:做错的题数
	bool rnum;
	for (int i = 1;; i++)
	{
		range=int(10+i*0.2);
		srand(time(0));
		a = rand() % 4;
		switch (a)
		{
		case 0:
			rnum = Qadd(i, range);
			break;
		case 1:
			rnum = Qsub(i, range);
			break;
		case 2:
			rnum = Qmul(i, range);
			break;
		case 3:
			rnum = Qdiv(i, range);
			break;
		}
		ofstream fout("last.txt");
		if (rnum) rightsum++;
		else wrongsum++;
		fout << rightsum << " " << wrongsum;
		fout.close();
	}
	return 0;
}

void begin()
{
	printf("计算游戏 精简版 V0.0.2\n");
	printf("作者: Huang Mingyang\n");
	printf("Copyright(c) 2022 Huang Mingyang. All rights reserved.\n");
}

void last()
{
	int rightsum, wrongsum;
	ifstream fin("last.txt");
	if (!fin)
	{
		ofstream fout("last.txt");
		fout << "0 0";
		fout.close();
	}
	else
	{
		fin >> rightsum >> wrongsum;
		fin.close();
		if (rightsum != 0 || wrongsum != 0)
		{
			printf("\n上一次记录:\n正确 %d 错误 %d\n", rightsum, wrongsum);
			ofstream fout("last.txt");
			fout << "0 0";
			fout.close();
		}
	}
}

void random(int& a, int& b, int c)//数字1，数字2，范围
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);//获取系统时间
	srand(time(0));
	a = rand() % c;
	b = rand() % c;
}

bool Qadd(int Qnum, int range)//题号，范围
{
	int num[2] = {}, answer, solution;
	random(num[0], num[1], range);
	solution = num[0] + num[1];
	printf("\n(%d) %d + %d = ( )\n输入: ", Qnum, num[0], num[1]);
	cin >> answer;
	if (answer == solution)
	{
		printf("判定: 正确\n");
		return true;
	}
	else
	{
		printf("判定: 错误\n正确答案是: %d\n", solution);
		return false;
	}
}

bool Qsub(int Qnum, int range)//题号，范围
{
	int num[2] = {}, answer, solution;
	random(num[0], num[1], range);
	if (num[0] < num[1]) swap(num[0], num[1]);
	solution = num[0] - num[1];
	printf("\n(%d) %d - %d = ( )\n输入: ", Qnum, num[0], num[1]);
	cin >> answer;
	if (answer == solution)
	{
		printf("判定: 正确\n");
		return true;
	}
	else
	{
		printf("判定: 错误\n正确答案是: %d\n", solution);
		return false;
	}
}

bool Qmul(int Qnum, int range)//题号，范围
{
	int num[2] = {}, answer, solution;
	random(num[0], num[1], range);
	solution = num[0] * num[1];
	printf("\n(%d) %d × %d = ( )\n输入: ", Qnum, num[0], num[1]);
	cin >> answer;
	if (answer == solution)
	{
		printf("判定: 正确\n");
		return true;
	}
	else
	{
		printf("判定: 错误\n正确答案是: %d\n", solution);
		return false;
	}
}

bool Qdiv(int Qnum, int range)//题号，范围
{
	int num[2] = {}, answer, answer2, solution, mod;
	random(num[0], num[1], range);
	if (num[0] < num[1]) swap(num[0], num[1]);
	if (num[1] == 0) num[1]++;
	solution = num[0] / num[1];
	mod = num[0] % num[1];
	if (mod == 0)
	{
		printf("\n(%d) %d ÷ %d = ( )\n输入: ", Qnum, num[0], num[1]);
		cin >> answer;
		if (answer == solution)
		{
			printf("判定: 正确\n");
			return true;
		}
		else
		{
			printf("判定: 错误\n正确答案是: %d\n", solution);
			return false;
		}
	}
	else
	{
		printf("\n(%d) %d ÷ %d = ( ) ······ ( )\n", Qnum, num[0], num[1]);
		printf("商: ");
		cin >> answer;
		printf("余数: ");
		cin >> answer2;
		if (answer == solution && answer2 == mod)
		{
			printf("判定: 正确\n");
			return true;
		}
		else
		{
			printf("判定: 错误\n正确答案是: %d %d\n", solution, mod);
			return false;
		}
	}
}