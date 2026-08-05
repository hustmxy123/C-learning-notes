#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct GirlFriend
{
    char name[100];
    int age;
    char gender;
    double height;//最后一个变量也要加分号
};//结构体末尾也要加分号
/*
结构体可以写在函数内部（局部位置，只能在本函数中使用）
也可以写在所有函数上方（全局位置，在所有函数中都可以使用，通常选这个）
*/

struct Student
{
    char name[100];
    int age;
};

typedef struct GameCharacter
{
    char name[100];
    int attack;
    int defend;
    int blood;
}GC;

typedef struct Message
{
    char phone[12];//手机号11位，还要加上结束标记'0'
    char email[100];
} M;

typedef struct Student2
{
    char name[100];
    int age;
    char gender;
    double height;
    M msg;//结构体的嵌套
}S2;

//投票选举例题结构体
struct spot
{
    char name[10];
    int count;
};

void method(struct Student* p);//函数声明写在结构体下面，因为可能要用到某个结构体

int main()
{
    struct GirlFriend gf1;
    strcpy(gf1.name, "小诗诗");//相当于把名字这个字符串复制到name这个字符数组中，所以要用到字符串函数，而不是单纯赋值
    //因为字符数组参与运算会退化为地址，所以不能直接赋值，两边类型都不对等
    gf1.age = 21;
    gf1.gender = 'F';
    gf1.height = 1.60;
    printf("她的名字是：%s\n", gf1.name);
    printf("她的年龄是：%d\n", gf1.age);
    printf("她的性别是：%c\n", gf1.gender);
    printf("她的身高是：%.2lf\n", gf1.height);

    /*
    定义一个结构体表示学生，学生的属性有：姓名、年龄
    要求：把三个学生信息放入到数组当中，并遍历数组
    */
    //结构体已定义在上方，现在赋值
    struct Student stu1 = { "zhangsan",23 };//定义的同时就把值也赋了，还不用调用strcpy方法
    struct Student stu2 = { "lisi",24 };
    struct Student stu3 = { "wangwu",25 };
    //存入数组并遍历
    struct Student arrStu[] = { stu1,stu2,stu3 };
    for (int i = 0; i < 3; i++)
    {
        printf("学生姓名：%s  \t学生年龄：%d\n", arrStu[i].name, arrStu[i].age);
    }

    /*
    定义一个结构体表示游戏人物
    属性有：姓名、攻击力、防御力、血量
    要求：把三个游戏人物放入到数组当中，并遍历数组
    */
    GC gc1 = { "克洛琳德",2500,920,17000 };
    GC gc2 = { "阿蕾奇诺",2300,800,15000 };
    GC gc3 = { "丝柯克",2200,900,18000 };
    GC arrGc[] = { gc1,gc2,gc3 };
    for (int i = 0; i < 3; i++)
    {
        printf("角色姓名：%s\t角色攻击力：%d\t角色防御力：%d  \t角色血量：%d\n", arrGc[i].name, arrGc[i].attack, arrGc[i].defend, arrGc[i].blood);
    }

    /*
    定义一个结构体表示学生，学生的属性：姓名、年龄
    要求：定义一个函数，修改学生中的数据
    */
    //结构体用现成的即可
    struct Student stu4;
    strcpy(stu4.name, "zhangsan");
    stu4.age = 23;
    printf("学生初始信息为：%s %d\n", stu4.name, stu4.age);
    //在main函数下方定义一个函数method用来修改学生信息，调用函数
    method(&stu4);
    printf("修改后的学生信息为：%s %d\n", stu4.name, stu4.age);

    /*
    定义一个结构体表示学生 Student
    Student 成员如下：
    名字、年龄、性别、身高、联系方式
    联系方式 Message 也是一个结构体，成员如下：
    手机号、电子邮箱
    */
    //赋值学生信息
    S2 stu5;
    strcpy(stu5.name, "zhangsan");
    stu5.age = 23;
    stu5.gender = 'M';
    stu5.height = 1.73;
    strcpy(stu5.msg.phone, "18182734893");//只要是字符数组都需要调用strcpy，不是只有名字才要
    strcpy(stu5.msg.email, "181827@qq.com");
    //打印学生信息
    printf("学生姓名为：%s\n", stu5.name);
    printf("学生年龄为：%d\n", stu5.age);
    printf("学生性别为：%c\n", stu5.gender);
    printf("学生身高为：%.2lf\n", stu5.height);
    printf("学生手机号为：%s\n", stu5.msg.phone);
    printf("学生邮箱为：%s\n", stu5.msg.email);
    //更简便的写法：定义的同时赋值
    S2 stu6 = { "lisi",22,'M',1.77,{"17382937463","8372638463@qq.com"} };//手机号和邮箱属于结构体嵌套的内容，定义时大括号也要嵌套一层
    //打印学生信息
    printf("学生姓名为：%s\n", stu6.name);
    printf("学生年龄为：%d\n", stu6.age);
    printf("学生性别为：%c\n", stu6.gender);
    printf("学生身高为：%.2lf\n", stu6.height);
    printf("学生手机号为：%s\n", stu6.msg.phone);
    printf("学生邮箱为：%s\n", stu6.msg.email);

    /*
    结构体综合练习 -- 投票选举
    某班级组织野外郊游，想要在 ABCD 四个景点选择其中一个。现在班上有 80 名同学进行投票，找出投票数最多的景点
    要求：1.学生投票，用随机数模拟
          2.如果多个景点投票一样的话，A 优先 B，B 优先于 C，C 优先于 D
    */
    //把景点spot的结构体定义在上方，包括景点名称name和投票数count
    //第一步：初始化景点数组 
    struct spot arrSpot[4] = { {'A', 0}, {'B',0}, {'C',0}, {'D',0} };//类似python中的字典键值对，其实这种靠结构体模拟键值对的做法在考试竞赛中很常见
    //第二步：打印，做完一步检查一步（后续投票结果其实也是这个循环搞定）
    for (int i = 0; i < 4; i++)
    {
        printf("%s %d\n", arrSpot[i].name, arrSpot[i].count);
    }
    //第三步：设置随机数模拟投票
    srand(time(NULL));
    for (int i = 0; i < 80; i++)//80名同学，投票80次
    {
        int choose = rand() % 4;//投票结果为0~3，有两层含义：
                                //1.  0 -> A   1 -> B   2 -> C   3 -> D
                                //2.对应arrSpot数组的索引，方便后续获取name和count等操作
        arrSpot[choose].count++;//无需if判断了，choose帮我们完成了同样目的
    }
    //第四步：获取投票最多的景点票数
    int max = arrSpot[0].count;
    for (int i = 0; i < 4; i++)
    {
        if (arrSpot[i].count > max)
        {
            max = arrSpot[i].count;
        }
    }
    //第五步：打印验证
    printf("最大票数为：%d\n", max);
    for (int i = 0; i < 4; i++)
    {
        printf("%s %d\n", arrSpot[i].name, arrSpot[i].count);
    }
    //第六步：考虑票数相同情况下的优先级
    for (int i = 0; i < 4; i++)
    {
        if (arrSpot[i].count == max)
        {
            printf("最终选择景点：%s\n", arrSpot[i].name);
            break;
        }
    }
	return 0;
}

void method(struct Student* p)
{
    printf("请输入修改后的学生名字：\n");
    scanf("%s", (*p).name);//name本身是字符数组，会退化为指针，所以不需加&
    printf("请输入修改后的学生年龄：\n");
    scanf("%d", &((*p).age));//age只是整型变量，别忘了加&!
}

/*
结构体可以理解为自定义的数据类型，它是由一批数据组合而成的结构型数据，里面的每一个数据都是结构体的 “成员”

struct GirlFriend
{
    char name[100];
    int age;
    char gender;
    double height;
};
注：末尾的分号;不能丢，C 语言结构体定义结尾必须加分号，很容易漏写报错
*/

/*
起别名：
typedef struct GirlFriend
{
    成员1;
    成员2;
    ...
} 别名;

例：
typedef struct GirlFriend    //其实这里的GirlFriend也可以省略
{
    char name[20];
    int age;
} GF;

GF g;   //等价于 struct GirlFriend g;
*/

/*
结构体作为函数参数
函数中可以传递结构体
两种情况：
传递结构体中的数据值（值传递），不会改变main函数中结构体的值，意义不大
传递结构体的地址值（地址 / 指针传递），同步修改main函数中结构体的值，指针的强大再次体现
*/

/*
如果结构体中成员的类型是其他的结构体，就用到了结构体的嵌套
#include <stdio.h>

//先定义子结构体
typedef struct Address
{
    char city[20];
} Address;

//外层结构体，成员是另一个结构体
typedef struct Student
{
    char name[20];
    int age;
    Address addr;   //结构体嵌套
} Student;

int main(void)
{
    Student s = {"张三",18,{"重庆"}};
    //访问嵌套成员：. 连续点
    printf("%s , %d , %s\n", s.name, s.age, s.addr.city);
    return 0;
}

访问嵌套结构体成员：变量.外层成员.内层成员
如果是结构体指针：指针->外层成员.内层成员，示例如下：
#include <stdio.h>

//内层结构体
typedef struct Message
{
    char phone[20];
} Message;

//外层结构体
typedef struct Student
{
    char name[20];
    Message contact;
} Student;

int main(void)
{
    Student s = {"小明", {"13912345678"}};

    Student *p = &s;   // p是结构体指针

    //->：指针访问结构体外层成员
    //.：外层得到的还是普通结构体变量，继续用点访问内层
    printf("手机号：%s\n", p->contact.phone);

    return 0;
}
*/

/*
结构体的内存对齐现象：（假设内存空间划分为从0开始的连续小格）
struct num
{
    double a;//0是8的整数倍，所以变量a放在0~7格
    char b;//8是1的整数倍，所以变量b放在8格
    int c;//9不是4的整数倍，要顺延到12，所以变量c放在12~15格
    char d;//16是1的整数倍，所以变量d放在16格
};
//总共0~16，有17格
//但又要求：结构体最大成员是 double 占 8 字节，整体总大小必须是 8 的整数倍，所以这个结构体最终大小：24 字节

总结，结构体内存对齐遵循两个原则：
1.确定变量位置：只能放在自己类型整数倍的内存地址上
2.最后一个补位：结构体的总大小，是最大类型的整数倍

基于此，我们通常在定义结构体时，会按数据类型的字节从小到大排序，从上往下定义变量，更节约内存空间
*/