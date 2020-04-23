//
//  main.cpp
//  CodingTestPayPP2020_2
//
//  Created by adeeb mohammed on 19/04/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

// time complexity is o(V) it is the total balance amount
const static std::map<float,std::string> currencyMap = {
       {0.01,"PENNY"},
       {0.05,"NICKEL"},
       {0.10,"DIME"},
       {0.25,"QUARTER"},
       {0.50,"HALF DOLLAR"},
       {1.00,"ONE"},
       {2.00,"TWO"},
       {5.00,"FIVE"},
       {10.00,"TEN"},
       {20.00,"TWENTY"},
       {50.00,"FIFTY"},
       {100.00,"ONE HUNDRED"}
   };

std::vector<std::string> findMinCurrency(float balanceAmount){
    std::vector<std::string> balanceCurrency;
    for (auto value = currencyMap.rbegin() ;  value != currencyMap.rend(); ++value) {
        while (balanceAmount >= value->first) {
            balanceAmount -= value->first;
            balanceCurrency.push_back(value->second);
        }
    }
    return balanceCurrency;
}


std::string balanceCalculator(std::string inputString){
    std::string result = "";
   
    
    if(!inputString.size()){
        return "ERROR";
    }
    
    size_t found;
    std::string purchasePrice = "";
    std::string cashGiven = "";
    if ((found = inputString.find(";")) != std::string::npos){
        purchasePrice = inputString.substr(0,found);
        cashGiven = inputString.substr(found+1,std::string::npos);
    }
    
   if(!purchasePrice.size() || !cashGiven.size()){
        return "ERROR";
    }
    
    float fPurchasePrice = std::stof(purchasePrice);
    float fCashGiven = std::stof(cashGiven);
    
    if(fCashGiven <  fPurchasePrice){
        return "ERROR";
    }
    
    if(fCashGiven == fPurchasePrice){
        return "ZERO";
    }
    
    float balanceAmount = fCashGiven - fPurchasePrice;
    std::vector<std::string> balanceCurrency = findMinCurrency(balanceAmount);
    std::sort(balanceCurrency.begin(), balanceCurrency.end());
    std::string prev = "";
    for(auto currency: balanceCurrency){
        if(prev != currency ){
            result  +=  currency + ",";
        }
        prev = currency;
    }
    result.pop_back();
    return result;
}

int main(int argc, const char * argv[]) {
    std::cout << "Program Number 2" << std::endl;
    std::cout << balanceCalculator("16.05;1000.35") << std::endl;
    return 0;
}
