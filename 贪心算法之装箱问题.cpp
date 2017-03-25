#include<stdio.h>
#include<stdlib.h>
# define V 50

typedef struct{
	int gno;
	int gv;
}Goods;/*物品信息*/ 

typedef struct node{
	int gno;
	struct node *link;
}GNode;/*箱子内物品节点信息*/ 

typedef struct box{
	int restv;
	GNode *hg;
	struct box* next;	
}BNode;/*箱子信息*/
 
void sortD(Goods *g,int n)
{
	int i,j,tag;
	Goods temp; 
	for(i=0;i<n-1;i++){
		tag=0;
		for(j=0;j<n-1-i;j++){
			if(g[j].gv<g[j+1].gv){
				temp=g[j];
				g[j]=g[j+1];
				g[j+1]=temp;
				tag=1;
			}
		}
		if(tag==0)   break;
	}
	for(i=0;i<n;i++){
		printf("%d %d\n",g[i].gno,g[i].gv);
	} 
}

BNode * PeckBox(Goods *g,int n)
{
	BNode *hbox,*tbox,*p;
	GNode *q,*newq;
	int i,num=0;
	hbox=NULL;
	for(i=0;i<n;i++)
	{//创建物品节点 
		newq=(GNode*)malloc(sizeof(GNode)); 
		newq->link=NULL;
		newq->gno=g[i].gno;
		for(p=hbox;p&&(p->restv<g[i].gv);p=p->next);//跑箱子链
		if(!p)  //p为空，开新箱子。 
		{
			p=(BNode *)malloc(sizeof(BNode));
			p->next=NULL;
			p->hg=NULL;
			p->restv=V;
			if(!hbox){
				hbox=tbox=p;
			}
			else{
				tbox=tbox->next=p;
			} 
			num++;
		} 
		//给指针p指向的箱子放物品 （都是在放物品） 
			p->restv-=g[i].gv;
			for(q=p->hg;q&&q->link;q=q->link); 
			if(q){
				q->link=newq;
			}
			else{
				p->hg=newq;
			}
		}
		printf("一共有%d个箱子\n",num);
	return hbox;
} 
void Print(BNode*hbox)
{
	BNode *p;
	GNode *q;
	int i=0;
	for(p=hbox;p;p=p->next){
		printf("第%d个箱子里面物品：",++i);
		for(q=p->hg;q;q=q->link){
			printf("%3d",q->gno);
		}
		printf("\n");
	}
 } 
 void Delete(BNode *hbox)
 {
 	BNode *p;
 	GNode *q;
 	while(hbox)
	 {
 		p=hbox;
 		while(p->hg)
		 {
 			q=p->hg; 
 			p->hg=q->link;
 			free(q);
		 }
		 hbox=p->next;
		 free(p);
	 }
 }
 
int main(void)
{
	int i,n,tag,f;
	Goods *g;
	BNode *hbox=NULL;
    printf("装箱问题可以实现的功能有:\n");
    printf("1.将物品装入箱子中。\n");
    printf("2.输出箱子内的情况。\n");
    printf("3.清空箱子\n"); 
    printf("0.结束功能！\n");
    scanf("%d",&tag);
    f=0;
    while(tag){
    	if(tag==1)
		{
			printf("请输入物品个数:\n");
		  	scanf("%d",&n);/*输入物品个数*/ 
			g=(Goods *)malloc(n*sizeof(Goods));
			printf("请依次输入物品体积\n"); 
			for(i=0;i<n;i++){//输入物品信息
			g[i].gno=i;
			scanf("%d",&g[i].gv); 
			}
			sortD(g,n);//排序 
			hbox=PeckBox(g,n);//装箱
			f=1;
		}
		if(tag==2&&f)
		{
			Print(hbox);//输出
		}
		if(tag==3&&f)
		{	 
			free(g);
			delete(hbox);
			printf("成功删除箱子内的物品！\n"); 
			f=0;
		}
		else{
			if(f==0)
			{
				printf("请先放入物品！\n"); 
			}
		}
		scanf("%d",&tag);
   	}
   	printf("欢迎在次使用！\n");
   	return 0;
 } 
