#include<iostream>
using namespace std;

enum TYPE
{
    TOSHIBA,
    HITACHI
};

class USDevice
{
public:
    virtual void make() = 0;
};

class TUSDevice : public USDevice
{
public:
    void make()
    {
         cout<<"TUS";
    }
};

class HUSDevice : public USDevice
{
public:
    void make()
    {
         cout<<"HUS";
    }
};


class MRDevice
{
public:
    virtual void make() = 0;
};


class TMRDevice : public MRDevice
{
public:
    void make()
    {
         cout<<"TMR";
    }
};

class HMRDevice : public MRDevice
{
public:
    void make()
    {
         cout<<"HMR";
    }
};


class DeviceFactory
{
public:
    virtual USDevice* CreateUSDevice() = 0;
    virtual MRDevice* CreateMRDevice() = 0;
};

class Toshiba : public DeviceFactory
{
public:
    virtual USDevice* CreateUSDevice()
    {
	USDevice* ptrTUS = new TUSDevice();
	return ptrTUS;
    }
    virtual MRDevice* CreateMRDevice()
    {
	MRDevice* ptrTMR = new TMRDevice();
	return ptrTMR;
    }
};

class Hitachi : public DeviceFactory
{
public:
    virtual USDevice* CreateUSDevice()
    {
	USDevice* ptrHUS = new HUSDevice();
	return ptrHUS;
    }
    virtual MRDevice* CreateMRDevice()
    {
	MRDevice* ptrHMR = new HMRDevice();
	return ptrHMR;
    }
};

class DeviceProducer
{
public:
    DeviceFactory* CreateFactory( TYPE type )
    {
     DeviceFactory* ptrFactory = 0;
     switch(type)
	{
	 case TOSHIBA:
         ptrFactory = new Toshiba();
		break;
	 case HITACHI:
         ptrFactory = new Hitachi();
		break;
	 default:
		break;
	}
     return ptrFactory;
    }
};


void main()
{
    DeviceProducer obj;

    DeviceFactory* pToshiba = obj.CreateFactory(TOSHIBA);
    USDevice* pTUS = pToshiba->CreateUSDevice();
    pTUS->make();
}















































