#include "bit_manip.h"


// Keeps the screen from scrolling for the given delay.
void pause_display_output(int delay)
{
    for (int i = 0; i < delay; i++) {
        sleep(1);
    }
}


// Keeps the screen from scrolling for the given delay.
void pause_for_input(int delay)
{
    char buf[5] = {0};
    fd_set rfds;
    struct timeval tv;
    int ret;

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
     
    tv.tv_sec = delay;
    tv.tv_usec = 0;

    ret = select(1, &rfds, 0, 0, &tv);

    if (ret && FD_ISSET(0, &rfds)) {
        memset(buf, 0, sizeof(buf));
        ret = read(0, buf, sizeof(buf));
        printf("%c\n", buf[0]);
    }

}
