#include<stdio.h>

int main()
{
    //int week;
    //printf("输入当前星期\n");
    //scanf("%d", &week);
    //switch(week)
    //{
    //    case 1:
    //        printf("克洛琳德");
    //        break;
    //    case 2:
    //        printf("阿蕾奇诺");
    //        break;
    //    case 3:
    //        printf("九条裟罗");
    //        break;
    //    case 4:
    //        printf("莱欧斯利");
    //        break;
    //    case 5:
    //        printf("那维莱特");
    //        break;
    //    case 6:
    //        printf("枫原万叶");
    //        break;
    //    case 7:
    //        printf("哥伦比娅");
    //        break;
    //    default:
    //        printf("不存在的星期！");
    //        break;
    //}

    ///*
    //case穿透的应用：
    //需求：键盘录入月份数，输出对应的季节
    //春季：3、4、5 月份
    //夏季：6、7、8 月份
    //秋季：9、10、11 月份
    //冬季：12 月份到次年的 2 月份
    //*/
    //int month;
    //printf("输入当前月份\n");
    //scanf("%d", &month);
    //switch (month)
    //{
    //    case 3:
    //    case 4:
    //    case 5:
    //        printf("春季");
    //        break;
    //    case 6:
    //    case 7:
    //    case 8:
    //        printf("夏季");
    //        break;
    //    case 9:
    //    case 10:
    //    case 11:
    //        printf("秋季");
    //        break;
    //    case 12:
    //    case 1:
    //    case 2:
    //        printf("冬季");
    //        break;
    //    default:
    //        printf("不存在的月份！");
    //        break;
    //}

    ////求1~100的偶数和
    //int sum = 0;
    //for (int i = 2; i <= 100; i+=2)
    //{
    //    sum += i;
    //}
    //printf("%d", sum);

    ///*
    //## 统计满足条件的数字
    //需求：键盘录入两个数字，表示一个范围,统计这个范围中既能被6整除又能被8整除数字有多少个？
    //*/
    //int count = 0;
    //int start;
    //int end;
    //printf("输入两个数字表示范围\n");
    //scanf("%d %d", &start, &end);
    ////考虑start可能大于end的情况
    //int min = start <= end ? start : end;
    //int max = start > end ? start : end;
    //for (int i = min; i <= max; i++)
    //{
    //    if (i % 6 == 0 && i % 8 == 0)
    //    {
    //        count++;
    //    }
    //}
    //printf("在这个范围中，既能被6整除又能被8整除数字有%d个", count);


    //简单循环算法题练习
    /*
    1.录入一个整数，判断其是否为2的幂次方
    */
    int num1;
    printf("输入一个整数\n");
    scanf("%d", &num1);
    int temp1 = num1;
    while (num1 > 1 && num1 % 2 == 0)
    {
        num1 /= 2;
    }
    if (num1 == 1)
    {
        printf("整数%d是2的幂次方\n", temp1);
    }
    else
    {
        printf("整数%d不是2的幂次方\n", temp1);
    }


    /*
    2.世界最高山峰是珠穆朗玛峰(8844.43米=8844430毫米)，假如我有一张足够大的纸，它的厚度是0.1毫米
    请问折叠多少次，可以折成珠穆朗玛峰的高度？
    */
    double num2 = 0.1;
    int count1 = 0;
    while (num2 < 8844430)
    {
        num2 *= 2;
        count1++;
    }
    printf("需要折叠%d次\n", count1);


    /*
    3.录入一个整数，输出反转后的结果
    123 -> 3、2、1 -> 3 * 100 + 2 * 10 + 1 * 1 -> 321
    */
    int num3;
    printf("录入一个整数\n");
    scanf("%d", &num3);
    int reverse = 0;
    while (num3 != 0)//用!=，负数同样适用；但如果用>，就只适用正数
    {
        //获取最右边一位数
        int temp = num3 % 10;
        //更新num3
        num3 /= 10;
        //粘贴到reverse中
        reverse = reverse * 10 + temp;
    }
    printf("反转后为：%d\n", reverse);


    /*
    4.返回非负整数x的算术平方根（结果只保留整数部分）
    4 -> 2    8 -> 2
    */
    int num4;
    printf("录入一个非负整数\n");
    scanf("%d", &num4);
    int i = 1;
    while (i * i <= num4)
    {
        i++;
    }
    printf("%d的算术平方根为：%d\n", num4, i - 1);


    /*
    5.判断一个数是否为回文数（正序倒序都一样）
    12321   45654
    */
    int num5;
    printf("录入一个整数\n");
    scanf("%d", &num5);
    int temp2 = num5;
    //反转之后和原数一样，就是回文数
    int rev = 0;
    while (num5 != 0)
    {
        int temp = num5 % 10;
        num5 /= 10;
        rev = rev * 10 + temp;
    }
    if (rev == temp2)
    {
        printf("是回文数\n");
    }
    else
    {
        printf("不是回文数\n");
    }


    /*
    6.两数相除
    两个整数，被除数 dividend 和除数 divisor
    将两数相除，要求不使用乘法、除法和取余运算
    返回被除数 dividend 除以除数 divisor 得到的商和余数
    如两个整数 11、3，输出结果：商3，余2
    */
    /*
    过程演算：
    11 - 3 = 8     8 - 3 = 5     5 - 3 = 2
    2小于除数3不能再减，2即为余数，做减法的次数即为商
    */
    int dividend;
    int divisor;
    printf("请输入两个整数作为被除数和除数\n");
    scanf("%d %d", &dividend, &divisor);
    int count = 0;
    while (dividend >= divisor)
    {
        dividend -= divisor;
        count++;
    }
    printf("商为：%d，余数为：%d", count, dividend);
	return 0;
}

/*
## switch语句：
switch(表达式) {
    case 值1:
        语句体1;
        break;
    case 值2:
        语句体2;
        break;
    ...
    default:
        语句体n;
        break;
}

执行流程：
I. 首先计算表达式的值。
II. 依次和 case 后面的值进行比较，如果有对应的值，就会执行相应的语句，在执行的过程中，遇到 break 就会结束。
III. 如果所有的 case 后面的值和表达式的值都不匹配，就会执行 default 里面的语句体，然后结束整个 switch 语句。
补充：
switch表达式只能是：int、char、short，不能是浮点型、字符串
case 后面只能写常量，不能写变量
break 作用：跳出 switch；如果省略 break，会发生case 穿透，继续往下执行后续 case 代码
default 位置可以随意放，规范一般写在末尾，不是必须写

case穿透的规则:
1.根据小括号中表达式的结果去匹配对应的case
2.执行对应case里面的代码
3.如果在执行的过程中, 遇到了break, 那么直接结束整个switch
但是如果没有遇到break, 就会继续执行下面case中的代码,
直到遇到break, 或者把整个switch中所有的代码全部执行完了, 才会结束
4.case穿透只会往下穿，不会回到上方
  如：如果匹配结果为default且都没有写break语句而default又不在最后一行，那么从default开始往下都会打印输出
*/

/*
循环：
变量的生命周期：变量只在所属的大括号中有效

## for和while的对比
相同点：运行规则都是一样的

for 和 while 的区别：
for循环中，控制循环的变量归属for循环，循环结束后，就不能再被访问到（但其实也可以把变量定义在外面，for循环中第一个冒号前就不写内容）
while循环中，控制循环的变量不归属其语法结构，在循环结束后还可以继续使用
所以本质区别是：
for循环使用场景：知道循环次数或者循环的范围
while循环使用场景：不知道循环的次数和范围，只知道循环的结束条件
*/

/*
do…while 循环执行流程：

初始化语句;
do {
    循环体语句;
    条件控制语句;
} while(条件判断语句);

先执行后判断，循环体至少执行一次
*/