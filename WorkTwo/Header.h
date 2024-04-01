#include <string>
#include <vector>
#include <iostream>

#pragma once

using namespace std;

class AdressShopingCentr
{
//private:
public:
	string Country, Region, City, Street;
	int House, Building;

	AdressShopingCentr() {
		Country = Region = City = Street = "";
		House = Building = 0;
	}
	AdressShopingCentr(string _Country, string _Region , string _City, string _Street, int _House, int _Building) {
		Country		= _Country;
		Region		= _Region;
		City		= _City;
		Street		= _Street;
		House		= _House;
		Building	= _Building;
	}

	friend iostream& operator<<(iostream& stringOut, const AdressShopingCentr& AdressShCentr);
	friend istream& operator>>(istream& stringIn, AdressShopingCentr& AdressShCentr);

};

iostream& operator<<(iostream& stringOut, const AdressShopingCentr& AdressShCentr) {
	
	stringOut << "A country: "	<< AdressShCentr.Country	<< ", ";
	stringOut << "Region: "		<< AdressShCentr.Region		<< ", ";
	stringOut << "City: "		<< AdressShCentr.City		<< ", ";
	stringOut << "Street: "		<< AdressShCentr.Street		<< ", ";
	stringOut << "House: "		<< AdressShCentr.House;
	
	if (AdressShCentr.Building != 0) {
		stringOut << ", ";
		stringOut << "Building: " << AdressShCentr.Building << " .";
	}
	else{
		stringOut << ".";
	}

	stringOut << endl;

	return stringOut;
}

istream& operator>>(istream& stringIn, AdressShopingCentr& AdressShCentr) {
	
	stringIn >> AdressShCentr.Country;
	stringIn >> AdressShCentr.Region;
	stringIn >> AdressShCentr.City;
	stringIn >> AdressShCentr.Street;
	stringIn >> AdressShCentr.House;
	stringIn >> AdressShCentr.Building;

}

class ShoppingCentre : public AdressShopingCentr
{
private:
	string NameShoppingCentr, INN;
	vector <string> RetailOutlets;
	AdressShopingCentr AdressShop;
public:

	ShoppingCentre();
	ShoppingCentre(string _NameShoppingCentr, string _INN, vector<string>_RetailOutlets, AdressShopingCentr _AdressShop);


};

ShoppingCentre::ShoppingCentre() {
	NameShoppingCentr = INN = "";
	RetailOutlets = *(new vector <string>(0));
}
ShoppingCentre::ShoppingCentre(string _NameShoppingCentr, string _INN, vector<string>_RetailOutlets, AdressShopingCentr _AdressShop) {

	NameShoppingCentr	= _NameShoppingCentr;
	INN					= _INN;
	RetailOutlets		= _RetailOutlets;
	AdressShop			= _AdressShop;

}

