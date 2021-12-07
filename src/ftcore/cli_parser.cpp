#include <fractool/ftcore/cli_parser.hpp>

// External
#include <boost/program_options.hpp>
#include <boost/log/trivial.hpp>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <map>

// Program options namespace
namespace po = boost::program_options;

/**
 * Print help message
 */
static void print_help(po::options_description desc) {
    BOOST_LOG_TRIVIAL(debug) << "Printing help message";
    std::cout << std::endl
        << "$ fractool [options]" 
        << std::endl << std::endl
        << desc 
        << std::endl;
};

/**
 * Operator system to pull ALGORITHM type from cli
 */
static std::map<std::string, ALGORITHM> const lookup = {
    { "mbrot", ALGORITHM::MANDELBROT },
    { "julia", ALGORITHM::JULIA }
};
std::istream& operator>> (std::istream &in, ALGORITHM &algorithm)
{
    algorithm = ALGORITHM::_INVALID;
    std::string str;
    in >> str;
    auto it = lookup.find(str);
    if (it != lookup.end()) { algorithm = it->second; }
    return in;
};
const char* repr_algorithms() {
    std::stringstream sin;
    sin << "Set algorithm type (";
    for (auto it = lookup.begin(); it != lookup.end(); ++it) {
        sin << it->first;
        if (it != --lookup.end()) sin << "|";
    }
    sin << ")";
    return strdup(sin.str().c_str());
};


/**
 * Parse command line arguments and generates config
 *
 * @param argc number of command line arguments
 * @param argv command line arguments buffer
 *
 * @return generated config file
 */
config config_from_cli(int argc, char **argv) {
    BOOST_LOG_TRIVIAL(debug) << "Parsing command line options";

    // Setup options description
    po::options_description desc("Configuration options");
    desc.add_options()
        ("help,h", "Produce help message")
        ("algorithm,a", po::value<ALGORITHM>(), repr_algorithms())
        ("image-size-x,u", po::value<int>(), "Set horizontal image size")
        ("image-size-y,v", po::value<int>(), "Set vertical image size");

    // Parse options
    po::variables_map vm;

    // Run options parsing
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    // Exit if printing help
    if (vm.count("help")) {
        print_help(desc);
        BOOST_LOG_TRIVIAL(debug) << "Exiting with status 0...";
        exit(0);
    }

    // Set config
    BOOST_LOG_TRIVIAL(debug) << "Setting config";
    config cfg;
    if (vm.count("image-size-x")) {
        BOOST_LOG_TRIVIAL(debug) << "image-size-x = " << vm["image-size-x"].as<int>();
        cfg.image_size_x = vm["image-size-x"].as<int>();
    }
    if (vm.count("image-size-y")) {
        BOOST_LOG_TRIVIAL(debug) << "image-size-y = " << vm["image-size-y"].as<int>();
        cfg.image_size_y = vm["image-size-y"].as<int>();
    }
    if (vm.count("algorithm")) {
        BOOST_LOG_TRIVIAL(debug) << "algorithm = " << vm["algorithm"].as<ALGORITHM>();
        if (vm["algorithm"].as<ALGORITHM>() == ALGORITHM::_INVALID) {
            BOOST_LOG_TRIVIAL(error) << "Invalid algorithm type!";
            print_help(desc);
            BOOST_LOG_TRIVIAL(debug) << "Exiting with status 1...";
            exit(1);
        }
        cfg.algorithm = vm["algorithm"].as<ALGORITHM>();
    }

    // Return config
    return cfg;
}