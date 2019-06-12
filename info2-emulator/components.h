#ifndef COMPONENTS_H
#include <sys/types.h>

#define COMPONENTS_H

#define BUTTON_0 0
#define BUTTON_1 1
#define BUTTON_2 2
#define BUTTON_3 3
#define BUTTON_4 4

#define LED_BLUE 5
#define LED_GREEN 6
#define LED_RED 7

#define IN_0 8
#define IN_1 9
#define IN_2 10

#define RELAY_0 11
#define RELAY_1 12
#define RELAY_2 13
#define RELAY_3 14

#define THERMOMETER 15
#define POTENTIOMETER 17
#define ADC_EXTERN 19

typedef union {
  u_int16_t value;
  u_int8_t  bytes[2];
} AD_TYPE;

typedef union {
    u_int8_t led;
    struct {
        u_int8_t red:1;
        u_int8_t green:1;
        u_int8_t blue:1;
        u_int8_t empty:5;
    }bits;
}led_t;

// Para usar con this->data
#define BUTTON(i) this->data[i]
#define LED(i) this->data[5 + i]
#define IN(i) this->data[8 + i]
#define RELAY(i) this->data[11 + i]

#define COMPONENT_COUNT 21

#define MEMORY_SIZE sizeof(u_int8_t) * COMPONENT_COUNT
#endif // COMPONENTS_H
