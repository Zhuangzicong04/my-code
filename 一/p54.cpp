#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct student {
      char name[20];
      int score;
};
int main()
{
      student std[20],max;
      int n;
      freopen("C:\\Codefield\\CODE_C\\C_Single\\Online Judge\\1.txt","r",stdin);
      cin >> n;
      for(int i = 0;i < n; ++ i)
      {
          cin >> std[i].name >> std[i].score;
      }
      for(int i = 0;i < n; ++ i)
      {
             for(int j = i + 1;j < n ; ++ j)
                 if(std[i].score < std[j].score)
               {
                 max = std[i];
                 std[i] = std[j];
                 std[j] = max;
               }
              else if(std[i].score == std[j].score && strcmp(std[i].name,std[j].name) > 0)
               {
                         max = std[i];
                         std[i] = std[j];
                         std[j] = max;
               }
              cout << std[i].name << " " << std[i].score << endl;
      }
                  
      return 0;
}