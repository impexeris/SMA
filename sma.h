/**
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <robin.lilja@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. - Robin Lilja
 *
 * @file sma.h
 * @author Robin Lilja
 * @date 26 Sep 2015
 */

#ifndef _SMA_H_
#define _SMA_H_

//#include "Arduino.h"

/**
 * Fast simple moving average class.
 */
class SMA {

public:

	/**
	 * Constructor.
	 * @param length of buffer.
	 */
	SMA(uint8_t length) {

		this->buffer = new float[length];

		this->average = 0.0f;

		this->pt = 0;
		this->length = length;

		for (uint8_t i = 0; i < length; i++) { buffer[i] = 0.0f; }
	};

	/**
	 * Update buffer with latest value.
	 * @param value new value to be added to buffer.
	 * @return the average value.
	 */
	float update(float value);

	/**
	 * Get average value.
	 * @return the average value.
	 */
	float output() { return average; }

private:

	float *buffer;

	double average;

	uint8_t pt;

	uint8_t length;
};

inline float SMA::update(float value) {

	average += (double)((value - buffer[pt]) / (float)length);

	buffer[pt] = value;

	pt = (pt+1) % length;

	return average;
}

#endif /* _SMA_H_ */
