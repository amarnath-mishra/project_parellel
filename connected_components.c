#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include <sys/time.h>



struct mainQ
{
	int value;
	struct mainQ *next;
};

struct mainQ *getNode(int);

void insertion_sort(int *arr1,int *arr2,int numEdges)
{

int c1,d1,t1,t2;
    printf("sorting starts\n");
for (c1 = 1 ; c1 <2* numEdges; c1++) {
    d1 = c1;
//printf("\nheerre %d,%d,%d",arr1[d1],arr1[(d1-1)],d1);
    while ( d1 > 0 && arr1[d1] < arr1[(d1-1)])
    {
    //printf("\nhere");
      t1          = arr1[d1];
      arr1[d1]   = arr1[d1-1];
      arr1[d1-1] = t1;

      t2          = arr2[d1];
      arr2[d1]   = arr2[d1-1];
      arr2[d1-1] = t2;

      d1--;
    }
    }
    printf("sorting done\n");

}


int delete_Q(struct mainQ **root)
{
	int deQueued_node;
	struct mainQ *temp;
	temp = *(root);
	deQueued_node = (*root)->value;
	*root = (*root)->next;
	free(temp);
	return deQueued_node;

}


struct mainQ *insert_Q(struct mainQ *root,int value)
{
	struct mainQ *temp,*node;
	node = getNode(value);
	temp = root;
	if (root == NULL)
	{
		root = node;
		return root;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = node;
		return root;

	}

}





int main()
{
     clock_t start, end;
     double cpu_time_used;
    struct timeval begin, end2;
    gettimeofday(&begin, NULL);

//code to time
    start = clock();
    // ... /* Do the work. */

	struct mainQ *root;
	root = NULL;
//printf("egegeg");

	int numEdges=0,q=0,v=0,deQueued_node;
	int *arr1,*arr2,*A,*visited;

	char a,b,c,d,sp[4];
	FILE *fp;

	fp=fopen("/home/amarnath/project7/GTgraph-master/R-MAT/try.txt","r");

	int numVertices=0;
	//printf("after sortinwdg \n");

	fscanf(fp, "%c %s %d %d\n", &a,sp,&numVertices,&numEdges);

	arr1=(int*)malloc(2*numEdges*sizeof(int));
	arr2=(int*)malloc(2*numEdges*sizeof(int));
	int x,y,z,i,j,k,l=0;

	while(fscanf(fp, "%c %d %d %d\n", &a,&x,&y,&z)!= -1)
	{
        i=x;
        j=y;
		arr1[l]=x;
		arr1[l+1]=y;
		arr2[l]=j;
		arr2[l+1]=i;
		//l=l+2;
		l=l+2;

	}
	insertion_sort(arr1,arr2,numEdges);



printf("\n");
for(i=0;i<2*numEdges;i++)
{
printf("(%d,%d)\n",arr1[i],arr2[i]);

}
printf("after sorting \n");
printf("after sorting done\n");


numEdges = numEdges*2;

//insertion code ends
	numVertices++;
printf("\n numVertices = %d",numVertices);
	A=(int*)malloc(numVertices*sizeof(int));
	visited=(int*)malloc(numVertices*sizeof(int));

	for(i=0;i<numVertices;i++)
	{
		A[i]=0;
		visited[i]=0;
	}

	for (i=0;i<numEdges;i++)
	{
		if(A[arr1[i]]==0)
		{ A[arr1[i]]=i+1;
		}
	}
	printf("\n");
	for (i=0;i<numVertices;i++)
	{
    //printf("A = %d\n",A[i]);
	}
	/////////////////////////////////////////////////////////////////////////////

	//printf("Enter the root node\n");
	//scanf("%d",&v);
	int counter =0;
	int t;
	for(t=1;t<numVertices;t++)
    {//printf("\t hh v= %d hh",t);
    if(A[t]!=0)
    {
        x=A[t];
        v=arr1[x-1];

        if(visited[v] == 0)
        {
        counter++;
        printf("\n");
    /////////////////////////////////////////////////////////////////////////////
	visited[v]=1;
	root = insert_Q(root,v);
	while(root != NULL)
	{
		deQueued_node = delete_Q(&root);

		v=deQueued_node;
		printf("%d-->",v);
		i=A[v]-1;

		if(i>=0){
			j=arr1[i];

			while(j==arr1[i])
			{

				if(visited[arr2[i]]==0)
				{
					visited[arr2[i]]=1;
					root = insert_Q(root,arr2[i]);

				}
				i++;
			}
		}
	}
}
}
}
printf("\n num of conn components are = %d\n",counter);

	fclose(fp);
	end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     printf("\nprogram took %f seconds to execute \n", cpu_time_used);

     gettimeofday(&end2, NULL);
//get the total number of ms that the code took:
//unsigned int t = end.tv_usec - begin.tv_usec;
double elapsed = (end2.tv_sec - begin.tv_sec) +
              ((end2.tv_usec - begin.tv_usec)/1000000.0);
              printf("\n get time gave took %f seconds to execute \n", elapsed);
	return 0;
}

struct mainQ *getNode(int value)
{
	struct mainQ *newnode;
	newnode = (struct mainQ *)malloc(sizeof(struct mainQ));
	newnode->value = value;
	newnode->next = NULL;
	return newnode;
}
