#include "weatherinfo.h"

WeatherInfo::WeatherInfo() {}


WeatherInfo::~WeatherInfo(){}



QString WeatherInfo::getCityName() const{
    return this->cityName;
}



void WeatherInfo::setCityName(const QString &cityName){
    this->cityName = cityName;
}



quint32 WeatherInfo::getId() const{
    return this->id;
}



void WeatherInfo::setId(quint32 id){
    this->id = id;
}



QDateTime WeatherInfo::getDateTime() const{
    return this->dateTime;
}



void WeatherInfo::setDateTime(const QDateTime &dateTime){
    this->dateTime = dateTime;
}



float WeatherInfo::getTemperature() const{
    return this->temperature;
}



void WeatherInfo::setTemperature(float temperature){
    this->temperature = temperature;
}



float WeatherInfo::getHumidity() const{
    return this->humidity;
}



void WeatherInfo::setHumidity(float humidity){
    this->humidity = humidity;
}



float WeatherInfo::getPressure() const{
    return this->pressure;
}



void WeatherInfo::setPressure(float pressure){
    this->pressure = pressure;
}



QList<WeatherDetail *> WeatherInfo::getDetails() const{
    return this->details;
}



void WeatherInfo::setDetails(const QList<WeatherDetail *> details){
    this->details = details;
}
