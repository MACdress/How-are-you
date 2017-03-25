#include<stdio.h>
int q[8],left[15],right[15],col[8];
int cnt;
int main(void)
{
	int i,j,top=-1;
	i=j=0;
	while(top!=-2){
		for(;j<8;j++){
			if((col[j]==0)&&(left[i+j]==0)&&(right[i-j+7]==0)){
				col[j]=left[i+j]=right[i-j+7]=1;
				break;
			}
		}
		if(j==8){
			i=top;
			j=q[top];
			col[j]=left[i+j]=right[i-j+7]=0;
			top--;
			j++;
		}
		else{
			q[++top]=j;
			i++;
			j=0;
		}  
		if(top==7){
			printf("No%d:\n",++cnt);
			for(i=0;i<8;i++){
				for(j=0;j<8;j++){
					if(q[i]==j){
						printf("Q ");
					}
					else{
						printf("%c",1);
					}
				}
				printf("\n");
			}
			printf("\n");
			i=top;
			j=q[top];
			col[j]=left[i+j]=right[i-j+7]=0;
			j++;
			top--;
		}
	}
	return 0;	
}
