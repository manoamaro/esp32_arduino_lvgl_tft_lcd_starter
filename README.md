# PlatformIO ESP32 + Arduino + LVGL v9.1 + TFT LCD Starter Project

Welcome to the starter project for PlatformIO with ESP32, Arduino framework, LVGL v9.1, and TFT LCD displays. This project is pre-configured and ready to run, making it easy to get started with your ESP32-based GUI applications.

## Features

- **PlatformIO**: Easy integration and development with ESP32.
- **Arduino Framework**: Utilize the extensive Arduino ecosystem.
- **LVGL v9.1**: A powerful and customizable graphics library for embedded systems.
- **TFT LCD Support**: Pre-configured for popular TFT LCD displays.
- **LittleFS + Arduino LVGL Driver**: File system driver setup for LVGL (see `src/littlefs_fs_drv.cpp`).
- **Simple Keypad Input Device**: 4-button keypad input device setup (see `include/keypad_indev.h` and `src/keypad_indev.cpp`).

## Getting Started

### Prerequisites

- [PlatformIO IDE](https://platformio.org/install/ide?install=vscode) installed on Visual Studio Code.
- ESP32 development board.
- TFT LCD display compatible with the defined pin setup.

### Installation

1. **Clone this repository**:
    ```sh
    git clone https://github.com/manoamaro/esp32_arduino_lvgl_tft_lcd_starter.git
    cd esp32_arduino_lvgl_tft_lcd_starter
    ```

2. **Open the project in PlatformIO**:
    - Open Visual Studio Code.
    - Navigate to `File > Open Folder...` and select the cloned repository.

3. **Install the required libraries**:
    PlatformIO should automatically handle the library installations as defined in `platformio.ini`. If not, you can install them manually.

### Configuration

Before running the project, ensure the following configuration files are adjusted according to your setup:

1. **`include/lv_conf.h`**:
    - Configure LVGL settings according to your application needs.
    - Refer to the [LVGL documentation](https://docs.lvgl.io/latest/en/html/porting/custom_conf.html) for detailed information.

2. **`include/tft_setup.h`**:
    - Adjust the pin configurations for your TFT LCD display if necessary. Default pin setup is as follows:
      ```c
      #define TFT_MOSI 23
      #define TFT_MISO 19
      #define TFT_SCK  18
      #define TFT_CS   5
      #define TFT_DC   17
      #define TFT_RST  2
      ```

### Build and Upload

1. **Build the project**:
    - Click the PlatformIO icon in the Visual Studio Code sidebar.
    - Click the build icon (checkmark) in the PlatformIO toolbar.

2. **Upload the firmware**:
    - Connect your ESP32 board to your computer via USB.
    - Click the upload icon (right arrow) in the PlatformIO toolbar.

### Usage

Once the firmware is uploaded, the ESP32 board should initialize and display the GUI on the connected TFT LCD.

### Additional Features

- **LittleFS + Arduino LVGL Driver**: The project includes a LittleFS file system driver for LVGL. You can find the implementation in `src/littlefs_fs_drv.cpp`.
- **Simple Keypad Input Device**: A simple keypad input device with 4 buttons is included in the project. The relevant files are `include/keypad_indev.h` and `src/keypad_indev.cpp`.

## Contributing

Feel free to submit issues or pull requests if you find any bugs or have feature suggestions. Contributions are always welcome!

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

- [PlatformIO](https://platformio.org/)
- [Arduino](https://www.arduino.cc/)
- [LVGL](https://lvgl.io/)

---

Happy coding!