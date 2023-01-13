#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DIMENSIONS 3

char* return_string()
{
    char *res_val = (char *) malloc(sizeof(char) * 10);
    if (!res_val)
    {
        return NULL;
    }
    // use strncpy here, setting dynamically allocated pointer to a literal redefines the pointer entirely, dynamic mem still allocated 
    // somewhere else
    strncpy(res_val, "test", 10 - 1);
    return res_val;
}

typedef struct GuyP
{
    char *name;
    char *job;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS];
} GuyP;

typedef struct GuyA
{
    char *name;
    char job[64];
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS];
} GuyA;

int main()
{
    printf("Sizeof(GuyP): %lld\n", sizeof(GuyP));
    printf("Sizeof(GuyA): %lld\n", sizeof(GuyA));

    GuyP billP = {
        .name = "Bill Gates",
        .job = "I make software...",
        .active = true,
    };

    billP.job = "I founded Microsoft!";

    GuyA billA = {
        .name = "Bill Gates",
        .job = "I make software...",
        .active = true,
    };

    billP.job = return_string();

    // can't reassign char array, must copy the string
    // billA.job = "new thing";

    // strncpy(destination, incoming value, size to stop copying, leave space for the null character)
    strncpy(billA.job, "I founded Michaelsoft!", sizeof(billA) - 1);

    printf("%s\n", billP.job);
    free(billP.job);
    billP.job = NULL;
    printf("%s\n", billP.job ? "defined" : "nothing");
    // billP.job = NULL;

    // legal because job is a pointer, can be assigned to a new literal

    return EXIT_SUCCESS;
}