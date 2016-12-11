/usr/local/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -Wf-ba0 -c -o savevars.o savevars.c
/usr/local/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o main.o main.c

/usr/local/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -Wl-yt2 -Wl-yo4 -Wl-ya4 -o gbmmc.gb main.o savevars.o
