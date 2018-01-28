#pragma once

#include <cstdint>
#include <string>

class Packet {
private:
	uint8_t* arr;
	size_t pos;
	size_t len;
	size_t cap;
	size_t rbeg;

public:

	Packet(size_t initCap = 16, size_t reserveBeg = 5);
	~Packet();

	void Expand(size_t newCap);

	void UseReserved(size_t count);

	void PrintHex();

	void PutBool(bool val);
	void PutByte(uint8_t val);
	void PutShort(uint16_t val);
	void PutInt(uint32_t val);
	void PutLong(uint64_t val);
	void PutFloat(float val);
	void PutDouble(double val);
	void PutVarint(uint32_t val);
	void PutVarlong(uint64_t val);
	void PutString(const std::string& str);
	void PutBytes(const void* ptr, size_t len);

	inline const uint8_t* GetData() const { return this->arr; }
	inline size_t GetPos() const { return this->pos; }
	inline size_t GetLength() const { return this->len; }
	inline size_t GetCapacity() const { return this->cap; }

	inline void Rewind() { this->pos = 0; }
	inline void Reset() { this->pos = this->len = 0; }

};