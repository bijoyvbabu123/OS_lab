#include <stdio.h>

#include <stdlib.h>

#define MAX 25
int n, head, seek_count, tracks[MAX];
void fcfsds() {
  int curr_track, distance;
  seek_count = 0;
  for (int i = 0; i < n; i++) {
    curr_track = tracks[i];
    distance = abs(head - curr_track);
    seek_count += distance;
    head = curr_track;
  }
}
int main() {
  printf("\n FCFS Disk Scheduling\n");
  printf("\n Enter the number of tracks to be seeked : ");
  scanf("%d", & n);
  if (n > MAX) {
    printf("\n Number of tracks to be seeked cannot exceed %d. Exiting...\n", MAX);
    exit(0);
  }
  printf("\n Enter the starting position of the head : ");
  scanf("%d", & head);
  printf("\n Enter the tracks to be seeked : ");
  for (int i = 0; i < n; i++)
    scanf("%d", & tracks[i]);
  fcfsds();
  printf("\n The Seek Sequence is : ");
  for (int i = 0; i < n - 1; i++)
    printf(" %d -> ", tracks[i]);
  printf(" %d\n", tracks[n - 1]);
  printf("\n The Seek Count is : %d\n", seek_count);
  return (0);
}