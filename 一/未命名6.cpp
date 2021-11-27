#include<map>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
map<int,int> club;	//角斗场
map<int,int>::iterator it;
int n,id,power;
int main(){
	cin>>n;
	club[1000000000]=1;	//记录老板的实力，强的一批
	while(n--){
		cin>>id>>power;
		it=club.lower_bound(power);
		if(it==club.begin()){	//申请者实力弱爆了，只能选择已有会员最弱的挑战
			cout<<id<<" "<<it->second<<endl;
		}
		else if(it==club.end()){//申请者比最强，比老板都强，挑选最强的会员输出（其中包括老板。）
			it--;
			cout<<id<<" "<<it->second<<endl;
		}
		else{	//实力中等
			int right=it->first;	//比申请者强的最少的
			it--;	//***
			int left=it->first;		//比申请者弱的最多的
			if(power-left<=right-power){	
				cout<<id<<" "<<it->second<<endl;	//选择那个弱的
			}
			else{	
				it++;	//回到强的那个迭代器，输出
				cout<<id<<" "<<it->second<<endl;
			}
		}
		club[power]=id; //存入会员信息。
	}
	//system("pause");
	return 0;
}
