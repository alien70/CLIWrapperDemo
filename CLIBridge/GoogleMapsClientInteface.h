#pragma once

# include <string>

using namespace std;

class CGoogleMapsClientIntefacePrivate;

class CGoogleMapsClientInteface
{
public:
	CGoogleMapsClientInteface();
	~CGoogleMapsClientInteface();

#pragma region Attributes
private:

	CGoogleMapsClientIntefacePrivate* _private;

	string  m_address;

	double m_latitude;

	double m_longitude;


#pragma endregion

#pragma region Properties
public:
	__declspec(property(get = GetLatitude)) double Latitude;
	double GetLatitude(void);

	__declspec(property(get = GetLongitude)) double Longitude;
	double GetLongitude(void);

	__declspec(property(put = SetAddress, get = GetAddress)) const char* Address;
	void SetAddress(const char*);
	const char* GetAddress(void) const;

#pragma endregion

};

