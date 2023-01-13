#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_DIMENSIONS 3

typedef struct Guy // deines Guy as a struct type
{
    char* name;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS];
    struct Guy *friend;
} Guy; // also defines Guy as a type derived from the struct Guy

typedef struct Motorcycle
{
    char *model;
    double speed;
    Guy owner;
} Motorcycle;

double calc_distance(int dimensions, double a[dimensions], double b[dimensions])
{
    double sqrd_distance = 0.0;

    for (int i = 0; i < dimensions; i++)
    {
        sqrd_distance += pow(a[i] - b[i], 2);
    }
    return sqrt(sqrd_distance);
}

int main()
{

    // implicit initialization
    Guy elon = {
        "Elon Musk",
        true,
        3,
        {1, 2, 3}
    };

    // Explicit declaration
    Guy bill = {
        .name = "Bill Gates",
        .active = true,
        .dimensions = 3,
        .pos = {3, 2, 1}
    };

    Motorcycle moto = {
        .model = "Honda",
        .speed = 300,
        .owner = {
            .name = "Andrea",
            .dimensions = 3,
            .active = true,
            .pos = {0, 0, 0}
        },
    };

    if (!elon.active || !bill.active)
    {
        printf("%s isn't active!\n", !elon.active ? elon.name : bill.name);
        return EXIT_FAILURE;
    }

    if (elon.dimensions != bill.dimensions)
    {
        printf("%s and %s are in different dimensions!\n", elon.name, bill.name);
        return EXIT_FAILURE;
    }

    printf(
        "The distance between %s and %s is: %.1f\n",
        elon.name,
        bill.name,
        calc_distance(elon.dimensions, elon.pos, bill.pos)
    );

    printf(
        "And %s's %s is running at %.1f km/h\n",
        moto.owner.name,
        moto.model,
        moto.speed
    );

    //completely overwrites moto with new declaration
    moto = (Motorcycle) {.model = "Ducati", .speed = 400};

    printf(
        "And %s's %s is running at %.1f km/h\n",
        moto.owner.name,
        moto.model,
        moto.speed
    );

    Guy anotherguy = bill;
    printf("%x0 | %x0", &bill, &anotherguy);

    return EXIT_SUCCESS;
}