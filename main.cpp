/*
1.界面
2.交互
3.数据结构设计
*/
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"myList.h"
//数据设计→学生信息抽象出来
void menu()
{
    printf("------------[学生信息管理系统]------------\n");
    printf("\t\t0.退出系统\n");
    printf("\t\t1.录入信息\n");
    printf("\t\t2.浏览信息\n");
    printf("\t\t3.修改信息\n");
    printf("\t\t4.删除信息\n");
    printf("\t\t5.查找信息\n");
    printf("------------------------------------------\n");
}
struct Node* list = createList();
//用户的交互
//根据相对应的菜单项，做不同的事情
void keyDown()
{
    struct Node* pMove = NULL;
    struct student data;
    int choice = 0;
    scanf("%d",&choice);
    switch(choice)
    {
    case 0:
        printf("正常退出！\n");
        system("pause");
        exit(0);
        break;
    case 1:
        printf("----------[录入信息]----------\n");
        //插入链表
        printf("请输入学生的学号，姓名，年龄，性别，电话：");
        fflush(stdin);  //清空缓冲区
        scanf("%d%s%d%s%s",&data.number, data.name,&data.age,data.gender,data.tel);
        insertNodeByHead(list,data);
        break;
    case 2:
        printf("----------[浏览信息]----------\n");
        printList(list);//打印链表
        break;
    case 3:
        printf("----------[修改信息]----------\n");
        printf("请输入待修改的学生学号：\n");
        scanf("%d",&data.number);
        if(searchInfoByData(list,data.number) == NULL)
        {
            printf("未找到相关信息!\n");
            system("pause");
        }
        else
        {
            struct Node* curNode = searchInfoByData(list,data.number);
            printf("请输入正确的学生的学号、姓名、年龄、性别、电话：\n");
            scanf("%d%s%d%s%s",&curNode->data.number,curNode->data.name,&curNode->data.age,curNode->data.gender,curNode->data.tel);
            printf("Es hat funktioniert!\n");
        }
        break;
    case 4:
        printf("----------[删除信息]----------\n");
        printf("请输入待删除的学生学号：\n");
        scanf("%d",&data.number);
        if(searchInfoByData(list,data.number) == NULL)
        {
            printf("未找到相关信息，无法删除!\n");
            system("pause");
        }
        else
        {
            deleteAppointNode(list,data.number);
            printf("Es hat funktioniert!\n");
        }
        break;
    case 5:
        printf("----------[查找信息]----------\n");
        printf("请输入要查找的学生学号：");
        scanf("%d",&data.number);
        pMove = searchInfoByData(list,data.number);
        if(searchInfoByData(list,data.number) == NULL)
        {
            printf("未找到相关信息!\n");
            system("pause");
        }
        else
        {
            printf("学号\t姓名\t年龄\t性别\t电话\n");
            printf("%d\t%s\t%d\t%s\t%s\n",pMove->data.number,pMove->data.name,pMove->data.age,pMove->data.gender,pMove->data.tel);
        }
        break;
    default:
        printf("重新输入\n");
        system("pause");
        break;
    }
    writeInfoToFile(list,"data.txt");
}
int main()
{
    readInfoFromFile(list,"data.txt");
    while(1)
    {
        menu();
        printf("输入0~5中间的数字:");
        keyDown();
        system("pause");
        system("cls");
    }
    /*
    //测试链表方法
    struct Node* list = createList();
    insertNodeByHead(list,1);
    insertNodeByHead(list,3);
    insertNodeByHead(list,2);
    insertNodeByHead(list,5);
    printList(list);
    printf("删除指定位置：\n");
    deleteAppointNode(list,3);
    printList(list);
    printf("链表的查找：\n");
    printf("2的位置是%d\n",searchInfoByData(list,2)->data);
    */
    system("pause");
    return 0;
}
