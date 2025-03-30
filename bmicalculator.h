#ifndef BMICALCULATOR_H
#define BMICALCULATOR_H

#include <QString>

class BmiCalculator
{
public:
    BmiCalculator(double _weight, double _height);

    void calculateBmi();

    double getBmi();

    QString getBmiCategory();

private:
    double weight;
    double height;
    double bmi;
};

#endif // BMICALCULATOR_H
