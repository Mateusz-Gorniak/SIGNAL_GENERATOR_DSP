#include "DSPlib.h"

//Functions definitions

int8_t OSC_GetValueSin(OSC_Cfg_t *cfg)
{
    float y;
    y = cfg->amplitude * pdsp_sinf(PDSP_2PI_DIV_FS * cfg->frequency * cfg->n);
    cfg->n++;
    return (int8_t)y;
}

int8_t OSC_GetValueCos(OSC_Cfg_t *cfg)
{
    float y;
    y = cfg->amplitude * pdsp_cosf(PDSP_2PI_DIV_FS * cfg->frequency * cfg->n);
    cfg->n++;
    return (int8_t)y;
}

void OSC_Init(OSC_Cfg_t *cfg, float A, float f)
{
    cfg->amplitude = A;
    cfg->frequency = f;
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