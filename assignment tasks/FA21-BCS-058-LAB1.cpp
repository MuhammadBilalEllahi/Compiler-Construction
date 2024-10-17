#include <iostream>
#include <string>
using namespace std;

struct Rule {
    string terms[10];  
    int num_terms = 0; 
    Rule* next = nullptr;
    Rule* prev = nullptr;
};

struct Prod {
    string name;        
    Prod* next = nullptr;
    Prod* prev = nullptr;
    Rule* first_rule = nullptr;  
    Rule* last_rule = nullptr;   
};


Prod* createProd(string nonTerminalName) {
    Prod* newProd = new Prod;
    newProd->name = nonTerminalName;
    return newProd;
}


Rule* createRule(string ruleTerms[], int numTerms) {
    Rule* newRule = new Rule;
    for (int i = 0; i < numTerms; i++) {
        newRule->terms[i] = ruleTerms[i];
    }
    newRule->num_terms = numTerms;
    return newRule;
}


void addRuleToProd(Prod* prod, Rule* rule) {
    if (prod->first_rule == nullptr) {
        prod->first_rule = rule;
        prod->last_rule = rule;
    } else {
        prod->last_rule->next = rule;
        rule->prev = prod->last_rule;
        prod->last_rule = rule;
    }
}


void displayProd(Prod* prod) {
    cout << prod->name << " -> ";
    Rule* cur = prod->first_rule;
    while (cur != nullptr) {
        for (int i = 0; i < cur->num_terms; i++) {
            cout << cur->terms[i] << " ";
        }
        if (cur->next != nullptr) {
            cout << "| ";
        }
        cur = cur->next;
    }
    cout << endl;
}


void traverseProdForward(Prod* head) {
    Prod* cur = head;
    while (cur != nullptr) {
        displayProd(cur);
        cur = cur->next;
    }
}


void traverseProdBackward(Prod* tail) {
    Prod* cur = tail;
    while (cur != nullptr) {
        displayProd(cur);
        cur = cur->prev;
    }
}


void inputRulesForProd(Prod* prod) {
    cout << "Enter rules for production " << prod->name << " (Enter 'done' to stop):" << endl;
    string ruleInput;
    while (true) {
        cout << "Rule: ";
        getline(cin, ruleInput);
        if (ruleInput == "done") {
            break;
        }

        
        string ruleTerms[10];
        int numTerms = 0;
        size_t pos = 0;
        while ((pos = ruleInput.find(" ")) != string::npos && numTerms < 10) {
            ruleTerms[numTerms++] = ruleInput.substr(0, pos);
            ruleInput.erase(0, pos + 1);
        }
        ruleTerms[numTerms++] = ruleInput;  

        Rule* newRule = createRule(ruleTerms, numTerms);
        addRuleToProd(prod, newRule);
    }
}

int main() {
    
    Prod* prodHead = nullptr;
    Prod* prodTail = nullptr;

    
    while (true) {
        string nonTerminal;
        cout << "Enter a non-terminal (or 'Exit' to quit): ";
        getline(cin, nonTerminal);
        if (nonTerminal == "Exit") {
            break;
        }

        Prod* newProd = createProd(nonTerminal);
        inputRulesForProd(newProd);

        
        if (prodHead == nullptr) {
            prodHead = newProd;
            prodTail = newProd;
        } else {
            prodTail->next = newProd;
            newProd->prev = prodTail;
            prodTail = newProd;
        }
    }

    
    cout << "\nProduction Rules (forward):" << endl;
    traverseProdForward(prodHead);

    cout << "\nProduction Rules (backward):" << endl;
    traverseProdBackward(prodTail);

    
    Prod* curProd = prodHead;
    while (curProd != nullptr) {
        Rule* curRule = curProd->first_rule;
        while (curRule != nullptr) {
            Rule* nextRule = curRule->next;
            delete curRule;
            curRule = nextRule;
        }
        Prod* nextProd = curProd->next;
        delete curProd;
        curProd = nextProd;
    }

    return 0;
}
