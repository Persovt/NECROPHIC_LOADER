#pragma once
/*
#include <string>
#include <iostream>
#include <sstream>
#include <filesystem>
#include <filesystem>
#include <d3d9.h>
#include <vector>
#include <WinInet.h>
#include <WbemIdl.h>
#include <Tlhelp32.h>
#include <iphlpapi.h>
#include <Psapi.h>
#include <urlmon.h>
#include <d3d9.h>
#include <Psapi.h>
#include <thread>

#include <shellapi.h>
#include "string_enc.h"
#include "settings.h"
#pragma comment(lib, "Urlmon.lib")
#pragma comment(lib, "Shell32.lib")
#pragma comment(lib, "d3dx9.lib")
#include <d3dx9tex.h>
#include <windows.h>
#include <locale.h>
#include "config.h"
#include "auth.h"
#include "web.h"
#include "hwid.h"
*/
#pragma once

#define _CRT_SECURE_NO_WARNINGS

// Settings
#include "config.h"

// Important includes.
#include "windows.h"
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <d3d9.h>
#include <stdio.h>
#include <fstream>
#include <experimental/filesystem>
#include <TlHelp32.h>

// Hosts/Internet checks.
#include <WinInet.h>
#pragma comment(lib, "wininet")
#pragma comment(lib, "ws2_32.lib")

// String Encryption.
#include "string_enc.h"



// Credential
#include "settings.h"

// Interface
#include "loader.h"

// HWID
#include "hwid.h"

// Web/Auth
#include "auth.h"
#include "web.h"