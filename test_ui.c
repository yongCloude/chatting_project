#include <ncurses.h>
#include <locale.h>
#include <form.h>
#include <panel.h>
#include <menu.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    WINDOW *win;
    WINDOW *sub, *sub2;
    int startx, starty, width, height;

    setlocale(LC_CTYPE, "ko_KR.utf-8");
    
    int ch;

    initscr();
    start_color();
    cbreak();
    keypad(stdscr, true);

    
    /* Initialize all the colors */
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    
    char test[100] = "";

    while(wgetch(win) != '\n'){

        char prompt[] = "chatting program(ver 0.0.1)";
        getmaxyx(stdscr,starty, startx);
        
        win = newwin(starty, startx, 0,0);
        
        wattron(win, COLOR_PAIR(4));
        box(win, ACS_VLINE, ACS_HLINE);
        mvwhline(win, 2, 1, ACS_HLINE, startx-2); 
    
        mvwvline(win, 3,(startx / 3)+1, ACS_LARROW,starty-2 -2 );
        mvwvline(win, 3,(startx / 3)+2, ACS_RARROW,starty-2 -2 );
        wattroff(win,COLOR_PAIR(4));

        wattron(win, COLOR_PAIR(1));
        mvwaddstr(win,1, startx /2 - (strlen(prompt)) / 2, prompt);
        wattroff(win, COLOR_PAIR(1));
        
        //wborder(win, '|', '|', '-', '-', '-', '-','-','-');

        sub = subwin(win,starty -4, (startx / 3) -1 , 3,2);
        sub2 = subwin(win, ((starty-2)-2), startx - (startx / 3) - 5, 3, (startx / 3) + 3);

        mvwprintw(sub, 1,1,"%s\n", test);
        wattron(sub, COLOR_PAIR(5));
        box(sub,ACS_VLINE,ACS_HLINE);
        wmove(sub, 2, 1);
        whline(sub, ACS_HLINE, startx/3 - 3);
        mvwhline(sub, 2, 1, ACS_HLINE, startx / 3 - 3);
        wattroff(sub, COLOR_PAIR(5));
        
        //waddch(sub, ACS_HLINE);

        box(sub2,ACS_VLINE,ACS_HLINE);

        mvwaddstr(win,1, 2, "EXIT");
        
        
        

        
        refresh();
        
        wrefresh(win);
        wrefresh(sub);
        wrefresh(sub2);
	    
        
        
        
          
    }

   
    
    
    endwin();
    return 0;
}
