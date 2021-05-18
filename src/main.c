#include "stdio.h"
#include "DSPlib.h"

OSC_Cfg_t Gen1;

int main(int argc, char const *argv[])
{

    srand(time(NULL));
    OSC_Init(&Gen1, 900, 300, 50);

    //file to ete
    FILE *f = fopen("graphs.m", "w");
    fprintf(f, "%%SINWAVE-------------------------------------\n");
    fprintf(f, "%s ", "s=[");
    printf("\nSINWAVE---------------------------------------\n");
    for (uint32_t i = 0; i < 100; i++)
    {
        printf("%d, ", OSC_GetValueSin(&Gen1));
        fprintf(f, "%d%s ", OSC_GetValueSin(&Gen1), ",");
    }
    fprintf(f, "%s ", "]");
    fprintf(f, "\n%s", "figure");
    fprintf(f, "\n%s", "stem(s);\n\n");

    fprintf(f, "%%TRIANGLE-------------------------------------\n");
    fprintf(f, "%s ", "t=[");
    printf("\nTRIANGLE---------------------------------------\n");
    for (uint32_t i = 0; i < 100; i++)
    {
        printf("%d, ", OSC_GetValueTriangle(&Gen1));
        fprintf(f, "%d%s ", OSC_GetValueTriangle(&Gen1), ",");
    }
    fprintf(f, "%s ", "]");
    fprintf(f, "\n%s", "figure");
    fprintf(f, "\n%s", "stem(t);\n\n");

    fprintf(f, "%%SQUARE-------------------------------------\n");
    fprintf(f, "%s ", "sq=[");
    printf("\nSQUARE---------------------------------------\n");
    for (uint32_t i = 0; i < 100; i++)
    {
        printf("%d, ", OSC_GetValueSquare(&Gen1));
        fprintf(f, "%d%s ", OSC_GetValueSquare(&Gen1), ",");
    }
    fprintf(f, "%s ", "]");
    fprintf(f, "\n%s", "figure");
    fprintf(f, "\n%s", "stem(sq);\n\n");

    fprintf(f, "%%RANDOM-------------------------------------\n");
    fprintf(f, "%s ", "r=[");
    printf("\nRANDOM---------------------------------------\n");
    for (uint32_t i = 0; i < 100; i++)
    {
        printf("%d, ", OSC_GetValueRandom(&Gen1));
        fprintf(f, "%d%s ", OSC_GetValueRandom(&Gen1), ",");
    }
    fprintf(f, "%s ", "]");
    fprintf(f, "\n%s", "figure");
    fprintf(f, "\n%s", "stem(r);\n\n");

    fprintf(f, "%%GAUSS-------------------------------------\n");
    fprintf(f, "%s ", "g=[");
    printf("\nGAUSS---------------------------------------\n");
    for (uint32_t i = 0; i < 100; i++)
    {
        printf("%d, ", OSC_GetValueGaussNormal(&Gen1));
        fprintf(f, "%d%s ", OSC_GetValueGaussNormal(&Gen1), ",");
    }
    fprintf(f, "%s ", "]");
    fprintf(f, "\n%s", "figure");
    fprintf(f, "\n%s", "stem(g);\n\n");

    fclose(f);
    return 0;
}