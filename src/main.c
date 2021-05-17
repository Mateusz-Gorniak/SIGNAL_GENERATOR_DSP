#include "stdio.h"
#include "DSPlib.h"

OSC_Cfg_t Gen1;
OSC_Cfg_t Gen2;

int main(int argc, char const *argv[])
{

    srand(time(NULL));
    OSC_Init(&Gen1, 1650, 400, 50);
    // OSC_Init(&Gen2, 100, 100, 50);
    printf("\n---------------------------------------\n");
    for (uint32_t i = 0; i < 100; i++)
    {
        printf("%d, ", OSC_GetValueSin(&Gen1));
    }
    printf("\n---------------------------------------\n");
    for (uint32_t i = 0; i < 100; i++)
    {
        printf("%d, ", OSC_GetValueCos(&Gen1));
    }
    printf("\n---------------------------------------\n");
    for (uint32_t i = 0; i < 100; i++)
    {
        printf("%d, ", OSC_GetValueSquare(&Gen1));
    }
    printf("\n---------------------------------------\n");
    for (uint32_t i = 0; i < 100; i++)
    {
        printf("%d, ", OSC_GetValueTriangle(&Gen1));
    }
    printf("\n---------------------------------------\n");
    for (uint32_t i = 0; i < 100; i++)
    {
        printf("%d, ", OSC_GetValueRandom(&Gen1));
    }
    printf("\n---------------------------------------\n");
    for (uint32_t i = 0; i < 100; i++)
    {
        printf("%d, ", OSC_GetValueGaussNormal(&Gen1));
    }
    return 0;
}