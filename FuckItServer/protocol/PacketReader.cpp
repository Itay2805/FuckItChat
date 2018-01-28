#include "PacketReader.hpp"
#include "../bin/Binary.h"

PacketReader::PacketReader(const uint8_t * arr, size_t len, bool copy)
	: len(len), pos(0), copy(copy)
{
	if (this->copy) {
		this->arr = new uint8_t[len];
		std::memcpy(this->arr, arr, len);
	}
	else {
		this->arr = const_cast<uint8_t*>(arr);
	}
}

PacketReader::~PacketReader() {
	if (this->copy) {
		delete[] this->arr;
	}
}

bool PacketReader::ReadBool() {
	return this->arr[this->pos++] ? true : false;
}

uint8_t PacketReader::ReadByte() {
	return this->arr[this->pos++];
}

int16_t PacketReader::ReadShort() {
	int16_t s = read_short_be(this->arr + this->pos);
	this->pos += 2;
	return s;
}

int32_t PacketReader::ReadInt() {
	int32_t s = read_int_be(this->arr + this->pos);
	this->pos += 4;
	return s;
}

int64_t PacketReader::ReadLong() {
	int64_t s = read_long_be(this->arr + this->pos);
	this->pos += 8;
	return s;
}

float PacketReader::ReadFloat() {
	float s = read_float_be(this->arr + this->pos);
	this->pos += 4;
	return s;
}

double PacketReader::ReadDouble() {
	double s = read_double_be(this->arr + this->pos);
	this->pos += 8;
	return s;
}

bool PacketReader::ReadString(char* out, int len) {
	int vl;
	if (!read_string(this->arr + this->pos, out, len, &vl)) {
		return false;
	}
	this->pos += vl;
	return true;
}

void PacketReader::ReadBytes(uint8_t* out, int len) {
	std::memcpy(out, this->arr + this->pos, len);
	this->pos += len;
}


int32_t PacketReader::ReadVarint() {
	int vl;
	int32_t v = read_varint(this->arr + this->pos, &vl);
	this->pos += vl;
	return v;
}

int64_t PacketReader::ReadVarlong() {
	int vl;
	int64_t v = read_varint(this->arr + this->pos, &vl);
	this->pos += vl;
	return v;
}