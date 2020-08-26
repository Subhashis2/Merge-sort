//.....Subhashis PAUL

#include<stdio.h>
#include<stdlib.h>
struct array
{
	int num;  int *arr;
};
int do_merge_sort(struct array *elements,int,int);
int do_merge(struct array *elements,int,int,int);

int main()
{
struct array elements; 
	int i;
	printf("\n\t\t\t\t -:  MERGE SORT METHOD  :-\n\n\n");
	printf("Enter number of elements in the array :  ");
	scanf("%d",&elements.num);
	elements.arr = (int*)malloc(elements.num*sizeof(int));
	printf("\n Enter the elements : ");
	for(i=0;i<elements.num;i++)
	scanf("%d",elements.arr+i);
	do_merge_sort(&elements, 0 , (elements.num - 1));
	printf("\n\n After sorting, the array is :     ");
	for(i=0;i<elements.num;i++)
	printf("%d\t",*(elements.arr+i));
	free(elements.arr);	
return 0;
}
int do_merge_sort(struct array *elements, int lb, int ub)
{
	int mid;
	if(lb < ub)
	{
		mid = (lb + ub)/2;
		do_merge_sort(elements, lb, mid);
		do_merge_sort(elements, mid+1, ub);
		do_merge(elements, lb, mid, ub);
	}	
}

int do_merge(struct array *elements,int lb,int mid,int ub)
{
	int i = lb;
	int j = mid + 1;
	int k = lb;
	int *temp;
	temp =(int*)malloc(elements->num*sizeof(int));
	while(i <= mid && j <= ub)
	{
		if(elements->arr[i] <= elements->arr[j])
		{
			temp[k] = elements->arr[i];
			i++;
		}
		else
		{
			temp[k] = elements->arr[j];
			j++;
		}
		k++;
	}
	if(i > mid)
		while(j <= ub)
		{
			temp[k] = elements->arr[j];
			j++;
			k++;
		}
	else
		while(i <= mid)
		{
			temp[k] = elements->arr[i];
			i++;
			k++;
		}
	for (i = lb; i <= ub; i++)
    {
        elements->arr[i] = temp[i];
    }
    free(temp);
}

