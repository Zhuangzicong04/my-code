#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream> 
#include<algorithm>
using namespace std;
int stud,borr,teac;
struct book//结构体存储一本图书详细信息，单链表结构实现图书储存。
{ 
	char num[10];//编号 
	char name[10];//书名 
	char author[10];//作者 
	char sort[10];//种类 
	int sum;//图书总量 
	int remainumber;//剩余图书的数量 
	struct book *next;// 指向下一本图书信息的指针 
};

struct student//用结构体存储学生信息
{
char st[10];//学号 
	char name[10];//姓名 
	int nums;
	char lendday[20];//借书日期 
	char returndaty[20];//还书日期 
}stu[1000];

struct teacher//用结构体存储教师信息 
{
	char te[10];//工号 
	char name[10];//姓名 
	char huandate[15]; //借书日期 
	char jiedate[15]; //还书日期 
	int nums; 
}tea[1000];

struct borrow//结构体数组存储借阅的信息 
{
	char book[10];
	char user[10];
	char st[10];
	int flag;
	char lendday[20];
}bo[1000];

void choice(){
	cout<< "\t" <<"\t" << "\t"<<"*******************图书管理系统********************"<<endl;
	cout<< "\t" <<"\t" << "\t"<<"***               1.添加新图书                  ***"<<endl;
	cout<< "\t" << "\t" <<"\t"<<"***               2.查询图书信息                ***"<<endl;
	cout<< "\t" << "\t" <<"\t"<<"***               3.借阅图书                    ***"<<endl;
	cout<< "\t" << "\t" <<"\t"<<"***               4.还阅图书                    ***"<<endl;
	cout<< "\t" <<"\t" << "\t"<<"***               5.删除图书                    ***"<<endl;
	cout<< "\t" <<"\t" << "\t"<<"***               6.统计图书借出量              ***"<<endl;
	cout<< "\t" << "\t" <<"\t"<<"***               7.统计图书的剩余量            ***"<<endl;
	cout<< "\t" << "\t" <<"\t"<<"***               0.退出系统                    ***"<<endl;
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
	choice();//菜单函数 
	int sel;
	struct book * Head =(struct book*)malloc(sizeof(struct book));//先建立头结点 
	struct book * p;
	Head -> next = NULL;
	p = Head;
	while(true){
		cout << "请输入你要操作的序号:";
		cin>>sel;
		if(sel == 0){
			break;
		}
		else if(sel == 1){//添加新的信息 
			char num[10];
			char name[10];
			char author[10];
			char sort[10];
			int number; 
			int n;
			cout <<"请输入要添加新图书的个数:";
			cin >> n;
			cout << "请输入添加图书的编号、名称、作者、种类、数量:" <<endl;
			for(int i=1;i<=n;i++){//将几个图书信息轮番插入 
				cin >> num;
				cin >> name;
				cin >> author;
				cin >> sort; 
				cin >> number; 
				struct book* q =(struct book*)malloc(sizeof(struct book));//每次遇到一个都动态申请结点 
			    strcpy(q -> num,num);//将书的编号复制给链表信息中 
			    strcpy(q -> name,name);//将书的名称复制给链表中 
			    strcpy(q -> author,author);
			    strcpy(q -> sort,sort);
			    q -> sum = number;// 添加图书时书籍总量等于剩余量 
			    q -> remainumber = number;
			    p -> next = q;//使用尾插法建立链表 
			    p = q;	
			}
			p -> next = NULL;
		    cout << "图书信息插入完毕" << endl;
		}
		else if(sel == 2){//查阅图书信息 
			struct book * bk;
		    bk = Head;
		    bk = bk -> next;
		    cout << "图书信息如下：" << endl; 
		    cout << "请输入今天的日期，采用xx-xx" << endl;
		   	char t[10];
		   	cin >> t;
		    while(bk){//依次遍历图书的信息 
		    	int flag = 0;
		    	for(int i = 0; i < borr;i ++){//在查阅借书信息中，如果有同学借阅，则输出 
		    		if(strcmp(bo[i].book,bk -> name) == 0 && bo[i].flag == 0){
		    			flag = 1;
		    			break;
					}
				}
				if(flag == 0){
					cout << "编号" << "\t" << "书名" << "\t" << "\t" << "数量" << endl;
					cout << bk -> num << "\t" << bk -> name << "\t" << bk -> remainumber << ":      " ; 
					cout<<"  暂时无人借阅" << endl; 
				}
				else{
				cout << "编号" << "\t" << "书名" << "\t" << "\t" << "数量" << endl;
				cout << bk -> num << "\t" << bk -> name << "\t" << bk -> remainumber << ":      " ;
				cout << "借阅该图书的人有：" ; 
				 for(int i = 0;i < borr;i++){
		    		if(strcmp(bo[i].book,bk -> name) == 0 && bo[i].flag == 0){
		    			cout << bo[i].st << " " << bo[i].user << " ";
		    			     int a = 0;
							 a = bi(t,bo[i].lendday);
							 if(a == 0){
							 	cout<<"   借书在有效期内" << endl;
							 }	
							 else{
							 	cout<<"    借书已经超过期限" << endl; 
							 }
					}
				}
					
				}
				bk = bk->next;
		   }
		   char sss[10];
		   int fl = 0; 
		   cout<<"请输入要查询借书情况的学生的名字:"<<endl;
		   cin >> sss;
		   for(int i = 0;i < borr;i ++){
		   	if(strcmp(bo[i].user,sss) == 0&&bo[i].flag == 0){
		   		fl=1;
			   }
		   }
		   if(fl==0){
		   	cout<<"该同学没有借阅的书籍:"<<endl;
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
		else if(sel==3){// 借阅图书
		  cout << "请输入图书的名称:";
		  char ss[10];
		  cin >> ss;
		  char lei[10];
		  char na[10];
		  int flag = 0;
		  cout << "请输入书的类别:";
		  cin >> lei;
		  struct book* ls;
		  ls = Head;
		  ls = ls->next;
		  while(ls){//遍历单链表，查看是否有这本图书 
		  	if(strcmp(ss,ls->name) == 0){//查阅的图书必须存在，并且数量要大于0 
		  		strcpy(lei,ls->sort);//把种类复制给lei， 
		  		if(ls->remainumber>0){
			  		flag=1;
			  		break;
		  	    }
			  }
			  ls = ls->next;
	      }
	      if(flag==0){//表示图书库中无所需查找的书籍 
	      	cout<<"图书库中没有你要查找的书籍，可能剩余量为0，也可能不存在该书籍"<<endl;
	      	cout<<"为您推荐以下几本书"<<endl; 
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
	      else if(flag==1){//书籍存在 
	       ls->remainumber = ls->remainumber-1;//借阅，图书的数量-1； 
	      	char stt[10];
	      	cout<<"请输入你的学号:";
	      	cin>>stt;
	      	cout<<"请输入你的姓名:";
			cin>>na;
			char sd[10];
			cout<<"请输入今日日期:";
			cin>>sd;
			strcpy(bo[borr].st,stt);//将学号复制到借阅表中 
			strcpy(bo[borr].user,na);
	      	strcpy(bo[borr].book,ss);
	      	strcpy(bo[borr].lendday,sd);
	      	borr++;
	      	cout<<"图书借阅完成"<<endl;
		  }	
		}
		else if(sel==4){//还书 
			char s[10]; 
			char ss[10];
			cout<<"请输入你的姓名:";
			cin>>ss;
			cout<<"请输入你还的图书名称：";
			cin>>s;
			struct book* ls;
		    ls=Head;
		    ls=ls->next; 
		    while(ls){//与上述情况类似，遍历单链表，找到之后，对应的数量+1 
		    	if(strcmp(ls->name,s)==0){
		    		ls->remainumber++;
		    		for(int i=0;i<borr;i++){//将对应的借阅表中的信息找出来，然后令flag=1即可 
		    			if(strcmp(bo[i].book,s)==0 && strcmp(bo[i].user,ss)==0){
		    				bo[i].flag=1;
		    				
						}
					}
					break;
				}
				ls = ls->next;
			}
			cout<<"还书成功"<<endl; 
		}
		else if(sel==5){//删除图书。
		    struct book* ls;
		    ls=Head;
		    cout<<"请输入你要删除的图书名称:";
			char s[10];
			cin>>s;
			struct book* pre;
			pre = ls;
			ls = ls->next;
			while(ls){//单链表的删除 
				if(strcmp(ls->name,s)==0){
					break;
				}
				pre = ls;
				ls = ls->next;
			}
		   pre->next=ls->next;
		   delete(ls);
		  cout<<"删除完毕"<<endl; 
		}
		else if(sel==6){//求借出量， 
			int ans=0;
			struct book* bk;
		    bk = Head;
		    bk = bk->next;
		    while(bk){//求借出量，等于原始的数量，减去现在的数量 
		   	  cout<<bk->num<<"  "<<bk->name<<" 的借出量为"<<bk->sum-bk->remainumber<<endl; 
		   	   bk = bk->next;
		   }
		}
		else if(sel==7){//求剩余的图书数量 
			int ans=0;
			struct book* bk;
		    bk = Head;
		    bk = bk->next;
		    while(bk){
		   	cout<<bk->num<<"  "<<bk->name<<" 的剩余量为"<<bk->remainumber<<endl;
		   	bk = bk->next;
		   }
		}
		cout << endl << endl;
	}
	return 0;
}

