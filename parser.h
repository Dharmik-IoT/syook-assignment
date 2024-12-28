#ifndef PARSER_H
#define PARSER_H

#include <stdint.h>

typedef struct {
    uint8_t data_length;
    uint8_t flag_data_type;
    uint8_t flag_data;
    uint8_t service_data_length;
    uint8_t service_uuid;
    uint16_t uuid_data;
    uint8_t service_data_length_2;
    uint8_t service_data_type;
    uint16_t uuid_data_2;
    uint8_t frame_type;
    uint8_t version_number;
    uint8_t soc;
    float x_axis;
    float y_axis;
    float z_axis;
    char mac_address[13];
} BLEData;

void parse_ble_data(const char *data, BLEData *parsed_data);
void print_parsed_data(const BLEData *data);
int is_tag_moving(const BLEData *parsed_data);

#endif // PARSER_H