#ifndef __AIRCONDITIONER_H__
#define	__AIRCONDITIONER_H__
#include "Appliance.h"

class AirConditioner : public Appliance
{
public:
	AirConditioner(); // Appliance�� default �����ڷ� ����, machineState�� ��ǳ���� �ʱ�ȭ
	AirConditioner(string machineName, int powerConsumption);// Appliance�� Overloaded �����ڷ� ����, machineState�� ��ǳ���� �ʱ�ȭ
	// getter, setter member function
	int getMachineState() const; // machineState ����� ��ȯ �Լ�
	int getSetTemperature() const;  // setTemperature ����� ��ȯ �Լ�
	void setMachineState(int machineState); // machineState ��� �ʱ�ȭ �Լ�
	void setSetTemperature(int setTemperature); // setTemperature ��� �ʱ�ȭ �Լ�
	// member function
	AirConditioner & operator++(); // ���� �µ��� 1���� �ø���(prefix increment)
	AirConditioner & operator--(); // ���� �µ��� 1���� ������(prefix decrement)
	void stateView();  // ��ü�� ���� ���
	enum { SENDAIR = 1, COOLER, HEATER }; // ��ǳ, �ù�, ������ ��Ÿ���� ������ ���
private:
	int machineState;     // ��ǰ����(1:��ǳ, 2:�ù�, 3:����) - �⺻���� : ��ǳ
	int setTemperature;   // �����µ� - �⺻�� 25��
};
#endif