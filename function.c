#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

int sum(int num1, int num2);
void print(int n);

int main()
{
	int dandan = sum(90, 12);
	int meimei = sum(87, 5);
	if (dandan > meimei)
	{
		printf("小丹的成绩比小美高\n");
	}
	else
	{
		printf("小美的成绩比小丹高\n");
	}
	print(3);
	printf("2的3次幂为：%.2f\n", pow(2, 3));
	printf("9的算术平方根为：%.2f\n", sqrt(9));
	printf("21.3向上取整后为：%.2f\n", ceil(21.3));
	printf("21.3向下取整后为：%.2f\n", floor(21.3));
	printf("-2的绝对值为：%d\n", abs(-2));

	//生成随机数
	srand(1);//设置种子
	int num = rand();//获取随机数
	printf("随机数为：%d\n", num);

	/*
	随机数的两个小弊端：
	1. 种子不变，随机数结果是固定的 -> 所以用时间作种子
	2. 随机数的范围无法控制，时大时小 -> 
	*/
	srand(time(NULL));
	int random1 = rand();
	printf("随机数为：%d\n", random1);

	/*
	 获取任意指定范围的随机数：（如7~23）
	 绝招：
	1.把这个范围变成包头不包尾，包左不包右的 -> 7~24
	2.拿着尾巴 - 开头 -> 24 - 7 = 17
	3.rand()对第二步的结果取余再加上开头 -> rand() % 17 + 7（这样范围就一定在0~16 + 7 = 7~23之间）
	*/
	srand(time(NULL));
	int random2 = rand() % 100 + 1;//1~100的随机数
	printf("随机数为：%d\n", random2);

	//猜数字游戏
	int a;
	printf("请猜一个1~100的数字\n");
	srand(time(NULL));
	int random3 = rand() % 100 + 1;
	while (1)
	{
		scanf("%d", &a);
		if (a > random3)
		{
			printf("猜大了，请继续\n");
		}
		else if (a < random3)
		{
			printf("猜小了，请继续\n");
		}
		else
		{
			printf("猜中了\n");
			break;
		}
	}


	return 0;
}

int sum(int num1, int num2)
{
	return num1 + num2;
}

void print(int n)
{
	for (int i = 1; i <= n; i++)
	{
		printf("阿伟\n");
	}
}


/*
函数最基本格式：
void 函数名()
{
	函数体;
}

有返回值的函数格式：
返回值类型 函数名(形参1, 形参2...)
{
	函数体;
	return 返回值;
}
*/

/*
C 语言里return的两大作用：
立刻终止当前函数执行；
将 return 后的值返回给调用这个函数的地方
*/

/*
定义函数的终极绝招
三个问题：
1.我定义函数，是为了干什么事情？  -> 函数体
2.我干这件事情，需要什么才能完成？ -> 形参
3.我干完了，调用处是否需要继续使用？ -> 返回值类型
										需要继续使用 必须写
										不需要返回 void
```
*/

/*
## 函数的注意事项
1. 函数不调用就不执行
2. 函数名不能重复
3. 函数与函数之间是平级关系，不能嵌套定义
4. 自定义函数写在main函数的下面时，需要在上方声明
5. return下面，不能编写代码，永远执行不到，属于无效的代码
6. 函数的返回值类型为void，表示没有返回值，return可以省略不写
   如果书写了return，后面不能跟具体的数据，仅表示结束函数
*/

/*
C语言中常见函数及其所属头文件：
1.  <math.h>
	pow()（幂运算）、sqrt()（开平方）、fabs()（求浮点绝对值）
	注：1.math.h中函数的返回值大多都是double类型
		2.abs()不在math.h中而在stdlib.h中，不导入stdlib.h也能正常使用abs()是由于VS的兼容性，要养成导入的习惯

2.  <stdio.h>
	printf()（输出）、scanf()（输入）

3. <stdlib.h>
	malloc()（分配内存，不清零）、free()（释放/回收内存）、calloc()（分配内存，自动清零）、realloc()（内存管理）、rand()（随机数）

4.  <string.h>
	strlen()（求长度）、strcmp()（字符串比较）、strlwr()（转小写）、strupr()（转大写）、strcat()（字符串拼接）、strcpy()（字符串拷贝）
*/

/*
time()  获取当前时间
形参：表示获取的当前时间是否需要在其他地方进行存储,一般来讲不需要，填NULL（大写）即可
返回值类型：long long
结果是从1970年1月1日 0:0:0 到现在过去的秒数
*/