#ifndef DRIVER_DOT_SCREEN_H 
#define DRIVER_DOT_SCREEN_H 

typedef struct
{
    char *screen_space_ptr;
    int x_size;
    int y_size;
}screen_t;

typedef struct {
    char *bitmap_buff_ptr;
    int x_size;
    int y_size;
} bitmap_t;

typedef enum
{
    PIXEL_ON = '#',
    PIXEL_OFF = ' '
} pixel_state;

extern void init_screen(screen_t *screen_ptr, char *screen_buffer_ptr, int x_size, int y_size);
extern void clear_screen(screen_t *dot_screen);
extern void fill_screen(screen_t *dot_screen);
extern void show_screen(screen_t *dot_screen);
extern void blit_bitmap(screen_t *dot_screen, int start_x, int start_y, bitmap_t *bitmap_ptr);
    
#endif
