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


