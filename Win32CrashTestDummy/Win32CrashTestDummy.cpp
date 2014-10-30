// Win32CrashTestDummy.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"

# include <iostream>
# include <conio.h>

# include "CLIBridge.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << " ------------------------ " << endl;
	cout << " ---------START---------- " << endl;
	cout << " ------------------------ " << endl;

	cout << endl;

	// cout << "Exported function \'fnCLIBridge()\' returned: " << fnCLIBridge() << endl;

	THandle handle = CGoogleMapsClientInteface_Create();

	const char* address = "Google Building 44, Mountain View, California, Stati Uniti";

	CGoogleMapsClientInteface_SetAddress(handle, address);

	const char* value = CGoogleMapsClientInteface_GetAddress(handle);
	
	cout << "Address:\t" << value << endl;

	cout << endl;

	cout << "Latitude:\t" << CGoogleMapsClientInteface_GetLatitude(handle) << endl;

	cout << endl;

	cout << "Longitude:\t" << CGoogleMapsClientInteface_GetLongitude(handle) << endl;

	cout << endl;

	cout << " ------------------------ " << endl;
	cout << " ----------END----------- " << endl;
	cout << " ------------------------ " << endl;

	std::cin.get();
	cout << " ------------------------ " << endl;

	return 0;
}

