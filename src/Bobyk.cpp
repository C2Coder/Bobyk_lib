#include "Bobyk.hpp"
#include "Platform.hpp"

#include <bitset>
#include <eventpp/callbacklist.h>
#include <eventpp/utilities/conditionalfunctor.h>
#include <freertos/FreeRTOS.h>
#include <freertos/queue.h>
#include <freertos/task.h>
#include <functional>
#include <thread>

Bobyk::Bobyk() {
}

Bobyk& IRAM_ATTR Bobyk::singleton() {
    static Bobyk DRAM_ATTR instance;
    return instance;
}

void Bobyk::init() {
    gpio_config_t configData = {
        .pin_bit_mask = 1ULL << Platform::Pins::LedPower,
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&configData);
    m_buttons.init();
}

void Bobyk::turnOnLeds() {
    gpio_set_level(Platform::Pins::LedPower, Platform::LedPowerOnLevel);
}

void Bobyk::turnOffLeds() {
    gpio_set_level(Platform::Pins::LedPower, !Platform::LedPowerOnLevel);
}

StatusBar& Bobyk::statusBar() {
    return m_statusBar;
}

Display& Bobyk::display() {
    return m_display;
}

Buttons& Bobyk::buttons() {
    return m_buttons;
}

Buzzer& Bobyk::buzzer() {
    return m_buzzer;
}

Nvs& Bobyk::nvs() {
    static Nvs instance("BobykLib");
    return instance;
}

Bobyk& bobyk = Bobyk::singleton();
Display& display = bobyk.display();
StatusBar& statusBar = bobyk.statusBar();
Buttons& buttons = bobyk.buttons();
Buzzer& buzzer = bobyk.buzzer();

extern void bobykMain();

extern "C" {
[[gnu::weak]] void app_main() {
    bobyk.init();

    // The SmartLeds Interrupt handler must be registered on different core than
    // the WiFi Interrupts are, otherwise SmartLeds can't feed RMT fast enough.
    // We can't feasibly change SmartLeds's core because it is initialized
    // via global constructors, but WiFi core is set to 1 via sdkconfig.* files.
    // CONFIG_ESP32_WIFI_TASK_PINNED_TO_CORE_1
    bobyk.turnOnLeds();

    bobykMain();

    while (true)
        vTaskDelay(1000 / portTICK_PERIOD_MS);
}
}
