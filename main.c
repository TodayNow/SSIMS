//头文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header/Struct.h"//结构体
#include "Header/SSIMSRW.h"//项目输入输出
#include "Header/Sort.h"//并归排序
//全局变量
int choice1;//第一次选择
int choice2;//第二次选择
int choice3;//第三次选择
int choice4;//第四次选择
//菜单模块
void FirstMenu();//主菜单✓
void SecondMenu();//二级菜单✓
void ThirdMenu();//三级菜单✓
//程序模块
void InputBasic();//录入基础✓
void InputGrade();//录入成绩✓
void LookUpBasic();//查找基础✓
void LookUpGrade();//查找成绩✓
void SortBasic();//排序基础✓
void SortGrade();//排序成绩✓
void Delete();//删除✓

int main()
{
    FirstMenu();
    printf("====================\n");
    return 0;
}

void InputBasic()
{
    StuBas *head,*temp,*node;//头节点，新增节点
    head=NULL;
    temp=(StuBas *) malloc(sizeof(StuBas));//创建新节点
    //以下为节点信息输入
    printf("===============\n");
    printf("请输入\n学号：");
    scanf("%lld",&temp->stu_id);
    printf("姓名：");
    scanf("%s",temp->name);
    printf("性别：");
    scanf("%s",temp->gender);
    printf("宿舍号：");
    scanf("%s",temp->dom_id);
    printf("电话：");
    scanf("%lld",&temp->tel);
    printf("===============\n");
    //节点信息输入完成
    temp->next=NULL;
    head=temp;//头指针指向新增指针
    while(temp->stu_id != 0)//循环创建新节点
    {
        node=(StuBas *) malloc(sizeof(StuBas));//创建新节点
        printf("===============\n");
        printf("请输入\n学号：");
        scanf("%lld",&node->stu_id);//新节点学号
        if(node->stu_id == 0)break;//判定，学号为0结束新增节点，该节点不连入链表
        //以下为节点信息输入
        printf("姓名：");
        scanf("%s",node->name);
        printf("性别：");
        scanf("%s",node->gender);
        printf("宿舍号：");
        scanf("%s",node->dom_id);
        printf("电话：");
        scanf("%lld",&node->tel);
        printf("===============\n");
        //节点信息输入完成
        node->next=NULL;
        temp->next=node;//新增节点连入链表
        temp=temp->next;
    }
    FILE *Basic=fopen("学生基础信息.txt","a+");
    FILE *Basic_DB=fopen("StuBasDB.txt","a+");//打开数据文件，以追加的方式写入
    if(Basic == NULL || Basic_DB == NULL)
        printf("打开文件失败！");
    StuBas *end=(StuBas *) malloc(sizeof(StuGra));
    temp->next=end;//尾节点
    WriteBasic(Basic,Basic_DB,head);//链表全部写入文件
    printf("数据录入成功！\n返回主菜单(U)或退出(E)\n");
    char ant_key;
    scanf("%s",&ant_key);
    switch(ant_key)
    {
        case 'u':
        case 'U':
            FirstMenu();
            break;
        case 'e':
        case 'E':
            break;
    }
}

void InputGrade()
{
    StuGra *head,*temp,*node;//头节点，新增节点
    head=NULL;
    temp=(StuGra *) malloc(sizeof(StuGra));//创建新节点
    //以下为节点信息输入
    printf("====================\n");
    printf("请输入\n学号：");
    scanf("%lld",&temp->stu_id);
    printf("课程：");
    scanf("%s",temp->course_name);
    printf("课程编号：");
    scanf("%s",temp->course_id);
    printf("课程学分：");
    scanf("%f",&temp->course_credit);
    printf("平时分：");
    scanf("%f",&temp->grade_usual);
    printf("实验分：");
    scanf("%f",&temp->grade_exp);
    printf("期末分：");
    scanf("%f",&temp->grade_exam);
    temp->grade_final=temp->grade_usual*0.25+temp->grade_exp*0.35+temp->grade_exam*0.4;
    if(temp->grade_final >= 60)
        temp->credit=temp->grade_final/10-5;
    else
        temp->credit=0.0;
    printf("====================\n");
    //节点信息输入完成
    temp->next=NULL;
    head=temp;//头指针指向新增指针
    while(temp->stu_id != 0)//循环创建新节点
    {
        node=(StuGra *) malloc(sizeof(StuGra));//创建新节点
        printf("===================\n");
        printf("请输入\n学号：");
        scanf("%lld",&node->stu_id);//新节点学号
        if(node->stu_id == 0)break;//判定，学号为0结束新增节点，该节点不连入链表
        //以下为节点信息输入
        printf("课程名称：");
        scanf("%s",node->course_name);
        printf("课程编号：");
        scanf("%s",node->course_id);
        printf("课程学分：");
        scanf("%f",&node->course_credit);
        printf("平时分：");
        scanf("%f",&node->grade_usual);
        printf("实验分：");
        scanf("%f",&node->grade_exp);
        printf("期末分：");
        scanf("%f",&node->grade_exam);
        printf("====================\n");
        node->grade_final=node->grade_usual*0.25+node->grade_exp*0.35+node->grade_exam*0.4;
        if(node->grade_final >= 60)
            node->credit=node->grade_final/10-5;
        else
            node->credit=0.0;
        //节点信息输入完成
        node->next=NULL;
        temp->next=node;//新增节点连入链表
        temp=temp->next;
    }
    FILE *Grade=fopen("学生成绩信息.txt","a+");
    FILE *Grade_DB=fopen("StuGraDB.txt","a+");//打开数据文件，以追加的方式写入
    if(Grade == NULL || Grade_DB == NULL)
        printf("打开文件失败！");
    StuGra *end=(StuGra *) malloc(sizeof(StuGra));
    temp->next=end;//尾节点
    WriteGrade(Grade,Grade_DB,head);//链表全部写入文件
    printf("数据录入成功！\n返回主菜单(U)或退出(E)\n");
    char ant_key;
    scanf("%s",&ant_key);
    switch(ant_key)
    {
        case 'u':
        case 'U':
            FirstMenu();
            break;
        case 'e':
        case 'E':
            break;
    }
}

void LookUpBasic()
{
    long long stu_id;
    char stu_name[20]={'\0'},dom_id[20]={'\0'};
    int count=0;
    char error;
    StuBas *head_bas=ReadBasic();//读入基础信息，写入链表
    switch(choice3)
    {
        case 1:
            printf("请输入学号：\n");
            scanf("%lld",&stu_id);
            while(head_bas->next != NULL)//遍历节点
            {
                if(head_bas->stu_id == stu_id)//寻找目标学号
                {
                    printf("学号：%lld\n姓名：%s\n性别：%s\n宿舍：%s\n电话：%lld\n\n",head_bas->stu_id,head_bas->name,head_bas->gender,head_bas->dom_id,
                           head_bas->tel);
                    count++;
                }
                head_bas=head_bas->next;
            }
            if(count == 0)//错误处理
            {
                printf("该学号不存在，请退出(E)或返回上一级(U)。\n");
                scanf("%s",&error);
                switch(error)
                {
                    case 'e':
                    case 'E':
                        break;
                    case 'u':
                    case 'U':
                        SecondMenu();
                        break;
                }
            }
            break;
        case 2:
            printf("请输入姓名：\n");
            scanf("%s",stu_name);
            while(head_bas->next != NULL)//遍历节点
            {
                if(strcmp(head_bas->name,stu_name) == 0)//寻找目标名字
                {
                    printf("学号：%lld\n姓名：%s\n性别：%s\n宿舍：%s\n电话：%lld\n\n",head_bas->stu_id,head_bas->name,head_bas->gender,head_bas->dom_id,
                           head_bas->tel);
                    count++;
                }
                head_bas=head_bas->next;
            }
            if(count == 0)//错误处理
            {
                printf("该学生不存在，请退出(E)或返回上一级(U)。\n");
                scanf("%s",&error);
                switch(error)
                {
                    case 'e':
                    case 'E':
                        break;
                    case 'u':
                    case 'U':
                        SecondMenu();
                        break;
                }
            }
            break;
        case 3:
            printf("请输入宿舍：\n");
            scanf("%s",dom_id);
            while(head_bas->next != NULL)//遍历节点
            {
                if(strcmp(head_bas->dom_id,dom_id) == 0)//寻找目标宿舍
                {
                    printf("学号：%lld\n姓名：%s\n性别：%s\n宿舍：%s\n电话：%lld\n\n",head_bas->stu_id,head_bas->name,head_bas->gender,head_bas->dom_id,
                           head_bas->tel);
                    count++;
                }
                head_bas=head_bas->next;
            }
            if(count == 0)//错误处理
            {
                printf("该寝室不存在，请退出(E)或返回上一级(U)。\n");
                scanf("%s",&error);
                switch(error)
                {
                    case 'e':
                    case 'E':
                        break;
                    case 'u':
                    case 'U':
                        SecondMenu();
                        break;
                }
            }
            break;
    }
    printf("数据查询结束！\n返回主菜单(U)或退出(E)\n");
    char ant_key;
    scanf("%s",&ant_key);
    switch(ant_key)
    {
        case 'u':
        case 'U':
            FirstMenu();
            break;
        case 'e':
        case 'E':
            break;
    }
}

void LookUpGrade()
{
    StuGra *head_gra=ReadGrade();
    StuBas *head_bas=ReadBasic();//调用读入函数把两个数据文件分别读入链表中
    long long stu_id;
    int count1=0,count2=0;
    char error,stu_name[20];
    switch(choice3)
    {
        case 1:
            printf("请输入学号：\n");
            scanf("%lld",&stu_id);
            while(head_gra->next != NULL)
            {
                if(head_gra->stu_id == stu_id)
                {
                    printf("学生学号：%lld\n课程名称：%s\n课程编号：%s\n课程学分：%4.2f\n平时得分：%4.2f\n实验得分：%4.2f\n期末得分：%4.2f\n最终得分：%4.2f\n所获绩点：%4.2f\n\n",head_gra->stu_id,
                           head_gra->course_name,head_gra->course_id,head_gra->course_credit,head_gra->grade_usual,head_gra->grade_exp,
                           head_gra->grade_exam,head_gra->grade_final,head_gra->credit);
                    count1++;
                }
                head_gra=head_gra->next;
            }
            if(count1 == 0)//错误判断
            {
                printf("该学生不存在，请退出(E)或返回上一级(U)。\n");
                scanf("%s",&error);
                switch(error)
                {
                    case 'e':
                    case 'E':
                        break;
                    case 'u':
                    case 'U':
                        SecondMenu();
                        break;
                }
            }
            break;
        case 2:
            printf("请输入姓名：\n");
            scanf("%s",stu_name);
            while(head_bas->next != NULL)//外层循环，遍历基础信息节点
            {
                if(strcmp(head_bas->name,stu_name) == 0)//寻找用户指定的学生
                {
                    count1++;
                    while(head_gra->next != NULL)//内层循环，遍历成绩信息节点
                    {
                        if(head_gra->stu_id == head_bas->stu_id)//利用外层循环找到的名字对应的学号，来寻找成绩节点中的对应学生学号
                        {
                            count2++;
                            printf("学生学号：%lld\n课程名称：%s\n课程编号：%s\n课程学分：%4.2f\n平时得分：%4.2f\n实验得分：%4.2f\n期末得分：%4.2f\n最终得分：%4.2f\n所获绩点：%4.2f\n\n",
                                   head_gra->stu_id,
                                   head_gra->course_name,head_gra->course_id,head_gra->course_credit,head_gra->grade_usual,head_gra->grade_exp,
                                   head_gra->grade_exam,head_gra->grade_final,head_gra->credit);
                        }
                        head_gra=head_gra->next;
                    }
                }
                head_bas=head_bas->next;
            }
            if(count1 == 0)//错误处理
            {
                printf("该学生不存在，请退出(E)或返回上一级(U)。\n");
                scanf("%s",&error);
                switch(error)
                {
                    case 'e':
                    case 'E':
                        break;
                    case 'u':
                    case 'U':
                        SecondMenu();
                        break;
                }
            }
            else
                if(count2 == 0)
                {
                    printf("该学生存在，但未登记成绩，请退出(E)或返回上一级(U)。\n");
                    scanf("%s",&error);
                    switch(error)
                    {
                        case 'e':
                        case 'E':
                            break;
                        case 'u':
                        case 'U':
                            SecondMenu();
                            break;
                    }
                }
            break;
        case 3:
            printf("暂不支持以寝室为关键字查询成绩！请退出(E)或返回上一级(U)。\n");//略略路，咱就是说，不要没事干偷偷内卷室友！！
            scanf("%s",&error);
            switch(error)
            {
                case 'e':
                case 'E':
                    break;
                case 'u':
                case 'U':
                    SecondMenu();
                    break;
            }
            break;
    }
    printf("数据查询结束！\n返回主菜单(U)或退出(E)\n");
    char ant_key;
    scanf("%s",&ant_key);
    switch(ant_key)
    {
        case 'u':
        case 'U':
            FirstMenu();
            break;
        case 'e':
        case 'E':
            break;
    }
}

void SortBasic()
{
    StuBas *head=ReadBasic();
    StuBas *NewHead=MergeSort_B(head);
    while(NewHead->next != NULL)
    {
        if(NewHead->stu_id != 0)
            printf("学号：%lld\n姓名：%s\n性别：%s\n宿舍：%s\n电话：%lld\n\n",NewHead->stu_id,NewHead->name,NewHead->gender,NewHead->dom_id,NewHead->tel);
        NewHead=NewHead->next;
    }
    printf("排序结束，请按U并回车返回主菜单……\n");
    fflush(stdin);
    char any_keys;
    any_keys=getchar();
    FirstMenu();
}

void SortGrade()
{
    StuGra *head=ReadGrade();
    StuGra *NewHead=MergeSort_G(head);
    while(NewHead->next != NULL)
    {
        if(NewHead->stu_id != 0)
            printf("学生学号：%lld\n课程名称：%s\n课程编号：%s\n课程学分：%4.2f\n平时得分：%4.2f\n实验得分：%4.2f\n期末得分：%4.2f\n最终得分：%4.2f\n所获绩点：%4.2f\n\n",NewHead->stu_id,
                   NewHead->course_name,NewHead->course_id,NewHead->course_credit,NewHead->grade_usual,NewHead->grade_exp,NewHead->grade_exam,
                   NewHead->grade_final,NewHead->credit);
        NewHead=NewHead->next;
    }
    printf("排序结束，请按U并回车返回主菜单……\n");
    fflush(stdin);
    char any_keys;
    any_keys=getchar();
    FirstMenu();
}

void Delete()
{
    long long stu_id;//学号
    char stu_name[20]={'\0'};//姓名
    char confirm='N';
    StuBas *head_bas=ReadBasic();//读入文件并载入链表，head为头指针
    StuBas *temp_bas=head_bas;//基础信息主操作指针
    StuBas *former_bas=head_bas;//操作指针节点的前驱节点
    StuGra *head_gra=ReadGrade();//读入文件并载入链表，head为头指针
    StuGra *temp_gra=head_gra;//成绩信息主操作指针
    StuGra *former_gra=head_gra;//操作指针节点的前驱节点
    //！！警告！！
    Clear();
    printf("！！！请注意，禁止中止本功能的执行，即您在下一次操作确认中确认执行后，不要提前中止本程序的运行，否则将丢失全部数据信息！！！\n"
           "！！！请注意，禁止中止本功能的执行，即您在下一次操作确认中确认执行后，不要提前中止本程序的运行，否则将丢失全部数据信息！！！\n"
           "！！！请注意，禁止中止本功能的执行，即您在下一次操作确认中确认执行后，不要提前中止本程序的运行，否则将丢失全部数据信息！！！\n");
    printf("即将开始运行删除数据程序，请确认是否继续(Y/N)，这是最后一次操作确认：\n");
    scanf("%s",&confirm);
    if(confirm == 'y' || confirm == 'Y')
    {
        //数据及展示文件读入
        FILE *Basic_DB=fopen("StuBasDB.txt","w");
        FILE *Basic=fopen("学生基础信息.txt","w");
        FILE *Grade_DB=fopen("StuGraDB.txt","w");
        FILE *Grade=fopen("学生成绩信息.txt","w");
        Clear();
        printf("\n");
        printf("===============学生学籍信息管理系统===============\n"
               "\n"
               "                    信息删除\n"
               "\n"
               "               1.删除学生全部信息\n"
               "               2.删除学生成绩信息\n"
               "               3.保留信息退出\n"
               "             请选择操作，并以回车键继续\n"
               "===============================================\n");
        scanf("%d",&choice4);
        switch(choice4)
        {
            case 1:
                printf("！！请注意，该操作会删除学生基础信息及其关联的全部成绩信息！！\n");//操作警告
                printf("请输入学生学号：\n");
                scanf("%lld",&stu_id);
                while(temp_bas->next != NULL)//在基础信息链表中查找目标节点
                {
                    if(temp_bas->stu_id != stu_id)//找到目标节点和其前驱节点
                    {
                        former_bas=temp_bas;
                        temp_bas=temp_bas->next;
                    }
                    else
                        if(temp_bas == head_bas)//头节点情况
                        {
                            head_bas=head_bas->next;
                            temp_bas=temp_bas->next;
                        }
                        else//其他节点情况
                        {
                            former_bas->next=temp_bas->next;
                            temp_bas=former_bas->next;
                        }
                }
                while(temp_gra->next != NULL)//在成绩信息链表中查找目标节点
                {
                    if(temp_gra->stu_id != stu_id)//找到目标节点和其前驱节点
                    {
                        former_gra=temp_gra;
                        temp_gra=temp_gra->next;
                    }
                    else
                        if(temp_gra == head_gra)//头节点情况
                        {
                            head_gra=head_gra->next;
                            temp_gra=head_gra;
                        }
                        else//其他节点情况
                        {
                            former_gra->next=temp_gra->next;
                            temp_gra=former_gra->next;
                        }
                }
                WriteBasic(Basic,Basic_DB,head_bas);//链表全部写入文件
                WriteGrade(Grade,Grade_DB,head_gra);//链表全部写入文件
                break;
            case 2:
                printf("请输入姓名：\n");
                scanf("%s",stu_name);
                while(temp_bas->next != NULL)//遍历基础信息
                {
                    if(strcmp(temp_bas->name,stu_name) == 0)//查找对应学号
                    {
                        while(temp_gra->next != NULL)//遍历成绩信息
                        {
                            if(temp_gra->stu_id != temp_bas->stu_id)//查找目标节点和其前驱节点
                            {
                                former_gra=temp_gra;
                                temp_gra=temp_gra->next;
                            }
                            else
                                if(temp_gra == head_gra)//头节点情况
                                {
                                    head_gra=head_gra->next;
                                    temp_gra=head_gra;
                                }
                                else//其他节点情况
                                {
                                    former_gra->next=temp_gra->next;
                                    temp_gra=former_gra->next;
                                }
                        }
                    }
                    temp_bas=temp_bas->next;
                }
                WriteBasic(Basic,Basic_DB,head_bas);//链表全部写入文件
                WriteGrade(Grade,Grade_DB,head_gra);//链表全部写入文件
                break;
            case 3:
                WriteBasic(Basic,Basic_DB,head_bas);//链表全部写入文件
                WriteGrade(Grade,Grade_DB,head_gra);//链表全部写入文件
                break;
        }
    }
    else
    {
        printf("您取消了操作，没有数据被更改，按U并回车返回主菜单……\n");
        fflush(stdin);
        char any_keys;
        any_keys=getchar();
        FirstMenu();
    }
}

void FirstMenu()
{
    Clear();
    printf("\n");
    printf("===============学生学籍信息管理系统===============\n"
           "\n"
           "                      首页\n"
           "\n"
           "                   1.录入信息\n"
           "                   2.查询信息\n"
           "                   3.信息排序\n"
           "                   4.删除信息\n"
           "                   5.退出系统\n"
           "             请选择操作，并以回车键继续\n"
           "===============================================\n");
FirstRetry:
    scanf("%d",&choice1);
    switch(choice1)//1-3选择全部调用SecondMenu()进入二级菜单，或者退出系统
    {
        case 1:
        case 2:
        case 3:
            SecondMenu();
            break;
        case 4:
            Delete();
            break;
        case 5:
            break;
        default:
            printf("您的输入有误请重试：");
            goto FirstRetry;//输入超出给定范围则提示重新输入，同时控制流跳转回输入前，直到输入正确为止
    }
}

void SecondMenu()
{
    Clear();
    printf("\n");
    printf("===============学生学籍信息管理系统===============\n"
           "\n"
           "                    信息系统\n"
           "\n"
           "                   1.基础信息\n"
           "                   2.成绩信息\n"
           "                   3.退出系统\n"
           "                   4.返回上一级\n"
           "             请选择操作，并以回车键继续\n"
           "===============================================\n");
SecondRetry:
    scanf("%d",&choice2);
    switch(choice1)//先判断第一次的选择，进入对应的case后判断第二次的选择，调用对应的函数，或者退出系统
    {
        case 1://录入
            switch(choice2)
            {
                case 1:
                    InputBasic();
                    break;
                case 2:
                    InputGrade();
                    break;
                case 3:
                    break;
                case 4:
                    FirstMenu();
                    break;
                default:
                    printf("您的输入有误请重试：");
                    goto SecondRetry;//输入超出给定范围则提示重新输入，同时控制流跳转回输入前，直到输入正确为止
            }
            break;
        case 2://查询
            switch(choice2)
            {
                case 1:
                case 2:
                    ThirdMenu();
                    break;
                case 3:
                    break;
                case 4:
                    FirstMenu();
                    break;
                default:
                    printf("您的输入有误请重试：");
                    goto SecondRetry;//输入超出给定范围则提示重新输入，同时控制流跳转回输入前，直到输入正确为止
            }
            break;
        case 3://排序
            switch(choice2)
            {
                case 1:
                    SortBasic();
                    break;
                case 2:
                    SortGrade();
                    break;
                case 3:
                    break;
                case 4:
                    FirstMenu();
                    break;
                default:
                    printf("您的输入有误请重试：");
                    goto SecondRetry;//输入超出给定范围则提示重新输入，同时控制流跳转回输入前，直到输入正确为止
            }
            break;
        default:
            printf("您的输入有误请重试：");
            goto SecondRetry;//输入超出给定范围则提示重新输入，同时控制流跳转回输入前，直到输入正确为止
    }
}

void ThirdMenu()
{
    Clear();
    printf("\n");
    printf("===============学生学籍信息管理系统===============\n"
           "\n"
           "                    查询系统\n"
           "\n"
           "                  1.按学号查询\n"
           "                  2.按姓名查询\n"
           "                  3.按宿舍查询\n"
           "             请选择操作，并以回车键继续\n"
           "===============================================\n");
    scanf("%d",&choice3);
    switch(choice2)//先判断第二次的选择，进入对应的case后判断第三次的选择，调用对应的函数
    {
        case 1://基础
            switch(choice3)
            {
                case 1:
                case 2:
                case 3:
                    LookUpBasic();
                    break;
            }
            break;
        case 2://成绩
            switch(choice3)
            {
                case 1:
                case 2:
                case 3:
                    LookUpGrade();
                    break;
            }
    }
}
