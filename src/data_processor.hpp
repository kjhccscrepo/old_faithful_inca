#pragma once
#include <vector>

template <typename T>
static double findAverage(std::vector<T> myVec) {
    double totalValue = 0;
    for (int i = 0; i < myVec.size(); i++) {
        totalValue = totalValue + myVec[i];
    }
    return (totalValue / myVec.size());
}

bool isSmall (int x) {
    if (x <= 60) {
        return true;
    }
    return false;
}

std::string bool_print (int x) {
    if (isSmall(x)) {
        return "T";
    }
    return "F";
}
