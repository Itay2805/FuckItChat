#include "Packet.hpp"
#include "bin\Binary.h"

#include <iostream>
#include <iomanip>
#include <cctype>

Packet::Packet(size_t initCap, size_t reserveBeg)
	:
	arr(new unsigned char[reserveBeg + initCap]),
	cap(initCap),
	len(0),
	pos(0),
	rbeg(reserveBeg)
{
	arr += this->rbeg;
}

Packet::~Packet() {
	delete[](this->arr - this->rbeg);
}

void Packet::Expand(size_t newCap) {
	if (this->cap >= newCap)
		return;

	uint8_t* narr = new unsigned char[this->rbeg + newCap];
	std::memcpy(narr + this->rbeg, this->arr, this->len);
	delete[](this->arr - this->rbeg);

	this->cap = newCap;
	this->arr = narr;
	this->arr += this->rbeg;
}

void Packet::UseReserved(size_t count) {
	this->arr -= count;
	this->len += count;
	this->pos = 0;
	this->rbeg -= count;
}

void Packet::PrintHex() {
	std::cout << std::hex;

	int lines = (this->len >> 4) + !!(this->len & 15);
	for (int i = 0; i < lines; ++i) {
		std::cout << std::setfill('0') << std::setw(8) << (i << 4) << " | ";

		int c = this->len - (i << 4);
		if (c > 16) c = 16;

		for (int j = 0; j < c; ++j) {
			std::cout << std::setfill('0') << std::setw(2) << (int)this->arr[(i << 4) | j];
			if (j != (c - 1)) {
				std::cout << ' ';
			}
		}

		for (int j = c; j < 16; ++j) {
			std::cout << "   ";
		}

		std::cout << " | ";
		for (int j = 0; j < c; ++j) {
			char cc = this->arr[(i << 4) | j];
			std::cout << (std::isprint(cc) ? cc : '.');
		}

		std::cout << std::endl;
	}

	std::cout << std::dec;
}

#define EXPAND(size) if((this->pos + size) > this->cap) this->Expand((this->cap * 16) / 10 + size)

void Packet::PutBool(bool val) {
	EXPAND(1);

	this->arr[this->pos++] = val ? 1 : 0;
	if (this->pos > this->len) {
		this->len = this->pos;
	}
}

void Packet::PutByte(uint8_t val) {
	EXPAND(1);
	
	this->arr[this->pos++] = val;
	if (this->pos > this->len) {
		this->len = this->pos;
	}
}

void Packet::PutShort(uint16_t val) {
	EXPAND(2);


	this->pos += write_short_be(this->arr + this->pos, val);
	if (this->pos > this->len) {
		this->len = this->pos;
	}
}

void Packet::PutInt(uint32_t val) {
	EXPAND(4);

	this->pos += write_int_be(this->arr + this->pos, val);
	if (this->pos > this->len) {
		this->len = this->pos;
	}
}

void Packet::PutLong(uint64_t val) {
	EXPAND(8);

	this->pos += write_long_be(this->arr + this->pos, val);
	if (this->pos > this->len) {
		this->len = this->pos;
	}
}

void Packet::PutFloat(float val) {
	EXPAND(4);

	this->pos += write_float_be(this->arr + this->pos, val);
	if (this->pos > this->len) {
		this->len = this->pos;
	}
}

void Packet::PutDouble(double val) {
	EXPAND(8);

	this->pos += write_double_be(this->arr + this->pos, val);
	if (this->pos > this->len) {
		this->len = this->pos;
	}
}

void Packet::PutVarint(uint32_t val) {
	EXPAND(5);
	
	this->pos += write_varint(this->arr + this->pos, val);
	if (this->pos > this->len) {
		this->len = this->pos;
	}
}

void Packet::PutVarlong(uint64_t val) {
	EXPAND(10);

	this->pos += write_varlong(this->arr + this->pos, val);
	if (this->pos > this->len) {
		this->len = this->pos;
	}
}

void Packet::PutString(const std::string& str) {
	int size = 5 + str.size();
	if ((this->pos + size) > this->cap) {
		this->Expand((this->cap * 14) / 10 + size);
	}

	this->pos += write_string(this->arr + this->pos, str.c_str());
	
	if (this->pos > this->len) {
		this->len = this->pos;
	}
}

void Packet::PutBytes(const void* ptr, size_t len) {
	const uint8_t* arr = (const uint8_t*)ptr;
	if ((this->pos + len) > this->cap) {
		this->Expand((this->cap * 11) / 10 + len);
	}

	std::memcpy(this->arr + this->pos, arr, len);
	this->pos += len;
	if (this->pos > this->len) {
		this->len = this->pos;
	}
}
