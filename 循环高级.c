#include<stdio.h>

int main()
{
	//在1~100间找出第一个既能被3又能被5整除的数
	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			printf("%d\n", i);
			break;
		}
	}

	//打印3行5列的*
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			printf("* ");
		}
		printf("\n");
	}

	//打印两个互补的5行5列的三角形
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("* ");
		}
		printf("\n");
	}

	for (int i = 5; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("* ");
		}
		printf("\n");
	}

	//打印九九乘法表
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d * %d = %d\t", j, i, j * i);
		}
		printf("\n");
	}

	//录入一个整数，求小于等于该整数的质数个数
	//不要一上来就从大框架思考，很容易晕，先从小的开始写，再慢慢补充、完善思路（抽茧剥丝大法）


	//第二步：统计从1到录入的整数之间有多少质数
	int n;
	printf("输入一个整数\n");
	scanf("%d", &n);
	int count1 = 0;
	for (int i = 2; i <= n; i++)//循环内放第一步的代码，每次循环就是在判断当前的i是不是质数
	{
		//第一步：判断一个数是不是质数
		int count = 0;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				count++;
				break;
			}
		}
		if (count == 0)
		{
			count1++;
		}
	}
	printf("从1到%d之间有%d个质数\n", n, count1);
	

	/*
	1 的 1 次方 + 2 的 2 次方 + 3 的 3 次方 + … + 10 的 10 次方，结果是多少？
	结果过大，用long long类型
	1 + 2 * 2 + 3 * 3 * 3 + 4 * 4 * 4 * 4 + ......
	*/
	
	//第二步：算从1到10的数次方的和
	long long sum = 0;
	for (int i = 1; i <= 10; i++)
	{
		//第一步：算一个数的该数次方
		long long result = 1;
		for (int j = 1; j <= i; j++)
		{
			result = result * i;
		}
		sum = sum + result;
	}
	printf("1 的 1 次方 + 2 的 2 次方 + 3 的 3 次方 + … + 10 的 10 次方的结果为：%lld\n", sum);
	

	/*
	找出 0~1000之内，符合要求的数字：要求：每一位的数字之和等于15
	举例：78，168 ...
	*/

	/*
	最小的一个是69，从它往后找
	求得每一位的数字再求和，要分两位数、三位数讨论
	*/
	for (int i = 69; i < 1000; i++)
	{
		if (i <= 99)
		{
			if (i % 10 + i / 10 == 15)
			{
				printf("%d ", i);
			}
		}
		else
		{
			if (i % 10 + i / 10 % 10 + i / 100 == 15)
			{
				printf("%d ", i);
			}
		}
	}
	return 0;
}

/*
break：不能单独书写，只能写在switch，或者是循环中，表示结束，跳出的意思
continue：结束本次循环，继续下次循环
*/

/*
\t：制表符，长度可变的大空格
会根据前面字母的个数在后面补空格，让整体的长度达到8或者8的倍数，最少补1个，最多补8个
*/

/*
循环嵌套的跳出问题
break: 只能跳出单层循环（写在内循环中就只能跳出内循环，跳不出外循环）
goto:可以跳出多层循环，跳到标号指定的位置，不限于循环，但大多都是在循环中使用，否则代码阅读性差

//外循环
for (int i = 1; i <= 3; i++)
{
	//内循环
	for (int j = 1; j <= 5; j++)
	{
		printf("内循环执行%d\n", j);
		//break;// 跳出内循环
		goto a;
	}
	printf("内循环结束\n");
	printf("------------\n");
}

// 标号
a: printf("外循环结束\n");

return 0;
*/