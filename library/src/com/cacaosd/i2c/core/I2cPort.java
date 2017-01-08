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

package com.cacaosd.i2c.core;

public class I2cPort {

    /**
     * Constructor
     *
     * @param device_address
     * @param bus
     */
    public I2cPort(byte device_address, byte bus) {
        setBusAddress(bus);
        setDeviceAddress(device_address);
    }

    /**
     * Open I2C connection.
     */
    public native void openConnection();

    /**
     * Set slave device address.
     *
     * @param device_address
     */
    public native void setDeviceAddress(byte device_address);

    /**
     * Get slave device address.
     *
     * @return device_address
     */
    public native byte getDeviceAddress();

    /**
     * Set I2C bus address
     *
     * @param bus
     */
    public native void setBusAddress(byte bus);

    /**
     * Get I2C bus address
     *
     * @return bus
     */
    public native byte getBusAddress();

    /**
     * Write one bit to register which given specific bit number.
     *
     * @param register_address
     * @param data
     * @param bit_no
     */
    public native void writeBit(byte register_address, byte data, byte bit_no);

    /**
     * Write multiple bits to register.
     *
     * @param register_address
     * @param data
     * @param bit_length
     * @param start_bit
     */
    public native void writeMoreBits(byte register_address, byte data,
                                     byte bit_length, byte start_bit);

    /**
     * Write one byte to register.
     *
     * @param register_Address
     * @param data
     */
    public native void writeByte(byte register_Address, byte data);

    /**
     * Write byte array to register.
     *
     * @param register_address
     * @param data
     */
    public native void writeByteBuffer(byte register_address, byte[] data);

    /**
     * Write one byte to Arduino device.
     *
     * @param data
     */
    public native void writeByteArduino(byte data);

    /**
     * Write byte array to Arduino device.
     *
     * @param data
     */
    public native void writeByteBufferArduino(byte[] data);

    /**
     * Read one bit from register which given specific bit number.
     *
     * @param register_address
     * @param bit_no
     * @return
     */
    public native byte readBit(byte register_address, byte bit_no);

    /**
     * Read multiple bits from register.
     *
     * @param register_address
     * @param length
     * @param start_bit
     * @return data type of byte
     */
    public native byte readMoreBits(byte register_address, byte length,
                                    byte start_bit);

    /**
     * Read one byte from register.
     *
     * @param register_address
     * @return data type of byte
     */
    public native byte readByte(byte register_address);

    /**
     * Read byte array from register.
     *
     * @param register_address
     * @param length
     * @return data type of byte
     */
    public native byte[] readByteBuffer(byte register_address, byte length);

    /**
     * Read byte array from Arduino device.
     *
     * @param length
     * @return data type of byte array
     */
    public native byte[] readByteBufferArduino(byte length);

    /**
     * Read one word from register.
     *
     * @param msb_address
     * @param lsb_address
     * @return data type of short
     */
    public native short readWord(byte msb_address, byte lsb_address);

}
