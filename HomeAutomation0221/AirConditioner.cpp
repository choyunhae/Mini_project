#include "AirConditioner.h"

AirConditioner::AirConditioner() :Appliance()
{
	this->machineState = 1;
	this->setTemperature = 25;
}
AirConditioner::AirConditioner(string machineName, int powerConsumption)
: Appliance(machineName, powerConsumption)
{
	this->machineState = 1;
	this->setTemperature = 25;
}
int AirConditioner::getMachineState()const
{
	return machineState;
}
int AirConditioner::getSetTemperature()const
{
	return setTemperature;
}
void AirConditioner::setMachineState(int machineState)
{
	this->machineState = machineState;
}
void AirConditioner::setSetTemperature(int setTemperature)
{
	this->setTemperature = setTemperature;
}
AirConditioner&AirConditioner::operator++()
{
	this->setTemperature++;
	return *this;
}
AirConditioner&AirConditioner::operator--()
{
	this->setTemperature--;
	return *this;
}
void AirConditioner::stateView()
{
	cout << "제품명 : " << getMachineName();
	if (this->getPowerFlag() == true)
	{
		cout << "(ON)" << " " << "설정상태 : ";
		if (this->machineState == 1){
			cout << "송풍";
		}
		else if (this->machineState == 2)
		{
			cout << "냉방";
		}
		else if (this->machineState == 3)
		{
			cout << "난방";
		}
		cout << "(설정온도 : " << this->getSetTemperature() << ")" << endl;
	}
	if (this->getPowerFlag() == false)
	{
		cout << "(OFF)" << endl;
	}
}
