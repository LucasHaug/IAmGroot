/**
 * @file audio.h
 *
 * @brief Unsigned 8-bit WAV audio file related
 *
 * @note Audacity was used to convert from mp3 to wav
 * @note To generate the audio_data array the scripts/wav_reader.py was used
 */

#ifndef __AUDIO_H__
#define __AUDIO_H__

#include <stdint.h>

/*****************************************
 * Public Types
 *****************************************/

/**
 * @brief Audio status.
 */
typedef enum audio_status {
    AUDIO_PLAYING,
    AUDIO_END,
} audio_status_t;

/*****************************************
 * Public Function Prototypes
 *****************************************/

/**
 * @brief Get the audio intensity
 *
 * @param data_index Index to get the audio data
 * @param p_store_data Pointer where to store the data
 * @return audio_status_t
 */
audio_status_t get_audio_intensity(uint16_t data_index, uint8_t* p_store_data);

/**
 * @brief Get the audio sampling rate
 *
 * @return Samppling rate in Hz
 */
uint16_t get_audio_sampling_rate();

#endif // __AUDIO_H__
