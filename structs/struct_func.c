#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DIMENSIONS 3

typedef struct Guy
{
    char *name;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS];
    struct Guy *friend;
} Guy;

Guy create_bill()
{
    return (Guy) {
        .name = "Bill Gates",
        .pos = {1, 2, 3},
        .dimensions = 3,
        .active = true,
    };
}

void set_active_false(Guy guy)
{
    guy.active = false;
}

void set_active_false_ptr(Guy *guy)
{
    guy->active = false;
}

Guy *alloc_elon()
{
    Guy *elon = malloc(sizeof(Guy));

    if (!elon)
    {
        return NULL;
    }
    elon->name = "Elon Musk";
    elon->active = true;
    elon->dimensions = 3;
    double pos[] = {3, 2, 1};
    memcpy(elon->pos, pos, sizeof(pos));
    elon->friend = NULL;

    return elon;
}

int main()
{
    Guy bill = create_bill();
    bill.friend = alloc_elon();

    printf("%s\n", bill.friend->name);

    set_active_false(bill);
    printf("%d\n", bill.active);

    set_active_false_ptr(&bill);
    printf("%d\n", bill.active);

}