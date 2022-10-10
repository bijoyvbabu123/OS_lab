#include <stdio.h>

#include <stdlib.h>

#define MAX 25
int n, head, size, seek_count, tracks[MAX], sequence[MAX];
char dir;
void sort(int arr[], int m) {
  int temp;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
void scands() {
  int curr_track, distance, l = 0, r = 0, left[MAX], right[MAX];
  seek_count = 0;
  if (dir == 'L') {
    left[0] = 0;
    l++;
  } else if (dir == 'R') {
    right[0] = size - 1;
    r++;
  }
  for (int i = 0; i < n; i++) {
    if (tracks[i] < head)
      left[l++] = tracks[i];
    if (tracks[i] > head)
      right[r++] = tracks[i];
  }
  sort(left, l);
  sort(right, r);
  int run = 2, x = 0;
  while (run--> 0) {
    if (dir == 'L') {
      for (int i = l - 1; i >= 0; i--) {
        curr_track = left[i];
        sequence[x++] = curr_track;
        distance = abs(head - curr_track);
        seek_count += distance;
        head = curr_track;
      }
      dir = 'R';
    } else {
      for (int i = 0; i < r; i++) {
        curr_track = right[i];
        sequence[x++] = curr_track;
        distance = abs(head - curr_track);
        seek_count += distance;
        head = curr_track;
      }
      dir = 'L';
    }
  }
}
int main() {
  int i;
  printf("\n SCAN Disk Scheduling\n");
  printf("\n Enter the size of the disk : ");
  scanf("%d", & size);
  printf("\n Enter the number of tracks to be seeked : ");
  scanf("%d", & n);
  if (n > MAX) {
    printf("\n Number of tracks to be seeked cannot exceed %d Exiting...\n", MAX);
    exit(0);
  }
  printf("\n Enter the starting position of the head : ");
  scanf("%d", & head);
  if (head > size) {
    printf("\n Starting position of head cannot exceed the size of disk. Exiting...\n");
    exit(0);
  }
  printf("\n Enter the initial direction of the head(L/R) : ");
  scanf(" %c", & dir);
  if ((dir != 'L') && (dir != 'R')) {
    printf("\n Invalid direction input. Exiting...\n");
    exit(0);
  }
  printf("\n Enter the tracks to be seeked : ");
  for (int i = 0; i < n; i++)
    scanf("%d", & tracks[i]);
  scands();
  printf("\n The Seek Sequence is : ");
  for (i = 0; i < n; i++)
    printf(" %d -> ", sequence[i]);
  printf(" %d\n", sequence[i]);
  printf("\n The Seek Count is : %d\n", seek_count);
  return 0;
}