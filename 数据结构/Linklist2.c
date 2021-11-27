#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Book{
	char id[30];
	char name[30];
	char author[30];
	char kind[30];
	int  sum;
	int  remain;
	struct Book * next;
};
typedef struct Book * book;

struct Pbook{
	char id[30];
	char name[30];
	char author[30];
	char kind[30];
	int sum;
};
struct People{
	char id[4];
	char name[30];
	int  borrow_amount;
	int  max_amount;
	int license;
	int by,bm,bd;
	int ry,rm,rd;
	struct book 
	struct People * next;
};
typedef struct People * people;

book create(book head);
book delete(book head);
void * borrow(book head,people p); 
int main()
{
	int option;
	book head = NULL;
	people p = NULL;
	printf("1. ���ͼ��\n");
	printf("2. ��ѯͼ����Ϣ\n");
	printf("3. ɾ��ͼ��\n");
	printf("4. ����\n");
	printf("5. ����\n");
	printf("6. ����ͳ��\n");
	printf("6. �˳�\n");
	while(printf("\n>������ѡ�") && (scanf("%d", &option) == 1))
	{
		switch (option)
		{
		case 1:
			head = create(head);
			break;
		/*case 2:
			borrow(head,p);
			break;*/
		case 3:
			head = delete(head);
			break;
		case 4:
			borrow(head,p);
			break;
		case 5:
			return(head,p);
			break;
		case 6:
			free(head,p);
			break;
		default:
			printf("����ѡ����������롣\n");
			break;*/
		}
	}
	return 0; 
}
book create(book head){
	book node = (book)malloc(sizeof(struct Book));
	printf("������ͼ����Ϣ\n|  ���  |  ����  |  ����  |  ����  |  ����\n");
	scanf("%s",node -> id);
	scanf("%s",node -> name);
	scanf("%s",node -> author);
	scanf("%s",node -> kind);
	scanf("%d",&node -> sum);
	node -> remain = node -> sum;
	node -> next = NULL;
	if(head == NULL)
	{
		head = node;
	}
	else{
		book pnode = head;
		while(pnode -> next != NULL)
		{
			pnode = pnode -> next;
		}
		pnode -> next = node;
	}
	printf("ͼ����ӳɹ���");
	return head;
}
book delete(book head){
	book p,q;
	char id[50];
	p = head;
	if(p == NULL)
	{
		printf("����ͼ�飡\n");
	    return head;
	}
		q = head -> next;
		printf("����������ɾ����ͼ���ţ�");
	    scanf("%s",id);
	    if(strcmp(id,p -> id) == 0)
	    {
	    	head = q;
	    	free(p);
	    	printf("ɾ���ɹ���\n");
	    	return head;
		}
		else
		{
			while(q != NULL)
			{
				if(strcmp(id,q -> id) == 0){
					p -> next = q -> next;
					free(q);
					q = NULL;
					printf("ɾ���ɹ�!\n");
					return head;
				}
				p = q;
				q = q -> next;
			}
			printf("���޴��飡\n");
			return head;
		}		
}
void * borrow(book head,people p)
{
	int a,b;
	char id[4];
	char bookname[30],author[30];
	book node1;
	people node2 = (people)malloc(sizeof(struct People));
	node1 = head;
	node2 -> next = NULL;
	if(node1 == NULL)
	{
		printf("����ͼ��\n");
		return; 
	}
	if(p == NULL)
	{
		p = node2;
	}
	printf("��ӭ��������ϵͳ��������ʦ������1����ѧ��������2\n");
	scanf("%d",&a);
	printf("���ǵ�һ����������,�ǵĻ�������1������������2\n");
	scanf("%d",&b);
	if(a == 1 && b == 1)
	{
		printf("���������Ĺ��ţ�"); 
		scanf("%s",node2 -> id);
		node2 -> license = 1;
		node2 -> max_amount = 15; 
		printf("����������Ҫ����������Ϣ��| ���� | ���� | ���� | ���� | ʱ�� \n");
		scanf("%s",node2 -> name);
		scanf("%s",bookname);
		scanf("%s",author);
		scanf("%d",&node2 -> borrow_amount);
		scanf("%d%d%d",&node2 -> by,&node2 -> bm,&node2 -> bd);
		if(strcmp(bookname,node1 -> name) == 0 && strcmp(author,node1 -> author) == 0)
		{
			if(node2 -> borrow_amount <= node1 -> remain)
			{
				node1 -> remain = node1 -> remain - node2 -> borrow_amount;
				if(node2 -> bm < 6)
				{
					node2 -> ry = node2 -> by;
					node2 -> rm = node2 -> bm + 6;
					node2 -> rd = node2 -> bd;
				}
				else{
					node2 -> ry = node2 -> by + 1;
					node2 -> ry = node2 -> bm -6;
					node2 -> rd = node2 -> bd;
				}
				people q = p;
				while(q -> next != NULL)
				q = q -> next;
				q -> next = node2;
				printf("����ɹ���\n");
				return;
			}
			else
			{
				printf("�����鼮����������\n");
				return;
			}
		}
		while(node1 -> next != NULL)
		{
			if(strcmp(bookname,node1 -> name) == 0 && strcmp(author,node1 -> author) == 0)
		{
			if(node2 -> borrow_amount <= node1 -> remain)
			{
				node1 -> remain = node1 -> remain - node2 -> borrow_amount;
				if(node2 -> bm <= 6)
				{
					node2 -> ry = node2 -> by;
					node2 -> rm = node2 -> bm + 6;
					node2 -> rd = node2 -> bd;
				}
				else{
					node2 -> ry = node2 -> by + 1;
					node2 -> ry = node2 -> bm -6;
					node2 -> rd = node2 -> bd;
				}
				people q = p;
				while(q -> next != NULL)
				q = q -> next;
				q -> next = node2;
				printf("����ɹ���\n");
				return;
			}
			else
			{
				printf("�����鼮����������\n");
				return;
			}
		}
		printf("���޴��飡\n");
		return;
	 }
	}
	else if(a == 1 && b == 2)
	{
		people q = p;
		int sum;
		printf("���������Ĺ��ţ�\n");
		scanf("%s",&id);
		do
		{
		    	if(strcmp(id,q -> id) == 0)
		    {
			  if(q -> borrow_amount < q -> max_amount)
			  {
			  	printf("����������Ҫ����������Ϣ��|  ���� | ���� | ���� | ʱ�� \n");
		        scanf("%s",bookname);
	    	    scanf("%s",author);
	        	scanf("%d",&sum);
	        	scanf("%d%d%d",&q -> by,&q -> bm,&q -> bd);
	        	if(strcmp(bookname,node1 -> name) == 0 && strcmp(author,node1 -> author) == 0)
		{
			if( sum <= node1 -> remain)
			{
				node1 -> remain = node1 -> remain - sum;
				q -> borrow_amount = q -> borrow_amount + sum;
				if(q -> bm < 6)
				{
					q -> ry = q -> by;
					q -> rm = q -> bm + 6;
					q -> rd = q -> bd;
				}
				else{
					q -> ry = q -> by + 1;
					q -> ry = q -> bm -6;
					q -> rd = q -> bd;
				}
				printf("����ɹ���\n");
				return;
			}
			else
			{
				printf("�����鼮����������\n");
				return;
			}
		}
		while(node1 -> next != NULL)
		{
			if(strcmp(bookname,node1 -> name) == 0 && strcmp(author,node1 -> author) == 0)
		{
				if( sum <= node1 -> remain)
			{
				node1 -> remain = node1 -> remain - sum;
				q -> borrow_amount = q -> borrow_amount + sum;
				if(q -> bm < 6)
				{
					q -> ry = q -> by;
					q -> rm = q -> bm + 6;
					q -> rd = q -> bd;
				}
				else{
					q -> ry = q -> by + 1;
					q -> ry = q -> bm -6;
					q -> rd = q -> bd;
				}
				printf("����ɹ���\n");
				return;
			}
			else
			{
				printf("�����鼮����������\n");
				return;
			}
		}
		printf("���޴��飡\n");
		return;
	 }
			  }
			   else
			   {
			   		printf("������ͼ���Ѵﵽ���ޣ�\n");
					return; 
			   }
	    	}
	    	q = q -> next;
		}while(q != NULL);
	}
	else if(a == 2 && b == 1)
	{
		printf("����������ѧ�ţ�"); 
		scanf("%s",node2 -> id);
		node2 -> license = 2;
		node2 -> max_amount = 10; 
		printf("����������Ҫ����������Ϣ��| ���� | ���� | ���� | ���� | ʱ��\n ");
		scanf("%s",node2 -> name);
		scanf("%s",bookname);
		scanf("%s",author);
		scanf("%d",&node2 -> borrow_amount);
		scanf("%d%d%d",&node2 -> by,&node2 -> bm,&node2 -> bd);
		if(strcmp(bookname,node1 -> name) == 0 && strcmp(author,node1 -> author) == 0)
		{
			if(node2 -> borrow_amount <= node1 -> remain)
			{
				node1 -> remain = node1 -> remain - node2 -> borrow_amount;
				if(node2 -> bm <= 8)
				{
					node2 -> ry = node2 -> by;
					node2 -> rm = node2 -> bm + 4;
					node2 -> rd = node2 -> bd;
				}
				else{
					node2 -> ry = node2 -> by + 1;
					node2 -> ry = node2 -> bm - 8;
					node2 -> rd = node2 -> bd;
				}
				people q = p;
				while(q -> next != NULL)
				q = q -> next;
				q -> next = node2;
				printf("����ɹ���\n");
				return;
			}
			else
			{
				printf("�����鼮����������\n");
				return;
			}
		}
		while(node1 -> next != NULL)
		{
			if(strcmp(bookname,node1 -> name) == 0 && strcmp(author,node1 -> author) == 0)
		{
			if(node2 -> borrow_amount <= node1 -> remain)
			{
				node1 -> remain = node1 -> remain - node2 -> borrow_amount;
				if(node2 -> bm <= 8)
				{
					node2 -> ry = node2 -> by;
					node2 -> rm = node2 -> bm + 4;
					node2 -> rd = node2 -> bd;
				}
				else{
					node2 -> ry = node2 -> by + 1;
					node2 -> ry = node2 -> bm - 8;
					node2 -> rd = node2 -> bd;
				}
				people q = p;
				while(q -> next != NULL)
				q = q -> next;
				q -> next = node2;
				printf("����ɹ���\n");
				return;
			}
			else
			{
				printf("�����鼮����������\n");
				return;
			}
		}
		printf("���޴��飡\n");
		return;
	 }
	}
	else if(a == 2 && b == 2)
	{
		people q = p;
		int sum;
		printf("����������ѧ�ţ�\n");
		scanf("%s",&id);
		do
		{
		    	if(strcmp(id,q -> id) == 0)
		    {
			  if(q -> borrow_amount < q -> max_amount)
			  {
			  	printf("����������Ҫ����������Ϣ��|  ���� | ���� | ���� | ʱ�� \n");
		        scanf("%s",bookname);
	    	    scanf("%s",author);
	        	scanf("%d",&sum);
	        	scanf("%d%d%d",&q -> by,&q -> bm,&q -> bd);
	        	if(strcmp(bookname,node1 -> name) == 0 && strcmp(author,node1 -> author) == 0)
		{
			if( sum <= node1 -> remain)
			{
				node1 -> remain = node1 -> remain - sum;
				q -> borrow_amount = q -> borrow_amount + sum;
				if(q -> bm < 8)
				{
					q -> ry = q -> by;
					q -> rm = q -> bm + 4;
					q -> rd = q -> bd;
				}
				else{
					q -> ry = q -> by + 1;
					q -> ry = q -> bm - 8;
					q -> rd = q -> bd;
				}
				printf("����ɹ���\n");
				return;
			}
			else
			{
				printf("�����鼮����������\n");
				return;
			}
		}
		while(node1 -> next != NULL)
		{
			if(strcmp(bookname,node1 -> name) == 0 && strcmp(author,node1 -> author) == 0)
		{
				if( sum <= node1 -> remain)
			{
				node1 -> remain = node1 -> remain - sum;
				q -> borrow_amount = q -> borrow_amount + sum;
				if(q -> bm < 8)
				{
					q -> ry = q -> by;
					q -> rm = q -> bm + 4;
					q -> rd = q -> bd;
				}
				else{
					q -> ry = q -> by + 1;
					q -> ry = q -> bm -8;
					q -> rd = q -> bd;
				}
				printf("����ɹ���\n");
				return;
			}
			else
			{
				printf("�����鼮����������\n");
				return;
			}
		}
		printf("���޴��飡\n");
		return;
	 }
			  }
			   else
			   {
			   		printf("������ͼ���Ѵﵽ���ޣ�\n");
					return; 
			   }
	    	}
	    	q = q -> next;
		}while(q != NULL);
	}
	}
void * return(book head,people p)
{
	
}


