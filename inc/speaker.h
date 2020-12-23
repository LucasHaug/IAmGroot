/**
 * @file speaker.h
 *
 * @brief Controls the speaker
 *
 * @note The sound intensity is max 255 (8-bit)
 */

#ifndef __SPEAKER_H__
#define __SPEAKER_H__

#include <stdint.h>

/*****************************************
 * Public Function Prototypes
 *****************************************/

/**
 * @brief Initializes the speaker
 */
void speaker_init();

/**
 * @brief Plays a intensity value in the speaker
 *
 * @param sound_intensity Intensity to be played
 */
void speaker_play(uint8_t sound_intensity);

#endif // __SPEAKER_H__
