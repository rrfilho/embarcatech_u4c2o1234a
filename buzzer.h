#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include <stdio.h>

static const uint BUZZER_PIN = 21;
static const uint DURATION = 100;

void init_buzzer() {
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
    gpio_put(BUZZER_PIN, 0);
}

static uint to_frequency(char key) {
    return (key - '#' + 10)*200;
}

static uint set_as_pwm() {
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
    return pwm_gpio_to_slice_num(BUZZER_PIN);
}

static void buzzee(uint slice_id, uint frequency) {
    pwm_set_wrap(slice_id, 125000000/frequency);
    pwm_set_chan_level(slice_id, PWM_CHAN_B, (125000000/frequency)/2);
    pwm_set_enabled(slice_id, true);
    sleep_ms(DURATION);
    pwm_set_enabled(slice_id, false);
    sleep_ms(DURATION);
}

static void set_as_sio() {
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_SIO);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
    gpio_put(BUZZER_PIN, 0);
}

void buzzee_for_key(char key) {
    uint frequency = to_frequency(key);
    uint slice_id = set_as_pwm();
    buzzee(slice_id, frequency);
    set_as_sio();
}