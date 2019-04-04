#include <stdio.h>

int a[10005]={0,1,2,3,5};
void data_init()
{
	int i;
	for(i=3;i<10005;i++)
	{
		a[i]=a[i-1]+a[i-2];
		if(a[i]>=10000) a[i]%=10000;
	}
}
int main()
{
	int n,t;
	data_init();
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			scanf("%d",&t);
			printf("%04d",a[t]);
		}
		printf("\n");
	}
	return 0;
}
