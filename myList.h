

#ifndef MYLIST_H_INCLUDED
#define MYLIST_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//������ơ�ѧ����Ϣ����
struct student
{
    long number;
    char name[20];
    int age;
    char gender[20];
    char tel[20];
};
//�ṹ�ֽṹȥд
//ÿһ�����ݽṹȥʵ��ʲô������ʱ�򣬵���ȥд�������ݽṹ
//�Ȱ����ݽṹд����
struct Node
{
    struct student data;
    struct Node* next;
};
//������
struct Node* createList()
{
    //�ṹ�������ʾ��ͷ
    //ָ�����������̬�ڴ�����
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    //��ͷ�����컯����������data������ʼ��
    headNode ->next  = NULL;
    return headNode;
}
//�����ڵ�
struct Node* createList(struct student data)
{
    //�б�ͷ������һ���ڵ㲻��������
    //�ޱ�ͷ������һ���ڵ㴢������
    //1.����һ���ṹ�����
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    //2.��ʼ��һ������
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};
//����ڵ�
void insertNodeByHead(struct Node* headNode, struct student data)
{
    struct  Node* newNode = createList(data);
    //��ͷ��
    newNode ->next = headNode ->next;
    headNode ->next = newNode;
}
//ָ��λ��ɾ��
//posFrontNode ->next = postNode ->next;
//free(posNode);
void deleteAppointNode(struct Node* headNode, long number)//�Ƚ�ѧ��
{

    struct Node* posNode = headNode->next; //ָ��λ�ýڵ�
    struct Node* posFrontNode = headNode; //ǰ��һ���ڵ�
    if(posNode == NULL)
    {
        printf("���ݲ��㣬�޷�ɾ����\n");
        return;
    }
    //�������ַ������ַ�����strcmp
    while(posNode-> data.number != number)//���ݲ����ڽڵ�
    {
        posFrontNode = posNode; //ָ��λ��ǰ�浽����ָ��λ��
        posNode = posFrontNode ->next; //ָ��λ�õ�������һ��
        //�ҵ������ʱ���ending
        if(posNode == NULL)
        {
            printf("δ�ҵ�ָ��λ���޷�ɾ����\n");
            return;
        }
    }
    //�ҵ���
    posFrontNode ->next = posNode ->next;
    free(posNode);
}
//����ķ�����1.newNode ->next = headNode ->next 2. headNode ->next = newNode
//���ҹ���
struct Node*searchInfoByData(struct Node* headNode, long number)
{
    struct Node* pMove = headNode ->next;
    if(pMove == NULL)//�����ǿյ�
    {
        return NULL;
    }
    while(pMove->data.number != number)
    {
        pMove = pMove ->next;
    }
    return pMove;
};
//�ļ���ȡ����
void readInfoFromFile(struct Node* headNode, char *fileName)
{
    //���ļ�
    FILE *fp;
    struct student data;
    fp = fopen(fileName,"r");
    if(fp = NULL)
    {
        fopen(fileName,"w+");
    }
    //��ȡ�ļ�
    while(fscanf(fp,"%lld%s\t%d\t%s\t%s\n",&data.number,data.name,&data.age,data.gender,data.tel) != EOF)
    {
        insertNodeByHead(headNode,data);
    }
    //�ر��ļ�
    fclose(fp);
}
//�ļ�д�����
void writeInfoToFile(struct Node* headNode, char *fileName)
{
    //���ļ�
    FILE *fp;
    fp = fopen(fileName,"a");
    if(fp == NULL)
    {
        printf("�ļ���ʧ�ܣ�\n");
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
//��ӡ����
void printList(struct Node* headNode)
{
    struct Node* pMove = headNode ->next;
    //�漰�����ݵĴ���
    printf("ѧ��\t����\t����\t�Ա�\t�绰\n");
    while(pMove)
    {
        printf("%lld\t%s\t%d\t%s\t%s\n",pMove->data.number,pMove->data.name,pMove->data.age,pMove->data.gender,pMove->data.tel);
        pMove = pMove ->next;
    }
    printf("\n");
}
#endif // MYLIST_H_INCLUDED
