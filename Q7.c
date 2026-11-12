#include <stdio.h>
int findMax(int *p,int n)
{
    int m=*p,i;
    for(i=1;i<n;i++)
        if(*(p+i)>m)
            m=*(p+i);
    return m;
}
int findMin(int *p,int n)
{
    int m=*p,i;
    for(i=1;i<n;i++)
        if(*(p+i)<m)
            m=*(p+i);
    return m;
}
double findAverage(int *p,int n)
{
    int s=0,i;
    for(i=0;i<n;i++)
        s=s+*(p+i);
    return (double)s/n;
}
int countAbove(int *p,int n,double avg)
{
    int c=0,i;
    for(i=0;i<n;i++)
        if(*(p+i)>avg)
            c++;
    return c;
}
void reverseArray(int *p,int n)
{
    int *a=p,*b=p+n-1;
    while(a<b)
    {
        int t=*a;
        *a=*b;
        *b=t;
        a++;
        b--;
    }
}
int searchMark(int *p,int n,int key)
{
    int i;
    for(i=0;i<n;i++)
        if(*(p+i)==key)
            return i;
    return -1;
}
void printArray(int *p,int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",*(p+i));
    printf("\n");
}
int main()
{
    int marks[10];
    int k,c=0,i;
    int *p;
    printf("Ms. Hina's Class Result\n");
    for(i=0;i<10;i++)
    {
        printf("Enter marks of Roll No %d (0-100): ",i+1);
        scanf("%d",&marks[i]);
        while(marks[i]<0||marks[i]>100)
        {
            printf("Invalid marks! Enter again: ");
            scanf("%d",&marks[i]);
        }
    }
    double a=findAverage(marks,10);
    printf("\nHighest Marks        : %d\n",findMax(marks,10));
    printf("Lowest Marks         : %d\n",findMin(marks,10));
    printf("Class Average        : %.2f\n",a);
    printf("Students Above Avg   : %d\n",countAbove(marks,10,a));
    for(p=marks;p<marks+10;p++)
        if(*p>=40)
            c++;
    printf("Students Passed      : %d\n",c);
    printf("\nEnter a mark to search: ");
    scanf("%d",&k);
    int r=searchMark(marks,10,k);
    if(r==-1)
        printf("Mark %d was not found in the class.\n",k);
    else
        printf("Mark %d found at position %d (Roll No %d)\n",k,r,r+1);
    printf("\nMarks before reversing: ");
    printArray(marks,10);
    reverseArray(marks,10);
    printf("Marks after reversing : ");
    printArray(marks,10);
    return 0;
}
