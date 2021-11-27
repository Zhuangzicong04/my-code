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

	printf("1. ���ͼ��\n");
	printf("2. ��ѯͼ����Ϣ\n");
	printf("3. �޸�ͼ��۸�\n");
	printf("4. ɾ��ͼ��\n");
	printf("5. �鿴����ͼ��\n");
	printf("6. �˳�\n");
	while(printf("\n>������ѡ�") && (scanf("%d", &option) == 1))
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
			printf("����ѡ����������롣\n");
			break;
		}
	}
	return 0; 
}

bookNode *appendBook(bookNode * head)
{
	bookNode *book = (bookNode*)malloc(sizeof(bookNode));
	printf("���������ͼ���������");
	scanf("%s", book->bookName);

	printf("���������ͼ��ı�ţ�");
	scanf("%d", &book->bookNum);

	printf("���������ͼ��ļ۸�");
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
	printf("ͼ����ӳɹ���\n");
	return head;
}

void *searchBook(bookNode * head)
{
	bookNode *pNode = head;
	if (pNode == NULL) {
		printf("����ͼ��\n");
		return NULL;
	}
	else {
		printf("���������ͼ�������: ");
		char bookName[50] = {0};
		scanf("%s", bookName);
		printf("��ѯ�����\n");
		if (strcmp(bookName, pNode->bookName) == 0) {
			printf("ͼ��������%s\n", pNode->bookName);
			printf("ͼ���ţ�%d\n", pNode->bookNum);
			printf("ͼ��۸�%.2f\n", pNode->bookPrice);
			return pNode;
		}
		while (pNode->nextBookNode != NULL) {
			pNode = pNode->nextBookNode;
			if (strcmp(bookName, pNode->bookName) == 0) {
				printf("ͼ��������%s\n", pNode->bookName);
				printf("ͼ���ţ�%d\n", pNode->bookNum);
				printf("ͼ��۸�%.2f\n", pNode->bookPrice);
				return pNode;
			}
		}
		printf("���޴���\n");
		return NULL;
	}
}

void modifyBook(bookNode * head)
{
	char bookName[50];
	float newBookPrice;


	bookNode *pNode = head;
	if (pNode == NULL) {
		printf("����ͼ��\n");
		
	}
	else {
		printf("������Ҫ�޸ļ۸�ͼ�������: ");
		scanf("%s", bookName);

		if (strcmp(bookName, pNode->bookName) == 0) {

			printf("��������ͼ��ĺ�ļ۸�: ");
			scanf("%f", &newBookPrice);
			pNode->bookPrice = newBookPrice;
			printf("ͼ��۸��޸ĳɹ�!\n");
			return;
		}
		else {
			while (pNode->nextBookNode != NULL) {
				pNode = pNode->nextBookNode;
				if (strcmp(bookName, pNode->bookName) == 0) {
					printf("��������ͼ��ĺ�ļ۸�: ");
					scanf("%f", &newBookPrice);
					pNode->bookPrice = newBookPrice;
					printf("ͼ��۸��޸ĳɹ�!\n");
					return;
				}
			}
		}
		printf("���޴���\n");

	}

}

bookNode * deleteBook(bookNode * head)
{
	bookNode *pNode = head;
	if (pNode == NULL) {
		printf("����ͼ��\n");
	}

	char bookName[50];
	printf("������Ҫɾ��ͼ���������");
	scanf("%s", bookName);
	//ɾ��ͼ��Ϊͷ�ڵ�
	if (strcmp(bookName, pNode->bookName) == 0) {
		head = head->nextBookNode;
		free(pNode);
		printf("ɾ���ɹ�!\n");
		return head;
	}
	else {
		while (pNode->nextBookNode != NULL) {
			if (strcmp(bookName, pNode->nextBookNode->bookName) == 0) {
				bookNode* tempNode = pNode->nextBookNode;
				pNode->nextBookNode = pNode->nextBookNode->nextBookNode;
				free(tempNode);
				printf("ɾ���ɹ�!\n");
				return head;
			}
			pNode = pNode->nextBookNode;
		}
		printf("���޴���\n");
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
		printf("����ͼ��\n");
		return;
	}
	else {
		printf("����ͼ�飺\n");
		bookNode *pNode = head;
		printf("%s\n", pNode->bookName);
		while (pNode->nextBookNode != NULL) {
			pNode = pNode->nextBookNode;
			printf("%s\n", pNode->bookName);
		}
	}
	return ;
}
