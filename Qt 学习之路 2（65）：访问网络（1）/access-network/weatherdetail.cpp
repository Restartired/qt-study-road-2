#include "weatherdetail.h"

WeatherDetail::WeatherDetail() {}



WeatherDetail::~WeatherDetail(){};



QString WeatherDetail::getDesc() const{
    return this->desc;
}



void WeatherDetail::setDesc(const QString &desc){
    this->desc = desc;
}



QString WeatherDetail::getIcon() const{
    return this->icon;
}



void WeatherDetail::setIcon(const QString &icon){
    this->icon = icon;
}


