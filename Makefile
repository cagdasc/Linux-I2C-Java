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
 
CXX=g++
CXX_INCLUDE=-I$(JAVA_HOME)/include -I/$(JAVA_HOME)/include/linux
SOURCE=jni/I2C.cpp jni/BBB_I2C.cpp
CFLAGS=-shared -fPIC -o
SLIB_OUTPUT=libI2CJava.so

JC=javac
JVM=java
CLASSPATH_FLAGS0=-d bin/
CLASSPATH_FLAGS1=-classpath bin/
SRC_CORE_LIB=src/com/cacaosd/i2cjava/core/I2C.java
SRC_DEV_LIB=src/com/cacaosd/i2cjava/devices/*.java
SRC_MPU6050_EX=src/com/cacaosd/i2cjava/examples/Mpu6050Example.java
EXEC=com.cacaosd.i2cjava.examples.Mpu6050Example

all: $(EXEC)
	@echo "Successful."
run:
	@echo "Running..."
	@$(JVM) $(CLASSPATH_FLAGS1) $(EXEC)

$(SLIB_OUTPUT):
	@echo "Shared library creating..."
	@$(CXX) $(CXX_INCLUDE) $(SOURCE) $(CFLAGS) jni/$(SLIB_OUTPUT)

$(EXEC): $(SLIB_OUTPUT)
	@#javac can not create classpath(bin/) folder
	@mkdir -p bin
	@echo "Java files compiling..."
	@$(JC) $(CLASSPATH_FLAGS0) $(CLASSPATH_FLAGS1) $(SRC_CORE_LIB) $(SRC_DEV_LIB) $(SRC_MPU6050_EX)

clean:
	@echo "Classpath and shared library files removed."
	@rm -rf jni/*.so bin/com