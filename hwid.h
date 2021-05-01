#pragma once

#include "include.h"

#include "CryptoPP/sha.h"
#include "CryptoPP/osrng.h"
#include "CryptoPP/hex.h"

#include "CryptoPP/cryptlib.h"
#include "CryptoPP/aes.h"
#include "CryptoPP/modes.h"
#include "CryptoPP/base64.h"

namespace HWID
{
	std::string SHA1(std::string text);
	auto encrypt(const std::string& str_in, const std::string& key, const std::string& iv)->std::string;
	auto decrypt(const std::string& str_in, const std::string& key, const std::string& iv)->std::string;
	std::string GetHWID();
	
};