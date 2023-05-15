#include <cmath>
#include <string>
#include <iostream>

using namespace std;

enum optType { call, put, dcall, dput, null};
optType opt;

double M_SQRT1_2 = sqrt(0.5);

double CDF(double f) {
	return 0.5 * erfc(-f * M_SQRT1_2);
}

void getOptionType(string optType) {

	if (optType == "call") {
		opt = call;
	}
	else if (optType == "put") {
		opt = put;
	}
	else if (optType == "dcall") {
		opt = dcall;
	}
	else if (optType == "dput"){

		opt = dput; 
	}
	else {
		opt = null;
		cout << "Invalid option Type";
		exit(0);
	}

}

double option_payoff(double* S, double* K, double* r, double* T, double* div, string optionType, double d1, double d2)
{
	double price = 0.0;
	double Nd1, Nd2;

	getOptionType(optionType);

	switch (opt) {
	case call:
		price = *S * exp(-*div * *T) * CDF(d1) - *K * exp(-*r * *T) * CDF(d2);
		break;
	
	case put:
		price = - *S * exp(-*div * *T) * CDF(-d1) + *K * exp(-*r * *T) * CDF(-d2);
		break;

	case dcall:
		price = exp(-*r * *T) * CDF(d2);
		break;

	case dput:
		price = exp(-*r * *T) * (1-CDF(d2));
		break;

	default:
		cout << "Invalid option type ";
	};
	
	return price;

}

void Black_Scholes(double* price, double* S, double* K, double* T, double* r, double* div, double* vol, std::string optionType, double* dig_payoff)
{
	double d1, d2, optionPayoff;
	d1 = (log(*S / *K)+(*r - *div + 0.5* *vol * *vol)* *T)/(*vol * sqrt(*T));
	d2 = d1 - *vol * sqrt(*T);
	
	optionPayoff = option_payoff(S, K, r, T, div, optionType, d1,  d2);
	if (optionType == "dcall" or optionType == "dput") {
		optionPayoff *= *dig_payoff;
	}

	*price = optionPayoff;
}
