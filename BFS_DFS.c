#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1,top=-1;

void insert(int n,int a[n],int item);
void del(int n,int a[n]);
void bfs(int n,int a[n],int status[n],int g[n][n], int p);
void bst(int n,int a[n],int status[n],int g[n][n]);
void push(int n,int A[n],int p);
void pop(int n,int A[n]);
void dfs(int n,int A[n],int g[n][n],int status[n],int p);

int main(){
	int ch,n;
	printf("\nenter the number of elements:");		
	scanf("%d",&n);
	int a[n],A[n],status[n],g[n][n];
	printf("\nenter the elements of graph\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&g[i][j]);
		}
	}
	do
	{
		printf("\n1.bfs\n2.dfs\n0.exit\n");
		scanf("%d",&ch);
		if(ch==0)
			exit(0);
		switch (ch){
			case 1:bst(n,a,status,g);
				break;
			case 2:dfs(n,A,g,status,0);
				break;
		}
	}while(ch<3);
	return 0;
}

void insert(int n,int a[n],int item){
	if(front==-1){
		front=rear=0;
	}
	else
		rear=rear+1;
	a[rear]=item;
}

void del(int n,int a[n]){
	printf("%d ",a[front]);
	if(front==rear){
		front=rear=-1;
	}
	else
		front++;
}

void bfs(int n,int a[n],int status[n],int g[n][n],int p){
	int i,k;
	insert(n,a,p);
	status[p]=2;
	while(front!=-1&&rear!=-1){
		status[a[front]]=3;
		k=a[front];
		del(n,a);
		for(i=0;i<n;i++){
			if(g[k][i]==1&&status[i]==1){
				insert(n,a,i);
				status[i]=2;
			}
		}
	}
}

void bst(int n,int a[n],int status[n],int g[n][n]){
	int i;
	for(i=0;i<n;i++)
		status[i]=1;
	for(i=0;i<n;i++){
		if(status[i]==1)
			bfs(n,a,status,g,i);
	}
}

void push(int n,int A[n],int p){
	top++;
	A[top]=p;
}

void pop(int n,int A[n]){
	printf("%d ",A[top]);
	top--;
}

void dfs(int n,int A[n],int g[n][n],int status[n],int p){
	int i,k;
	for(i=0;i<n;i++)
		status[i]=1;
	push(n,A,p);
	status[p]=2;
	while(top!=-1){
		status[A[top]]=3;
		k=A[top];
		pop(n,A);
		for(i=0;i<n;i++){
			if(g[k][i]==1&&status[i]==1){
				push(n,A,i);
				status[i]=2;
			}
		}
	}
}
