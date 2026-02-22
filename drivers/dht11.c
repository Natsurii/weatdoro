/**
 * @file dht11.c
 * @author 
 * @brief 
 * @version 0.1
 * @date 2026-02-21
 * 
 * @copyright Copyright (c) 2026
 * 
 */
 #include "dht11.h"

/**
 * @brief initialize dht11 handle
 * 
 * @param h 
 * @param config 
 */
 void dht11_init(dht11_handle_t *h, dht11_config_t *config) {
    h->port = config->port;
    h->pin = config->pin;
    h->status = OK;
    h->current_unit = CELSIUS;

    // set initial values to zero
    dht11_setTemperature(h, 0.0);
    dht11_setRelativeHumidity(h, 0.0);
    dht11_setHeatIndex(h, 0.0);
}

/**
 * @brief perform sensor data collection routine
 * 
 * @param h 
 */
void dht11_getData(dht11_handle_t *h) {
    // todo
}

/**
 * @brief setter: temperature
 * 
 * @param h 
 * @param temp 
 */
void dht11_setTemperature(dht11_handle_t *h, dht11_raw_t temp){
    h->temp = temp;
}

/**
 * @brief  setter: relativeHumidity
 * 
 * @param h 
 * @param rh 
 */
void dht11_setRelativeHumidity(dht11_handle_t *h, float rh){
    h->rh = rh;
}

/**
 * @brief setter: heatIndex
 * 
 * @param h 
 * @param hi 
 */
void dht11_setHeatIndex(dht11_handle_t *h,  float hi){
    h->heat_index = hi;
}

/**
 * @brief getter: temperature
 * 
 * @param h 
 * @return dht11_raw_t 
 */
dht11_raw_t dht11_getTemperature(dht11_handle_t *h){
    return h->temp;
}

/**
 * @brief getter relativeHumidity
 * 
 * @param h 
 * @return dht11_raw_t 
 */
dht11_raw_t dht11_getRelativeHumidity(dht11_handle_t *h){
    return h->rh;
}

/**
 * @brief getter: heatIndex
 * 
 * @param h 
 * @return dht11_raw_t 
 */
dht11_raw_t dht11_getHeatIndex(dht11_handle_t *h){
    return h->heat_index;
}

/**
 * @brief convert Celsius to Fahrenheit
 * 
 * @param temp_in_c 
 * @return float 
 */
float helper_convertCtoF(float temp_in_c) {
    return (temp_in_c * (9.0/5.0)) + 32.0;
}

/**
 * @brief convert Celsius to Kelvin
 * 
 * @param temp_in_c 
 * @return float 
 */
float helper_convertCtoK(float temp_in_c){
    return (temp_in_c) + 273.15; 
}

/**
 * @brief 
 * 
 * @param temp_in_f 
 * @return float 
 */
float helper_convertFtoC(float temp_in_f) {
    return (temp_in_f - 32.0) * (5.0 / 9.0);
}

/**
 * @brief convert Kelvin to Celsius
 * 
 * @param temp_in_k 
 * @return float 
 */
float helper_convertKtoC(float temp_in_k){
    return temp_in_k - 273.15;
}
 

