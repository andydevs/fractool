// Fractool
#include <fractool/macros.hpp>
#include <fractool/ftcore/map_color.hpp>

// External
#include <boost/log/trivial.hpp>

/**
 * Map parameter space to color space using colormap
 */
void map_color(unsigned size_x, unsigned size_y, const colormap cmap, unsigned char* param_buffer, unsigned char* color_buffer)
{
    BOOST_LOG_TRIVIAL(info) << "Mapping Color...";
    unsigned char n;
    for (unsigned j = 0; j < size_y; ++j) {
        for (unsigned i = 0; i < size_x; ++i) {
            // Get parameter
            n = param_buffer[ARRAY2D(size_x, i, j)];

            // Color image using colormap
            color_buffer[IMAGE(size_x, i, j, BLU_CHAN)] = cmap.data[ARRAY2D(NUM_CHANS, BLU_CHAN, n)];
            color_buffer[IMAGE(size_x, i, j, GRN_CHAN)] = cmap.data[ARRAY2D(NUM_CHANS, GRN_CHAN, n)];
            color_buffer[IMAGE(size_x, i, j, RED_CHAN)] = cmap.data[ARRAY2D(NUM_CHANS, RED_CHAN, n)];
        }
    }
}