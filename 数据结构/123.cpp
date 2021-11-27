#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct bookNode {
	char bookName[50];
	int bookNum;
	float bookPrice;
	struct bookNode *nextBookNode;
}bookNode;

bookNode *appendBook(bookNode *head);

void *searchBook(bookNode *head);

void modifyBook(bookNode *head);

bookNode *deleteBook(bookNode *head);

void freeAllNode(bookNode *head);

void showAllBook(bookNode *head);
int main() {
	int option;
	bookNode *head = NULL;

	printf("1. 添加图书\n");
	printf("2. 查询图书信息\n");
	printf("3. 修改图书价格\n");
	printf("4. 删除图书\n");
	printf("5. 查看所有图书\n");
	printf("6. 退出\n");
	while(printf("\n>请输入选项：") && (scanf("%d", &option) == 1))
	{
		switch (option)
		{
		case 1:
			head = appendBook(head);
			break;
		case 2:
			searchBook(head);
			break;
		case 3:
			modifyBook(head);
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
			printf("错误选项，请重新输入。\n");
			break;
		}
	}
	return 0; 
}

bookNode *appendBook(bookNode * head)
{
	bookNode *book = (bookNode*)malloc(sizeof(bookNode));
	printf("请输入添加图书的书名：");
	scanf("%s", book->bookName);

	printf("请输入添加图书的编号：");
	scanf("%d", &book->bookNum);

	printf("请输入添加图书的价格：");
	scanf("%f", &book->bookPrice);
	book->nextBookNode = NULL;

	if (head == NULL) {
		head = book;
	}
	else {
		bookNode *pNode = head;
		while (pNode->nextBookNode != NULL) {
			pNode = pNode->nextBookNode;
		}
		pNode->nextBookNode = book;

	}
	printf("图书添加成功！\n");
	return head;
}

void *searchBook(bookNode * head)
{
	bookNode *pNode = head;
	if (pNode == NULL) {
		printf("暂无图书\n");
		return NULL;
	}
	else {
		printf("请输入查找图书的书名: ");
		char bookName[50] = {0};
		scanf("%s", bookName);
		printf("查询结果：\n");
		if (strcmp(bookName, pNode->bookName) == 0) {
			printf("图书书名：%s\n", pNode->bookName);
			printf("图书编号：%d\n", pNode->bookNum);
			printf("图书价格：%.2f\n", pNode->bookPrice);
			return pNode;
		}
		while (pNode->nextBookNode != NULL) {
			pNode = pNode->nextBookNode;
			if (strcmp(bookName, pNode->bookName) == 0) {
				printf("图书书名：%s\n", pNode->bookName);
				printf("图书编号：%d\n", pNode->bookNum);
				printf("图书价格：%.2f\n", pNode->bookPrice);
				return pNode;
			}
		}
		printf("暂无此书\n");
		return NULL;
	}
}

void modifyBook(bookNode * head)
{
	char bookName[50];
	float newBookPrice;


	bookNode *pNode = head;
	if (pNode == NULL) {
		printf("暂无图书\n");
		
	}
	else {
		printf("请输入要修改价格图书的书名: ");
		scanf("%s", bookName);

		if (strcmp(bookName, pNode->bookName) == 0) {

			printf("请输入修图书改后的价格: ");
			scanf("%f", &newBookPrice);
			pNode->bookPrice = newBookPrice;
			printf("图书价格修改成功!\n");
			return;
		}
		else {
			while (pNode->nextBookNode != NULL) {
				pNode = pNode->nextBookNode;
				if (strcmp(bookName, pNode->bookName) == 0) {
					printf("请输入修图书改后的价格: ");
					scanf("%f", &newBookPrice);
					pNode->bookPrice = newBookPrice;
					printf("图书价格修改成功!\n");
					return;
				}
			}
		}
		printf("暂无此书\n");

	}

}

bookNode * deleteBook(bookNode * head)
{
	bookNode *pNode = head;
	if (pNode == NULL) {
		printf("暂无图书\n");
	}

	char bookName[50];
	printf("请输入要删除图书的书名：");
	scanf("%s", bookName);
	//删除图书为头节点
	if (strcmp(bookName, pNode->bookName) == 0) {
		head = head->nextBookNode;
		free(pNode);
		printf("删除成功!\n");
		return head;
	}
	else {
		while (pNode->nextBookNode != NULL) {
			if (strcmp(bookName, pNode->nextBookNode->bookName) == 0) {
				bookNode* tempNode = pNode->nextBookNode;
				pNode->nextBookNode = pNode->nextBookNode->nextBookNode;
				free(tempNode);
				printf("删除成功!\n");
				return head;
			}
			pNode = pNode->nextBookNode;
		}
		printf("暂无此书\n");
		return head;
	}
}

void freeAllNode(bookNode * head)
{
	bookNode *pNode = head;
	while (head != NULL) {
		head = head->nextBookNode;
		free(pNode);
		pNode = head;
	}

	exit(0);
}

void showAllBook(bookNode * head)
{
	
	if (head == NULL) {
		printf("暂无图书\n");
		return;
	}
	else {
		printf("所有图书：\n");
		bookNode *pNode = head;
		printf("%s\n", pNode->bookName);
		while (pNode->nextBookNode != NULL) {
			pNode = pNode->nextBookNode;
			printf("%s\n", pNode->bookName);
		}
	}
	return ;
}
