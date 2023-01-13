#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DIMENSIONS 3

typedef struct Guy
{
    char *name;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS];
    struct Guy *friend;
} Guy;

int main()
{
    Guy bill = {
        .name = "Bill Gates",
        .pos = {3, 2, 1},
        .dimensions = 3,
        .active = true,
    };

    Guy *firstGuy = &bill;

    // direct access

    printf("Guy's name: %s\n", bill.name);

    // access through pointer
    printf("Guy's name: %s\n", (*firstGuy).name);

    // arrow operator
    printf("Guy's name: %s\n", firstGuy->name);
    printf(
        "Guy's position: %.1f, %.1f, %.1f\n",
        firstGuy->pos[0],
        firstGuy->pos[1],
        firstGuy->pos[2]
    );

    firstGuy->friend = malloc(sizeof(Guy));
    firstGuy->friend->name = "Elon Musk";
    firstGuy->friend->active = false;

    firstGuy->friend->friend = malloc(sizeof(Guy));
    firstGuy->friend->friend->name = "Andrea";

    printf("%s's friend's friend is %s\n", firstGuy->name, firstGuy->friend->friend->name);

    // allocating an array of guys
    int num = 10;
    Guy *manyGuys = malloc(num * sizeof(Guy));

    manyGuys[0].name = "Mario";
    manyGuys[0].friend = &bill;

    (manyGuys + 1)->name = "Tom";
    printf("manyGuys[1].name = %s\n", manyGuys[1].name);


}