/**
 * @file control_timer.c
 *
 * @brief Sampling control
 */

#include "control_timer.h"

#include "tim.h"

/*****************************************
 * Private Constants
 *****************************************/

#define TIM_FREQUENCY_HZ 64000000U /**< This is the internal clock divided by the timer prescaler */

#define TIM_HANDLER htim6

/*****************************************
 * Private Variables
 *****************************************/

/**
 * @brief Pointer to timer handler.
 */
static TIM_HandleTypeDef* mp_htim = &TIM_HANDLER;

/*****************************************
 * Public Function Prototypes
 *****************************************/

void control_timer_init(float control_timer_freq_hz) {
    MX_TIM6_Init();

    uint32_t hclk_frequency = HAL_RCC_GetHCLKFreq();

    uint16_t prescaler = 0;
    __HAL_TIM_SET_PRESCALER(mp_htim, prescaler);

    uint16_t counter = (hclk_frequency / (prescaler + 1)) / control_timer_freq_hz;
    __HAL_TIM_SET_AUTORELOAD(mp_htim, counter);

    __HAL_TIM_SET_COUNTER(mp_htim, 0);

    HAL_TIM_Base_Start_IT(mp_htim);
}

__weak void control_timer_callback() {
}

/**
 * @brief  Timer period elapsed callback.
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim) {
    if (htim->Instance == mp_htim->Instance) {
        control_timer_callback();
    }
}
