/**
 * @file dht11.h
 * @author natsurii
 * @brief 
 * @version 0.1
 * @date 2026-02-20
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef DHT11_H
#define DHT11_H
#include <stdint.h>

typedef float dht11_raw_t;

typedef enum Status {
    OK, 
    READING,
    DONE,
    CHECKSUM_ERROR
} dht11_status_e;

typedef enum TempUnit {
    CELSIUS, 
    FAHRENHEIT, 
    KELVIN
} dht11_unit_e;

typedef struct dht11_handle {
    uint32_t pin;
    uint32_t port;
    dht11_raw_t rh;
    dht11_raw_t temp;
    dht11_raw_t heat_index;
    dht11_status_e status;
} dht11_handle_t;

typedef struct dht11_config {
    uint32_t pin;
    uint32_t port;
} dht11_config_t;

void dht11_init(dht11_handle_t *h, dht11_config_t *config);
void dht11_getData(dht11_handle_t *h);
dht11_raw_t dht11_getTemperature(dht11_handle_t *h);
dht11_raw_t dht11_getRelativeHumidity(dht11_handle_t *h);
dht11_raw_t dht11_getHeatIndex(dht11_handle_t *h);
float helper_convertCtoF(float temp_in_c);
float helper_convertCtoK(float temp_in_c);
float helper_convertFtoC(float temp_in_f);
float helper_convertKtoC(float temp_in_k);
#endif /* DHT11_H */