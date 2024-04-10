// Autor: Adam Czubak
// Utworzenie pliku nagłówkowego klasy Investment.
// Definicja klasy, jej atrybutów i metod.

#ifndef INVESTMENT_H
#define INVESTMENT_H
#include <iostream>

class Investment
{
    // Klasa "Investment" reprezentująca pierwiastek i jego atrybuty.
    private:
        double funds;
        double interest_rate;
        int years;
        bool tax_state;
        int tax_rate;
        int capitalization_number_per_year;
        std::string investment_current;
    public:
        // Konstruktor klasy (dwa ostatnie parametry: kapitalizacja w ciągu roku i waluta mają przypisane parametry domyślne):
        Investment(double funds,
                   double interest_rate,
                   int years,
                   bool tax_state,
                   int tax_rate,
                   int capitalization_number_per_year = 1,
                   std::string investment_current = "PLN");
        // Zwraca ilość środków:
        double check_funds();
        // Ustawia ilość środków:
        void change_account_state(double new_funds);
        // Dodaje (lub odejmuje) dodatkowe środki do stanu konta:
        void add_funds(double new_funds);
        // Zwraca oprocentowanie lokaty:
        double get_interest_rate();
        // Ustawia oprocentowanie lokaty:
        void change_interest_rate(double new_interest_rate);
        // Zwraca liczbę lat, na które została założona lokata:
        int get_years();
        // Ustawia liczbę lat, na które została założona lokata:
        void set_years(int new_years);
        // Zwraca informacje czy uwzględniamy podatek w lokacie:
        bool get_tax_state();
        // Ustawia stan uwzględniający podatek w lokacie: true - uwzględniamy; false - nieuwzględniamy:
        void set_tax_state(bool new_tax_state);
        // Zwraca procentową wartość podatku:
        int get_tax_rate();
        // Ustawia procentową wartość podatku:
        void set_tax_rate(int new_tax_rate);
        // Zwraca liczbę kapitalizacji w ciągu roku:
        int get_capitalozation_number_per_year();
        // Ustawia liczbę kapitalizacji w ciągu roku:
        void set_capitalization_number_per_year(int new_capitalization_number);
        // Zwraca walutę, na której aktualnie operujemy:
        std::string get_investment_current();
        // Ustawia walutę, na której chcemy operować:
        void set_investment_current(std::string new_investment_current);
        // Szacuje zysk uwzględniając oprocentowanie, kapitalizację, liczbę lat, podatek:
        double estimate_profits(double rate_of_interest, int years_number, bool taxes_state, int taxes_rate, int capitalization);
        // Przekonwertowanie środków na koncie na żądaną walutę:
        double convert_current(std::string new_current, double current_conversion_rate);
};

#endif