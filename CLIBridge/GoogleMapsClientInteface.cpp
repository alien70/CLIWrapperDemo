#include "stdafx.h"
#include "GoogleMapsClientInteface.h"

# include <msclr\auto_gcroot.h>

using namespace System::Runtime::InteropServices;
//using namespace GoogleMapsClientInteface;

CGoogleMapsClientInteface::CGoogleMapsClientInteface()
{
}


CGoogleMapsClientInteface::~CGoogleMapsClientInteface()
{
}

double CGoogleMapsClientInteface::GetLatitude()
{
	return m_latitude;
}

double CGoogleMapsClientInteface::GetLongitude()
{
	return m_longitude;
}

void CGoogleMapsClientInteface::SetAddress(const char* value)
{
	m_address = value;
}
const char* CGoogleMapsClientInteface::GetAddress(void) const
{
	return m_address.c_str();
}