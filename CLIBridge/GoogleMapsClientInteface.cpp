#include "stdafx.h"
#include "GoogleMapsClientInteface.h"

# include <msclr\auto_gcroot.h>

using namespace System::Runtime::InteropServices;
using namespace GoogleMapsAPI;

class CGoogleMapsClientIntefacePrivate
{
public:
	msclr::auto_gcroot<GoogleMaps^> googleMapsAPI;
};

CGoogleMapsClientInteface::CGoogleMapsClientInteface()
{
	this->_private = new CGoogleMapsClientIntefacePrivate();
	this->_private->googleMapsAPI = gcnew GoogleMaps();
}


CGoogleMapsClientInteface::~CGoogleMapsClientInteface()
{
	if (this->_private)
		delete this->_private;
}

double CGoogleMapsClientInteface::GetLatitude()
{
	return this->_private->googleMapsAPI->Latitude;
}

double CGoogleMapsClientInteface::GetLongitude()
{
	return this->_private->googleMapsAPI->Longitude;
}

void CGoogleMapsClientInteface::SetAddress(const char* value)
{
	this->_private->googleMapsAPI->Address = gcnew System::String(value);

	this->_private->googleMapsAPI->GetCoordinates();
}
const char* CGoogleMapsClientInteface::GetAddress(void) const
{
	return (const char*)Marshal::StringToHGlobalAnsi(this->_private->googleMapsAPI->Address).ToPointer();

}