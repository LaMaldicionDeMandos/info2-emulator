#ifndef COMPONENTS_H
#define COMPONENTS_H

#define BUTTON_0 0
#define BUTTON_1 1
#define BUTTON_2 2
#define BUTTON_3 3
#define BUTTON_4 4
#define LED_BLUE 5
#define LED_GREEN 6
#define LED_RED 7

// Para usar con this->data
#define BUTTON(i) this->data[i]
#define LED(i) this->data[5 + i]

#define COMPONENT_COUNT 8

#define MEMORY_SIZE sizeof(char) * COMPONENT_COUNT
#endif // COMPONENTS_H
