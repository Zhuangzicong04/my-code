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
	printf("1. 添加图书\n");
	printf("2. 查询图书信息\n");
	printf("3. 删除图书\n");
	printf("4. 借书\n");
	printf("5. 还书\n");
	printf("6. 分类统计\n");
	printf("6. 退出\n");
	while(printf("\n>请输入选项：") && (scanf("%d", &option) == 1))
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
			printf("错误选项，请重新输入。\n");
			break;*/
		}
	}
	return 0; 
}
book create(book head){
	book node = (book)malloc(sizeof(struct Book));
	printf("请输入图书信息\n|  编号  |  书名  |  作者  |  种类  |  数量\n");
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
	printf("图书添加成功！");
	return head;
}
book delete(book head){
	book p,q;
	char id[50];
	p = head;
	if(p == NULL)
	{
		printf("暂无图书！\n");
	    return head;
	}
		q = head -> next;
		printf("请输入你想删除的图书编号：");
	    scanf("%s",id);
	    if(strcmp(id,p -> id) == 0)
	    {
	    	head = q;
	    	free(p);
	    	printf("删除成功！\n");
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
					printf("删除成功!\n");
					return head;
				}
				p = q;
				q = q -> next;
			}
			printf("暂无此书！\n");
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
		printf("暂无图书\n");
		return; 
	}
	if(p == NULL)
	{
		p = node2;
	}
	printf("欢迎来到借阅系统，您是老师请输入1，是学生请输入2\n");
	scanf("%d",&a);
	printf("您是第一次来借书吗？,是的话请输入1，不是请输入2\n");
	scanf("%d",&b);
	if(a == 1 && b == 1)
	{
		printf("请输入您的工号："); 
		scanf("%s",node2 -> id);
		node2 -> license = 1;
		node2 -> max_amount = 15; 
		printf("请输入您想要借书的相关信息：| 姓名 | 书名 | 作者 | 数量 | 时间 \n");
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
				printf("借书成功！\n");
				return;
			}
			else
			{
				printf("所借书籍数量不够！\n");
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
				printf("借书成功！\n");
				return;
			}
			else
			{
				printf("所借书籍数量不够！\n");
				return;
			}
		}
		printf("查无此书！\n");
		return;
	 }
	}
	else if(a == 1 && b == 2)
	{
		people q = p;
		int sum;
		printf("请输入您的工号：\n");
		scanf("%s",&id);
		do
		{
		    	if(strcmp(id,q -> id) == 0)
		    {
			  if(q -> borrow_amount < q -> max_amount)
			  {
			  	printf("请输入您想要借书的相关信息：|  书名 | 作者 | 数量 | 时间 \n");
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
				printf("借书成功！\n");
				return;
			}
			else
			{
				printf("所借书籍数量不够！\n");
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
				printf("借书成功！\n");
				return;
			}
			else
			{
				printf("所借书籍数量不够！\n");
				return;
			}
		}
		printf("查无此书！\n");
		return;
	 }
			  }
			   else
			   {
			   		printf("您所借图书已达到上限！\n");
					return; 
			   }
	    	}
	    	q = q -> next;
		}while(q != NULL);
	}
	else if(a == 2 && b == 1)
	{
		printf("请输入您的学号："); 
		scanf("%s",node2 -> id);
		node2 -> license = 2;
		node2 -> max_amount = 10; 
		printf("请输入您想要借书的相关信息：| 姓名 | 书名 | 作者 | 数量 | 时间\n ");
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
				printf("借书成功！\n");
				return;
			}
			else
			{
				printf("所借书籍数量不够！\n");
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
				printf("借书成功！\n");
				return;
			}
			else
			{
				printf("所借书籍数量不够！\n");
				return;
			}
		}
		printf("查无此书！\n");
		return;
	 }
	}
	else if(a == 2 && b == 2)
	{
		people q = p;
		int sum;
		printf("请输入您的学号：\n");
		scanf("%s",&id);
		do
		{
		    	if(strcmp(id,q -> id) == 0)
		    {
			  if(q -> borrow_amount < q -> max_amount)
			  {
			  	printf("请输入您想要借书的相关信息：|  书名 | 作者 | 数量 | 时间 \n");
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
				printf("借书成功！\n");
				return;
			}
			else
			{
				printf("所借书籍数量不够！\n");
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
				printf("借书成功！\n");
				return;
			}
			else
			{
				printf("所借书籍数量不够！\n");
				return;
			}
		}
		printf("查无此书！\n");
		return;
	 }
			  }
			   else
			   {
			   		printf("您所借图书已达到上限！\n");
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


