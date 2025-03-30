#include "bmicalculator.h"

BmiCalculator::BmiCalculator(double _weight, double _height)
    : weight(_weight), height(_height / 100) {
    calculateBmi();
}

void BmiCalculator::calculateBmi() {
    bmi = weight / (height * height);
}

double BmiCalculator::getBmi() {
    return bmi;
}

QString BmiCalculator::getBmiCategory() {
    if (bmi < 16) {
        return "Выраженный дефицит массы тела.";
    } else if (bmi < 18.5) {
        return "Недостаточная (дефицит) масса тела.";
    } else if (bmi < 25) {
        return "Норма.";
    } else if (bmi < 30) {
        return "Избыточная масса тела (предожирение).";
    } else if (bmi < 35) {
        return "Ожирение первой степени.";
    } else if (bmi < 40) {
        return "Ожирение второй степени.";
    } else {
        return "Ожирение третьей степени (морбидное).";
    }
}
