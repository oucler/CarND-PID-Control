#ifndef PID_H
#define PID_H

#include <vector>

using namespace std;

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  //double sum;

  vector<double> params;
  vector<double> dParams;
  double err;
  double bestErr;
  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
  double prev_cte;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double kp, double ki, double kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  vector<double> findBestParams();
  double sum(vector<double> params);

};

#endif /* PID_H */
