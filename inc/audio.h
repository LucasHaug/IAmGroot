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
 * Public Function Prototypes
 *****************************************/

/**
 * @brief Get audio data
 *
 * @return Pointer to audio buffer
 */
const uint8_t* get_audio_data();

/**
 * @brief Get the audio size
 *
 * @return Audio size
 */
uint16_t get_audio_size();

/**
 * @brief Get the audio sampling rate
 *
 * @return Samppling rate in Hz
 */
uint32_t get_audio_sampling_rate();

#endif // __AUDIO_H__
