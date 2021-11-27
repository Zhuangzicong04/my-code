#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream> 
#include<algorithm>
using namespace std;
int stud,borr,teac;
struct treebook{//�ṹͼ��ŵ�����ͼ����Ϣ������������������е�ͼ����Ϣ 
	char num[10];//ͼ���� 
	char name[10];//ͼ������ 
	char author[10];//ͼ������ 
	char sort[10];//ͼ������ 
	int sum;//��¼�ܵ����� 
	int remainnumber;//��¼��̬������ 
	struct treebook* left;//�������ĵ�ַ 
	struct treebook* right ;//�������ĵ�ַ 
};

struct teacher{//��ʦ����Ϣ 
	char te[10];
	char name[10];
	char huandate[15];
	char jiedate[15];
	int nums;	
}tea[1000];

struct student{//�洢ѧ������Ϣ 
	char st[10];
	char name[10];
	int nums;
}stu[1000];

struct borrow{//����ͼ�����Ϣ 
	char book[10];
	char user[10];
	char st[10];
	char num[10];
	char jsdate[10];
	int flag;
}bo[1000];


void menuprint(){
	cout<<"\t" <<"**************ͼ�����ϵͳ**************"<<endl;
	cout<< "\t"<<"***          1.�����ͼ��            ***"<<endl;
	cout<<"\t" <<"***          2.��ѯͼ����Ϣ          ***"<<endl;
	cout<< "\t"<<"***          3.����ͼ��              ***"<<endl;
	cout<< "\t"<<"***          4.����ͼ��              ***"<<endl;
	cout<<"\t" <<"***          5.ɾ��ͼ��              ***"<<endl;
	cout<<"\t" <<"***          6.ͳ��ͼ������        ***"<<endl;
	cout<<"\t" <<"***          7.ͳ��ͼ���ʣ����      ***"<<endl;
	cout<<"\t" <<"***          0.�˳�ϵͳ              ***"<<endl;
	cout<<"\t" <<"****************************************"<<endl;
}
bool insert(struct treebook* &p,struct treebook* qq){//�������뵽�����������С� 
	if(p==NULL){//���� 
	    p = (struct treebook*)malloc(sizeof(struct treebook));//����������������ֻ�еȵ���û�н���ʱ�򣬴�����㣬����������ҵ��������� 
	    strcpy(p->num,qq->num);
		strcpy(p->name,qq->name);
		strcpy(p->author,qq->author);
		strcpy(p->sort,qq->sort);
		p->remainnumber=p->sum=qq->sum;
		p->left=p->right=NULL;	
	}
	else{//�ǿ��� 
		if(strcmp(qq->num,p->num)<0){//��ͼ������к�����������������������ı�׼ 
			
			return insert(p->left,qq);//С�ڣ���ȥ������ 
		}
		else if(strcmp(qq->num,p->num)==0){//���ڣ���������쳣��������ܳ������������ 
			return  false;
		}
		else if(strcmp(qq->num,p->num)>0){//���ڣ���ȥ������ 
			return insert(p->right,qq);
		}
	}
}
void build(struct treebook* &root,int n){//������������ͼ��ı�Ŵ�С�������� 
	root=NULL;
	char num[10];
	char name[10];
	char author[10];
	char sort[10];
	int number;
	for(int i=1;i<=n;i++){//ÿ��������Ϣ��Ȼ���������� 
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
		insert(root,q);	//�������뵽������������ 
	}	
}
void midvis(struct treebook* &root,char s[]){//������� 
	if(root==NULL){
		return ;
	}
	else{
		midvis(root->left,s);
		if(strcmp(root->sort,s)==0){//��������ͼ�����Ϣ 
			cout<<root->name<<" ";
		}
    	midvis(root->right,s);
	}	
}
int findtree(struct treebook* &rt,char s[]){//�ڶ�����������Ѱ�Ҷ�Ӧ�Ľ�� 
	if(rt!=NULL){//�ǿյ�����£����� 
		if(strcmp(s,rt->num)==0){//���ڣ���ֱ�ӷ��� 
			rt->remainnumber=rt->remainnumber-1;//����Ҫ��ȥһ��1 
			return 1;
		}
		else if(strcmp(s,rt->num)<0){//���С�ڣ���ȥ�������� 
			return findtree(rt->left,s);
		}
		else{
			return findtree(rt->right,s);
		}	
	}
	return 0;
}
void operate(struct treebook* &root,char n[],char st[]){//���л���Ĳ��� 
	if(root==NULL){
		return ;
	}
	else{
		operate(root->left,n,st);
		if(strcmp(root->num,n)==0){
			root->remainnumber++;//���飬����Ҫ����1 
			for(int i=0;i<borr;i++){
		    		if(strcmp(bo[i].num,n)==0 && strcmp(bo[i].user,st)==0){
		    			bo[i].flag=1;
		    				
				}
			}
			
		}
		operate(root->right,n,st);
	}	
	
	
}
void del(struct treebook* &root,char s[]){//����������ɾ�� 
	if(root==NULL){//����ǿյģ��򷵻� 
		return;
	}
	else{
		if(strcmp(root->num,s)==0){//�����ȣ����ҵ��� 
			if(root->left==NULL){//������Ϊ�� 
				struct treebook* k= root;
				root = k->right;
				free(k);
			}
			else if(root->right==NULL){//������Ϊ�� 
				struct treebook* k= root;
				root = k->left;
				free(k);
			}
			else{//�����������ǿ� 
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
		else if(strcmp(root->num,s)>0){//ȥ�������� 
			del(root->left,s);
		}
		else if(strcmp(root->num,s)<0){//ȥ�������� 
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
void previs(struct treebook* &root,char s[]){//������� 
	if(root==NULL){
		return ;
	}
	else{//����Ѱ�ҽ��� 
		int flag=0;
		for(int i=0;i<borr;i++){
		    if(strcmp(bo[i].num,root->num)==0&&bo[i].flag==0){
			     flag=1;
			    break;
		    }
		}
		if(flag==0){
			cout<<root -> num << "\t" <<root->name<<"\t"<< root -> author << "\t" << root -> sort << "\t" << "ʣ������" <<  root -> remainnumber << "\t" << "״̬: "; 
			cout<<"  ��ʱ���˽���"<<endl; 
			}
		else{
			cout<<root -> num << "\t" <<root->name<<"\t"<< root -> author << "\t" << root -> sort << "\t" << "ʣ������" <<  root -> remainnumber << "\t" <<"״̬: ";   
			cout<<"���ĸ�ͼ����˺�ѧ��Ϊ��"; 
			for(int i=0;i<borr;i++){
				if(strcmp(bo[i].num,root->num)==0&&bo[i].flag==0){
				    cout<<bo[i].st<<" "<<bo[i].user;
				    	int a=0;
						a = bi(s,bo[i].jsdate);
					   if(a==0){
							cout<<"   ��������Ч����"<<endl;
						}	
					   else{
							cout<<"    �����Ѿ���������"<<endl; 
						}
					}
			}
	}
	previs(root->left,s);
	previs(root->right,s); 
}
}
int anss;
void calcul(struct treebook* &root){//�������� 
	if(root==NULL){
		return;
	}
	else{
		cout<<root->name<<"�Ľ����Ϊ��"<<root->sum-root->remainnumber<<endl; 
		calcul(root->left);
		calcul(root->right);
	}
}
int anns;
void cal(struct treebook* &root){//����ʣ���� 
	if(root==NULL){
		return;
	}
	else{
		cout<<root->name<<"��ʣ����Ϊ��"<<root->remainnumber<<endl; 
		cal(root->left);
		cal(root->right);
	}
}
void find(struct treebook* &rt,char s[]){
	if(rt!=NULL){//�ǿյ�����£����� 
		if(strcmp(s,rt->num)==0){//���ڣ���ֱ�ӷ��� 
			cout<<rt->name<<"  "<<rt->author<<"  "<<rt->sort<<"  "<<rt->remainnumber<<endl;
			return;
		}
		else if(strcmp(s,rt->num)<0){//���С�ڣ���ȥ�������� 
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
		cout<<"��������Ҫ���������:";
		cin>>sel; 
		if(sel==0){
			break;
		}
		else if(sel==1){ 
			int n;
			cout<<"������Ҫ�����ͼ��ĸ���:";
			cin>>n;
			cout<<"���������ͼ��ı�š����ơ����ߡ����ࡢ����:"<<endl;
		    build(root,n);
		    cout<<"ͼ����Ϣ�������"<<endl;
		}
		else if(sel==2){
			char t[10];
			cout<<"�������������:";
			cin>>t; 
		    cout<<"ͼ����Ϣ���£�"<<endl; 
		    previs(root,t);
			char sss[10];
		    f1=0;
		    cout<<"������Ҫ��ѯ���������ѧ��������:"<<endl;
		    cin>>sss;
		    for(int i=0;i<borr;i++){
		   	  if(strcmp(bo[i].user,sss) == 0 &&bo[i].flag == 0){
		   		f1=1;
			   }
		   }
		   if(f1==0){
		   	cout<<"��ͬѧû�н��ĵ��鼮:"<<endl;
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
		else if(sel==3){// ����ͼ��
		  cout<<"������ͼ��ı��:";
		  char ss[10];
		  cin>>ss;
		  char na[10];
		  char lei[10];
		  cout<<"������ͼ������:";
		  cin>>lei;
		  int flag=0;
		  flag = findtree(root,ss); 
	      if(flag==0){
	      	cout<<"ͼ�����û����Ҫ���ҵ��鼮������ʣ����Ϊ0��Ҳ���ܲ����ڸ��鼮"<<endl;
	      	cout<<"Ϊ���Ƽ����¼�����:"<<endl; 
			midvis(root,lei);
			cout<<endl;
		  }
	      else if(flag==1){
	      	char t[10];
	      	char stt[10];
	      	cout<<"���������ѧ��:";
	      	cin>>stt;
	      	cout<<"�������������:";
			cin>>na;
			cout<<"�������������:";
			cin>>t; 
			strcpy(bo[borr].st,stt);
			strcpy(bo[borr].user,na);
	      	strcpy(bo[borr].num,ss);
	      	strcpy(bo[borr].jsdate,t);
	      	borr++;
	      	cout<<"ͼ��������"<<endl;
		  }	
		}
		else if(sel==4){//���� 
			char s[10]; 
			char ss[10];
			cout<<"�������������:";
			cin>>ss;
			cout<<"�������㻹��ͼ���ţ�";
			cin>>s;
			operate(root,s,ss);
			cout<<"����ɹ�"<<endl; 
		}
		else if(sel==5){//ɾ��ͼ�顣
		    cout<<"��������Ҫɾ����ͼ����:";
			char s[10];
			cin>>s;
			del(root,s); 
		    cout<<"ɾ�����"<<endl; 
		}
		else if(sel==6){
		    calcul(root);
		   cout<<"�����Ϊ:"<<anss<<endl;
		}
		else if(sel==7){
		  cal(root);
		}
	}
	return 0;
} 


