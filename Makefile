

CC = gcc
HEADER_PATH = /opt/homebrew/Cellar/ncurses/6.2/include
LIB_PATH = /opt/homebrew/Cellar/ncurses/6.2/lib

test_ui : test_ui.o
	${CC} -o test_ui test_ui.o -I${HEADER_PATH} -L${LIB_PATH} -lform -lncurses
