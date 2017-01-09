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
package com.cacaosd.i2c.devices.constants;

public class Mpu6050Constants {

	public static final byte SELF_TEST_X = 0x0D;
	public static final byte SELF_TEST_Y = 0x0E;
	public static final byte SELF_TEST_Z = 0x0F;
	public static final byte SELF_TEST_A = 0x10;
	public static final byte SMPLRT_DIV = 0x19;
	public static final byte CONFIG = 0x1A;
	public static final byte GYRO_CONFIG = 0x1B;
	public static final byte ACCEL_CONFIG = 0x1C;
	public static final byte MOT_THR = 0x1F;
	public static final byte FIFO_EN = 0x23;
	public static final byte I2C_MST_CTRL = 0x24;
	public static final byte I2C_SLV0_ADDR = 0x25;
	public static final byte I2C_SLV0_REG = 0x26;
	public static final byte I2C_SLV0_CTRL = 0x27;
	public static final byte I2C_SLV1_ADDR = 0x28;
	public static final byte I2C_SLV1_REG = 0x29;
	public static final byte I2C_SLV1_CTRL = 0x2A;
	public static final byte I2C_SLV2_ADDR = 0x2B;
	public static final byte I2C_SLV2_REG = 0x2C;
	public static final byte I2C_SLV2_CTRL = 0x2D;
	public static final byte I2C_SLV3_ADDR = 0x2E;
	public static final byte I2C_SLV3_REG = 0x2F;
	public static final byte I2C_SLV3_CTRL = 0x30;
	public static final byte I2C_SLV4_ADDR = 0x31;
	public static final byte I2C_SLV4_REG = 0x32;
	public static final byte I2C_SLV4_DO = 0x33;
	public static final byte I2C_SLV4_CTRL = 0x34;
	public static final byte I2C_SLV4_DI = 0x35;
	public static final byte I2C_MST_STATUS = 0x36;
	public static final byte INT_PIN_CFG = 0x37;
	public static final byte INT_ENABLE = 0x38;
	public static final byte INT_STATUS = 0x3A;
	public static final byte ACCEL_XOUT_H = 0x3B;
	public static final byte ACCEL_XOUT_L = 0x3C;
	public static final byte ACCEL_YOUT_H = 0x3D;
	public static final byte ACCEL_YOUT_L = 0x3E;
	public static final byte ACCEL_ZOUT_H = 0x3F;
	public static final byte ACCEL_ZOUT_L = 0x40;
	public static final byte TEMP_OUT_H = 0x41;
	public static final byte TEMP_OUT_L = 0x42;
	public static final byte GYRO_XOUT_H = 0x43;
	public static final byte GYRO_XOUT_L = 0x44;
	public static final byte GYRO_YOUT_H = 0x45;
	public static final byte GYRO_YOUT_L = 0x46;
	public static final byte GYRO_ZOUT_H = 0x47;
	public static final byte GYRO_ZOUT_L = 0x48;
	public static final byte I2C_SLV0_DO = 0x63;
	public static final byte I2C_SLV1_DO = 0x64;
	public static final byte I2C_SLV2_DO = 0x65;
	public static final byte I2C_SLV3_DO = 0x66;
	public static final byte I2C_MST_DELAY_CTRL = 0x67;
	// public static final byte SIGNAL_PATH_RESET 0x68;
	public static final byte MOT_DETECT_CTRL = 0x69;
	public static final byte USER_CTRL = 0x6A;
	public static final byte PWR_MGMT_1 = 0x6B;
	public static final byte PWR_MGMT_2 = 0x6C;
	public static final byte FIFO_COUNTH = 0x72;
	public static final byte FIFO_COUNTL = 0x73;
	public static final byte FIFO_R_W = 0x74;
	public static final byte WHO_AM_I = 0x75;
	public static final byte DEF_DEV_ADD = 0x68;
	public static final byte AFS_SEL = 0x1C;
	public static final byte FS_SEL = 0x1B;
	public static final byte TEMP_FIFO_EN_BIT = 7;
	public static final byte XG_FIFO_EN_BIT = 6;
	public static final byte YG_FIFO_EN_BIT = 5;
	public static final byte ZG_FIFO_EN_BIT = 4;
	public static final byte ACCEL_FIFO_EN_BIT = 3;
	public static final byte SLV2_FIFO_EN_BIT = 2;
	public static final byte SLV1_FIFO_EN_BIT = 1;
	public static final byte SLV0_FIFO_EN_BIT = 0;
	public static final byte FIFO_EN_BIT = 6;
	public static final byte FIFO_RESET_BIT = 2;
	
}
