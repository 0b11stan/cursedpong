#include <stdbool.h>
#include <time.h>
#include <curses.h>
#include <unistd.h>

void init() {
  initscr();
  cbreak();
  nodelay(stdscr, TRUE);
  clearok(stdscr, TRUE);
  keypad(stdscr, TRUE);
  leaveok(stdscr, TRUE);
  curs_set(0);
}

struct player {
  int posx;
  int posy;
  char skin;
};

void display_player(struct player *p) {
  printf("(%d, %d, %c)", player->posx, player->posy, player->skin);
}

int main() {
  init();

  struct player p1 = {0, 0, '#'};

  int maxx, maxy;
  getmaxyx(stdscr, maxx, maxy);

  bool need_clear = FALSE;

  while (true) {
    switch (getch()) {
      case KEY_UP:
        if (p1.posy >= 0) p1.posy--;
        display_player(p1); return 0;
        need_clear = TRUE;
        break;
      case KEY_DOWN:
        if (p1.posy <= maxy) p1.posy++;
        need_clear = TRUE;
        break;
      case KEY_LEFT:
        if (p1.posx <= 0) p1.posx--;
        need_clear = TRUE;
        break;
      case KEY_RIGHT:
        if (p1.posx >= maxx) p1.posx++;
        need_clear = TRUE;
        break;
    }

    mvaddch(p1.posx, p1.posy, p1.skin);

    if (need_clear) {
      erase();
      refresh();
    }
  }
  endwin();
  return 0;
}
