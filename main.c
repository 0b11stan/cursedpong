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
  char text[15];
  sprintf(text, "(%d, %d)", p->posx, p->posy);
  addstr(text);
}

int main() {
  init();

  struct player p1 = {5, 5, '#'};

  bool need_clear = FALSE;

  while (true) {
    switch (getch()) {
      case KEY_UP:
        if (p1.posy >= 2) p1.posy--;
        need_clear = TRUE;
        break;
      case KEY_DOWN:
        if (p1.posy <= getmaxy(stdscr) - 2) p1.posy++;
        need_clear = TRUE;
        break;
      case KEY_LEFT:
        if (p1.posx >= 1) p1.posx--;
        need_clear = TRUE;
        break;
      case KEY_RIGHT:
        if (p1.posx <= getmaxx(stdscr) - 2) p1.posx++;
        need_clear = TRUE;
        break;
    }

    if (need_clear) {
      erase();
      display_player(&p1);
      mvaddch(p1.posy, p1.posx, p1.skin);
      refresh();
    }
  }
  endwin();
  return 0;
}
