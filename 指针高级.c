#include<stdio.h>

int* method();
void swap(void* p1, void* p2, int len);
void method1();
int method2(int num1, int num2);
int add(int num1, int num2);
int subtract(int num1, int num2);
int multiply(int num1, int num2);
int divide(int num1, int num2);


int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
	int* p1 = &arr1[0];
	int* p2 = &arr1[5];
	printf("指针p1的下一个步长对应数据为：%d\n", *(p1 + 1));
	printf("指针p1、p2相差步长为：%d\n", p2 - p1);

	int* p3 = p1 + 10;//野指针，空间尚未分配
	printf("野指针所指数据为：%d\n", *p3);

	int* p4 = method();//悬空指针，方法调用完后那一片空间就被释放了
	printf("拖点时间\n");
	printf("悬空指针所指数据为：%d\n", *p4);

	// 不同类型的指针之间，是不能互相赋值的（虽然有隐式转换但也会报警告）
	// 而void类型的指针可以打破上面的观念
	// void没有任何类型，好处就是可以接受任意类型指针记录的内存地址
	void* p5 = p1;
	void* p6 = p2;
	// 缺点: void类型的指针，无法获取变量里面的数据，也不能进行加、减的计算（因为只有知道数据类型，才能通过指针找到完整数据）
	//printf("%p\n", p5 + 1); 报错！

	// 调用函数交换数据
	short c = 10;
	short d = 200;
	swap(&c, &d, 2);//2即sizeof(c)
	printf("c = %d, d = %d\n", c, d);

	/*
	二级指针
	数据类型** 指针名，二级指针类型为数据类型**，二级指针中的内容为一级指针，类型为数据类型*
	*/
	int a = 10;
	int b = 20;
	int* p = &a;
	int** pp = &p;//二级指针中存放一级指针的地址
	*pp = &b;//将二级指针中的内容（即一级指针的地址）改为变量b的地址
	printf("变量a的地址为：%p\n", &a);
	printf("变量b的地址为：%p\n", &b);
	printf("一级指针p的地址为（原本和a一致，现在应和b一致）：%p\n", p);
	printf("变量b的值为：%d\n", **pp);

	//数组指针
	int arr2[] = { 10,20,30,40,50 };
	int* p7 = arr2;//等价于&arr2[0]，但arr2更简洁，因此更常用
	int len1 = sizeof(arr2) / sizeof(int);
	for (int i = 0; i < len1; i++)
	{
		printf("%d ", *p7++);//先解引用得到数组元素，后p7加加
	}

	// 1.定义数组
	int arr3[] = { 1,2,3,4,5,6,7,8,9,10 };
	// 2.sizeof 运算的时候，不会退化，arr还是整体
	printf("%zu\n", sizeof(arr3));// 40
	// 3.&arr获取地址的时候，不会退化，记录的内存地址第一个元素的首地址，也是数组的首地址，步长: 数据类型 * 数组的长度 40
	// arr参与计算的时候，会退化为第一个元素的指针，记录的内存地址第一个元素的首地址，也是数组的首地址，步长: 数据类型 4
	//arr和&arr的指针类型也不一样，arr的是int*，&arr的是int (*)[10]（指向整个长度为 10 的 int 数组）
	printf("%p\n", arr3);
	printf("%p\n", &arr3);
	printf("%p\n", arr3 + 1);// 4
	printf("%p\n", &arr3 + 1);// 40

	/*
	二维数组的第一种定义格式（该格式要求一维数组长度都一样）：
	数据类型 arr[m][n] =
	{
    {1,2,3,4...},
    {1,2,3,4...},
    {1,2,3,4...}
	};
	其中，m为二维数组的长度（行），n为一维数组的长度（列）

	二维数组的第二种定义格式：
	int arr1[5] = {1,2,3,4,5};
	int arr2[5] = {6,7,8,9,0};
	int* arr[2] = {arr1, arr2};//传入的是首地址，故二维数组的类型为int*

	计算二维数组和其中一维数组长度的公式（针对一维数组长度都一样的情况）：
	行数 = sizeof(二维数组名) / sizeof(数组名[0])
	列数（每行元素数） = sizeof(数组名[0]) / sizeof(数组名[0][0])
	例：int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
		int rows = sizeof(arr)/sizeof(arr[0]);    // 3 行
		int cols = sizeof(arr[0])/sizeof(arr[0][0]); // 4 列
	*/

	//利用索引遍历第一种格式的二维数组
	int arr4[3][5] =
	{
		{1,2,3,4,5},
		{11,22,33,44,55},
		{111,222,333,444,555}
	};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", arr4[i][j]);
		}
		printf("\n");
	}

	//利用索引遍历第二种格式的二维数组
	int arr5[] = { 1,2,3 };
	int arr6[] = { 1,2,3,4,5 };
	int arr7[] = { 1,2,3,4,5,6,7 };
	//定义二维数组（本质是指针数组）装一维数组
	int* arr8[] = { arr5,arr6,arr7 };
	//定义一个长度数组，便于后续遍历一维数组
	int len2 = sizeof(arr5) / sizeof(int); 
	int len3 = sizeof(arr6) / sizeof(int);
	int len4 = sizeof(arr7) / sizeof(int);
	int lenArr[3] = {len2,len3,len4};
	//遍历二维数组
	for (int i = 0; i < 3; i++)
	{
		//不能在这里写int len = sizeof(arr8[i])/sizeof(int)，因为arr8[i]算作参与运算，直接退化为第一个元素的指针
		//再来求sizeof就只看操作系统，64位下一律为8个字节，而int又是4个字节，所以len的结果永远是2，无法得到真正的一维数组长度
		//所以正确的做法是在循环前提前把每个一维数组的长度算好封存进长度数组，循环中只调用
		for (int j = 0; j < lenArr[i]; j++)
		{
			printf("%d ", arr8[i][j]);
		}
		printf("\n");
	}

	/*
	按逻辑，二维数组指针的定义格式为：数据类型 * 指针名 = arr，即int [5] * p = arr
	但实际C语言的合法写法为：int (*p)[5];
	这就是数组指针，指向一个长度为 5 的 int 数组
	括号不能丢，(*p)代表 p 是指针，指向int[5]这种数组类型
	区分：
	int (*p)[5]：p 是指针 → 数组指针
	int *p[5]：p 是数组，数组元素为 int* → 指针数组
	*/

	//利用指针遍历第一种格式的二维数组（借用上面的arr4数组）
	//定义二维数组的数组指针
	int(*p8)[5] = arr4;//arr4数组名参与运算，退化为数组指针，类型就是int (*)[5]（类比int* p = &a;）
	//遍历
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//p8指向二维数组第一行；*p8得到该行首元素地址；*p8 + j该行第j个元素地址；*(*p8 + j)取元素
			printf("%d ", *(*p8 + j));
		}
		p8++; //数组指针+1，跳到下一行
		printf("\n");
	}

	//利用指针遍历第二种格式的二维数组（借用上面索引遍历第二种格式数组的数据）
	//定义二维数组的数组指针
	int** p9 = arr8;//这种格式下二维数组中存的不是真正的一维数组，而是一维数组首地址，类型为int*，第二个*是指针标记
	//遍历
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < lenArr[i]; j++)
		{
			printf("%d ", *(*p9 + j));//此处逻辑和指针第一种一样
		}
		printf("\n");
		p9++;
	}

	//定义函数指针，用来调用函数
	void (*p10)() = method1;
	int (*p11)(int, int) = method2;//书写格式：函数名和形参名删掉，中间加上(*p)，等号右侧写上函数名即可
	//调用函数
	p10();
	int result = p11(10, 20);
	printf("%d\n", result);

	/*
	函数指针的练习
	定义加、减、乘、除四个函数,用户键盘录入三个数字,前两个表示参与计算的数字,第三个数字表示调用的函数
	1：加法  2：减法  3：乘法  4：除法
	*/
	printf("请输入要进行运算的两个整数\n");
	int num1;
	int num2;
	scanf("%d %d", &num1, &num2);
	//将函数指针存入数组（因为有四个函数，所以要用数组存储），即构造函数指针数组
	//注：只有形参和返回值类型完全一样的函数才能放入同一个函数指针数组
	int (*p12[4])(int, int) = { add,subtract,multiply,divide };
	//用户选择要进行的运算，调用函数指针数组中对应函数即可
	printf("请选择要进行的运算1~4\n");
	int choose;
	scanf("%d", &choose);
	//调用函数
	int result2 = p12[choose - 1](num1, num2);//本质就是p1();，只是多处理一个数组的外壳
	printf("运算结果为：%d\n", result2);
	return 0;
}

int* method()
{
	int num = 20;
	int* p = &num;
	return p;
}

//用void* 指针类型替代之前写过的swap函数，使其更具有通用性
void swap(void* p1, void* p2, int len)//len为要操作的数据的字节大小
{
	// 把void类型的指针转成char类型，方便后续一个字节一个字节地交换数据（因为void*类型没法直接操作）
	char* pc1 = p1;
	char* pc2 = p2;

	char temp = 0;

	// 以字节为单位进行交换（不要把字节和数字位数搞混了，是一个字节一个字节交换而非一位数字一位数字交换）
	//所以交换的两个数，位数可以不一样，但数据类型必须一样
	for (int i = 0; i < len; i++)
	{
		temp = *pc1;
		*pc1 = *pc2;
		*pc2 = temp;
		pc1++;
		pc2++;
	}
}

void method1()
{
	printf("method1\n");
}

int method2(int num1, int num2)
{
	printf("method2\n");
	return num1 + num2;
}

//函数指针的练习，先定义加减乘除四个函数
int add(int num1, int num2)
{
	return num1 + num2;
}

int subtract(int num1, int num2)
{
	return num1 - num2;
}

int multiply(int num1, int num2)
{
	return num1 * num2;
}

int divide(int num1, int num2)
{
	return num1 / num2;
}

/*
指针中数据类型的作用：获取字节数据的个数（因为指针只是定位到首地址，还要结合数据类型才能找到整个数据）

指针运算：
步长：指针移动一次，走了多少个字节
char: 1     short: 2     int: 4     long:4     long long:8
加法：指针往后移动了 N 步，p + 1     减法：指针往前移动了 N 步，p - 1

有意义的操作：
指针跟整数进行加、减操作（表示每次移动N个步长）
指针跟指针进行减操作（表示间隔步长）

无意义的操作：
指针跟整数进行乘除操作（此时指针指向不明）
指针跟指针进行加、乘、除操作

void * p，没有类型的指针
特点：无法获取数据，无法计算，但是可以接收任意地址，使函数更具通用性
*/

/*
arr参与计算的时候，会退化为第一个元素的指针

特殊情况：
sizeof 运算的时候，不会退化，arr还是整体（计算数组长度的公式int len = sizeof(arr)/sizeof(int)就是因为这样才成立的）
&arr获取地址的时候，不会退化（获取到的和arr一样是首地址，但步长是整个数组的字节大小，而arr就只是一个数组元素的字节大小）
所以：arr + 1是指向下一个元素     &arr + 1是横跨整个数组
*/

/*
数组指针：指向数组的指针    作用：方便的操作数组中的各种数据
举例：int* p = arr;       步长为： int（4 字节）
	  int (*p)[5] = &arr;  步长为： int 乘 5（20 字节）

指针数组：存放指针的数组作用：用来存放指针
举例：int *p[5]，这个数组里面存着 int 类型的指针
举例：int arr1[5] = {1,2,3,4,5};
	  int arr2[5] = {6,7,8,9,0};
	  int* arr[2] = {arr1, arr2};
*/