#ifndef PARTS_LIBRARY_H
#define PARTS_LIBRARY_H

#include <stddef.h>

#define MAX_LINE_LENGTH 2048
#define MAX_PROPERTY_LENGTH 256

// Structure to store a single part record
typedef struct {
    char symbol[64];
    char value[128];
    char footprint[128];
    char mpn[128];
    char digikey_url[256];
    int quantity;
} PartRecord;

// Structure to store the entire parts library
typedef struct {
    PartRecord *parts;
    size_t size;
    size_t capacity;
} PartsLibrary;

typedef struct {
    char part_number[MAX_PROPERTY_LENGTH];
    char description[MAX_PROPERTY_LENGTH];
    char manufacturer[MAX_PROPERTY_LENGTH];
    char unit_price[MAX_PROPERTY_LENGTH];
    char stock[MAX_PROPERTY_LENGTH];
    char product_url[MAX_PROPERTY_LENGTH];
} PartInfo;

// Functions to manage the parts library
void init_parts_library(PartsLibrary *lib);
void load_parts_library(PartsLibrary *lib, const char *filename);
void save_parts_library(const PartsLibrary *lib, const char *filename);
void save_basket(const PartsLibrary *lib, const char *filename);
PartRecord *find_part(PartsLibrary *lib, const char *symbol, const char *value, const char *footprint);
void add_part(PartsLibrary *lib, const char *symbol, const char *value, const char *footprint, const char *mpn, const char *digikey_url, int quantity);
void free_parts_library(PartsLibrary *lib);
PartInfo parse_csv(const char *filename);

#endif // PARTS_LIBRARY_H
