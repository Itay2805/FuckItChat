#pragma once

#include <cstdint>
#include <memory>

int read_varint(const void *ptr, int *olen = nullptr);

long long read_varlong(const void *ptr, int *olen = nullptr);

bool read_string(const unsigned char *ptr, char *out, int out_len, int *olen = nullptr);

int got_varint(const void *ptr, int len);

int varint_size(int num);

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

inline size_t write_bool(uint8_t* ptr, bool val) {
	*ptr = val ? 1 : 0; 
	return 1;
}

inline size_t write_byte(uint8_t* ptr, uint8_t val) {
	*ptr = val; 
	return 1;
}

inline size_t write_short_be(uint8_t* ptr, uint16_t val) {
	ptr[0] = val >> 8;
	ptr[1] = val & 0xFF;
	return 2;
}

inline size_t write_short_le(uint8_t* ptr, uint16_t val) {
	std::memcpy(ptr, &val, 2);
	return 2;
}

inline size_t write_int_be(uint8_t* ptr, uint32_t val) {
	ptr[0] = val >> 24;
	ptr[1] = (val >> 16) & 0xFF;
	ptr[2] = (val >> 8) & 0xFF;
	ptr[3] = val & 0xFF;
	return 4;
}

inline size_t write_int_le(uint8_t* ptr, uint32_t val) {
	std::memcpy(ptr, &val, 4);
	return 4;
}

inline size_t write_long_be(uint8_t* ptr, uint64_t val) {
	ptr[0] = val >> 56;
	ptr[1] = (val >> 48) & 0xFF;
	ptr[2] = (val >> 40) & 0xFF;
	ptr[3] = (val >> 32) & 0xFF;
	ptr[4] = (val >> 24) & 0xFF;
	ptr[5] = (val >> 16) & 0xFF;
	ptr[6] = (val >> 8) & 0xFF;
	ptr[7] = val & 0xFF;
	return 8;
}

inline size_t write_long_le(uint8_t* ptr, uint64_t val) {
	std::memcpy(ptr, &val, 8);
	return 8;
}

inline size_t write_float_be(uint8_t* ptr, float f) {
	uint32_t val = *((uint32_t*)&f);
	ptr[0] = val >> 24;
	ptr[1] = (val >> 16) & 0xFF;
	ptr[2] = (val >> 8) & 0xFF;
	ptr[3] = val & 0xFF;
	return 4;
}

inline size_t write_float_le(uint8_t* ptr, float val) {
	std::memcpy(ptr, &val, 4);
	return 4;
}

inline size_t write_double_be(uint8_t* ptr, double f) {
	uint64_t val = *((uint64_t*)&f);
	ptr[0] = val >> 56;
	ptr[1] = (val >> 48) & 0xFF;
	ptr[2] = (val >> 40) & 0xFF;
	ptr[3] = (val >> 32) & 0xFF;
	ptr[4] = (val >> 24) & 0xFF;
	ptr[5] = (val >> 16) & 0xFF;
	ptr[6] = (val >> 8) & 0xFF;
	ptr[7] = val & 0xFF;
	return 8;
}

inline size_t write_double_le(uint8_t* ptr, double val) {
	std::memcpy(ptr, &val, 8);
	return 8;
}

int write_varint(unsigned char *ptr, unsigned int val);

int write_varlong(unsigned char *ptr, unsigned long long val);

int write_string(unsigned char *ptr, const char *str);