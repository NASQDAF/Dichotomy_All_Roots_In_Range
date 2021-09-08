#include <iostream>
#include <cmath>
#include <vector>

std::vector<double> A_B_pair_, solutions;
double 	e = 0.000001,
		a = -1.6f,
		b = 1.5f,
		c;
int steps = 100;


double polinom(double x) { return x * exp(sin(5 * x)) - 5 * cos(x) * pow(x, 3); }

double find_root(double a, double b) {
	for (size_t i = 0; (b - a) >= e; i++) {
		c = (a + b) / 2.0f;
		if (polinom(c) == 0)
			return c;
		else if (polinom(c) * polinom(a) < 0)
			b = c;
		else
			a = c;
	}
	return c;
}

bool sign(double x) { return polinom(x) > 0 ? 1 : 0; }

void how_many_roots(double a, double b) {
	double min_var, max_var;
	if (a > b) { 
		max_var = a;
		min_var = b; 
	}
	else { 
		max_var = b; 
		min_var = a; 
	}
	double e = (max_var - min_var) / steps;
	bool ka = sign(min_var);
	bool temp = ka;
	for (double i = min_var; i < max_var; i += e)
		if (sign(i) != ka) {
			A_B_pair_.push_back(i - e);
			A_B_pair_.push_back(i);
			ka = sign(i);
		}
}

void find_all_solution() {
	for (int i = 0; i < A_B_pair_.size() / 2; i++)
		solutions.push_back(find_root(A_B_pair_[i * 2], A_B_pair_[i * 2 + 1]));
}

int main() {
	how_many_roots(a, b);
	find_all_solution();
	for (auto i : solutions)
		std::cout << i << std::endl;
}