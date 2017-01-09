/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_cacaosd_i2c_core_I2cPort */
#include "I2cPort.h"
using namespace cacaosd_i2cport;

#ifndef _Included_com_cacaosd_i2c_core_I2cPort
#define _Included_com_cacaosd_i2c_core_I2cPort
#ifdef __cplusplus
uint8_t _device_address;
I2cPort i2c;
extern "C" {
#endif

/*
 * Class:     com_cacaosd_i2c_core_I2cPort
 * Method:    openConnection
 * Signature: ()V
 */
JNIEXPORT jbyte JNICALL Java_com_cacaosd_i2c_core_I2cPort_openConnection
  (JNIEnv *, jobject);

/*
 * Class:     com_cacaosd_i2c_core_I2cPort
 * Method:    setDeviceAddress
 * Signature: (B)V
 */
JNIEXPORT void JNICALL Java_com_cacaosd_i2c_core_I2cPort_setDeviceAddress
  (JNIEnv *, jobject, jbyte);

/*
 * Class:     com_cacaosd_i2c_core_I2cPort
 * Method:    getDeviceAddress
 * Signature: ()B
 */
JNIEXPORT jbyte JNICALL Java_com_cacaosd_i2c_core_I2cPort_getDeviceAddress
  (JNIEnv *, jobject);

/*
 * Class:     com_cacaosd_i2c_core_I2cPort
 * Method:    setBusAddress
 * Signature: (B)V
 */
JNIEXPORT void JNICALL Java_com_cacaosd_i2c_core_I2cPort_setBusAddress
  (JNIEnv *, jobject, jbyte);

/*
 * Class:     com_cacaosd_i2c_core_I2cPort
 * Method:    getBusAddress
 * Signature: ()B
 */
JNIEXPORT jbyte JNICALL Java_com_cacaosd_i2c_core_I2cPort_getBusAddress
  (JNIEnv *, jobject);

/*
 * Class:     com_cacaosd_i2c_core_I2cPort
 * Method:    writeBit
 * Signature: (BBB)V
 */
JNIEXPORT void JNICALL Java_com_cacaosd_i2c_core_I2cPort_writeBit
  (JNIEnv *, jobject, jbyte, jbyte, jbyte);

/*
 * Class:     com_cacaosd_i2c_core_I2cPort
 * Method:    writeMoreBits
 * Signature: (BBBB)V
 */
JNIEXPORT void JNICALL Java_com_cacaosd_i2c_core_I2cPort_writeMoreBits
  (JNIEnv *, jobject, jbyte, jbyte, jbyte, jbyte);

/*
 * Class:     com_cacaosd_i2c_core_I2cPort
 * Method:    writeByte
 * Signature: (BB)V
 */
JNIEXPORT void JNICALL Java_com_cacaosd_i2c_core_I2cPort_writeByte
  (JNIEnv *, jobject, jbyte, jbyte);

/*
 * Class:     com_cacaosd_i2c_core_I2cPort
 * Method:    writeByteBuffer
 * Signature: (B[B)V
 */
JNIEXPORT void JNICALL Java_com_cacaosd_i2c_core_I2cPort_writeByteBuffer
  (JNIEnv *, jobject, jbyte, jbyteArray);

/*
 * Class:     com_cacaosd_i2c_core_I2cPort
 * Method:    writeByteArduino
 * Signature: (B)V
 */
JNIEXPORT void JNICALL Java_com_cacaosd_i2c_core_I2cPort_writeByteArduino
  (JNIEnv *, jobject, jbyte);

/*
 * Class:     com_cacaosd_i2c_core_I2cPort
 * Method:    writeByteBufferArduino
 * Signature: ([B)V
 */
JNIEXPORT void JNICALL Java_com_cacaosd_i2c_core_I2cPort_writeByteBufferArduino
  (JNIEnv *, jobject, jbyteArray);

/*
 * Class:     com_cacaosd_i2c_core_I2cPort
 * Method:    readBit
 * Signature: (BB)B
 */
JNIEXPORT jbyte JNICALL Java_com_cacaosd_i2c_core_I2cPort_readBit
  (JNIEnv *, jobject, jbyte, jbyte);

/*
 * Class:     com_cacaosd_i2c_core_I2cPort
 * Method:    readMoreBits
 * Signature: (BBB)B
 */
JNIEXPORT jbyte JNICALL Java_com_cacaosd_i2c_core_I2cPort_readMoreBits
  (JNIEnv *, jobject, jbyte, jbyte, jbyte);

/*
 * Class:     com_cacaosd_i2c_core_I2cPort
 * Method:    readByte
 * Signature: (B)B
 */
JNIEXPORT jbyte JNICALL Java_com_cacaosd_i2c_core_I2cPort_readByte
  (JNIEnv *, jobject, jbyte);

/*
 * Class:     com_cacaosd_i2c_core_I2cPort
 * Method:    readByteBuffer
 * Signature: (BB)[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_cacaosd_i2c_core_I2cPort_readByteBuffer
  (JNIEnv *, jobject, jbyte, jbyte);

/*
 * Class:     com_cacaosd_i2c_core_I2cPort
 * Method:    readByteBufferArduino
 * Signature: (B)[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_cacaosd_i2c_core_I2cPort_readByteBufferArduino
  (JNIEnv *, jobject, jbyte);

/*
 * Class:     com_cacaosd_i2c_core_I2cPort
 * Method:    readWord
 * Signature: (BB)S
 */
JNIEXPORT jshort JNICALL Java_com_cacaosd_i2c_core_I2cPort_readWord
  (JNIEnv *, jobject, jbyte, jbyte);

#ifdef __cplusplus
}
#endif
#endif