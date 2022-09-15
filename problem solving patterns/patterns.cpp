#include <iostream>
#include <unordered_map>
#include <vector>

using std::vector; using std::unordered_map;

/**
 * @brief The purpose of this source file is to present some of the most famous problem solving design pattern
 * Two Pointers pattern
 * Frequency Counter
 * 
 * @author Andrea Maggetto
 */



/**
 * @brief: Two pointers pattern; Pattern built on two flag variable placed on the two extreme bounds of the data structure.
 * Through this algorithm, the time complexity is reduced from O(n^2) to O(nlogn).
 * 
 * The following functions simply reverse an input string.
 */
void reverse(std::string& str){
    char swapper{};

    for(size_t i{0},j{str.size() - 1}; j > i; ++i,--j){
        swapper = str.at(i);
        str.at(i) = str.at(j);
        str.at(j) = swapper;
    }
}



/**
 * @brief: Frequency Counter; Pattern build upon the use of an efficent unordered_map; Its access time is O(1)
 * 
 * The following functions check whether all the items of the first vector are also stored in the second one.
 */
bool is_there(const vector<int>& first, const vector<int>& second){
    if(first.size() and second.size()){
        unordered_map<int,int> values{};

        for(int it : first) values[it] = 1;

        for(int it : second){
            if(!values[it]) return false;
            else --(values[it]);
        }

        return true;
    }
}

/**
 * @brief Divide and Conquer through a simple binary search algorithm. 
 * The Divide and Conquer pattern is helpful when it comes to divide a bigger problem in smaller ones, computing a result and then compounding to get the final result.
 * One of the common algorithms that lies in this class is Binary Search; A default search would have O(n) complexity whereas with an efficient BS algorithm it's reduced up to O(log(n))
 * 
 */
bool binary_search(const vector<int>& v, const int& value){ 
    if(v.size()){
        int middle_value{v.at(v.size() / 2)};   
        if(middle_value == value) return true;
        else{
            bool check{false};
            if(value < middle_value){
                for(size_t i{0}; i < middle_value and !check; ++i) check |= (v.at(i) == value);
            }
            else{
                for(size_t i{middle_value + 1}; i < v.size() and !check; ++i) check |= (v.at(i) == value);
            }
            return check;
        }
    }
    return false;
}




