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
    float fill = (cfg->filling / 100.0f) * (Fs / cfg->frequency); //wypelnienie na podstawie czestotliwosci sygnalu
    float high_samples = (cfg->n % (uint32_t)(Fs / cfg->frequency));
    cfg->n++;
    y = (high_samples >= fill) ? 0 : cfg->amplitude;
    return (uint32_t)y;
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