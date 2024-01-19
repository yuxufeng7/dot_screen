#ifndef CHAR_SET_H
#define CHAR_SET_H

char num_0_buff[7][3] = 
{
    {1, 1, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 1, 1}
};

char num_1_buff[7][3] = 
{
    {0, 1, 0},
    {1, 1, 0},
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0},
    {1, 1, 1}
//    {1, 1, 1},
//    {1, 1, 1},
//    {1, 1, 1},
//    {1, 1, 1},
//    {1, 1, 1},
//    {1, 1, 1},
//    {1, 1, 1}
};

char num_2_buff[7][3] = 
{
    {1, 1, 1},
    {0, 0, 1},
    {0, 0, 1},
    {1, 1, 1},
    {1, 0, 0},
    {1, 0, 0},
    {1, 1, 1}
};

char num_3_buff[7][3] = 
{
    {1, 1, 1},
    {0, 0, 1},
    {0, 0, 1},
    {1, 1, 1},
    {0, 0, 1},
    {0, 0, 1},
    {1, 1, 1}
};

char num_4_buff[7][3] = 
{
    {1, 0, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 1, 1},
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1}
};

char num_5_buff[7][3] = 
{
    {1, 1, 1},
    {1, 0, 0},
    {1, 0, 0},
    {1, 1, 1},
    {0, 0, 1},
    {0, 0, 1},
    {1, 1, 1}
};

char num_6_buff[7][3] = 
{
    {1, 1, 1},
    {1, 0, 0},
    {1, 0, 0},
    {1, 1, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 1, 1}
};

char num_7_buff[7][3] = 
{
    {1, 1, 1},
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1},
    {0, 0, 1}
};

char num_8_buff[7][3] = 
{
    {1, 1, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 1, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 1, 1}
};

char num_9_buff[7][3] = 
{
    {1, 1, 1},
    {1, 0, 1},
    {1, 0, 1},
    {1, 1, 1},
    {0, 0, 1},
    {0, 0, 1},
    {1, 1, 1}
};

bitmap_t bitmap_num_0 = {
    .bitmap_buff_ptr = (char *)num_0_buff,
    .x_size = 3,
    .y_size = 7
};

bitmap_t bitmap_num_1 = {
    .bitmap_buff_ptr = (char *)num_1_buff,
    .x_size = 3,
    .y_size = 7
};

bitmap_t bitmap_num_2 = {
    .bitmap_buff_ptr = (char *)num_2_buff,
    .x_size = 3,
    .y_size = 7
};

bitmap_t bitmap_num_3 = {
    .bitmap_buff_ptr = (char *)num_3_buff,
    .x_size = 3,
    .y_size = 7
};

bitmap_t bitmap_num_4 = {
    .bitmap_buff_ptr = (char *)num_4_buff,
    .x_size = 3,
    .y_size = 7
};

bitmap_t bitmap_num_5 = {
    .bitmap_buff_ptr = (char *)num_5_buff,
    .x_size = 3,
    .y_size = 7
};

bitmap_t bitmap_num_6 = {
    .bitmap_buff_ptr = (char *)num_6_buff,
    .x_size = 3,
    .y_size = 7
};

bitmap_t bitmap_num_7 = {
    .bitmap_buff_ptr = (char *)num_7_buff,
    .x_size = 3,
    .y_size = 7
};

bitmap_t bitmap_num_8 = {
    .bitmap_buff_ptr = (char *)num_8_buff,
    .x_size = 3,
    .y_size = 7
};

bitmap_t bitmap_num_9 = {
    .bitmap_buff_ptr = (char *)num_9_buff,
    .x_size = 3,
    .y_size = 7
};

bitmap_t *bitmap_digits[10] = {
    &bitmap_num_0,
    &bitmap_num_1,
    &bitmap_num_2,
    &bitmap_num_3,
    &bitmap_num_4,
    &bitmap_num_5,
    &bitmap_num_6,
    &bitmap_num_7,
    &bitmap_num_8,
    &bitmap_num_9
};

#endif
