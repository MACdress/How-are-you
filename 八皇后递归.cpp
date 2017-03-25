#include<stdio.h>
int Q[8],col[8],left[15],right[15];
int count,top=-1;
void Printfs(int a[]){
	int i,j;
	printf("No%d\n",++count);
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(a[i]==j){
				printf("Q ");
			}
			else{
				printf("%c",1);
			}
		}
		printf("\n");
	}
	printf("\n");
}
void Queen(int i)
{
	int j;
	for(j=0;j<8;j++){
		if(!col[j]&&!left[i+j]&&!right[i-j+7]){
			col[j]=left[i+j]=right[i-j+7]=1;
			Q[++top]=j;
			if(i<7){
				Queen(i+1);
				}
			else{
				Printfs(Q);
			}
			col[j]=left[i+j]=right[i-j+7]=0;
			top--;
			}		
		}
	return;
}
int main(void)
{
	Queen(0);
	return 0;
}