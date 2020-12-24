/**
 * @file main.c
 *
 * @brief Main function
 */

#include "mcu.h"
#include "audio.h"
#include "speaker.h"

/*****************************************
 * Main Function
 *****************************************/

int main(void) {
    mcu_init();
    speaker_init();

    const uint8_t* p_audio_data = get_audio_data();
    uint16_t audio_size = get_audio_size();
    uint32_t sampling_rate = get_audio_sampling_rate();

    spekaer_set_audio(p_audio_data, audio_size, sampling_rate);

    bool changed_state = false;
    speaker_status_t speaker_status = speaker_get_status();

    for (;;) {
        speaker_status = speaker_get_status();

        if (button_is_pressed() && (speaker_status == SPEAKER_STOPPED)) {
            speaker_play();

            speaker_status = speaker_get_status();

            changed_state = true;
        }

        if (speaker_status == SPEAKER_STOPPED) {
            if (changed_state) {
                speaker_stop();

                changed_state = false;
            }
        }
    }
}
