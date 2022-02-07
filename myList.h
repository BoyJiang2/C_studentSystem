

#ifndef MYLIST_H_INCLUDED
#define MYLIST_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//数据设计→学生信息抽象
struct student
{
    long number;
    char name[20];
    int age;
    char gender[20];
    char tel[20];
};
//结构分结构去写
//每一种数据结构去实现什么东西的时候，单独去写这种数据结构
//先把数据结构写对了
struct Node
{
    struct student data;
    struct Node* next;
};
//创建表
struct Node* createList()
{
    //结构体变量表示表头
    //指针→变量，动态内存申请
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    //表头：差异化处理，数据域data不做初始化
    headNode ->next  = NULL;
    return headNode;
}
//创建节点
struct Node* createList(struct student data)
{
    //有表头链表：第一个节点不储存数据
    //无表头链表：第一个节点储存数据
    //1.产生一个结构体变量
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    //2.初始化一个变量
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};
//插入节点
void insertNodeByHead(struct Node* headNode, struct student data)
{
    struct  Node* newNode = createList(data);
    //表头法
    newNode ->next = headNode ->next;
    headNode ->next = newNode;
}
//指定位置删除
//posFrontNode ->next = postNode ->next;
//free(posNode);
void deleteAppointNode(struct Node* headNode, long number)//比较学号
{

    struct Node* posNode = headNode->next; //指定位置节点
    struct Node* posFrontNode = headNode; //前面一个节点
    if(posNode == NULL)
    {
        printf("数据不足，无法删除！\n");
        return;
    }
    //姓名是字符串，字符串用strcmp
    while(posNode-> data.number != number)//数据不等于节点
    {
        posFrontNode = posNode; //指定位置前面到达了指定位置
        posNode = posFrontNode ->next; //指定位置到达了下一个
        //找到链表的时候就ending
        if(posNode == NULL)
        {
            printf("未找到指定位置无法删除！\n");
            return;
        }
    }
    //找到了
    posFrontNode ->next = posNode ->next;
    free(posNode);
}
//插入的方法：1.newNode ->next = headNode ->next 2. headNode ->next = newNode
//查找功能
struct Node*searchInfoByData(struct Node* headNode, long number)
{
    struct Node* pMove = headNode ->next;
    if(pMove == NULL)//链表是空的
    {
        return NULL;
    }
    while(pMove->data.number != number)
    {
        pMove = pMove ->next;
    }
    return pMove;
};
//文件读取操作
void readInfoFromFile(struct Node* headNode, char *fileName)
{
    //打开文件
    FILE *fp;
    struct student data;
    fp = fopen(fileName,"r");
    if(fp = NULL)
    {
        fopen(fileName,"w+");
    }
    //读取文件
    while(fscanf(fp,"%lld%s\t%d\t%s\t%s\n",&data.number,data.name,&data.age,data.gender,data.tel) != EOF)
    {
        insertNodeByHead(headNode,data);
    }
    //关闭文件
    fclose(fp);
}
//文件写入操作
void writeInfoToFile(struct Node* headNode, char *fileName)
{
    //打开文件
    FILE *fp;
    fp = fopen(fileName,"a");
    if(fp == NULL)
    {
        printf("文件打开失败！\n");
        return;
    }
    struct Node* pMove = headNode ->next;
    while(pMove)
    {
        fprintf(fp,"%lld\t%s\t%d\t%s\t%s\n",pMove->data.number,pMove->data.name,pMove->data.age,pMove->data.gender,pMove->data.tel);
        pMove = pMove ->next;
    }
    fclose(fp);
}
//打印链表
void printList(struct Node* headNode)
{
    struct Node* pMove = headNode ->next;
    //涉及到数据的处理
    printf("学号\t姓名\t年龄\t性别\t电话\n");
    while(pMove)
    {
        printf("%lld\t%s\t%d\t%s\t%s\n",pMove->data.number,pMove->data.name,pMove->data.age,pMove->data.gender,pMove->data.tel);
        pMove = pMove ->next;
    }
    printf("\n");
}
#endif // MYLIST_H_INCLUDED
