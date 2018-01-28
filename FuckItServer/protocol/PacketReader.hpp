#pragma once

#include <cstdint>
#include <string>

class PacketReader {
private:
	uint8_t * arr;
	size_t len;
	size_t pos;
	bool copy;

public:
	PacketReader(const uint8_t* arr, size_t len, bool copy = false);
	~PacketReader();
	
	bool ReadBool();
	uint8_t ReadByte();
	int16_t ReadShort();
	int32_t ReadInt();
	int64_t ReadLong();
	float ReadFloat();
	double ReadDouble();
	int32_t ReadVarint();
	int64_t ReadVarlong();
	bool ReadString(char* out, int len);
	void ReadBytes(uint8_t* out, int len);

	inline size_t Length() const { return this->len; }
	inline size_t GetPos() const { return this->pos; }

	inline void Rewind() { this->pos = 0; }
};