#include <stdio.h>
#include<stdlib.h>   /*其它说明*/
#include<string.h>   /*字符串函数*/
#include<ctype.h>    /*字符操作函数*/、 
#define N  5
struct Node   /*定义结构体数组用于缓存数据*/
{
   char name[20];//书名 
   char write[20];//作者
   char no[20];// ISBM
   char kind[20];//leibie 
   int num;//数量
   int order;//标记计数情况 
   struct Node *next; 
};
typedef struct Node* pNode; 
/*struct People{
     int id;
     char name[20];
     int ay,am,ad;//为借书的年月日 
	 int by,bm,bd; //为还书的年月日 
};
typedef struct People * rNode; */
/*函数原型*/

int menu_select();   /*菜单函数*/
pNode create();   /*创建链表*/
void print(pNode pHead);   /* 显示全部记录*/
void search(pNode pHead);    /*查找记录*/
void dele(pNode pHead);   /*删除记录*/
void calu(pNode pHead); /*计数*/
/*主函数界面*/
int main()
{
    while(1)            /*循环无限次*/
   {
   	pNode head;
   	int t;
   switch(menu_select())    
      {
	                  
	 case 1:
	 head=create();
	 break;/*创建图书库*/
	 
	 case 2:
	 print(head);
	 break;/*显示图书信息*/
	 
	 case 3:
	 search(head);
	 break;/*查询*/
	 
	 case 4:
    dele(head);
	print(head);//打印每次的情况 
    scanf("%c",&t);
    if(t == '#')
	 break;/*删除*/
	 
	 case 5:exit(0);       /*如菜单返回值为6则程序结束*/
      }
   }
   return 0;
}
/*菜单选择函数*/
menu_select()
{
 int n;
 //printf("按任一键进入主菜单......");   /*按任一键进入主菜单*/
 //getchar();    /*从键盘读取一个字符,但不显示于屏幕*/
 system("cls");   /*清屏*/
 printf("********************************************************************************\n");
 printf("\t\t                Welcome to\n");
 printf("\n\t\t              图书馆管理系统\n");
 printf("*************************************MENU***************************************\n");
 
 printf("\t\t\t1. 输入图书信息\n");                /*输入图书信息*/
 printf("\t\t\t2. 显示图书信息\n");                /*显示图书信息*/
 printf("\t\t\t3. 查询书籍信息\n");                /*查询书籍信息*/
 printf("\t\t\t4. 删除图书信息\n");                /*删除图书信息*/
 printf("\t\t\t5. 退出\n");                        /*退出*/
 printf("********************************************************************************\n");
 do
 {
    printf("\n\t\t\t输入你的操作序号(1~5):");  
    scanf("%d",&n);
 }while(n<1||n>5);    /*如果选择项不在1~5之间则重输*/
   return(n);           /*返回选择项，主函数根据该数调用相应的函数*/
}
/*
/*输入函数*/

/* 显示全部记录函数*/
void print(pNode pHead)
{
int i=0;     /* 统计记录条数*/
int sum=0;//总图书量 
char t;
system("cls");
 printf("\n************************************图书信息******************************************\n");
 printf("----------------------------------------------------------------------------------------\n");
 printf("| 序号 |   书名   |   作者   |   ISBN  |    类别   | 数量 |\n");
 printf("----------------------------------------------------------------------------------------\n");
 pNode p=pHead->next;//跳过头节点，头节点为空 ，否则报错 
 pNode q=p->next;
 while(p!=NULL)
 {
 	//pNode p=pHead->next;//跳过头节点，头节点为空 ，否则报错 
 	printf("| %3d |  %4s   |   %-4s    |  %3s  |  %3s  |  %-5d|\n", 
    i, p->name,p->write,p->no,p->kind,p->num);
    i++;
    p=p->next;
 }
 calu(pHead);
 printf("-----------------------------------------------------------------------------------------\n");
 printf("**************************************END************************************************\n");
 while(1)
 {
 	 scanf("%c",&t);
	 if(t == '#')
    break;
 }
}
void calu(pNode pHead)
{
	printf("\n");
	int sum=0;
	pNode p=pHead->next; 
//    pNode q=p->next;
    while(p!=NULL)
    {
    	int cnt=0;
    	pNode q=p->next;
    	while(q!=NULL)
    	{
    		if(p->order==1)
    		{
    			cnt+=q->num;
    		    q->order=0;//&&p->order==1
			}
			q=q->next;
		}
		if(p->order ==1 )
		{
			printf("%s的藏书量：%d本\n",p->name,cnt+p->num);
		}
		sum+=p->num;
		p=p->next; 
	}
	printf("总藏书量：%d本\n",sum);
}
void dele(pNode head)//数据删除
{
	char ID[20];
	printf("请输入你要删除的书的ID： \n");
	scanf("%s",ID);
	if(head->next==NULL)
	{
		printf("空链表，长度无效");//头节点下一节点，为空，则失败，因为没有数据，也是保证数据长度有效 
		exit(1);
	}
	pNode p=head;//头节点赋值 
	head=head->next;//头节点指向下一节点 
	while(head!=NULL)//循环查找 
   {
		if(!strcmp(head->no,ID))//ID如果相等则让p指向head的下一个节点，同时释放head，因为head永远指向p的下两个节点 
		{
			p->next=head->next;
			free(head);//释放野指针 
		}
		head=head->next;//两个节点不断指向下一个节点查找 
		p=p->next;
	}
}
void search(pNode head)//数据查找，根据书名查找 
{
	char Name[20];
	char t; 
	printf("请输入你要查找的书名： \n"); 
	scanf("%s",Name);
	int flag=0;
	if(head->next==NULL)
	{
		printf("空链表，长度无效");
		exit(1); 
	}
	pNode p=head->next; 
	while(p!=NULL)//顺序查找 
	{
		if(!strcmp(p->name,Name))
		{
	    	printf("| 书名   |   作者   |  ISBN  |   类别   | 数量 |\n"); 
	    	printf("-------------------------------------------------------------------------------\n");
	    	printf("| %4s    |   %-4s   |   %3s  |    %4s   |  %-5d|\n", 
                    p->name,p->write,p->no,p->kind,p->num);
            flag=1;
		}
		p=p->next;
	}
	if(!flag)
	{
		printf("记录中未有此书\n");
	}	
	while(1)
 {
 	 scanf("%c",&t);
	 if(t == '#')
    break;
 }
} 
pNode create()//信息读入和链表创建 
{
	 printf("请输入书籍信息\n| 书名   |   作者    |  ISBN  |   类别   | 数量 |\n");
	pNode pHead=(pNode)malloc(sizeof(struct Node));//建立头节点 
	int i;
	if(pHead==NULL)//头节点创立是否成功 
	{
		printf("创建失败");
		exit(1);//检验是否成功 ，失败就退出 
	}
	else
	{
		pNode pTail=pHead;//尾节点
		pHead->next=NULL; //头节点指向空 
		while(1)//循环创建节点 
		{
			pNode p=(pNode)malloc(sizeof(struct Node));//创建节点，让他指向下一个 
			if(p==NULL)
			{
				printf("创建失败");
		        exit(1);//检验是否成功 
			}
			else
			{
               scanf("%s",p->name);//书名 
               if(!strcmp(p->name,"#"))
               {
               	break;
			   }
               scanf("%s",p->write);//作者 
               scanf("%s",p->no);//ISBN 
			   scanf("%s",p->kind);//类别
			   scanf("%d",&p->num);//数量 
			   p->order=1;
               pTail->next=p;//不断 创建节点，最后总指向空 
               p->next=NULL;
               pTail=p; 				
			}
		}
	} 
 return pHead;
}
