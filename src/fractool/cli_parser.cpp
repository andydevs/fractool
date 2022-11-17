// Fractool
#include <fractool/colormap.hpp>
#include <fractool/fractool/cli_parser.hpp>

// External
#include <boost/program_options.hpp>
#include <boost/log/trivial.hpp>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
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
 * Print algorithm list
 */
static void print_algos() {
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
    template <typename T>
    istream& operator>> (istream &in, pair<T,T> &mpair)
    {
        char c;
        T a, b;
        in >> a; 
        in >> c; 
        if (c != ',') { 
            BOOST_LOG_TRIVIAL(error) << "Invalid character processing pair: \"" << c << "\" expecting \",\""; 
            return in; 
        }
        in >> b;
        mpair.first = a;
        mpair.second = b;
        return in;
    }
}

// Intermediary parameter type
struct parameter {
    std::string name;
    std::string value;
};

/**
 * Operator to interpret parameter
 */
std::istream& operator>> (std::istream &in, parameter &param)
{
    std::string name, value;
    std::getline(in, name, '=');
    std::getline(in, value, '=');
    param.name = name;
    param.value = value;
    return in;
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
    po::options_description help("Help");
    help.add_options()
        ("help,h", "Produce help message")
        ("colormaps,m", "List colormaps")
        ("algorithms,n", "List algorithms");
    po::options_description algorithm("Algorithm");
    algorithm.add_options()
        ("algorithm,a", po::value<ALGORITHM>(), "Use algorithm (see --algorithms)")
        ("parameter,p", po::value<std::vector<parameter>>()->value_name("param=value"), 
            "Set parameter. Set this option multiple times to set multiple parameters");
    po::options_description image("Image");
    image.add_options()
        ("colormap,C", po::value<colormap>(), "Use colormap (see --colormaps)")
        ("image-size,i", po::value<std::pair<unsigned,unsigned>>()->value_name("width,height"), "Set image size");
    po::options_description options("Available Options:");
    options.add(help).add(algorithm).add(image);

    // Parse options
    po::variables_map vm;

    // Run options parsing
    try {
        po::store(po::parse_command_line(argc, argv, options), vm);
        po::notify(vm);
    }
    catch (po::unknown_option& err)
    {
        BOOST_LOG_TRIVIAL(error) << "Invalid option: " << err.get_option_name();
        print_help(options);
        exit(1);
    }

    // Exit if printing any help message
    if (vm.count("help")) {
        print_help(options);
        BOOST_LOG_TRIVIAL(debug) << "Exiting with status 0...";
        exit(0);
    }
    else if (vm.count("colormaps")) {
        print_cmaps();
        BOOST_LOG_TRIVIAL(debug) << "Exiting with status 0...";
        exit(0);
    }
    else if (vm.count("algorithms")) {
        print_algos();
        BOOST_LOG_TRIVIAL(debug) << "Exiting with status 0...";
        exit(0);
    }

    // Set config
    BOOST_LOG_TRIVIAL(debug) << "Setting config";
    config cfg;
    if (vm.count("image-size")) {
        std::pair<unsigned,unsigned> size = vm["image-size"].as<std::pair<unsigned,unsigned>>();
        BOOST_LOG_TRIVIAL(debug) << "image-size = " << size.first << "," << size.second;
        cfg.image_size_x = size.first;
        cfg.image_size_y = size.second;
    }
    if (vm.count("algorithm")) {
        ALGORITHM algo = vm["algorithm"].as<ALGORITHM>();
        if (algo == ALGORITHM::_INVALID) {
            print_algos();
            BOOST_LOG_TRIVIAL(debug) << "Exiting with status 1...";
            exit(1);
        }
        BOOST_LOG_TRIVIAL(debug) << "algorithm = " << algo;
        cfg.algorithm = algo;
    }
    if (vm.count("parameter")) {
        std::vector<parameter> ps = vm["parameter"].as<std::vector<parameter>>();
        for (parameter p : ps) {
            BOOST_LOG_TRIVIAL(debug) << "parameter " << p.name << " = " << p.value;
            cfg.parameters[p.name] = p.value;
        }
    }
    if (vm.count("colormap")) {
        cfg.cmap = vm["colormap"].as<colormap>();
    }

    // Return config
    return cfg;
}