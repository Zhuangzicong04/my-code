#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream> 
#include<algorithm>
using namespace std;
int stud,borr,teac;
struct book//�ṹ��洢һ��ͼ����ϸ��Ϣ��������ṹʵ��ͼ�鴢�档
{ 
	char num[10];//��� 
	char name[10];//���� 
	char author[10];//���� 
	char sort[10];//���� 
	int sum;//ͼ������ 
	int remainumber;//ʣ��ͼ������� 
	struct book *next;// ָ����һ��ͼ����Ϣ��ָ�� 
};

struct student//�ýṹ��洢ѧ����Ϣ
{
char st[10];//ѧ�� 
	char name[10];//���� 
	int nums;
	char lendday[20];//�������� 
	char returndaty[20];//�������� 
}stu[1000];

struct teacher//�ýṹ��洢��ʦ��Ϣ 
{
	char te[10];//���� 
	char name[10];//���� 
	char huandate[15]; //�������� 
	char jiedate[15]; //�������� 
	int nums; 
}tea[1000];

struct borrow//�ṹ������洢���ĵ���Ϣ 
{
	char book[10];
	char user[10];
	char st[10];
	int flag;
	char lendday[20];
}bo[1000];

void choice(){
	cout<< "\t" <<"\t" << "\t"<<"*******************ͼ�����ϵͳ********************"<<endl;
	cout<< "\t" <<"\t" << "\t"<<"***               1.�����ͼ��                  ***"<<endl;
	cout<< "\t" << "\t" <<"\t"<<"***               2.��ѯͼ����Ϣ                ***"<<endl;
	cout<< "\t" << "\t" <<"\t"<<"***               3.����ͼ��                    ***"<<endl;
	cout<< "\t" << "\t" <<"\t"<<"***               4.����ͼ��                    ***"<<endl;
	cout<< "\t" <<"\t" << "\t"<<"***               5.ɾ��ͼ��                    ***"<<endl;
	cout<< "\t" <<"\t" << "\t"<<"***               6.ͳ��ͼ������              ***"<<endl;
	cout<< "\t" << "\t" <<"\t"<<"***               7.ͳ��ͼ���ʣ����            ***"<<endl;
	cout<< "\t" << "\t" <<"\t"<<"***               0.�˳�ϵͳ                    ***"<<endl;
	cout<< "\t" << "\t" <<"\t"<<"***************************************************"<<endl;
}
int bi(char le[],char ri[]){
	int ans1=0;
	int ans2=0;
	for(int i=0;i<=1;i++){
		ans1 = ans1*10 + le[i];
		ans2 = ans2*10 +ri[i];
	}
	if(ans1-ans2>=2){
		return 1;
	}
	else{
		if(ans1-ans2==0){
		  int f1 = 0;
		  int f2 = 0;
		  for(int i=3;i<=4;i++){
		  	f1 = f1*10 + le[i];
		  	f2 = f2*10 + ri[i];
		}
		if(f1-f2>15){
			return 1;
		}
		else{
			return 0;
		}
		}
		else if(ans1-ans2==1){
		  int f1 = 0;
		  int f2 = 0;
		  for(int i=3;i<=4;i++){
		  	f1 = f1*10 + le[i];
		  	f2 = f2*10 + ri[i];
		}
		if(f1+(30-f2)>=15){
			return 1;
		}
		else{
			return 0;
		}
		} 
	}
}
int main(){
	choice();//�˵����� 
	int sel;
	struct book * Head =(struct book*)malloc(sizeof(struct book));//�Ƚ���ͷ��� 
	struct book * p;
	Head -> next = NULL;
	p = Head;
	while(true){
		cout << "��������Ҫ���������:";
		cin>>sel;
		if(sel == 0){
			break;
		}
		else if(sel == 1){//����µ���Ϣ 
			char num[10];
			char name[10];
			char author[10];
			char sort[10];
			int number; 
			int n;
			cout <<"������Ҫ�����ͼ��ĸ���:";
			cin >> n;
			cout << "���������ͼ��ı�š����ơ����ߡ����ࡢ����:" <<endl;
			for(int i=1;i<=n;i++){//������ͼ����Ϣ�ַ����� 
				cin >> num;
				cin >> name;
				cin >> author;
				cin >> sort; 
				cin >> number; 
				struct book* q =(struct book*)malloc(sizeof(struct book));//ÿ������һ������̬������ 
			    strcpy(q -> num,num);//����ı�Ÿ��Ƹ�������Ϣ�� 
			    strcpy(q -> name,name);//��������Ƹ��Ƹ������� 
			    strcpy(q -> author,author);
			    strcpy(q -> sort,sort);
			    q -> sum = number;// ���ͼ��ʱ�鼮��������ʣ���� 
			    q -> remainumber = number;
			    p -> next = q;//ʹ��β�巨�������� 
			    p = q;	
			}
			p -> next = NULL;
		    cout << "ͼ����Ϣ�������" << endl;
		}
		else if(sel == 2){//����ͼ����Ϣ 
			struct book * bk;
		    bk = Head;
		    bk = bk -> next;
		    cout << "ͼ����Ϣ���£�" << endl; 
		    cout << "�������������ڣ�����xx-xx" << endl;
		   	char t[10];
		   	cin >> t;
		    while(bk){//���α���ͼ�����Ϣ 
		    	int flag = 0;
		    	for(int i = 0; i < borr;i ++){//�ڲ��Ľ�����Ϣ�У������ͬѧ���ģ������ 
		    		if(strcmp(bo[i].book,bk -> name) == 0 && bo[i].flag == 0){
		    			flag = 1;
		    			break;
					}
				}
				if(flag == 0){
					cout << "���" << "\t" << "����" << "\t" << "\t" << "����" << endl;
					cout << bk -> num << "\t" << bk -> name << "\t" << bk -> remainumber << ":      " ; 
					cout<<"  ��ʱ���˽���" << endl; 
				}
				else{
				cout << "���" << "\t" << "����" << "\t" << "\t" << "����" << endl;
				cout << bk -> num << "\t" << bk -> name << "\t" << bk -> remainumber << ":      " ;
				cout << "���ĸ�ͼ������У�" ; 
				 for(int i = 0;i < borr;i++){
		    		if(strcmp(bo[i].book,bk -> name) == 0 && bo[i].flag == 0){
		    			cout << bo[i].st << " " << bo[i].user << " ";
		    			     int a = 0;
							 a = bi(t,bo[i].lendday);
							 if(a == 0){
							 	cout<<"   ��������Ч����" << endl;
							 }	
							 else{
							 	cout<<"    �����Ѿ���������" << endl; 
							 }
					}
				}
					
				}
				bk = bk->next;
		   }
		   char sss[10];
		   int fl = 0; 
		   cout<<"������Ҫ��ѯ���������ѧ��������:"<<endl;
		   cin >> sss;
		   for(int i = 0;i < borr;i ++){
		   	if(strcmp(bo[i].user,sss) == 0&&bo[i].flag == 0){
		   		fl=1;
			   }
		   }
		   if(fl==0){
		   	cout<<"��ͬѧû�н��ĵ��鼮:"<<endl;
		   }
		   else {
		   	for(int i = 0;i<borr;i++){
		   	   if(strcmp(bo[i].user,sss) == 0 && bo[i].flag == 0){
		   		  cout<<bo[i].book<<"  ";
		   		  struct book* bkk;
		   		  bkk = Head;
		   		  bkk = bkk->next;
		   		  while(bkk){
		   		  	if(strcmp(bkk->name,bo[i].book)==0){
		   		  	    cout << bkk->num << "  " << bkk->sort << "  " << bkk->author << "  " << bkk -> remainumber << endl;
					   }
					   bkk = bkk->next;
					 }
			   }
			   cout<<endl;
		   }
		   	cout<<endl;
		   }
			
		} 
		else if(sel==3){// ����ͼ��
		  cout << "������ͼ�������:";
		  char ss[10];
		  cin >> ss;
		  char lei[10];
		  char na[10];
		  int flag = 0;
		  cout << "������������:";
		  cin >> lei;
		  struct book* ls;
		  ls = Head;
		  ls = ls->next;
		  while(ls){//�����������鿴�Ƿ����Ȿͼ�� 
		  	if(strcmp(ss,ls->name) == 0){//���ĵ�ͼ�������ڣ���������Ҫ����0 
		  		strcpy(lei,ls->sort);//�����ิ�Ƹ�lei�� 
		  		if(ls->remainumber>0){
			  		flag=1;
			  		break;
		  	    }
			  }
			  ls = ls->next;
	      }
	      if(flag==0){//��ʾͼ�������������ҵ��鼮 
	      	cout<<"ͼ�����û����Ҫ���ҵ��鼮������ʣ����Ϊ0��Ҳ���ܲ����ڸ��鼮"<<endl;
	      	cout<<"Ϊ���Ƽ����¼�����"<<endl; 
			struct book* lss;
			lss = Head;
			lss= lss->next;
			while(lss){
				if(strcmp(lss->sort,lei)==0){
					cout<<lss->num<<" "<<lss->name<<" "<<lss->author<<endl;
				}
				lss = lss->next;
			}
		  }
	      else if(flag==1){//�鼮���� 
	       ls->remainumber = ls->remainumber-1;//���ģ�ͼ�������-1�� 
	      	char stt[10];
	      	cout<<"���������ѧ��:";
	      	cin>>stt;
	      	cout<<"�������������:";
			cin>>na;
			char sd[10];
			cout<<"�������������:";
			cin>>sd;
			strcpy(bo[borr].st,stt);//��ѧ�Ÿ��Ƶ����ı��� 
			strcpy(bo[borr].user,na);
	      	strcpy(bo[borr].book,ss);
	      	strcpy(bo[borr].lendday,sd);
	      	borr++;
	      	cout<<"ͼ��������"<<endl;
		  }	
		}
		else if(sel==4){//���� 
			char s[10]; 
			char ss[10];
			cout<<"�������������:";
			cin>>ss;
			cout<<"�������㻹��ͼ�����ƣ�";
			cin>>s;
			struct book* ls;
		    ls=Head;
		    ls=ls->next; 
		    while(ls){//������������ƣ������������ҵ�֮�󣬶�Ӧ������+1 
		    	if(strcmp(ls->name,s)==0){
		    		ls->remainumber++;
		    		for(int i=0;i<borr;i++){//����Ӧ�Ľ��ı��е���Ϣ�ҳ�����Ȼ����flag=1���� 
		    			if(strcmp(bo[i].book,s)==0 && strcmp(bo[i].user,ss)==0){
		    				bo[i].flag=1;
		    				
						}
					}
					break;
				}
				ls = ls->next;
			}
			cout<<"����ɹ�"<<endl; 
		}
		else if(sel==5){//ɾ��ͼ�顣
		    struct book* ls;
		    ls=Head;
		    cout<<"��������Ҫɾ����ͼ������:";
			char s[10];
			cin>>s;
			struct book* pre;
			pre = ls;
			ls = ls->next;
			while(ls){//�������ɾ�� 
				if(strcmp(ls->name,s)==0){
					break;
				}
				pre = ls;
				ls = ls->next;
			}
		   pre->next=ls->next;
		   delete(ls);
		  cout<<"ɾ�����"<<endl; 
		}
		else if(sel==6){//�������� 
			int ans=0;
			struct book* bk;
		    bk = Head;
		    bk = bk->next;
		    while(bk){//������������ԭʼ����������ȥ���ڵ����� 
		   	  cout<<bk->num<<"  "<<bk->name<<" �Ľ����Ϊ"<<bk->sum-bk->remainumber<<endl; 
		   	   bk = bk->next;
		   }
		}
		else if(sel==7){//��ʣ���ͼ������ 
			int ans=0;
			struct book* bk;
		    bk = Head;
		    bk = bk->next;
		    while(bk){
		   	cout<<bk->num<<"  "<<bk->name<<" ��ʣ����Ϊ"<<bk->remainumber<<endl;
		   	bk = bk->next;
		   }
		}
		cout << endl << endl;
	}
	return 0;
}

