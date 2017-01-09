/*
 * I2cPort.cpp
 *
 *  Created on: Jan 7, 2017
 *      Author: cagdas
 */

#include "I2cPortJava.hpp"

JNIEXPORT jbyte JNICALL Java_com_cacaosd_i2c_core_I2cPort_openConnection
  (JNIEnv *env, jobject obj) {
    i2c.openConnection();
}

JNIEXPORT jbyte JNICALL Java_com_cacaosd_i2c_core_I2cPort_closeConnection
  (JNIEnv *env, jobject obj) {
    i2c.closeConnection();
}

JNIEXPORT void JNICALL Java_com_cacaosd_i2c_core_I2cPort_setDeviceAddress(
		JNIEnv *env, jobject obj, jbyte device_address) {
	i2c.setDeviceAddress(device_address);
}

JNIEXPORT jbyte JNICALL Java_com_cacaosd_i2c_core_I2cPort_getDeviceAddress(
		JNIEnv *env, jobject obj) {
	return i2c.getDeviceAddress();
}

JNIEXPORT void JNICALL Java_com_cacaosd_i2c_core_I2cPort_setBusAddress(JNIEnv *env,
		jobject obj, jbyte bus_address) {
	i2c.setBusAddress((uint8_t) bus_address);
}

JNIEXPORT jbyte JNICALL Java_com_cacaosd_i2c_core_I2cPort_getBusAddress(JNIEnv *env,
		jobject obj) {
	return i2c.getBusAddress();
}

JNIEXPORT void JNICALL Java_com_cacaosd_i2c_core_I2cPort_writeBit(JNIEnv *env,
		jobject obj, jbyte register_address, jbyte data, jbyte bit_no) {
	i2c.writeBit(register_address, data, bit_no);
}

JNIEXPORT void JNICALL Java_com_cacaosd_i2c_core_I2cPort_writeMoreBits(JNIEnv *env,
		jobject object, jbyte register_address, jbyte data, jbyte length,
		jbyte start_bit) {
	i2c.writeMoreBits(register_address, data, length, start_bit);
}

JNIEXPORT void JNICALL Java_com_cacaosd_i2c_core_I2cPort_writeByte(JNIEnv *env,
		jobject object, jbyte register_address, jbyte data) {
	i2c.writeByte(register_address, data);
}

JNIEXPORT void JNICALL Java_com_cacaosd_i2c_core_I2cPort_writeByteBuffer(JNIEnv *env,
		jobject object, jbyte register_address, jbyteArray data) {
	uint8_t *new_data = (uint8_t*) env->GetByteArrayElements(data, JNI_FALSE);
	uint8_t length = env->GetArrayLength(data);

	i2c.writeByteBuffer(register_address, new_data, length);
	env->ReleaseByteArrayElements(data, (jbyte *) new_data, JNI_ABORT);
}

JNIEXPORT void JNICALL Java_com_cacaosd_i2c_core_I2cPort_writeByteArduino(
		JNIEnv *env, jobject object, jbyte data) {
	i2c.writeByteArduino(data);
}

JNIEXPORT void JNICALL Java_com_cacaosd_i2c_core_I2cPort_writeByteBufferArduino(
		JNIEnv *env, jobject object, jbyteArray data) {
	uint8_t *new_data = (uint8_t*) env->GetByteArrayElements(data, JNI_FALSE);
	uint8_t length = env->GetArrayLength(data);

	i2c.writeByteBufferArduino(new_data, length);
	env->ReleaseByteArrayElements(data, (jbyte*) new_data, JNI_ABORT);
}

JNIEXPORT jbyte JNICALL Java_com_cacaosd_i2c_core_I2cPort_readBit(JNIEnv *env,
		jobject object, jbyte register_address, jbyte bit_no) {
	return i2c.readBit(register_address, bit_no);
}

JNIEXPORT jbyte JNICALL Java_com_cacaosd_i2c_core_I2cPort_readMoreBits(JNIEnv *env,
		jobject object, jbyte register_address, jbyte length, jbyte start_bit) {
	return i2c.readMoreBits(register_address, length, start_bit);
}

JNIEXPORT jbyte JNICALL Java_com_cacaosd_i2c_core_I2cPort_readByte(JNIEnv *env,
		jobject object, jbyte register_address) {
	return i2c.readByte((uint8_t)register_address);
}

JNIEXPORT jbyteArray JNICALL Java_com_cacaosd_i2c_core_I2cPort_readByteBuffer(
		JNIEnv *env, jobject object, jbyte register_address, jbyte length) {
	jbyteArray temp_Array = env->NewByteArray(length);
	uint8_t *new_data = (uint8_t*) calloc(length, sizeof(uint8_t));
	i2c.readByteBuffer(register_address, new_data, length);
	env->SetByteArrayRegion(temp_Array, 0, length, (jbyte*) new_data);
	free(new_data);
	return temp_Array;
}

JNIEXPORT jbyteArray JNICALL Java_com_cacaosd_i2c_core_I2cPort_readByteBufferArduino(
		JNIEnv *env, jobject object, jbyte length) {
	jbyteArray temp_array = env->NewByteArray(length);
	uint8_t *new_data = (uint8_t*) calloc(length, sizeof(uint8_t));
	i2c.readByteBufferArduino(new_data, length);
	env->SetByteArrayRegion(temp_array, 0, length, (jbyte*) new_data);
	free(new_data);
	return temp_array;
}

JNIEXPORT jshort JNICALL Java_com_cacaosd_i2c_core_I2cPort_readWord(JNIEnv *env,
		jobject object, jbyte msb_address, jbyte lsb_address) {
	return i2c.readWord(msb_address, lsb_address);
}
