#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
typedef struct student     //定义结构体
{
    char name[20];    //姓名
    char num[15];      //学号
    char sex[10];     //性别
    char phone[15];      //手机号
    char QQ[15];         //QQ号
    char dorm[10];     //宿舍
    struct student *next;  //结构体指针
}stu;
stu *head;

void print()    //主菜单
{
    system("cls");
    printf("\n\n\n");
    printf("--------------------------------------------------------------------\n");
    printf("\t\t班级通讯录管理系统\n");
    printf("\n");
    printf("\t\t1. 输入数据\n");
    printf("\t\t2. 显示数据\n");
    printf("\t\t3. 删除数据\n");
    printf("\t\t4. 查看数据\n");
    printf("\t\t5. 保存数据\n");
    printf("\t\t6. 返回主菜单\n");
    printf("\t\t7. 退出\n");
}


void input(stu *p1)    //输入相关数据
{
    printf("姓名:");
    scanf("%s",&p1->name);
    printf("学号:");
    scanf("%s",&p1->num);
    printf("性别:");
    scanf("%s",&p1->sex);
    printf("手机号:");
    scanf("%s",&p1->phone);
    printf("QQ号:");
    scanf("%s",&p1->QQ);
    printf("宿舍:");
    scanf("%s",&p1->dorm);
}


stu * inputdata()     //数据输入的函数
{
    stu *p1,*p2;
    int i=1;
    p1=(stu *)malloc(sizeof(stu));
    if(p1!=NULL)
    {
        head=p1;
        printf("\n\t\t\t---输入数据---\n");
        printf("------------------------------------------------------------------\n");
        printf("在姓名处输入“OK”代表输入数据结束\n");
        while(i)
        {
            printf("姓名:");
            scanf("%s",&p1->name);
            if(strcmp(p1->name,"ok")==0)
            {
                printf("\n输入完毕!\n");
                printf("-------------------------------------------------------------------------\n");
                i=0;
                p2->next=NULL;
                free(p1);
                p1=p2;
            }
            else
            {
                printf("学号:");
                scanf("%s",&p1->num);
                printf("性别:");
                scanf("%s",&p1->sex);
                printf("手机号:");
                scanf("%s",&p1->phone);
                printf("QQ号:");
                scanf("%s",&p1->QQ);
                printf("宿舍:");
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


stu * lookdata(stu *p1)     //查看数据的函数
{
    printf("\n\t\t---显示数据---\n");
    printf("----------------------------------------------------------------------\n");
    while(p1!=NULL)
    {
        printf("姓名:%s\n",p1->name);
        printf("学号:%s\t",p1->num);
        printf("性别:%s\t",p1->sex);
        printf("手机号:%s\t",p1->phone);
        printf("QQ号:%s\t",p1->QQ);
        printf("宿舍:%s\n",p1->dorm);
        printf("------------------------------------------------------------------\n");
        p1=p1->next;
    }
    return p1;
}

void deleted()          //删除数据
{
    stu *p1,*p2;
    char Name[20];  //想要删除的人的姓名
    printf("\n\t\t\t---删除数据---\n");
    printf("----------------------------------------------------------------------\n");
    printf("请输入要删除的姓名:");
    scanf("%s",Name);
    p1=head;
    if(head==NULL)
    {
    printf("还没有输入数据\n");
    printf("-----------------------------------------------------------------------\n");
    return;
    }
    if(strcmp(Name,p1->name)==0)
    {
    head=p1->next;
    printf("删除成功!\n");
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
    printf("此人不存在!\n");
    printf("======================================================================\n");
    return;
    }
    if(p1->next!=NULL)
    {
    p1=p1->next;
    p2->next=p1;
    printf("删除成功!\n");
    printf("======================================================================\n");
    return;
    }
    else
    {
    p2->next=NULL;
    printf("删除成功!\n");
    printf("======================================================================\n");
    return;
    }
}


find(stu *p2)        //通过姓名查找查看数据的函数
{
    char name[20];
    int b=0;
    printf("\n\t\t---查看数据---\n");
    printf("----------------------------------------------------------------------\n");
    printf("请输入您想查找人的姓名:");
    scanf("%s",name);
    while(p2!=NULL)
    {
        if(strcmp(name,p2->name)==0)
        {
            printf("你要找到的数据\n");
            printf("姓名:%s\n",p2->name);
            printf("学号:%s\t",p2->num);
            printf("性别:%s\t",p2->sex);
            printf("手机号:%s\t",p2->phone);
            printf("QQ号:%s\t",p2->QQ);
            printf("宿舍:%s\n",p2->dorm);
            printf("--------------------------------------------------------------\n");
            b=1;
        }
        p2=p2->next;
    }
    if(b==0)
    {
        printf("\n您要查找的人不存在!\n");
    }
}



save(stu *p2)   //保存数据
{
    FILE *fp;
    char file[15];
    printf("\n\t\t---保存数据---\n");
    printf("----------------------------------------------------------------------\n");
    printf("输入文件名:");
    scanf("%s",file);
    if((fp=fopen(file,"w"))==NULL)
    {
        printf("cannot open this file\n");
        exit(0);
    }
    fprintf(fp,"姓名\t学号\t性别\t手机号\tQQ号\t宿舍\n");
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
    printf("\n保存成功!\n");
    printf("-----------------------------------------------------------------\n");
    fclose(fp);
}


void screen()
{
    int i;
    char s[251]={"欢迎使用由第20制作的，\n\n\t\t\t本系统用于通讯录管理----排序，打印\n\n\n\t\tWelcome to use produced by ZM class address book\n\n\t\t management system,sorting,printing"};

    printf("\n================================================================================\n");
    printf("\n\n\n\t\t\t");
    for(i=0;s[i]!=NULL;i++)
    {
        Sleep(30);
        printf("%c",s[i]);
    }
    printf("\n\n\n\n\n\n\n\n\t\t ~ Hi~ o(*￣▽￣*)ブ~ ~ ~祝您旅途愉快~ ~\n");
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
        printf("请输入1~7的数字进行选择:");
        loop:scanf("%d",&i);
        if(i<1||i>9)
        {
            printf("输入数字未在1~7内:");
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
