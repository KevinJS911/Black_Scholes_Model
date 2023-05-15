#include <iostream>
#include "BlackScholes_Functions.h"

using namespace std;

int main() {
	double S, K, T, r, div, vol;
	double dig_payoff = 0.0;	
	string optionType;

	cout << "What option do you want to price? (call, price, dcall, dput):";
	cin >> optionType;
	
	if (optionType == "dcall" or optionType == "dput")
	{
		cout << "What is the payoff when digital option expires in the money?: ";
		cin >> dig_payoff;
	}
	
	cout << "Enter current stock price?: ";
	cin >> S;
	cout << "Enter strike price: ";
	cin >> K;
	cout << "Enter maturity of option (in years): ";
	cin >> T;
	cout << "Enter risk-free rate (in %): ";
	cin >> r;
	r /= 100;
	cout << "Enter annual dividend yield (in %): ";
	cin >> div;
	div /= 100;
	cout << "Enter volatility of underlying asset (in %): ";
	cin >> vol;
	vol /= 100;

	double price = 0;
	Black_Scholes(&price, &S, &K, &T, &r, &div, &vol, optionType, &dig_payoff);

	cout << endl << "Price of " << optionType << " option is : " << price;
	

	return 0;
}