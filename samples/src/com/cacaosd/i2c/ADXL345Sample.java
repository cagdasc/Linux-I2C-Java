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
package com.cacaosd.i2c;

import com.cacaosd.i2c.devices.ADXL345;

import static com.cacaosd.i2c.devices.constants.ADXL345Constants.ADXL345_DEFAULT_ADDRESS;

public class ADXL345Sample {

    static {
        String absolutePath = System.getProperty("java.library.path");
        System.load(absolutePath + "/libi2cport.so");
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        ADXL345 adxl345 = new ADXL345(ADXL345_DEFAULT_ADDRESS, (byte) 2);
        adxl345.initialize();
        short[] accels;

        while (true) {
            accels = adxl345.getAccelerations();
            System.out.println("Accel X: " + accels[0]);
            System.out.println("Accel Y: " + accels[1]);
            System.out.println("Accel Z: " + accels[2]);
            System.out.println("-----------------");
            try {
                Thread.sleep(200);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }

    }
}
