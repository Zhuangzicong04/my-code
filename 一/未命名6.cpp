#include<map>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
map<int,int> club;	//�Ƕ���
map<int,int>::iterator it;
int n,id,power;
int main(){
	cin>>n;
	club[1000000000]=1;	//��¼�ϰ��ʵ����ǿ��һ��
	while(n--){
		cin>>id>>power;
		it=club.lower_bound(power);
		if(it==club.begin()){	//������ʵ�������ˣ�ֻ��ѡ�����л�Ա��������ս
			cout<<id<<" "<<it->second<<endl;
		}
		else if(it==club.end()){//�����߱���ǿ�����ϰ嶼ǿ����ѡ��ǿ�Ļ�Ա��������а����ϰ塣��
			it--;
			cout<<id<<" "<<it->second<<endl;
		}
		else{	//ʵ���е�
			int right=it->first;	//��������ǿ�����ٵ�
			it--;	//***
			int left=it->first;		//����������������
			if(power-left<=right-power){	
				cout<<id<<" "<<it->second<<endl;	//ѡ���Ǹ�����
			}
			else{	
				it++;	//�ص�ǿ���Ǹ������������
				cout<<id<<" "<<it->second<<endl;
			}
		}
		club[power]=id; //�����Ա��Ϣ��
	}
	//system("pause");
	return 0;
}
