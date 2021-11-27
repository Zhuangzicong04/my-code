#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream> 
#include<algorithm>
using namespace std;
int stud,borr,teac;
struct book{//结构体存储一本图书详细信息，单链表结构存储所有图书。 
	char num[20];
	char name[20];
	char author[20];
	char sort[20];
	int prenumber; 
	int donnumber;
	struct book *next;
};
struct student{//用结构体存储学生数据 
	char st[10];
	char name[10];
	int nums;
	char jsdate[20];
	char hsdate[20];
}stu[1000];

struct borrow{//结构体数组存储学生借阅的信息 
	char book[10];
	char user[10];
	char st[10];
	int flag;
	char jsdate[20];
}bo[1000];

struct teacher{//用来存储教职工的信息 
	char te[10];
	char name[10];
	char huandate[15];
	char jiedate[15];
	int nums;	
}tea[1000];

void menuprint(){
	cout<<"**************图书管理系统**************"<<endl;
	cout<<"***          1.添加新图书            ***"<<endl;
	cout<<"***          2.查询图书信息          ***"<<endl;
	cout<<"***          3.借阅图书              ***"<<endl;
	cout<<"***          4.还阅图书              ***"<<endl;
	cout<<"***          5.删除图书              ***"<<endl;
	cout<<"***          6.统计图书借出量        ***"<<endl;
	cout<<"***          7.统计图书的剩余量      ***"<<endl;
	cout<<"***          0.退出系统              ***"<<endl;
	cout<<"****************************************"<<endl;
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
int main(void){
	menuprint();//菜单函数 
	int sel;
	struct book* Head =(struct book*)malloc(sizeof(struct book));//先建立头结点 
	struct book* p;
	Head->next = NULL;
	p = Head;
	while(true){
		cout<<"请输入你要操作的序号:";
		cin>>sel;
		if(sel==0){
			break;
		}
		else if(sel==1){//添加新的信息 
			char num[10];
			char name[10];
			char author[10];
			char sort[10];
			int number; 
			int n;
			cout<<"请输入要添加新图书的个数:";
			cin>>n;
			cout<<"请输入添加图书的编号、名称、作者、种类、数量:"<<endl;
			for(int i=1;i<=n;i++){//将几个图书信息轮番插入 
				cin>>num;
				cin>>name;
				cin>>author;
				cin>>sort; 
				cin>>number; 
				struct book* q =(struct book*)malloc(sizeof(struct book));//每次遇到一个都动态申请结点 
			    strcpy(q->num,num);//将书的编号复制给链表信息中 
			    strcpy(q->name,name);//将书的名称复制给链表中，下面也是一样 
			    strcpy(q->author,author);
			    strcpy(q->sort,sort);
			    q->prenumber = number;//使用尾插法建立链表 
			    q->donnumber = number;
			    p->next = q;
			    p = q;	
			}
			p->next=NULL;
		    cout<<"图书信息插入完毕"<<endl;
		}
		else if(sel==2){//查阅图书信息 
			struct book* bk;
		    bk = Head;
		    bk = bk->next;
		    cout<<"图书信息如下："<<endl; 
		    cout<<"请输入今天的日期，采用xx-xx"<<endl;
		   	char t[10];
		   	cin>>t;
		    while(bk){//依次遍历图书的信息 
		    	int flag=0;
		    	for(int i=0;i<borr;i++){//在查阅借书信息中，如果有同学借阅，则输出 
		    		if(strcmp(bo[i].book,bk->name)==0&&bo[i].flag==0){
		    			flag=1;
		    			break;
					}
				}
				if(flag==0){
					cout<< bk->num<<" "<<bk->name<<" "<<bk->donnumber<<":      "; 
					cout<<"  暂时无人借阅"<<endl; 
				}
				else{
				cout<< bk->num<<" "<<bk->name<<" "<<bk->donnumber; 
				cout<<"借阅该图书的人有："<<endl; 
				 for(int i=0;i<borr;i++){
		    		if(strcmp(bo[i].book,bk->name)==0&&bo[i].flag==0){
		    			cout<<bo[i].st<<" "<<bo[i].user<<" ";
		    			int a=0;
							 a = bi(t,bo[i].jsdate);
							 if(a==0){
							 	cout<<"   借书在有效期内"<<endl;
							 }	
							 else{
							 	cout<<"    借书已经超过期限"<<endl; 
							 }
					}
				}
					
				}
				bk = bk->next;
		   }
		   char sss[10];
		   int fl=0; 
		   cout<<"请输入要查询借书情况的学生的名字:"<<endl;
		   cin>>sss;
		   for(int i=0;i<borr;i++){
		   	if(strcmp(bo[i].user,sss)==0&&bo[i].flag==0){
		   		fl=1;
			   }
		   }
		   if(fl==0){
		   	cout<<"该同学没有借阅的书籍:"<<endl;
		   }
		   else {
		   	for(int i=0;i<borr;i++){
		   	   if(strcmp(bo[i].user,sss)==0&&bo[i].flag==0){
		   		  cout<<bo[i].book<<"  ";
		   		  struct book* bkk;
		   		  bkk=Head;
		   		  bkk = bkk->next;
		   		  while(bkk){
		   		  	if(strcmp(bkk->name,bo[i].book)==0){
		   		  	    cout<<bkk->num<<"  "<<bkk->sort<<"  "<<bkk->author<<"  "<<bkk->donnumber<<endl;
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
		  cout<<"请输入图书的名称:";
		  char ss[10];
		  cin>>ss;
		  char lei[10];
		  char na[10];
		  int flag=0;
		  cout<<"请输入书的类别:";
		  cin>>lei;
		  struct book* ls;
		  ls=Head;
		  ls=ls->next;
		  while(ls){//遍历单链表，查看是否有这本图书 
		  	if(strcmp(ss,ls->name)==0){//查阅的图书必须存在，并且数量要大于0 
		  		strcpy(lei,ls->sort);//把种类复制给lei， 
		  		if(ls->donnumber>0){
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
	       ls->donnumber = ls->donnumber-1;//借阅，图书的数量-1； 
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
	      	strcpy(bo[borr].jsdate,sd);
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
		    		ls->donnumber++;
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
		   	  cout<<bk->num<<"  "<<bk->name<<" 的借出量为"<<bk->prenumber-bk->donnumber<<endl; 
		   	   bk = bk->next;
		   }
		}
		else if(sel==7){//求剩余的图书数量 
			int ans=0;
			struct book* bk;
		    bk = Head;
		    bk = bk->next;
		    while(bk){
		   	cout<<bk->num<<"  "<<bk->name<<" 的剩余量为"<<bk->donnumber<<endl;
		   	bk = bk->next;
		   }
		}
	}
	return 0;
} 
/*105 数据结构 张三 计科 100
106 操作系统  李四  计科 100
104 程序设计 王五 计科 100
103 编译原理 小刘  计科 100
107 离散数学  小庄 数学 100
102 高等数学  小张 数学 100
101 线性代数  大明 数学 100
