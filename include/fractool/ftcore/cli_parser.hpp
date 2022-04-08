#ifndef __FRACTOOL_PARSER_H__
#define __FRACTOOL_PARSER_H__

#include <fractool/macros.hpp>
#include <fractool/ftcore/config.hpp>

/**
 * Parse command line arguments and generates config
 *
 * @param argc number of command line arguments
 * @param argv command line arguments buffer
 *
 * @return generated config file
 */
config EXPORT config_from_cli(int argc, char **argv);

#endif // __FRACTOOL_PARSER_H__