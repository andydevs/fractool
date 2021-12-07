#include <fractool/ftcore/cli_parser.hpp>

// External
#include <boost/program_options.hpp>
#include <boost/log/trivial.hpp>
#include <iostream>

// Program options namespace
namespace po = boost::program_options;

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
        ("image-size-x,u", po::value<int>(), "Set horizontal image size")
        ("image-size-y,v", po::value<int>(), "Set vertical image size");

    // Parse options
    po::variables_map vm;

    // Run options parsing
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    // Exit if printing help
    if (vm.count("help")) {
        BOOST_LOG_TRIVIAL(debug) << "Printing help message";
        std::cout << std::endl
            << "$ fractool [options]" 
            << std::endl << std::endl
            << desc 
            << std::endl;
        BOOST_LOG_TRIVIAL(debug) << "Exiting...";
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

    // Return config
    return cfg;
}