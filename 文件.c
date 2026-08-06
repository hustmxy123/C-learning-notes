#include<stdio.h>

int main()
{
	//读文件
	char* file = "C:\\aaa\\a.txt";//原本路径为C:\aaa\a.txt，但写成字符串就需要添加转义字符"\"
	printf("%s\n", file);
	//打开文件
	FILE* file1 = fopen("D:\\PycharmProjects\\pythonProject\\python-learning-notes\\day05\\movies.csv", "r");//r表示以只读模式打开
	//读取数据
	/*
	//1.fgetc
	int c;
	while ((c = fgetc(file1)) != -1)
	{
		printf("%c ", c);
	}
	*/
	//2.fgets
	char arr[1024];
	char* str;
	while ((str = fgets(arr, 1024, file1)) != NULL)//参数表示数组名、数组长度、文件名
	{
		//printf("%s ", arr);
		printf("%s ", str);
	}
	//3.fread（返回当前读到的字节个数）
	//读取的时候尽可能每次把数组装满，返回读取到的有效字节个数，读不到返回0
	char arr1[1024];
	int n;//参数表示数组、数组中每个元素占多少字节、数组长度、文件名
	while ((n = fread(arr1, 2, 1024, file1)) != 0)
	{
		for(int i = 0; i < n; i++)
		{
			printf("%c", arr[i]);
		}
	}


	//写文件
	// 1.打开文件
	FILE* file2 = fopen("C:\\Users\\1\\Desktop\\a.txt", "w");

	// 2.写出数据
	//fputc 一次写一个字符，返回写出的字符
	// a --- 97
	int c1 = fputc(97, file2);
	printf("%c\n", c1);

	//fputs 一次写一个字符串，写出成功返回非负数，一般忽略返回值
	//细节：因为如果写出失败，那么就会有一个EOF的错误
	int n1 = fputs("你好你好", file2);
	printf("%d\n", n1);

	//fwrite 一次读多个，返回写出的字节个数
	char arr2[] = { 97, 98 , 99 , 100 , 101 };
	int n2 = fwrite(arr2, 1, 5, file2);
	printf("%d\n", n2);

	// 3.关闭文件
	fclose(file2);


	//拷贝文件
	// 1.打开a.wmv文件(数据源)
	FILE* file3 = fopen("C:\\Users\\1\\Desktop\\a.wmv", "rb");
	// 2.打开copy.wmv（目的地）
	FILE* file4 = fopen("C:\\Users\\1\\Desktop\\aaa\\copy.wmv", "wb");

	// 3.利用循环读取数据源，读完之后，再写到目的地
	char arr3[1024];
	int n3;
	while ((n3 = fread(arr3, 1, 1024, file3)) != 0)
	{
		// 就要把读取到的数据，再写到目的地文件当中
		fwrite(arr3, 1, n3, file4);
	}

	// 4.关闭文件
	fclose(file3);
	fclose(file4);
	return 0;
}

/*
站在程序角度：
数据从文件读到程序中 -> 输入流
数据从程序写到文件中 -> 输出流
*/

/*
路径的两种表示方式
绝对路径：C:\Users\admin\Desktop\a.txt （以盘符开头）
相对路径：aaa\a.txt （针对当前项目而言，在项目下找aaa文件夹，进而找到a.txt文件）
*/

/*
读取数据
把本地文件中的数据，读到程序中来
书写步骤：
① 打开文件：fopen
② 读数据：fgetc（一次读一个字符，读不到返回-1） fgets（一次读一行，读不到返回null） fread（一次读多个）
③ 关闭文件：fclose

写出数据
把程序中的数据，写到本地文件中永久存储
书写步骤：
① 打开文件：fopen
② 写数据：fputc（一次写一个字符，返回写出的数据） fputs（一次写一行字符） fwrite（一次写多个）
③ 关闭通道：fclose
*/

/*
## 文件的读写模式：
模式	描述
r	    只读模式
w	    只写模式细节 1：文件不存在，创建新文件        细节 2：文件已存在，清空文件
a	    追加写出模式细节 1：文件不存在，创建新文件    细节 2：文件已存在，不清空文件，续写
rb	    只读模式（操作二进制文件）//如图片、音频、视频等
wb	    只写模式（操作二进制文件）细节 1：文件不存在，创建新文件      细节 2：文件已存在，清空文件
ab	    追加写出模式（操作二进制文件）细节 1：文件不存在，创建新文件  细节 2：文件已存在，不清空文件，续写
*/