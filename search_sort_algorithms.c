#include<stdio.h>
#include<stdlib.h>
struct student
{
	int roll;
	char name[25];
	char add[25];
	float per;
};

void getdata(struct student s[50], int n);
void printdata(struct student s[50], int n);
void linear(struct student s[50], int n);
void binary(struct student s[50], int n);
int binary_rec(struct student s[50], int key, int low, int high);
void bubbleSort(struct student s[50], int n);
void selectionSort(struct student s[20], int n);
void insertionSort(struct student s[20], int n);

void main()
{
	int n,a,b;
	struct student s[50];
	printf("Enter the no. of students...");
	scanf("%d",&n);
	getdata(s,n);
	while(1)
	{
	printf("Enter the task you want to perform \n");
	printf(" 1.Display \n 2.Linear Search \n 3.Binary Search w/o recursion  \n 4.Binary search with recursion \n 5.Bubble Sort \n  6.Selection sort \n 7.Insertion Sort \n 8.Exit \n");
	scanf("%d",&a);
	switch(a)
	{
	case 1 :
	printdata(s,n);
	break;
	case 2 :
	linear(s,n);
	break;
	case 3 :
	binary(s,n);
	break;
	case 4 :
	printf("Enter the no. to be searched \n");
	scanf("%d",&b);
	int br = binary_rec(s, b, 0, n-1);
	printf("Found at %d\n",br);
	break;
	case 5 :
	bubbleSort(s,n);
	printdata(s,n);
	break;
	case 6:
	selectionSort(s,n);
	printdata(s,n);
	break;
	case 7:
	insertionSort(s,n);
	printdata(s,n);
	break;
	default :
	exit(0);
}
}
}

void getdata(struct student s[50], int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
	    printf("\nEnter for student %d.\n",i);
		printf("Enter your name: \n");
		scanf("%s",s[i].name);
		printf("Enter your roll: \n");
		scanf("%d",&s[i].roll);
		printf("Enter your address: \n");
		scanf("%s",s[i].add);
		printf("Enter your percentage: \n");
		scanf("%f",&s[i].per);
	}
}

void printdata(struct student s[50], int n)
{
	int i;
	printf("\n\n\n\t\t\t Student Information Portal: \t\t\t\n\n\n");
	for(i=1;i<=n;i++)
	{
		printf("Name of student is %s \n",s[i].name);

		printf("Roll No.: %d \n",s[i].roll);

		printf("Address: %s\n",s[i].add);

		printf("Percentage: %f \n",s[i].per);
	}
}

void linear(struct student s[50], int n)
{
	int i, key, flag=0, loc;
	printf("ENter roll no. to be searched\n");
	scanf("%d",&key);

	for(i=0;i<n;i++)
	{
		if(s[i].roll==key)
		{
			flag = 1;
			loc = i;
		}
	}
	if (flag ==1)
	{
	printf("Element found at loc %d \n",loc);
	}
}

void binary(struct student s[50], int n)
{
	int mid, low = 0, high = n-1;
	int find;
	int k = 0;
	printf("Enter the roll no. to be searched: \n");
	scanf("%d",&find);
	while(high>=low)
	{
		mid = (low + high)/2;
		if(s[mid].roll == find)
		{
			printf("Roll no. found \n");
			k++;
			break;
		}
		else if (s[mid].roll > find)
			high = mid-1;
		else
			low = mid +1;
	}
	if(k==0)
		printf("ROll no. not found \n");
}

int binary_rec(struct student s[50], int key, int low, int high)
{
	int mid;
	mid = (low+high)/2;
	if(s[mid].roll == key)
	return (mid);
	else if (s[mid].roll > key)
	binary_rec(s,key,low,mid-1);
	else if (s[mid].roll < key)
	binary_rec(s,key, mid+1, high);
	else
	return -1;
}

void bubbleSort(struct student s[50], int n)
{
	int i,j;
	struct student temp;

	for(i=1; i<n; i++)
	{
		for(j = 0; j< n-i; j++)
		{
		 	if(s[j].roll > s[j+1].roll)
		 	{

		 		temp = s[j];
		 		s[j] = s[j+1];
		 		s[j+1]=temp;
		 	}
		 }
	}
}

void selectionSort(struct student s[20], int n)
{
		int minpos;
		struct student temp;
		for(int i = 0; i<=n-2; i++)
		{
				minpos = i;
				for(int j = i+1; j<n; j++)
			{
				if(s[j].roll < s[minpos].roll)
					minpos = j;

			}
			if (minpos != i)
			{
				temp = s[i];
				s[i] = s[minpos];
				s[minpos] = temp;
			}

		}


}

void insertionSort(struct student s[20], int n)
{
	int j;
	struct student key;
	for (int i = 0; i < n; i++)
		{
		key = s[i];
		j = i-1;
		while(j >= 0 && s[i].roll > key.roll)
		{
			s[j+1] = s[j];
			j = j-1;
		}
		}
}




