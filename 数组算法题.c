#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printArr(int arr[], int len);
int binarySearch(int arr[], int len);
void bubbleSort(int arr[], int len);
void selection_sort(int arr[], int len);

int main()
{
	/*
	1.需求：已知数组元素为{33,5,22,44,55}
	  请找出数组中最大值并打印在控制台
	*/
	int arr1[] = { 33,5,22,44,55 };
	int len1 = sizeof(arr1) / sizeof(int);
	int max = arr1[0];//不能让max=0，因为可能数组中都是负数
	for (int i = 1; i < len1; i++)
	{
		if (arr1[i] > max)
		{
			max = arr1[i];
		}
	}
	printf("该数组中最大值为：%d\n", max);


	/*
	2.需求：生成10个1~100之间的随机数存入数组，要求数据不能重复
	  1）求出所有数据的和
	  2）求所有数据的平均数
	  3）统计有多少个数据比平均值小
	*/
	int arr2[10] = { 0 };//不初始化可能也正常运行，但这属于去读取还没赋值的位置，行为不可预测，一旦生成的随机数和未初始化中的垃圾数据一样就会出bug
	srand(time(NULL));//种子写一次就好了，千万别放循环里
	for (int i = 0; i < 10; )
	{
		int flag = 1;
		int random = rand() % 100 + 1;
		//数组中不存在这个新生成随机数，才把它加入数组
		for (int j = 0; j < 10; j++)
		{
			if (random == arr2[j])
			{
				flag = 0;
			}
		}
		if (flag == 1)
		{
			arr2[i] = random;
			i++;//每加入一个新随机数后，i才++
		}
	}
	//遍历最终数组验证前面的代码逻辑是否有问题（养成习惯，不要全部写完才来运行，否则不好排查bug）
	printf("生成的随机数数组arr2中元素依次为：");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");
	//1）求出所有数据的和
	int sum1 = 0;
	for (int i = 0; i < 10; i++)
	{
		sum1 += arr2[i];
	}
	printf("所有数之和为：%d\n", sum1);
	//2）求所有数据的平均数
	double ave1 = sum1 / 10.0;
	printf("所有数的平均数为：%.2lf\n", ave1);
	//3）统计有多少个数据比平均值小
	int count1 = 0;
	for (int i = 0; i < 10; i++)
	{
		if (arr2[i] < ave1)
		{
			count1++;
		}
	}
	printf("有%d个数比平均值小\n", count1);


	/*
	题2解法二
	int arr3[10];//这个方法无须初始化数组，因为count计数器思想避免了原始数组中的垃圾数据和随机数“碰面”
	int count = 0; // 记录当前数组存了几个有效数字
	while (count < 10)
	{
		int random = rand() % 100 + 1;
		int flag = 1;
		// 只遍历【已经存入】的count个元素，不用扫描全部10个
		for (int j = 0; j < count; j++)
		{
			if (arr3[j] == random)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			arr3[count] = random;
			count++;
		}
	}
	printf("生成的随机数数组arr3中元素依次为：");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr3[i]);
	}
	*/


	/*
	3.需求：键盘录入5个数据并存入数组，完成以下需求：
	  1）遍历数组
	  2）反转数组后再次遍历
	*/
	int arr3[5] = { 0 };
	printf("请输入5个数字\n");
	for (int i = 0; i < 5; i++)
	{
		int a;
		scanf("%d", &a);
		arr3[i] = a;
		/*
		或者直接写成：
		scanf("%d",&arr3[i]);
		*/
	}
	printf("您创建的数组元素为：");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr3[i]);
	}
	printf("\n");
	//反转数组并遍历（思路：定义一个新数组，把原数组元素倒着存入即可）
	int arr4[5] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		arr4[i] = arr3[5 - i - 1];
	}
	printf("反转后的数组元素为：");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr4[i]);
	}
	printf("\n");


	/*
	题3解法二，双索引思想，i从索引0出发，j从索引末尾出发，，一一对应交换所指元素，当i>=j时停止交换，即反转数组成功
	int arr5[5] = { 0 };
	int len = sizeof(arr5) / sizeof(int);
	printf("请输入5个数字\n");
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &arr5[i]);
	}
	printf("您创建的数组元素为：");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr5[i]);
	}
	printf("\n");
	//双索引反转数组法
	int i = 0;
	int j = len - 1;
	while (i < j)//只知道循环结束条件用while，别只知道for循环！
	{
		int temp = arr5[i];//temp第三方变量
		arr5[i] = arr5[j];
		arr5[j] = temp;
		i++;
		j--;
	}
	printf("反转后的数组元素为：");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr5[i]);
	}
	printf("\n");
	*/


	/*
	打乱数组{ 1,2,3,4,5 }中的顺序并返回
	*/
	int arr5[] = { 1,2,3,4,5 };
	int len2 = sizeof(arr5) / sizeof(int);
	//生成范围为0到数组长度-1的随机数索引，将原数据存入随机索引对应的数组位置
	srand(time(NULL));
	int index1;
	for (int i = 0; i < len2; i++)
	{
		index1 = rand() % 5;//rand() % len
		int temp = arr5[i];
		arr5[i] = arr5[index1];
		arr5[index1] = temp;
	}
	printf("打乱后的数组元素为：\n");
	printArr(arr5, len2);
	printf("\n");


	/*
	基本查找（顺序查找）
	原理：从数组第一个元素开始，逐个对比目标值，找到就返回下标；遍历结束没找到则返回-1表示查找失败（因为数组索引没有-1）
	特点：有序、无序数组都能用；效率低

	int arr6[] = { 1,2,3,4,5,6,7,8,9 };
	int len3 = sizeof(arr6) / sizeof(int);
	int num1 = 7;
	for (int i = 0; i < len3; i++)
	{
		if (arr6[i] == num1)
		{
			return i;//找到就返回索引
		}
	}
	return -1;//没找到就返回-1
	*/

	/*
	二分查找（折半查找）
	前提：数组升序/降序有序，不断取中间元素mid = (min + max) / 2和目标比较：
	目标 < 中间值 → 在左半区间查找 → max = mid - 1
	目标 > 中间值 → 在右半区间查找 → min = mid + 1
	不断缩小范围，直到找到或区间为空 → min > max 时，未查找成功，返回-1
	特点：速度快；只能用于有序数组
	*/
	int arr6[] = { 7, 23, 79, 81, 103, 127, 131, 147 };
	int len3 = sizeof(arr6) / sizeof(int);
	int index2 = binarySearch(arr6, len3);
	printf("返回的索引为：%d\n", index2);

	/*
	冒泡排序
	相邻元素两两比较，逆序就交换；一轮遍历后最大值“冒泡”到末尾。多轮循环，逐步确定尾部有序元素
	*/
	int arr7[] = { 3,6,2,8,19,56,4 };
	int len4 = sizeof(arr7) / sizeof(int);
	bubbleSort(arr7, len4);
	printf("冒泡排序后的数组元素为：\n");
	printArr(arr7, len4);
	printf("\n");

	/*
	选择排序
	1，从0索引开始，跟后面的元素一一比较
	2，小的放前面，大的放后面
	3，第一轮循环结束后，最小的数据已经确定
	4，第二轮循环从1索引开始以此类推
	*/
	selection_sort(arr7, len4);
	printf("选择排序后的数组元素为：\n");
	printArr(arr7, len4);
	printf("\n");
	return 0;
}

void printArr(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
}

/*
二分查找
*/
int binarySearch(int arr[], int len)
{
	printf("请输入要查找的数据\n");
	int num;
	scanf("%d", &num);
	int min = 0;
	int max = len - 1;
	while (min <= max)//不知道循环多少次，用while！
	{
		int mid = (min + max) / 2;//mid写在循环内，因为每次要更新
		if (num > arr[mid])
		{
			min = mid + 1;
		}
		else if (num < arr[mid])
		{
			max = mid - 1;
		}
		else if (num == arr[mid])
		{
			return mid;
		}
	}
	return -1;
}

/*
冒泡排序
*/
void bubbleSort(int arr[], int len)//直接修改原数组，无返回值，不要写成int[]，是错的！
{
	//第二步：多轮循环处理完整个数组（外循环len-1轮，因为len - 1轮结束，最小的元素也定下来了，不用再比一次）
	for (int i = 0; i < len - 1; i++)
	{
		//第一步：比较相邻元素，把最大的放最右边
		for (int j = 0; j < len - 1 - i; j++)//len - 1是为了防止数组越界，因为要拿i和i + 1的数据比较，要以i + 1为准（连续两次Ctrl + R可批量修改函数内变量名）
		{                                    //再 - i是要排除尾部已确定的元素，减少循环次数
			if (arr[j] > arr[j + 1])//逆序就交换
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

/*
选择排序
*/
void selection_sort(int arr[], int len)
{
	for (int i = 0; i < len - 1; i++)//也是只用循环len - 1轮，因为最后一轮最大元素也跟着确定下来了
	{
		for (int j = i + 1; j < len; j++)//arr[j]表示i索引之后的每个元素
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


/*
## 一、查找算法
1. 顺序查找（线性\基本查找）

2. 二分查找（折半查找）

3. 插值查找（二分的优化）
   前提：有序、数据尽量均匀分布
   插值公式：
   mid = min + (({key-arr[min]})/({arr[max]-arr[min]}))*(max-min)
   原理：预估目标大概所在位置，不是固定取中间
   特点：均匀数据速度比二分快；分布极端不均匀时效果很差

4. 分块查找（索引顺序查找）前提：块内无序，块间有序，即后一块的所有元素都比前一块的最大值大
   分块原则：一般是元素数量的算术平方根
   原理：（先确定在哪一块，再在块内顺序查找）
   建立索引表，保存每一块最大值；
   先对索引二分查找，确定目标在哪一块；
   在对应块内顺序查找
   特点：折中方案；适合大数据

   扩展：如果没有规律（即不是块内无序块间有序），也可以用分块思想，只要保证块与块之间没有交叉
         每一块保存该块的最大值和最小值，再来确定是哪一块，最后块内顺序查找

   扩展2：如果分块的同时还要添加不重复的随机数，可以按区间分块，每一块不重复的元素像链子一样串着（为后续链表铺垫）
		 
5. 哈希查找（散列查找）前提：哈希表结构，不是普通有序数组
   原理：
   通过哈希函数 hash(key)，直接算出元素存放位置
   理想情况：一次定位找到元素。
   存在问题：哈希冲突（多个 key 算出同一个地址），需要冲突解决方案（链地址法、开放寻址等）。
   复杂度：理想O(1)
   特点：不要求有序；考研数据结构高频，蓝桥笔试选择常考


二分、插值、分块都属于基于比较的查找；
哈希查找不依靠比较，依靠地址映射，思路完全不一样；
做题区分：
普通一维有序数组优先二分；海量数据可以分块；快速去重、映射用哈希

## 二、排序算法
1. 冒泡排序

2. 选择排序

3. 插入排序
原理：把数组分成「有序区」和「无序区」；依次取出无序区第一个元素，向前插入到有序区合适位置

4. 快速排序（蓝桥高频）
原理：选定一个基准值，把数组划分成两部分：小于基准放左边、大于基准放右边；再递归处理左右两个子区间

5. 归并排序
原理：分治思想。数组不断对半拆分，拆到单个元素；再按大小有序合并子数组。稳定排序

6. 希尔排序（插入排序优化）
原理：设置步长分组，组内进行插入排序；逐步缩小步长直到步长=1，完成整体插入排序

7. 堆排序
原理：构建大顶堆（父节点≥子节点），不断把堆顶最大值交换到数组尾部，再调整堆

# 极简考点小结（适合C语言/蓝桥杯）
1. 无序数组查找：只用顺序查找
2. 有序数组查找优先：二分查找
3. 手写代码常考：冒泡、选择、插入、快速排序
4. C语言实战：直接用 qsort() 库函数（考试利器）
*/