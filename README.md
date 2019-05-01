Linux-I2C-Java
===========================
This native library written for Linux Systems. This library include JNI(java Native Interface) implementation. Find native library in this [repo](https://github.com/cagdasc/Linux-I2C).
You can use I2C interface for your Java applications with this library.
It's not fully tested but You can find a simple samples for Mpu6050 and ADXL345.

**Warning:** It's only experimental, not in use production.

**NOTE:** Library is developing and other devices will be added.

**Important Note:** You need to set JAVA_HOME environment variable.

#Usage

	make clean
	make all
	make runMpu6050
	make runAdxl345

#License

	Copyright (C) 2017  Cagdas Caglak cagdascaglak@gmail.com

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
