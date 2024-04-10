// Autor: Adam Czubak
// Implementacja metod klasy.

#include "investment.h"
#include <cmath>
#include <algorithm>
#include <vector>
#include "check_availability_of_current.h"

Investment::Investment(double funds,
                       double interest_rate,
                       int years,
                       bool tax_state,
                       int tax_rate,
                       int capitalization_number_per_year,
                       std::string investment_current) : funds(funds),
                                                                 interest_rate(interest_rate),
                                                                 years(years),
                                                                 tax_state(tax_state),
                                                                 tax_rate(tax_rate),
                                                                 capitalization_number_per_year(capitalization_number_per_year),
                                                                 investment_current(investment_current){}

double Investment::check_funds()
{
    return funds;
}

void Investment::change_account_state(double new_funds)
{
    funds = trunc(new_funds * 100) / 100;
}

void Investment::add_funds(double new_funds)
{
    funds += trunc(new_funds * 100) / 100;
}

double Investment::get_interest_rate()
{
    return (trunc(interest_rate * 100)) / 100;
}

void Investment::change_interest_rate(double new_interest_rate)
{
    if (new_interest_rate >= 1 && new_interest_rate <= 100)
        interest_rate = new_interest_rate;
    else
        throw std::out_of_range("Interest rate must be between 1 and 100!");
    
}

int Investment::get_years()
{
    return years;
}

void Investment::set_years(int new_years)
{
    if (new_years >= 1)
        years = new_years;
    else
        throw std::logic_error("Years cannot be negative or zero!");
}

bool Investment::get_tax_state()
{
    return tax_state;
}

void Investment::set_tax_state(bool new_tax_state)
{
    tax_state = new_tax_state;
}

int Investment::get_tax_rate()
{
    return tax_rate;
}

void Investment::set_tax_rate(int new_tax_rate)
{
    if (new_tax_rate >= 1 && new_tax_rate <= 100)
    {
        if (tax_state == true)
            tax_rate = new_tax_rate;
        else
        {
            tax_rate = 0;
            throw std::logic_error("You disabled the taxes option! Tax rate has been reseted to 0!");
        }
    }
    else
        throw std::out_of_range("Tax rate must be between 1 and 100!");
    
}

int Investment::get_capitalozation_number_per_year()
{
    return capitalization_number_per_year;
}

void Investment::set_capitalization_number_per_year(int new_capitalization_number)
{
    capitalization_number_per_year = new_capitalization_number;
}

std::string Investment::get_investment_current()
{
    return investment_current;
}

void Investment::set_investment_current(std::string new_investment_current)
{
    bool founded_current = check_availability_of_current(new_investment_current);
    if (founded_current == true)
        investment_current = new_investment_current;
    else
        throw std::invalid_argument("This current is not available!");
}

double Investment::estimate_profits(double rate_of_interest, int years_number, bool taxes_state, int taxes_rate, int capitalization)
{
    if (taxes_state == false)
        taxes_rate = 0;
    double estimated_profits;
    estimated_profits = funds * pow(1 + rate_of_interest / (
        100 * capitalization), capitalization * years_number) - funds;
    estimated_profits = trunc((estimated_profits - estimated_profits * taxes_rate / 100) * 100) / 100;
    return estimated_profits;
}

double Investment::convert_current(std::string new_current, double current_conversion_rate)
{
    bool founded_current = check_availability_of_current(new_current);
    if (founded_current == true)
    {
        if (new_current == investment_current)
            throw std::logic_error("Resulting current cannot be the same as the present one!");
        else
        {
            investment_current = new_current;
            funds = (funds * (trunc(current_conversion_rate * 100))) / 100;
        }
    }
    else
        throw std::invalid_argument("This current is not available!");
    return funds;
}