#include<stdio.h>
#include<conio.h>


int mod(int x)
  {
       if(x<0)
       return (-x);
       else
       return x;
  }                

int main()
{
    int dir;
    int wt[8][8]={
                     {200,200,200,200,200,200,200,200},
                     {200,0,200,0,0,0,0,200},
                     {200,0,0,200,0,0,0,200},
                     {200,0,0,0,200,0,0,200},
                     {200,0,0,0,0,200,0,200},
                     {200,0,0,200,0,200,0,200},
                     {200,0,0,0,0,0,0,200},
                     {200,200,200,200,200,200,200,200}
                  };
                                       
    
    int i,j,t,r,c;
    int stack[15];
    int top;
    r=5;
    c=6;
    
    
  /*  for(i=0;i<8;i++)
    {printf("\nnext\n");
                    for(j=0;j<8;j++)
                    {
                                    printf("enter the entry\n");
                                    scanf("   %d",&arr[i][j]);
                    }
    }*/
    
    
    
    
    
    for(i=1;i<7;i++)
    {
                    for(j=1;j<7;j++)
                    {
                                if(wt[i][j]==0)
                                {
                                   t=mod(r-i);
                                   wt[i][j]=t;
                                    t=mod(c-j);
                                    wt[i][j]+=t;
                                }
                    }  
    }   
    
    
     for(i=0;i<8;i++)
    {
                    printf("\n");
                    for(j=0;j<8;j++)
                    {
                                    printf("%4d",wt[i][j]);
                    }
    }
    i=1;
    j=1;
    top=0;
    stack[0]=1;
    dir =1;
    while( (i!=r)||(j!=c)  )                                                                               
    {
           if(dir==1)
           {
                      if(wt[i][j+1]==wt[i][j]-1)//forward
                      {
                                                              stack[++top]=1;
                                                              j++;
                                                              dir=1;
                      }
                     else if(wt[i-1][j]==wt[i][j]-1)//left
                      {
                                                              stack[++top]=2;
                                                              i--;
                                                              dir=2;
                                                              
                      }
                    else if(wt[i+1][j]==wt[i][j]-1)   //right
                      {
                                                              stack[++top]=4;
                                                              i++;
                                                              dir=4;//printf(" %4d",stack[top]);
                                                              
                      }
                      else
                      {
                          wt[i][j]+=2;
                          /* for(i=0;i<=top;i++)
                          {
                                             printf("%4d",stack[i]);
                          }
                          printf("\n");*/
                          top=0;
                          i=1;
                          j=1;
                      }
           }
           else if(dir==2)
           {
                 if(wt[i-1][j]==wt[i][j]-1)//forward
                      {
                                                              stack[++top]=2;
                                                              i--;
                                                              dir=2;
                      }
                     else if(wt[i][j-1]==wt[i][j]-1)//left
                      {
                                                              stack[++top]=3;
                                                              j--;
                                                              dir=3;
                                                              
                      }
                    else if(wt[i][j+1]==wt[i][j]-1)   //right
                      {
                                                              stack[++top]=1;
                                                              j++;
                                                              dir=1;
                      }
                      else
                      {
                          wt[i][j]+=2;
                          /* for(i=0;i<=top;i++)
                          {
                                             printf("%4d",stack[i]);
                          }
                          printf("\n");*/
                          top=0;
                          i=1;
                          j=1;
                      }
           }
           else if(dir==3)
           {
                 if((wt[i][j-1]==wt[i][j]-1))//forward
                      {
                                                              stack[++top]=3;
                                                              j--;
                                                              dir=3;
                      }
                     else if(wt[i+1][j]==wt[i][j]-1)//left
                      {
                                                              stack[++top]=4;
                                                              i++;
                                                              dir=4;
                                                              
                      }
                    else if(wt[i-1][j]==wt[i+1][j]-1)   //right
                      {
                                                              stack[++top]=2;
                                                              i--;
                                                              dir=2;
                      }
                      else
                      {
                          wt[i][j]+=2;
                         /*  for(i=0;i<=top;i++)
                          {
                                             printf("%4d",stack[i]);
                          }
                          printf("\n");*/
                          top=0;
                          i=1;
                          j=1;
                      }
           }
            else if(dir==4)
           {
                 if((wt[i+1][j]==wt[i][j]-1))//forward
                      {
                                                             
                                                              i++;
                                                              dir=4;
                                                               stack[++top]=4;//printf(" %4d",stack[top]);
                      }
                     else if(wt[i][j+1]==wt[i][j]-1)//left
                      {
                                                              stack[++top]=1;
                                                              j++;
                                                              dir=1;//printf(" %4d",stack[top]);
                                                              
                      }
                    else if(wt[i][j-1]==wt[i][j]-1)   //right
                      {
                                                              stack[++top]=3;
                                                              j--;
                                                              dir=3;//printf(" %4d",stack[top]);getch();
                      }
                      else
                      {
                         // printf("in");
                          wt[i][j]+=2;
                         
                         // printf("\n");
                          top=0;
                          i=1;
                          j=1;
                      }
           }
                
    }
    
     
      for(i=0;i<=top;i++)
                          {
                                             printf("%4d",stack[i]);
                          }
      i=0;
     dir=1;
     
     while(i<=top)
     {
                  if(stack[i]==dir)
                  {
                                   printf("\n forward delay(100ms)  nd move till nxt node\n");
                  }
                 else if((stack[i]==dir+1)||(stack[i]==1&&dir==4))
                  {
                                   printf("\n turn left \n");
                  }
                 else if((stack[i]==dir-1)||(stack[i]==4&&dir==1))
                  {
                                 printf("\n turn right \n");
                  }
                  dir=stack[i];
                  i++;
     }
     printf("\n destination reached    \n   HAPPY ENDING      \n");
     getch();
     return 0;
}






    
                                                              
    
