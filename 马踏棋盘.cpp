#include<stdio.h>
int chess[12][12]={0};
int move[8][2]={{2,-1},{1,-2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,2},{2,1}};
int H[64][3];
int cnt=0;
int top=-1;
void Print(){
	int i,j;
	for(i=2;i<10;i++){
		for(j=2;j<10;j++){
			printf("%3d",chess[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void MT(int x,int y){
	int a,b,i,tag;
	i=0;
	H[++top][0]=x;
	H[top][1]=y;
	chess[x][y]=++cnt;
	while(cnt<64){
		for(;i<8;i++){
			a=x+move[i][0];//踏出的方向 
			b=y+move[i][1];
			if(chess[a][b]==0){//如果位置可以踏，则跳出循环 					
				break;
			}
		}
		if(i<8){
			H[top][2]=i;//把方向入栈 
			H[++top][0]=a;//把踏过的点入栈 
			H[top][1]=b;
			chess[a][b]=++cnt;//标上轨迹 
			x=a;//更改位置 
			y=b;
			i=0;
		}
		else{
			chess[x][y]=0;//抹去当前位置 
			top--;
			x=H[top][0];//回到上一个位置 
			y=H[top][1];
			i=H[top][2]+1;//换一个方向 
			cnt--;//路程减一 
		}
	}
	Print();
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
