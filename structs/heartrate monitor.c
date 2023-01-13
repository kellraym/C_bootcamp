#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ZONE_COUNT 6

typedef struct User
{
    int age;
    float max_heartrate;
} User;

typedef struct Zone
{
    int id;
    float range[2];
    char desc[100];
} Zone;

float get_max_heartrate(int age)
{
    return 208.0 - 0.7 * age;
}

void print_all_zones(float max_rate, Zone *zone_array)
{
    for (int i = 0; i < ZONE_COUNT; i++)
    {
        Zone *current_zone = zone_array + i;
        if (i == 0)
        {
            printf("%d | below %5.1f   | %s\n",
             current_zone->id,
             current_zone->range[1], 
             current_zone->desc);
             continue;
        }
        if (i == ZONE_COUNT - 1)
        {
            printf("%d | above %5.1f   | %s\n",
             current_zone->id,
             current_zone->range[0], 
             current_zone->desc);
             break;
        }

        printf("%d | %5.1f - %5.1f | %s\n",
         current_zone->id,
         current_zone->range[0],
         current_zone->range[1],
         current_zone->desc);
    }
}

int get_zone_index(float max_heartrate, float current_heartrate)
{
    float percentage = current_heartrate / max_heartrate;
    if (percentage < 0.5)
    {
        return 0;
    }
    else if (percentage < 0.6)
    {
        return 1;
    }
    else if (percentage < 0.7)
    {
        return 2;
    }
    else if (percentage < 0.8)
    {
        return 3;
    }
    else if (percentage <= 0.9)
    {
        return 4;
    }
    else
    {
        return 5;
    }

    return 0;
}

void print_current_zone(float max_heartrate, float current_heartrate, Zone *zone_array)
{
    int zone_index = get_zone_index(max_heartrate, current_heartrate);
    Zone *current_zone = zone_array + zone_index;
    printf("%d | %s\n", current_zone->id, current_zone->desc);
}

int main()
{
    User user;
    Zone all_zones[ZONE_COUNT];
    float current_heartrate = -1;

    printf("Enter your age: ");
    scanf("%d", &(user.age));
    user.max_heartrate = get_max_heartrate(user.age);
    printf("Your max heartrate is %.1f beats per minute\n", user.max_heartrate);

    all_zones[0] = (Zone) {
        .id = 1,
        .range = {0, user.max_heartrate * 0.5},
        .desc = "rest",
    };

    all_zones[1] = (Zone) {
        .id = 2,
        .range = {user.max_heartrate * 0.5, user.max_heartrate * 0.6},
        .desc = "very light, active recovery",
    };

    all_zones[2] = (Zone) {
        .id = 3,
        .range = {user.max_heartrate * 0.6, user.max_heartrate * 0.7},
        .desc = "light, cardio training, improves your general endurance",
    };

    all_zones[3] = (Zone) {
        .id = 4,
        .range = {user.max_heartrate * 0.7, user.max_heartrate * 0.8},
        .desc = "moderate, aerobic fitness, improve your efficiency",
    };

    all_zones[4] = (Zone) {
        .id = 5,
        .range = {user.max_heartrate * 0.8, user.max_heartrate * 0.9},
        .desc = "hard, raise the anaerobic threshold, improve your speed endurance",
    };

    all_zones[5] = (Zone) {
        .id = 6,
        .range = {user.max_heartrate * 0.9, 999},
        .desc = "peak performance, improve your power, only for pros!",
    };
    
    print_all_zones(user.max_heartrate, all_zones);
    while (current_heartrate)
    {
        printf("Enter your current heartrate: ");
        scanf("%f", &current_heartrate);
        if (current_heartrate)
        {
            print_current_zone(user.max_heartrate, current_heartrate, all_zones);
        }
    }

    return EXIT_SUCCESS;
}