#include "util.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

void init(game_state_t *s) {
  char buf[MAX_LENGTH];
  int i, j;

  scanf("%d%d", &s->n, &s->m);
  s->grid = malloc(sizeof(int *) * s->n);
  for (i = 0; i < s->n; i++) {
    s->grid[i] = malloc(sizeof(int) * s->m);
    scanf("%s", buf);
    for (j = 0; j < s->m; j++) {
      s->grid[i][j] = buf[j] == 'T';
    }
  }
  scanf("%d%d", &s->start_x, &s->start_y);

  s->food = malloc(sizeof(int *) * s->n);
  for (i = 0; i < s->n; i++) {
    s->food[i] = malloc(sizeof(int) * s->m);
    scanf("%s", buf);
    for (j = 0; j < s->m; j++) {
      s->food[i][j] = buf[j] == 'T';
    }
  }

  scanf("%d", &s->num_ghosts);
  s->ghost_x = malloc(sizeof(int) * s->num_ghosts);
  s->ghost_y = malloc(sizeof(int) * s->num_ghosts);
  s->timer = malloc(sizeof(int) * s->num_ghosts);
  for (i = 0; i < s->num_ghosts; i++) {
    scanf("%d %d %d", &s->ghost_x[i], &s->ghost_y[i], &s->timer[i]);
  } 

  scanf("%d", &s->num_capsule);
  s->capsule_x = malloc(sizeof(int) * s->num_capsule);
  s->capsule_y = malloc(sizeof(int) * s->num_capsule);
  for (i = 0; i < s->num_capsule; i++) {
    scanf("%d %d", &s->capsule_x[i], &s->capsule_y[i]);
  } 
}

void destroy(game_state_t *s) {
  int i;
  for (i = 0; i < s->n; i++) {
    free(s->grid[i]);
    free(s->food[i]);
  }
  free(s->grid);
  free(s->food);
  free(s->ghost_x);
  free(s->ghost_y);
  free(s->capsule_x);
  free(s->capsule_y);
  free(s->timer);
}
