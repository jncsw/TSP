//3311
//随机生成
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <malloc.h>
using namespace std;
const int maxn = 10000007;
typedef long long ll;
const int maxx = 20;
int c[maxx][maxx];//距离矩阵，用于Floyd计算结果存储以及状压DP源数据


//void dfs(int x){
//    cout<<"f[x]=:"<<f[x]<<" "<<x<<endl;
//    if(f[x]==maxn)return;
//    dfs(f[x]);
//    cout<<x<<endl;
//}
char file[1000];

double random(double start, double end)
{
    return start+(end-start)*rand()/(RAND_MAX + 1.0);
}


int main()
{


    int n=1;
    cout << "#-------------------------------------------#" << endl;//输出欢迎信息
    cout << "    Welcome to the TSP system!" << endl;
    cout << "#-------------------------------------------#" << endl;

    cout << endl;
    cout << endl;
    cout << endl;

        cout << "Please choose the ways to input data:(1 for file and 2 for the command line input and 3 for random)" << endl;
        int cc=3;
        while (1)
        {
            cin >> cc;//输入用户选择
            if (cc == 1 || cc == 2 || cc==3)break;
            cout << "Input error, please try it again" << endl;
        }
        cout << "The way you chose is: " <<( (cc == 1) ? "File" : "Terminal" )<< endl;
        switch (cc)
        {

        case 1:
            cout << "Please input the absolute addr of the file:" << endl;
            cin >> file;//输入文件路径
            cout<<"Reading data....."<<endl;
            freopen(file, "r", stdin);//重定向

            cout<<"Please input the total number of nodes:(0 for exit)"<<endl;
            cin>>n;//读入节点个数
            n++;
            cout<<"Please input each distance between each nodes:"<<endl;
    //        for(int i=0;i<n;i++)
    //            for(int j=0;j<n;j++){
    //                scanf("%d",&c[i][j]);
    //            }
    //


            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                {
                    cin>>c[i][j];
                }
            freopen("CON", "r", stdin);//重定向
            break;
        case 2:

            cout<<"Please input the total number of nodes:(0 for exit)"<<endl;
            cin>>n;
            n++;
            cout<<"Please input each distance between each nodes:"<<endl;
    //        for(int i=0;i<n;i++)
    //            for(int j=0;j<n;j++){
    //                scanf("%d",&c[i][j]);
    //            }
    //

            double random(double,double);//随机数
            srand(unsigned(time(0)));//时间种子
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                {
                    cin>>c[i][j];
                }



            break;
        case 3:

            cout<<"Please input the total number of nodes:(0 for exit)"<<endl;
            cin>>n;
            n++;
            cout<<"Please input each distance between each nodes:"<<endl;
    //        for(int i=0;i<n;i++)
    //            for(int j=0;j<n;j++){
    //                scanf("%d",&c[i][j]);
    //            }
    //

            double random(double,double);//随机数
            srand(unsigned(time(0)));//时间种子
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                {
                    c[i][j]=(int(random(0,100)));//随机数0~100
                }

            for(int i=0; i<n; i++){

                for(int j=0; j<n; j++)
                {
                    cout<<c[i][j]<<" ";
                }
                cout<<endl;
            }

            break;

        default:
            break;
        }

    //    for(int ii = 0;ii<15;ii++){
    //        f[ii]=maxn;
    //    }

            //floyde 最短路
        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    if(c[i][j]>c[i][k]+c[k][j])
                        c[i][j]=c[i][k]+c[k][j];//Floyd
        cout<<"The dist matrix:"<<endl;
        for(int i=0; i<n; i++)//输出距离矩阵
        {
            for(int j=0; j<n; j++)
                cout<<c[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        int inte=1<<n;
        /*
        状态转移方程:DP(S,i) = min{DP(S^(1<<i-1),k) + dis[k][j],DP(S,i)},其中S^(1<<i-1)表示未到达城市i的所有状态，1<=k<=n
        对于全1的状态，即S = (1<<n)-1则表示经过所有城市的状态，最终还需要回到城市0，那么最终答案就是min{DP(S,i) + dis[i][0]}

        */
        int **dp;
        int sz = 1<<n;//2^n 状压初始化

        dp=(int **)malloc(sizeof(int *)*sz);//分配内存
        for(int i=0;i<sz;i++)dp[i]= (int *)malloc(sizeof(int)*n);
        if(dp==NULL)
        {
            printf("Can not assign the space!\n");
            exit(1);
        }

        for(int i=0;i<sz;i++){//初始化DP数组
            for(int j=0;j<n;j++)dp[i][j]=0x3f3f3f3f;
        }
//        memset(dp,0x3f,sizeof dp);
        for(int i=0; i<n; i++)dp[(1<<i)][i]=c[0][i];//初值赋值为距离
        for(int s=1; s<inte; s++)//没有完成运算
        {
            for(int i=0; i<n; i++)
            {
                if((s>>i)&1)//如果点曾经到达
                {
                    int te = s^(1<<i);//标记为未到达
                    for(int j=0; j<n; j++)
                    {
                        if((te>>j)&1)//如果从j能够到达该节点
                        {
                            if(dp[te][j]+c[j][i]<dp[s][i])
                            {
                                dp[s][i]=dp[te][j]+c[j][i];//进行路径更新
                            }
                        }
                    }
                }
            }

        }



        printf("Total distance is: %d\n",dp[inte-1][0]);//输出答案

//        cout<<"The route is:"<<endl;
//        for(int ii=0;ii<n;ii++){
//            cout<<f[ii]<<" ";
//
//        }
        cout<<endl;
        getchar();
        getchar();

}

