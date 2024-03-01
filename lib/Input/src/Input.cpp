#include "Input.h"

Input::Input() : dht1()
{
}

Input::~Input()
{
}

void Input::initSensor()
{
    dht1.setup(DHTPIN1, DHTesp::DHT22);
    // this->dht1.begin();
    // this->dht2.begin();
}

void Input::updateSensor()
{

    this->dht1Temp = this->dht1.getTemperature();
    this->dht1Hum = this->dht1.getHumidity();
    // this->dht2Temp = this->dht2.readTemperature();
    // this->dht2Hum = this->dht2.readHumidity();

    DEBUG_PRINTLN("Suhu: " + (String)this->dht1Temp + " Kelembaban: " + (String)this->dht1Hum);

    if (isnan(this->dht1Temp))
    {
        this->dht1Temp = 0;
    }

    if (isnan(this->dht1Hum))
    {
        this->dht1Hum = 0;
    }

    if (isnan(this->dht2Temp))
    {
        this->dht2Temp = 0;
    }

    if (isnan(this->dht2Hum))
    {
        this->dht2Hum = 0;
    }
}

float Input::getDHT1Temp()
{
    return this->dht1Temp;
}

float Input::getDHT1Hum()
{
    return this->dht1Hum;
}

float Input::getDHT2Temp()
{
    return this->dht2Temp;
}

float Input::getDHT2Hum()
{
    return this->dht2Hum;
}
