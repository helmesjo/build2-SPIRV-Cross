/* Packaging-only input for c.predefs. Must match SPVC_C_API_VERSION_* in
   spirv_cross_c.h. Not installed, and not an #include of that public header
   (MSVC cl /EP /PD cannot see stddef.h without system /I). */

#define SPVC_C_API_VERSION_MAJOR 0
#define SPVC_C_API_VERSION_MINOR 68
#define SPVC_C_API_VERSION_PATCH 0
