#include <jni.h>
#include <stdio.h>
#include "I2CJNI.h"
#define DEBUG 1

//#undef DEBUG

/*
 * Class:     cacaosd_BBB_I2C
 * Method:    writeBit
 * Signature: (BBBB)V
 */
JNIEXPORT void JNICALL Java_cacaosd_BBB_1I2C_writeBit
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyte DATA_REGADD, jbyte data, jbyte bitNum) {
    int8_t temp = Java_cacaosd_BBB_1I2C_readByte(env, obj, DEV_ADD, DATA_REGADD);
    if (data == 0) {
        temp = temp & ~(1 << bitNum);
    } else if (data == 1) {
        temp = temp | (1 << bitNum);
    } else {
        printf("Value must be 0 or 1! --> Address %d.\n", DEV_ADD);
    }

    Java_cacaosd_BBB_1I2C_writeByte(env, obj, DEV_ADD, DATA_REGADD, temp);
}

/*
 * Class:     cacaosd_BBB_I2C
 * Method:    writeBits
 * Signature: (BBBBB)V
 */
JNIEXPORT void JNICALL Java_cacaosd_BBB_1I2C_writeBits
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyte DATA_REGADD, jbyte data, jbyte length, jbyte startBit) {
    int8_t temp = Java_cacaosd_BBB_1I2C_readByte(env, obj, DEV_ADD, DATA_REGADD);
    uint8_t bits = 1;
    uint8_t i = 0;

    while (i < length - 1) {
        bits = (bits << 1);
        ++bits;
        ++i;
    }

    temp &= ~(bits << startBit);

    temp |= (data << startBit);

    Java_cacaosd_BBB_1I2C_writeByte(env, obj, DEV_ADD, DATA_REGADD, temp);
}

/*
 * Class:     cacaosd_BBB_I2C
 * Method:    writeByte
 * Signature: (BBB)V
 */
JNIEXPORT void JNICALL Java_cacaosd_BBB_1I2C_writeByte
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

/*
 * Class:     cacaosd_BBB_I2C
 * Method:    writeByteBuffer
 * Signature: (BB[BB)V
 */
JNIEXPORT void JNICALL Java_cacaosd_BBB_1I2C_writeByteBuffer
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyte DATA_REGADD, jbyteArray data, jbyte length) {
    jbyte *data_ar = env->GetByteArrayElements(data, JNI_FALSE);

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

    env->ReleaseByteArrayElements(data, data_ar, JNI_ABORT);
}

/*
 * Class:     cacaosd_BBB_I2C
 * Method:    writeByteArduino
 * Signature: (BB)V
 */
JNIEXPORT void JNICALL Java_cacaosd_BBB_1I2C_writeByteArduino
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

/*
 * Class:     cacaosd_BBB_I2C
 * Method:    writeByteBufferArduino
 * Signature: (B[BB)V
 */
JNIEXPORT void JNICALL Java_cacaosd_BBB_1I2C_writeByteBufferArduino
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyteArray data, jbyte length) 
{
    jbyte *data_ar = env->GetByteArrayElements(data, JNI_FALSE);
    
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
    
    env->ReleaseByteArrayElements(data, data_ar, JNI_ABORT);
}

/*
 * Class:     cacaosd_BBB_I2C
 * Method:    initialize
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_cacaosd_BBB_1I2C_initialize
(JNIEnv *env, jobject obj) {

    jclass cls = env->GetObjectClass(obj);
    jmethodID methId = env->GetMethodID(cls, "getPath", "()Ljava/lang/String;");
    jstring str = (jstring) env->CallObjectMethod(obj, methId);
    path = env->GetStringUTFChars(str, 0);

#ifdef DEBUG
    printf("%s\n", path);
    env->ReleaseStringUTFChars(str, path);
#endif
}

JNIEXPORT jbyte JNICALL Java_cacaosd_BBB_1I2C_readByte
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

JNIEXPORT jbyte JNICALL Java_cacaosd_BBB_1I2C_readBit
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyte DATA_REGADD, jbyte bitNum) {
    int8_t temp = Java_cacaosd_BBB_1I2C_readByte(env, obj, DEV_ADD, DATA_REGADD);
    return (temp >> bitNum) % 2;
}

/*
 * Class:     cacaosd_BBB_I2C
 * Method:    readBits
 * Signature: (BBBB)B
 */
JNIEXPORT jbyte JNICALL Java_cacaosd_BBB_1I2C_readBits
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyte DATA_REGADD, jbyte length, jbyte startBit) {
    int8_t temp = Java_cacaosd_BBB_1I2C_readByte(env, obj, DEV_ADD, DATA_REGADD);
    return (temp >> startBit) % (uint8_t) pow(2, length);
}

/*
 * Class:     cacaosd_BBB_I2C
 * Method:    readByteBuffer
 * Signature: (BB[BB)V
 */
JNIEXPORT void JNICALL Java_cacaosd_BBB_1I2C_readByteBuffer
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyte DATA_REGADD, jbyteArray data, jbyte length) {
    jbyte *data_ar = env->GetByteArrayElements(data, JNI_FALSE);

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

    env->ReleaseByteArrayElements(data, data_ar, JNI_ABORT);
}

/*
 * Class:     cacaosd_BBB_I2C
 * Method:    readByteBufferArduino
 * Signature: (B[BB)V
 */
JNIEXPORT void JNICALL Java_cacaosd_BBB_1I2C_readByteBufferArduino
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyteArray data, jbyte length) {
    jbyte *data_ar = env->GetByteArrayElements(data, 0);

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

/*
 * Class:     cacaosd_BBB_I2C
 * Method:    readWord
 * Signature: (BBB)S
 */
JNIEXPORT jshort JNICALL Java_cacaosd_BBB_1I2C_readWord
(JNIEnv *env, jobject obj, jbyte DEV_ADD, jbyte MSB, jbyte LSB) {
    uint8_t msb = Java_cacaosd_BBB_1I2C_readByte(env, obj, DEV_ADD, MSB);

    uint8_t lsb = Java_cacaosd_BBB_1I2C_readByte(env, obj, DEV_ADD, LSB);

    return ((int16_t) msb << 8) +lsb;
}
