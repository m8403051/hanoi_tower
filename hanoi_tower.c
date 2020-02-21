/*
  3柱河內塔
  執行後輸入要搬幾個 disk
*/
#include <stdio.h>

int tower_a[100];
int tower_b[100];
int tower_c[100];
int tail[4]={0,0,0,0};
int step=0;

void show_tower()
{
  int tail_local;
  
  tail_local=1;
  printf("tower A: ");
  while(tail_local<=tail[1])
  {
    printf("%d ", tower_a[tail_local]);
    tail_local++;
  }

  tail_local=1;
  printf("\ntower B: ");
  while(tail_local<=tail[2])
  {
    printf("%d ", tower_b[tail_local]);
    tail_local++;
  }
  tail_local=1;
  printf("\ntower C: ");
  while(tail_local<=tail[3])
  {
    printf("%d ", tower_c[tail_local]);
    tail_local++;
  }
  printf("\n=====================\n");
}

void init(int disk)
{
  int i;
  tower_a[0]=0;
  tower_b[0]=0;
  tower_c[0]=0;
  
  for(i=1;i<=disk;i++)
  {
    tower_a[i]=disk-i+1;
  }
  tail[1] = i-1;
  show_tower();
}

int check_tc(int a, int b)
{
  int c=0;
  if(a==1)
  {
    if(b==2)
      c=3;
    else
      c=2;
  }
  else if(a==2)
  {
    if(b==1)
      c=3;
    else
      c=1;
  }
  else
  {
    if(b==1)
      c=2;
    else
      c=1;
  }
  return c;
}

void move_disk(int disk, int t_a, int t_b)
{
  int disk_move;
  int t_c=check_tc(t_a, t_b);

  if(disk==1)
  {
    step++;
    switch(t_a)
    {
      case 1:
          disk_move=tower_a[tail[1]];
          tower_a[tail[1]]=0;
          tail[1]=tail[1]-1;
          break;
      case 2:
          disk_move=tower_b[tail[2]];
          tower_b[tail[2]]=0; 
          tail[2]=tail[2]-1;
          break;
      case 3:
          disk_move=tower_c[tail[3]];
          tower_c[tail[3]]=0;        
          tail[3]=tail[3]-1;          
          break;
      default:
          printf("error!!\n");
    }
    switch(t_b)
    {
      case 1:
          tail[1]=tail[1]+1;
          tower_a[tail[1]]=disk_move;
          break;
      case 2:
          tail[2]=tail[2]+1;
          tower_b[tail[2]]=disk_move;
          break;
      case 3:
          tail[3]=tail[3]+1;
          tower_c[tail[3]]=disk_move;
          break;
      default:
          printf("error!!\n");
    }

    show_tower();
  }
  else
  {
    move_disk(disk-1, t_a, t_c);
    move_disk(1, t_a, t_b);
    move_disk(disk-1, t_c, t_b);
  }
}

int main(void)
{
  int disk;
  printf("input number of tower: ");
  disk=getchar()-'0';
  init(disk);
  move_disk(disk,1,3);
  printf("done, total %d steps\n",step);
}