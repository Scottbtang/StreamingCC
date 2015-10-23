#ifndef __UTILS_H__
#define __UTILS_H__
#include <random>
#include <iostream>


namespace utils {
  const int MAX = 1 << 30;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0, 1);
  std::default_random_engine generator;
  std::normal_distribution<double> distribution(5.0,2.0);
  std::uniform_int_distribution<> dis_int(0, MAX);
}



class Gaussian {
  std::normal_distribution<double> *distPtr;
public:
  Gaussian(double m, double sig) {
    distPtr = new std::normal_distribution<double>(m, sig);
  };
  double rand() {
    return (*distPtr)(utils::gen);
  };
  ~Gaussian() {delete distPtr; }
};

//! return random double between 0. and 1.
double rand_double() {
  return utils::dis(utils::gen);
}

//! randomly return from 0, 1, 2, ..., M-1
double rand_int(int M) {
  return utils::dis_int(utils::gen) % M;
}

double find_closest(double a, double b) {
  int j = std::ceil(std::log(b) / std::log(a));
  return std::pow(a, j);
}


#endif
