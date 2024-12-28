# BLE Tag Movement Detection

This project demonstrates how to parse BLE tag data and determine if the tag is moving based on accelerometer data.

## Files

- `main.c`: The main program that processes BLE tag data samples.
- `parser.c`: Contains functions to parse BLE data and determine movement.
- `parser.h`: Header file for `parser.c`.

## Prerequisites

- GCC compiler
- Make sure you have the necessary permissions to execute the commands.

## Instructions

1. **Clone the repository** (if applicable):
    ```sh
    git clone <repository-url>
    cd <repository-directory>
    ```

2. **Compile the code**:
    ```sh
    gcc main.c parser.c -o main
    ```

3. **Run the executable**:
    ```sh
    ./main
    ```

    On Windows, use:
    ```sh
    main.exe
    ```

## Example Output

The program will process the BLE data samples and print the parsed data along with the movement status for each sample.
