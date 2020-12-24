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
 * Public Types
 *****************************************/

/**
 * @brief Speaker status.
 */
typedef enum speaker_status {
    SPEAKER_PLAYING,
    SPEAKER_STOPPED,
} speaker_status_t;

/*****************************************
 * Public Function Prototypes
 *****************************************/

/**
 * @brief Initializes the speaker
 */
void speaker_init();

/**
 * @brief Sets the audio to be played
 *
 * @param p_audio Pointer to audio data
 * @param audio_size Audio size
 * @param sampling_rate_hz Audio sampling rate
 */
void spekaer_set_audio(const uint8_t* p_audio,  uint16_t audio_size, float sampling_rate_hz);

/**
 * @brief Plays the audio
 */
void speaker_play();

/**
 * @brief Stops the audio
 */
void speaker_stop();

/**
 * @brief Gets speaker status
 *
 * @return speaker_status_t
 */
speaker_status_t speaker_get_status();

#endif // __SPEAKER_H__
