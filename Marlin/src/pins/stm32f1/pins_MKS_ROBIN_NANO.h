/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * MKS Robin nano (STM32F130VET6) board pin assignments
 */

#ifndef __STM32F1__
  #error "Oops! Select an STM32F1 board in 'Tools > Board.'"
#elif HOTENDS > 2 || E_STEPPERS > 2
  #error "MKS Robin nano supports up to 2 hotends / E-steppers. Comment out this line to continue."
#endif

#define BOARD_INFO_NAME "MKS Robin Nano"

//
// Release PB4 (Y_ENABLE_PIN) from JTAG NRST role
//
#define DISABLE_DEBUG

//
// EEPROM
//
// from https://github.com/le3tspeak/Marlin-2.0.X-MKS-Robin-Nano/blob/5c74af5006950defbd8a6d5467ba2707897e881f/Marlin/src/pins/stm32f1/pins_MKS_ROBIN_NANO.h#L39
//#define SDCARD_EEPROM_EMULATION
#if EITHER(NO_EEPROM_SELECTED, FLASH_EEPROM_EMULATION) && NONE (SDCARD_EEPROM_EMULATION)
  #define FLASH_EEPROM_EMULATION
  #define EEPROM_PAGE_SIZE     (0x800U) // 2KB
  #define EEPROM_START_ADDRESS (0x8000000UL + (STM32_FLASH_SIZE) * 1024UL - (EEPROM_PAGE_SIZE) * 2UL)
  #define MARLIN_EEPROM_SIZE   EEPROM_PAGE_SIZE  // 2KB
#endif

#define ENABLE_SPI2

//
// Limit Switches
//
#define X_STOP_PIN                          PA15
#define Y_STOP_PIN                          PA12
#define Z_MIN_PIN                           PA11
//#define Z_MAX_PIN                           PC4

#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN                    PA4   // MT_DET
#endif

//
// Steppers
//
#define X_ENABLE_PIN                        PE4
#define X_STEP_PIN                          PE3
#define X_DIR_PIN                           PE2

#define Y_ENABLE_PIN                        PE1
#define Y_STEP_PIN                          PE0
#define Y_DIR_PIN                           PB9

#define Z_ENABLE_PIN                        PB8
#define Z_STEP_PIN                          PB5
#define Z_DIR_PIN                           PB4

#define E0_ENABLE_PIN                       PB3
#define E0_STEP_PIN                         PD6
#define E0_DIR_PIN                          PD3

//#define E1_ENABLE_PIN                       PA3
//#define E1_STEP_PIN                         PA6
//#define E1_DIR_PIN                          PA1

//
// Temperature Sensors
//
#define TEMP_0_PIN                          PC1   // TH1
//#define TEMP_1_PIN                          PC2   // TH2
#define TEMP_BED_PIN                        PC0   // TB1

//
// Heaters / Fans
//
#define HEATER_0_PIN                        PC3   // HEATER1
//#define HEATER_1_PIN                        PB0   // HEATER2
#define HEATER_BED_PIN                      PA0   // HOT BED

#define FAN_PIN                             PB1   // FAN

//
// Thermocouples
//
//#define MAX6675_SS_PIN                    PE5   // TC1 - CS1
//#define MAX6675_SS_PIN                    PE6   // TC2 - CS2

//
// Misc. Functions
//
//#define POWER_LOSS_PIN                      PA2   // PW_DET
//#define PS_ON_PIN                           PA3   // PW_OFF

//#define SUICIDE_PIN                       PB2   // Enable MKSPWC support ROBIN NANO v1.2 ONLY
//#define SUICIDE_PIN_INVERTING false

//#define KILL_PIN                          PA2   // Enable MKSPWC support ROBIN NANO v1.2 ONLY
//#define KILL_PIN_INVERTING true                 // Enable MKSPWC support ROBIN NANO v1.2 ONLY

//#define SERVO0_PIN                        PA8   // Enable BLTOUCH support ROBIN NANO v1.2 ONLY

//#define LED_PIN                           PB2

#define MT_DET_1_PIN                        PA4
#define MT_DET_PIN_INVERTING false

//
// SD Card
//
//#ifndef SDCARD_CONNECTION
 // #define SDCARD_CONNECTION              ONBOARD
//#endif

#define SDIO_SUPPORT
#define SDIO_CLOCK                          8000000       /* 8 MHz */
#define SD_DETECT_PIN                       PD12
#define ONBOARD_SD_CS_PIN                   PC11

//
// LCD / Controller
//
#define BEEPER_PIN                          PC5

// UART
#if HAS_TMC_UART

    #define X_SERIAL_TX_PIN                   PE5 // TC-MAX31855  CS pin 
    #define X_SERIAL_RX_PIN                   X_SERIAL_TX_PIN

    #define Y_SERIAL_TX_PIN                   X_SERIAL_TX_PIN
    #define Y_SERIAL_RX_PIN                   X_SERIAL_TX_PIN

    #define Z_SERIAL_TX_PIN                   X_SERIAL_TX_PIN
    #define Z_SERIAL_RX_PIN                   X_SERIAL_TX_PIN

    #define E0_SERIAL_TX_PIN                  PA5 // wifi PA5 pin
    #define E0_SERIAL_RX_PIN                  E0_SERIAL_TX_PIN

  // Reduce baud rate for software serial reliability
  //#if HAS_TMC_SW_SERIAL
  #define TMC_BAUD_RATE 19200
  //#endif

#endif

// from https://github.com/le3tspeak/Marlin-2.0.X-MKS-Robin-Nano/blob/ccab494060aa552243e8323c15aee0bae4f61a14/Marlin/src/pins/stm32f1/pins_MKS_ROBIN_NANO.h#L268
//
// WIFI ESP8266 
//

#if ANY (WIFISUPPORT, ESP3D_WIFISUPPORT)
  #define WIFI_TX_PIN    PA10
  #define WIFI_RX_PIN    PA9
  #define WIFI_IO0_PIN   PC13
  #define WIFI_IO1_PIN   PC7
#endif

/**
 * Note: MKS Robin TFT screens use various TFT controllers.
 * If the screen stays white, disable 'LCD_RESET_PIN'
 * to let the bootloader init the screen.
 */

#if ENABLED(FSMC_GRAPHICAL_TFT)

  #define FSMC_UPSCALE 3
  #define LCD_FULL_PIXEL_WIDTH  480
  #define LCD_PIXEL_OFFSET_X    48
  #define LCD_FULL_PIXEL_HEIGHT 320
  #define LCD_PIXEL_OFFSET_Y    32

#endif

#if ENABLED(FSMC_GRAPHICAL_TFT)
  #define DOGLCD_MOSI -1 // prevent redefine Conditionals_post.h
  #define DOGLCD_SCK -1
  #define FSMC_CS_PIN                       PD7   // NE4
  #define FSMC_RS_PIN                       PD11  // A0

  #define LCD_USE_DMA_FSMC
  #define FSMC_DMA_DEV DMA2
  #define FSMC_DMA_CHANNEL DMA_CH5
 // #define LCD_RESET_PIN                     PC6   // FSMC_RST

  #define LCD_BACKLIGHT_PIN                 PD13

  #if ENABLED(TOUCH_BUTTONS)
    #define TOUCH_CS_PIN                    PA7   // SPI2_NSS
    #define TOUCH_SCK_PIN                   PB13  // SPI2_SCK
    #define TOUCH_MISO_PIN                  PB14  // SPI2_MISO
    #define TOUCH_MOSI_PIN                  PB15  // SPI2_MOSI
  #endif

#endif

//
// SPI
//

#define ENABLE_SPI2
#define SPI_FLASH
#if ENABLED(SPI_FLASH)
  #define W25QXX_CS_PIN                     PB12
  #define W25QXX_MOSI_PIN                   PB15
  #define W25QXX_MISO_PIN                   PB14
  #define W25QXX_SCK_PIN                    PB13
#endif
