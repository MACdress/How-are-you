#include<stdio.h>
int chess[12][12]={0};
int move[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int H[64][3];
int cnt=0;
int top=-1;
int tag;
void Print(){
	int i,j;
	printf("运行了%d次\n",++tag);
	for(i=2;i<10;i++){
		for(j=2;j<10;j++){
			printf("%3d",chess[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void MT(int x,int y){
	int a,b,i;
	i=0;
	H[++top][0]=x;
	H[top][1]=y;
	chess[x][y]=++cnt;
	while(1){
		for(;i<8;i++){
			a=x+move[i][0];
			b=y+move[i][1];
			if(!chess[a][b]){
				break;
			}
		}
		if(i==8&&top==0) break;
		if(i<8){
			H[top][2]=i;
			H[++top][0]=a;
			H[top][1]=b;
			chess[a][b]=++cnt;
			x=a;
			y=b;
			i=0;
			if(cnt==64){
				Print();
				chess[x][y]=0;
				cnt--;
				top--;
				x=H[top][0];
				y=H[top][1];
				i=H[top][2]+1;
			}
		}
		else{
			chess[x][y]=0;
			cnt--;
			top--;
			x=H[top][0];
			y=H[top][1];
			i=H[top][2]+1;
		}
	}
}
int main(void)
{
	int i,j,x,y;
	for(i=0;i<12;i++){
		for(j=0;j<12;j++){
			if(i==0||i==1||i==10||i==11||j==0||j==1||j==10||j==11){
				chess[i][j]=-1;
			}
		}
	}
	scanf("%d%d",&x,&y);
	MT(x,y); 
	return 0;
}

