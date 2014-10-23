// Il seguente blocco ifdef rappresenta il modo standard di creare macro che semplificano 
// l'esportazione da una DLL. Tutti i file all'interno della DLL sono compilati con il simbolo CLIBRIDGE_EXPORTS
// definito nella riga di comando. Questo simbolo non deve essere definito in alcun progetto
// che utilizza questa DLL. In questo modo qualsiasi altro progetto i cui file di origine includono questo file vedranno le funzioni 
// CLIBRIDGE_API come importate da una DLL, mentre la DLL vedrà i simboli
// definiti con questa macro come esportati.
#ifdef CLIBRIDGE_EXPORTS
#define CLIBRIDGE_API __declspec(dllexport)
#else
#define CLIBRIDGE_API __declspec(dllimport)
#endif

typedef void* THandle;

# include "GoogleMapsClientInteface.h"

#ifdef __cplusplus
extern "C"
{
#endif

	inline CLIBRIDGE_API THandle CGoogleMapsClientInteface_Create()
	{
		return (THandle) new CGoogleMapsClientInteface();
	}

	inline CLIBRIDGE_API void CGoogleMapsClientInteface_SetAddress(THandle handle, const char* value)
	{
		if (handle)
			((CGoogleMapsClientInteface*)handle)->Address = value;
	}
	inline CLIBRIDGE_API const char* CGoogleMapsClientInteface_GetAddress(THandle handle)
	{
		return (handle)
			? ((CGoogleMapsClientInteface*)handle)->Address
			: "";
	}

	inline CLIBRIDGE_API double CGoogleMapsClientInteface_GetLatitude(THandle handle)
	{
		return (handle)
			? ((CGoogleMapsClientInteface*)handle)->Latitude
			: numeric_limits<double>::signaling_NaN();
	}

	inline CLIBRIDGE_API double CGoogleMapsClientInteface_GetLongitude(THandle handle)
	{
		return (handle)
			? ((CGoogleMapsClientInteface*)handle)->Longitude
			: numeric_limits<double>::signaling_NaN();
	}


	CLIBRIDGE_API int fnCLIBridge(void);

#ifdef __cplusplus
}
#endif
