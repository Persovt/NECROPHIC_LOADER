#include "hwid.h"

using namespace std;
namespace HWID
{
	





	std::string SHA1(std::string text)
	{
		CryptoPP::SHA1 sha1;
		std::string hash;
		CryptoPP::StringSource(text, true, new CryptoPP::HashFilter(sha1, new CryptoPP::HexEncoder(new CryptoPP::StringSink(hash))));
		return hash;
	}

	auto encrypt(const std::string& str_in, const std::string& key, const std::string& iv) -> std::string
	{
		std::string str_out;
		CryptoPP::CFB_Mode<CryptoPP::AES>::Encryption encryption((byte*)key.c_str(), key.length(), (byte*)iv.c_str());

		CryptoPP::StringSource encryptor(str_in, true,
			new CryptoPP::StreamTransformationFilter(encryption,
				new CryptoPP::Base64Encoder(
					new CryptoPP::StringSink(str_out),
					false
				)
			)
		);
		return str_out;
	}

	auto decrypt(const std::string& str_in, const std::string& key, const std::string& iv) -> std::string
	{
		std::string str_out;

		CryptoPP::CFB_Mode<CryptoPP::AES>::Decryption decryption((byte*)key.c_str(), key.length(), (byte*)iv.c_str());

		CryptoPP::StringSource decryptor(str_in, true,
			new CryptoPP::Base64Decoder(
				new CryptoPP::StreamTransformationFilter(decryption,
					new CryptoPP::StringSink(str_out)
				)
			)
		);
		return str_out;
	}

	std::string GetHWID()
	{
		std::string result;

		char computerName[32], userName[32];

		DWORD disk_serialINT;
		GetVolumeInformationA("c:\\", NULL, NULL, &disk_serialINT, NULL, NULL, NULL, NULL);

		int CPUInfo[4] = { -1 };
		char CPUBrandString[0x40];
		__cpuid(CPUInfo, 0x80000000);
		unsigned int nExIds = CPUInfo[0];

		memset(CPUBrandString, 0, sizeof(CPUBrandString));

		for (int i = 0x80000000; i <= nExIds; ++i)
		{
			__cpuid(CPUInfo, i);
			if (i == 0x80000002)
				memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
			else if (i == 0x80000003)
				memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
			else if (i == 0x80000004)
				memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
		}

		DWORD cnCharCount = 32;
		DWORD unCharCount = 32;

		GetComputerName(computerName, &cnCharCount);
		GetUserName(userName, &unCharCount);

		result = std::string(userName) + std::string(computerName) + std::to_string(disk_serialINT) + std::string(CPUBrandString);

		result.erase(std::remove_if(result.begin(), result.end(), isspace), result.end());

		result = SHA1(result).substr(22);

		std::transform(result.begin(), result.end(), result.begin(), ::tolower);

		return result;
	}

	

};