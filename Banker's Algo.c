#include<stdio.h>
int main()
{
    // assume there are 5 processes
    // P0,P1,P2,P3,P4 are their name

    int n,m,i,j,k;
    n = 5; // number of processes
    m = 4;// number of resources
    //allocation matrix
    int alloc[5][4] = {{0,1,1,0},
                       {1,2,3,1},
                       {1,3,6,5},
                       {0,6,3,2},
                       {0,0,1,4}};
    // maximum matrix
    int max[5][4] = {{0,2,1,0},
                     {1,6,5,2},
                     {2,3,6,6},
                     {0,6,5,2},
                     {0,6,5,6}};
    // Available Resources
    int available[4] = {1,5,2,0};
    int x[n],res[n],ind = 0;
    for(int y = 0;y<n;y++){
        x[y] = 0;
    }
    int need[n][m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y =0;
    for(k = 0;k<n;k++){
        for(i=0;i<n;i++){
            if(x[i] == 0){
                int temp = 0;
                for(j=0;j<m;j++){
                    if(need[i][j] > available[j]){
                        temp = 1;
                        break;
                    }
                }
                if(temp==0){
                    res[ind++] = i;
                    for(y=0;y<m;y++)
                        available[y] += alloc[i][y];
                    x[i] = 1;
                }
            }
        }
    }
      int temp = 1;
      for(i=0;i<n;i++){
        if(x[i] == 0){
            temp = 0;
            printf("The system is not safe");
            break;
        }
      }
      if(temp == 1)
      {
          printf("system is the safe sequence\n");
          for(i=0;i<n-1;i++)
            printf("P%d ->",res[i]);
          printf("P%d",res[n-1]);
      }
      return(0);
}
