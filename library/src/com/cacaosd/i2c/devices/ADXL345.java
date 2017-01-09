/*
 * Copyright (C) 2017  Cagdas Caglak cagdascaglak@gmail.com
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package com.cacaosd.i2c.devices;

import com.cacaosd.i2c.core.I2cPort;

import static com.cacaosd.i2c.devices.constants.ADXL345Constants.*;

public class ADXL345 {

    private I2cPort i2cPort;

    public ADXL345(byte deviceAddress, byte bus) {
        i2cPort = new I2cPort(deviceAddress, bus);
    }

    public byte getDeviceAddress() {
        return i2cPort.getDeviceAddress();
    }

    public void setDeviceAddress(byte deviceAddress) {
        i2cPort.setDeviceAddress(deviceAddress);
    }

    public void initialize() {
        i2cPort.writeByte(ADXL345_RA_POWER_CTL, (byte) 0);
        setAutoSleepEnabled(true);
        setMeasureEnabled(true);
    }

    public boolean getAutoSleepEnabled() {
        return i2cPort.readBit(ADXL345_RA_POWER_CTL, ADXL345_PCTL_AUTOSLEEP_BIT) == 1;
    }

    public void setAutoSleepEnabled(boolean autoSleepEnabled) {
        i2cPort.writeBit(ADXL345_RA_POWER_CTL, (byte) (autoSleepEnabled ? 1 : 0), ADXL345_PCTL_AUTOSLEEP_BIT);
    }

    public boolean getMeasureEnabled() {
        return i2cPort.readBit(ADXL345_RA_POWER_CTL, ADXL345_PCTL_MEASURE_BIT) == 1;
    }

    public void setMeasureEnabled(boolean measureEnabled) {
        i2cPort.writeBit(ADXL345_RA_POWER_CTL, (byte) (measureEnabled ? 1 : 0), ADXL345_PCTL_MEASURE_BIT);
    }

    public short getAccelerationX() {
        return i2cPort.readWord(ADXL345_RA_DATAX1, ADXL345_RA_DATAX0);
    }

    public short getAccelerationY() {
        return i2cPort.readWord(ADXL345_RA_DATAY1, ADXL345_RA_DATAY0);
    }

    public short getAccelerationZ() {
        return i2cPort.readWord(ADXL345_RA_DATAZ1, ADXL345_RA_DATAZ0);
    }

    public short[] getAccelerations() {
        short[] accels = new short[3];
        accels[0] = i2cPort.readWord(ADXL345_RA_DATAX1, ADXL345_RA_DATAX0);
        accels[1] = i2cPort.readWord(ADXL345_RA_DATAY1, ADXL345_RA_DATAY0);
        accels[2] = i2cPort.readWord(ADXL345_RA_DATAZ1, ADXL345_RA_DATAZ0);
        return accels;
    }
}
