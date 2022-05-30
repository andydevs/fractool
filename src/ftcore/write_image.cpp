#include <fractool/macros.hpp>
#include <fractool/ftcore/write_image.hpp>

// External
#include <boost/log/trivial.hpp>
#include <png.h>
#include <cstdio>

// Helper macro
#define PNG_ERROR_IF(condition, error_message) \
    if (condition) { \
        BOOST_LOG_TRIVIAL(debug) << error_message; \
        BOOST_LOG_TRIVIAL(info) << "Failed to create png image"; \
        throw std::exception("Failed to create png image"); \
    }

/**
 * Write image to file
 *
 * @param size_x       horizontal image size
 * @param size_y       vertical image size
 * @param color_buffer color data buffer
 * @param filename     file name to save to
 */
void write_image(const unsigned size_x, const unsigned size_y, unsigned char* color_buffer, const char* filename) {
    BOOST_LOG_TRIVIAL(info) << "Writing Image...";
    
    // Create file header
    FILE* fp = fopen(filename, "wb"); 
    PNG_ERROR_IF(!fp, "failed to create file pointer for filename " << filename);

    // PNG Setup
    png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    PNG_ERROR_IF(!png_ptr, "failed to create png write struct");
    png_infop info_ptr = png_create_info_struct(png_ptr);
    PNG_ERROR_IF(!info_ptr, "failed to create png info struct");
    PNG_ERROR_IF(setjmp(png_jmpbuf(png_ptr)), "failed during init_io");
    png_init_io(png_ptr, fp);
    PNG_ERROR_IF(setjmp(png_jmpbuf(png_ptr)), "failed during write header");
    png_set_IHDR(png_ptr, info_ptr, size_x, size_y, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
    png_write_info(png_ptr, info_ptr);

    // Write rows
    PNG_ERROR_IF(setjmp(png_jmpbuf(png_ptr)), "failed during writing rows");
    png_bytep row = (png_bytep)malloc(size_x * NUM_CHANS * sizeof(png_byte));
    PNG_ERROR_IF(!row, "failed to create png row");
    for (int y = 0; y < size_y; ++y) {
        for (int x = 0; x < size_x; ++x) {
            row[ARRAY2D(NUM_CHANS, RED_CHAN, x)] = color_buffer[IMAGE(size_x, x, y, RED_INDX)];
            row[ARRAY2D(NUM_CHANS, GRN_CHAN, x)] = color_buffer[IMAGE(size_x, x, y, GRN_INDX)];
            row[ARRAY2D(NUM_CHANS, BLU_CHAN, x)] = color_buffer[IMAGE(size_x, x, y, BLU_INDX)];
        }
        png_write_row(png_ptr, row);
    }
    png_write_end(png_ptr, NULL);

    // Teardown
    if (fp != NULL) fclose(fp);
    if (info_ptr != NULL) png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
    if (png_ptr != NULL) png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
    if (row != NULL) free(row);
}