#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;

// Observer interface
class Observer {
public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
};

// Subject (WeatherStation) class
class WeatherStation {
private:
    float temperature;
    float humidity;
    float pressure;
    std::vector<Observer*> observers;

public:
    void registerObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        // You can implement the removal logic if needed.
        auto it = find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update(temperature, humidity, pressure);
        }
    }

    void setMeasurements(float temp, float hum, float press) {

    if(temperature == temp && humidity == hum && pressure == press)
        return;
    temperature = temp;
    humidity = hum;
    pressure = press;
    notifyObservers();
    
    }
};

// Concrete Observer
class Display : public Observer {
    private:
    const char* name;
public:
    Display(const char* _name): name(_name){};
    void update(float temperature, float humidity, float pressure) {
        std::cout << this->name <<": Temperature = " << temperature
                  << "°C, Humidity = " << humidity
                  << "%, Pressure = " << pressure << " hPa"
                  << std::endl;
    }
};
