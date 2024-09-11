#pragma once

#include <array>
#include <driver/gpio.h>

enum StepperID {
    Step_1 = 0,
    Dir_1,
    Step_2,
    Dir_2,
    Step_3,
    Dir_3,
    Step_4,
    Dir_4,
    MaxID,
};

namespace Platform {

namespace Pins {

namespace Stepper1 {
static constexpr gpio_num_t Step = GPIO_NUM_38;
static constexpr gpio_num_t Dir = GPIO_NUM_39;
} // namespace Stepper1

namespace Stepper2 {
static constexpr gpio_num_t Step = GPIO_NUM_47;
static constexpr gpio_num_t Dir = GPIO_NUM_48;
} // namespace Stepper2

namespace Stepper3 {
static constexpr gpio_num_t Step = GPIO_NUM_21;
static constexpr gpio_num_t Dir = GPIO_NUM_14;
} // namespace Stepper3

namespace Stepper4 {
static constexpr gpio_num_t Step = GPIO_NUM_41;
static constexpr gpio_num_t Dir = GPIO_NUM_40;
} // namespace Stepper4


namespace AUX1 {
static constexpr gpio_num_t A = GPIO_NUM_10;
static constexpr gpio_num_t B = GPIO_NUM_9;    
static constexpr gpio_num_t C = GPIO_NUM_8;    
} // namespace AUX1


namespace Servo {
    static constexpr gpio_num_t S1 = GPIO_NUM_11;
    static constexpr gpio_num_t S2 = GPIO_NUM_12;
    static constexpr gpio_num_t S3 = GPIO_NUM_13;
} // namespace Servo


namespace SDcard {
static constexpr gpio_num_t CS = GPIO_NUM_5;
static constexpr gpio_num_t SCK = GPIO_NUM_6;
static constexpr gpio_num_t MOSI = GPIO_NUM_7;
static constexpr gpio_num_t MISO = GPIO_NUM_15;
} // namespace SDcard


static constexpr std::array<gpio_num_t, MaxID> Steppers = {
    Stepper1::Step,
    Stepper1::Dir,
    Stepper2::Step,
    Stepper2::Dir,
    Stepper3::Step,
    Stepper3::Dir,
    Stepper4::Step,
    Stepper4::Dir,
};

} // namespace Pins

} // namespace Platform
