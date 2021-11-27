#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream> 
#include<algorithm>
using namespace std;
int stud,borr,teac;
struct treebook{//结构图存放单个的图书信息，二叉排序树存放所有的图书信息 
	char num[10];//图书编号 
	char name[10];//图书名称 
	char author[10];//图书作者 
	char sort[10];//图书种类 
	int sum;//记录总的书量 
	int remainnumber;//记录动态的书量 
	struct treebook* left;//左子树的地址 
	struct treebook* right ;//右子树的地址 
};

struct teacher{//老师的信息 
	char te[10];
	char name[10];
	char huandate[15];
	char jiedate[15];
	int nums;	
}tea[1000];

struct student{//存储学生的信息 
	char st[10];
	char name[10];
	int nums;
}stu[1000];

struct borrow{//借阅图书的信息 
	char book[10];
	char user[10];
	char st[10];
	char num[10];
	char jsdate[10];
	int flag;
}bo[1000];


void menuprint(){
	cout<<"\t" <<"**************图书管理系统**************"<<endl;
	cout<< "\t"<<"***          1.添加新图书            ***"<<endl;
	cout<<"\t" <<"***          2.查询图书信息          ***"<<endl;
	cout<< "\t"<<"***          3.借阅图书              ***"<<endl;
	cout<< "\t"<<"***          4.还阅图书              ***"<<endl;
	cout<<"\t" <<"***          5.删除图书              ***"<<endl;
	cout<<"\t" <<"***          6.统计图书借出量        ***"<<endl;
	cout<<"\t" <<"***          7.统计图书的剩余量      ***"<<endl;
	cout<<"\t" <<"***          0.退出系统              ***"<<endl;
	cout<<"\t" <<"****************************************"<<endl;
}
bool insert(struct treebook* &p,struct treebook* qq){//将结点插入到二叉排序树中。 
	if(p==NULL){//空树 
	    p = (struct treebook*)malloc(sizeof(struct treebook));//建立二叉排序树，只有等到了没有结点的时候，创建结点，并把这个结点挂到二叉树中 
	    strcpy(p->num,qq->num);
		strcpy(p->name,qq->name);
		strcpy(p->author,qq->author);
		strcpy(p->sort,qq->sort);
		p->remainnumber=p->sum=qq->sum;
		p->left=p->right=NULL;	
	}
	else{//非空树 
		if(strcmp(qq->num,p->num)<0){//用图书的序列号来当做二叉排序树的排序的标准 
			
			return insert(p->left,qq);//小于，则去左子树 
		}
		else if(strcmp(qq->num,p->num)==0){//等于，则出现了异常情况，不能出现两个数相等 
			return  false;
		}
		else if(strcmp(qq->num,p->num)>0){//大于，则去右子树 
			return insert(p->right,qq);
		}
	}
}
void build(struct treebook* &root,int n){//二叉排序树以图书的编号大小进行排序。 
	root=NULL;
	char num[10];
	char name[10];
	char author[10];
	char sort[10];
	int number;
	for(int i=1;i<=n;i++){//每次输入信息，然后建立二叉树 
		cin>>num;
		cin>>name;
		cin>>author;
		cin>>sort; 
		cin>>number; 
		struct treebook* q = (struct treebook*)malloc(sizeof(struct treebook));
		strcpy(q->num,num);
		strcpy(q->name,name);
		strcpy(q->author,author);
		strcpy(q->sort,sort);
		q->sum = number;
		q->remainnumber = number;
		insert(root,q);	//将结点插入到二叉排序树中 
	}	
}
void midvis(struct treebook* &root,char s[]){//中序遍历 
	if(root==NULL){
		return ;
	}
	else{
		midvis(root->left,s);
		if(strcmp(root->sort,s)==0){//用来遍历图书的信息 
			cout<<root->name<<" ";
		}
    	midvis(root->right,s);
	}	
}
int findtree(struct treebook* &rt,char s[]){//在二叉排序树中寻找对应的结点 
	if(rt!=NULL){//非空的情况下，查找 
		if(strcmp(s,rt->num)==0){//等于，则直接返回 
			rt->remainnumber=rt->remainnumber-1;//借书要减去一个1 
			return 1;
		}
		else if(strcmp(s,rt->num)<0){//如果小于，则去左子树找 
			return findtree(rt->left,s);
		}
		else{
			return findtree(rt->right,s);
		}	
	}
	return 0;
}
void operate(struct treebook* &root,char n[],char st[]){//进行还书的操作 
	if(root==NULL){
		return ;
	}
	else{
		operate(root->left,n,st);
		if(strcmp(root->num,n)==0){
			root->remainnumber++;//还书，数量要上升1 
			for(int i=0;i<borr;i++){
		    		if(strcmp(bo[i].num,n)==0 && strcmp(bo[i].user,st)==0){
		    			bo[i].flag=1;
		    				
				}
			}
			
		}
		operate(root->right,n,st);
	}	
	
	
}
void del(struct treebook* &root,char s[]){//二叉树结点的删除 
	if(root==NULL){//如果是空的，则返回 
		return;
	}
	else{
		if(strcmp(root->num,s)==0){//如果相等，则找到了 
			if(root->left==NULL){//左子树为空 
				struct treebook* k= root;
				root = k->right;
				free(k);
			}
			else if(root->right==NULL){//右子树为空 
				struct treebook* k= root;
				root = k->left;
				free(k);
			}
			else{//左右子树都非空 
				struct treebook* k = root->right;
				while(k->left){
					k = k->left;
				}
				strcpy(root->num,k->num);
	          	strcpy(root->name,k->name);
		        strcpy(root->author,k->author);
		        strcpy(root->sort,k->sort);
		        root->remainnumber=root->sum=k->sum;
				del(root->right,k->num);	
			}
		}
		else if(strcmp(root->num,s)>0){//去左子树找 
			del(root->left,s);
		}
		else if(strcmp(root->num,s)<0){//去右子树找 
			del(root->right,s);
		}	
	}
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
void previs(struct treebook* &root,char s[]){//先序遍历 
	if(root==NULL){
		return ;
	}
	else{//用来寻找借阅 
		int flag=0;
		for(int i=0;i<borr;i++){
		    if(strcmp(bo[i].num,root->num)==0&&bo[i].flag==0){
			     flag=1;
			    break;
		    }
		}
		if(flag==0){
			cout<<root -> num << "\t" <<root->name<<"\t"<< root -> author << "\t" << root -> sort << "\t" << "剩余量：" <<  root -> remainnumber << "\t" << "状态: "; 
			cout<<"  暂时无人借阅"<<endl; 
			}
		else{
			cout<<root -> num << "\t" <<root->name<<"\t"<< root -> author << "\t" << root -> sort << "\t" << "剩余量：" <<  root -> remainnumber << "\t" <<"状态: ";   
			cout<<"借阅该图书的人和学号为："; 
			for(int i=0;i<borr;i++){
				if(strcmp(bo[i].num,root->num)==0&&bo[i].flag==0){
				    cout<<bo[i].st<<" "<<bo[i].user;
				    	int a=0;
						a = bi(s,bo[i].jsdate);
					   if(a==0){
							cout<<"   借书在有效期内"<<endl;
						}	
					   else{
							cout<<"    借书已经超过期限"<<endl; 
						}
					}
			}
	}
	previs(root->left,s);
	previs(root->right,s); 
}
}
int anss;
void calcul(struct treebook* &root){//计算借出量 
	if(root==NULL){
		return;
	}
	else{
		cout<<root->name<<"的借出量为："<<root->sum-root->remainnumber<<endl; 
		calcul(root->left);
		calcul(root->right);
	}
}
int anns;
void cal(struct treebook* &root){//计算剩余量 
	if(root==NULL){
		return;
	}
	else{
		cout<<root->name<<"的剩余量为："<<root->remainnumber<<endl; 
		cal(root->left);
		cal(root->right);
	}
}
void find(struct treebook* &rt,char s[]){
	if(rt!=NULL){//非空的情况下，查找 
		if(strcmp(s,rt->num)==0){//等于，则直接返回 
			cout<<rt->name<<"  "<<rt->author<<"  "<<rt->sort<<"  "<<rt->remainnumber<<endl;
			return;
		}
		else if(strcmp(s,rt->num)<0){//如果小于，则去左子树找 
			return find(rt->left,s);
		}
		else{
			return find(rt->right,s);
		}	
	}
	return ;
	
}
int main(){
	menuprint();
	int sel;
	struct treebook* root;
	root=NULL;
	while(true){
		int f1;
		cout<<"请输入你要操作的序号:";
		cin>>sel; 
		if(sel==0){
			break;
		}
		else if(sel==1){ 
			int n;
			cout<<"请输入要添加新图书的个数:";
			cin>>n;
			cout<<"请输入添加图书的编号、名称、作者、种类、数量:"<<endl;
		    build(root,n);
		    cout<<"图书信息插入完毕"<<endl;
		}
		else if(sel==2){
			char t[10];
			cout<<"请输入今日日期:";
			cin>>t; 
		    cout<<"图书信息如下："<<endl; 
		    previs(root,t);
			char sss[10];
		    f1=0;
		    cout<<"请输入要查询借书情况的学生的名字:"<<endl;
		    cin>>sss;
		    for(int i=0;i<borr;i++){
		   	  if(strcmp(bo[i].user,sss) == 0 &&bo[i].flag == 0){
		   		f1=1;
			   }
		   }
		   if(f1==0){
		   	cout<<"该同学没有借阅的书籍:"<<endl;
		   }
		   else if(f1==1){
		   	 for(int i=0;i<borr;i++){
		   	   if(strcmp(bo[i].user,sss)==0&&bo[i].flag==0){
		   		  cout<<bo[i].num<<"  ";
		   		  find(root,bo[i].num);
		        }  
         	}
         }
		} 
		else if(sel==3){// 借阅图书
		  cout<<"请输入图书的编号:";
		  char ss[10];
		  cin>>ss;
		  char na[10];
		  char lei[10];
		  cout<<"请输入图书的类别:";
		  cin>>lei;
		  int flag=0;
		  flag = findtree(root,ss); 
	      if(flag==0){
	      	cout<<"图书库中没有你要查找的书籍，可能剩余量为0，也可能不存在该书籍"<<endl;
	      	cout<<"为您推荐以下几本书:"<<endl; 
			midvis(root,lei);
			cout<<endl;
		  }
	      else if(flag==1){
	      	char t[10];
	      	char stt[10];
	      	cout<<"请输入你的学号:";
	      	cin>>stt;
	      	cout<<"请输入你的姓名:";
			cin>>na;
			cout<<"请输入今日日期:";
			cin>>t; 
			strcpy(bo[borr].st,stt);
			strcpy(bo[borr].user,na);
	      	strcpy(bo[borr].num,ss);
	      	strcpy(bo[borr].jsdate,t);
	      	borr++;
	      	cout<<"图书借阅完成"<<endl;
		  }	
		}
		else if(sel==4){//还书 
			char s[10]; 
			char ss[10];
			cout<<"请输入你的姓名:";
			cin>>ss;
			cout<<"请输入你还的图书编号：";
			cin>>s;
			operate(root,s,ss);
			cout<<"还书成功"<<endl; 
		}
		else if(sel==5){//删除图书。
		    cout<<"请输入你要删除的图书编号:";
			char s[10];
			cin>>s;
			del(root,s); 
		    cout<<"删除完毕"<<endl; 
		}
		else if(sel==6){
		    calcul(root);
		   cout<<"借出量为:"<<anss<<endl;
		}
		else if(sel==7){
		  cal(root);
		}
	}
	return 0;
} 


