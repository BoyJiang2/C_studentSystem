/*
1.����
2.����
3.���ݽṹ���
*/
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"myList.h"
//������ơ�ѧ����Ϣ�������
void menu()
{
    printf("------------[ѧ����Ϣ����ϵͳ]------------\n");
    printf("\t\t0.�˳�ϵͳ\n");
    printf("\t\t1.¼����Ϣ\n");
    printf("\t\t2.�����Ϣ\n");
    printf("\t\t3.�޸���Ϣ\n");
    printf("\t\t4.ɾ����Ϣ\n");
    printf("\t\t5.������Ϣ\n");
    printf("------------------------------------------\n");
}
struct Node* list = createList();
//�û��Ľ���
//�������Ӧ�Ĳ˵������ͬ������
void keyDown()
{
    struct Node* pMove = NULL;
    struct student data;
    int choice = 0;
    scanf("%d",&choice);
    switch(choice)
    {
    case 0:
        printf("�����˳���\n");
        system("pause");
        exit(0);
        break;
    case 1:
        printf("----------[¼����Ϣ]----------\n");
        //��������
        printf("������ѧ����ѧ�ţ����������䣬�Ա𣬵绰��");
        fflush(stdin);  //��ջ�����
        scanf("%d%s%d%s%s",&data.number, data.name,&data.age,data.gender,data.tel);
        insertNodeByHead(list,data);
        break;
    case 2:
        printf("----------[�����Ϣ]----------\n");
        printList(list);//��ӡ����
        break;
    case 3:
        printf("----------[�޸���Ϣ]----------\n");
        printf("��������޸ĵ�ѧ��ѧ�ţ�\n");
        scanf("%d",&data.number);
        if(searchInfoByData(list,data.number) == NULL)
        {
            printf("δ�ҵ������Ϣ!\n");
            system("pause");
        }
        else
        {
            struct Node* curNode = searchInfoByData(list,data.number);
            printf("��������ȷ��ѧ����ѧ�š����������䡢�Ա𡢵绰��\n");
            scanf("%d%s%d%s%s",&curNode->data.number,curNode->data.name,&curNode->data.age,curNode->data.gender,curNode->data.tel);
            printf("Es hat funktioniert!\n");
        }
        break;
    case 4:
        printf("----------[ɾ����Ϣ]----------\n");
        printf("�������ɾ����ѧ��ѧ�ţ�\n");
        scanf("%d",&data.number);
        if(searchInfoByData(list,data.number) == NULL)
        {
            printf("δ�ҵ������Ϣ���޷�ɾ��!\n");
            system("pause");
        }
        else
        {
            deleteAppointNode(list,data.number);
            printf("Es hat funktioniert!\n");
        }
        break;
    case 5:
        printf("----------[������Ϣ]----------\n");
        printf("������Ҫ���ҵ�ѧ��ѧ�ţ�");
        scanf("%d",&data.number);
        pMove = searchInfoByData(list,data.number);
        if(searchInfoByData(list,data.number) == NULL)
        {
            printf("δ�ҵ������Ϣ!\n");
            system("pause");
        }
        else
        {
            printf("ѧ��\t����\t����\t�Ա�\t�绰\n");
            printf("%d\t%s\t%d\t%s\t%s\n",pMove->data.number,pMove->data.name,pMove->data.age,pMove->data.gender,pMove->data.tel);
        }
        break;
    default:
        printf("��������\n");
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
        printf("����0~5�м������:");
        keyDown();
        system("pause");
        system("cls");
    }
    /*
    //����������
    struct Node* list = createList();
    insertNodeByHead(list,1);
    insertNodeByHead(list,3);
    insertNodeByHead(list,2);
    insertNodeByHead(list,5);
    printList(list);
    printf("ɾ��ָ��λ�ã�\n");
    deleteAppointNode(list,3);
    printList(list);
    printf("����Ĳ��ң�\n");
    printf("2��λ����%d\n",searchInfoByData(list,2)->data);
    */
    system("pause");
    return 0;
}
