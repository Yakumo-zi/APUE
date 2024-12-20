LIBDIR=../lib/
INCLUDE=../include/
LIBS=../lib/error.c
TARGET:=$(subst .c,,$(FILE))

.PHONY:all clean

all:
	gcc -o $(TARGET) $(FILE) $(LIBS) -I$(INCLUDE) -L$(LIBDIR)

clean:
	rm $(TARGET)
