#include <iostream>
using namespace std;



struct WithinRule{
    string withinRule;
    WithinRule *next = nullptr;
    WithinRule *prev = nullptr;
};
// A -> E;
// E-> E+E | E*E;
// E+E -> [E,+,E]



class WithinRuleDoublyLinkedList {
    private:
        WithinRule* head;
        WithinRule* tail;
    
    public:
        WithinRuleDoublyLinkedList() : head(nullptr), tail(nullptr) {};
    
        void insertWithinRule(string ruleValue){
            WithinRule* rule = new WithinRule();
            rule->withinRule= ruleValue;

                if(head == nullptr){
                    head = rule;
                }
                else if(tail == nullptr){
                    tail = rule;
                    
                    head->next=tail;
                    tail->prev=head;
                }else{
                    tail->next=rule;
                    rule->prev=tail;
                    tail=rule; 
                }
            
        }

        void displayWithinRuleList (){
            WithinRule* cur = head;
            cout << "\nWithin Rule:";
                while(cur != nullptr){
                    cout << " -> " <<  cur->withinRule ;
                    cur = cur->next;
                }
            }

        void displayWithinRuleListReverse (){
            WithinRule* cur = tail;
            cout << "Reversed: ";
                while(cur != nullptr){
                    cout <<  cur->withinRule << "\n";
                    cur = cur->prev;
                }
            }
        
};



struct Rule{
    string rule;
    Rule *next = nullptr;
    Rule *prev = nullptr;

    WithinRuleDoublyLinkedList* withinRuleList;
    Rule(): withinRuleList(new WithinRuleDoublyLinkedList()) {}
};


class RuleDoublyLinkedList {
    private:
        Rule* head;
        Rule* tail;
    
    public:
        RuleDoublyLinkedList() : head(nullptr), tail(nullptr) {};
    
        // Rule processRules(string allRules){
        //     // int i = 0;
        //     Rule* rule = new Rule();
        //     string allRules= rule;
        //     // string rules[];
        //     while(allRules.find("|") != string::npos){
        //         cout << "ProcessValue: "<<(allRules);
        //         int loc=  allRules.find("|");
        //         insertRule(allRules.substr(0,loc));
        //         allRules = allRules.substr(loc+1);
        //         // i++;
        //         if(allRules.find("|") == string::npos){
        //             insertRule(allRules);
        //         }
        //         cout << "ProcessRules: " << rules[i-1];
                
        //     }   
        //     return 
        // }
        void insertRule(string ruleValue){
            Rule* rule = new Rule();
            rule->rule= ruleValue;

                if(head == nullptr){
                    head = rule;
                }
                else if(tail == nullptr){
                    tail = rule;
                    
                    head->next=tail;
                    tail->prev=head;
                }else{
                    tail->next=rule;
                    rule->prev=tail;
                    tail=rule; 
                }
            
        }

        void displayRuleList (){
            Rule* cur = head;
            cout << "\nRule:";
                while(cur != nullptr){
                    cout << " -> " <<  cur->rule ;
                    cur->withinRuleList->displayWithinRuleList();
                    cur = cur->next;
                }
            }

        void displayRuleListReverse (){
            Rule* cur = tail;
            cout << "Reversed: ";
                while(cur != nullptr){
                    cout <<  cur->rule << "\n";
                    cur = cur->prev;
                }
            }
        Rule* findRule(string ruleValue) {
            Rule* cur = head;
            while (cur != nullptr) {
                if (cur->rule == ruleValue) {
                    return cur;
                }
                cur = cur->next;
            }
            return nullptr;
        }
        
};


struct Prod{
    string nT;//non terminal
    Prod *next = nullptr;
    Prod *prev = nullptr;


    RuleDoublyLinkedList* rulesList;

    Prod(string nonTerminalValue): nT(nonTerminalValue) , rulesList(new RuleDoublyLinkedList()){}
};

class ProdDoublyLinkedList {
    private:
        Prod* head;
        Prod* tail;
    
    public:
        ProdDoublyLinkedList() : head(nullptr), tail(nullptr) {};
    
        void insertProd(string prodValue){
            Prod* prod = new Prod(prodValue);
            // prod->nT= prodValue;

                if(head == nullptr){
                    head = prod;
                }
                else if(tail == nullptr){
                    tail = prod;
                    
                    head->next=tail;
                    tail->prev=head;
                }else{
                    tail->next=prod;
                    prod->prev=tail;
                    tail=prod; 
                }
            
        }

        void displayProdList (){
            Prod* cur = head;
            cout << "\n\nProd:";
                while(cur != nullptr){
                    cout << " -> " <<  cur->nT ;
                    cur->rulesList->displayRuleList();
                    cur = cur->next;
                }
            }

        void displayProdListReverse (){
            Prod* cur = tail;
            cout << "Reversed: ";
                while(cur != nullptr){
                    cout <<  cur->nT << "\n";
                    cur = cur->prev;
                }
            }
        Prod* findProd(string nonTerminalValue) {
            Prod* cur = head;
            while (cur != nullptr) {
                if (cur->nT == nonTerminalValue)
                    return cur;
                cur = cur->next;
            }
            return nullptr;
        }
        
};






int main(){

    ProdDoublyLinkedList* prodGrammer  = new ProdDoublyLinkedList();
    Prod* prodE;
    
    // prodGrammer->insertProd("A");
    // prodGrammer->insertProd("E");
    
    // Prod* prodE = prodGrammer->findProd("A"); 
    
    // prodE->rulesList->insertRule("E+E");
    // prodE->rulesList->insertRule("E*E");
    
    // prodE->rulesList->displayRuleList();

    // prodGrammer->displayProdList();
    


    
    string nonTerminalValue;

    cout << "Enter (Exit) to Exit" << "\n";
    for (int i =0 ; ;i++){
        cout << "\n\nEnter another paragraph: ";
        getline(cin,nonTerminalValue);
        if(nonTerminalValue == "Exit"){
            break;
        }else{
            string value = nonTerminalValue;
 
            size_t arrow = value.find("->");
            size_t semiColon = value.find(";");

            if (arrow == string::npos || semiColon == string::npos){
                cout << "You must enter -> + * ; ";
                break;
            }
            // cout << "\n"<<arrow;

            // cout << value.substr(0,arrow);
            // cout << value.substr(arrow+2);
            

            string grammer = value.substr(0,arrow);
            string rule = value.substr(arrow+2);

            prodGrammer->insertProd(grammer);

            string rules[10];

            int i = 0;
            string cutRules= rule;
            if(cutRules.find("|") != string::npos){
                while(cutRules.find("|") != string::npos){
                    cout << "Value: "<<(cutRules);
                    int loc=  cutRules.find("|");
                    rules[i] = cutRules.substr(0,loc);
                    cutRules = cutRules.substr(loc+1);
                    i++;
                    if(cutRules.find("|") == string::npos){
                        rules[i] = cutRules;
                    }
                    // cout << "Rules " << rules[i-1];
                    
                }   
            }else{
                rules[0] = rule;
            }
            

            // i = 0;
            // while(i!=3){
            //     cout << "\nloop" << rules[i];
            //     i++;
            // }
            int j = 0;
            prodE = prodGrammer->findProd(grammer); 
            while(j <= i){
                cout << "\nIN j rules -: "<< rules[j];
                prodE->rulesList->insertRule(rules[j]);
                
                Rule* ruleNode = prodE->rulesList->findRule(rules[j]);
                string sep = rules[j];
                if(sep.find("+")!= string::npos){
                    ruleNode->withinRuleList->insertWithinRule(sep.substr(0,sep.find("+")));
                    ruleNode->withinRuleList->insertWithinRule("+");
                    ruleNode->withinRuleList->insertWithinRule(sep.substr(sep.find("+")+1));
                }else if(sep.find("*")!= string::npos){
                    ruleNode->withinRuleList->insertWithinRule(sep.substr(0,sep.find("*")));
                    ruleNode->withinRuleList->insertWithinRule("*");
                    ruleNode->withinRuleList->insertWithinRule(sep.substr(sep.find("*")+1));
                }
                else{
                    ruleNode->withinRuleList->insertWithinRule(sep);
                }
                j++;
            }
        }
    }
    prodGrammer->displayProdList();
    // prodE->rulesList->displayRuleList();
}   
