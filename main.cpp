//3311
//�������
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
int c[maxx][maxx];//�����������Floyd�������洢�Լ�״ѹDPԴ����


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
    cout << "#-------------------------------------------#" << endl;//�����ӭ��Ϣ
    cout << "    Welcome to the TSP system!" << endl;
    cout << "#-------------------------------------------#" << endl;

    cout << endl;
    cout << endl;
    cout << endl;

        cout << "Please choose the ways to input data:(1 for file and 2 for the command line input and 3 for random)" << endl;
        int cc=3;
        while (1)
        {
            cin >> cc;//�����û�ѡ��
            if (cc == 1 || cc == 2 || cc==3)break;
            cout << "Input error, please try it again" << endl;
        }
        cout << "The way you chose is: " <<( (cc == 1) ? "File" : "Terminal" )<< endl;
        switch (cc)
        {

        case 1:
            cout << "Please input the absolute addr of the file:" << endl;
            cin >> file;//�����ļ�·��
            cout<<"Reading data....."<<endl;
            freopen(file, "r", stdin);//�ض���

            cout<<"Please input the total number of nodes:(0 for exit)"<<endl;
            cin>>n;//����ڵ����
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
            freopen("CON", "r", stdin);//�ض���
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

            double random(double,double);//�����
            srand(unsigned(time(0)));//ʱ������
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

            double random(double,double);//�����
            srand(unsigned(time(0)));//ʱ������
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                {
                    c[i][j]=(int(random(0,100)));//�����0~100
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

            //floyde ���·
        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    if(c[i][j]>c[i][k]+c[k][j])
                        c[i][j]=c[i][k]+c[k][j];//Floyd
        cout<<"The dist matrix:"<<endl;
        for(int i=0; i<n; i++)//����������
        {
            for(int j=0; j<n; j++)
                cout<<c[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        int inte=1<<n;
        /*
        ״̬ת�Ʒ���:DP(S,i) = min{DP(S^(1<<i-1),k) + dis[k][j],DP(S,i)},����S^(1<<i-1)��ʾδ�������i������״̬��1<=k<=n
        ����ȫ1��״̬����S = (1<<n)-1���ʾ�������г��е�״̬�����ջ���Ҫ�ص�����0����ô���մ𰸾���min{DP(S,i) + dis[i][0]}

        */
        int **dp;
        int sz = 1<<n;//2^n ״ѹ��ʼ��

        dp=(int **)malloc(sizeof(int *)*sz);//�����ڴ�
        for(int i=0;i<sz;i++)dp[i]= (int *)malloc(sizeof(int)*n);
        if(dp==NULL)
        {
            printf("Can not assign the space!\n");
            exit(1);
        }

        for(int i=0;i<sz;i++){//��ʼ��DP����
            for(int j=0;j<n;j++)dp[i][j]=0x3f3f3f3f;
        }
//        memset(dp,0x3f,sizeof dp);
        for(int i=0; i<n; i++)dp[(1<<i)][i]=c[0][i];//��ֵ��ֵΪ����
        for(int s=1; s<inte; s++)//û���������
        {
            for(int i=0; i<n; i++)
            {
                if((s>>i)&1)//�������������
                {
                    int te = s^(1<<i);//���Ϊδ����
                    for(int j=0; j<n; j++)
                    {
                        if((te>>j)&1)//�����j�ܹ�����ýڵ�
                        {
                            if(dp[te][j]+c[j][i]<dp[s][i])
                            {
                                dp[s][i]=dp[te][j]+c[j][i];//����·������
                            }
                        }
                    }
                }
            }

        }



        printf("Total distance is: %d\n",dp[inte-1][0]);//�����

//        cout<<"The route is:"<<endl;
//        for(int ii=0;ii<n;ii++){
//            cout<<f[ii]<<" ";
//
//        }
        cout<<endl;
        getchar();
        getchar();

}

