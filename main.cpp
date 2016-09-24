/*
   DR      :  AHMED YOUNES
   STUDENT : HUSSAM EL DIEN SALAH
   ID      : 126154
   SUB     : DATA STRUCURE PROJECT - CPU OUTING
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#define S 10
#define Q1 15
#define Q2 35
#define Q3 60
using namespace std;
typedef int EleType;
typedef struct node
{
    EleType data;
    struct node *next;
}Node;
typedef struct node *Stack;
typedef struct {
Node *Front;
Node *rear;
}Queue;
int IsEmpty(Stack s)
{
    Node *p;
    p=s;
    return p==NULL;
}

void printstack(Stack s,int choice)
{
    Node* p;
    p=s;
    if(IsEmpty(p)){printf("[Empty list]\n");}
    else{
        while(!IsEmpty(p))
        {
            if(choice==0)
                printf("%d\n",p->data);
            else
                printf("(%p,%d,%p)\n",p,p->data,p->next);
            p=p->next;
        }
        printf("\n");
        }
    }
EleType Pop(Stack *s)
{
    EleType x;
    Node *p, *q;
    p=*s;
    q=p->next;
    x=p->data;
    *s=q;
    free(p);
    return x;
}
int Push(Stack *s,EleType x)
{
    Node* p,*q;
    p=*s;
    q=(Node*)malloc(sizeof(Node));
    if(IsEmpty(q))
        {printf("Error\n");
    return 0;}
    q->data=x;
    q->next=p;
    *s=q;
    return 1;
}
void Init(Queue *Q)
{
    Q->Front=Q->rear=NULL;

}

int Enter(Queue *Q,EleType x)
{
    Node *p;
    p=(Node *)malloc(sizeof(Node));
    if(p==NULL)
    return 0;
    p->data=x;
    p->next=NULL;
    if(Q->Front==NULL && Q->rear==NULL)
    {
    Q->Front=Q->rear=p;
    }
    else
    {
        Q->rear->next=p;
        Q->rear=p;
    }
    return 1;
}

EleType Leave(Queue *Q)
{
    Node *p;
    EleType x;
    p=Q->Front;
    x=p->data;
    Q->Front=p->next;
    if(p->next==NULL)
    Q->rear=p->next;
    free(p);
    return x;
}
int Isempty(Queue Q)
{
    return ((Q.Front==NULL)&&(Q.rear==NULL));
}

int main(void)
{
    Queue q1,q2,q3;
    Stack s;
    int i,x,r,t;
    int zs,zq1,zq2,zq3;

    zs=0;zq1=0;zq2=0;zq3=0;
    Init(&q1);
    Init(&q2);
    Init(&q3);
    s=NULL;
    srand(unsigned(time(0)));
    i=1;
    while(i<=200)
  {
     r=rand() %100 +1;
     if(r>=0 && r<=30)//A1
        {
        if(zq1==Q1)continue ;
         Enter(&q1,i);
           zq1++;
            i++;
         }
         else if(r>30 && r<=45)//A2
            {
            if(Isempty(q1))continue;
            if(zs==S)continue;
            t=Leave(&q1);
             zq1--;
           Push(&s,t);
           zs++;
        }
         else if(r>45 && r<=60)//A3
        {
            if(Isempty(q1))continue;
            if(zq2==Q2)continue;
                t=Leave(&q1);
                 zq1--;
            Enter(&q2,t);
           zq2++;
        }
        else if(r>60 && r<=70)//A4
        {
            if(IsEmpty(s))continue;
                if(zq3==Q3)continue;
                t=Pop(&s);
                zs--;
            Enter(&q3,t);
           zq3++;
        }
       else  if(r>70 && r<80)//A5
        {
            if(Isempty(q2)) continue;
               if(zq3==Q3)continue;
                t=Leave(&q2);
                zq2--;
                Enter(&q3,t);
           zq3++;
        }
         else if(r>80 && r<=100)//A6
        {
            if(Isempty(q3)) continue;
            t=Leave(&q3);
            zq3--;
            printf("%d\n",t);
        }
    }
   printstack(s,0);
    printstack(s,5);
        while ((zq1+zq2+zq3+zs)>0)
{
     r=rand() %100 +1;
     if(r>=0 && r<=30)//A1
        {
        continue;
        }
         else if(r>30 && r<=45)//A2
            {
            if(Isempty(q1))continue;
            if(zs==S)continue;
            t=Leave(&q1);
             zq1--;
           Push(&s,t);
           zs++;
        }
         else if(r>45 && r<=60)//A3
        {
            if(Isempty(q1))continue;
            if(zq2==Q2)continue;
                t=Leave(&q1);
                 zq1--;
            Enter(&q2,t);
           zq2++;
        }
        else if(r>60 && r<=70)//A4
        {
            if(IsEmpty(s))continue;
                if(zq3==Q3)continue;
                t=Pop(&s);
                zs--;
            Enter(&q3,t);
           zq3++;
        }
       else  if(r>70 && r<80)//A5
        {
            if(Isempty(q2)) continue;
               if(zq3==Q3)continue;
                t=Leave(&q2);
                zq2--;
                Enter(&q3,t);
           zq3++;
        }
         else if(r>80 && r<=100)//A6
        {
            if(Isempty(q3)) continue;
            t=Leave(&q3);
            zq3--;
            printf("%d\n",t);
        }
    }
         printstack(s,0);
    printstack(s,5);
}
