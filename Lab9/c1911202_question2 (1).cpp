#include <iostream>
#include <vector>

using namespace std;

class Car
{
private:
protected:
    string brandname;
    int modelyear;
    int price;
    int totalCost;

public:
    Car(/* args */) {}
    Car(string brandname, int price, int totalCost)
    {
        this->brandname = brandname;
        this->price = price;
        this->totalCost = totalCost;
    }
    Car(const Car &source) : brandname(source.brandname), modelyear(source.modelyear), price(source.price), totalCost(source.totalCost)
    {
    }
    string GetBrandname() const
    {
        return brandname;
    }

    void SetBrandname(string brandname)
    {
        this->brandname = brandname;
    }

    int GetModelyear() const
    {
        return modelyear;
    }

    void SetModelyear(int modelyear)
    {
        this->modelyear = modelyear;
    }

    int GetPrice() const
    {
        return price;
    }

    void SetPrice(int price)
    {
        this->price = price;
    }

    int GetTotalCost() const
    {
        return totalCost;
    }

    void SetTotalCost(int _totalCost)
    {
        this->totalCost = _totalCost;
    }
    ~Car() {}
};
class ElectricCar : virtual public Car
{
    friend ostream &operator<<(ostream &os, const ElectricCar &obj);

private:
protected:
    int NumberOfBatteries;
    int electricCost;

public:
    ElectricCar(/* args */) {}
    ElectricCar(string brandname, int modelyear, int price, int numberofbatteries, int electriccost)
    {
        this->brandname = brandname;
        this->modelyear = modelyear;
        this->price = price;
        this->NumberOfBatteries = numberofbatteries;
        this->electricCost = electriccost;
    }
    ElectricCar(const ElectricCar &source)
    {
        brandname = source.brandname;
        modelyear = source.modelyear;
        price = source.price;
        NumberOfBatteries = source.NumberOfBatteries;
        electricCost = source.electricCost;
        totalCost = source.totalCost;
    }
    int GetNumberOfBatteries() const
    {
        return NumberOfBatteries;
    }

    void SetNumberOfBatteries(int NumberOfBatteries)
    {
        this->NumberOfBatteries = NumberOfBatteries;
    }

    int GetElectricCost() const
    {
        return electricCost;
    }

    void SetElectricCost(int electricCost)
    {
        this->electricCost = electricCost;
    }
    ~ElectricCar() {}
};

class GasolineCar : virtual public Car
{
    friend ostream &operator<<(ostream &os, const GasolineCar &obj);

private:
protected:
    int engineVolume;
    int fuelCost;

public:
    GasolineCar(/* args */) {}
    GasolineCar(string brandname, int modelyear, int price, int enginevolume, int fuelcost)
    {
        this->brandname = brandname;
        this->modelyear = modelyear;
        this->price = price;
        this->engineVolume = enginevolume;
        this->fuelCost = fuelcost;
    }
    GasolineCar(const GasolineCar &source)
    {
        brandname = source.brandname;
        modelyear = source.modelyear;
        price = source.price;
        engineVolume = source.engineVolume;
        fuelCost = source.fuelCost;
        totalCost = source.totalCost;
    }
    int GetEngineVolume() const
    {
        return engineVolume;
    }

    void SetEngineVolume(int engineVolume)
    {
        this->engineVolume = engineVolume;
    }

    int GetFuelCost() const
    {
        return fuelCost;
    }

    void SetFuelCost(int fuelCost)
    {
        this->fuelCost = fuelCost;
    }
    ~GasolineCar() {}
};

class HybridCar : public ElectricCar, public GasolineCar
{
    friend ostream &operator<<(ostream &os, const HybridCar &obj);

private:
public:
    HybridCar(/* args */) {}
    HybridCar(const HybridCar &source)
    {
        brandname = source.brandname;
        modelyear = source.modelyear;
        price = source.price;
        NumberOfBatteries = source.NumberOfBatteries;
        electricCost = source.electricCost;
        engineVolume = source.engineVolume;
        fuelCost = source.fuelCost;
        totalCost = source.totalCost;
    }
    ~HybridCar() {}
};
ostream &operator<<(ostream &os, const ElectricCar &obj)
{
    os << obj.GetBrandname() << " " << obj.GetModelyear() << " Price:" << obj.GetPrice() << " Number of batteries:" << obj.GetNumberOfBatteries() << " Electric cost:" << obj.GetElectricCost() << " Total Cost:" << obj.GetTotalCost() << endl;
    return os;
}
ostream &operator<<(ostream &os, const GasolineCar &obj)
{
    os << obj.GetBrandname() << " " << obj.GetModelyear() << " Price:" << obj.GetPrice() << " Engine Volume:" << obj.GetEngineVolume() << " Fuel Cost:" << obj.GetFuelCost() << " Total Cost:" << obj.GetTotalCost() << endl;
    return os;
}
ostream &operator<<(ostream &os, const HybridCar &obj)
{
    os << obj.GetBrandname() << " " << obj.GetModelyear() << " Price:" << obj.GetPrice() << " Number of batteries:" << obj.GetNumberOfBatteries() << " Electric cost:" << obj.GetElectricCost() << " Engine Volume(CC):" << obj.GetEngineVolume() << " Fuel Cost:" << obj.GetFuelCost() << " Total Cost:" << obj.GetTotalCost() << endl;
    return os;
}

int main(int argc, char const *argv[])
{
    vector<ElectricCar> ve;
    vector<GasolineCar> vg;
    vector<HybridCar> vh;

    ElectricCar e;
    GasolineCar g;
    HybridCar h;
    string brandname, minname;
    int modelyear, price, numberofbatteries, electriccost, enginevolume, fuelcost, mincost;

    int choice, j = 1;
    while (1)
    {
        cout << "\n1)Electric Car - 2)Gasoline Car - 3)Hybrid Car - 4)Exit:    ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter brand name: ";
            cin >> brandname;
            e.SetBrandname(brandname);
            cout << "Enter model year: ";
            cin >> modelyear;
            e.SetModelyear(modelyear);
            cout << "Price: ";
            cin >> price;
            e.SetPrice(price);
            cout << "Number of Batteries: ";
            cin >> numberofbatteries;
            e.SetNumberOfBatteries(numberofbatteries);
            cout << "Electric Cost: ";
            cin >> electriccost;
            e.SetElectricCost(electriccost);
            e.SetTotalCost(electriccost);
            ve.push_back(e);
            break;
        case 2:
            cout << "\nEnter brand name: ";
            cin >> brandname;
            g.SetBrandname(brandname);
            cout << "Enter model year: ";
            cin >> modelyear;
            g.SetModelyear(modelyear);
            cout << "Price: ";
            cin >> price;
            g.SetPrice(price);
            cout << "Engine Volume(CC): ";
            cin >> enginevolume;
            g.SetEngineVolume(enginevolume);
            cout << "Fuel Cost: ";
            cin >> fuelcost;
            g.SetFuelCost(fuelcost);
            g.SetTotalCost(fuelcost);
            vg.push_back(g);
            break;
        case 3:
            cout << "\nEnter brand name: ";
            cin >> brandname;
            h.SetBrandname(brandname);
            cout << "Enter model year: ";
            cin >> modelyear;
            h.SetModelyear(modelyear);
            cout << "Price: ";
            cin >> price;
            h.SetPrice(price);
            cout << "Number of Batteries: ";
            cin >> numberofbatteries;
            h.SetNumberOfBatteries(numberofbatteries);
            cout << "Electric Cost: ";
            cin >> electriccost;
            h.SetElectricCost(electriccost);
            cout << "Engine Volume(CC): ";
            cin >> enginevolume;
            h.SetEngineVolume(enginevolume);
            cout << "Fuel Cost: ";
            cin >> fuelcost;
            h.SetFuelCost(fuelcost);
            h.SetTotalCost(electriccost + fuelcost);
            vh.push_back(h);

            break;
        case 4:
            cout << "\nElectric Cars:" << endl;
            mincost = ve.at(0).GetTotalCost();
            for (auto &i : ve)
            {
                cout << j << "-" << i;
                j++;
                if (mincost > i.GetTotalCost())
                {
                    mincost = i.GetTotalCost();
                    minname = i.GetBrandname();
                }
            }
            j = 1;
            cout << "\nGasoline Cars:" << endl;
            for (auto &i : vg)
            {
                cout << j << "-" << i;
                j++;
                if (mincost > i.GetTotalCost())
                {
                    mincost = i.GetTotalCost();
                    minname = i.GetBrandname();
                }
            }
            j = 1;
            cout << "\nHybrid Cars:" << endl;
            for (auto &i : vh)
            {
                cout << j << "-" << i;
                j++;
                if (mincost > i.GetTotalCost())
                {
                    mincost = i.GetTotalCost();
                    minname = i.GetBrandname();
                }
            }
            cout << endl
                 << minname << " has the minimum cost of all cars" << endl;
            exit(1);
            break;
        default:
            cout << "Wrong" << endl;
            exit(1);
            break;
        }
    }

    return 0;
}
