#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
typedef struct student     //����ṹ��
{
    char name[20];    //����
    char num[15];      //ѧ��
    char sex[10];     //�Ա�
    char phone[15];      //�ֻ���
    char QQ[15];         //QQ��
    char dorm[10];     //����
    struct student *next;  //�ṹ��ָ��
}stu;
stu *head;

void print()    //���˵�
{
    system("cls");
    printf("\n\n\n");
    printf("--------------------------------------------------------------------\n");
    printf("\t\t�༶ͨѶ¼����ϵͳ\n");
    printf("\n");
    printf("\t\t1. ��������\n");
    printf("\t\t2. ��ʾ����\n");
    printf("\t\t3. ɾ������\n");
    printf("\t\t4. �鿴����\n");
    printf("\t\t5. ��������\n");
    printf("\t\t6. �������˵�\n");
    printf("\t\t7. �˳�\n");
}


void input(stu *p1)    //�����������
{
    printf("����:");
    scanf("%s",&p1->name);
    printf("ѧ��:");
    scanf("%s",&p1->num);
    printf("�Ա�:");
    scanf("%s",&p1->sex);
    printf("�ֻ���:");
    scanf("%s",&p1->phone);
    printf("QQ��:");
    scanf("%s",&p1->QQ);
    printf("����:");
    scanf("%s",&p1->dorm);
}


stu * inputdata()     //��������ĺ���
{
    stu *p1,*p2;
    int i=1;
    p1=(stu *)malloc(sizeof(stu));
    if(p1!=NULL)
    {
        head=p1;
        printf("\n\t\t\t---��������---\n");
        printf("------------------------------------------------------------------\n");
        printf("�����������롰OK�������������ݽ���\n");
        while(i)
        {
            printf("����:");
            scanf("%s",&p1->name);
            if(strcmp(p1->name,"ok")==0)
            {
                printf("\n�������!\n");
                printf("-------------------------------------------------------------------------\n");
                i=0;
                p2->next=NULL;
                free(p1);
                p1=p2;
            }
            else
            {
                printf("ѧ��:");
                scanf("%s",&p1->num);
                printf("�Ա�:");
                scanf("%s",&p1->sex);
                printf("�ֻ���:");
                scanf("%s",&p1->phone);
                printf("QQ��:");
                scanf("%s",&p1->QQ);
                printf("����:");
                scanf("%s",&p1->dorm);
                printf("-------------------------------------------\n");
                p2=p1;
                p1=(stu *)malloc(sizeof(stu));
                if(p1!=NULL)
                {
                    p2->next=p1;
                }
            }
        }
        return(p1->next);
    }
}


stu * lookdata(stu *p1)     //�鿴���ݵĺ���
{
    printf("\n\t\t---��ʾ����---\n");
    printf("----------------------------------------------------------------------\n");
    while(p1!=NULL)
    {
        printf("����:%s\n",p1->name);
        printf("ѧ��:%s\t",p1->num);
        printf("�Ա�:%s\t",p1->sex);
        printf("�ֻ���:%s\t",p1->phone);
        printf("QQ��:%s\t",p1->QQ);
        printf("����:%s\n",p1->dorm);
        printf("------------------------------------------------------------------\n");
        p1=p1->next;
    }
    return p1;
}

void deleted()          //ɾ������
{
    stu *p1,*p2;
    char Name[20];  //��Ҫɾ�����˵�����
    printf("\n\t\t\t---ɾ������---\n");
    printf("----------------------------------------------------------------------\n");
    printf("������Ҫɾ��������:");
    scanf("%s",Name);
    p1=head;
    if(head==NULL)
    {
    printf("��û����������\n");
    printf("-----------------------------------------------------------------------\n");
    return;
    }
    if(strcmp(Name,p1->name)==0)
    {
    head=p1->next;
    printf("ɾ���ɹ�!\n");
    printf("-------------------------------------------------------------------------\n");
    return;
    }
    while(p1!=NULL&&(strcmp(Name,p1->name)!=0))
    {
    p2=p1;
    p1=p1->next;
    }
    if(p1==NULL)
    {
    printf("���˲�����!\n");
    printf("======================================================================\n");
    return;
    }
    if(p1->next!=NULL)
    {
    p1=p1->next;
    p2->next=p1;
    printf("ɾ���ɹ�!\n");
    printf("======================================================================\n");
    return;
    }
    else
    {
    p2->next=NULL;
    printf("ɾ���ɹ�!\n");
    printf("======================================================================\n");
    return;
    }
}


find(stu *p2)        //ͨ���������Ҳ鿴���ݵĺ���
{
    char name[20];
    int b=0;
    printf("\n\t\t---�鿴����---\n");
    printf("----------------------------------------------------------------------\n");
    printf("��������������˵�����:");
    scanf("%s",name);
    while(p2!=NULL)
    {
        if(strcmp(name,p2->name)==0)
        {
            printf("��Ҫ�ҵ�������\n");
            printf("����:%s\n",p2->name);
            printf("ѧ��:%s\t",p2->num);
            printf("�Ա�:%s\t",p2->sex);
            printf("�ֻ���:%s\t",p2->phone);
            printf("QQ��:%s\t",p2->QQ);
            printf("����:%s\n",p2->dorm);
            printf("--------------------------------------------------------------\n");
            b=1;
        }
        p2=p2->next;
    }
    if(b==0)
    {
        printf("\n��Ҫ���ҵ��˲�����!\n");
    }
}



save(stu *p2)   //��������
{
    FILE *fp;
    char file[15];
    printf("\n\t\t---��������---\n");
    printf("----------------------------------------------------------------------\n");
    printf("�����ļ���:");
    scanf("%s",file);
    if((fp=fopen(file,"w"))==NULL)
    {
        printf("cannot open this file\n");
        exit(0);
    }
    fprintf(fp,"����\tѧ��\t�Ա�\t�ֻ���\tQQ��\t����\n");
    while(p2!=NULL)
    {
        fprintf(fp,"%s\t",p2->name);
        fprintf(fp,"%s\t",p2->num);
        fprintf(fp,"%s\t",p2->sex);
        fprintf(fp,"%s\t",p2->phone);
        fprintf(fp,"%s\t",p2->QQ);
        fprintf(fp,"%s\n",p2->dorm);
        p2=p2->next;
    }
    printf("\n����ɹ�!\n");
    printf("-----------------------------------------------------------------\n");
    fclose(fp);
}


void screen()
{
    int i;
    char s[251]={"��ӭʹ���ɵ�20�����ģ�\n\n\t\t\t��ϵͳ����ͨѶ¼����----���򣬴�ӡ\n\n\n\t\tWelcome to use produced by ZM class address book\n\n\t\t management system,sorting,printing"};

    printf("\n================================================================================\n");
    printf("\n\n\n\t\t\t");
    for(i=0;s[i]!=NULL;i++)
    {
        Sleep(30);
        printf("%c",s[i]);
    }
    printf("\n\n\n\n\n\n\n\n\t\t ~ Hi~ o(*������*)��~ ~ ~ף����;���~ ~\n");
    printf("================================================================================\n");

}


int main()
{
    int i;
    screen();
    Sleep(3000);
    print();
    while(1)
    {
        printf("������1~7�����ֽ���ѡ��:");
        loop:scanf("%d",&i);
        if(i<1||i>9)
        {
            printf("��������δ��1~7��:");
            goto loop;
        }
        switch(i)
        {
        case 1:
            inputdata();
            break;
        case 2:
            lookdata(head);
            break;
        case 3:
             deleted();
            break;
        case 4:
            find(head);
            break;
        case 5:
            save(head);
            break;
        case 6:
            print();
            break;
        case 7:
            exit(1);
            break;
        }
    }
}
