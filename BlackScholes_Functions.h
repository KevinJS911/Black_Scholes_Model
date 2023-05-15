#ifndef Black_Scholes()

#include <string>

using namespace std;

void Black_Scholes(double* price, double* S, double* L, double* T, double* r, double* div, double* vol, std::string optionType, double* dig_payoff);

double option_payoff(double* S, double* K, double* r, double* T, double* div, string optionType, double d1, double d2);

void getOptionType(string optType);

double CDF(double f);

#endif // !Black_Scholes()