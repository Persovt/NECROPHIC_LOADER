#pragma once
#include <stdio.h>
#include <tchar.h>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <tlhelp32.h>
#include <psapi.h> 
#include <sddl.h>
#include <accctrl.h>
#include <conio.h>
#include <aclapi.h>
#include "Xor.h"
#pragma comment(lib, "Ws2_32.lib")
using namespace std;


BYTE light1[3068] = {
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x78, 0x08, 0x06, 0x00, 0x00, 0x00, 0x39, 0x64, 0x36, 0xD2, 0x00, 0x00, 0x01, 0x37, 0x69, 0x43, 0x43, 0x50, 0x41, 0x64, 0x6F, 0x62, 0x65, 0x20, 0x52, 0x47, 0x42, 0x20, 0x28, 0x31, 0x39, 0x39, 0x38, 0x29, 0x00, 0x00, 0x28, 0x91, 0x95, 0x8F, 0xBF, 0x4A, 0xC3, 0x50, 0x14, 0x87, 0xBF, 0x1B, 0x45, 0xC5, 0xA1, 0x56, 0x08, 0xE2, 0xE0, 0x70, 0x27, 0x51, 0x50, 0x6C, 0xD5, 0xC1, 0x8C, 0x49, 0x5B, 0x8A, 0x20, 0x58, 0xAB, 0x43, 0x92, 0xAD, 0x49, 0x43, 0x95, 0x62, 0x12, 0x6E, 0xAE, 0x7F, 0xFA, 0x10, 0x8E, 0x6E, 0x1D, 0x5C, 0xDC, 0x7D, 0x02, 0x27, 0x47, 0xC1, 0x41, 0xF1, 0x09, 0x7C, 0x03, 0xC5, 0xA9, 0x83, 0x43, 0x84, 0x0C, 0x05, 0x8B, 0xDF, 0xF4, 0x9D, 0xDF, 0x39, 0x1C, 0xCE, 0x01, 0xA3, 0x62, 0xD7, 0x9D, 0x86, 0x51, 0x86, 0xF3, 0x58, 0xAB, 0x76, 0xD3, 0x91, 0xAE, 0xE7, 0xCB, 0xD9, 0x17, 0x66, 0x98, 0x02, 0x80, 0x4E, 0x98, 0xA5, 0x76, 0xAB, 0x75, 0x00, 0x10, 0x27, 0x71, 0xC4, 0x18, 0xDF, 0xEF, 0x08, 0x80, 0xD7, 0x4D, 0xBB, 0xEE, 0x34, 0xC6, 0xFB, 0x7F, 0x32, 0x1F, 0xA6, 0x4A, 0x03, 0x23, 0x60, 0xBB, 0x1B, 0x65, 0x21, 0x88, 0x0A, 0xD0, 0xBF, 0xD2, 0xA9, 0x06, 0x31, 0x04, 0xCC, 0xA0, 0x9F, 0x6A, 0x10, 0x0F, 0x80, 0xA9, 0x4E, 0xDA, 0x35, 0x10, 0x4F, 0x40, 0xA9, 0x97, 0xFB, 0x1B, 0x50, 0x0A, 0x72, 0xFF, 0x00, 0x4A, 0xCA, 0xF5, 0x7C, 0x10, 0x5F, 0x80, 0xD9, 0x73, 0x3D, 0x1F, 0x8C, 0x39, 0xC0, 0x0C, 0x72, 0x5F, 0x01, 0x4C, 0x1D, 0x5D, 0x6B, 0x80, 0x5A, 0x92, 0x0E, 0xD4, 0x59, 0xEF, 0x54, 0xCB, 0xAA, 0x65, 0x59, 0xD2, 0xEE, 0x26, 0x41, 0x24, 0x8F, 0x07, 0x99, 0x8E, 0xCE, 0x33, 0xB9, 0x1F, 0x87, 0x89, 0x4A, 0x13, 0xD5, 0xD1, 0x51, 0x17, 0xC8, 0xEF, 0x03, 0x60, 0x31, 0x1F, 0x6C, 0x37, 0x1D, 0xB9, 0x56, 0xB5, 0xAC, 0xBD, 0xF5, 0x7F, 0xFE, 0x3D, 0x11, 0xD7, 0xF3, 0x65, 0x6E, 0x9F, 0x47, 0x08, 0x40, 0x2C, 0x3D, 0x17, 0x59, 0x41, 0x78, 0xA1, 0x2E, 0x7F, 0x55, 0x18, 0x3B, 0x93, 0xEB, 0x62, 0xC7, 0x70, 0x19, 0x0E, 0xEF, 0x61, 0x7A, 0x54, 0x64, 0xBB, 0x37, 0x70, 0xB7, 0x01, 0x0B, 0xB7, 0x45, 0xB6, 0x5A, 0x85, 0xF2, 0x16, 0x3C, 0x0E, 0x7F, 0x00, 0xC0, 0xC6, 0x4F, 0xFD, 0xF3, 0x53, 0x3F, 0xC8, 0x00, 0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 0x00, 0x00, 0x2E, 0x23, 0x00, 0x00, 0x2E, 0x23, 0x01, 0x78, 0xA5, 0x3F, 0x76, 0x00, 0x00, 0x05, 0xF9, 0x69, 0x54, 0x58, 0x74, 0x58, 0x4D, 0x4C, 0x3A, 0x63, 0x6F, 0x6D, 0x2E, 0x61, 0x64, 0x6F, 0x62, 0x65, 0x2E, 0x78, 0x6D, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x3F, 0x78, 0x70, 0x61, 0x63, 0x6B, 0x65, 0x74, 0x20, 0x62, 0x65, 0x67, 0x69, 0x6E, 0x3D, 0x22, 0xEF, 0xBB, 0xBF, 0x22, 0x20, 0x69, 0x64, 0x3D, 0x22, 0x57, 0x35, 0x4D, 0x30, 0x4D, 0x70, 0x43, 0x65, 0x68, 0x69, 0x48, 0x7A, 0x72, 0x65, 0x53, 0x7A, 0x4E, 0x54, 0x63, 0x7A, 0x6B, 0x63, 0x39, 0x64, 0x22, 0x3F, 0x3E, 0x20, 0x3C, 0x78, 0x3A, 0x78, 0x6D, 0x70, 0x6D, 0x65, 0x74, 0x61, 0x20, 0x78, 0x6D, 0x6C, 0x6E, 0x73, 0x3A, 0x78, 0x3D, 0x22, 0x61, 0x64, 0x6F, 0x62, 0x65, 0x3A, 0x6E, 0x73, 0x3A, 0x6D, 0x65, 0x74, 0x61, 0x2F, 0x22, 0x20, 0x78, 0x3A, 0x78, 0x6D, 0x70, 0x74, 0x6B, 0x3D, 0x22, 0x41, 0x64, 0x6F, 0x62, 0x65, 0x20, 0x58, 0x4D, 0x50, 0x20, 0x43, 0x6F, 0x72, 0x65, 0x20, 0x35, 0x2E, 0x36, 0x2D, 0x63, 0x31, 0x34, 0x35, 0x20, 0x37, 0x39, 0x2E, 0x31, 0x36, 0x33, 0x34, 0x39, 0x39, 0x2C, 0x20, 0x32, 0x30, 0x31, 0x38, 0x2F, 0x30, 0x38, 0x2F, 0x31, 0x33, 0x2D, 0x31, 0x36, 0x3A, 0x34, 0x30, 0x3A, 0x32, 0x32, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x22, 0x3E, 0x20, 0x3C, 0x72, 0x64, 0x66, 0x3A, 0x52, 0x44, 0x46, 0x20, 0x78, 0x6D, 0x6C, 0x6E, 0x73, 0x3A, 0x72, 0x64, 0x66, 0x3D, 0x22, 0x68, 0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 0x77, 0x77, 0x77, 0x2E, 0x77, 0x33, 0x2E, 0x6F, 0x72, 0x67, 0x2F, 0x31, 0x39, 0x39, 0x39, 0x2F, 0x30, 0x32, 0x2F, 0x32, 0x32, 0x2D, 0x72, 0x64, 0x66, 0x2D, 0x73, 0x79, 0x6E, 0x74, 0x61, 0x78, 0x2D, 0x6E, 0x73, 0x23, 0x22, 0x3E, 0x20, 0x3C, 0x72, 0x64, 0x66, 0x3A, 0x44, 0x65, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x69, 0x6F, 0x6E, 0x20, 0x72, 0x64, 0x66, 0x3A, 0x61, 0x62, 0x6F, 0x75, 0x74, 0x3D, 0x22, 0x22, 0x20, 0x78, 0x6D, 0x6C, 0x6E, 0x73, 0x3A, 0x78, 0x6D, 0x70, 0x3D, 0x22, 0x68, 0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 0x6E, 0x73, 0x2E, 0x61, 0x64, 0x6F, 0x62, 0x65, 0x2E, 0x63, 0x6F, 0x6D, 0x2F, 0x78, 0x61, 0x70, 0x2F, 0x31, 0x2E, 0x30, 0x2F, 0x22, 0x20, 0x78, 0x6D, 0x6C, 0x6E, 0x73, 0x3A, 0x78, 0x6D, 0x70, 0x4D, 0x4D, 0x3D, 0x22, 0x68, 0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 0x6E, 0x73, 0x2E, 0x61, 0x64, 0x6F, 0x62, 0x65, 0x2E, 0x63, 0x6F, 0x6D, 0x2F, 0x78, 0x61, 0x70, 0x2F, 0x31, 0x2E, 0x30, 0x2F, 0x6D, 0x6D, 0x2F, 0x22, 0x20, 0x78, 0x6D, 0x6C, 0x6E, 0x73, 0x3A, 0x73, 0x74, 0x45, 0x76, 0x74, 0x3D, 0x22, 0x68, 0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 0x6E, 0x73, 0x2E, 0x61, 0x64, 0x6F, 0x62, 0x65, 0x2E, 0x63, 0x6F, 0x6D, 0x2F, 0x78, 0x61, 0x70, 0x2F, 0x31, 0x2E, 0x30, 0x2F, 0x73, 0x54, 0x79, 0x70, 0x65, 0x2F, 0x52, 0x65, 0x73, 0x6F, 0x75, 0x72, 0x63, 0x65, 0x45, 0x76, 0x65, 0x6E, 0x74, 0x23, 0x22, 0x20, 0x78, 0x6D, 0x6C, 0x6E, 0x73, 0x3A, 0x64, 0x63, 0x3D, 0x22, 0x68, 0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 0x70, 0x75, 0x72, 0x6C, 0x2E, 0x6F, 0x72, 0x67, 0x2F, 0x64, 0x63, 0x2F, 0x65, 0x6C, 0x65, 0x6D, 0x65, 0x6E, 0x74, 0x73, 0x2F, 0x31, 0x2E, 0x31, 0x2F, 0x22, 0x20, 0x78, 0x6D, 0x6C, 0x6E, 0x73, 0x3A, 0x70, 0x68, 0x6F, 0x74, 0x6F, 0x73, 0x68, 0x6F, 0x70, 0x3D, 0x22, 0x68, 0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 0x6E, 0x73, 0x2E, 0x61, 0x64, 0x6F, 0x62, 0x65, 0x2E, 0x63, 0x6F, 0x6D, 0x2F, 0x70, 0x68, 0x6F, 0x74, 0x6F, 0x73, 0x68, 0x6F, 0x70, 0x2F, 0x31, 0x2E, 0x30, 0x2F, 0x22, 0x20, 0x78, 0x6D, 0x70, 0x3A, 0x43, 0x72, 0x65, 0x61, 0x74, 0x6F, 0x72, 0x54, 0x6F, 0x6F, 0x6C, 0x3D, 0x22, 0x41, 0x64, 0x6F, 0x62, 0x65, 0x20, 0x50, 0x68, 0x6F, 0x74, 0x6F, 0x73, 0x68, 0x6F, 0x70, 0x20, 0x43, 0x43, 0x20, 0x32, 0x30, 0x31, 0x39, 0x20, 0x28, 0x57, 0x69, 0x6E, 0x64, 0x6F, 0x77, 0x73, 0x29, 0x22, 0x20, 0x78, 0x6D, 0x70, 0x3A, 0x43, 0x72, 0x65, 0x61, 0x74, 0x65, 0x44, 0x61, 0x74, 0x65, 0x3D, 0x22, 0x32, 0x30, 0x31, 0x39, 0x2D, 0x30, 0x38, 0x2D, 0x32, 0x38, 0x54, 0x30, 0x39, 0x3A, 0x35, 0x31, 0x3A, 0x32, 0x34, 0x2B, 0x30, 0x33, 0x3A, 0x30, 0x30, 0x22, 0x20, 0x78, 0x6D, 0x70, 0x3A, 0x4D, 0x65, 0x74, 0x61, 0x64, 0x61, 0x74, 0x61, 0x44, 0x61, 0x74, 0x65, 0x3D, 0x22, 0x32, 0x30, 0x31, 0x39, 0x2D, 0x30, 0x38, 0x2D, 0x32, 0x38, 0x54, 0x30, 0x39, 0x3A, 0x35, 0x31, 0x3A, 0x32, 0x34, 0x2B, 0x30, 0x33, 0x3A, 0x30, 0x30, 0x22, 0x20, 0x78, 0x6D, 0x70, 0x3A, 0x4D, 0x6F, 0x64, 0x69, 0x66, 0x79, 0x44, 0x61, 0x74, 0x65, 0x3D, 0x22, 0x32, 0x30, 0x31, 0x39, 0x2D, 0x30, 0x38, 0x2D, 0x32, 0x38, 0x54, 0x30, 0x39, 0x3A, 0x35, 0x31, 0x3A, 0x32, 0x34, 0x2B, 0x30, 0x33, 0x3A, 0x30, 0x30, 0x22, 0x20, 0x78, 0x6D, 0x70, 0x4D, 0x4D, 0x3A, 0x49, 0x6E, 0x73, 0x74, 0x61, 0x6E, 0x63, 0x65, 0x49, 0x44, 0x3D, 0x22, 0x78, 0x6D, 0x70, 0x2E, 0x69, 0x69, 0x64, 0x3A, 0x66, 0x30, 0x30, 0x33, 0x38, 0x63, 0x34, 0x36, 0x2D, 0x36, 0x39, 0x39, 0x30, 0x2D, 0x63, 0x32, 0x34, 0x38, 0x2D, 0x38, 0x34, 0x31, 0x63, 0x2D, 0x32, 0x66, 0x65, 0x32, 0x34, 0x65, 0x34, 0x37, 0x32, 0x61, 0x36, 0x65, 0x22, 0x20, 0x78, 0x6D, 0x70, 0x4D, 0x4D, 0x3A, 0x44, 0x6F, 0x63, 0x75, 0x6D, 0x65, 0x6E, 0x74, 0x49, 0x44, 0x3D, 0x22, 0x61, 0x64, 0x6F, 0x62, 0x65, 0x3A, 0x64, 0x6F, 0x63, 0x69, 0x64, 0x3A, 0x70, 0x68, 0x6F, 0x74, 0x6F, 0x73, 0x68, 0x6F, 0x70, 0x3A, 0x65, 0x31, 0x64, 0x36, 0x32, 0x65, 0x32, 0x66, 0x2D, 0x32, 0x66, 0x31, 0x37, 0x2D, 0x33, 0x37, 0x34, 0x66, 0x2D, 0x62, 0x32, 0x37, 0x32, 0x2D, 0x64, 0x36, 0x34, 0x64, 0x36, 0x30, 0x66, 0x64, 0x38, 0x37, 0x64, 0x64, 0x22, 0x20, 0x78, 0x6D, 0x70, 0x4D, 0x4D, 0x3A, 0x4F, 0x72, 0x69, 0x67, 0x69, 0x6E, 0x61, 0x6C, 0x44, 0x6F, 0x63, 0x75, 0x6D, 0x65, 0x6E, 0x74, 0x49, 0x44, 0x3D, 0x22, 0x78, 0x6D, 0x70, 0x2E, 0x64, 0x69, 0x64, 0x3A, 0x35, 0x62, 0x62, 0x65, 0x31, 0x34, 0x64, 0x61, 0x2D, 0x66, 0x31, 0x35, 0x34, 0x2D, 0x38, 0x66, 0x34, 0x38, 0x2D, 0x62, 0x33, 0x39, 0x62, 0x2D, 0x32, 0x62, 0x36, 0x33, 0x66, 0x39, 0x33, 0x62, 0x34, 0x34, 0x30, 0x34, 0x22, 0x20, 0x64, 0x63, 0x3A, 0x66, 0x6F, 0x72, 0x6D, 0x61, 0x74, 0x3D, 0x22, 0x69, 0x6D, 0x61, 0x67, 0x65, 0x2F, 0x70, 0x6E, 0x67, 0x22, 0x20, 0x70, 0x68, 0x6F, 0x74, 0x6F, 0x73, 0x68, 0x6F, 0x70, 0x3A, 0x43, 0x6F, 0x6C, 0x6F, 0x72, 0x4D, 0x6F, 0x64, 0x65, 0x3D, 0x22, 0x33, 0x22, 0x20, 0x70, 0x68, 0x6F, 0x74, 0x6F, 0x73, 0x68, 0x6F, 0x70, 0x3A, 0x49, 0x43, 0x43, 0x50, 0x72, 0x6F, 0x66, 0x69, 0x6C, 0x65, 0x3D, 0x22, 0x41, 0x64, 0x6F, 0x62, 0x65, 0x20, 0x52, 0x47, 0x42, 0x20, 0x28, 0x31, 0x39, 0x39, 0x38, 0x29, 0x22, 0x3E, 0x20, 0x3C, 0x78, 0x6D, 0x70, 0x4D, 0x4D, 0x3A, 0x48, 0x69, 0x73, 0x74, 0x6F, 0x72, 0x79, 0x3E, 0x20, 0x3C, 0x72, 0x64, 0x66, 0x3A, 0x53, 0x65, 0x71, 0x3E, 0x20, 0x3C, 0x72, 0x64, 0x66, 0x3A, 0x6C, 0x69, 0x20, 0x73, 0x74, 0x45, 0x76, 0x74, 0x3A, 0x61, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x3D, 0x22, 0x63, 0x72, 0x65, 0x61, 0x74, 0x65, 0x64, 0x22, 0x20, 0x73, 0x74, 0x45, 0x76, 0x74, 0x3A, 0x69, 0x6E, 0x73, 0x74, 0x61, 0x6E, 0x63, 0x65, 0x49, 0x44, 0x3D, 0x22, 0x78, 0x6D, 0x70, 0x2E, 0x69, 0x69, 0x64, 0x3A, 0x35, 0x62, 0x62, 0x65, 0x31, 0x34, 0x64, 0x61, 0x2D, 0x66, 0x31, 0x35, 0x34, 0x2D, 0x38, 0x66, 0x34, 0x38, 0x2D, 0x62, 0x33, 0x39, 0x62, 0x2D, 0x32, 0x62, 0x36, 0x33, 0x66, 0x39, 0x33, 0x62, 0x34, 0x34, 0x30, 0x34, 0x22, 0x20, 0x73, 0x74, 0x45, 0x76, 0x74, 0x3A, 0x77, 0x68, 0x65, 0x6E, 0x3D, 0x22, 0x32, 0x30, 0x31, 0x39, 0x2D, 0x30, 0x38, 0x2D, 0x32, 0x38, 0x54, 0x30, 0x39, 0x3A, 0x35, 0x31, 0x3A, 0x32, 0x34, 0x2B, 0x30, 0x33, 0x3A, 0x30, 0x30, 0x22, 0x20, 0x73, 0x74, 0x45, 0x76, 0x74, 0x3A, 0x73, 0x6F, 0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x41, 0x67, 0x65, 0x6E, 0x74, 0x3D, 0x22, 0x41, 0x64, 0x6F, 0x62, 0x65, 0x20, 0x50, 0x68, 0x6F, 0x74, 0x6F, 0x73, 0x68, 0x6F, 0x70, 0x20, 0x43, 0x43, 0x20, 0x32, 0x30, 0x31, 0x39, 0x20, 0x28, 0x57, 0x69, 0x6E, 0x64, 0x6F, 0x77, 0x73, 0x29, 0x22, 0x2F, 0x3E, 0x20, 0x3C, 0x72, 0x64, 0x66, 0x3A, 0x6C, 0x69, 0x20, 0x73, 0x74, 0x45, 0x76, 0x74, 0x3A, 0x61, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x3D, 0x22, 0x73, 0x61, 0x76, 0x65, 0x64, 0x22, 0x20, 0x73, 0x74, 0x45, 0x76, 0x74, 0x3A, 0x69, 0x6E, 0x73, 0x74, 0x61, 0x6E, 0x63, 0x65, 0x49, 0x44, 0x3D, 0x22, 0x78, 0x6D, 0x70, 0x2E, 0x69, 0x69, 0x64, 0x3A, 0x66, 0x30, 0x30, 0x33, 0x38, 0x63, 0x34, 0x36, 0x2D, 0x36, 0x39, 0x39, 0x30, 0x2D, 0x63, 0x32, 0x34, 0x38, 0x2D, 0x38, 0x34, 0x31, 0x63, 0x2D, 0x32, 0x66, 0x65, 0x32, 0x34, 0x65, 0x34, 0x37, 0x32, 0x61, 0x36, 0x65, 0x22, 0x20, 0x73, 0x74, 0x45, 0x76, 0x74, 0x3A, 0x77, 0x68, 0x65, 0x6E, 0x3D, 0x22, 0x32, 0x30, 0x31, 0x39, 0x2D, 0x30, 0x38, 0x2D, 0x32, 0x38, 0x54, 0x30, 0x39, 0x3A, 0x35, 0x31, 0x3A, 0x32, 0x34, 0x2B, 0x30, 0x33, 0x3A, 0x30, 0x30, 0x22, 0x20, 0x73, 0x74, 0x45, 0x76, 0x74, 0x3A, 0x73, 0x6F, 0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x41, 0x67, 0x65, 0x6E, 0x74, 0x3D, 0x22, 0x41, 0x64, 0x6F, 0x62, 0x65, 0x20, 0x50, 0x68, 0x6F, 0x74, 0x6F, 0x73, 0x68, 0x6F, 0x70, 0x20, 0x43, 0x43, 0x20, 0x32, 0x30, 0x31, 0x39, 0x20, 0x28, 0x57, 0x69, 0x6E, 0x64, 0x6F, 0x77, 0x73, 0x29, 0x22, 0x20, 0x73, 0x74, 0x45, 0x76, 0x74, 0x3A, 0x63, 0x68, 0x61, 0x6E, 0x67, 0x65, 0x64, 0x3D, 0x22, 0x2F, 0x22, 0x2F, 0x3E, 0x20, 0x3C, 0x2F, 0x72, 0x64, 0x66, 0x3A, 0x53, 0x65, 0x71, 0x3E, 0x20, 0x3C, 0x2F, 0x78, 0x6D, 0x70, 0x4D, 0x4D, 0x3A, 0x48, 0x69, 0x73, 0x74, 0x6F, 0x72, 0x79, 0x3E, 0x20, 0x3C, 0x2F, 0x72, 0x64, 0x66, 0x3A, 0x44, 0x65, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x69, 0x6F, 0x6E, 0x3E, 0x20, 0x3C, 0x2F, 0x72, 0x64, 0x66, 0x3A, 0x52, 0x44, 0x46, 0x3E, 0x20, 0x3C, 0x2F, 0x78, 0x3A, 0x78, 0x6D, 0x70, 0x6D, 0x65, 0x74, 0x61, 0x3E, 0x20, 0x3C, 0x3F, 0x78, 0x70, 0x61, 0x63, 0x6B, 0x65, 0x74, 0x20, 0x65, 0x6E, 0x64, 0x3D, 0x22, 0x72, 0x22, 0x3F, 0x3E, 0x1E, 0x79, 0x85, 0x7C, 0x00, 0x00, 0x04, 0x66, 0x49, 0x44, 0x41, 0x54, 0x78, 0x9C, 0xED, 0x9D, 0x6D, 0x7A, 0xE2, 0x3A, 0x0C, 0x46, 0x5F, 0x99, 0x90, 0xD0, 0x59, 0xDE, 0x2C, 0xE4, 0x2E, 0x66, 0x16, 0x32, 0xCB, 0x9B, 0x92, 0x0F, 0xAC, 0xFB, 0x03, 0x32, 0x65, 0x18, 0x98, 0xB4, 0x10, 0x59, 0xB2, 0xA2, 0xC3, 0xDF, 0x3E, 0x58, 0xD6, 0xA9, 0x6C, 0xA7, 0xB6, 0x53, 0x62, 0x66, 0x04, 0x7E, 0x49, 0xDA, 0x01, 0x04, 0xB2, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x84, 0x60, 0xE7, 0x34, 0xDA, 0x01, 0x94, 0xE0, 0x27, 0x7E, 0xDC, 0x3D, 0x1B, 0xFC, 0x1D, 0xFF, 0x51, 0xE9, 0x58, 0x4A, 0x43, 0x1E, 0xCF, 0x45, 0x3F, 0x12, 0xBA, 0x84, 0x47, 0xE1, 0x2E, 0x04, 0x3F, 0x2B, 0x74, 0x09, 0x0F, 0xC2, 0xAB, 0x15, 0x2C, 0x25, 0xF5, 0x11, 0xB5, 0xCA, 0xAE, 0x46, 0x70, 0x69, 0xA1, 0x4B, 0xD4, 0x22, 0xDC, 0xBC, 0x60, 0x6B, 0x62, 0x6F, 0xB1, 0x2E, 0xDA, 0xF4, 0x63, 0x92, 0x75, 0xB9, 0x80, 0xFD, 0x18, 0x4D, 0x56, 0xB0, 0xF5, 0xA4, 0x3D, 0xC2, 0x62, 0x35, 0x9B, 0xAB, 0xE0, 0x5A, 0xE5, 0x02, 0x36, 0x63, 0x37, 0x25, 0xD8, 0x62, 0x82, 0xBE, 0x8A, 0xB5, 0x3E, 0x98, 0x11, 0x6C, 0x2D, 0x31, 0xAF, 0x60, 0xA9, 0x2F, 0xEA, 0x73, 0xB0, 0xA5, 0x64, 0x48, 0xA0, 0x3D, 0x2F, 0xAB, 0x56, 0xB0, 0x77, 0xB9, 0x80, 0x7E, 0x1F, 0xD5, 0x04, 0x6B, 0x77, 0xBC, 0x24, 0x9A, 0x7D, 0x55, 0x11, 0xBC, 0x25, 0xB9, 0x33, 0x5A, 0x7D, 0x36, 0xB3, 0xC8, 0x0A, 0x64, 0x28, 0x2E, 0x78, 0x8B, 0xD5, 0x3B, 0xA3, 0xD1, 0xF7, 0xA2, 0x82, 0xB7, 0x2C, 0x77, 0xA6, 0x74, 0x0E, 0x8A, 0x09, 0x0E, 0xB9, 0x1F, 0x94, 0xCC, 0x45, 0x11, 0xC1, 0x21, 0xF7, 0x6F, 0x4A, 0xE5, 0x24, 0x16, 0x59, 0xCE, 0x11, 0x17, 0x1C, 0xD5, 0xFB, 0x98, 0x12, 0xB9, 0x11, 0x15, 0x1C, 0x72, 0x97, 0x91, 0xCE, 0x91, 0xDB, 0x63, 0xB3, 0x99, 0x4F, 0x98, 0x30, 0x22, 0xF3, 0x09, 0x99, 0x33, 0xF8, 0xF2, 0x01, 0x00, 0xBA, 0x7C, 0x12, 0x25, 0x24, 0xDA, 0xA1, 0xC1, 0x1E, 0x89, 0x76, 0xCA, 0x11, 0xCB, 0xE0, 0x4A, 0x30, 0x73, 0xC6, 0xC0, 0x3D, 0x26, 0x9E, 0xC0, 0xC8, 0x8F, 0x7F, 0xEE, 0xF2, 0xC9, 0x9C, 0x01, 0x9E, 0x30, 0xA0, 0x07, 0x21, 0xA1, 0xA1, 0x06, 0x2D, 0x75, 0x20, 0xF2, 0xB3, 0x34, 0x11, 0xDB, 0x4D, 0x2A, 0x39, 0x3C, 0xCF, 0x62, 0x47, 0xEE, 0x01, 0xBC, 0xBA, 0x79, 0xC3, 0xD8, 0x53, 0x87, 0x36, 0x75, 0xA0, 0x82, 0x6B, 0x50, 0xA9, 0x5D, 0xA7, 0xEA, 0x2B, 0x78, 0xE4, 0x01, 0x43, 0x3E, 0x5E, 0x86, 0xDF, 0x35, 0x72, 0x44, 0x18, 0x79, 0xC0, 0x74, 0x1A, 0xD1, 0xA6, 0x03, 0xF6, 0xD4, 0xAE, 0xF0, 0x9D, 0x7A, 0x54, 0x2D, 0xF8, 0x98, 0xDF, 0x31, 0xF1, 0x20, 0xF2, 0xDD, 0x0C, 0x46, 0x9F, 0xDF, 0x71, 0xA2, 0x13, 0x0E, 0xE9, 0x4D, 0xA4, 0x8D, 0x12, 0x54, 0x3B, 0xD9, 0x1C, 0xF3, 0x2F, 0x31, 0xB9, 0xD7, 0x4C, 0x3C, 0xE0, 0x98, 0x7F, 0x89, 0xB7, 0x23, 0x85, 0x88, 0x60, 0xE9, 0xF9, 0xF7, 0x5C, 0xB9, 0xA3, 0x64, 0x13, 0x7F, 0x30, 0xF1, 0x88, 0x3E, 0xBF, 0x8B, 0xB6, 0x21, 0x95, 0xB3, 0xEA, 0x2A, 0x78, 0xE2, 0xA1, 0x48, 0xE5, 0xDE, 0x32, 0x2A, 0xB5, 0xFB, 0x2A, 0x55, 0x09, 0x66, 0x64, 0xF4, 0xF9, 0xA8, 0xD6, 0x7E, 0x9F, 0x8F, 0xFF, 0x7C, 0xFC, 0xB2, 0x48, 0x55, 0x82, 0x87, 0xDC, 0xFF, 0xFE, 0x63, 0x85, 0x06, 0x0C, 0xC6, 0x90, 0x7B, 0xB5, 0xF6, 0x9F, 0x61, 0x75, 0xC1, 0x72, 0xF3, 0x2F, 0x17, 0x9D, 0x77, 0x1F, 0x31, 0xF2, 0x00, 0x08, 0xFD, 0x92, 0x49, 0xE4, 0xAE, 0x9A, 0x0A, 0x9E, 0x78, 0x54, 0xAD, 0xDE, 0x6B, 0x2C, 0xFC, 0xA2, 0x7D, 0x96, 0x8A, 0x04, 0x4F, 0xDA, 0x21, 0xFC, 0xC6, 0x52, 0x2C, 0x4B, 0xAC, 0x2A, 0x58, 0xF2, 0xF1, 0x28, 0xF3, 0x49, 0xEA, 0xAB, 0xBF, 0x8C, 0x64, 0x2C, 0x6B, 0xE7, 0xB0, 0x9A, 0x0A, 0xB6, 0x31, 0x38, 0x9F, 0xB1, 0x14, 0xCB, 0x12, 0x15, 0x09, 0xB6, 0xF3, 0x78, 0x62, 0x29, 0x96, 0x25, 0xAA, 0x11, 0x5C, 0x72, 0x67, 0x67, 0x09, 0x4B, 0xB1, 0x2C, 0x51, 0x4D, 0xA4, 0x96, 0x6E, 0x56, 0x5B, 0x8A, 0x65, 0x89, 0x55, 0x05, 0x4B, 0xDE, 0xA4, 0xB3, 0x74, 0xE2, 0x42, 0x32, 0x96, 0xB5, 0x73, 0x58, 0x4D, 0x05, 0x37, 0x64, 0x67, 0x67, 0xD3, 0x52, 0x2C, 0x4B, 0x54, 0x24, 0x78, 0xAF, 0x1D, 0x02, 0x80, 0xF3, 0x79, 0x2E, 0x2B, 0xB1, 0x7C, 0x86, 0xD5, 0x05, 0xCB, 0x0D, 0xD3, 0x64, 0xE2, 0x74, 0xC5, 0x59, 0xAE, 0x4C, 0x17, 0x25, 0x72, 0x57, 0x4D, 0x05, 0x03, 0xB8, 0x9C, 0x93, 0xD2, 0x5B, 0xE2, 0x10, 0x08, 0x6D, 0xEA, 0xD4, 0xDA, 0x7F, 0x86, 0xAA, 0x04, 0x13, 0x12, 0xBA, 0x74, 0x50, 0x6B, 0xBF, 0x4B, 0x87, 0xAA, 0x1E, 0x91, 0x80, 0xCA, 0x04, 0x03, 0x40, 0x43, 0xAD, 0xCA, 0x50, 0xBD, 0xA7, 0x16, 0x8D, 0x81, 0x29, 0xE2, 0xAB, 0x88, 0x08, 0x96, 0x7E, 0xF1, 0x48, 0x97, 0xDE, 0x8A, 0x2E, 0x74, 0x1A, 0xDA, 0xA3, 0x13, 0x3E, 0x78, 0x27, 0x95, 0xB3, 0xEA, 0x2A, 0x78, 0xE6, 0x90, 0xBE, 0x15, 0xA9, 0xA8, 0x86, 0x5A, 0x1C, 0xD2, 0x37, 0xF1, 0x76, 0xA4, 0xA8, 0xE7, 0x81, 0xEE, 0x0E, 0x87, 0xF4, 0x86, 0x91, 0x77, 0x57, 0xE7, 0xA2, 0xD7, 0xE3, 0xBC, 0xA0, 0x8A, 0x73, 0xD1, 0xEA, 0xEC, 0xA9, 0x45, 0x93, 0x1A, 0xF4, 0x7C, 0xBC, 0x1C, 0x8A, 0x7B, 0xFD, 0x66, 0x43, 0x43, 0x6D, 0x95, 0x0B, 0xAA, 0x7B, 0x88, 0xBE, 0x08, 0xAD, 0xF4, 0xED, 0xC2, 0xCF, 0xDE, 0x4D, 0xBA, 0x87, 0xE6, 0xDD, 0x24, 0xC9, 0x35, 0x4B, 0xF5, 0x15, 0x7C, 0x0D, 0x51, 0x42, 0x47, 0x6F, 0xE8, 0xF0, 0xE7, 0xED, 0x42, 0x66, 0x46, 0x46, 0xC6, 0xC7, 0x4E, 0x2E, 0x21, 0x21, 0x81, 0x88, 0xE2, 0x76, 0x61, 0xAD, 0x24, 0xDA, 0xA1, 0xC5, 0xAE, 0xAE, 0xAD, 0x1F, 0x01, 0x44, 0xC7, 0x22, 0xED, 0xF7, 0x34, 0xD6, 0x80, 0x74, 0x8E, 0xC4, 0x27, 0x9B, 0x90, 0xFC, 0x98, 0x12, 0xB9, 0xA9, 0x7F, 0x99, 0x18, 0xFC, 0x93, 0x22, 0x82, 0xA3, 0x8A, 0xFF, 0xA6, 0x54, 0x4E, 0x8A, 0x55, 0x70, 0x48, 0xFE, 0xA0, 0x64, 0x2E, 0x8A, 0x0E, 0xD1, 0x21, 0xB9, 0x7C, 0x0E, 0x8A, 0xCF, 0xC1, 0x5B, 0x96, 0xAC, 0xD1, 0xF7, 0x58, 0x64, 0x39, 0x47, 0x45, 0xF0, 0x16, 0xAB, 0x58, 0xAB, 0xCF, 0x6A, 0x15, 0xBC, 0x25, 0xC9, 0x9A, 0x7D, 0x55, 0x1D, 0xA2, 0xB7, 0x20, 0x59, 0xBB, 0x8F, 0xEA, 0xFF, 0x56, 0x67, 0xC6, 0xDB, 0x7B, 0x2D, 0xB5, 0xC5, 0xCE, 0x98, 0x59, 0x64, 0x59, 0x49, 0xC8, 0x1A, 0x58, 0xEA, 0x8B, 0x19, 0xC1, 0x80, 0xAD, 0xC4, 0x3C, 0x8B, 0xB5, 0x3E, 0x98, 0x12, 0x0C, 0xD8, 0x4B, 0xD0, 0x57, 0xB0, 0x18, 0xBB, 0x99, 0x39, 0xF8, 0x1E, 0xB5, 0xCC, 0xCB, 0x16, 0xC5, 0xCE, 0x98, 0xAB, 0xE0, 0x6B, 0x2C, 0x27, 0x6E, 0xC6, 0x7A, 0x8C, 0xA6, 0x2B, 0xF8, 0x1A, 0x6B, 0xD5, 0x6C, 0x5D, 0xEC, 0x4C, 0x35, 0x82, 0x6F, 0x29, 0x2D, 0xBC, 0x16, 0xA1, 0xB7, 0x54, 0x2B, 0xF8, 0x1A, 0x29, 0xD9, 0xB5, 0x4A, 0xBD, 0xC6, 0x85, 0xE0, 0x5B, 0x9E, 0x15, 0xEE, 0x41, 0xE8, 0x2D, 0x2E, 0x05, 0xDF, 0xF2, 0x48, 0xB8, 0x47, 0xA1, 0xB7, 0x6C, 0x42, 0xF0, 0x96, 0x31, 0xFD, 0x98, 0x14, 0xBC, 0x4E, 0x08, 0x76, 0x4E, 0x08, 0x76, 0x4E, 0x08, 0x76, 0x4E, 0x08, 0x76, 0x4E, 0x08, 0x76, 0x4E, 0x08, 0x76, 0x4E, 0x08, 0x76, 0x4E, 0x08, 0x76, 0x4E, 0x08, 0x76, 0x4E, 0x08, 0x76, 0x4E, 0x08, 0x76, 0x4E, 0x08, 0x76, 0x4E, 0x08, 0x76, 0x4E, 0x08, 0x76, 0x4E, 0x08, 0x76, 0x4E, 0x08, 0x76, 0x4E, 0x08, 0x76, 0x4E, 0x08, 0x76, 0xCE, 0xFF, 0xB5, 0x32, 0x94, 0xD5, 0x6F, 0x9B, 0x0B, 0x8F, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82
};