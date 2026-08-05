#include<stdio.h>
#include<string.h>

union MoneyType
{
    int moneyi;
    double moneyd;
    char moneystr[100];
};

int main()
{
    union MoneyType money;
    money.moneyi = 99999;
    printf("%d\n", money.moneyi);
    money.moneyd = 99999.99;
    printf("%.2lf\n", money.moneyd);
    strcpy(money.moneystr, "100万");
    printf("%s\n", money.moneystr);//因为这里是定义完立马打印输出，看不出异常，但如果全部定义完后统一打印，
                                  //会发现只有moneystr是对的，其他的都被覆盖掉了，不是原本的值
	return 0;
}

/*
当一种数据可能有多种类型时，用共同体（也叫共用体、联合体）来定义
比如：钱可能为整数、小数、字符串
      成绩可能为整数、小数、字符（打等级的那种）
typedef union MoneyType//和结构体一样可以起别名
{
    int moneyi;//4
    double moneyd;//8
    char moneystr[100];//100
} MT;
整个共同体的字节大小为104，解释如下：
最大成员的长度为字符数组的100，但由于受内存对齐影响，还要看int、char、double这三者中最大的那一位的字节大小
在考虑内存对齐时，字符数组要看成若干个char，所以长度只有1
因此，共同体还得是double -> 8的整数倍，所以为104

共用体的特点：
所有的变量都使用同一个内存空间（和结构体最大的区别）
所占的内存大小 = 最大成员的长度（也受内存对齐影响）
每次只能给一个变量进行赋值，因为第二次赋值时会覆盖原有的数据
*/