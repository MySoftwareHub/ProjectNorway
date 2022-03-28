#ifndef SX1272_h          // If the librairy is not include just
#define SX1272_h          // Define the librairy SX1272_h

/******************************************************************************

 * Includes

 ******************************************************************************/

#include <stdlib.h>       // Include many functions in C language
#include <stdint.h>       // Include the all kind of integer
#include <Arduino.h>      // Include the librairy of Arduino to make it easier for programming the code
#include <SPI.h>          // Include the Serial Protocol Interface to communicate between the Arduino card and the microcontroller of the SX1272

#ifndef   inttypes_h      // If the librairy is not include just
#include <inttypes.h>     // Define the librairy 
#endif                    // Close the ifndef


/******************************************************************************

 * Definitions & Declarations

 *****************************************************************************/
 
// do not remove!

#define W_REQUESTED_ACK             // Just acquire the request of the SX1272 

//#define W_NET_KEY
//#define W_INITIALIZATION

#define SX1272_RST          A0      // Define the reset pin on A0
#define SX1272_SS           10      // Define the slave of the SX1272
#define SX1272Chip          1       // Put 1 to use this module and 0 if you don't want to use it ( just choose between SX1272 and SX1276 )
#define SX1276Chip          0       // Put 1 to use this module and 0 if you don't want to use it ( just choose between SX1272 and SX1276 )
#define SX1272_debug_mode   1       // Choose between 1 (less informations comapred to the 2 ) or 2 (more informations compared to the 1) to use the serial monitor


//! MACROS //


#define bitRead(value, bit)   (((value) >> (bit)) & 0x01)     // Permit to read a bit
#define bitSet(value, bit)    ((value) |= (1UL << (bit)))     // Permit to set bit to '1'
#define bitClear(value, bit)  ((value) &= ~(1UL << (bit)))    // Permit to set bit to '0'


//! REGISTERS //


// ----- Part 1 ----- // ( Arranged with the address from 0 to 9 )

#define        REG_FIFO                               0x00  // Configure the register with a special address (found in the datasheet of the SX1272) for using FIFO

#define        REG_OP_MODE                            0x01  // Configure the register with a special address (found in the datasheet of the SX1272) for using the OP Mode

#define        REG_BITRATE_MSB                        0x02  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Bitrate MSB

#define        REG_BITRATE_LSB                        0x03  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Bitrate LSB 

#define        REG_FDEV_MSB                           0x04  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Fdev MSB

#define        REG_FDEV_LSB                           0x05  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Fdev LSB

#define        REG_FRF_MSB                            0x06  // Configure the register with a special address (found in the datasheet of the SX1272) for using the FRF MSB

#define        REG_FRF_MID                            0x07  // Configure the register with a special address (found in the datasheet of the SX1272) for using the FRF MID

#define        REG_FRF_LSB                            0x08  // Configure the register with a special address (found in the datasheet of the SX1272) for using the FRF LSB

#define        REG_PA_CONFIG                          0x09  // Configure the register with a special address (found in the datasheet of the SX1272) for using the PA configuration

// ----- Part 2 ----- // ( Arranged with the address from 0A to 0F )

#define        REG_PA_RAMP                            0x0A  // Configure the register with a special address (found in the datasheet of the SX1272) for using the PA ramp

#define        REG_OCP                                0x0B  // Configure the register with a special address (found in the datasheet of the SX1272) for using the OCP

#define        REG_LNA                                0x0C  // Configure the register with a special address (found in the datasheet of the SX1272) for using the LNA

#define        REG_RX_CONFIG                          0x0D  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Rx configuration

#define        REG_FIFO_ADDR_PTR                      0x0D  // Configure the register with a special address (found in the datasheet of the SX1272) for using the FIFO address for PTR

#define        REG_RSSI_CONFIG                        0x0E  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the RSSI configuration

#define        REG_FIFO_TX_BASE_ADDR                  0x0E  // Configure the register with a special address (found in the datasheet of the SX1272) for using the FIFO Tx base address

#define        REG_FIFO_RX_BASE_ADDR                  0x0F  // Configure the register with a special address (found in the datasheet of the SX1272) for using the FIFO Rx base address

#define        REG_RSSI_COLLISION                     0x0F  // Configure the register with a special address (found in the datasheet of the SX1272) for using the RSSI collision

// ----- Part 3 ----- // ( Arranged with the address from 10 to 19 ) 

#define        REG_RSSI_THRESH                        0x10  // Configure the register with a special address (found in the datasheet of the SX1272) for using the RSSI thresh

#define        REG_FIFO_RX_CURRENT_ADDR               0x10  // Configure the register with a special address (found in the datasheet of the SX1272) for using the FIFO Rx current address

#define        REG_RSSI_VALUE_FSK                     0x11  // Configure the register with a special address (found in the datasheet of the SX1272) for using the RSSI value FSK
      
#define        REG_IRQ_FLAGS_MASK                     0x11  // Configure the register with a special address (found in the datasheet of the SX1272) for using the IRQ flags mask

#define        REG_RX_BW                              0x12  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Rx bw

#define        REG_IRQ_FLAGS                          0x12  // Configure the register with a special address (found in the datasheet of the SX1272) for using the IRQ flags

#define        REG_AFC_BW                             0x13  // Configure the register with a special address (found in the datasheet of the SX1272) for using the AFC bw

#define        REG_RX_NB_BYTES                        0x13  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Rx number of bytes

#define        REG_OOK_PEAK                           0x14  // Configure the register with a special address (found in the datasheet of the SX1272) for using the OOK peak

#define        REG_RX_HEADER_CNT_VALUE_MSB            0x14  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Rx header CNT value MSB

#define        REG_OOK_FIX                            0x15  // Configure the register with a special address (found in the datasheet of the SX1272) for using the OOK fix

#define        REG_RX_HEADER_CNT_VALUE_LSB            0x15  // Configure the register with a special address (found in the datasheet of the SX1272) for using the RX header constant value LSB

#define        REG_OOK_AVG                            0x16  // Configure the register with a special address (found in the datasheet of the SX1272) for using the OOK average

#define        REG_RX_PACKET_CNT_VALUE_MSB            0x16  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Rx packet constant value MSB

#define        REG_RX_PACKET_CNT_VALUE_LSB            0x17  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Rx packet constant value LSB  

#define        REG_MODEM_STAT                         0x18  // Configure the register with a special address (found in the datasheet of the SX1272) for using the MODEM statistic

#define        REG_PKT_SNR_VALUE                      0x19  // Configure the register with a special address (found in the datasheet of the SX1272) for using the PKT SNR value

// ----- Part 4 ----- // ( Arranged with the address from 1A to 1F )

#define        REG_AFC_FEI                            0x1A  // Configure the register with a special address (found in the datasheet of the SX1272) for using the AFC FEI

#define        REG_PKT_RSSI_VALUE                     0x1A  // Configure the register with a special address (found in the datasheet of the SX1272) for using the PKT RSSI value

#define        REG_AFC_MSB                            0x1B  // Configure the register with a special address (found in the datasheet of the SX1272) for using the AFC MSB

#define        REG_RSSI_VALUE_LORA                    0x1B  // Configure the register with a special address (found in the datasheet of the SX1272) for using the RSSI value of the LORA

#define        REG_AFC_LSB                            0x1C  // Configure the register with a special address (found in the datasheet of the SX1272) for using the AFC LSB

#define        REG_HOP_CHANNEL                        0x1C  // Configure the register with a special address (found in the datasheet of the SX1272) for using the HOP channel

#define        REG_FEI_MSB                            0x1D  // Configure the register with a special address (found in the datasheet of the SX1272) for using the FEI MSB

#define        REG_MODEM_CONFIG1                      0x1D  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Modem configuration 1

#define        REG_FEI_LSB                            0x1E  // Configure the register with a special address (found in the datasheet of the SX1272) for using the FEI LSB

#define        REG_MODEM_CONFIG2                      0x1E  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Modem configuration 2

#define        REG_PREAMBLE_DETECT                    0x1F  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Preamble detection

#define        REG_SYMB_TIMEOUT_LSB                   0x1F  // Configure the register with a special address (found in the datasheet of the SX1272) for using the symbole timeout LSB

// ----- Part 5 ----- // ( Arranged with the address from 20 to 29 )

#define        REG_RX_TIMEOUT1                        0x20  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Rx timeout 1

#define        REG_PREAMBLE_MSB_LORA                  0x20  // Configure the register with a special address (found in the datasheet of the SX1272) for using the preamble MSB LORA

#define        REG_RX_TIMEOUT2                        0x21  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Rx timeout 2

#define        REG_PREAMBLE_LSB_LORA                  0x21  // Configure the register with a special address (found in the datasheet of the SX1272) for using the preamble LSB LORA

#define        REG_RX_TIMEOUT3                        0x22  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Rx timeout 3

#define        REG_PAYLOAD_LENGTH_LORA                0x22  // Configure the register with a special address (found in the datasheet of the SX1272) for using the payload's length LORA

#define        REG_RX_DELAY                           0x23  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Rx delay

#define        REG_MAX_PAYLOAD_LENGTH                 0x23  // Configure the register with a special address (found in the datasheet of the SX1272) for using the max payload length

#define        REG_OSC                                0x24  // Configure the register with a special address (found in the datasheet of the SX1272) for using the OSC

#define        REG_HOP_PERIOD                         0x24  // Configure the register with a special address (found in the datasheet of the SX1272) for using the HOP period

#define        REG_PREAMBLE_MSB_FSK                   0x25  // Configure the register with a special address (found in the datasheet of the SX1272) for using the preamble MSB FSK 

#define        REG_FIFO_RX_BYTE_ADDR                  0x25  // Configure the register with a special address (found in the datasheet of the SX1272) for using the FIFO Rx byte address

#define        REG_PREAMBLE_LSB_FSK                   0x26  // Configure the register with a special address (found in the datasheet of the SX1272) for using the preamble LSB FSK

#define        REG_MODEM_CONFIG3                      0x26  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Modem configuration 3

#define        REG_SYNC_CONFIG                        0x27  // Configure the register with a special address (found in the datasheet of the SX1272) for using the SYNC configuration

#define        REG_SYNC_VALUE1                        0x28  // Configure the register with a special address (found in the datasheet of the SX1272) for using the SYNC value 1

#define        REG_SYNC_VALUE2                        0x29  // Configure the register with a special address (found in the datasheet of the SX1272) for using the SYNC value 2

// ----- Part 6 ----- // ( Arranged with the address from 2A to 2F )

#define        REG_SYNC_VALUE3                        0x2A  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the SYNC value 3

#define        REG_SYNC_VALUE4                        0x2B  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the SYNC value 4

#define        REG_SYNC_VALUE5                        0x2C  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the SYNC value 5

#define        REG_SYNC_VALUE6                        0x2D  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the SYNC value 6

#define        REG_SYNC_VALUE7                        0x2E  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the SYNC value 7

#define        REG_SYNC_VALUE8                        0x2F  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the SYNC value 8

// ----- Part 7 ----- // ( Arranged with the address from 30 to 39 )

#define        REG_PACKET_CONFIG1                     0x30  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the Packet config 1

#define        REG_PACKET_CONFIG2                     0x31  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the Packet config 2

#define        REG_DETECT_OPTIMIZE                    0x31  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the Detection optimize

#define        REG_PAYLOAD_LENGTH_FSK                 0x32  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the Payload length FSK

#define        REG_NODE_ADRS                          0x33  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the Node address

#define        REG_BROADCAST_ADRS                     0x34  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the Broadcast address

#define        REG_FIFO_THRESH                        0x35  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the FIFO thresh

#define        REG_SEQ_CONFIG1                        0x36  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the Sequence configuration 1

#define        REG_SEQ_CONFIG2                        0x37  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the Sequence configuration 2

#define        REG_DETECTION_THRESHOLD                0x37  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the Detection threshold

#define        REG_TIMER_RESOL                        0x38  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the timer resolution

#define        REG_SYNC_WORD                          0x39  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the SYNC word

#define        REG_TIMER1_COEF                        0x39  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the Timer 1 coefficient

// ----- Part 8 ----- // ( Arranged with the address from 3A to 3F )

#define        REG_TIMER2_COEF                        0x3A  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the Timer 2 coefficient

#define        REG_IMAGE_CAL                          0x3B  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the Image cal

#define        REG_TEMP                               0x3C  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the Temperature

#define        REG_LOW_BAT                            0x3D  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the Low battery

#define        REG_IRQ_FLAGS1                         0x3E  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the IRQ flags 1

#define        REG_IRQ_FLAGS2                         0x3F  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the IRQ flags 2

// ----- Part 9 ----- // ( Arranged with the address from 40 to 46 )

#define        REG_DIO_MAPPING1                       0x40  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the Mapping 1

#define        REG_DIO_MAPPING2                       0x41  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the Mapping 2

#define        REG_VERSION                            0x42  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the version

#define        REG_AGC_REF                            0x43  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the AGC reference

#define        REG_AGC_THRESH1                        0x44  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the AGC thresh 1 

#define        REG_AGC_THRESH2                        0x45  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the AGC thresh 2

#define        REG_AGC_THRESH3                        0x46  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the AGC thresh 3

// ----- Part 10 ----- // ( Arranged with the address from 4B to 6C )

#define        REG_PLL_HOP                            0x4B  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the PLL HOP

#define        REG_TCXO                               0x58  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the TCXO

#define        REG_PA_DAC                             0x5A  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the PA DAC

#define        REG_PLL                                0x5C  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the PLL

#define        REG_PLL_LOW_PN                         0x5E  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the PLL low PN

#define        REG_FORMER_TEMP                        0x6C  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the former temperature

// ----- Part 11 ----- // ( Arranged with the address 70 )

#define        REG_BIT_RATE_FRAC                      0x70  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the Bit rate frac

// ----- Part 12 ----- // ( Arranged with the address 7F )

#define        RF_IMAGECAL_AUTOIMAGECAL_MASK          0x7F  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the Image cal auto image cal MASK

// ----- Part 13 ----- // ( Arranged with the address from 80 to 0 )

#define        RF_IMAGECAL_AUTOIMAGECAL_ON            0x80  //  Configure the register with a special address (found in the datasheet of the SX1272) for using the Image cal auto image cal ON

#define        RF_IMAGECAL_AUTOIMAGECAL_OFF           0x00  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Image cal auto image cal OFF ( Default )

// ----- Part 14 ----- // ( Arranged with the address BF )

#define        RF_IMAGECAL_IMAGECAL_MASK              0xBF  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Image cal Image cal MASK

// ----- Part 15 ----- // ( Arranged with the address from 40 to 0 )

#define        RF_IMAGECAL_IMAGECAL_START             0x40  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Image cal Image cal Start

#define        RF_IMAGECAL_IMAGECAL_RUNNING           0x20  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Image cal Image cal Running

#define        RF_IMAGECAL_IMAGECAL_DONE              0x00  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Image cal Image cal Done ( Default )

#define        RF_IMAGECAL_TEMPCHANGE_HIGHER          0x08  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Image cal Image cal Higher

#define        RF_IMAGECAL_TEMPCHANGE_LOWER           0x00  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Image cal Image cal Lower

// ----- Part 16 ----- // ( Arranged with the address F9 )

#define        RF_IMAGECAL_TEMPTHRESHOLD_MASK         0xF9  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Image cal temperature threshold MASK

// ----- Part 17 ----- // ( Arranged with the address from 0 to 6 )

#define        RF_IMAGECAL_TEMPTHRESHOLD_05           0x00  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Image cal temperature threshold 05

#define        RF_IMAGECAL_TEMPTHRESHOLD_10           0x02  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Image cal temperature threshold 10 ( Default )

#define        RF_IMAGECAL_TEMPTHRESHOLD_15           0x04  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Image cal temperature threshold 15

#define        RF_IMAGECAL_TEMPTHRESHOLD_20           0x06  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Image cal temperature threshold 20

// ----- Part 18 ----- // ( Arranged with the address FE )

#define        RF_IMAGECAL_TEMPMONITOR_MASK           0xFE  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Image cal temperature monitor MASK

// ----- Part 19 ----- // ( Arranged with the address from 0 to 1 )

#define        RF_IMAGECAL_TEMPMONITOR_ON             0x00  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Image cal temperature monitor ON ( Default )

#define        RF_IMAGECAL_TEMPMONITOR_OFF            0x01  // Configure the register with a special address (found in the datasheet of the SX1272) for using the Image cal temperature monitor OFF

// ----- Part 20 ----- // ( Arranged with the address from 80 to 0 )

#define        RH_LORA_FXOSC 32000000.0                    // Configure the register with a special address (found in the datasheet of the SX1272) for using the LORA FXOSC ( f = 32 Mhz ) 

#define        RH_LORA_FCONVERT  (524288 / RH_LORA_FXOSC)  // Configure the register with a special address (found in the datasheet of the SX1272) for using the LORA Frequency convert 


//FREQUENCY CHANNELS:


// ----- Part 1 ----- //

const uint32_t    CH_00_433 = 0x6C5333;     // channel 00, central freq = 433.3 MHz

const uint32_t    CH_01_433 = 0x6C6666;     // channel 01, central freq = 433.6 MHz

const uint32_t    CH_02_433 = 0x6C7999;     // channel 02, central freq = 433.9 MHz

const uint32_t    CH_03_433 = 0x6C9333;     // channel 03, central freq = 434.3 MHz

// ----- Part 2 ----- //

const uint32_t    CH_04_868 = 0xD7CCCC;     // channel 04, central freq = 863.20 MHz

const uint32_t    CH_05_868 = 0xD7E000;     // channel 05, central freq = 863.50 MHz

const uint32_t    CH_06_868 = 0xD7F333;     // channel 06, central freq = 863.80 MHz

const uint32_t    CH_07_868 = 0xD80666;     // channel 07, central freq = 864.10 MHz

const uint32_t    CH_08_868 = 0xD81999;     // channel 08, central freq = 864.40 MHz

const uint32_t    CH_09_868 = 0xD82CCC;     // channel 09, central freq = 864.70 MHz

const uint32_t    CH_10_868 = 0xD84CCC;     // channel 10, central freq = 865.20 MHz

const uint32_t    CH_11_868 = 0xD86000;     // channel 11, central freq = 865.50 MHz

const uint32_t    CH_12_868 = 0xD87333;     // channel 12, central freq = 865.80 MHz

const uint32_t    CH_13_868 = 0xD88666;     // channel 13, central freq = 866.10 MHz

const uint32_t    CH_14_868 = 0xD89999;     // channel 14, central freq = 866.40 MHz

const uint32_t    CH_15_868 = 0xD8ACCC;     // channel 15, central freq = 866.70 MHz

const uint32_t    CH_16_868 = 0xD8C000;     // channel 16, central freq = 867.00 MHz

const uint32_t    CH_17_868 = 0xD90000;     // channel 17, central freq = 868.00  MHz

const uint32_t    CH_18_868 = 0xD90666;     // channel 18, central freq = 868.1MHz for LoRaWAN test

// ----- Part 3 ----- //

const uint32_t    CH_00_900 = 0xE1C51E;     // channel 00, central freq = 903.08 MHz

const uint32_t    CH_01_900 = 0xE24F5C;     // channel 01, central freq = 905.24 MHz

const uint32_t    CH_02_900 = 0xE2D999;     // channel 02, central freq = 907.40 MHz

const uint32_t    CH_03_900 = 0xE363D7;     // channel 03, central freq = 909.56 MHz

const uint32_t    CH_04_900 = 0xE3EE14;     // channel 04, central freq = 911.72 MHz

const uint32_t    CH_05_900 = 0xE47851;     // channel 05, central freq = 913.88 MHz

const uint32_t    CH_06_900 = 0xE5028F;     // channel 06, central freq = 916.04 MHz

const uint32_t    CH_07_900 = 0xE58CCC;     // channel 07, central freq = 918.20 MHz

const uint32_t    CH_08_900 = 0xE6170A;     // channel 08, central freq = 920.36 MHz

const uint32_t    CH_09_900 = 0xE6A147;     // channel 09, central freq = 922.52 MHz

const uint32_t    CH_10_900 = 0xE72B85;     // channel 10, central freq = 924.68 MHz

const uint32_t    CH_11_900 = 0xE7B5C2;     // channel 11, central freq = 926.84 MHz

const uint32_t    CH_12_900 = 0xE4C000;     // channel 12, central freq = 915MHz, default channel and frequency, the module is configured with it


//LORA BANDWIDTH:


const uint8_t     SX1272_BW_125 = 0x00;   // bandwidth frequency = 125 MHz

const uint8_t     SX1272_BW_250 = 0x01;   // bandwidth frequency = 250 MHz

const uint8_t     SX1272_BW_500 = 0x02;   // bandwidth frequency = 500 MHz



// use the following constants with setBW()


const uint8_t     BW_7_8    =   0x00;     //  bandwidth frequency = 7.8 MHz

const uint8_t     BW_10_4   =   0x01;     //  bandwidth frequency = 10.4 MHz

const uint8_t     BW_15_6   =   0x02;     //  bandwidth frequency = 15.6 MHz

const uint8_t     BW_20_8   =   0x03;     //  bandwidth frequency = 20.8 MHz

const uint8_t     BW_31_25  =   0x04;     //  bandwidth frequency = 31.25 MHz

const uint8_t     BW_41_7   =   0x05;     //  bandwidth frequency = 41.7 MHz

const uint8_t     BW_62_5   =   0x06;     //  bandwidth frequency = 62.5 MHz

const uint8_t     BW_125    =   0x07;     //  bandwidth frequency = 125 MHz

const uint8_t     BW_250    =   0x08;     //  bandwidth frequency = 250 MHz

const uint8_t     BW_500    =   0x09;     //  bandwidth frequency = 500 MHz


const double SignalBwLog[] =
{

    5.0969100130080564143587833158265,

    5.397940008672037609572522210551,

    5.6989700043360188047862611052755

};                                        //  I don't know what it is


//LORA CODING RATE:


const uint8_t     CR_5 = 0x01;    // Coding rate = 5

const uint8_t     CR_6 = 0x02;    // Coding rate = 6

const uint8_t     CR_7 = 0x03;    // Coding rate = 7

const uint8_t     CR_8 = 0x04;    // Coding rate = 8


//LORA SPREADING FACTOR:


const uint8_t     SF_6  = 0x06;   // Spreading factor = 6

const uint8_t     SF_7  = 0x07;   // Spreading factor = 7

const uint8_t     SF_8  = 0x08;   // Spreading factor = 8

const uint8_t     SF_9  = 0x09;   // Spreading factor = 9

const uint8_t     SF_10 = 0x0A;   // Spreading factor = 10

const uint8_t     SF_11 = 0x0B;   // Spreading factor = 11

const uint8_t     SF_12 = 0x0C;   // Spreading factor = 12


//LORA MODES:


const uint8_t     LORA_SLEEP_MODE       = 0x80;   // Sleep mode of the LORA

const uint8_t     LORA_STANDBY_MODE     = 0x81;   // Stand by mode of the LORA

const uint8_t     LORA_TX_MODE          = 0x83;   // Transmitter mode of the LORA

const uint8_t     LORA_RX_MODE          = 0x85;   // Receiver mode of the LORA

const uint8_t     LORA_CAD_MODE         = 0x87;   // Channel Activity Detector mode of the LORA


#define LNA_MAX_GAIN        0x23    // Max Gain

#define LNA_OFF_GAIN        0x00    // No Gain

#define LNA_LOW_GAIN        0x20    // Low Gain


const uint8_t LORA_STANDBY_FSK_REGS_MODE = 0xC1;    // Put the FSK mode on stand by


//FSK MODES:


const uint8_t     FSK_SLEEP_MODE      = 0x00;   // Sleep mode of the FSK

const uint8_t     FSK_STANDBY_MODE    = 0x01;   // Standby mode of the FSK

const uint8_t     FSK_TX_MODE         = 0x03;   // Transmitter mode of the FSK

const uint8_t     FSK_RX_MODE         = 0x05;   // Receiver mode of the FSK


//OTHER CONSTANTS:


const uint8_t     HEADER_ON           =   0;      // Set the header ON to 0

const uint8_t     HEADER_OFF          =   1;      // Set the header OFF to 1

const uint8_t     CRC_ON              =   1;      // Set the CRC ON to 1

const uint8_t     CRC_OFF             =   0;      // Set the CRC OFF to 0

const uint8_t     LORA                =   1;      // Set the LORA to 1

const uint8_t     FSK                 =   0;      // Set the FSK to 0

const uint8_t     BROADCAST_0         =   0x00;   // Broadcast output 

const uint8_t     MAX_LENGTH          =   255;    // Set the max length to 255

const uint8_t     MAX_PAYLOAD         =   251;    // Set the max payload to 251

const uint8_t     MAX_LENGTH_FSK      =   64;     // Set the max FSK length to 64

const uint8_t     MAX_PAYLOAD_FSK     =   60;     // Set the max FSK payload to 60

const uint8_t     ACK_LENGTH          =   7;      // Set the Acquisition length to 7


#ifdef            W_NET_KEY   // If the Net Key is not declared we do the things below

const uint8_t     NET_KEY_LENGTH         =  2;                    // Set the Net key length to 2

const uint8_t     OFFSET_PAYLOADLENGTH   =  4+NET_KEY_LENGTH;     // Set the offset  payload length to 6

const uint8_t     net_key_0              = 0x12;                  // Set the net key 0

const uint8_t     net_key_1              = 0x34;                  // Set the net key 1

#else                         // If the things upper are established, we do the things below

const uint8_t     OFFSET_PAYLOADLENGTH   = 4;       // Set the offset payload length to 4

#endif                        // End the loop

const uint8_t     OFFSET_RSSI             = 139;    // Set the offset RSSI to 139

const uint8_t     NOISE_FIGURE            = 6.0;    // Set the noise figure to 6.0

const uint8_t     NOISE_ABSOLUTE_ZERO     = 174.0;  // Set the absolute zero to 174.0

const uint16_t    MAX_TIMEOUT             = 10000;  // Set the max timeout to 10 000 ms( = 10 s )

const uint16_t    MAX_WAIT                = 12000;  // Set the max wait to 12 000 ms ( = 12 s )

const uint8_t     MAX_RETRIES             = 5;      // Set the max retries to 5

const uint8_t     CORRECT_PACKET          = 0;      // Set the correct packet to 0

const uint8_t     INCORRECT_PACKET        = 1;      // Set the incorrect packet to 1


// Packet type definition


#define       PKT_TYPE_MASK               0xF0    // Declare the type mask
#define       PKT_FLAG_MASK               0x0F    // Declare the flag mask
#define       PKT_TYPE_DATA               0x10    // Declare the type of data
#define       PKT_TYPE_ACK                0x20    // Declare the type of things we acquired

#define       PKT_FLAG_ACK_REQ            0x08    // Declare the flag for the acquisition req
#define       PKT_FLAG_DATA_ENCRYPTED     0x04    // Declare the flag for data encrypted
#define       PKT_FLAG_DATA_WAPPKEY       0x02    // Declare the flag for data wappkey
#define       PKT_FLAG_DATA_ISBINARY      0x01    // Declare the flag for data if there are binary

#define       SX1272_ERROR_ACK            3       // Declare the error acquisition
#define       SX1272_ERROR_TOA            4       // Declare the error for TOA


//! Structure :


struct pack                         // Declare a structure named pack

{                                   // Begin the loop
#ifdef W_NET_KEY                    // If net key is not declared just do the things below

  uint8_t netkey[NET_KEY_LENGTH];   // Declare the netkey by is length

#endif                              // End of the "If"


//! Structure Variable : Packet destination


uint8_t dst;                        // Declare dst
uint8_t type;                       // Declare type


//! Structure Variable : Packet source


uint8_t src;                        // Declare src


//! Structure Variable : Packet number


uint8_t packnum;                    //  Declare the package number ( will not be used in the transmitted packet )
  

//! Structure Variable : Packet length


uint8_t length;                     // Declare the length
  

//! Structure Variable : Packet payload

    
uint8_t* data;                      // Declare the data


//! Structure Variable : Retry number


uint8_t retry;                      // Declare the retry to change the number

};                                  // End of the loop



/******************************************************************************

 * Class

 ******************************************************************************/



class SX1272                        // Create the class named SX1272

{                                   // Begin the loop

public:                             // Public class

  SX1272();                         // For SX1272 we declare the things below
  
  uint8_t ON();                                                                                           // It puts the module ON
  void OFF();                                                                                             // It puts the module OFF
  
  byte readRegister(byte address);                                                                        // It reads an internal module register
  void writeRegister(byte address, byte data);                                                            // It writes a register
  
  void clearFlags();                                                                                      // It clears the interruption flags
  
  uint8_t setLORA();                                                                                      // Permit to put the LORA ON or OFF
  uint8_t setFSK();                                                                                       // Permit to put the FSK ON or OFF
  
  uint8_t getMode();                                                                                      // It gets the BW, SF and CR of the module => 0 if sucess, 1 otherwhise
  int8_t setMode(uint8_t mode);                                                                           // It sets the BW, SF and CR of the module => 0 if sucess, 1 otherwhise
  
  uint8_t getHeader();                                                                                    // It gets the header mode configured => 0 if sucess, 1 otherwhise
  int8_t  setHeaderON();                                                                                  // It sets explicit header ON mode => 0 if sucess, 1 otherwhise
  int8_t  setHeaderOFF();                                                                                 // It sets explicit header OFF mode => 0 if sucess, 1 otherwhise
  
  uint8_t getCRC();                                                                                       // It gets the CRC configured => 0 if sucess, 1 otherwhise
  uint8_t setCRC_ON();                                                                                    //  It sets CRC on => 0 if sucess, 1 otherwhise
  uint8_t setCRC_OFF();                                                                                   //  It sets CRC off => 0 if sucess, 1 otherwhise
  
  boolean isSF(uint8_t spr);                                                                              // It is true if the SF selected exists
  int8_t  getSF();                                                                                        // It gets the SF configured
  uint8_t setSF(uint8_t spr);                                                                             // It sets the SF 
  
  boolean isBW(uint16_t band);                                                                            // It is true if the BW selected exists
  int8_t  getBW();                                                                                        // It gets the BW configured
  int8_t setBW(uint16_t band);                                                                            // It sets the BW
  
  boolean isCR(uint8_t cod);                                                                              // It is true if the CR selected exists
  int8_t  getCR();                                                                                        // It gets the CR configured
  int8_t  setCR(uint8_t cod);                                                                             // It sets the CR
  
  boolean isChannel(uint32_t ch);                                                                         // It is true if the channel selected exists
  uint8_t getChannel();                                                                                   // It gets frequency channel that the module is using
  int8_t setChannel(uint32_t ch);                                                                         // It sets frequency channel that the module is using
  
  uint8_t getPower();                                                                                     // It gets the output power of the signal
  int8_t setPower(char p);                                                                                // It sets the output power of the signal (M,H or L)
  int8_t setPowerNum(uint8_t pow);                                                                        // It sets the output power of the signal
  
  uint8_t getPreambleLength();                                                                            // It gets the preamble length configured
  uint8_t setPreambleLength(uint16_t l);                                                                  // It sets the preamble length
  
  uint8_t getPayloadLength();                                                                             // It gets the payload length of the last packet to send/receive
  
  int8_t setPacketLength();                                                                               // It sets the packet length to send/receive
  int8_t setPacketLength(uint8_t l);                                                                      // It sets the packet length to send/receive
  
  uint8_t getNodeAddress();                                                                               // It gets the node address of the mote
  int8_t setNodeAddress(uint8_t addr);                                                                    // It sets the node address of the mote
  
  int8_t getSNR();                                                                                        // It gets the SNR of the latest received packet
  
  uint8_t getRSSI();                                                                                      // It gets the current value of RSSI
  int16_t getRSSIpacket();                                                                                // It gets the RSSI of the latest received packet
  
  uint8_t setRetries(uint8_t ret);                                                                        // It sets the total of retries when a packet is not correctly received
  
  uint8_t getMaxCurrent();                                                                                // It gets the maximum current supply by the module
  int8_t setMaxCurrent(uint8_t rate);                                                                     // It sets the maximum current supply by the module
  
  uint8_t getRegs();                                                                                      // It gets the content of the main configuration registers
  
  uint8_t truncPayload(uint16_t length16);                                                                // It sets the maximum number of bytes from a frame that fit in a packet structure
  
  uint8_t setACK();                                                                                       // It writes an ACK in FIFO to send it
  
  uint8_t receive();                                                                                      // It puts the module in reception mode
  
  uint8_t receivePacketMAXTimeout();                                                                      // It receives a packet before MAX_TIMEOUT
  
  uint8_t receivePacketTimeout();                                                                         // It receives a packet before a timeout
  uint8_t receivePacketTimeout(uint16_t wait);                                                            // It receives a packet before a timeout
  
  uint8_t receivePacketMAXTimeoutACK();                                                                   // It receives a packet before MAX_TIMEOUT and reply with an ACK
  
  uint8_t receivePacketTimeoutACK();                                                                      // It receives a packet before a timeout and reply with an ACK
  uint8_t receivePacketTimeoutACK(uint16_t wait);                                                         // It receives a packet before a timeout and reply with an ACK
  
  uint8_t receiveAll();                                                                                   // It puts the module in 'promiscuous' reception mode
  uint8_t receiveAll(uint16_t wait);                                                                      // It puts the module in 'promiscuous' reception mode with a timeout
  
  boolean availableData();                                                                                // It checks if there is an available packet and its destination
  boolean availableData(uint16_t wait);                                                                   // It checks if there is an available packet and its destination before a timeout
  
  uint8_t setPacket(uint8_t dest, char *payload);                                                         // It writes a packet in FIFO in order to send it 
  uint8_t setPacket(uint8_t dest, uint8_t *payload);                                                      // It writes a packet in FIFO in order to send it 
  
  uint8_t getPacketMAXTimeout();                                                                          // It reads a received packet from the FIFO, if it arrives before ending MAX_TIMEOUT time
  
  int8_t getPacket();                                                                                     // It reads a received packet from the FIFO, if it arrives before ending '_sendTime' time
  int8_t getPacket(uint16_t wait);                                                                        // It receives and gets a packet from FIFO, if it arrives before ending 'wait' time
  
  uint8_t sendWithMAXTimeout();                                                                           // It sends the packet stored in FIFO before ending MAX_TIMEOUT
  
  uint8_t sendWithTimeout();                                                                              // It sends the packet stored in FIFO before ending _sendTime time
  uint8_t sendWithTimeout(uint16_t wait);                                                                 // It tries to send the packet stored in FIFO before ending 'wait' time 

  uint8_t sendPacketMAXTimeout(uint8_t dest, char *payload);                                              // It tries to send the packet wich payload is a parameter before ending MAX_TIMEOUT 
  uint8_t sendPacketMAXTimeout(uint8_t dest, uint8_t *payload, uint16_t length);                          // It tries to send the packet wich payload is a parameter before ending MAX_TIMEOUT 
                                                                                                          
  uint8_t sendPacketTimeout(uint8_t dest, char *payload);                                                 // It sends the packet wich payload is a parameter before ending MAX_TIMEOUT
  uint8_t sendPacketTimeout(uint8_t dest, uint8_t *payload, uint16_t length);                             // It sends the packet wich payload is a parameter before ending MAX_TIMEOUT                                                                                                      
  uint8_t sendPacketTimeout(uint8_t dest, char *payload, uint16_t wait);                                  // It sends the packet wich payload is a parameter before ending 'wait' time 
  uint8_t sendPacketTimeout(uint8_t dest, uint8_t *payload, uint16_t length, uint16_t wait);              // It sends the packet wich payload is a parameter before ending 'wait' time
  
  uint8_t sendPacketMAXTimeoutACK(uint8_t dest, char *payload);                                           // It sends the packet wich payload is a parameter before MAX_TIMEOUT, and replies with ACK 
  uint8_t sendPacketMAXTimeoutACK(uint8_t dest, uint8_t *payload, uint16_t length);                       // It sends the packet wich payload is a parameter before MAX_TIMEOUT, and replies with ACK
                                                                                                          
  uint8_t sendPacketTimeoutACK(uint8_t dest, char *payload);                                              // It sends the packet wich payload is a parameter before a timeout, and replies with ACK                                                                                                         
  uint8_t sendPacketTimeoutACK(uint8_t dest, uint8_t *payload, uint16_t length);                          // It sends the packet wich payload is a parameter before a timeout, and replies with ACK                                                                                                        
  uint8_t sendPacketTimeoutACK(uint8_t dest, char *payload, uint16_t wait);                               // It sends the packet wich payload is a parameter before 'wait' time, and replies with ACK                                                                                                        
  uint8_t sendPacketTimeoutACK(uint8_t dest, uint8_t *payload, uint16_t length, uint16_t wait);           // It sends the packet wich payload is a parameter before 'wait' time, and replies with ACK
                                                                                                         
  int8_t setDestination(uint8_t dest);                                                                    // It sets the destination of a packet
  
  uint8_t setTimeout();                                                                                   // It sets the waiting time to send a packet => It stores in global '_sendTime' variable the time for each mode
  
  uint8_t setPayload(char *payload);                                                                      // It sets the payload of the packet that is going to be sent 
  uint8_t setPayload(uint8_t *payload);                                                                   // It sets the payload of the packet that is going to be sent
  
  uint8_t getACK();                                                                                       // If an ACK is received, it gets it and checks its content
  uint8_t getACK(uint16_t wait);                                                                          // It receives and gets an ACK from FIFO, if it arrives before ending 'wait' time
  
  uint8_t sendPacketMAXTimeoutACKRetries(uint8_t dest, char *payload);                                    // It sends a packet, waits to receive an ACK and updates the _retries value, before ending MAX_TIMEOUT time                                                                                                      
  uint8_t sendPacketMAXTimeoutACKRetries(uint8_t dest, uint8_t *payload, uint16_t length);                // It sends a packet, waits to receive an ACK and updates the _retries value, before ending MAX_TIMEOUT time
                                                                                                          
  uint8_t sendPacketTimeoutACKRetries(uint8_t dest, char *payload);                                       // It sends a packet, waits to receive an ACK and updates the _retries value                                                                                                       
  uint8_t sendPacketTimeoutACKRetries(uint8_t dest, uint8_t *payload, uint16_t length);                   // It sends a packet, waits to receive an ACK and updates the _retries value                                                                                                      
  uint8_t sendPacketTimeoutACKRetries(uint8_t dest, char *payload, uint16_t wait);                        // It sends a packet, waits to receive an ACK and updates the _retries value, before ending 'wait' time                                                                                                     
  uint8_t sendPacketTimeoutACKRetries(uint8_t dest, uint8_t *payload, uint16_t length, uint16_t wait);    // It sends a packet, waits to receive an ACK and updates the _retries value, before ending 'wait' time
                                                                                                          
  uint8_t getTemp();                                                                                      // It gets the internal temperature of the module =>  It stores in global '_temp' variable the module temperature



    // Others functions

  void setPacketType(uint8_t type);     // Set the packet type
  
  void RxChainCalibration();            // Calibrate the Rx chain
  
  uint8_t doCAD(uint8_t counter);       // Permit to do a CAD
  
  uint16_t getToA(uint8_t pl);          // Get ToA
  
  void CarrierSense(uint8_t cs=1);      // Declare the carrier sense
  void CarrierSense1();                 // Declare the carrier sense 1
  void CarrierSense2();                 // Declare the carrier sense 2
  void CarrierSense3();                 // Declare the carrier sense 3
  
  int8_t setSyncWord(uint8_t sw);       // Set Sync word
  int8_t getSyncWord();                 // Get Sync word
  
  int8_t setSleepMode();                // Set the sleep mode
  int8_t setPowerDBM(uint8_t dbm);      // Set the power DBM
 
  long limitToA();                      // Set the limit ToA
  long getRemainingToA();               // Get the remaining ToA
  long removeToA(uint16_t toa);         // Remove the ToA
  
  int8_t setFreqHopOn();                // Set the frequency Hop ON
  
  void setCSPin(uint8_t cs);            // Set CS pin

  uint8_t _board;                       // Choose between SX1272 to SX1276
  
  uint8_t _syncWord;                    // Declare sync word
 
  uint8_t _defaultSyncWord;             // Declare sync word
  
  uint8_t _SX1272_SS;                   // Declare the SX1272 SS
  
  unsigned long _starttime;             // Used for Start time 
  unsigned long _stoptime;              // Used for Stop time
  
  unsigned long _startDoCad;            // Start Do Cad
  unsigned long _endDoCad;              // End Do Cad
  
  uint8_t _loraMode;                    // Set the lora mode
  
  uint8_t _send_cad_number;             // Permit to send the cad number
  
  bool _extendedIFS;                    // Permit to extend IFS
  
  bool _RSSIonSend;                     // Return 0 or 1 for RSSI on send
  
  bool _enableCarrierSense;             // Return 0 or 1 for enable carrier sense
  
  bool _freqHopOn;                      // Return 0 or 1 if the frequency Hop ON
  uint8_t _hopPeriod;                   // Permit to have a Hop period
 
  bool _rawFormat;                      // Return 0 or 1 for the raw format
  
  int8_t _rcv_snr_in_ack;               // Don't know what it is
  
  bool _needPABOOST;                    // Return 0 or 1 for need PABOOST
  
  uint8_t _rawSNR;                      // Declare the raw SNR

#ifdef W_REQUESTED_ACK                  // If the requested ack is not define just do the things below
  
  uint8_t _requestACK;                  // Permit to have the request ACK
  uint8_t _requestACK_indicator;        // Permit to have the request ACK indicator
  
#endif                                  // End of the "If" loop

#ifdef W_NET_KEY                        // If the net key is not define just do the things below

  uint8_t _my_netkey[NET_KEY_LENGTH];   // Declare my net key with its length
  
  uint8_t _the_net_key_0;               // Declare the net key 0
  uint8_t _the_net_key_1;               // Declare the net key 1
  
#endif                                  // End of the "If" loop



  // Variables //


  // Variable : bandwidth configured in LoRa mode.
  
  //    bandwidth = 00  --> BW = 125 KHz
  //    bandwidth = 01  --> BW = 250 KHz
  //    bandwidth = 10  --> BW = 500 KHz
  
  uint8_t _bandwidth; // Declaration of the bandwidth

  // Variable : coding rate configured in LoRa mode.
  
  //   codingRate = 001  --> CR = 4/5
  //   codingRate = 010  --> CR = 4/6
  //   codingRate = 011  --> CR = 4/7
  //   codingRate = 100  --> CR = 4/8
  
  uint8_t _codingRate; // Declaration of the coding rate

  // Variable : spreading factor configured in LoRa mode.
  
  //   spreadingFactor = 6   --> SF = 6,64     chips/symbol
  //   spreadingFactor = 7   --> SF = 7,128    chips/symbol
  //   spreadingFactor = 8   --> SF = 8,256    chips/symbol
  //   spreadingFactor = 9   --> SF = 9,512    chips/symbol
  //   spreadingFactor = 10  --> SF = 10,1024  chips/symbol
  //   spreadingFactor = 11  --> SF = 11,2048  chips/symbol
  //   spreadingFactor = 12  --> SF = 12,4096  chips/symbol
  
  uint8_t _spreadingFactor; // Declaration of the spreading factor

  // Variable : frequency channel.
  
  //    channel = 0xD84CCC  --> CH = 10_868, 865.20 MHz
  //    channel = 0xD86000  --> CH = 11_868, 865.50 MHz
  //    channel = 0xD87333  --> CH = 12_868, 865.80 MHz
  //    channel = 0xD88666  --> CH = 13_868, 866.10 MHz
  //    channel = 0xD89999  --> CH = 14_868, 866.40 MHz
  //    channel = 0xD8ACCC  --> CH = 15_868, 866.70 MHz
  //    channel = 0xD8C000  --> CH = 16_868, 867.00 MHz
  //    channel = 0xE1C51E  --> CH = 00_900, 903.08 MHz
  //    channel = 0xE24F5C  --> CH = 01_900, 905.24 MHz
  //    channel = 0xE2D999  --> CH = 02_900, 907.40 MHz
  //    channel = 0xE363D7  --> CH = 03_900, 909.56 MHz
  //    channel = 0xE3EE14  --> CH = 04_900, 911.72 MHz
  //    channel = 0xE47851  --> CH = 05_900, 913.88 MHz
  //    channel = 0xE5028F  --> CH = 06_900, 916.04 MHz
  //    channel = 0xE58CCC  --> CH = 07_900, 918.20 MHz
  //    channel = 0xE6170A  --> CH = 08_900, 920.36 MHz
  //    channel = 0xE6A147  --> CH = 09_900, 922.52 MHz
  //    channel = 0xE72B85  --> CH = 10_900, 924.68 MHz
  //    channel = 0xE7B5C2  --> CH = 11_900, 926.84 MHz
 
  uint32_t _channel; // Declaration of the channel

  // Variable : output power.
  
  uint8_t _power;               // Declaration of the power

  // Variable : SNR from the last packet received in LoRa mode.
  
  int8_t _SNR;                  // Declaration of the snr

  // Variable : RSSI current value.
  
  int8_t _RSSI;                 // Declaration of the rssi

  // Variable : RSSI from the last packet received in LoRa mode.
  
  int16_t _RSSIpacket;          // Declaration of the rssi packet

  // Variable : preamble length sent/received.
  
  uint16_t _preamblelength;     // Declaration of the preamble length

  // Variable : payload length sent/received.
  
  uint16_t _payloadlength;      // Declaration of the payload length

  // Variable : node address.
  
  uint8_t _nodeAddress;         // Declaration of the node address

  // Variable : implicit or explicit header in LoRa mode.
  
  uint8_t _header;              // Declaration of the header

  // Variable : header received while waiting a packet to arrive.
  
  uint8_t _hreceived;           // Declaration of the h receiver

  // Variable : presence or absence of CRC calculation.
  
  uint8_t _CRC;                 // Declaration of the crc

  // Variable : packet destination.
  
  uint8_t _destination;         // Declaration of the destination

  // Variable : packet number.
  
  uint8_t _packetNumber;        // Declaration of the packet number

  // Variable : indicates if received packet is correct or incorrect.
  
  uint8_t _reception;           // Declaration of the reception

  // Variable : number of current retry.
  
  uint8_t _retries;             // Declaration of the retries

  // Variable : maximum number of retries.
  
  uint8_t _maxRetries;          // Declaration of the max retries

  // Variable : maximum current supply.
  
  uint8_t _maxCurrent;          // Declaration of the max current 

  // Variable : indicates FSK or LoRa 'modem'.
  
  uint8_t _modem;               // Declaration of the modem

  // Variable : array with all the information about a sent packet.
  
  pack packet_sent;             // Declaration of the array for the packet sent

  // Variable : array with all the information about a received packet.
  
  pack packet_received;         // Declaration of the array for the packet received

  // Variable : array with all the information about a sent/received ack.
  
  pack ACK;                     // Declaration of the ACK

  // Structure Variable : Packet payload
  
  uint8_t packet_data[MAX_PAYLOAD];     // Declare the packet data with the max payload
  uint8_t ack_data[2];                  // Declare the ack data with 2

  // Variable : temperature module.
  
  int _temp;                            // Declare the temperature

  // Variable : current timeout to send a packet.
  
  uint16_t _sendTime;                   // Declare the send time
  
private:                                // Private class

    bool _limitToA;                     // Declare the limit ToA
    long _remainingToA;                 // Declare the remaining ToA
    
    unsigned long _startToAcycle;       // Declare to start a cycle
    unsigned long _endToAcycle;         // Declare to end a cycle 
          
    uint16_t _currentToA;               // Permit to know the current ToA
    
};                                      // End of the class

extern SX1272 sx1272;                   // Permit to say that we're using a SX1272



#endif                                  // End of the loop

