//
// Created by 南北 on 2022/3/10.
//

//#include "Struct.h"

#ifndef SSIMS_SORT_H
#define SSIMS_SORT_H

#endif //SSIMS_SORT_H

//StudentBasicInformation
StuBas *MergeSort_B(StuBas *head);//并归排序
StuBas *GetMid_B(StuBas *head);//快慢指针找中间节点
StuBas *Merge_B(StuBas *head1,StuBas *head2);//有序链表合并
//StudentGradeInformation
StuGra *MergeSort_G(StuGra *head);//并归排序
StuGra *GetMid_G(StuGra *head);//快慢指针找中间节点
StuGra *Merge_G(StuGra *head1,StuGra *head2);//有序链表合并


//StudentBasicInformation
StuBas *MergeSort_B(StuBas *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    StuBas *head1=head;
    StuBas *head2=GetMid_B(head);  //获取中间节点，将链表分为两段
    head1=MergeSort_B(head1);   //分别对两段链表进行排序
    head2=MergeSort_B(head2);
    return Merge_B(head1,head2);  //将两段有序链表合并
}

StuBas *Merge_B(StuBas *head1,StuBas *head2) //合并两个有序链表
{
    StuBas *NewHead=(StuBas *) malloc(sizeof(StuBas));
    StuBas *NewTail=NewHead;
    while(head1 && head2)
    {
        if(head1->stu_id <= head2->stu_id)
        {
            NewTail->next=head1;
            head1=head1->next;
        }
        else
        {
            NewTail->next=head2;
            head2=head2->next;
        }
        NewTail=NewTail->next;
        NewTail->next=NULL;
    }
    if(head1) NewTail->next=head1;
    if(head2) NewTail->next=head2;
    return NewHead->next;  //链表头节点
}

StuBas *GetMid_B(StuBas *head)  //获取中间节点并分段
{
    StuBas *fast=head->next;
    StuBas *slow=head->next;
    StuBas *prev=head;
    while(1)
    {
        if(fast == NULL) break;
        fast=fast->next;
        if(fast == NULL) break;
        fast=fast->next;

        prev=slow;
        slow=slow->next;
    }
    prev->next=NULL;  //将链表分为两段
    return slow;
}

//StudentGradeInformation
StuGra *MergeSort_G(StuGra *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    StuGra *head1=head;
    StuGra *head2=GetMid_G(head);  //获取中间节点，将链表分为两段
    head1=MergeSort_G(head1);   //分别对两段链表进行排序
    head2=MergeSort_G(head2);
    return Merge_G(head1,head2);  //将两段有序链表合并
}

StuGra *Merge_G(StuGra *head1,StuGra *head2) //合并两个有序链表
{
    StuGra *NewHead=(StuGra *) malloc(sizeof(StuGra));
    StuGra *NewTail=NewHead;
    while(head1 && head2)
    {
        if(head1->grade_final >= head2->grade_final)
        {
            NewTail->next=head1;
            head1=head1->next;
        }
        else
        {
            NewTail->next=head2;
            head2=head2->next;
        }
        NewTail=NewTail->next;
        NewTail->next=NULL;
    }
    if(head1) NewTail->next=head1;
    if(head2) NewTail->next=head2;
    return NewHead->next;  //链表头节点
}

StuGra *GetMid_G(StuGra *head)  //获取中间节点并分段
{
    StuGra *fast=head->next;
    StuGra *slow=head->next;
    StuGra *prev=head;
    while(1)
    {
        if(fast == NULL) break;
        fast=fast->next;
        if(fast == NULL) break;
        fast=fast->next;

        prev=slow;
        slow=slow->next;
    }
    prev->next=NULL;  //将链表分为两段
    return slow;
}
