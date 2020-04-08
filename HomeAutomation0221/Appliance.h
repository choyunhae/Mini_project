#ifndef __APPLIANCE_H__
#define __APPLIANCE_H__

#include <string>
#include <time.h>  // �ý��� �ð��� �о���� ���� include
#include <iostream>
using namespace std;

class Appliance
{
public:
	// constructor, destructor : deep copy cons.�� destructor�� ������ �������� ����
	Appliance();  // default constructor (machineName:Null string, powerFlag:false, powerConsumption:0, startHour:0, useHour:0)
	Appliance(string machineName, int powerConsumption, bool powerFlag = false, time_t startHour = 0, time_t useHour = 0);
	virtual ~Appliance() { } // ���� �Ҹ���
	// getter, setter member function
	string getMachineName() const;  // machineName ����� ��ȯ �Լ�
	bool getPowerFlag() const; // powerFlag ��� �� ��ȯ �Լ� 
	int getPowerConsumption() const; // powerConsumtion ��� �� ��ȯ �Լ�
	time_t getStartHour(); // startHour ��� �� ��ȯ �Լ�
	time_t getUseHour(); // useHour ��� �� ��ȯ �Լ�
	void setMachineName(string machineName);  // machineName ��� �ʱ�ȭ �Լ�
	void setPowerFlag(bool powerFlag); // powerFlag ��� �ʱ�ȭ �Լ� 
	void setPowerConsumption(int powerConsumption); // powerConsumtion ��� �ʱ�ȭ �Լ�
	// member fucntion
	virtual bool turnOn(); // ��ǰ�� �Ѵ�
	virtual bool turnOff(); // ��ǰ�� ����
	virtual void stateView() = 0; // ���������Լ� : ��ǰ�� ���¸� ����ϴ�
private:
	string machineName;  // ������ǰ��
	bool powerFlag;  // ���� on_off����(on-ture, off-false)
	int powerConsumption; // �ð���  ���¼Ҹ�
	time_t startHour;  // ��ǰ ��� ���۽ð�
	time_t useHour;    // ��ǰ ��� �����ð� ���� ���
};
#endif