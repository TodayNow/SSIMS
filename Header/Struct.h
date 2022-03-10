//
// Created by 南北 on 2022/3/10.
//

#ifndef SSIMS_STRUCT_H
#define SSIMS_STRUCT_H

#endif //SSIMS_STRUCT_H


typedef struct StuBasicInfo//学生基本信息
{
    long long stu_id;//学号
    char name[20];//姓名
    char gender[5];//性别
    char dom_id[20];//宿舍
    long long tel;//电话
    struct StuBasicInfo *next;//链接指针
} StuBas;

typedef struct StuGradeInfo//学生成绩信息
{
    long long stu_id;//学号
    char course_id[20];//课程编号
    char course_name[50];//课程名称
    float course_credit;//课程学分
    float grade_usual;//平时成绩
    float grade_exp;//实验成绩
    float grade_exam;//期末成绩
    float grade_final;//综合成绩
    float credit;//绩点【算法：credit=(usual*0.25)+(exp*0.35)+(exam*0.4)】
    struct StuGradeInfo *next;//链接指针
} StuGra;