/**
 * @file mcu.c
 *
 * @brief MCU related
 */

#include <stdint.h>

#include "mcu.h"

#include "gpio.h"
#include "main.h"

/*****************************************
 * Public Function Body Definitions
 *****************************************/

void mcu_init(void) {
    HAL_Init();

    SystemClock_Config();

    MX_GPIO_Init();
}

void mcu_sleep(uint32_t ms) {
    HAL_Delay(ms);
}

void led_toggle(void) {
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}

bool button_is_pressed(void) {
    if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) {
        while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) {
            mcu_sleep(1);
        }

        return true;
    }

    return false;
}
