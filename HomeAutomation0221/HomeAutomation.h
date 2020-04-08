#ifndef __HOMEAUTOMATION_H__
#define	__HOMEAUTOMATION_H__
#include "Appliance.h"
#include "AirConditioner.h"
#include "RiceCooker.h"
#include "Washer.h"
#include "Power.h"
int controlMenuSelect(string message, int menuCnt); // ������ǰ�� ���º��� ó���� ���� �޴� �Լ�
void displayTitle(string title); // ó������ ���� ����ϱ� ���� Ÿ��Ʋ ����Լ� 
int inputInteger(char *message);  //  message�� ����ϰ� ������ �Է� �޾� ����(����, �Ǽ��� ���� ó��)
int inputInteger(string message); //  message�� ����ϰ� ������ �Է� �޾� ����(����, �Ǽ��� ���� ó��)
void myFlush();  // cin�Է� ���۸� ��� ���� fail���¸� �ʱ���·� �缳��

#define APPLIANCE_MAX_CNT 20 // �ִ� ��� ������ ������ǰ�� ����

class HomeAutomation
{
public:
	HomeAutomation(); // appliaceArray�� �޸� ������ ��� 0���� �ʱ�ȭ �ϰ�, applianceCnt�� 0���� �ʱ�ȭ
	HomeAutomation(const HomeAutomation &r); // deep copy constructor
	~HomeAutomation(); // applianceArray�� ���� �Ҵ�� ��ü�� ��� ������

	// getter, setter member function
	Appliance ** getApplianceArray(); // applianceArray ��� �� ��ȯ �Լ�
	int getApplianceCnt() const; // applianceCnt ��� �� ��ȯ �Լ�

	// member function
	HomeAutomation & operator=(const HomeAutomation &r); // ����(�Ҵ�)������ �����ε� �Լ�
	bool addAppliance(Appliance *ap);	// ������ǰ�� ��Ͽ� �߰�.  ������ ��ǰ�� �߰� �Ұ���. 
	int searchMachine(string machineName); // ������ǰ���� �ش��ϴ� ������ǰ�� ã�Ƽ� �迭�� index����/���� �� -1 ����
	bool deleteAppliance(string machineName); // ������ǰ���� �ش��ϴ� ������ǰ�� ��Ͽ��� �����ϴ�
	void listDisplayAppliance(); // ��ϵ� ������ǰ ��ü ��� �� ���¸�  Ȯ���ϴ�
	bool controlAppliance(string machineName);   // �ش� ������ǰ�� �����ϴ�
	void setStateAppliance(Appliance * ap); // �����ִ� ������ǰ�� ���¸� �����ϴ�
	friend int Power::calPowerConsumption(HomeAutomation &rHa); // Power class�� calPowerConsumption()����Լ��� friend ���
private:
	Appliance * applianceArray[APPLIANCE_MAX_CNT]; // ��ϵ� ������ǰ ��ü�� ���� ���� �迭(������ü �Ҵ� �� �ּ�����)
	int applianceCnt; // ��ϵ� ��ü�� ���� ���� 
};
#endif