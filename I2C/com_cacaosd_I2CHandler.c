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

#include <jni.h>
#include <stdio.h>
#include "com_cacaosd_I2CHandler.h"

JNIEXPORT void JNICALL Java_com_cacaosd_I2CHandler_initialize
(JNIEnv *env, jobject obj) {

    jclass cls = (*env)->GetObjectClass(env, obj);
    jmethodID methId = (*env)->GetMethodID(env, cls, "getPath", "()Ljava/lang/String;");
    jstring str = (jstring) (*env)->CallObjectMethod(env, obj, methId);
    path = (*env)->GetStringUTFChars(env, str, 0);
    
    //(*env)->ReleaseStringUTFChars(env, str, path);
}

JNIEXPORT void JNICALL Java_com_cacaosd_I2CHandler_writeBit
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyte DATA_REGADD, jbyte data, jbyte bitNum) {

    int8_t temp = Java_com_cacaosd_I2CHandler_readByte(env, obj, DEV_ADD, DATA_REGADD);
    if (data == 0) {
        temp = temp & ~(1 << bitNum);
    } else if (data == 1) {
        temp = temp | (1 << bitNum);
    } else {
        printf("Value must be 0 or 1! --> Address %d.\n", DEV_ADD);
    }

    Java_com_cacaosd_I2CHandler_writeByte(env, obj, DEV_ADD, DATA_REGADD, temp);
}

JNIEXPORT void JNICALL Java_com_cacaosd_I2CHandler_writeBits
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyte DATA_REGADD, jbyte data, jbyte length, jbyte startBit) {
    int8_t temp = Java_com_cacaosd_I2CHandler_readByte(env, obj, DEV_ADD, DATA_REGADD);
    uint8_t bits = 1;
    uint8_t i = 0;

    while (i < length - 1) {
        bits = (bits << 1);
        ++bits;
        ++i;
    }

    temp &= ~(bits << startBit);

    temp |= (data << startBit);

    Java_com_cacaosd_I2CHandler_writeByte(env, obj, DEV_ADD, DATA_REGADD, temp);
}

JNIEXPORT void JNICALL Java_com_cacaosd_I2CHandler_writeByte
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyte DATA_REGADD, jbyte data) {
    int file;

    if ((file = open(path, O_RDWR)) < 0) {
        printf("%s do not open. Address %d.\n", path, DEV_ADD);
        exit(1);
    }

    if (ioctl(file, I2C_SLAVE, DEV_ADD) < 0) {
        printf("Can not join I2C Bus. Address %d.\n", DEV_ADD);
        exit(1);
    }

    uint8_t buffer[2];

    buffer[0] = DATA_REGADD;
    buffer[1] = data;

    if (write(file, buffer, 2) != 2) {
        printf("Can not write data. Address %d.\n", DEV_ADD);
        exit(1);
    }

    close(file);

}

JNIEXPORT void JNICALL Java_com_cacaosd_I2CHandler_writeByteBuffer
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyte DATA_REGADD, jbyteArray data, jbyte length) {
    jbyte *data_ar = (*env)->GetByteArrayElements(env, data, JNI_FALSE);

    int file;

    if ((file = open(path, O_RDWR)) < 0) {
        printf("%s do not open. Address %d.\n", path, DEV_ADD);
        exit(1);
    }

    if (ioctl(file, I2C_SLAVE, DEV_ADD) < 0) {
        printf("Can not join I2C Bus. Address %d.\n", DEV_ADD);
        exit(1);
    }

    uint8_t buffer[1];
    buffer[0] = DATA_REGADD;

    if (write(file, buffer, 1) != 1) {
        printf("Can not write data. Address %d.\n", DEV_ADD);
        exit(1);
    }

    if (write(file, data_ar, length) != length) {
        printf("Can not write data. Address %d.\n", DEV_ADD);
        exit(1);
    }

    close(file);

    (*env)->ReleaseByteArrayElements(env, data, data_ar, JNI_ABORT);
}

JNIEXPORT void JNICALL Java_com_cacaosd_I2CHandler_writeByteArduino
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyte data) {
    int file;

    if ((file = open(path, O_RDWR)) < 0) {
        printf("%s do not open. Address %d.\n", path, DEV_ADD);
        exit(1);
    }

    if (ioctl(file, I2C_SLAVE, DEV_ADD) < 0) {
        printf("Can not join I2C Bus. Address %d.\n", DEV_ADD);
        exit(1);
    }

    int8_t buffer[1];
    buffer[0] = data;

    if (write(file, buffer, 1) != 1) {
        printf("Can not write data. Address %d.\n", DEV_ADD);
        exit(1);
    }

    close(file);
}

JNIEXPORT void JNICALL Java_com_cacaosd_I2CHandler_writeByteBufferArduino
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyteArray data, jbyte length) {
    jbyte *data_ar = (*env)->GetByteArrayElements(env, data, JNI_FALSE);

    int file;

    if ((file = open(path, O_RDWR)) < 0) {
        printf("%s do not open. Address %d.\n", path, DEV_ADD);
        exit(1);
    }

    if (ioctl(file, I2C_SLAVE, DEV_ADD) < 0) {
        printf("Can not join I2C Bus. Address %d.\n", DEV_ADD);
        exit(1);
    }

    if (write(file, data_ar, length) != length) {
        printf("Can not write data. Address %d.\n", DEV_ADD);
        exit(1);
    }

    close(file);

    (*env)->ReleaseByteArrayElements(env, data, data_ar, JNI_ABORT);
}

JNIEXPORT jbyte JNICALL Java_com_cacaosd_I2CHandler_readByte
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyte DATA_REGADD) {
    int file;

    if ((file = open(path, O_RDWR)) < 0) {
        printf("%s do not open. Address %d.\n", path, DEV_ADD);
    }

    if (ioctl(file, I2C_SLAVE, DEV_ADD) < 0) {
        printf("Can not join I2C Bus. Address %d.\n", DEV_ADD);
    }

    uint8_t buffer[1];
    buffer[0] = DATA_REGADD;

    if (write(file, buffer, 1) != 1) {
        printf("Can not write data. Address %d.\n", DEV_ADD);
    }

    uint8_t value[1];

    if (read(file, value, 1) != 1) {
        printf("Can not read data. Address %d.\n", DEV_ADD);
    }

    close(file);

    return value[0];
}

JNIEXPORT jbyte JNICALL Java_com_cacaosd_I2CHandler_readBit
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyte DATA_REGADD, jbyte bitNum) {
    int8_t temp = Java_com_cacaosd_I2CHandler_readByte(env, obj, DEV_ADD, DATA_REGADD);
    return (temp >> bitNum) % 2;
}

JNIEXPORT jbyte JNICALL Java_com_cacaosd_I2CHandler_readBits
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyte DATA_REGADD, jbyte length, jbyte startBit) {
    int8_t temp = Java_com_cacaosd_I2CHandler_readByte(env, obj, DEV_ADD, DATA_REGADD);
    return (temp >> startBit) % (uint8_t) pow(2, length);
}

JNIEXPORT void JNICALL Java_com_cacaosd_I2CHandler_readByteBuffer
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyte DATA_REGADD, jbyteArray data, jbyte length) {
    jbyte *data_ar = (*env)->GetByteArrayElements(env, data, JNI_FALSE);

    int file;

    if ((file = open(path, O_RDWR)) < 0) {
        printf("%s do not open. Address %d.\n", path, DEV_ADD);
    }

    if (ioctl(file, I2C_SLAVE, DEV_ADD) < 0) {
        printf("Can not join I2C Bus. Address %d.\n", DEV_ADD);
    }

    uint8_t buffer[1];
    buffer[0] = DATA_REGADD;

    if (write(file, buffer, 1) != 1) {
        printf("Can not write data. Address %d.\n", DEV_ADD);
    }

    if (read(file, data_ar, length) != length) {
        printf("Can not read data. Address %d.\n", DEV_ADD);
    }

    close(file);

    (*env)->ReleaseByteArrayElements(env, data, data_ar, JNI_ABORT);
}

JNIEXPORT void JNICALL Java_com_cacaosd_I2CHandler_readByteBufferArduino
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyteArray data, jbyte length) {
    jbyte *data_ar = (*env)->GetByteArrayElements(env, data, 0);

    int file;

    if ((file = open(path, O_RDWR)) < 0) {
        printf("%s do not open. Address %d.\n", path, DEV_ADD);
    }

    if (ioctl(file, I2C_SLAVE, DEV_ADD) < 0) {
        printf("Can not join I2C Bus. Address %d.\n", DEV_ADD);
    }

    if (read(file, data_ar, length) != length) {
        printf("Can not read data. Address %d.\n", DEV_ADD);
    }

    close(file);
}

JNIEXPORT jshort JNICALL Java_com_cacaosd_I2CHandler_readWord
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyte MSB, jbyte LSB) {
    uint8_t msb = Java_com_cacaosd_I2CHandler_readByte(env, obj, DEV_ADD, MSB);

    uint8_t lsb = Java_com_cacaosd_I2CHandler_readByte(env, obj, DEV_ADD, LSB);

    return ((int16_t) msb << 8) +lsb;
}

