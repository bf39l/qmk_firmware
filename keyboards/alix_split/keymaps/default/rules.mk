# Bootloader selection
BOOTLOADER = rp2040

# WPM_ENABLE = yes          # Enable WPM Counter
OLED_ENABLE = yes          # Enable OLED
OLED_DRIVER = ssd1306      # Enable Support for SSD1306 or SH1106 OLED Displays; Communicating over I2C
OLED_TRANSPORT = i2c

SPLIT_KEYBOARD = yes

SERIAL_DRIVER = vendor

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pimoroni_trackball

MOUSEKEY_ENABLE = yes
RAW_ENABLE = yes # 

# https://docs.qmk.fm/tap_hold
DYNAMIC_TAPPING_TERM_ENABLE = yes