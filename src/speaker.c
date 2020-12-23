/**
 * @file speaker.h
 *
 * @brief Controls the speaker
 *
 * @note The sound intensity is max 255 (8-bit)
 */

#include "speaker.h"

#include "dac.h"

/*****************************************
 * Public Function Body Definitions
 *****************************************/

void speaker_init() {
    MX_DAC1_Init();
    HAL_DAC_Start(&hdac1, DAC_CHANNEL_1);
}

void speaker_play(uint8_t sound_intensity) {
    HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_8B_R, (uint32_t) sound_intensity);
}
