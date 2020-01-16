#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
int top=-1;
int st[MAX];
void decimalToBase(int deci,int base);
void push(int num);
int pop();
void baseToDecimal(int base,long long n);
int main()
{
    int ch,base,deci;
    long long n;
    printf("This program is based on the Base converter to Decimal and Decimal to Base\n\n");
    do
    {
        printf("Select any of the options given below\n\n");
        printf("1 Base to Decimal converter.\n");
        printf("2 Decimal to Base converter.\n");
        printf("IF YOU DO WANT TO EXIT PRESS 3.\n");
        printf("\nWhat is your choice from the above options : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the base and the respective base number\n");
            scanf("%d %lld",&base,&n);
            baseToDecimal(base,n);
            break;
        case 2:
            printf("Enter the decimal value\n");
            scanf("%d",&deci);
            printf("\nEnter the base number to which it should be computed\n");
            scanf("%d",&base);
            decimalToBase(deci,base);
            break;
        default:
            if(ch==3)
                return 0;
            printf("Please select the correct choice once again\n\n");
            break;
        }
    }while(ch!=3);
    return 0;
}
void decimalToBase(int deci,int base)
{
    int i,num,n,count=0;
    num=deci;
    while(num>0)
    {
        n=num%base;
        push(n);
        count++;
        num=num/2;
    }
    printf("The computed value is given by (");
    for(i=0;i<count;i++)
    {
        printf("%d",pop());
    }
    printf(") with base of %d\n\n",base);
}
void push(int num)
{
    if(top==MAX-1)
        {
            printf("We can't store more number of elements\n\t..Sorry..\t\n");
            return;
        }
    else
    {
        st[++top]=num;
    }
}
int pop()
{
    return st[top--];
}
void baseToDecimal(int base,long long n)
{
    int rem,deci=0,i=0;
    long long num=n;
    while(n!=0)
    {
        rem=n%10;
        n=n/10;
        deci=deci+rem*pow(base,i);
        i++;
    }
    printf("(%lld) of Base %d == %d of Decimal value\n\n",num,base,deci);
}
