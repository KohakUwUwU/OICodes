#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m;
int a[N],r[N],g[N];//ÿ��·�ڼ�ľ��룬���ʱ�䣨red�����̵�ʱ�䣨green��
int main(){
    cin>>n>>m;//����
    for(int i=1;i<n;i++){//��ס����n��·�ڣ�ֻ��n-1������
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){//������ʱ��
        cin>>r[i];
    }
    for(int i=1;i<=n;i++){//�����̵�ʱ��
        cin>>g[i];
    }
    for(int i=1;i<=n;i++){//��ʱ����д���
        if(m%(r[i]+g[i])>g[i])m+=(r[i]+g[i])-m%(r[i]+g[i]);//�����ǰʱ�䲻���̵Ʒ�Χ�ڣ��ͽ�m���ϵ�ǰʱ��������ĵ�ǰ·�ڵ��̵Ƶ�ʱ���
        cout<<m<<endl;//���ʱ��
        m+=a[i];//����ͨ����i��i+1��·�ڼ�����ʱ��
    }
    return 0;
}
