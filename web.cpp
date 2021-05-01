#include "web.h"

namespace Web
{
	std::string GetUrlData(std::string url)
	{
		std::string request_data = "";

		HINTERNET hIntSession = InternetOpenA("", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);

		if (!hIntSession)
		{
			return request_data;
		}

		HINTERNET hHttpSession = InternetConnectA(hIntSession, HOST, 80, 0, 0, INTERNET_SERVICE_HTTP, 0, NULL);

		if (!hHttpSession)
		{
			return request_data;
		}

		HINTERNET hHttpRequest = HttpOpenRequestA(hHttpSession, "GET", url.c_str()
			, 0, 0, 0, INTERNET_FLAG_RELOAD, 0);

		if (!hHttpSession)
		{
			return request_data;
		}

		const char* szHeaders = ("");
		char szRequest[1024] = { 0 };

		if (!HttpSendRequestA(hHttpRequest, szHeaders, strlen(szHeaders), szRequest, strlen(szRequest)))
		{
			return request_data;
		}

		CHAR szBuffer[1024] = { 0 };
		DWORD dwRead = 0;

		while (InternetReadFile(hHttpRequest, szBuffer, sizeof(szBuffer) - 1, &dwRead) && dwRead)
		{
			request_data.append(szBuffer, dwRead);
		}

		InternetCloseHandle(hHttpRequest);
		InternetCloseHandle(hHttpSession);
		InternetCloseHandle(hIntSession);

		return request_data;
	}

	std::string GetUrlData2(std::string url)
	{
		std::string request_data = "";

		HINTERNET hIntSession = InternetOpenA("", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);

		if (!hIntSession)
		{
			return request_data;
		}

		HINTERNET hHttpSession = InternetConnectA(hIntSession, HOST, 80, 0, 0, INTERNET_SERVICE_HTTP, 0, NULL);

		if (!hHttpSession)
		{
			return request_data;
		}

		HINTERNET hHttpRequest = HttpOpenRequestA(hHttpSession, "GET", url.c_str()
			, 0, 0, 0, INTERNET_FLAG_RELOAD, 0);

		if (!hHttpSession)
		{
			return request_data;
		}

		const char* szHeaders = ("");
		char szRequest[1024] = { 0 };

		if (!HttpSendRequestA(hHttpRequest, szHeaders, strlen(szHeaders), szRequest, strlen(szRequest)))
		{
			return request_data;
		}

		CHAR szBuffer[1024] = { 0 };
		DWORD dwRead = 0;

		while (InternetReadFile(hHttpRequest, szBuffer, sizeof(szBuffer) - 1, &dwRead) && dwRead)
		{
			request_data.append(szBuffer, dwRead);
		}

		InternetCloseHandle(hHttpRequest);
		InternetCloseHandle(hHttpSession);
		InternetCloseHandle(hIntSession);

		return request_data;
	}
};