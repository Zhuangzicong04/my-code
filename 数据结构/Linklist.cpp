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

struct Student{
	char id[4];
	char name[30];
	int  amount = 10;
	int by,bm,bd;
	int ry,rm,rd;
	struct Student * next;
};
typedef struct Student * student;

struct Teacher{
	char id[4];
	char name[30];
	int  amount = 15;
	int  by,bm,bd;
	int  ry,rm,rd;
	struct Teacher * next;
};
typedef struct Teacher * teacher;

book create(book head);
int main()
{
	int option;
	book head = NULL;
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
		case 2:
			search(head);
			break;
		case 3:
			delete(head);
			break;
		case 4:
			head = deleteBook(head);
			break;
		case 5:
			showAllBook(head);
			break;
		case 6:
			freeAllNode(head);
			break;
		default:
			printf("����ѡ����������롣\n");
			break;
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




