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

#ifndef SENSIRIONI2CSTS4X_H
#define SENSIRIONI2CSTS4X_H

#include <Wire.h>

#include <SensirionCore.h>

class SensirionI2CSts4x {

  public:
    SensirionI2CSts4x();
    /**
     * begin() - Initializes the SensirionI2CSts4x class.
     *
     * @param serial Arduino stream object to be communicated with.
     *
     */
    void begin(TwoWire& i2cBus);

    /**
     * measureHighPrecisionTicks() - SHT4x command for a single shot measurement
     * with high repeatability.
     *
     * @param temperatureTicks Temperature ticks. Convert to degrees celsius by
     * (175 * value / 65535) - 45
     *
     * @return 0 on success, an error code otherwise
     */
    uint16_t measureHighPrecisionTicks(uint16_t& temperatureTicks);

    /**
     * measureHighPrecision() - SHT4x command for a single shot
     * measurement with high repeatability.
     *
     * @param temperature Temperature in degrees celsius.
     *
     * @return 0 on success, an error code otherwise
     */
    uint16_t measureHighPrecision(float& temperature);

    /**
     * measureMediumPrecisionTicks() - SHT4x command for a single shot
     * measurement with medium repeatability.
     *
     * @param temperatureTicks Temperature ticks. Convert to degrees celsius by
     * (175 * value / 65535) - 45
     *
     * @return 0 on success, an error code otherwise
     */
    uint16_t measureMediumPrecisionTicks(uint16_t& temperatureTicks);

    /**
     * measureMediumPrecision() - SHT4x command for a single shot
     * measurement with medium repeatability.
     *
     * @param temperature Temperature in degrees celsius.
     *
     * @return 0 on success, an error code otherwise
     */
    uint16_t measureMediumPrecision(float& temperature);

    /**
     * measureLowestPrecisionTicks() - SHT4x command for a single shot
     * measurement with lowest repeatability.
     *
     * @param temperatureTicks Temperature ticks. Convert to degrees celsius by
     * (175 * value / 65535) - 45
     *
     * @return 0 on success, an error code otherwise
     */
    uint16_t measureLowestPrecisionTicks(uint16_t& temperatureTicks);

    /**
     * measureLowestPrecision() - SHT4x command for a single shot
     * measurement with lowest repeatability.
     *
     * @param temperature Temperature in degrees celsius.
     *
     * @return 0 on success, an error code otherwise
     */
    uint16_t measureLowestPrecision(float& temperature);

    /**
     * serialNumber() - Read out the serial number
     *
     * @note Each sensor has a unique serial number that is assigned by
     * Sensirion during production. It is stored in the one-time-programmable
     * memory and cannot be manipulated after production.
     *
     * @param serialNumber Unique serial number
     *
     * @return 0 on success, an error code otherwise
     */
    uint16_t serialNumber(uint32_t& serialNumber);

    /**
     * softReset() - Perform a soft reset.
     *
     * @note A reset of the sensor can be achieved in three ways: By perform a
     * soft reset using this function, by using an I2C general call, at which
     * all devices on the I2C bus will be reset, or by a power down (incl.
     * pulling SCL and SDA low). See the datasheet for more detailed
     * information.
     *
     * @return 0 on success, an error code otherwise
     */
    uint16_t softReset(void);

  private:
    TwoWire* _i2cBus = nullptr;
    float _convertTicksToCelsius(uint16_t ticks);
};

#endif /* SENSIRIONI2CSTS4X_H */
