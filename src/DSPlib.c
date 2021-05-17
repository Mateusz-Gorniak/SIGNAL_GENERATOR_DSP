#include "DSPlib.h"

//Functions definitions

int32_t OSC_GetValueSin(OSC_Cfg_t *cfg)
{
    float y;
    y = cfg->amplitude * pdsp_sinf(PDSP_2PI_DIV_FS * cfg->frequency * cfg->n);
    cfg->n++;
    return (int32_t)y;
}
int32_t OSC_GetValueCos(OSC_Cfg_t *cfg)
{
    float y;
    y = cfg->amplitude * pdsp_cosf(PDSP_2PI_DIV_FS * cfg->frequency * cfg->n);
    cfg->n++;
    return (int32_t)y;
}
uint32_t OSC_GetValueSquare(OSC_Cfg_t *cfg)
{
    float y;
    float fill = (cfg->filling / 100) * (Fs / cfg->frequency); //wypelnienie na podstawie czestotliwosci sygnalu
    //np 0,5*(8000/400)=10 probek wowczas przypada na stan wysoki
    float pulse_width = (cfg->n % (uint32_t)(Fs / cfg->frequency));
    cfg->n++;
    y = (pulse_width >= fill) ? 0 : cfg->amplitude;
    return (uint32_t)y;
}
uint32_t OSC_GetValueTriangle(OSC_Cfg_t *cfg)
{
}
int32_t OSC_GetValueRandom(OSC_Cfg_t *cfg)
{
    //srand(time(NULL));
    //zmienne pomocnicze +-amplituda
    float y;
    uint8_t s = 5;
    int32_t max = (uint32_t)cfg->amplitude;
    int32_t min = -(uint32_t)cfg->amplitude;

    y = (rand() % (int)(max - min + 1)) + (min);

    return (int32_t)y;
}
int32_t OSC_GetValueGaussNormal(OSC_Cfg_t *cfg)
{
    //BOX-MULLER implementation
    float y, mi = 0;
    double u1, u2, normal;
    float Sigma = (cfg->amplitude) / 3;

    u1 = 1.0 - (double)rand() / RAND_MAX; //unikniecie log(0)=Inf
    u2 = 1.0 - (double)rand() / RAND_MAX; //unikniecie log(0)=Inf

    normal = cos(2 * M_PI * u2) * sqrt(-2. * log(u1));
    y = normal * Sigma + mi;
    return (int32_t)y;
}

void OSC_Init(OSC_Cfg_t *cfg, float A, float f, float fill)
{
    cfg->amplitude = A;
    cfg->frequency = f;
    cfg->filling = fill;
    cfg->n = 0;
}
void OSC_SetFrequency(OSC_Cfg_t *cfg, float f)
{
    cfg->frequency = f;
}
void OSC_SetAmplitude(OSC_Cfg_t *cfg, float A)
{
    cfg->amplitude = A;
}
void OSC_SetFilling(OSC_Cfg_t *cfg, float fill)
{
    cfg->filling = fill;
}