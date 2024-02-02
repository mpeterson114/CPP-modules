/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:47:28 by mpeterso          #+#    #+#             */
/*   Updated: 2024/02/01 11:58:05 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include "Account.hpp"

/* Init Static Member Variables */
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* Default Constructor */
Account::Account()
{
}

/* Parameterized Constructor */
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
                                        _amount(initial_deposit),
                                        _nbDeposits(0),
                                        _nbWithdrawals(0)
{
    Account::_nbAccounts++;
    Account::_totalAmount += _amount;
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "created" << std::endl;
}

/* Destructor */
Account::~Account() 
{
    Account::_nbAccounts--;
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "closed" << std::endl;
}

/* Getters */
int Account::getNbAccounts()
{
    return _nbAccounts;
}

int Account::getTotalAmount()
{
    return _totalAmount;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{
    std::time_t t_default;
    std::string timestamp;

    t_default = std::time(NULL);
    timestamp.resize(20);
    std::strftime(&timestamp[0], timestamp.size(), "[%Y%m%d_%H%M%S] ", std::localtime(&t_default));
    std::cout << timestamp;
}