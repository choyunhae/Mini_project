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
	cout << "��ǰ�� : " << getMachineName();
	if (this->getPowerFlag() == true)
	{
		cout << "(ON)" << " " << "�������� : ";
		if (this->machineState == 1){
			cout << "��ǳ";
		}
		else if (this->machineState == 2)
		{
			cout << "�ù�";
		}
		else if (this->machineState == 3)
		{
			cout << "����";
		}
		cout << "(�����µ� : " << this->getSetTemperature() << ")" << endl;
	}
	if (this->getPowerFlag() == false)
	{
		cout << "(OFF)" << endl;
	}
}
