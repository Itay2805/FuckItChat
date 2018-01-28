#pragma once

#include <cstdint>

int read_varint(const void *ptr, int *olen = nullptr);

long long read_varlong(const void *ptr, int *olen = nullptr);

bool read_string(const unsigned char *ptr, char *out, int out_len, int *olen = nullptr);

inline bool read_bool(const uint8_t* ptr) {
	return *ptr ? true : false;
}

inline int16_t read_short_be(const uint8_t* ptr) {
	return (int16_t)(((uint16_t)ptr[0] << 8) |
		(uint16_t)ptr[1]);
}

inline int16_t read_short_le(const uint8_t* ptr) {
	return *((const int16_t*)ptr);
}

inline int32_t read_int_be(const uint8_t* ptr) {
	return (int32_t)(((uint32_t)ptr[0] << 24) |
		((uint32_t)ptr[1] << 16) |
		((uint32_t)ptr[2] << 8) |
		(uint32_t)ptr[3]);
}

inline int32_t read_int_le(const uint8_t* ptr)
{
	return *((const int32_t*)ptr);
}

inline int64_t read_long_be(const uint8_t* ptr)
{
	return (int64_t)(((uint64_t)ptr[0] << 56) |
		((uint64_t)ptr[1] << 48) |
		((uint64_t)ptr[2] << 40) |
		((uint64_t)ptr[3] << 32) |
		((uint64_t)ptr[4] << 24) |
		((uint64_t)ptr[5] << 16) |
		((uint64_t)ptr[6] << 8) |
		(uint64_t)ptr[7]);
}

inline int64_t read_long_le(const uint8_t* ptr) {
	return *((const int64_t*)ptr);
}

inline float read_float_be(const uint8_t* ptr) {
	uint8_t arr[4];
	arr[0] = ptr[3];
	arr[1] = ptr[2];
	arr[2] = ptr[1];
	arr[3] = ptr[0];
	return *((float *)arr);
}

inline float read_float_le(const uint8_t* ptr) {
	return *((const float *)ptr);
}

inline double read_double_be(const uint8_t* ptr) {
	uint8_t arr[8];
	arr[0] = ptr[7];
	arr[1] = ptr[6];
	arr[2] = ptr[5];
	arr[3] = ptr[4];
	arr[4] = ptr[3];
	arr[5] = ptr[2];
	arr[6] = ptr[1];
	arr[7] = ptr[0];
	return *((double *)arr);
}

inline double read_double_le(const uint8_t* ptr) {
	return *((const double *)ptr);
}