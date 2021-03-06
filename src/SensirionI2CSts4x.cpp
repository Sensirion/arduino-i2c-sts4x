/*
 * THIS FILE IS AUTOMATICALLY GENERATED
 *
 * I2C-Generator: 0.2.0
 * Yaml Version: 0.1.0
 * Template Version: 0.7.0-12-g6411a7e
 */
/*
 * Copyright (c) 2021, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "SensirionI2CSts4x.h"
#include "Arduino.h"
#include "SensirionCore.h"
#include <Wire.h>

#define STS4X_I2C_ADDRESS _i2c_address

SensirionI2CSts4x::SensirionI2CSts4x() {
}

void SensirionI2CSts4x::begin(TwoWire& i2cBus, uint8_t i2c_address) {
    _i2cBus = &i2cBus;
    _i2c_address = i2c_address;
}

void SensirionI2CSts4x::begin(TwoWire& i2cBus) {
    SensirionI2CSts4x::begin(i2cBus, ADDR_STS4X);
}

uint16_t
SensirionI2CSts4x::measureHighPrecisionTicks(uint16_t& temperatureTicks) {
    uint16_t error;
    uint8_t buffer[3];
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt8Command(0xFD, buffer, 3);

    error = SensirionI2CCommunication::sendFrame(STS4X_I2C_ADDRESS, txFrame,
                                                 *_i2cBus);
    if (error) {
        return error;
    }

    delay(10);

    SensirionI2CRxFrame rxFrame(buffer, 3);
    error = SensirionI2CCommunication::receiveFrame(STS4X_I2C_ADDRESS, 3,
                                                    rxFrame, *_i2cBus);
    if (error) {
        return error;
    }

    error |= rxFrame.getUInt16(temperatureTicks);
    return error;
}

uint16_t SensirionI2CSts4x::measureHighPrecision(float& temperature) {
    uint16_t error;
    uint16_t temperatureTicks;

    error = measureHighPrecisionTicks(temperatureTicks);
    if (error) {
        return error;
    }

    temperature = _convertTicksToCelsius(temperatureTicks);
    return NoError;
}

uint16_t
SensirionI2CSts4x::measureMediumPrecisionTicks(uint16_t& temperatureTicks) {
    uint16_t error;
    uint8_t buffer[3];
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt8Command(0xF6, buffer, 3);

    error = SensirionI2CCommunication::sendFrame(STS4X_I2C_ADDRESS, txFrame,
                                                 *_i2cBus);
    if (error) {
        return error;
    }

    delay(10);

    SensirionI2CRxFrame rxFrame(buffer, 3);
    error = SensirionI2CCommunication::receiveFrame(STS4X_I2C_ADDRESS, 3,
                                                    rxFrame, *_i2cBus);
    if (error) {
        return error;
    }

    error |= rxFrame.getUInt16(temperatureTicks);
    return error;
}

uint16_t SensirionI2CSts4x::measureMediumPrecision(float& temperature) {
    uint16_t error;
    uint16_t temperatureTicks;

    error = measureMediumPrecisionTicks(temperatureTicks);
    if (error) {
        return error;
    }

    temperature = _convertTicksToCelsius(temperatureTicks);
    return NoError;
}

uint16_t
SensirionI2CSts4x::measureLowestPrecisionTicks(uint16_t& temperatureTicks) {
    uint16_t error;
    uint8_t buffer[3];
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt8Command(0xE0, buffer, 3);

    error = SensirionI2CCommunication::sendFrame(STS4X_I2C_ADDRESS, txFrame,
                                                 *_i2cBus);
    if (error) {
        return error;
    }

    delay(10);

    SensirionI2CRxFrame rxFrame(buffer, 3);
    error = SensirionI2CCommunication::receiveFrame(STS4X_I2C_ADDRESS, 3,
                                                    rxFrame, *_i2cBus);
    if (error) {
        return error;
    }

    error |= rxFrame.getUInt16(temperatureTicks);
    return error;
}

uint16_t SensirionI2CSts4x::measureLowestPrecision(float& temperature) {
    uint16_t error;
    uint16_t temperatureTicks;

    error = measureLowestPrecisionTicks(temperatureTicks);
    if (error) {
        return error;
    }

    temperature = _convertTicksToCelsius(temperatureTicks);
    return NoError;
}

uint16_t SensirionI2CSts4x::serialNumber(uint32_t& serialNumber) {
    uint16_t error;
    uint8_t buffer[6];
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt8Command(0x89, buffer, 6);

    error = SensirionI2CCommunication::sendFrame(STS4X_I2C_ADDRESS, txFrame,
                                                 *_i2cBus);
    if (error) {
        return error;
    }

    delay(10);

    SensirionI2CRxFrame rxFrame(buffer, 6);
    error = SensirionI2CCommunication::receiveFrame(STS4X_I2C_ADDRESS, 6,
                                                    rxFrame, *_i2cBus);
    if (error) {
        return error;
    }

    error |= rxFrame.getUInt32(serialNumber);
    return error;
}

uint16_t SensirionI2CSts4x::softReset() {
    uint16_t error;
    uint8_t buffer[1];
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt8Command(0x94, buffer, 1);

    error = SensirionI2CCommunication::sendFrame(STS4X_I2C_ADDRESS, txFrame,
                                                 *_i2cBus);
    delay(10);
    return error;
}

float SensirionI2CSts4x::_convertTicksToCelsius(uint16_t ticks) {
    return static_cast<float>(ticks * 175.0 / 65535.0 - 45.0);
}
