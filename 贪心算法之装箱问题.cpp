#include<stdio.h>
#include<stdlib.h>
# define V 50

typedef struct{
	int gno;
	int gv;
}Goods;/*��Ʒ��Ϣ*/ 

typedef struct node{
	int gno;
	struct node *link;
}GNode;/*��������Ʒ�ڵ���Ϣ*/ 

typedef struct box{
	int restv;
	GNode *hg;
	struct box* next;	
}BNode;/*������Ϣ*/
 
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
	{//������Ʒ�ڵ� 
		newq=(GNode*)malloc(sizeof(GNode)); 
		newq->link=NULL;
		newq->gno=g[i].gno;
		for(p=hbox;p&&(p->restv<g[i].gv);p=p->next);//��������
		if(!p)  //pΪ�գ��������ӡ� 
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
		//��ָ��pָ������ӷ���Ʒ �������ڷ���Ʒ�� 
			p->restv-=g[i].gv;
			for(q=p->hg;q&&q->link;q=q->link); 
			if(q){
				q->link=newq;
			}
			else{
				p->hg=newq;
			}
		}
		printf("һ����%d������\n",num);
	return hbox;
} 
void Print(BNode*hbox)
{
	BNode *p;
	GNode *q;
	int i=0;
	for(p=hbox;p;p=p->next){
		printf("��%d������������Ʒ��",++i);
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
    printf("װ���������ʵ�ֵĹ�����:\n");
    printf("1.����Ʒװ�������С�\n");
    printf("2.��������ڵ������\n");
    printf("3.�������\n"); 
    printf("0.�������ܣ�\n");
    scanf("%d",&tag);
    f=0;
    while(tag){
    	if(tag==1)
		{
			printf("��������Ʒ����:\n");
		  	scanf("%d",&n);/*������Ʒ����*/ 
			g=(Goods *)malloc(n*sizeof(Goods));
			printf("������������Ʒ���\n"); 
			for(i=0;i<n;i++){//������Ʒ��Ϣ
			g[i].gno=i;
			scanf("%d",&g[i].gv); 
			}
			sortD(g,n);//���� 
			hbox=PeckBox(g,n);//װ��
			f=1;
		}
		if(tag==2&&f)
		{
			Print(hbox);//���
		}
		if(tag==3&&f)
		{	 
			free(g);
			delete(hbox);
			printf("�ɹ�ɾ�������ڵ���Ʒ��\n"); 
			f=0;
		}
		else{
			if(f==0)
			{
				printf("���ȷ�����Ʒ��\n"); 
			}
		}
		scanf("%d",&tag);
   	}
   	printf("��ӭ�ڴ�ʹ�ã�\n");
   	return 0;
 } 
