package com.cacaosd.i2cjava;

public class I2C {
	private static final String DEV_PATH = "/dev/i2c-";
	
	private String bus;
	private String fullPath;
	
	public I2C(byte device_address, String bus){
		this.bus = bus;
		this.setFullPath(DEV_PATH + this.bus);
		setDeviceAddress(device_address);
	}

	public String getFullPath() {
		return fullPath;
	}

	public void setFullPath(String fullPath) {
		this.fullPath = fullPath;
	}
	
	public native void setDeviceAddress(byte device_address);
	public native byte getDeviceAddress();
	
	public native void initialize();
	
	public native void writeBit(byte register_address, byte data, byte bit_no);
	public native void writeBitNoExit(byte register_address, byte data, byte bit_no);
	public native void writeMoreBits(byte register_address, byte data, byte bit_length, byte start_bit);
	public native void writeMoreBitsNoExit(byte register_address, byte data, byte bit_length, byte start_bit);
	public native void writeByte(byte register_Address, byte data);
	public native void writeByteNoExit(byte register_Address, byte data);
	public native void writeByteBuffer(byte register_address, byte[] data);
	public native void writeByteBufferNoExit(byte register_address, byte[] data);
	public native void writeByteArduino(byte data);
	public native void writeByteArduinoNoExit(byte data);
	public native void writeByteBufferArduino(byte[] data);
	public native void writeByteBufferArduinoNoExit(byte[] data);
	
	public native byte readBit(byte register_address, byte bit_no);
	public native byte readBitNoExit(byte register_address, byte bit_no);
	public native byte readMoreBits(byte register_address, byte length, byte start_bit);
	public native byte readMoreBitsNoExit(byte register_address, byte length, byte start_bit);
	public native byte readByte(byte register_address);
	public native byte readByteNoExit(byte register_address);
	public native byte[] readByteBuffer(byte register_address, byte length);
	public native byte[] readByteBufferNoExit(byte register_address, byte length);
	public native byte[] readByteBufferArduino(byte length);
	public native byte[] readByteBufferArduinoNoExit(byte length);
	public native short[] readWord(byte msb_address, byte lsb_address);
	public native short[] readWordNoExit(byte msb_address, byte lsb_address);

}
