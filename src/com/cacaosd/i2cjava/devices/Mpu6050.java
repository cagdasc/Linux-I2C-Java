/*
 Copyright (C) 2014  Cagdas Caglak cagdascaglak@gmail.com http://expcodes.blogspot.com.tr/

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package com.cacaosd.i2cjava.devices;

import com.cacaosd.i2cjava.core.I2C;

public class Mpu6050 extends I2C {

	private boolean actionMode;

	public Mpu6050(byte device_address, byte bus) {
		super(device_address, bus);
		// TODO Auto-generated constructor stub
		this.actionMode = true;
	}

	void setActionMode(boolean actionMode) {
		this.actionMode = actionMode;
	}

	boolean getActionMode() {
		return actionMode;
	}

	public void setDeviceAddress(byte DEV_ADD) {
		super.setDeviceAddress(DEV_ADD);
	}

	public byte getDeviceAddress() {
		return super.getDeviceAddress();
	}

	public void initalize() {
		setSleepMode(false);
		setRangeAcceleration((byte) 0);
		setRangeGyroscope((byte) 0);
	}

	public void setSleepMode(boolean mode) {
		byte var = readByte(Mpu6050Helper.PWR_MGMT_1);
		if (mode) {
			var |= 64;
		} else {
			var &= ~64;
		}
		writeByte(Mpu6050Helper.PWR_MGMT_1, var);
	}

	public boolean getSleepMode() {
		byte var = readByte(Mpu6050Helper.PWR_MGMT_1);
		var >>= 6;
		var %= 2;
		if (var == 1) {
			return true;
		} else {
			return false;
		}
	}

	public void setRangeAcceleration(byte range) {
		byte afs = readByte(Mpu6050Helper.ACCEL_CONFIG);
		if (range == 0) {
			afs &= ~24;
		} else if (range == 1) {
			afs |= 8;
			afs &= ~16;
		} else if (range == 2) {
			afs &= ~8;
			afs |= 16;
		} else {
			afs |= 24;
		}
		writeByte(Mpu6050Helper.ACCEL_CONFIG, afs);
	}

	public byte getRangeAcceleration() {
		byte afs = readByte(Mpu6050Helper.ACCEL_CONFIG);
		afs >>= 3;
		afs %= 4;
		return afs;
	}

	public void setRangeGyroscope(byte range) {
		byte fs = readByte(Mpu6050Helper.GYRO_CONFIG);
		if (range == 0) {
			fs &= ~24;
		} else if (range == 1) {
			fs |= 8;
			fs &= ~16;
		} else if (range == 2) {
			fs &= ~8;
			fs |= 16;
		} else {
			fs |= 24;
		}
		writeByte(Mpu6050Helper.GYRO_CONFIG, fs);
	}

	public byte getRangeGyroscope() {
		byte fs = readByte(Mpu6050Helper.GYRO_CONFIG);
		fs >>= 3;
		fs %= 4;
		return fs;
	}

	public short[] getAccelerations() {
		short[] accels = new short[3];
		accels[0] = readWord(Mpu6050Helper.ACCEL_XOUT_H,
				Mpu6050Helper.ACCEL_XOUT_L);
		accels[1] = readWord(Mpu6050Helper.ACCEL_YOUT_H,
				Mpu6050Helper.ACCEL_YOUT_L);
		accels[2] = readWord(Mpu6050Helper.ACCEL_ZOUT_H,
				Mpu6050Helper.ACCEL_ZOUT_L);
		return accels;
	}

	public short getAccelerationX() {
		return readWord(Mpu6050Helper.ACCEL_XOUT_H,
				Mpu6050Helper.ACCEL_XOUT_L);
	}

	public short getAccelerationY() {
		return readWord(Mpu6050Helper.ACCEL_YOUT_H,
				Mpu6050Helper.ACCEL_YOUT_L);
	}

	public short getAccelerationZ() {
		return readWord(Mpu6050Helper.ACCEL_ZOUT_H,
				Mpu6050Helper.ACCEL_ZOUT_L);
	}

	public short[] getAngularVelocities() {
		short[] velocities = new short[3];
		velocities[0] = readWord(Mpu6050Helper.GYRO_XOUT_H,
				Mpu6050Helper.GYRO_XOUT_L);
		velocities[1] = readWord(Mpu6050Helper.GYRO_YOUT_H,
				Mpu6050Helper.GYRO_YOUT_L);
		velocities[2] = readWord(Mpu6050Helper.GYRO_ZOUT_H,
				Mpu6050Helper.GYRO_ZOUT_L);
		return velocities;
	}

	public short getAngularVelocityX() {
		return readWord(Mpu6050Helper.GYRO_XOUT_H,
				Mpu6050Helper.GYRO_XOUT_L);
	}

	public short getAngularVelocityY() {
		return readWord(Mpu6050Helper.GYRO_YOUT_H,
				Mpu6050Helper.GYRO_YOUT_L);
	}

	public short getAngularVelocityZ() {
		return readWord(Mpu6050Helper.GYRO_ZOUT_H,
				Mpu6050Helper.GYRO_ZOUT_L);
	}

	public short getTemperature() {
		return readWord(Mpu6050Helper.TEMP_OUT_H,
				Mpu6050Helper.TEMP_OUT_L);
	}

	public short[] getMotion6() {
		short[] motion6 = new short[6];
		motion6[0] = readWord(Mpu6050Helper.ACCEL_XOUT_H,
				Mpu6050Helper.ACCEL_XOUT_L);
		motion6[1] = readWord(Mpu6050Helper.ACCEL_YOUT_H,
				Mpu6050Helper.ACCEL_YOUT_L);
		motion6[2] = readWord(Mpu6050Helper.ACCEL_ZOUT_H,
				Mpu6050Helper.ACCEL_ZOUT_L);
		motion6[3] = readWord(Mpu6050Helper.GYRO_XOUT_H,
				Mpu6050Helper.GYRO_XOUT_L);
		motion6[4] = readWord(Mpu6050Helper.GYRO_YOUT_H,
				Mpu6050Helper.GYRO_YOUT_L);
		motion6[5] = readWord(Mpu6050Helper.GYRO_ZOUT_H,
				Mpu6050Helper.GYRO_ZOUT_L);
		return motion6;
	}

	public void setDLPFMode(byte mode) {
		byte config = readByte(Mpu6050Helper.CONFIG);
		if (mode == 0) {
			config &= ~7;
		} else if (mode == 1) {
			config |= 1;
			config &= ~6;
		} else if (mode == 2) {
			config |= 2;
			config &= ~5;
		} else if (mode == 3) {
			config |= 3;
			config &= ~4;
		} else if (mode == 4) {
			config |= 4;
			config &= ~3;
		} else if (mode == 5) {
			config |= 5;
			config &= ~2;
		} else if (mode == 6) {
			config |= 6;
			config &= ~1;
		} else if (mode == 7) {
			config |= 7;
		}
		writeByte(Mpu6050Helper.CONFIG, config);
	}

	public byte getDLPFMode() {
		byte config = readByte(Mpu6050Helper.CONFIG);
		return config %= 8;
	}

	public void setSampleRate(byte rate) {
		writeByte(Mpu6050Helper.SMPLRT_DIV, rate);
	}

	public byte getSampleRate() {
		return readByte(Mpu6050Helper.SMPLRT_DIV);
	}

	public void setMotionDetectionThresold(byte value) {
		writeByte(Mpu6050Helper.MOT_THR, value);
	}

	public byte getMotionDecetionThresold() {
		return readByte(Mpu6050Helper.MOT_THR);
	}

	public void setTEMP_FIFO_EN(byte value) {
		writeBit(Mpu6050Helper.FIFO_EN, value,
				Mpu6050Helper.TEMP_FIFO_EN_BIT);
	}

	public byte getTEMP_FIFO_EN() {
		return readBit(Mpu6050Helper.FIFO_EN,
				Mpu6050Helper.TEMP_FIFO_EN_BIT);
	}

	public void setXG_FIFO_EN(byte value) {
		writeBit(Mpu6050Helper.FIFO_EN, value,
				Mpu6050Helper.XG_FIFO_EN_BIT);
	}

	public byte getXG_FIFO_EN() {
		return readBit(Mpu6050Helper.FIFO_EN,
				Mpu6050Helper.XG_FIFO_EN_BIT);
	}

	public void setYG_FIFO_EN(byte value) {
		writeBit(Mpu6050Helper.FIFO_EN, value,
				Mpu6050Helper.YG_FIFO_EN_BIT);
	}

	public byte getYG_FIFO_EN() {
		return readBit(Mpu6050Helper.FIFO_EN,
				Mpu6050Helper.YG_FIFO_EN_BIT);
	}

	public void setZG_FIFO_EN(byte value) {
		writeBit(Mpu6050Helper.FIFO_EN, value,
				Mpu6050Helper.ZG_FIFO_EN_BIT);
	}

	public byte getZG_FIFO_EN() {
		return readBit(Mpu6050Helper.FIFO_EN,
				Mpu6050Helper.ZG_FIFO_EN_BIT);
	}

	public void setACCEL_FIFO_EN(byte value) {
		writeBit(Mpu6050Helper.FIFO_EN, value,
				Mpu6050Helper.ACCEL_FIFO_EN_BIT);
	}

	public byte getACCEL_FIFO_EN() {
		return readBit(Mpu6050Helper.FIFO_EN,
				Mpu6050Helper.ACCEL_FIFO_EN_BIT);
	}

	public void setSLV2_FIFO_EN(byte value) {
		writeBit(Mpu6050Helper.FIFO_EN, value,
				Mpu6050Helper.SLV2_FIFO_EN_BIT);
	}

	public byte getSLV2_FIFO_EN() {
		return readBit(Mpu6050Helper.FIFO_EN,
				Mpu6050Helper.SLV2_FIFO_EN_BIT);
	}

	public void setSLV1_FIFO_EN(byte value) {
		writeBit(Mpu6050Helper.FIFO_EN, value,
				Mpu6050Helper.SLV1_FIFO_EN_BIT);
	}

	public byte getSLV1_FIFO_EN() {
		return readBit(Mpu6050Helper.FIFO_EN,
				Mpu6050Helper.SLV1_FIFO_EN_BIT);
	}

	public void setSLV0_FIFO_EN(byte value) {
		writeBit(Mpu6050Helper.FIFO_EN, value,
				Mpu6050Helper.SLV0_FIFO_EN_BIT);
	}

	public byte getSLV0_FIFO_EN() {
		return readBit(Mpu6050Helper.FIFO_EN,
				Mpu6050Helper.SLV0_FIFO_EN_BIT);
	}

	public short getFIFO_Count() {
		return readWord(Mpu6050Helper.FIFO_COUNTH,
				Mpu6050Helper.FIFO_COUNTL);
	}

	public void setFIFO_Enable(byte value) {
		writeBit(Mpu6050Helper.USER_CTRL, value,
				Mpu6050Helper.FIFO_EN_BIT);
	}

	public byte getFIFO_Enable() {
		return readBit(Mpu6050Helper.USER_CTRL, Mpu6050Helper.FIFO_EN_BIT);
	}

	public byte[] getFIFO_Data(byte length) {
		return readByteBuffer(Mpu6050Helper.FIFO_R_W, length);
	}

	public void setFIFO_Reset(byte value) {
		writeBit(Mpu6050Helper.USER_CTRL, value,
				Mpu6050Helper.FIFO_RESET_BIT);
	}

	public byte getFIFO_Reset() {
		return readBit(Mpu6050Helper.USER_CTRL,
				Mpu6050Helper.FIFO_RESET_BIT);
	}
}
