#include <stdio.h>
#include <string.h>
void readMarks(int *m1,int *m2,int *m3)
{
    printf("Enter marks of subject 1 (0-100): ");
    scanf("%d",m1);
    while(*m1<0||*m1>100)
    {
        printf("Invalid! Enter again: ");
        scanf("%d",m1);
    }
    printf("Enter marks of subject 2 (0-100): ");
    scanf("%d",m2);
    while(*m2<0||*m2>100)
    {
        printf("Invalid! Enter again: ");
        scanf("%d",m2);
    }
    printf("Enter marks of subject 3 (0-100): ");
    scanf("%d",m3);
    while(*m3<0||*m3>100)
    {
        printf("Invalid! Enter again: ");
        scanf("%d",m3);
    }
}
void calculateStats(int m1,int m2,int m3,int *total,double *average,int *highest,int *lowest)
{
    *total=m1+m2+m3;
    *average=*total/3.0;
    *highest=m1;
    if(m2>*highest)
        *highest=m2;
    if(m3>*highest)
        *highest=m3;
    *lowest=m1;
    if(m2<*lowest)
        *lowest=m2;
    if(m3<*lowest)
        *lowest=m3;
}
void swapMarks(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void addGraceMarks(int *mark,int grace)
{
    if(grace>5)
        grace=5;
    if(*mark>=35&&*mark<=39&&40-*mark<=grace)
        *mark=40;
}
void findGrade(double avg,char *grade,char *remarks)
{
    if(avg>=80)
    {
        *grade='A';
        strcpy(remarks,"Excellent");
    }
    else if(avg>=60)
    {
        *grade='B';
        strcpy(remarks,"Good");
    }
    else if(avg>=40)
    {
        *grade='C';
        strcpy(remarks,"Needs Improvement");
    }
    else
    {
        *grade='F';
        strcpy(remarks,"Needs Improvement");
    }
}
void incrementByValue(int x)
{
    x++;
}
void incrementByReference(int *x)
{
    (*x)++;
}
int main()
{
    int a,b,c,h,l,i;
    int t[5],m[5][3];
    double v[5];
    char g[5];
    char r[5][20];
    for(i=0;i<5;i++)
    {
        printf("\nStudent %d\n",i+1);
        readMarks(&a,&b,&c);
        addGraceMarks(&a,5);
        addGraceMarks(&b,5);
        addGraceMarks(&c,5);
        if(a<b)
            swapMarks(&a,&b);
        if(a<c)
            swapMarks(&a,&c);
        if(b<c)
            swapMarks(&b,&c);
        m[i][0]=a;
        m[i][1]=b;
        m[i][2]=c;
        calculateStats(a,b,c,&t[i],&v[i],&h,&l);
        findGrade(v[i],&g[i],r[i]);
        printf("Highest: %d  Lowest: %d\n",h,l);
    }
    printf("\n%-10s%-16s%-8s%-10s%-8s%s\n","Student","Marks","Total","Average","Grade","Remarks");
    
    for(i=0;i<5;i++)
        printf("%-10d%-5d%-5d%-6d%-8d%-10.2f%-8c%s\n",i+1,m[i][0],m[i][1],m[i][2],t[i],v[i],g[i],r[i]);
    int x=10;
    
    printf("Original value: %d\n",x);
    incrementByValue(x);
    printf("After incrementByValue: %d\n",x);
    incrementByReference(&x);
    printf("After incrementByReference: %d\n",x);
    return 0;
}
