 #Copyright (C) 2014  Cagdas Caglak http://expcodes.blogspot.com.tr/

 #This program is free software: you can redistribute it and/or modify
 #it under the terms of the GNU General Public License as published by
 #the Free Software Foundation, either version 3 of the License, or
 #(at your option) any later version.

 #This program is distributed in the hope that it will be useful,
 #but WITHOUT ANY WARRANTY; without even the implied warranty of
 #MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 #GNU General Public License for more details.

 #You should have received a copy of the GNU General Public License
 #along with this program.  If not, see <http://www.gnu.org/licenses/>.

JC=javac
JVM=java
CXX=g++
CXX_INCLUDE=-I$(JAVA_HOME)/include -I/$(JAVA_HOME)/include/linux
SOURCE=library/jni/I2cPortJava.cpp library/jni/I2cPort.cpp

CFLAGS=-shared -fPIC -o
SLIB_OUTPUT=libi2cport.so
SLIB_PATH=`pwd`/library/jni/
CLASSPATH_FLAGS0=-d bin/
CLASSPATH_FLAGS1=-classpath bin/

SRC_CORE_LIB=library/src/com/cacaosd/i2c/core/I2cPort.java
SRC_DEV_LIB=library/src/com/cacaosd/i2c/devices/*.java
SRC_MPU6050_EX=samples/src/com/cacaosd/i2c/Mpu6050Sample.java

COMPILE=Compile
MPU6050_EXEC=com.cacaosd.i2c.Mpu6050Sample

all: $(COMPILE)
	@echo "Successful."

run:
	@echo "Running..."
	@echo "java library path="$(SLIB_PATH)
	@$(JVM) -Djava.library.path=$(SLIB_PATH) $(CLASSPATH_FLAGS1) $(MPU6050_EXEC)

$(COMPILE): $(SLIB_OUTPUT)
	@mkdir -p bin
	@echo "Java files compiling..."
	@$(JC) $(CLASSPATH_FLAGS0) $(CLASSPATH_FLAGS1) $(SRC_CORE_LIB) $(SRC_DEV_LIB) $(SRC_MPU6050_EX)

$(SLIB_OUTPUT):
	@echo "Shared library creating..."
	@$(CXX) $(CXX_INCLUDE) $(SOURCE) $(CFLAGS) library/jni/$(SLIB_OUTPUT)

clean:
	@echo "Classpath and shared library files removed."
	@rm -rf library/jni/*.so bin/*
