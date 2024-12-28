#include "parser.h"
#include <stdio.h>
#include <math.h>

void parse_ble_data(const char *data, BLEData *parsed_data) {
    // Convert hex string to byte array
    uint8_t bytes[26];
    for (int i = 0; i < 26; i++) {
        unsigned int temp;
        sscanf(data + 2 * i, "%2x", &temp);
        bytes[i] = (uint8_t)temp;
    }

    // Parse fields based on the given structure
    parsed_data->data_length = bytes[0];
    parsed_data->flag_data_type = bytes[1];
    parsed_data->flag_data = bytes[2];
    parsed_data->service_data_length = bytes[3];
    parsed_data->service_uuid = bytes[4];
    parsed_data->uuid_data = (uint16_t)((uint16_t)bytes[5] << 8 | bytes[6]);
    parsed_data->service_data_length_2 = bytes[7];
    parsed_data->service_data_type = bytes[8];
    parsed_data->uuid_data_2 = (uint16_t)((uint16_t)bytes[9] << 8 | bytes[10]);
    parsed_data->frame_type = bytes[11];
    parsed_data->version_number = bytes[12];
    parsed_data->soc = bytes[13];
    parsed_data->x_axis = (int16_t)((int16_t)bytes[14] << 8 | bytes[15]) / 256.0;
    parsed_data->y_axis = (int16_t)((int16_t)bytes[16] << 8 | bytes[17]) / 256.0;
    parsed_data->z_axis = (int16_t)((int16_t)bytes[18] << 8 | bytes[19]) / 256.0;
    snprintf(parsed_data->mac_address, sizeof(parsed_data->mac_address), "%02X%02X%02X%02X%02X%02X",
             bytes[20], bytes[21], bytes[22], bytes[23], bytes[24], bytes[25]);
}


void print_parsed_data(const BLEData *data) {
    printf("Device Information:\n");
    printf("  MAC Address: %s\n", data->mac_address);
    printf("  UUID Data: %04X\n", data->uuid_data);
    printf("  UUID Data 2: %04X\n", data->uuid_data_2);
    printf("  Frame Type: %u\n", data->frame_type);
    printf("  Version Number: %u\n", data->version_number);
    printf("  State of Charge (SOC): %u%%\n", data->soc);

    printf("\nSensor Data:\n");
    printf("  X-Axis: %.2fg\n", data->x_axis);
    printf("  Y-Axis: %.2fg\n", data->y_axis);
    printf("  Z-Axis: %.2fg\n", data->z_axis);

    printf("\nRaw Data:\n");
    printf("  Data Length: %u\n", data->data_length);
    printf("  Flag Data Type: %u\n", data->flag_data_type);
    printf("  Flag Data: %u\n", data->flag_data);
    printf("  Service Data Length: %u\n", data->service_data_length);
    printf("  16-bit Service UUID: %u\n", data->service_uuid);
    printf("  Service Data Length 2: %u\n", data->service_data_length_2);
    printf("  Service Data Type: %u\n", data->service_data_type);
}

void print_movement_status(int is_moving) {
    if (is_moving) {
        printf("\nThe tag is moving.\n");
    } else {
        printf("\nThe tag is not moving.\n");
    }
}

int is_tag_moving(const BLEData *parsed_data) {

    double magnitude = sqrt(pow(parsed_data->x_axis, 2) +
                                    pow(parsed_data->y_axis, 2) +
                                    pow(parsed_data->z_axis, 2));

    printf("parsed_data->x_axis: %f\n", parsed_data->x_axis);
    printf("parsed_data->y_axis: %f\n", parsed_data->y_axis);
    printf("parsed_data->z_axis: %f\n", parsed_data->z_axis);

    const double threshold = 1.0;
    printf("Magnitude: %f\n", magnitude);


    return magnitude > threshold;
}