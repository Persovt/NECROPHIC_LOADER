#include "auth.h"
namespace Auth
{
	bool Auth(std::string log, std::string pass, bool server)
	{
		if (InternetCheckConnection("https://www.google.ru", FLAG_ICC_FORCE_CONNECTION, 0))
		{
			std::string hwid = HWID::GetHWID();
			std::string UrlRequest = "/";
			UrlRequest.append("licensecheck?binding=" + hwid + "&login=" + log + "&password=" + pass);
			std::string resCode = Web::GetUrlData(UrlRequest);

			if (resCode == "success_ok")
			{
				return false;
			}

			if (resCode == "oldversion")
			{
				MessageBoxA(NULL, "Your loader version is not up to date. Please download the loader from your personal account.", "MixtureCheats", MB_OK);
			
			}

			if (resCode == "errorHWID")
			{
				MessageBoxA(NULL, "Wrong HWID. Please message to support.", "MixtureCheats", MB_OK);
				
			}

			if (resCode == "errorTIME")
			{
				MessageBoxA(NULL, "You doesn`t have subscription. Please reactive your subscription.", "MixtureCheats", MB_OK);
				
			}

			if (resCode == "banned")
			{
				MessageBoxA(NULL, "Your account has been banned.", "MixtureCheats", MB_OK);
				
			}

			if (resCode == "error0")
			{
				MessageBoxA(NULL, "Cheat has been disabled. Please check news.", "MixtureCheats", MB_OK);
				
			}

			if (resCode == "error1403")
			{
				MessageBoxA(NULL, "Whats wrong. Error - code: 1403", "MixtureCheats", MB_OK);
				
			}

			if (resCode == "error1440")
			{
				MessageBoxA(NULL, "Whats wrong. Error - code: 1440", "MixtureCheats", MB_OK);
				
			}

			if (resCode == "freez")
			{
				MessageBoxA(NULL, "Your subscription has been freezed.", "MixtureCheats", MB_OK);
				
			}

			return true;
		}
	}
};