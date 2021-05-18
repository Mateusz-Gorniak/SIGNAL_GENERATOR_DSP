#ifndef DSPLIB_H
#define DSPLIB_H

//Includes
#include "stdint.h"
#include "math.h"
#include "stdio.h"
#include "time.h"
#include "stdlib.h"

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

float y;

typedef struct
{
    float amplitude;
    float frequency;
    float filling;
    uint32_t n;
} OSC_Cfg_t;

//Function defines
int32_t OSC_GetValueSin(OSC_Cfg_t *cfg);
int32_t OSC_GetValueCos(OSC_Cfg_t *cfg);
uint32_t OSC_GetValueSquare(OSC_Cfg_t *cfg);
uint32_t OSC_GetValueTriangle(OSC_Cfg_t *cfg);
int32_t OSC_GetValueRandom(OSC_Cfg_t *cfg);
int32_t OSC_GetValueGaussNormal(OSC_Cfg_t *cfg);
void OSC_Init(OSC_Cfg_t *cfg, float A, float f, float fill);
void OSC_SetFrequency(OSC_Cfg_t *cfg, float f);
void OSC_SetAmplitude(OSC_Cfg_t *cfg, float A);
void OSC_SetFilling(OSC_Cfg_t *cfg, float fill);

#endif