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
package com.cacaosd.i2cjava.examples;

import com.cacaosd.i2cjava.devices.Mpu6050;

public class Mpu6050Example {

	static {
		System.load("/home/ubuntu/I2CJava/jni/libI2CJava.so");
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Mpu6050 mpu = new Mpu6050((byte) 0x68, (byte) 1);
		mpu.initalize();
		short[] accels;

		while (true) {
			accels = mpu.getAccelerations();
			System.out.println("Accel X: " + accels[0] + " Accel Y: "
					+ accels[1] + " Accel Z: " + accels[2]);
		}

	}

}
