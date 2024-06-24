# Bootloader selection
BOOTLOADER = rp2040

# WPM_ENABLE = yes          # Enable WPM Counter
OLED_ENABLE = yes          # Enable OLED
OLED_DRIVER = ssd1306      # Enable Support for SSD1306 or SH1106 OLED Displays; Communicating over I2C
OLED_TRANSPORT = i2c

CONSOLE_ENABLE = yes
I2C_DRIVER_REQUIRED = yes

# SPLIT_KEYBOARD = yes

# SERIAL_DRIVER = vendor

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = azoteq_iqs5xx

MOUSEKEY_ENABLE = yes