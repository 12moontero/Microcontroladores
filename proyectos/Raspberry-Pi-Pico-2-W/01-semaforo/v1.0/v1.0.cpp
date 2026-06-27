#include "pico/stdlib.h"

const uint PIN_LED_GREEN = 11;
const uint PIN_LED_ORANGE = 12;
const uint PIN_LED_RED = 13;

int main()
{
    stdio_init_all();

    gpio_init(PIN_LED_GREEN);
    gpio_init(PIN_LED_ORANGE);
    gpio_init(PIN_LED_RED);

    gpio_set_dir(PIN_LED_GREEN, GPIO_OUT);
    gpio_set_dir(PIN_LED_ORANGE, GPIO_OUT);
    gpio_set_dir(PIN_LED_RED, GPIO_OUT);

    while (true){
        gpio_put(PIN_LED_GREEN,1);
        sleep_ms(2000);
        gpio_put(PIN_LED_GREEN,0);
        gpio_put(PIN_LED_ORANGE,1);
        sleep_ms(2000);
        gpio_put(PIN_LED_ORANGE,0);
        gpio_put(PIN_LED_RED,1);
        sleep_ms(2000);
        gpio_put(PIN_LED_RED,0);

    }
}
