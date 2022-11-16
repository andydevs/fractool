// Fractool
#include <fractool/colormap.hpp>
#include <fractool/fractool/cli_parser.hpp>

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
 * Print colormaps list
 */
static void print_cmaps() {
    BOOST_LOG_TRIVIAL(debug) << "Printing colormaps list";
    std::cout << std::endl 
        << "Colormaps list:" 
        << std::endl 
        << std::endl;
    for (auto it = cmap_lookup.begin(); it != cmap_lookup.end(); ++it) {
        std::cout << "\t- " << it->first << std::endl;
    }
    std::cout << std::endl;
}

/**
 * Map names to algorithm types
 */
static std::map<std::string, ALGORITHM> const algo_lookup = {
    { "mbrot", ALGORITHM::MANDELBROT },
    { "julia", ALGORITHM::JULIA }
};

/**
 * Representation of algorithm types (for printing in help message)
 */
static const char* repr_algorithms() {
    std::stringstream sin;
    sin << "Set algorithm type (";
    for (auto it = algo_lookup.begin(); it != algo_lookup.end(); ++it) {
        sin << it->first;
        if (it != --algo_lookup.end()) sin << "|";
    }
    sin << ")";
    return strdup(sin.str().c_str()); // SECURITY RISK
};

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

/**
 * Operator to inrerpret colormap from input string
 */
std::istream& operator>> (std::istream &in, colormap &colormap)
{
    colormap = COLORMAP_FLOWER;
    std::string str;
    in >> str;
    auto it = cmap_lookup.find(str);
    if (it != cmap_lookup.end()) { colormap = it->second; }
    else { BOOST_LOG_TRIVIAL(error) << "Invalid colormap name: " << str << ". Defaulting to flower."; }
    return in;
}

// Pair operators
namespace std {
    /**
     * Operator to interpret pair values
     */
    istream& operator>> (std::istream &in, pair<float, float> &mpair)
    {
        char c;
        float a, b;
        in >> a;
        in >> c; if (c != ',') { BOOST_LOG_TRIVIAL(error) << "Invalid character processing pair: \"" << c << "\" expecting \",\""; }
        in >> b;
        mpair.first = a;
        mpair.second = b;
        return in;
    }
}

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
        ("colormaps,m", "List colormaps")
        ("algorithm,a", po::value<ALGORITHM>(), repr_algorithms())
        ("image-size-x,u", po::value<int>(), "Set horizontal image size")
        ("image-size-y,v", po::value<int>(), "Set vertical image size")
        ("colormap,C", po::value<colormap>(), "Set colormap")
        ("parameter,p", po::value<std::pair<float,float>>(), "Set parameter");

    // Parse options
    po::variables_map vm;

    // Run options parsing
    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);
    }
    catch (po::unknown_option& err)
    {
        BOOST_LOG_TRIVIAL(error) << "Invalid option: " << err.get_option_name();
        print_help(desc);
        exit(1);
    }

    // Exit if printing any help message
    if (vm.count("help")) {
        print_help(desc);
        BOOST_LOG_TRIVIAL(debug) << "Exiting with status 0...";
        exit(0);
    }
    else if (vm.count("colormaps")) {
        print_cmaps();
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
        ALGORITHM algo = vm["algorithm"].as<ALGORITHM>();
        if (algo == ALGORITHM::_INVALID) {
            print_help(desc);
            BOOST_LOG_TRIVIAL(debug) << "Exiting with status 1...";
            exit(1);
        }
        BOOST_LOG_TRIVIAL(debug) << "algorithm = " << algo;
        cfg.algorithm = algo;
    }
    if (vm.count("parameter")) {
        std::pair<float, float> param = vm["parameter"].as<std::pair<float, float>>();
        BOOST_LOG_TRIVIAL(debug) << "Read pair (" << param.first << "," << param.second << ")";
    }
    if (vm.count("colormap")) {
        cfg.cmap = vm["colormap"].as<colormap>();
    }

    // Return config
    return cfg;
}