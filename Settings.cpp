#include "settings.h"

namespace Credential
{
	bool save_credential = false;
	char login[256] = "";
	char password[256] = "";

	void SaveConfig()
	{
		HKEY hKey;

		RegCreateKeyEx(HKEY_CURRENT_USER, "Software\\MIXTURE", 0, NULL, REG_OPTION_VOLATILE, KEY_WRITE, NULL, &hKey, NULL);
		RegSetValueEx(hKey, "login", 0, REG_SZ, (BYTE*)login, sizeof(login));
		RegSetValueEx(hKey, "password", 0, REG_SZ, (BYTE*)password, sizeof(password));
		RegCloseKey(hKey);
	}

	void LoadConfig()
	{
		DWORD dwBufLen = MAX_PATH;
		RegGetValue(HKEY_CURRENT_USER, "Software\\MIXTURE", ("login"), RRF_RT_REG_SZ, NULL, (BYTE*)login, &dwBufLen);
		RegGetValue(HKEY_CURRENT_USER, "Software\\MIXTURE", ("password"), RRF_RT_REG_SZ, NULL, (BYTE*)password, &dwBufLen);
	}
}