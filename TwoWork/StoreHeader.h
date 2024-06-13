#include <iostream>
#include <string>
#include <vector>
#include <map>

#pragma once
using namespace std;

enum TypeStore { Production, Shop, Warehouse, Office , Logistics_Center};
map <int, string> TypeStoreOut = {
	{Production,		"Production"},
	{Shop,				"Shop"},
	{Warehouse,			"Warehouse"},
	{Office,			"Office"},
	{Logistics_Center,	"Logistics Center"} 
};

enum StatusJob { works , does_not_work};
map <int, string> StatusOut = {
	{works, "Works"},
	{does_not_work, "Does not work"}
};

class CentralOrganization {
protected:
	string Name,		// Название
		OfficeAdress,	// Адрес
		INN,			// ИНН
		chief,			// Руководитель
		callPhone;		// Контактный телефон
public:
	
	CentralOrganization(string _INN);

	void setName(string _Name),
		setOfficeAdress(string _OfficeAdress),
		setchief(string _chief),
		setCallPhone(string _callPhone);

	void infoPrintOut();



};
/* class CentralOrganization + */
CentralOrganization::CentralOrganization(string _INN) {
	INN = _INN;
}
void CentralOrganization::setName(string _Name) {
	Name = _Name;
}
void CentralOrganization::setOfficeAdress(string _OfficeAdress) {
	OfficeAdress = _OfficeAdress;
}
void CentralOrganization::setchief(string _chief) {
	chief = _chief;
}
void CentralOrganization::setCallPhone(string _callPhone) {
	callPhone = _callPhone;
}
void CentralOrganization::infoPrintOut() {
	
	cout << "Организация: "			<< Name			<< " ИНН: " << INN << endl;
	cout << "Адрес: "				<< OfficeAdress << endl;
	cout << "Руководитель: "		<< chief		<< endl;
	cout << "Контактный телефон: "	<< callPhone	<< endl;

}
/* class CentralOrganization - */

class CentralStore {
protected:
	TypeStore TypeCStore;
	StatusJob Status;
	string Name, 
		AdressStore, 
		callPhone;


public:
	CentralStore(StatusJob _Status, TypeStore _TypeCStore, string _Name);
	void setAdress(string _Adress),
		setCallPhone(string _CallPhone);
	virtual void PrintOutStore();
};

CentralStore::CentralStore(StatusJob _Status, TypeStore _TypeCStore, string _Name) {
	Status = _Status;
	TypeCStore = _TypeCStore;
	Name = _Name;
}
void CentralStore::setAdress(string _Adress) {
	AdressStore = _Adress;
}
void CentralStore::setCallPhone(string _CallPhone) {
	callPhone = _CallPhone;
}
void CentralStore::PrintOutStore() {
	cout << endl << "Магазин: " << Name << " Статус: " << Status << endl;

}

class Store: public CentralStore {
private:
	int CountKKM;			// Кол-во ккм
	string OperatingMode;	// Режим работы
public:
	Store(StatusJob _Status, TypeStore _TypeCStore, string _Name);
	void setCountKKM(int _countKKM),
		setOperatingMode(string _OperatingMode);
};

Store::Store(StatusJob _Status, TypeStore _TypeCStore, string _Name) :CentralStore(_Status, _TypeCStore, _Name) {
}
void Store::setCountKKM(int _countKKM) {
	CountKKM = _countKKM;
}
void Store::setOperatingMode(string _OperatingMode) {
	OperatingMode = _OperatingMode;
}