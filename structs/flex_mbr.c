#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_DIMENSIONS 3

typedef struct Guy
{
    char *name;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS];
} Guy;

typedef struct GuyFlex
{
    char *name;
    bool active;
    int dimensions;
    float pos[]; // flexible array, has to be last member. Not actually part of physical memory (initially)
} GuyFlex;

typedef struct BleHeader
{
    uint16_t pdu_type : 4;
    uint16_t rfu_1 : 2;
    uint16_t tx_add : 1;
    uint16_t rx_add : 1;
    uint16_t length : 6;
    uint16_t rfu_2 : 2;
} BleHeader;

typedef struct BlePacket
{
    BleHeader header;
    uint8_t payload[];
} BlePacket;

GuyFlex *alloc_guy(int dimensions)
{
    // (GuyFlex *) 0 - cast null value to a specific pointer to get sizeof its members
    size_t size = sizeof(((GuyFlex*) 0)->pos[0]); // type safety for pos, changes if type of array changes
    GuyFlex *guy = malloc(sizeof(GuyFlex) * dimensions * size);

    if (!guy)
    {
        return NULL;
    }

    guy->dimensions = dimensions;
    return guy;
}

void read_ble_packet(BlePacket *packet)
{
    int len = packet->header.length;

    for (int i = 0; i < len; i++)
    {
        printf("%X", packet->payload[i]);
    }
    printf("\n");
}

int main()
{
    printf("sizeof Guy: %lld\n", sizeof(Guy));
    printf("sizeof GuyFlex: %lld\n", sizeof(GuyFlex));

    const uint8_t rx_buffer[] = {0x41, 0x06, 0xCA, 0xFE, 0xCA, 0xFE, 0xCA, 0XFE};
    read_ble_packet((BlePacket *) rx_buffer);

    return EXIT_SUCCESS;
}