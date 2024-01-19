#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "driver_dot_screen.h"
#include "char_set.h"

#define X_MAX 16
#define Y_MAX 8
#define HHMM_LEN 4
#define MMSS_LEN 4

char my_screen_space[Y_MAX][X_MAX] = {0};
screen_t my_screen;

char hhmm[HHMM_LEN] = {};
char mmss[MMSS_LEN] = {};
bitmap_t progress_bitmap;
char progress_buff[1][X_MAX] = {};

void get_hhmm(char *hhmm, int hhmm_len);
void get_mmss(char *mmss, int mmss_len);
void get_sec_progress(char (*prg_buff)[X_MAX], int prg_buff_len);
void blit_time_digits(screen_t *dot_screen, char *time_digits, int time_digits_len);

int main()
{
    init_screen(&my_screen, (char *)my_screen_space, X_MAX, Y_MAX);
    fill_screen(&my_screen);
    show_screen(&my_screen);
    sleep(1);

    progress_bitmap.x_size = X_MAX;
    progress_bitmap.y_size = 1;
    progress_bitmap.bitmap_buff_ptr = (char *)progress_buff;

    clear_screen(&my_screen);

    while (1) 
    {
        get_hhmm(hhmm, HHMM_LEN);
        get_sec_progress(progress_buff, sizeof(progress_buff));

        blit_bitmap(&my_screen, 0, Y_MAX - 1, &progress_bitmap);
        blit_time_digits(&my_screen, hhmm, HHMM_LEN);
        show_screen(&my_screen);

        sleep(1);
    }
    return 0;
}

void get_hhmm(char *hhmm, int hhmm_len)
{
    time_t current_time;
    struct tm *timeinfo;
    char time_str[50];

    time(&current_time);
    timeinfo = localtime(&current_time);

    // Format the time into a string
    strftime(time_str, sizeof(time_str), "%H%M", timeinfo);
    memcpy(hhmm, time_str, hhmm_len);
}

void get_mmss(char *mmss, int mmss_len)
{
    time_t current_time;
    struct tm *timeinfo;
    char time_str[50];

    time(&current_time);
    timeinfo = localtime(&current_time);

    // Format the time into a string
    strftime(time_str, sizeof(time_str), "%M%S", timeinfo);
    memcpy(mmss, time_str, mmss_len);
}

void blit_time_digits(screen_t *dot_screen, char *time_digits, int time_digits_len)
{
    int index;
    for(int i = 0; i < time_digits_len; i++)
    {
        index = time_digits[i] - '0';
        blit_bitmap(dot_screen, i*4, 0, bitmap_digits[index]);
    }
}

void get_sec_progress(char (*prg_buff)[X_MAX], int prg_buff_len)
{
    time_t current_time;
    struct tm *timeinfo;
    
    time(&current_time);
    timeinfo = localtime(&current_time);
    int progress = (int)(((float)(timeinfo->tm_sec) / 59.0) * (float)prg_buff_len);

    memset(prg_buff, 0, prg_buff_len);
    for (int i = 0; i < progress; i++)
    {
        prg_buff[0][i] = 1;
    }
}

