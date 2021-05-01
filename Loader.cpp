#include "WndProc.h"
#include <fstream>
#include <urlmon.h>
#include <io.h>
#include "RawD.h"
#include "mmap.h"
#include "xor.h"
#include "mmap.h"
#include "antire.h"
#include "sh.h"

#include "light.h"

#include "loader.h"

#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

#include <TlHelp32.h>

#include "imgui\imgui.h"
#include "imgui\imgui_impl_dx9.h"
#include "imgui\imgui_internal.h"

LPCTSTR lpzClass = CHEATNAME;
bool server = false;


//static bool SpectroLicense = CheckLicense();

IDirect3DTexture9 *light = nullptr;

ImFont* globalFont = nullptr;
ImFont* bigFont = nullptr;
ImFont* lowFont = nullptr;
ImFont*  forTabs = nullptr;

const std::string GetTempDir()
{
	char buf[MAX_PATH];
	GetTempPathA(MAX_PATH, buf);
	std::string g_TempPath = buf;
	GetLongPathNameA(g_TempPath.c_str(), buf, MAX_PATH);
	g_TempPath = buf;
	return g_TempPath;
}

bool IsHTTPDebuggerInstalled()
{
	LPVOID drivers[2048];
	DWORD cbNeeded;
	int cDrivers, i;
	if (EnumDeviceDrivers(drivers, sizeof(drivers), &cbNeeded) && cbNeeded < sizeof(drivers))
	{
		TCHAR szDriver[2048];
		cDrivers = cbNeeded / sizeof(drivers[0]);
		for (i = 0; i < cDrivers; i++)
		{
			if (GetDeviceDriverBaseName(drivers[i], szDriver, sizeof(szDriver) / sizeof(szDriver[0])))
			{
				std::string strDriver = szDriver;
				if (strDriver.find("HttpDebug") != std::string::npos)
					return false;
			}
		}
	}
	return true;
}
ATOM RegMyWindowClass(HINSTANCE, LPCTSTR);
void ToClipboard(const char* text)
{
	if (OpenClipboard(0))
	{
		EmptyClipboard();
		char* clip_data = (char*)(GlobalAlloc(GMEM_FIXED, MAX_PATH));
		lstrcpy(clip_data, text);
		SetClipboardData(CF_TEXT, (HANDLE)(clip_data));
		LCID* lcid = (DWORD*)(GlobalAlloc(GMEM_FIXED, sizeof(DWORD)));
		*lcid = MAKELCID(MAKELANGID(LANG_RUSSIAN, SUBLANG_NEUTRAL), SORT_DEFAULT);
		SetClipboardData(CF_LOCALE, (HANDLE)(lcid));
		CloseClipboard();
	}
}
const static int listbox_item_current = 0;





bool IsProcessRun(const char * const processName)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hSnapshot, &pe);

	while (1) {
		if (strcmp(pe.szExeFile, processName) == 0) return true;
		if (!Process32Next(hSnapshot, &pe)) return false;
	}
}
void Cheack()
{


	if (InternetCheckConnection("https://www.google.ru", FLAG_ICC_FORCE_CONNECTION, 0))
	{
		MessageBox(0, "No internet connection", "Cheack connection", MB_OK);
		exit(0);
	}
}
void injecting()
{
	PVOID rData = reinterpret_cast<char*>(rawData);
	//
	pIDH = (PIMAGE_DOS_HEADER)/*Memory*/rData;
	pINH = (PIMAGE_NT_HEADERS)((LPBYTE)/*Memory*/rData + pIDH->e_lfanew);
	DWORD pid = MyGetProcessId(/*Process Name*/"csgo.exe");
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	image = VirtualAllocEx(hProcess, NULL, pINH->OptionalHeader.SizeOfImage, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	WriteProcessMemory(hProcess, image, /*Memory*/rData, pINH->OptionalHeader.SizeOfHeaders, NULL);
	pISH = (PIMAGE_SECTION_HEADER)(pINH + 1);
	for (i = 0; i < pINH->FileHeader.NumberOfSections; i++)
	{
		WriteProcessMemory(hProcess, (PVOID)((LPBYTE)image + pISH[i].VirtualAddress),
			(PVOID)((LPBYTE)rData/*Memory*/ + pISH[i].PointerToRawData), pISH[i].SizeOfRawData, NULL);
	}
	mem = VirtualAllocEx(hProcess, NULL, 4096, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	memset(&ManualInject, 0, sizeof(MANUAL_INJECT));
	ManualInject.ImageBase = image;
	ManualInject.NtHeaders = (PIMAGE_NT_HEADERS)((LPBYTE)image + pIDH->e_lfanew);
	ManualInject.BaseRelocation = (PIMAGE_BASE_RELOCATION)((LPBYTE)image + pINH->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress);
	ManualInject.ImportDirectory = (PIMAGE_IMPORT_DESCRIPTOR)((LPBYTE)image + pINH->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);
	ManualInject.fnLoadLibraryA = LoadLibraryA;
	ManualInject.fnGetProcAddress = GetProcAddress;
	WriteProcessMemory(hProcess, mem, &ManualInject, sizeof(MANUAL_INJECT), NULL);
	WriteProcessMemory(hProcess, (PVOID)((PMANUAL_INJECT)mem + 1), LoadDll, (DWORD)LoadDllEnd - (DWORD)LoadDll, NULL);
	hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)((PMANUAL_INJECT)mem + 1), mem, 0, NULL);
	WaitForSingleObject(hThread, INFINITE);
	GetExitCodeThread(hThread, &ExitCode);
	
}

HANDLE GetProcessHandle(LPSTR szExeName)
{
	PROCESSENTRY32 Pc = { sizeof(PROCESSENTRY32) };
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
	if (Process32First(hSnapshot, &Pc)) {
		do {
			if (!strcmp(Pc.szExeFile, szExeName)) {
				return OpenProcess(PROCESS_ALL_ACCESS, TRUE, Pc.th32ProcessID);
			}
		} while (Process32Next(hSnapshot, &Pc));
	}
	return NULL;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
	//Cheack();

	

	// регистраци€ класса
	if (!RegMyWindowClass(hInstance, lpzClass))
		return 1;

	// вычисление координат центра экрана
	RECT screen_rect;
	GetWindowRect(GetDesktopWindow(), &screen_rect); // разрешение экрана
	int x = screen_rect.right / 2 - 150;
	int y = screen_rect.bottom / 2 - 75;

	// создание диалогового окна
	HWND hWnd = CreateWindow(lpzClass, CHEATNAME, WS_POPUP, x, y, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);

	// если окно не создано, описатель будет равен 0
	if (!hWnd) return 2;

	// Initialize Direct3D
	LPDIRECT3D9 pD3D;
	if ((pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
	{
		UnregisterClass(lpzClass, hInstance);
	}

	ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
	g_d3dpp.Windowed = TRUE;
	g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	g_d3dpp.EnableAutoDepthStencil = TRUE;
	g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE; // Present with vsync
	//g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE; // Present without vsync, maximum unthrottled framerate

	//Ўрифт меню
	ImGuiIO& io = ImGui::GetIO();
	globalFont = io.Fonts->AddFontFromMemoryCompressedTTF(font_compressed_data, font_compressed_size, 16.f, NULL, io.Fonts->GetGlyphRangesCyrillic());
	//globalFont = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\tahoma.ttf", 14.0f, NULL, io.Fonts->GetGlyphRangesCyrillic());
	forTabs = io.Fonts->AddFontFromMemoryCompressedTTF(font_compressed_data, font_compressed_size, 20.f, NULL, io.Fonts->GetGlyphRangesCyrillic());
	bigFont = io.Fonts->AddFontFromMemoryCompressedTTF(font_compressed_data, font_compressed_size, 19.f, NULL, io.Fonts->GetGlyphRangesCyrillic());

	if (pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
	{

		pD3D->Release();
		UnregisterClass(lpzClass, hInstance);
		return 0;

	}
	//if (light == nullptr)D3DXCreateTextureFromFileInMemory(g_pd3dDevice, &light1, sizeof(light1), &light);
	// Setup ImGui binding
	ImGui_ImplDX9_Init(hWnd, g_pd3dDevice);

	ImGuiStyle& style = ImGui::GetStyle();

	style.FramePadding = ImVec2(4, 2);
	style.ItemSpacing = ImVec2(6, 2);
	style.ItemInnerSpacing = ImVec2(6, 4);
	style.WindowRounding = 4.0f;
	style.WindowTitleAlign = ImVec2(0.5, 0.5);
	style.FrameRounding = 6.0f;
	style.IndentSpacing = 6.0f;
	style.ItemInnerSpacing = ImVec2(2, 4);
	style.ColumnsMinSpacing = 50.0f;
	style.GrabMinSize = 14.0f;
	style.GrabRounding = 16.0f;
	style.ScrollbarSize = 12.0f;
	style.ScrollbarRounding = 16.0f;


	style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 0.91f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 0.82f);
	style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.89f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.17f, 0.17f, 0.17f, 0.67f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.44f, 0.43f, 0.43f, 0.22f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(1.00f, 0.00f, 0.00f, 0.40f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(1.00f, 0.00f, 0.00f, 0.45f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.23f, 0.23f, 0.23f, 0.83f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.21f, 0.21f, 0.21f, 0.20f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.35f, 0.35f, 0.35f, 0.87f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.35f, 0.33f, 0.33f, 0.14f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.48f, 0.48f, 0.48f, 0.30f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.45f, 0.45f, 0.45f, 0.40f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.61f, 0.61f, 0.61f, 0.40f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.90f, 0.90f, 0.90f, 0.50f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 1.00f, 1.00f, 0.30f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.80f, 0.50f, 0.50f, 1.00f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.30f, 0.30f, 0.30f, 0.5f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.5f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.50f, 0.50f, 0.50f, 0.5f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.15f, 0.15f, 0.15f, 0.45f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.29f, 0.29f, 0.29f, 0.80f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.47f, 0.47f, 0.47f, 0.80f);
	style.Colors[ImGuiCol_Column] = ImVec4(0.47f, 0.47f, 0.47f, 1.00f);
	style.Colors[ImGuiCol_ColumnHovered] = ImVec4(0.70f, 0.60f, 0.60f, 1.00f);
	style.Colors[ImGuiCol_ColumnActive] = ImVec4(0.90f, 0.70f, 0.70f, 1.00f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.30f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);
	style.Colors[ImGuiCol_CloseButton] = ImVec4(0.50f, 0.50f, 0.90f, 0.50f);
	style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.70f, 0.70f, 0.90f, 0.60f);
	style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(0.70f, 0.70f, 0.70f, 1.00f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);
	style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);



	

	bool show_test_window = true;
	bool show_another_window = false;
	ImVec4 clear_col = ImColor(0, 0, 0, 255);




	// Main loop
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;
		}

		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

		ImGui_ImplDX9_NewFrame();


		static bool open = true;

		//if (!open)
		//	ExitProcess(0);

		//ImGui::PushFont(forTabs);

		
			ImGui::Begin("TRB - PROJECT", &open, ImVec2(WINDOW_WIDTH, WINDOW_HEIGHT), 1.0f, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoInputs);
			{
				
				
				
				ImGui::SetNextWindowPos(ImVec2(835,5));
				ImGui::BeginChild("##border", ImVec2(65, 15));
				{
					if (ImGui::Button("1", ImVec2(15, 15)))
						exit(0);
					ImGui::SameLine();
					if (ImGui::Button("2", ImVec2(15, 15)))
						exit(0);
					ImGui::SameLine();
					if (ImGui::Button("3", ImVec2(15, 15)))
						exit(0);
				}ImGui::EndChild();

			}ImGui::End();

			ImGui::SetNextWindowPosCenter();
			ImGui::Begin("##AutchWindow", &open, ImVec2(800, 600), 1.0f, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoTitleBar);
			{
				static int page = 0;
				//static char login[20] = {};
				//static char mail[20] ;
				//static char pass[20];
				//static char pass_conf[20];


				if (page == 0)
				{
					/*
					ImGui::SetNextWindowPosCenter();
					ImGui::BeginChild("Login", ImVec2(250, 100));
					{
						ImGui::SetCursorPos(ImVec2(90, 35));
						ImGui::PushItemWidth(180.f);
						ImGui::InputText(charenc("Login"), Credential::login, 44);

						ImGui::SetCursorPos(ImVec2(90, 60));
						ImGui::PushItemWidth(180.f);
						ImGui::InputText(charenc("Password"), Credential::password, 44, ImGuiInputTextFlags_Password);
						ImGui::InvisibleButton("", ImVec2(20, 0)); ImGui::SameLine();
						if (ImGui::Button(charenc("Authorize"), ImVec2(180, 0)))
						{
							if (Credential::login != "" || Credential::password != "")
							{
								Credential::SaveConfig();

								if (!Auth::Auth(Credential::login, Credential::password, server))
								{
									

									page = 1;
								}
							}
						}
						
					}*/
				}
			
				else if (page == 1)
				{
					ImGui::SetNextWindowPosCenter();
					ImGui::BeginChild("##page3", ImVec2(250, 100));
					{

					}ImGui::EndChild();
				}
				
			}ImGui::End();


		// Rendering
			
		g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, false);
		g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
		g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);

		//D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_color.x*255.0f), (int)(clear_color.y*255.0f), (int)(clear_color.z*255.0f), (int)(clear_color.w*255.0f));
		//g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
		if (g_pd3dDevice->BeginScene() >= 0)
		{
			ImGui::Render();
			g_pd3dDevice->EndScene();
		}
		g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
	}

	ImGui_ImplDX9_Shutdown();
	if (g_pd3dDevice) g_pd3dDevice->Release();
	if (pD3D) pD3D->Release();
	UnregisterClass(CHEATNAME, hInstance);

	return 0;						
}
////////////////////////////////////////////////////////////////////////// 
// функци§ регистрации класса окон
ATOM RegMyWindowClass(HINSTANCE hInst, LPCTSTR lpzClassName)
{
	WNDCLASS wcWindowClass = { 0 };
	// адрес ф-ции обработки сообщений
	wcWindowClass.lpfnWndProc = (WNDPROC)WndProc;
	// стиль окна
	wcWindowClass.style = CS_HREDRAW | CS_VREDRAW;
	// дискриптор экземпл§ра приложени§
	wcWindowClass.hInstance = hInst;
	// название класса
	wcWindowClass.lpszClassName = lpzClassName;
	// загрузка курсора
	wcWindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	// загрузка цвета окон
	wcWindowClass.hbrBackground = (HBRUSH)COLOR_APPWORKSPACE;
	return RegisterClass(&wcWindowClass); // регистраци§ класса
}