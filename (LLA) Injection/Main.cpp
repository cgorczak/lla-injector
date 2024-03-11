#include <iostream>
#include <Windows.h>

// Processo / Caminho da dll
void inject(HANDLE hProc, LPCSTR caminhoDaDll)
{
	// Verifica se o programa pode injetar algo no processo
	if (!hProc) { std::cout << "Ocorreu um erro com o processo"; system("PAUSE>nul"); exit(1); }

	// Aloca memoria para adicionar o caminho da dll no processo e mais 1 byte para o fim
	LPVOID pCaminhoDaDll = VirtualAllocEx(hProc, 0, strlen(caminhoDaDll) + 1, MEM_COMMIT, PAGE_READWRITE);

	// Escreve na memoria do processo o caminho da nossa dll
	WriteProcessMemory(hProc, pCaminhoDaDll, (LPVOID)caminhoDaDll, strlen(caminhoDaDll) + 1, 0);

	// Cria um Thread remoto no processo e chama a função "LoadLibraryA" para que o processo carregue sua dll
	HANDLE hLoadThread = CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("Kernel32.dll"),
	 "LoadLibraryA"), pCaminhoDaDll, 0, 0);

	// Espera o carregamento da Thread terminar
	WaitForSingleObject(hLoadThread, NULL);

	// Mensagem de sucesso
	std::cout << "Injecao completa!";

	// Saida
	system("PAUSE>nul");
	exit(0); 
}

int main()
{
	// ID do processo que você quer injeta
	DWORD PID = 0;

	// Handle para o processo o qual quer injetar a dll
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);

	// Caminho para chegar ate a dll que quer injetar
	LPCSTR caminhoDaDll = "C:\\Users\\DeathZ\\Desktop\\exemplo.dll";

	// Chama o metodo para injetar
	inject(hProc, caminhoDaDll);

}
