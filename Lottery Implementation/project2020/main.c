#include <stdio.h>
#include <stdlib.h>
int main()
{
    int metric,numbers,i,j,a[300][7],k=0,num,counter,i1,j1,first[300][7],last,n1,count=1;
    char s[30];
    float store[49][5],temp,fl;
    //read numbers,metric,file
    scanf("%d %d %s",&numbers,&metric,s);
    FILE *f;
    f=fopen(s,"r");
    if((metric<=-1 || metric>=4) ||(numbers<=0 || numbers>=50 ))
    {
        printf("Wrong Input!");
        return 0;
    }
    counter=0;
    if(f!=NULL)
    {
        for (counter = getc(f); counter != EOF; counter = getc(f)) {
           if (counter == '\n') // Increment count if this character is newline
            count = count + 1;
        }
        rewind(f);
        for(i=0;i<count;i++)
        {
            for(j=0;j<7;j++)
            {
                fscanf(f,"%d",&a[i][j]);
            }
        }
        fclose(f);
    }
    else
    {
         printf("File Error!");
         return 0;
    }
   //printf("\n%d",count);
   //printf("\n");

   /* for(i=0;i<10;i++)
    {
        for(j=0;j<7;j++)
        {
            printf("%d  ",a[i][j]);
        }
        printf("\n");
    }*/
    /* for(i=0;i<n;i++)
     {
       for(j=0;j<n2;j++)
       {
          scanf("%d",&a[i][j]);
       }
     }
     printf("\n");
     printf("Enter the numbers & metric:");
     scanf("%d %d",&number,&metric);
     //printf("\n");*/
     k=1;
     for(i=0;i<49;i++)
     {

         store[i][0]=k;
         store[i][1]=0.0;
         store[i][2]=10.0;
         store[i][3]=10.0;
         store[i][4]=0.0;
         k++;
     }
     //initialize the visited array
      for(i=0;i<count;i++)
     {
         for(j=0;j<7;j++)
           first[i][j]=0;
     }
     //calculate the frequency of each element and the last time that element appear
     for(i=0;i<count;i++)
 {
     last=i;
       //printf("\nFor %d:",i);
       for(j=0;j<7;j++)
     {
          counter=1;
          num=a[i][j];

          if(first[i][j]!=1)
        {
            //printf("\nNum %d",a[i][j]);
          for(i1=0;i1<count;i1++)
          {
            for(j1=0;j1<7;j1++)
             {
              //With continue the next will be skipped and y will get the next value
              if((i==i1)&&(j==j1))
              {
                continue;
              }
              if(a[i][j]==a[i1][j1])
               {

                first[i1][j1]=1;
                counter++;
                last=i;
                //printf("\n x %d y %d ",x,y);
              }
            }
          }
          fl=(float)count;
         // printf(" %d %d ",c,last);
          for(k=0;k<49;k++)
          {
             if(num==store[k][0])
            {
                store[k][1]=counter;
                store[k][2]=last;
                store[k][3]=store[k][1]+store[k][2];
                store[k][4]=(float)(store[k][2]-(fl/store[k][1]));


             }

          }
      }

   }
}
    //print the frequency of each value
    /* for(i=0;i<49;i++)
          {
              for(j=0;j<5;j++)
              {
                printf("%0.2f   ",store[i][j]);
              }
              printf("\n");
          }

printf("\n");*/
  /* for(i=0;i<49;i++)
    {
        max=i;
        for(j=49;j>i;j--)
        {
            if(store[j][metric+1]>store[max][metric+1])
            {
                max=j;
            }
        }
        temp=store[i][metric+1];
        store[i][metric+1]=store[max][metric+1];
        store[max][metric+1]=temp;

        temp=store[i][0];
        store[i][0]=store[max][0];
        store[max][0]=temp;
       // printf("\n%.1f %.1f",store[i][metric+1],store[i][0]);
    }*/
    for(i=0;i<49;i++)
    {
        for(j=48;j>i;j--)
        {
            if(store[j - 1][metric+1]<store[j][metric+1])
            {
                for(k=0;k<5;k++)
                {
                    temp=store[j -1][k];
                    store[j - 1][k] =store[j][k];
                    store[j][k]=temp;
                }
            }
        }
    }
   for(i=0;i<49;i++)
    {
        for(j=0;j<5;j++)
            printf("%0.1f  ",store[i][j]);
        printf("\n");
    }

       printf("\n");
       for(i=0;i<numbers;i++)
       {
           n1=(int)store[i][0];
           printf("%d ",n1);
       }


    return 0;
}
