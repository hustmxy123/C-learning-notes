#include<stdio.h>

void swap(int* p1, int* p2);
void getMaxAndMin(int arr[], int len, int* max, int* min);
int getRemainder(int num1, int num2, int* res);

int main()
{
	int a = 10;
	//定义一个指针指向变量a
	int* p = &a;//指针类型须和变量数据类型一致，这里的*是指针专属标记
	//通过指针获取数据
	printf("%d\n", *p);//这里的*是解引用运算符
	//利用指针存储/修改数据
	*p = 20;
	printf("%d\n", a);

	//作用1函数swap对应代码块
	int b = 30;
	swap(&a, &b);
	printf("a、b交换后的值为：%d %d\n", a, b);

	//作用2函数getMaxAndMin对应代码块
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(arr1) / sizeof(int);
	int max = arr1[0];
	int min = arr1[0];//max和min就是要调用的变量，要事先定义好，才能在getMaxAndMin中传入地址
	getMaxAndMin(arr1, len, &max, &min);
	printf("数组arr1中的最大值为：%d，最小值为：%d\n", max, min);

	//作用3函数getRemainder对应代码块
	int num1 = 10;
	int num2 = 0;
	int res = 0;//初始化为0，后续指针会同步修改
	int flag = getRemainder(num1, num2, &res);//flag接收计算状态
	if (!flag)//计算状态正常才执行
	{
		printf("%d除以%d的余数为：%d\n", num1, num2, res);
	}
	else
	{
		printf("除数不能为0！\n");
	}
	return 0;
}

/*
指针的作用 1：操作其他函数中的变量
定义两个变量，要求交换变量中记录的值
*/
void swap(int* p1, int* p2)//如果仅仅传入num1,num2，是无法真正实现交换main函数中a,b的值的
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

/*
指针的作用 2：让函数返回多个值（其实不是靠return来返回，而是事先定义好要调用的变量，通过指针同步修改变量值，和作用1中的swap函数其实思想是一样的）
定义一个函数，求数组的最大值和最小值，并进行返回
*/
void getMaxAndMin(int arr[],int len, int* max, int* min)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > *max)
		{
			*max = arr[i];
		}
		if (arr[i] < *min)
		{
			*min = arr[i];
		}
	}
}

/*
指针的作用 3：使函数的结果和计算状态分开
定义一个函数，将两数相除，获取他们的余数
*/
int getRemainder(int num1, int num2, int* res)
{
	if (num2 == 0)
	{
		return 1;//return的只是计算状态，即计算结果是否正常，正常返回0，异常返回1
		         //而计算结果也是事先定义好变量res，通过指针同步修改，最后获取即可
	}
	else
	{
		*res = num1 % num2;
		return 0;
	}
}

/*
指针（即内存地址）的使用细节：
1. 指针变量的名字是p而不是*p，*在这里只是一个标记（指针变量中存的就是指针，但为了方便，也常把指针变量叫做指针）
2. 指针变量的数据类型要跟指向变量的类型保持一致
3. 指针变量也会占用内存空间，但它占用的大小跟数据类型无关，而是跟编译器有关（32 位：4 字节　　64 位：8 字节）
4. 给指针变量赋值赋的是变量地址（&a），而非具体数字
*/

/*
指针的作用：
作用 1：操作其他函数中的变量
        细节：函数中变量的生命周期跟函数相关，函数结束了，变量也会消失
		      此时在其他函数中，就无法通过指针使用了
			  如果不想函数中的变量被回收，可以在变量前面加 static 关键字（如：static int a = 10;）
作用 2：让函数返回多个值
作用 3：使函数的结果和计算状态分开
作用 4：方便地操作数组和函数（大章节，放在下一文件“指针高级”中阐述）
*/