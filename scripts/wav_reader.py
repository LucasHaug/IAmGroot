#!/usr/bin/env python3

from scipy.io import wavfile
import matplotlib.pyplot as plt


def chunks(data_list, n):
    """
    Yield successive n-sized chunks from data_list.
    """

    for i in range(0, len(data_list), n):
        yield data_list[i:i + n]



if __name__ == "__main__":
    sampling_rate, data = wavfile.read('./audio/i-am-groot-8-bit-32k.wav')

    print(f"Audio sampling rate: {sampling_rate}")

    num_of_columns = 24

    chuncked_data = list(chunks(data, num_of_columns))

    with open('audio_data.c', 'w') as file:
        file.write(f"#include <stdint.h>\n\n")

        num_define_string = "NUM_ELEMENTS"

        file.write(f"#define {num_define_string} {len(data)}U\n\n")

        file.write(f"#define SAMPLING_RATE_HZ {sampling_rate}U\n\n")

        file.write(f"uint8_t audio_data[{num_define_string}] = {{\n")

        for item in chuncked_data[:-1]:
            formtaed_item = ', '.join(f"{num:3}" for num in item)
            file.write(f"{formtaed_item},\n")
        else:
            formtaed_item = ', '.join(map(str, chuncked_data[-1]))
            file.write(f"{formtaed_item}\n")

        file.write(f"}};\n\n")

    plt.grid(True)
    plt.plot(data)
    plt.show()
