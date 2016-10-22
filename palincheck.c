#include <stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
void palin(struct node *p){
	struct node *tmp,*f,*r,*prev,*next,*ptr;
	int c=0;
	tmp=p;
	while(tmp->link!=NULL){
		c++;
		r=tmp;
		tmp=tmp->link;
	}
	int l=0,pos=c/2;
	f=p;
//	r=p;
	prev=NULL;
	/*while(r!=NULL && l!=pos+1){
		r=r->link;
		l++;
	}*/
	ptr=r;
	while(ptr!=NULL){
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	r=prev;
	
	int z=0,count=pos;
	//printf("%d %d",r->info,f->info);
	while(r!=NULL && f!=NULL && pos!=0){
		//printf("f = %d ,r = %d",f->info,r->info);
		if(f->info == r->info){
			z++;
		}
	//	printf("------------");
		f=f->link;
		r=r->link;
		pos--;
	}
	if(z==count){
		printf("1");
	}
	else{
		printf("0");
	}
}
int main() {
	int n;		//number of nodes
	scanf("%d",&n);
	int i,d;
	struct node *p,*start;
	start=(struct node *)malloc(sizeof(struct node));
	//start=NULL;
	scanf("%d",&d);
	start->info=d;
//	printf("-----------");
	p=start;
	for(i=2;i<=n;i++){
		scanf("%d",&d);
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->info=d;
		temp->link=NULL;
		p->link=temp;
		p=temp;
	}
	p=start;
	/*while(p!=NULL){
		printf("%d",p->info);
		p=p->link;
	}*/
	palin(start);
	
	return 0;
}