/**
 * @file control_timer.h
 *
 * @brief Control timer
 */

#ifndef __CONTROL_TIMER_H__
#define __CONTROL_TIMER_H__

#include <stdint.h>

/*****************************************
 * Public Function Prototypes
 *****************************************/

/**
 * @brief Initializes the control timer
 *
 * @param control_timer_freq_hz Timer frequency
 */
void control_timer_init(float control_timer_freq_hz);

/**
 * @brief Control timer callback function
 *
 * @note Must be implemented by the user
 */
void control_timer_callback();

#endif // __CONTROL_TIMER_H__
