#include <iostream>
#include <vector>

using std::cout; using std::vector; using std::pair;

//this class is intended to create a data structure for a math polynomial management 

class polynomial{
    vector<pair<int,int>> data{};
    unsigned int degree{};

    int pow(int number, int exp) const{
        int amount{number};

        for(int i{0}; i < (exp - 1); ++i){
            amount *= (number);
        }

        return amount;
    }

    public:
        inline polynomial() {}; 
        inline polynomial(const polynomial& to_copy){
            int sz{to_copy.data.size()};

            data = vector<pair<int,int>>{sz};

            for(size_t i{0}; i < sz; ++i){
                data.at(i).first = to_copy.data.at(i).first;
                data.at(i).second = to_copy.data.at(i).second;
            }
        }
        inline polynomial(const unsigned int& degree) : degree(degree){
            data.resize(degree);
            
            for(size_t i{0}; i < data.size(); ++i){
                if(!i){
                    data.at(i).first = 1; data.at(i).second = 0;
                }
                else{
                    data.at(i).first = 0; data.at(i).second = i;
                }
            }
        }

        inline void set(int& coeff, int& exp) {
            if(data.size() < exp) data.resize(exp);

            data.at(exp).first = coeff; data.at(exp).second = exp;
        }   

        inline unsigned int max_degree() const{
            int max{0};

            for(size_t i{1}; i < data.size(); ++i){
                if(data.at(i).second > max) max = data.at(i).second;
            }

            return max;
        }

        inline int at(int& exp) const{
            int output{0}; bool check{true};

            for(size_t i{0}; i < data.size() and check; ++i){
                if(data.at(i).second == exp){
                    output = data.at(i).first; check = false;
                }
            }

            return output;
        }

        inline void delete_null(){
            vector<pair<int,int>> output{};

            for(pair<int,int> it : data){
                if(it.first) output.push_back(it);
            }

            data = output;
        }

        inline int evaluate(int& x) const{
            int total{0};

            for(size_t i{0}; i < data.size(); ++i){
                if(data.at(i).first){
                    total += pow(x,data.at(i).second);
                    total *= data.at(i).first;
                }
            }

            return total;
        }

        inline void print() const{
            for(pair<int,int> it : data){
                cout<<it.first << " " <<it.second <<"\n";
            }
        }
};

int main(int argc, char const *argv[])
{                
    
}
