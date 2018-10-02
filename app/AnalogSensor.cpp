#include <AnalogSensor.hpp>
#include <memory>  // Header files needed to access C++11 Smart Pointers
#include <numeric>
#include <vector>

AnalogSensor::AnalogSensor(unsigned int samples)
  : mSamples(samples) {
}

AnalogSensor::~AnalogSensor() {
}

int AnalogSensor::Read() {
  // Using smart pointers intead of traditional pointers,
  // so that we don't need to use delete keyword.
  // Secondly, using make_shared to avoid explicit use of new and
  // to have only one dynamic memory allocation.
  std::shared_ptr<std::vector<int>>
    readings(std::make_shared<std::vector<int>>(mSamples, 10));
  double result =
    std::accumulate(readings->begin(), readings->end(), 0.0) / readings->size();
  return result;
}


