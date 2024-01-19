#include <stdio.h>
#include "driver_dot_screen.h"

static void write_screen(screen_t *dot_screen, char value);

static void write_screen(screen_t *dot_screen, char value)
{
    for(int i = 0; i < dot_screen->y_size; i++)
    {
        for(int j = 0; j < dot_screen->x_size; j++)
        {
            *(dot_screen->screen_space_ptr + i*dot_screen->x_size + j) = value;
        }
    }
}

void show_screen(screen_t *dot_screen)
{
    printf("\033[s");
    
    putchar(' ');
    for(int j = 0; j < dot_screen->x_size; j++)
    {
        putchar('-');
        putchar('-');
    }
    putchar('-');
    putchar(' ');
    putchar('\n');

    for(int i = 0; i < dot_screen->y_size; i++)
    {
        putchar('|');
        for(int j = 0; j < dot_screen->x_size; j++)
        {
           putchar(' ');
           putchar(*(dot_screen->screen_space_ptr + i*dot_screen->x_size + j));
        }
        putchar(' ');
        putchar('|');
        putchar('\n');
    }
    
    putchar(' ');
    for(int j = 0; j < dot_screen->x_size; j++)
    {
        putchar('-');
        putchar('-');
    }
    putchar('-');
    putchar(' ');
    putchar('\n');
    
    fflush(stdout);
    
    printf("\033[u");

}

void init_screen(screen_t *screen_ptr, char *screen_buffer_ptr, int x_size, int y_size)
{
    screen_ptr->screen_space_ptr = screen_buffer_ptr;
    screen_ptr->x_size = x_size;
    screen_ptr->y_size = y_size;
}

void clear_screen(screen_t *dot_screen)
{
    write_screen(dot_screen, PIXEL_OFF);
}

void fill_screen(screen_t *dot_screen)
{
    write_screen(dot_screen, PIXEL_ON);
}

void blit_bitmap(screen_t *dot_screen, int start_x, int start_y, bitmap_t *bitmap_ptr)
{
    char *start_ptr = dot_screen->screen_space_ptr + start_x + dot_screen->x_size*start_y;
    for(int i = 0; i < bitmap_ptr->y_size; i++)
    {
        for(int j = 0; j < bitmap_ptr->x_size; j++)
        {
            if(*(bitmap_ptr->bitmap_buff_ptr + i*bitmap_ptr->x_size + j))
                *(start_ptr + i*dot_screen->x_size + j) = PIXEL_ON;
            else
                *(start_ptr + i*dot_screen->x_size + j) = PIXEL_OFF;
        }
    }
}
