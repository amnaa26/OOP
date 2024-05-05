/*
 * Creator: Amna(23K-0066)
*/

#include <iostream>
#include <string>
using namespace std;

class Medicine{
private:
    string name, formula, manufacture_date, expiration_date;
    double retail_price;

public:
    Medicine(string n, string f, string md, string ed, double cost) : name(n), formula(f), manufacture_date(md), expiration_date(ed), retail_price(cost) {}

    //getters
    string getName()const{}
    string getFormula() const {}
    string getManufactureDate() const {}
    string getExpirationData() const {}
    double getRetailPrice () const {}

    //setters
    void setName(string Name){}
    void setFormula(string Formula){}
    void setManufactureDate(string ManufactureDate) {}
    void setExpirationDate(string ExpirationDate){}
    void setRetailPrice(double cost){}

    virtual void printDetails(){}

    bool operator == (const Medicine& object) const{
        return expiration_date == object.expiration_date;
    }
};


class Tablet : public Medicine{
private:
    float sucrose_level;

public:
    Tablet(float sucrose, string name, string formula, string md, string ed, double cost) : sucrose_level(sucrose), Medicine(name, formula, md, ed, cost){}

    float getSucroseLevel() const {}
    void setSucroseLevel(float sucroseLevel){}

    void printDetails() override{}
};


class Capsule : public Medicine{
private:
    float absorption_percentage;

public:
    Capsule(float absorption, string name, string formula, string md, string ed, double cost) : absorption_percentage(absorption), Medicine(name, formula, md, ed, cost){}

    float getAbsorptionPercentage() const {}
    void setAbsorptionPercentange(float absorptionPercentage) {}

    void printDetails() override {}
};


class Syrup : public Medicine{
private:
    float concentration;

public:
    Syrup(float concent, string name, string formula, string md, string ed, double cost) : concentration(concent), Medicine(name, formula, md, ed, cost){}

    float getConcentration() const {}
    void setConcentration(float concentraion_level){}

    void printDetails() override {}
};


class Pharmacist{
public:
    void searchMedicine(string formula, Medicine* medicine, int count){}
};

class Counter{
private:
    double revenue;

public:
    void searchMedicine(string name, Medicine* medicines, int count){}
    void update_revenue(double amount){}
};


//Here is an example of Medicines array
int count = 4;
Medicine* medicineArray [] = {
    new Capsule(10.2f, "Capsule1", "Formula1", "01-02-2022", "05-12-2025", 120),
    new Tablet (2.2f, "Tablet1", "Formula2", "02-02-2019", "02-02-2022", 340),
    new Syrup(34.56f, "Syrup1", "Formula3", "27-08-2023", "27-08-2025", 450.25),
    new Tablet(1.2f, "Tablet2", "Formula4", "25-04-2022", "24-05-2026", 355.75)
};