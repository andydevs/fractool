// Includes
#include <fractool/ftensp/config.hpp>
#include <boost/log/trivial.hpp>
#include <iostream>


/**
 * Print algorithm list
 */
void print_algos() {
    BOOST_LOG_TRIVIAL(debug) << "Printing algorithms list";
    std::cout << std::endl 
        << "Algorithms list:" 
        << std::endl 
        << std::endl;
    for (auto it = algo_lookup.begin(); it != algo_lookup.end(); ++it) {
        std::cout << "\t- " << it->first << std::endl;
    }
    std::cout << std::endl;
}

/**
 * Operator to interpret algorithm from input string
 */
std::istream& operator>> (std::istream &in, ALGORITHM &algorithm)
{
    algorithm = ALGORITHM::_INVALID;
    std::string str;
    in >> str;
    auto it = algo_lookup.find(str);
    if (it != algo_lookup.end()) { algorithm = it->second; }
    else { BOOST_LOG_TRIVIAL(error) << "Invalid algorithm type: " << str; }
    return in;
};