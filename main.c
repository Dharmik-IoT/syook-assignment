#include <stdio.h>
#include <unistd.h> // For sleep function
#include "parser.h"

int main() {
    
    const char *data_samples[] = {
        "0201060303E1FF1216E1FFA10364000EFF7F00C23772A33F23AC",
        "0201060303E1FF1216E1FFA1036400FAFF7E01233772A33F23AC",
        "0201060303E1FF1216E1FFA1036400FBFF7D013F3772A33F23AC",
        "0201060303E1FF1216E1FFA1036400FCFF7C013F3772A33F23AC", 
        "0201060303E1FF1216E1FFA1036400FDFF7B013F3772A33F23AC"  
    };

    int size = sizeof(data_samples) / sizeof(data_samples[0]);

    for (int i = 0; i < size; i++) {
        BLEData parsed_data;
        parse_ble_data(data_samples[i], &parsed_data);
        print_parsed_data(&parsed_data);

        if (is_tag_moving(&parsed_data)) {
            printf("\nThe tag is moving.\n");
        } else {
            printf("\nThe tag is not moving.\n");
        }
        sleep(1);
    }

    return 0;
}
