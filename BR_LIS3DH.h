/*
 * ***************************************************************************
 * Component:    LIS3DH - Accelerometer
 * Manufacturer: Adafruit
 * Product:      LIS3DH - Triple-Axis Accelerometer (+-2g/4g/8g/16g)
 * Product ID:   2809
 *
 * Product Page:
 *     https://www.adafruit.com/product/2809
 *
 * Datasheet:
 *     https://www.st.com/en/mems-and-sensors/lis3dh.html
 *
 * ***************************************************************************
 */

#ifndef BR_LIS3DH_H
#define BR_LIS3DH_H

#include <Arduino.h>




class BR_LIS3DH {
    public:
        static constexpr uint8_t I2C_ADR = 0x18;


        /* LIS3DH Registers */

        // Identification & Auxiliary ADC
        static constexpr uint8_t STATUS_REG_AUX = 0x07;
        static constexpr uint8_t OUT_ADC1_L = 0x08;
        static constexpr uint8_t OUT_ADC1_H = 0x09;
        static constexpr uint8_t OUT_ADC2_L = 0x0A;
        static constexpr uint8_t OUT_ADC2_H = 0x0B;
        static constexpr uint8_t OUT_ADC3_L = 0x0C;
        static constexpr uint8_t OUT_ADC3_H = 0x0D;
        static constexpr uint8_t WHO_AM_I = 0x0F;
        static constexpr uint8_t CTRL_REG0 = 0x1E;
        static constexpr uint8_t TEMP_CFG_REG = 0x1F;

        // Core Control & Filtering
        static constexpr uint8_t CTRL_REG1 = 0x20;
        static constexpr uint8_t CTRL_REG2 = 0x21;
        static constexpr uint8_t CTRL_REG3 = 0x22;
        static constexpr uint8_t CTRL_REG4 = 0x23;
        static constexpr uint8_t CTRL_REG5 = 0x24;
        static constexpr uint8_t CTRL_REG6 = 0x25;
        static constexpr uint8_t REFERENCE = 0x26;

        // Acceleration Data Output
        static constexpr uint8_t STATUS_REG = 0x27;
        static constexpr uint8_t OUT_X_L = 0x28;
        static constexpr uint8_t OUT_X_H = 0x29;
        static constexpr uint8_t OUT_Y_L = 0x2A;
        static constexpr uint8_t OUT_Y_H = 0x2B;
        static constexpr uint8_t OUT_Z_L = 0x2C;
        static constexpr uint8_t OUT_Z_H = 0x2D;

        // FIFO Buffer Control
        static constexpr uint8_t FIFO_CTRL_REG = 0x2E;
        static constexpr uint8_t FIFO_SRC_REG = 0x2F;

        // Interrupt Generators 1 & 2
        static constexpr uint8_t INT1_CFG = 0x30;
        static constexpr uint8_t INT1_SRC = 0x31;
        static constexpr uint8_t INT1_THS = 0x32;
        static constexpr uint8_t INT1_DURATION = 0x33;
        static constexpr uint8_t INT2_CFG = 0x34;
        static constexpr uint8_t INT2_SRC = 0x35;
        static constexpr uint8_t INT2_THS = 0x36;
        static constexpr uint8_t INT2_DURATION = 0x37;

        // Click / Tap & Sleep-to-Wake
        static constexpr uint8_t CLICK_CFG = 0x38;
        static constexpr uint8_t CLICK_SRC = 0x39;
        static constexpr uint8_t CLICK_THS = 0x3A;
        static constexpr uint8_t TIME_LIMIT = 0x3B;
        static constexpr uint8_t TIME_LATENCY = 0x3C;
        static constexpr uint8_t TIME_WINDOW = 0x3D;
        static constexpr uint8_t ACT_THS = 0x3E;
        static constexpr uint8_t ACT_DUR = 0x3F;


        // Constructor
        BR_LIS3DH(uint8_t i2c_address = 0x18);

        // Initialization
        void begin();

        // Acceleration Readings
        void readAcceleration();
        float getAccelerationX();
        float getAccelerationY();
        float getAccelerationZ();

    private:

        // Configuration
        uint8_t _i2c_address;

        // Acceleration Data
        int16_t _raw_x = 0;
        int16_t _raw_y = 0;
        int16_t _raw_z = 0;

        // Register Communication
        uint8_t readRegister(uint8_t reg);
        void writeRegister(uint8_t reg, uint8_t data);
        
};

#endif
