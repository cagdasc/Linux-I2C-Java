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
/*
 * Chages
 * Add Javadoc - 24/10/2013
 */
/**
 *
 * @author Cagdas Caglak
 * @version 0.9.2
 */
public class I2CHandler {

    private String FULL_PATH = null;
    private String I2C_BUS = null;

    /**
     * Constructor for choose the i2c bus number.For Example: BeagleBone Black
     * has two i2c buses (i2c-0 and i2c-1).
     *
     * @param I2C_BUS
     */
    public I2CHandler(String I2C_BUS) {
        this.I2C_BUS = I2C_BUS;

        FULL_PATH = "/dev/i2c-" + I2C_BUS;
    }

    /**
     * For get path of the i2c bus. This method necessary for find i2c path in
     * JNI methods.
     *
     * @return FULL_PATH of the i2c devices.
     */
    public String getPath() {
        return FULL_PATH;
    }

    /**
     * Initialize to i2c path.
     */
    public native void initialize();

    /**
     *
     * @param DEV_ADD Slave device address.
     * @param DATA_REGADD Slave device register address which for use writing.
     * @param data Writing data.
     * @param bitNum Number of the bit used to write.
     */
    public native void writeBit(byte DEV_ADD, byte DATA_REGADD, byte data, byte bitNum);

    /**
     *
     * @param DEV_ADD Slave device address.
     * @param DATA_REGADD Slave device register address which for use writing.
     * @param data Writing data.
     * @param length Length of the bits used to write in data.
     * @param startBit Start bit number in data register.
     */
    public native void writeBits(byte DEV_ADD, byte DATA_REGADD, byte data, byte length, byte startBit);

    /**
     *
     * @param DEV_ADD Slave device address.
     * @param DATA_REGADD Slave device register address which for use writing.
     * @param data Writing data.
     */
    public native void writeByte(byte DEV_ADD, byte DATA_REGADD, byte data);

    /**
     *
     * @param DEV_ADD Slave device address.
     * @param DATA_REGADD Slave device register address which for use writing.
     * @param data Writing data array.
     * @param length Length of the array used to write.
     */
    public native void writeByteBuffer(byte DEV_ADD, byte DATA_REGADD, byte[] data, byte length);

    /**
     *
     * @param DEV_ADD Address of the connected Arduino device.
     * @param data Writing data.
     */
    public native void writeByteArduino(byte DEV_ADD, byte data);

    /**
     *
     * @param DEV_ADD Address of the connected Arduino device.
     * @param data Writing data array.
     * @param length Length of the array used to write.
     */
    public native void writeByteBufferArduino(byte DEV_ADD, byte[] data, byte length);

    /**
     *
     * @param DEV_ADD Slave device address.
     * @param DATA_REGADD Slave device register address which for use reading.
     * @return One byte reading from the device.
     */
    public native byte readByte(byte DEV_ADD, byte DATA_REGADD);

    /**
     *
     * @param DEV_ADD Slave device address.
     * @param DATA_REGADD Slave device register address which for use reading.
     * @param bitNum Number of the bit which want to read.
     * @return 0 or 1.
     */
    public native byte readBit(byte DEV_ADD, byte DATA_REGADD, byte bitNum);

    /**
     *
     * @param DEV_ADD Slave device address.
     * @param DATA_REGADD Slave device register address which for use reading.
     * @param length Length of the bits used to read in data.
     * @param startBit Start bit number in data register.
     * @return One byte reading from the device. Between the 0 - 2 ^ length.
     */
    public native byte readBits(byte DEV_ADD, byte DATA_REGADD, byte length, byte startBit);

    /**
     *
     * @param DEV_ADD Slave device address.
     * @param DATA_REGADD Slave device register address which for use reading.
     * @param data Reading data array.
     * @param length Length of the array used to reading.
     */
    public native void readByteBuffer(byte DEV_ADD, byte DATA_REGADD, byte[] data, byte length);

    /**
     *
     * @param DEV_ADD Address of the connected Arduino device.
     * @param data Reading data array.
     * @param length Length of the array used to reading.
     */
    public native void readByteBufferArduino(byte DEV_ADD, byte[] data, byte length);

    /**
     *
     * @param DEV_ADD Slave device address.
     * @param MSB High data register address in device.
     * @param LSB Low data register address in device.
     * @return One short reading from the device.
     */
    public native short readWord(byte DEV_ADD, byte MSB, byte LSB);
}
