#include "ArduinoLikeUtils.hpp"
#include "Bobyk.hpp"

void saveInt(const std::string& name, int value) {
    bobyk.nvs().writeInt(name.c_str(), value);
    bobyk.nvs().commit();
}

int loadInt(const std::string& name, int defaultVal) {
    if (bobyk.nvs().existsInt(name.c_str())) {
        return bobyk.nvs().getInt(name.c_str());
    }
    return defaultVal;
}
