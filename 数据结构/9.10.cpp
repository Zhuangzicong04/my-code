#include <stdio.h>
#include<stdlib.h>   /*����˵��*/
#include<string.h>   /*�ַ�������*/
#include<ctype.h>    /*�ַ���������*/�� 
#define N  5
struct Node   /*����ṹ���������ڻ�������*/
{
   char name[20];//���� 
   char write[20];//����
   char no[20];// ISBM
   char kind[20];//leibie 
   int num;//����
   int order;//��Ǽ������ 
   struct Node *next; 
};
typedef struct Node* pNode; 
/*struct People{
     int id;
     char name[20];
     int ay,am,ad;//Ϊ����������� 
	 int by,bm,bd; //Ϊ����������� 
};
typedef struct People * rNode; */
/*����ԭ��*/

int menu_select();   /*�˵�����*/
pNode create();   /*��������*/
void print(pNode pHead);   /* ��ʾȫ����¼*/
void search(pNode pHead);    /*���Ҽ�¼*/
void dele(pNode pHead);   /*ɾ����¼*/
void calu(pNode pHead); /*����*/
/*����������*/
int main()
{
    while(1)            /*ѭ�����޴�*/
   {
   	pNode head;
   	int t;
   switch(menu_select())    
      {
	                  
	 case 1:
	 head=create();
	 break;/*����ͼ���*/
	 
	 case 2:
	 print(head);
	 break;/*��ʾͼ����Ϣ*/
	 
	 case 3:
	 search(head);
	 break;/*��ѯ*/
	 
	 case 4:
    dele(head);
	print(head);//��ӡÿ�ε���� 
    scanf("%c",&t);
    if(t == '#')
	 break;/*ɾ��*/
	 
	 case 5:exit(0);       /*��˵�����ֵΪ6��������*/
      }
   }
   return 0;
}
/*�˵�ѡ����*/
menu_select()
{
 int n;
 //printf("����һ���������˵�......");   /*����һ���������˵�*/
 //getchar();    /*�Ӽ��̶�ȡһ���ַ�,������ʾ����Ļ*/
 system("cls");   /*����*/
 printf("********************************************************************************\n");
 printf("\t\t                Welcome to\n");
 printf("\n\t\t              ͼ��ݹ���ϵͳ\n");
 printf("*************************************MENU***************************************\n");
 
 printf("\t\t\t1. ����ͼ����Ϣ\n");                /*����ͼ����Ϣ*/
 printf("\t\t\t2. ��ʾͼ����Ϣ\n");                /*��ʾͼ����Ϣ*/
 printf("\t\t\t3. ��ѯ�鼮��Ϣ\n");                /*��ѯ�鼮��Ϣ*/
 printf("\t\t\t4. ɾ��ͼ����Ϣ\n");                /*ɾ��ͼ����Ϣ*/
 printf("\t\t\t5. �˳�\n");                        /*�˳�*/
 printf("********************************************************************************\n");
 do
 {
    printf("\n\t\t\t������Ĳ������(1~5):");  
    scanf("%d",&n);
 }while(n<1||n>5);    /*���ѡ�����1~5֮��������*/
   return(n);           /*����ѡ������������ݸ���������Ӧ�ĺ���*/
}
/*
/*���뺯��*/

/* ��ʾȫ����¼����*/
void print(pNode pHead)
{
int i=0;     /* ͳ�Ƽ�¼����*/
int sum=0;//��ͼ���� 
char t;
system("cls");
 printf("\n************************************ͼ����Ϣ******************************************\n");
 printf("----------------------------------------------------------------------------------------\n");
 printf("| ��� |   ����   |   ����   |   ISBN  |    ���   | ���� |\n");
 printf("----------------------------------------------------------------------------------------\n");
 pNode p=pHead->next;//����ͷ�ڵ㣬ͷ�ڵ�Ϊ�� �����򱨴� 
 pNode q=p->next;
 while(p!=NULL)
 {
 	//pNode p=pHead->next;//����ͷ�ڵ㣬ͷ�ڵ�Ϊ�� �����򱨴� 
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
			printf("%s�Ĳ�������%d��\n",p->name,cnt+p->num);
		}
		sum+=p->num;
		p=p->next; 
	}
	printf("�ܲ�������%d��\n",sum);
}
void dele(pNode head)//����ɾ��
{
	char ID[20];
	printf("��������Ҫɾ�������ID�� \n");
	scanf("%s",ID);
	if(head->next==NULL)
	{
		printf("������������Ч");//ͷ�ڵ���һ�ڵ㣬Ϊ�գ���ʧ�ܣ���Ϊû�����ݣ�Ҳ�Ǳ�֤���ݳ�����Ч 
		exit(1);
	}
	pNode p=head;//ͷ�ڵ㸳ֵ 
	head=head->next;//ͷ�ڵ�ָ����һ�ڵ� 
	while(head!=NULL)//ѭ������ 
   {
		if(!strcmp(head->no,ID))//ID����������pָ��head����һ���ڵ㣬ͬʱ�ͷ�head����Ϊhead��Զָ��p���������ڵ� 
		{
			p->next=head->next;
			free(head);//�ͷ�Ұָ�� 
		}
		head=head->next;//�����ڵ㲻��ָ����һ���ڵ���� 
		p=p->next;
	}
}
void search(pNode head)//���ݲ��ң������������� 
{
	char Name[20];
	char t; 
	printf("��������Ҫ���ҵ������� \n"); 
	scanf("%s",Name);
	int flag=0;
	if(head->next==NULL)
	{
		printf("������������Ч");
		exit(1); 
	}
	pNode p=head->next; 
	while(p!=NULL)//˳����� 
	{
		if(!strcmp(p->name,Name))
		{
	    	printf("| ����   |   ����   |  ISBN  |   ���   | ���� |\n"); 
	    	printf("-------------------------------------------------------------------------------\n");
	    	printf("| %4s    |   %-4s   |   %3s  |    %4s   |  %-5d|\n", 
                    p->name,p->write,p->no,p->kind,p->num);
            flag=1;
		}
		p=p->next;
	}
	if(!flag)
	{
		printf("��¼��δ�д���\n");
	}	
	while(1)
 {
 	 scanf("%c",&t);
	 if(t == '#')
    break;
 }
} 
pNode create()//��Ϣ����������� 
{
	 printf("�������鼮��Ϣ\n| ����   |   ����    |  ISBN  |   ���   | ���� |\n");
	pNode pHead=(pNode)malloc(sizeof(struct Node));//����ͷ�ڵ� 
	int i;
	if(pHead==NULL)//ͷ�ڵ㴴���Ƿ�ɹ� 
	{
		printf("����ʧ��");
		exit(1);//�����Ƿ�ɹ� ��ʧ�ܾ��˳� 
	}
	else
	{
		pNode pTail=pHead;//β�ڵ�
		pHead->next=NULL; //ͷ�ڵ�ָ��� 
		while(1)//ѭ�������ڵ� 
		{
			pNode p=(pNode)malloc(sizeof(struct Node));//�����ڵ㣬����ָ����һ�� 
			if(p==NULL)
			{
				printf("����ʧ��");
		        exit(1);//�����Ƿ�ɹ� 
			}
			else
			{
               scanf("%s",p->name);//���� 
               if(!strcmp(p->name,"#"))
               {
               	break;
			   }
               scanf("%s",p->write);//���� 
               scanf("%s",p->no);//ISBN 
			   scanf("%s",p->kind);//���
			   scanf("%d",&p->num);//���� 
			   p->order=1;
               pTail->next=p;//���� �����ڵ㣬�����ָ��� 
               p->next=NULL;
               pTail=p; 				
			}
		}
	} 
 return pHead;
}
