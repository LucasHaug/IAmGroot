/**
 * @file speaker.h
 *
 * @brief Controls the speaker
 *
 * @note The sound intensity is max 255 (8-bit)
 */

#include <stdbool.h>

#include "speaker.h"

#include "dac.h"
#include "dma.h"
#include "tim.h"

/*****************************************
 * Private Constants
 *****************************************/

#define SPEAKER_TIM_HANDLER htim6

#define SPEAKER_DAC_HANDLER hdac1
#define SPEAKER_DAC_CHANNEL DAC_CHANNEL_1

/*****************************************
 * Private Variables
 *****************************************/

static DAC_HandleTypeDef* mp_hdac = &SPEAKER_DAC_HANDLER;

static const uint8_t* mp_audio_data;
static uint16_t m_audio_data_size;

static bool is_playing = false;

/*****************************************
 * Public Function Body Definitions
 *****************************************/

void speaker_init() {
    MX_DMA_Init();

    MX_DAC1_Init();

    MX_TIM6_Init();
}

void spekaer_set_audio(const uint8_t* p_audio,  uint16_t audio_size, float sampling_rate_hz) {
    uint32_t hclk_frequency = HAL_RCC_GetHCLKFreq();

    uint16_t prescaler = 0;
    __HAL_TIM_SET_PRESCALER(&SPEAKER_TIM_HANDLER, prescaler);

    uint16_t counter = (hclk_frequency / (prescaler + 1)) / sampling_rate_hz;
    __HAL_TIM_SET_AUTORELOAD(&SPEAKER_TIM_HANDLER, counter);

    __HAL_TIM_SET_COUNTER(&SPEAKER_TIM_HANDLER, 0);

    mp_audio_data = p_audio;
    m_audio_data_size = audio_size;

    is_playing = false;
}

void speaker_play() {
    is_playing = true;

    HAL_DAC_Start_DMA(mp_hdac, SPEAKER_DAC_CHANNEL, (uint32_t*) mp_audio_data, m_audio_data_size, DAC_ALIGN_8B_R);

    HAL_TIM_Base_Start(&SPEAKER_TIM_HANDLER);
}

void speaker_stop() {
    HAL_TIM_Base_Stop(&SPEAKER_TIM_HANDLER);

    HAL_DAC_Stop_DMA(mp_hdac, SPEAKER_DAC_CHANNEL);
}

speaker_status_t speaker_get_status() {
    speaker_status_t current_status = is_playing ? SPEAKER_PLAYING : SPEAKER_STOPPED;

    return current_status;
}

/**
  * @brief  Conversion complete callback in non-blocking mode for Channel1
  * @param  hdac pointer to a DAC_HandleTypeDef structure that contains
  *         the configuration information for the specified DAC.
  * @retval None
  */
void HAL_DAC_ConvCpltCallbackCh1(DAC_HandleTypeDef *hdac) {
    if (hdac->Instance == mp_hdac->Instance) {
        is_playing = false;
    }
}
