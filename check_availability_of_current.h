// Autor: Adam Czubak
// Wydzielona funkcja sprawdzająca dostępność danej waluty oraz umożliwiająca jest wprowadzanie z małych liter.

#ifndef CHECK_AVAILABILITY_OF_CURRENT_H
#define CHECK_AVAILABILITY_OF_CURRENT_H
#include <iostream>
#include <vector>
#include <algorithm>

bool check_availability_of_current(std::string & new_investment_current_check)
{
    std::vector<std::string> currents{"EUR", "USD", "CHF", "GBP", "PLN"};
    for (long unsigned int i = 0; i < new_investment_current_check.length(); i++)
        new_investment_current_check[i] = toupper(new_investment_current_check[i]);
    auto founded_current_index = std::find(currents.begin(), currents.end(), new_investment_current_check);
    if (founded_current_index != currents.end())
        return true;
    else
        return false;
}

#endif