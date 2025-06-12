# Set the MCU to nRF52840 for NiceNano
MCU = nrf52840

# Bootloader for NiceNano MCU
BOOTLOADER = nrf52840_uf2

# Enable Bluetooth functionality
BLUETOOTH_ENABLE = yes
NRF52_SOFTDEVICE = s140  # Required for Bluetooth support on nRF52840

# WPM_ENABLE = yes          # Enable WPM Counter
OLED_ENABLE = yes          # Enable OLED
OLED_DRIVER = ssd1306      # Enable Support for SSD1306 or SH1106 OLED Displays; Communicating over I2C
OLED_TRANSPORT = i2c

# Split keyboard
SPLIT_KEYBOARD = yes
SPLIT_TRANSPORT = BLE

# Power management (optional)
SLEEP_MODE_DEEP = yes

SERIAL_DRIVER = vendor

MOUSEKEY_ENABLE = yes
RAW_ENABLE = yes # 





