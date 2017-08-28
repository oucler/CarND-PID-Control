#include "PID.h"
#include <iostream>
#include <math.h>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
	prev_cte=0;
	// Initialize errors
	p_error = 0;
	i_error = 0;
	d_error = 0;
	//sum = 0;
	params.push_back(0);
	params.push_back(0);
	params.push_back(0);
	dParams.push_back(1);
	dParams.push_back(1);
	dParams.push_back(1);
	err = 0;
	bestErr = 10000;;
}

PID::~PID() {}

void PID::Init(double kp, double ki, double kd) {
	this->Kp = kp;
	this->Ki = ki;
	this->Kd = kd;
}

void PID::UpdateError(double cte) {
	// Proportional error
	p_error = cte;

	// Integral error
	i_error += cte;

	// Differential error
	d_error = cte - prev_cte;
}

double PID::TotalError() {
	return -Kp*p_error - Ki*i_error - Kd*d_error;
}
vector<double> PID::findBestParams(){
	//while (sum(dParams) > 0.2){
	for (int j = 0;j<40;++j){
		for (int i=0;i<dParams.size();++i){
			params[i] += dParams[i];
			std::cout << "params[0]: " << params[0] << " params[1]: "<< params[1] << " params[2]: " << params[2] << std::endl;
			std::cout << "dParams[0]: " << dParams[0] << " dParams[1]: "<< dParams[1] << " dParams[2]: " << dParams[2] << std::endl;
			Init(params[0], params[1], params[2]);
			err = TotalError();
			err*=10000;
			std::cout << "err: " << err << std::endl;
			std::cout << "bestRrr: " << bestErr << std::endl;

			if (fabs(err) < fabs(bestErr)){
				cout << "###### First if ######" << endl;
				bestErr = err;
				bestErr*=10000;
				dParams[i]*= 1.1;
			}
			else{
				params[i]-= 2*dParams[i];
				std::cout << "params[0]: " << params[0] << " params[1]: "<< params[1] << " params[2]: " << params[2] << std::endl;
				std::cout << "dParams[0]: " << dParams[0] << " dParams[1]: "<< dParams[1] << " dParams[2]: " << dParams[2] << std::endl;
				Init(params[0], params[1], params[2]);
				err = TotalError();
				err*=10000;
				if (fabs(err) < fabs(bestErr)){
					cout << "###### Second if ######" << endl;
					bestErr = err;
					bestErr*=10000;
					dParams[i] *= 1.1;
				}
				else{
					params[i] += dParams[i];
					dParams[i] *= 0.9;
				}
			}


		}
	}
	std::cout << "params[0]: " << params[0] << "params[1]: "<< params[1] << "params[2]: " << params[2] << std::endl;
	std::cout << "dParams[0]: " << dParams[0] << " dParams[1]: "<< dParams[1] << " dParams[2]: " << dParams[2] << std::endl;
	return params;
}
double PID::sum(vector<double> params){
	double total=0;
	for (auto p: params){
		total+=p;
	}
	return total;
}


