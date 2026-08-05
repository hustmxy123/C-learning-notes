#include<stdio.h>
#include<string.h>

int main()
{
    // 1.利用字符数组 + 双引号的方式定义字符串
    char str1[4] = "abc";
    printf("%s\n", str1);

    //细节1：
    //在底层，实际存储的时候，C语言还是会帮我们把字符串"abc"转换成字符数组进行保存，并且在末尾还要再加上'\0'结束标记
    //{'a','b','c','\0'};

    //细节2：
    //数组的长度，要么不写，如果要写的话，记得要把结束标记的空间给预留出来

    //细节3：
    //字符数组 + 双引号的方式定义字符串，内容是可以发生改变的（普通内存区）
    str1[0] = 'Q';
    printf("%s\n", str1);


    // 2.利用指针 + 双引号的方式定义字符串
    char* str2 = "abcd";
    char* str3 = "abcd";

    //细节1：
    //在底层，实际存储的时候，C语言还是会帮我们把字符串"abcd"转换成字符数组进行保存，并且在末尾还要再加上'\0'
    //{'a','b','c','d','\0'};

    //细节2：
    //利用指针 + 双引号的方式定义字符串，会把底层的字符数组放在只读常量区（不可修改字符串）

    //只读常量区特点:
    //内容不可以修改的
    //里面定义的字符串是可以复用的
    //在创建abcd的时候，会检查只读常量区里面有没有abcd，如果没有才会创建新的，如果已经有了，不会创建新的，而是进行复用

    //str2[0] = 'Q'; // 错误！只读常量区不能修改

    printf("%p\n", str2);
    printf("%p\n", str3);//str2和str3地址是一样的

    //1.键盘录入一个字符串，并在控制台遍历
    char str[100];//初始化要足够长，避免字符串超出范围
    printf("键盘录入一个字符串\n");
    scanf("%s", str);//str无需加&，本身就是指针
    //每次录入字符串长度不一样，不知循环次数，故用while循环
    char* p = str;//str赋给字符指针
    while (*p != '\0')//循环条件：没碰上结束标记'\0'
    {
        printf("%c ", *p);
        p++;
    }
    printf("\n");  

    /*
    2.定义一个数组存储5个学生的名字并遍历
    字符串底层就是一个字符数组，相当于现在要用一个大数组存放字符数组，即二维数组
    */
    char str4[5][100] =
    {
        "张三",
        "李四",
        "王五",  
        "赵六",
        "钱七"
    };
    for (int i = 0; i < 5; i++)
    {
        char* p = str4[i];
        printf("%s ", p);
    }
    /*
    方法二：把五个字符串的指针放入一个数组，即指针数组
    */
    char* str5[5] =//这个就不是二维数组了，而是一维数组里存放了五个指针
    {
        "张三",
        "李四",
        "王五",
        "赵六",
        "钱七"
    };
    //遍历是一样的，只是定义数组的时候有格式上的区别
    for (int i = 0; i < 5; i++)
    {
        char* p = str5[i];
        printf("%s ", p);
    }
    printf("\n");

    /*
    3.字符串常用函数的应用，要写头文件<string.h>
    */
    char* str6 = "abc";
    char str7[100] = "Abc";
    char str8[5] = { 'Q', 'w', 'e', 'r', '\0' };

    printf("---------------strlen (长度) --------------------\n");
    //细节1：strlen函数在统计长度时，不会把结束标记算进去
    //细节2：windows下，一个汉字占两个字节
    int len1 = strlen(str6);
    int len2 = strlen(str7);
    int len3 = strlen(str8);

    printf("%d\n", len1);//3
    printf("%d\n", len2);//3
    printf("%d\n", len3);//4

    printf("---------------strcat (拼接) --------------------\n");
    /*
    细节1：会把第二个字符串的全部内容，拷贝到第一个字符串的末尾
        前提：1.第一个字符串是可以被修改的，即不是指针加双引号的格式
              2.第一个字符串有足够的剩余空间用来拼接
    */
    strcat(str7, str8);
    printf("%s\n", str7);//AbcQwer
    printf("%s\n", str8);//Qwer

    printf("---------------strcpy (拷贝) --------------------\n");
    /*
    细节：把第二个字符串的全部内容，拷贝到第一个字符串，第一个字符串原有内容被覆盖掉
        前提：1.第一个字符串是可以被修改的，即不是指针加双引号的格式
              2.第一个字符串有足够的空间用来拷贝
    */
    strcpy(str7, str8);
    printf("%s\n", str7);//Qwer
    printf("%s\n", str8);//Qwer

    printf("---------------strcmp (比较) --------------------\n");
    // 完全一样: 0（指顺序、内容和大小写等等都相同才叫完全一样）
    // 只要有一个不一样: 非0
    int res = strcmp(str6, str7);
    printf("%d\n", res);//-1

    printf("---------------strlwr (变小写) --------------------\n");
    //细节：只能转换英文字母的大小写，不能转换中文汉字的大小写
    _strlwr(str7);
    printf("%s\n", str7);//qwer

    printf("---------------strupr (变大写) --------------------\n");
    //细节：只能转换英文字母的大小写，不能转换中文汉字的大小写
    _strupr(str7);
    printf("%s\n", str7);//QWER

    /*
    4.已知正确的用户名和密码，请用程序实现模拟用户登录。总共给三次机会，登录之后，给出相应的提示
    不能用==判断两字符串是否相等，因为==比较的是两个指针的地址，不是比较字符串里面的文字内容
    */
    //正确的用户名和密码用指针形式存储，因为不可修改
    char* username_r = "zhangsan";
    char* password_r = "123456";
    //用户键盘录入
    printf("请输入用户名和密码\n");
    char username[100];
    char password[100];
    //比较
    for (int i = 1; i <= 3; i++)
    {
        scanf("%s %s", username, password);
        if (3 - i > 0)
        {
            if (!strcmp(username_r, username) && !strcmp(password_r, password))//完全一样返回0，所以这里要取反
            {
                printf("成功登录！\n");
                break;
            }
            else
            {
                printf("用户名或密码错误，请重新输入，您还有%d次输入机会\n", 3 - i);
                continue;
            }
        }
        else
        {
            printf("连续输错三次，账号已冻结，请稍后再试！\n");
        }
    }

    /*
    5.键盘录入一个字符串，统计该字符串中大写字母字符，小写字母字符，数字字符出现的次数（不考虑其他字符）
    */
    char str9[100];
    printf("键盘录入一个字符串\n");
    scanf("%s", str9);
    char* p1 = str9;//让指针 p1 指向字符串第一个字符的地址
                    //p1 最开始存的就是第一个字符的内存地址，后面做p1++，指针就向后移动，指向下一个字符
    int count_upr = 0;
    int count_lwr = 0;
    int count_num = 0;
    //遍历，统计每种字符的出现次数
    while (1)
    {
        char c = *p1;//取出 p1 这个地址里面真实存放的字符内容
        if (c != '\0')
        {
            if (c > 'A' && c < 'Z')
            {
                count_upr++;
                p1++;
            }
            else if (c > 'a' && c < 'z')
            {
                count_lwr++;
                p1++;
            }
            else
            {
                count_num++;
                p1++;
            }
        }
        else
        {
            break;
        }
    }
    printf("大写字母有%d个，小写字母有%d个，数字字符有%d个\n", count_upr, count_lwr, count_num);
	return 0;
}

/*
字符串的三种写法：
char str[4] = {'a', 'b', 'c', '\0'};//不常用，手动加'\0'一般交给C语言底层来做
char str[4] = "abc";//字符数组 + 双引号
char* str = "abc";//指针 + 双引号
*/

/*
string 常用函数
strlen：获取字符串的长度
strcat：拼接两个字符串
strcpy：复制字符串
strcmp：比较两个字符串
_strlwr：将字符串变成小写
_strupr：将字符串变成大写
头文件：#include <string.h>
注意：strlwr、strupr属于微软扩展函数，不是 C 标准库，部分编译器会告警，竞赛尽量自己手写大小写转换
*/