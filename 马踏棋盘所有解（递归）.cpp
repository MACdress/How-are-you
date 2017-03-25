#include<stdio.h>
int chess[12][12]={0};
int move[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int cnt=0; 
int tag=0;
void Print(){
	int i,j;
	tag++;
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
		for(i=0;i<8;i++){
			a=x+move[i][0];
			b=y+move[i][1];
			if(chess[a][b]==0){
				chess[a][b]=++cnt;
				if(cnt<64){
					MT(a,b);
				}
				else{
					Print();
				}
				chess[a][b]=0;
				cnt--;
			}
		}
	return;
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
	chess[x][y]=++cnt;
	MT(x,y);
	printf("%d\n",tag);
	return 0;
}
