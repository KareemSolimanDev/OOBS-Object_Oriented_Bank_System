#include "Transaction.h"


void Transaction::withdraw(float amount)
{
    *(this->_balance) -= amount;

}

void Transaction::deposite(float amount)
{
    *(this->_balance) += amount;
}