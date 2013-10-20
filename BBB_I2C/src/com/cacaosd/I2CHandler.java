package com.cacaosd;

/*
 * Copyright 2013 Cagdas Caglak, cagdascaglak@gmail.com, http://expcodes.blogspot.com/
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
 */

public class I2CHandler {

    private String FULL_PATH = null;
    private String I2C_BUS = null;

    public I2CHandler(String I2C_BUS) {
        this.I2C_BUS = I2C_BUS;

        FULL_PATH = "/dev/i2c-" + I2C_BUS;
    }

    public String getPath() {
        return FULL_PATH;
    }

    public native void initialize();

    public native void writeBit(byte DEV_ADD, byte DATA_REGADD, byte data, byte bitNum);

    public native void writeBits(byte DEV_ADD, byte DATA_REGADD, byte data, byte length, byte startBit);

    public native void writeByte(byte DEV_ADD, byte DATA_REGADD, byte data);

    public native void writeByteBuffer(byte DEV_ADD, byte DATA_REGADD, byte[] data, byte length);

    public native void writeByteArduino(byte DEV_ADD, byte data);

    public native void writeByteBufferArduino(byte DEV_ADD, byte[] data, byte length);

    public native byte readByte(byte DEV_ADD, byte DATA_REGADD);

    public native byte readBit(byte DEV_ADD, byte DATA_REGADD, byte bitNum);

    public native byte readBits(byte DEV_ADD, byte DATA_REGADD, byte length, byte startBit);

    public native void readByteBuffer(byte DEV_ADD, byte DATA_REGADD, byte[] data, byte length);

    public native void readByteBufferArduino(byte DEV_ADD, byte[] data, byte length);

    public native short readWord(byte DEV_ADD, byte MSB, byte LSB);
}
