#ifndef __WASHER_H__
#define	__WASHER_H__
#include "Appliance.h"

class Washer : public Appliance
{
public:
	Washer(); // Appliance�� default�����ڷ� ����, machineState�� ���������� �ʱ�ȭ
	Washer(string machineName, int powerConsumption); // Appliance�� Overloaded �����ڷ� ����, machineState�� ���������� �ʱ�ȭ
	// getter, setter member function
	int getMachineState() const; // machineState ��� �� ��ȯ �Լ�
	void setMachineState(int machineState); // machineState ��� �ʱ�ȭ �Լ�
	// member function
	void stateView();  // ��ü�� ���� ���
	enum { NO_OPERATION = 1, GENERAL, BOIL, DRY }; // ��Ź���� ���¸� ��Ÿ���� ������ ���
private:
	int machineState; // ��ǰ����(1:������, 2:�Ϲݻ���, 3:��������, 4:����)
};
#endif