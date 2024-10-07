// exo1.cpp

#include <iostream>
#include <string>

class CompteBancaire
{
public:
    CompteBancaire(int balance = 0, const std::string& owner = "John Doe")
        : mBalance(balance), mOwner(owner)
    {
    }
    ~CompteBancaire() = default;

    void Debit(int amount) {
        mBalance -= amount;
    }

    void Credit(int amount) {
        mBalance += amount;
    }

    void ShowBalance() {
        std::cout << "Balance of " << mOwner << ": " << mBalance << std::endl;
    }

    int GetBalance() {
        return mBalance;
    }
private:
    int mBalance;
    std::string mOwner;
};
