#include <iostream>

#include "observer.hpp"

using std::vector;
using std::cout;
using std::cin;


int main() {
    WeatherStation weatherStation;

    // Create displays
    Display display1("dispaly1");
    Display display2("display2");
    Display display3("display3");
    Display display4("display4");
    

    // Register displays as observers
    weatherStation.registerObserver(&display1);
    weatherStation.registerObserver(&display2);    
    weatherStation.registerObserver(&display3);
    weatherStation.registerObserver(&display4);

    // Simulate weather data updates
    weatherStation.setMeasurements(25.5, 60, 1013.2);
    weatherStation.setMeasurements(24.8, 58, 1014.5);
    weatherStation.removeObserver(&display1);
    double temp, hum, press;
    while(1){
        cout << "Enter new status of Temperature, Humidity and Pressure: ";
        cin >> temp >> hum >> press; 
        weatherStation.setMeasurements(temp, hum, press);
    }

    return 0;
}
