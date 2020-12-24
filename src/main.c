/**
 * @file main.c
 *
 * @brief Main function
 */

#include "mcu.h"
#include "audio.h"
#include "speaker.h"
#include "control_timer.h"

/*****************************************
 * Private Variables
 *****************************************/

static uint8_t current_audio_data = 0;
static bool play_audio = false;

/*****************************************
 * Main Function
 *****************************************/

int main(void) {
    mcu_init();
    speaker_init();

    uint16_t sampling_rate = get_audio_sampling_rate();

    control_timer_init(sampling_rate);

    for (;;) {
        if (button_is_pressed()) {
            led_toggle();

            play_audio = true;
        }

        speaker_play(current_audio_data);
    }
}

/**
 * @brief Control callback function
 */
void control_timer_callback() {
    static uint16_t current_audio_data_index = 0;
    static audio_status_t audio_status = AUDIO_END;

    /* TEST */
    // static uint32_t counter = 0;
    /* TEST */

    if (play_audio) {
        /* TEST */
        audio_status = get_audio_intensity(current_audio_data_index, &current_audio_data);

        current_audio_data_index++;

        /* TEST */

        /* TEST */
        // audio_status = (counter % 82000 == 0) ? AUDIO_END : AUDIO_PLAYING;
        // counter++;

        // current_audio_data = 255;

        /* TEST */

        if (audio_status == AUDIO_END) {
            play_audio = false;
            current_audio_data_index = 0;
            current_audio_data = 0;
        }
    } else {
        current_audio_data = 0;
    }
}
