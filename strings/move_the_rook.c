#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ROOK_MOVES 14
#define POS_SIZE 3

int convert_x(char x)
{
    switch (x)
    {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
        default:
            return -1;
    }
}



int find_moves(char cur_pos[], char possible_moves[ROOK_MOVES][POS_SIZE])
{
    char horizontal_spaces[] = "abcdefgh";
    char vertical_spaces[] = "12345678";
    char *vertend, *vertptr = cur_pos + 1;

    int horiz_idx = convert_x(cur_pos[0]);
    int vert_idx = strtol(vertptr, &vertend, 10) - 1;

    for (int i = 0; i < ROOK_MOVES / 2; i++)
    {
        if (i < vert_idx)
        {
            char new_pos[POS_SIZE] = {horizontal_spaces[horiz_idx], vertical_spaces[i]};
            strncpy(possible_moves[i], new_pos, POS_SIZE);
        }
        else
        {
            char new_pos[POS_SIZE] = {horizontal_spaces[horiz_idx], vertical_spaces[i + 1]};
            strncpy(possible_moves[i], new_pos, POS_SIZE);
        }

        if (i < horiz_idx)
        {
            char new_pos[POS_SIZE] = {horizontal_spaces[i], vertical_spaces[vert_idx]};
            strncpy(possible_moves[i + ROOK_MOVES / 2], new_pos, POS_SIZE);
        }
        else
        {
            char new_pos[POS_SIZE] = {horizontal_spaces[i + 1], vertical_spaces[vert_idx]};
            strncpy(possible_moves[i + ROOK_MOVES / 2], new_pos, POS_SIZE);
        }
    }
    return EXIT_SUCCESS;
}

void find_moves_better(char current_position[], char output_buffer[])
{
    // const char cols[] = "abcdefgh";
    // const char rows[] = "12345678";

    const char cols_rows[] = "abcdefgh12345678";

    char cur_col = current_position[0];
    char cur_row = current_position[1];
    char *dst = output_buffer;

    for (const char *p = cols_rows; *p; p++)
    {
        *dst++ = isdigit(*p) ? cur_col : *p;
        *dst++ = isdigit(*p) ? *p : cur_row;
        *dst++ = ' ';
    }

    // for (const char *c = cols, *r = rows; *c || *r; *c ? c++ : r++)
    // {
    //     *dst++ = *c ? *c : cur_col;
    //     *dst++ = *c ? cur_row : *r;
    //     *dst++ = ' ';
    // }
    *dst = '\0';
}

int print_moves(char possible_moves[ROOK_MOVES + 1][POS_SIZE])
{
    printf("You can move to: ");
    for (int i = 0; i < ROOK_MOVES; i++)
    {
        printf("%s", possible_moves[i]);
        if (i < ROOK_MOVES - 1)
        {
            printf(", ");
        }
    }
}

int main()
{
    char current_pos[POS_SIZE];
    printf("Enter a two digit position (ex. a1): ");
    scanf("%s", current_pos);
    char possible_moves[ROOK_MOVES + 1][POS_SIZE];

    char possible_moves_str[100];
    find_moves_better(current_pos, possible_moves_str);
    printf("You can move to: %s", possible_moves_str);

    // find_moves(current_pos, possible_moves);
    // print_moves(possible_moves);

    return EXIT_SUCCESS;
}