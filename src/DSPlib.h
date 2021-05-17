#ifndef DSPLIB_H
#define DSPLIB_H

//Includes
#include "stdint.h"
#include "math.h"
#include "stdio.h"

//Defines
#define pdsp_sinf(fi) sinf(fi) //sinwave function
#define pdsp_cosf(fi) cosf(fi) //coswave function
#define PDSP_2PI_DIV_FS ((M_PI * 2.0f) / Fs)

//Samle rates defines
// #define Fs 96000.0f
// #define Fs 48000.0f
// #define Fs 32000.0f
// #define Fs 16000.0f
#define Fs 8000.0f

typedef struct
{
    uint8_t signal_type;
    float filling;
    float amplitude;
    float frequency;
    uint32_t n;
} OSC_Cfg_t;

//Function defines

int8_t OSC_GetValueSin(OSC_Cfg_t *cfg);
int8_t OSC_GetValueCos(OSC_Cfg_t *cfg);
void OSC_Init(OSC_Cfg_t *cfg, float A, float f);
void OSC_SetFrequency(OSC_Cfg_t *cfg, float f);
void OSC_SetAmplitude(OSC_Cfg_t *cfg, float A);

#endif