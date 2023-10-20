#include <iostream>
#include "Sensor.h"
#include "Temperature.h"
#include "Humidity.h"
#include "Light.h"
#include "Sound.h"
#include "Scheduler.h"

int main() {
//    srand(static_cast<unsigned>(time(0)));
    Temperature temperature;
    Humidity humidity;
    Light light;
    Sound sound;
    std::vector<Sensor> sensors{temperature, humidity, light, sound};
    std::vector<Sensor*> psensors{&temperature, &humidity, &light, &sound};

    Scheduler scheduler;
    Server server = Server(psensors);

    scheduler.schedule(server);

    return 0;
}
