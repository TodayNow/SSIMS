//
// Created by 南北 on 2022/3/10.
//

//#include "Struct.h"

#ifndef SSIMS_READ_H
#define SSIMS_READ_H

#endif //SSIMS_READ_H

StuBas *ReadBasic();//读入基础✓
StuGra *ReadGrade();//读入成绩✓
void WriteBasic(FILE *B,FILE *B_DB,StuBas *H);//写入基础✓
void WriteGrade(FILE *G,FILE *G_DB,StuGra *H);//写入成绩✓
void Clear();//清屏✓

StuBas *ReadBasic()
{
    StuBas *head,*node,*temp;//头节点，新增节点
    temp=(StuBas *) malloc(sizeof(StuBas));//创建新节点
    FILE *DB=fopen("StuBasDB.txt","r");//打开文件
    if(DB == NULL)
        printf("目标文件不存在！");
    fscanf(DB,"%lld%s%s%s%lld",&temp->stu_id,temp->name,temp->gender,temp->dom_id,&temp->tel);//格式读入
    temp->next=NULL;
    head=temp;//头节点指向新节点
    while(fgetc(DB) != EOF)//循环格式读入文件
    {
        node=(StuBas *) malloc(sizeof(StuBas));
        fscanf(DB,"%lld%s%s%s%lld",&node->stu_id,node->name,node->gender,node->dom_id,&node->tel);
        node->next=NULL;
        temp->next=node;
        temp=temp->next;
    }
    fclose(DB);
    return head;
}

StuGra *ReadGrade()
{
    StuGra *head,*node,*temp;//头节点，新增节点
    temp=(StuGra *) malloc(sizeof(StuGra));//创建新节点
    FILE *DB=fopen("StuGraDB.txt","r");//打开文件
    if(DB == NULL)
        printf("目标文件不存在！");
    fscanf(DB,"%lld%s%s%f%f%f%f%f%f",&temp->stu_id,temp->course_name,temp->course_id,&temp->course_credit,&temp->grade_usual,&temp->grade_exp,
           &temp->grade_exam,&temp->grade_final,&temp->credit);
    temp->next=NULL;
    head=temp;//头节点指向新节点
    while(fgetc(DB) != EOF)
    {
        node=(StuGra *) malloc(sizeof(StuGra));
        fscanf(DB,"%lld%s%s%f%f%f%f%f%f",&node->stu_id,node->course_name,node->course_id,&node->course_credit,&node->grade_usual,&node->grade_exp,
               &node->grade_exam,&node->grade_final,&node->credit);
        node->next=NULL;
        temp->next=node;
        temp=temp->next;
    }
    fclose(DB);
    return head;
}

void WriteBasic(FILE *B,FILE *B_DB,StuBas *H)
{
    while(H->next != NULL)//将链表全部写入文件中
    {
        fprintf(B,"学号：%lld\n姓名：%s\n性别：%s\n宿舍：%s\n电话：%lld\n\n",H->stu_id,H->name,H->gender,H->dom_id,H->tel);
        fprintf(B_DB,"%lld\n%s\n%s\n%s\n%lld\n\n",H->stu_id,H->name,H->gender,H->dom_id,H->tel);
        H=H->next;
    }
    fclose(B);
    fclose(B_DB);
}

void WriteGrade(FILE *G,FILE *G_DB,StuGra *H)
{
    while(H->next != NULL)//将链表全部写入文件中
    {
        fprintf(G,"学生学号：%lld\n课程名称：%s\n课程编号：%s\n课程学分：%4.2f\n平时得分：%4.2f\n实验得分：%4.2f\n期末得分：%4.2f\n最终得分：%4.2f\n所获绩点：%4.2f\n\n",H->stu_id,H->course_name,
                H->course_id,H->course_credit,H->grade_usual,H->grade_exp,H->grade_exam,H->grade_final,H->credit);
        fprintf(G_DB,"%lld\n%s\n%s\n%4.2f\n%4.2f\n%4.2f\n%4.2f\n%4.2f\n%4.2f\n\n",H->stu_id,H->course_name,H->course_id,H->course_credit,
                H->grade_usual,H->grade_exp,H->grade_exam,H->grade_final,H->credit);
        H=H->next;
    }
    fclose(G);
    fclose(G_DB);
}

void Clear()
{
#ifdef _WIN32//判断操作系统为Windows
    system("cls");
#elif __APPLE__//判断操作系统为macOS
    system("clear");
#endif
}
