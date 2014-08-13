/*
 * I2C.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: cagdas
 */

#include "I2C.h"

JNIEXPORT
void JNICALL Java_com_cacaosd_i2cjava_I2C_initialize(JNIEnv *env,
		jobject object, jbyte busAddr) {
	i2c.setBusAddress(US8 busAddr);
}

JNIEXPORT
void JNICALL Java_com_cacaosd_i2cjava_I2C_setDeviceAddress(JNIEnv *env,
		jobject object, jbyte DEV_ADD) {
	i2c.setDEV_ADD(DEV_ADD);
}

JNIEXPORT
jbyte JNICALL Java_com_cacaosd_i2cjava_I2C_getDeviceAddress(JNIEnv *env,
		jobject object) {
	return DEV_ADD;
}

JNIEXPORT
void JNICALL Java_com_cacaosd_i2cjava_I2C_writeBit(JNIEnv *env, jobject object,
		jbyte register_address, jbyte data, jbyte bit_no) {
	i2c.writeBit(register_address, data, bit_no);
}

JNIEXPORT
void JNICALL Java_com_cacaosd_i2cjava_I2C_writeBitNoExit(JNIEnv *env,
		jobject object, jbyte register_address, jbyte data, jbyte bit_no) {
	i2c.writeBitNoExit(register_address, data, bit_no);
}

JNIEXPORT
void JNICALL Java_com_cacaosd_i2cjava_I2C_writeMoreBits(JNIEnv *env,
		jobject object, jbyte register_address, jbyte data, jbyte length,
		jbyte start_bit) {
	i2c.writeMoreBits(register_address, data, length, start_bit);
}

JNIEXPORT
void JNICALL Java_com_cacaosd_i2cjava_I2C_writeMoreBitsNoExit(JNIEnv *env,
		jobject object, jbyte register_address, jbyte data, jbyte length,
		jbyte start_bit) {
	i2c.writeMoreBitsNoExit(register_address, data, length, start_bit);
}

JNIEXPORT
void JNICALL Java_com_cacaosd_i2cjava_I2C_writeByte(JNIEnv *env, jobject object,
		jbyte register_address, jbyte data) {
	i2c.writeByte(register_address, data);
}

JNIEXPORT
void JNICALL Java_com_cacaosd_i2cjava_I2C_writeByteNoExit(JNIEnv *env,
		jobject object, jbyte register_address, jbyte data) {
	i2c.writeByteNoExit(register_address, data);
}

JNIEXPORT
void JNICALL Java_com_cacaosd_i2cjava_I2C_writeByteBuffer(JNIEnv *env,
		jobject object, jbyte register_address, jbyteArray data) {
	uint8_t *new_data = US8P env->GetByteArrayElements(data, JNI_FALSE);
	uint8_t length = env->GetArrayLength(data);

	i2c.writeByteBuffer(register_address, new_data, length);
	env->ReleaseByteArrayElements(data, (jbyte *) new_data, JNI_ABORT);
}

JNIEXPORT
void JNICALL Java_com_cacaosd_i2cjava_I2C_writeByteBufferNoExit(JNIEnv *env,
		jobject object, jbyte register_address, jbyteArray data) {
	uint8_t *new_data = US8P env->GetByteArrayElements(data, JNI_FALSE);
	uint8_t length = env->GetArrayLength(data);

	i2c.writeByteBufferNoExit(register_address, new_data, (uint8_t) length);
	env->ReleaseByteArrayElements(data, (jbyte *) new_data, JNI_ABORT);
}

JNIEXPORT
void JNICALL Java_com_cacaosd_i2cjava_I2C_writeByteArduino(JNIEnv *env,
		jobject object, jbyte data) {
	i2c.writeByteArduino(data);
}

JNIEXPORT
void JNICALL Java_com_cacaosd_i2cjava_I2C_writeByteArduinoNoExit(JNIEnv *env,
		jobject object, jbyte data) {
	i2c.writeByteArduinoNoExit(data);
}

JNIEXPORT
void JNICALL Java_com_cacaosd_i2cjava_I2C_writeByteBufferArduino(JNIEnv *env,
		jobject object, jbyteArray data) {
	uint8_t *new_data = US8P env->GetByteArrayElements(data, JNI_FALSE);
	uint8_t length = env->GetArrayLength(data);

	i2c.writeByteBufferArduino(new_data, length);
	env->ReleaseByteArrayElements(data, (jbyte*) new_data, JNI_ABORT);
}

JNIEXPORT
void JNICALL Java_com_cacaosd_i2cjava_I2C_writeByteBufferArduinoNoExit(
		JNIEnv *env, jobject object, jbyteArray data) {
	uint8_t *new_data = US8P env->GetByteArrayElements(data, JNI_FALSE);
	uint8_t length = env->GetArrayLength(data);

	i2c.writeByteBufferArduinoNoExit(new_data, length);
	env->ReleaseByteArrayElements(data, (jbyte*) new_data, JNI_ABORT);
}

JNIEXPORT
jbyte JNICALL Java_com_cacaosd_i2cjava_I2C_readBit(JNIEnv *env, jobject object,
		jbyte register_address, jbyte bit_no) {
	return i2c.readBit(register_address, bit_no);
}

JNIEXPORT
jbyte JNICALL Java_com_cacaosd_i2cjava_I2C_readBitNoExit(JNIEnv *env,
		jobject object, jbyte register_address, jbyte bit_no) {
	return i2c.readBitNoExit(register_address, bit_no);
}

JNIEXPORT
jbyte JNICALL Java_com_cacaosd_i2cjava_I2C_readMoreBits(JNIEnv *env,
		jobject object, jbyte register_address, jbyte length, jbyte start_bit) {
	return i2c.readMoreBits(register_address, length, start_bit);
}

JNIEXPORT
jbyte JNICALL Java_com_cacaosd_i2cjava_I2C_readMoreBitsNoExit(JNIEnv *env,
		jobject object, jbyte register_address, jbyte length, jbyte start_bit) {
	return i2c.readMoreBitsNoExit(register_address, length, start_bit);
}

JNIEXPORT
jbyte JNICALL Java_com_cacaosd_i2cjava_I2C_readByte(JNIEnv *env, jobject object,
		jbyte register_address) {
	return i2c.readByte(register_address);
}

JNIEXPORT
jbyte JNICALL Java_com_cacaosd_i2cjava_I2C_readByteNoExit(JNIEnv *env,
		jobject object, jbyte register_address) {
	return i2c.readByteNoExit(register_address);
}

JNIEXPORT
jbyteArray JNICALL Java_com_cacaosd_i2cjava_I2C_readByteBuffer(JNIEnv *env,
		jobject object, jbyte register_address, jbyte length) {
	jbyteArray temp_Array = env->NewByteArray(length);
	uint8_t *new_data = (uint8_t*) calloc(length, sizeof(uint8_t));
	i2c.readByteBuffer(register_address, new_data, length);
	env->SetByteArrayRegion(temp_Array, 0, length, (jbyte*) new_data);
	free(new_data);
	return temp_Array;
}

JNIEXPORT
jbyteArray JNICALL Java_com_cacaosd_i2cjava_I2C_readByteBufferNoExit(
		JNIEnv *env, jobject object, jbyte register_address, jbyte length) {
	jbyteArray temp_array = env->NewByteArray(length);
	uint8_t *new_data = (uint8_t*) calloc(length, sizeof(uint8_t));
	i2c.readByteBufferNoExit(register_address, new_data, length);
	env->SetByteArrayRegion(temp_array, 0, length, (jbyte*) new_data);
	free(new_data);
	return temp_array;
}

JNIEXPORT
jbyteArray JNICALL Java_com_cacaosd_i2cjava_I2C_readByteBufferArduino(
		JNIEnv *env, jobject object, jbyte length) {
	jbyteArray temp_array = env->NewByteArray(length);
	uint8_t *new_data = (uint8_t*) calloc(length, sizeof(uint8_t));
	i2c.readByteBufferArduino(new_data, length);
	env->SetByteArrayRegion(temp_array, 0, length, (jbyte*) new_data);
	free(new_data);
	return temp_array;
}

JNIEXPORT
jbyteArray JNICALL Java_com_cacaosd_i2cjava_I2C_readByteBufferArduinoNoExit(
		JNIEnv *env, jobject object, jbyte length) {
	jbyteArray temp_array = env->NewByteArray(length);
	uint8_t *new_data = (uint8_t*) calloc(length, sizeof(uint8_t));
	i2c.readByteBufferArduinoNoExit(new_data, length);
	env->SetByteArrayRegion(temp_array, 0, length, (jbyte*) new_data);
	free(new_data);
	return temp_array;
}

JNIEXPORT
jshort JNICALL Java_com_cacaosd_i2cjava_I2C_readWord(JNIEnv *env,
		jobject object, jbyte msb_address, jbyte lsb_address) {
	return i2c.readWord(msb_address, lsb_address);
}

JNIEXPORT
jshort JNICALL Java_com_cacaosd_i2cjava_I2C_readWordNoExit(JNIEnv *env,
		jobject object, jbyte msb_address, jbyte lsb_address) {
	return i2c.readWordNoExit(msb_address, lsb_address);
}
