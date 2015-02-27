#include "moon.h"

#include "colors.h"

uint8_t MOON[] = {
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 211,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 196, 193, 189, 188, 189, 186, 176, 170, 173, 179, 191, 206, 211, 211, 211, 211, 211,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 120, 143, 142, 131, 123, 131, 120, 110, 120, 136, 148, 142, 133, 140, 154, 160, 162, 189, 205, 211, 211, 211, 211,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 104,  99, 100, 104,  75,  60,  81, 110, 152, 142, 151, 146, 152, 164, 140, 136, 115, 104, 110, 119, 123, 155, 170, 196, 211, 205, 205, 202, 198,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  81,  71,  77,  90,  95, 100, 128, 139, 145, 160, 175, 172, 179, 155, 155, 157, 151, 143, 152, 157, 137, 143, 140, 123, 100, 123, 152, 172, 173, 178, 191, 185, 188,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  81,  62,  64,  77,  79,  77,  66,  92, 134, 151, 148, 164, 143, 115, 119, 117, 140, 143, 130, 128, 115, 152, 176, 151, 154, 158, 142, 125, 123, 145, 148, 152, 173, 161, 175, 186, 183,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  69,  55,  69,  71,  69,  73,  64,  90, 128, 123, 120, 142, 140,  75,  71,  88,  81, 100,  81,  82, 102,  81, 107, 128, 114, 125, 148, 167, 182, 120, 117, 134, 134, 133, 151, 157, 166, 179, 201,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  73,  52,  62,  71,  69,  69,  69,  79,  82, 112, 112, 126, 122, 112,  97,  71,  69,  77,  71,  55,  60,  75,  86,  84, 112, 119, 109, 119, 143, 170, 193, 166, 143, 126, 131, 123, 125, 128, 143, 167, 178, 206, 211,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  66,  66,  62,  66,  62,  57,  64,  79,  75,  86,  99, 107, 109,  93,  55,  74,  73,  62,  57,  66,  71,  71,  73,  84,  86,  88,  99, 110,  90, 109, 155, 176, 176, 166, 134, 140, 125, 126, 119, 110, 110, 130, 163, 211, 211,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  41,  69,  60,  55,  64,  64,  69,  77,  77,  73,  73,  75,  93,  75,  62,  76,  77,  71,  64,  62,  62,  69,  71,  71,  79,  90,  93,  92,  93,  97,  95, 120, 152, 167, 178, 142, 131, 137, 164, 158, 128, 112, 102, 109, 157, 211, 211,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  81,  66,  52,  52,  55,  73,  79,  79,  84,  82,  77,  79,  84,  71,  66,  81,  84,  75,  71,  71,  69,  62,  69,  73,  71,  81,  93,  88,  82,  90,  97, 107, 112, 157, 166, 178, 161, 154, 152, 137, 149, 140, 130, 124, 119, 115, 166, 208, 211,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  73,  73,  52,  57,  52,  66,  77,  84,  93,  95,  84,  79,  77,  81,  81,  79,  82,  77,  64,  64,  71,  66,  66,  66,  77,  77,  84,  92,  88,  86,  99, 107, 122, 126, 123, 151, 170, 173, 161, 172, 178, 166, 166, 151, 148, 136, 134, 166, 182, 201, 199,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  86,  69,  47,  55,  52,  55,  71,  62, 112, 120,  81,  95,  92,  69,  77,  95,  86,  75,  73,  73,  66,  66,  69,  69,  64,  81,  77,  77,  84,  81,  79, 104, 107, 125, 122, 119, 142, 149, 166, 182, 173, 172, 167, 161, 142, 130, 130, 148, 170, 178, 180, 179, 199,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,  81,  75,  66,  57,  52,  55,  62,  71, 139, 182,  90,  97, 100,  79,  75,  79,  82,  79,  67,  73,  81,  81,  75,  77,  69,  79,  77,  79,  81,  82,  77,  77, 105, 102, 114, 120, 108, 126, 146, 175, 189, 167, 158, 161, 148, 139, 134, 142, 154, 143, 175, 183, 182, 185, 189,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,  79,  50,  64,  69,  44,  50,  55,  66,  86, 119, 130,  92,  84,  79,  62,  71,  64,  63,  66,  64,  71,  86,  77,  77,  73,  69,  88,  71,  75,  84,  77,  81,  82,  90, 102, 112, 143, 117, 104, 145, 173, 154, 133, 146, 166, 154, 122, 115, 149, 164, 142, 149, 160, 186, 188, 161, 183,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0, 117,  34,  57,  55,  41,  44,  52,  57,  62,  73,  64,  60,  90,  77,  73,  75,  69,  75,  66,  99,  82,  64,  79,  77,  82,  71,  77,  79,  93, 109,  88,  79,  92, 110, 114, 122, 125, 133, 115, 104, 134, 164, 104,  75,  77, 120, 152, 130, 100, 120, 133, 149, 148, 143, 152, 193, 155, 172, 158,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,  73,  60,  52,  44,  44,  47,  55,  57,  60,  62,  69,  69,  88,  84,  73,  84,  81,  84,  93, 110,  93,  73,  92,  81,  84,  75,  84,  77,  95, 115,  95, 112, 128, 126, 112, 119, 137, 145, 125, 109, 142, 114,  79,  90,  88,  82, 110, 133, 123, 117, 126, 143, 128, 151, 163, 170, 169, 148, 186,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0, 105,  60,  50,  50,  50,  47,  44,  52,  57,  60,  62,  62,  73,  90,  84,  75,  71,  71,  81,  97,  95,  86,  92,  81,  99,  93,  92,  88,  77,  79,  82,  81, 115, 133, 139, 130, 105, 117, 143, 130, 115,  92,  88,  77,  71,  84,  88,  92, 104, 110,  92, 110, 128, 102, 128, 172, 178, 180, 167, 167, 170,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0, 137,  82,  69,  50,  50,  47,  44,  44,  50,  50,  62,  62,  62,  77,  88, 107,  77,  64,  77,  88,  82,  84,  95, 100,  88, 100,  95,  82,  92,  81,  88,  86,  71,  84, 130, 142, 134, 119,  81,  99, 160, 140,  95,  86,  84,  79,  79,  79,  79,  84,  92,  84, 117, 137,  99, 117, 178, 167, 164, 167, 178, 172, 157,   0,   0,   0,   0, 
  0,   0,   0,   0,   0, 126,  90,  69,  50,  50,  47,  47,  52,  55,  50,  69,  69,  64,  79,  86, 110,  69,  82,  92, 114, 140, 123, 119, 105,  84,  84,  93,  95,  92,  90,  90,  86,  88,  79,  90, 114, 142, 145, 142, 152, 148, 126,  90,  77,  88,  75,  77,  82,  79,  93,  88,  73, 134, 168, 120, 133, 140, 179, 182, 178, 179, 176, 191,   0,   0,   0,   0, 
  0,   0,   0,   0, 146, 130, 107,  69,  44,  44,  50,  52,  50,  52,  52,  57,  62,  69,  86,  92,  97,  84,  88,  95, 122, 143, 123, 133, 136, 105, 107, 102, 110, 104,  95,  92, 104,  82,  69,  69, 115, 158, 180, 189, 158, 157, 112,  73,  71,  73,  75,  82,  84,  84,  89,  86,  69, 109, 173, 151, 167, 164, 183, 198, 178, 180, 195, 183, 160,   0,   0,   0, 
  0,   0,   0,   0, 160, 126,  99,  62,  50,  73,  62,  55,  52,  53,  50,  47,  64,  79, 104, 115, 112,  90,  55,  97, 131, 142, 136, 126, 155, 143, 133, 123, 126, 123, 115, 109, 107, 104, 126, 130, 143, 151, 158, 167, 140, 120,  88,  64,  66,  64,  77,  79,  82,  90,  86,  77,  71,  62, 123, 160, 175, 188, 189, 182, 191, 173, 199, 186, 169,   0,   0,   0, 
  0,   0,   0, 155, 134, 125, 114,  57,  50,  62,  55,  57,  57,  55,  52,  64,  79, 104, 137, 131, 115,  84,  88, 109, 133, 152, 154, 122, 145, 158, 145, 131, 128, 139, 131, 115, 112, 123, 146, 133, 145, 146, 134, 126, 125, 109,  92,  81,  62,  73,  75,  73,  92,  90,  82,  77,  81,  60, 102, 166, 191, 183, 188, 195, 206, 180, 199, 199, 167, 136,   0,   0, 
  0,   0,   0, 142, 133, 139, 112,  62,  44,  41,  50,  55,  55,  55,  55,  66,  81, 114, 142, 151, 123,  86,  88,  99, 117, 134, 137, 167, 196, 193, 140, 133, 134, 133, 122, 109,  86,  84, 120, 123, 133, 122, 107, 109, 117, 102,  99,  92,  86,  71,  73,  84,  99,  81,  73,  77,  81,  71, 109, 167, 203, 196, 182, 199, 201, 188, 192, 186, 166, 167,   0,   0, 
  0,   0,   0, 139, 131, 139,  97,  50,  47,  44,  47,  52,  57,  60,  50,  64,  84,  95, 130, 134, 100,  97,  93, 104,  99, 125, 136, 167, 208, 196, 137, 128, 130, 134, 115, 100,  99,  84,  86,  86, 109,  95,  79,  84,  90, 100,  75,  84, 107,  90,  57,  88,  86,  81,  75,  79,  79,  75, 115, 152, 196, 203, 185, 176, 199, 209, 185, 195, 154, 179,   0,   0, 
  0,   0, 131, 140, 131, 123,  69,  47,  44,  47,  47,  55,  52,  50,  48,  57,  92,  72, 125,  99,  77, 100, 109, 126, 117, 131, 126, 114, 130, 123, 126, 122, 125, 126, 112,  99,  84,  79,  55,  55,  90,  86,  88,  84,  75,  81, 148, 128,  95, 106, 107,  75,  79,  77,  79,  84,  77,  71, 128, 151, 157, 172, 188, 176, 178, 180, 183, 175, 172, 182, 148,   0, 
  0,   0, 120, 122, 145,  97,  73,  52,  50,  47,  50,  55,  50,  53,  52,  58,  84,  92, 109,  69,  97,  99,  82,  97, 120, 140, 126, 122, 107, 105, 105,  97, 104, 117, 105,  82,  84,  86,  81,  86, 100,  86,  71,  75,  75,  66, 152, 152,  81,  88, 178, 136,  82,  82,  66,  75,  66,  84, 139, 154, 143, 128, 172, 167, 143, 161, 173, 154, 185, 185, 173,   0, 
  0,   0, 105, 122, 133, 112,  82,  52,  47,  41,  50,  52,  50,  52,  47,  57,  66,  73,  82,  81,  81,  93,  88,  90, 117, 120, 136, 122, 107, 112,  84,  79,  97, 100,  82,  69,  81,  99, 117, 128, 133, 123,  92,  69,  57,  66,  90, 100, 100, 115, 125, 136, 117, 104,  82,  81,  82,  81, 130, 134, 123, 109, 186, 160, 158, 158, 163, 173, 161, 172, 183,   0, 
  0, 134, 114, 122,  81, 114,  90,  47,  41,  50,  73,  57,  47,  52,  47,  60,  57,  55,  66,  73,  79,  84, 102, 100, 105, 112, 142, 133, 110, 102,  86,  90,  92,  95,  47,  60,  77, 102, 160, 146, 145, 158, 110,  95,  73,  66,  90,  93, 112, 146, 139,  97,  90,  64,  93,  77,  75,  64,  95, 117, 104, 104, 152, 175, 172, 169, 167, 151, 125, 152, 186, 122, 
  0, 134, 125,  95,  73, 131,  84,  69,  41,  47,  64,  60,  52,  55,  55,  66,  55,  52,  66,  77,  84,  81,  90, 109,  90, 120, 119, 137, 142,  97,  84,  92, 107,  88,  75,  73,  90, 107, 152, 142, 142, 149, 136, 125, 112, 100, 100, 148, 142, 146, 122,  66,  64,  64,  60,  62,  71,  70,  69,  93,  93,  79,  97, 176, 192, 182, 143,  84,  88, 137, 178, 145, 
  0, 137, 131,  93, 125, 143,  79,  62,  46,  44,  66,  62,  66,  60,  57,  60,  57,  55,  66,  75, 100,  92, 105,  95,  92,  95, 102, 110, 131, 110,  86,  84,  99,  88,  84,  92,  77,  93, 122, 139, 151, 134, 183, 152, 115, 133, 123, 152, 154, 133, 115,  73,  66,  71,  63,  73,  73,  77,  71,  73,  79,  69, 126, 154, 211, 206, 133,  90,  97,  86, 146, 169, 
  0, 133, 122, 119, 123, 122, 100,  73,  57,  44,  50,  57,  47,  57,  52,  71,  73,  64,  81,  73,  71,  92,  86,  90,  77,  81,  82, 100, 122, 112, 110,  95,  93,  90, 107, 117, 100, 105, 101, 112, 140, 155, 183, 161, 167, 176, 170, 167, 169, 146, 102,  66,  60,  60,  60,  84,  86,  75,  66,  60,  71,  60, 120, 143, 183, 211, 146,  77,  84,  69, 131, 167, 
  0, 123, 123, 125, 122, 122, 105,  71,  55,  66,  57,  64,  64,  55,  55,  71,  71,  60,  82,  77, 107, 117, 105,  90,  75, 107, 109, 114, 126, 123, 119, 119,  93, 107, 134, 148, 130, 105,  82, 109, 114, 158, 166, 164, 182, 211, 203, 170, 160, 134, 105,  69,  73,  71,  77,  64,  73,  62,  64,  62,  62,  47, 109, 152, 163, 202, 139,  77,  81,  60, 109, 169, 
  0, 120, 123, 133, 125, 140, 131,  73,  69, 104,  69,  66,  57,  53,  60,  69,  64,  60,  84,  95, 136, 136,  93,  71,  81, 109, 112, 128, 128, 128, 104, 131, 154, 149, 130, 155, 151, 131,  90, 120, 151, 175, 185, 196, 193, 211, 211, 178, 148, 133, 107,  79,  88,  79,  77,  64,  66,  69,  69,  64,  62,  73,  71, 105, 161, 211, 140,  62,  81,  55, 105, 167, 
  0, 123, 134, 126, 109, 145, 160,  97,  92, 107,  75,  79,  81,  71, 107,  77,  55,  73,  73,  84, 125, 115,  55,  66,  86,  93, 110, 125, 128, 112,  92, 109, 180, 183, 155, 188, 154, 151, 140, 136, 160, 185, 178, 192, 195, 211, 211, 186, 149, 161, 126,  75,  77,  73,  66,  66,  69,  73,  64,  64,  64,  79,  82,  99, 128, 186, 164,  71,  79,  66, 114, 166, 
  0, 122, 128, 115, 110, 120, 130, 117, 114,  84,  97, 100,  97,  92, 123,  90,  57,  71,  71,  73, 102,  81,  66,  73,  79,  79,  97, 143, 154, 105,  75, 115, 149, 172, 161, 160, 178, 166, 160, 154, 163, 178, 191, 198, 183, 198, 182, 183, 173, 148, 125,  90,  71,  73,  75,  73,  71,  79,  75,  71,  69,  69, 120, 125, 130, 185, 172, 107,  50,  79, 148, 158, 
122, 119, 120, 102, 125, 126, 115, 115, 117,  82, 102, 105, 109, 115, 133, 109,  79,  69,  57,  81,  81,  71,  69,  60,  77,  77,  86, 123, 137,  92,  69,  95, 125, 149, 158, 173, 183, 180, 166, 169, 164, 185, 195, 189, 172, 183, 185, 192, 188, 160, 130, 100,  73,  86,  79,  71,  86,  88,  81,  92,  81,  84,  93, 102,  95, 160, 178, 145,  93, 123, 163, 151, 
  0, 130, 115, 125, 140, 136, 120, 115, 110, 105, 100, 107, 114, 126, 133,  93, 114,  82,  50,  62,  79,  93,  92,  93,  79,  77,  82, 107, 142, 112,  82,  79, 119, 152, 165, 158, 157, 166, 163, 170, 175, 180, 182, 176, 188, 192, 191, 188, 189, 183, 175, 145,  95,  88,  77,  81,  84,  99,  92,  84,  79,  84,  88, 128, 119, 128, 170, 155, 152, 151, 157, 148, 
  0, 126, 146, 148, 139, 149, 136, 122, 114, 120, 133, 146, 139, 133, 134,  88, 102,  92,  97,  57,  90, 115, 146, 126,  88, 105, 110,  97, 149, 107,  97, 102, 137, 149, 180, 142, 139, 145, 172, 179, 182, 192, 211, 211, 188, 185, 186, 196, 189, 199, 211, 180, 163, 115,  84,  84,  79, 166, 152,  66,  69,  92, 112, 119, 117,  90, 160, 163, 143, 137, 142, 146, 
  0, 139, 131, 149, 160, 160, 137, 115, 119, 125, 145, 161,  97,  77, 102,  64,  88,  84,  86,  77, 102, 130, 137,  90,  81, 102,  90, 105, 114,  82,  75,  99, 134, 139, 164, 164, 146, 152, 164, 165, 176, 202, 211, 211, 196, 201, 188, 192, 211, 211, 211, 205, 186, 128,  83,  86, 154, 198, 167, 128, 102, 112, 120,  92,  81,  60, 133, 163, 164, 139, 125, 139, 
  0, 145, 122, 140, 186, 183, 164, 150, 125, 131, 131, 102,  66,  50,  37,  52,  60, 112, 122, 110, 114, 128,  97,  81,  81,  97,  93,  84,  86,  71, 105, 130,  97, 115, 155, 163, 169, 157, 161, 148, 161, 192, 185, 185, 185, 199, 183, 196, 211, 211, 198, 167, 130, 110, 102, 126, 173, 151, 163, 158, 143, 122,  75,  84,  79,  57,  97, 152, 157, 130, 107, 128, 
  0, 134, 114, 136, 193, 191, 155, 161, 152, 128, 152, 105,  50,  57,  60,  62,  60, 119, 136, 100, 123, 109, 104, 100,  81,  99,  88,  84,  90,  84,  71, 100, 117, 137, 167, 157, 163, 158, 175, 161, 180, 182, 180, 183, 196, 192, 198, 201, 201, 211, 173, 148, 115, 115, 117, 149, 169, 164, 157, 154, 133,  90,  79,  77,  77,  71,  66,  99, 139, 130, 146, 125, 
  0, 140, 128, 125, 155, 172, 145, 143, 155, 140, 149, 120,  64,  73,  57,  52,  44, 110, 112, 104, 102,  95, 131, 131,  81,  88,  79,  71,  71,  90,  73, 102, 139, 155, 169, 166, 169, 155, 163, 179, 170, 164, 183, 183, 185, 203, 211, 211, 209, 211, 186, 143, 133, 123, 115, 152, 167, 163, 145, 151, 136,  81,  84,  84,  66,  66,  60,  86, 117, 123, 149, 104, 
  0, 142, 128, 119, 119, 146, 137, 140, 169, 167, 134, 105,  66,  71,  57,  62,  57,  66, 104, 104,  77, 107, 100, 104,  84,  92,  75,  75,  92,  84,  75, 154, 179, 158, 178, 180, 163, 179, 170, 166, 172, 176, 185, 175, 180, 205, 209, 203, 211, 211, 201, 188, 166, 120, 131, 163, 161, 186, 176, 130, 137, 102,  77,  77,  71,  71,  73, 102,  99, 128, 125,  62, 
  0, 128, 125, 115, 125, 131, 143, 133, 160, 170, 148, 130, 104,  75,  57,  60,  81,  93, 100, 126,  75, 114, 107,  90,  73,  95, 105,  71,  84,  71, 100, 146, 170, 175, 179, 180, 161, 195, 209, 175, 188, 199, 205, 185, 188, 198, 192, 182, 195, 211, 211, 211, 182, 143, 140, 152, 169, 201, 192, 148, 105,  93,  79,  77,  73,  79,  88,  99, 120, 125, 112,   0, 
  0,   0, 126, 115, 117, 117, 137, 137, 152, 176, 170, 152, 122,  99,  77,  82,  86, 123, 114, 128,  86,  88, 105,  90,  75,  69,  73,  73,  71,  81, 126, 137, 179, 183, 167, 146, 160, 175, 183, 188, 163, 188, 199, 188, 183, 176, 173, 186, 202, 211, 211, 193, 179, 172, 158, 109, 149, 169, 189, 164, 114,  88,  81,  73,  73,  92,  90, 112, 145, 131,  92,   0, 
  0,   0, 128, 114, 122, 123, 126, 131, 131, 161, 188, 160, 131, 112, 114, 122, 119, 154, 120,  92,  97, 102, 130,  92,  77,  66,  64,  69,  77,  79,  93, 131, 170, 185, 167, 167, 173, 163, 183, 164, 149, 166, 173, 178, 173, 169, 191, 198, 201, 211, 211, 211, 169, 142, 128, 109, 105, 154, 186, 183, 142, 105,  69,  71,  86,  92,  88, 114, 128, 130,  64,   0, 
  0,   0, 125, 120, 130, 112, 120, 120, 130, 128, 136, 140, 126, 137, 117, 117, 136, 133,  79, 115, 139, 128, 155, 109,  88,  93, 100,  88,  82,  88, 100, 163, 185, 161, 164, 185, 193, 173, 164, 157, 170, 185, 185, 175, 178, 185, 193, 183, 188, 211, 211, 211, 145, 114, 102,  99, 107, 133, 189, 169, 120, 105,  81,  84,  93, 117, 154, 122, 119, 120,   0,   0, 
  0,   0,   0, 126, 119, 112, 110, 148, 136, 137, 148, 133,  99, 133, 134, 133, 142, 112,  82, 109, 115, 112, 178, 178, 136, 137, 112, 122, 143, 130, 143, 179, 198, 173, 195, 211, 195, 167, 163, 178, 185, 188, 193, 188, 188, 185, 180, 176, 196, 202, 211, 189, 134, 112, 100, 109, 117, 166, 170, 155, 143, 112,  84,  97, 107, 158, 182, 134, 128,  88,   0,   0, 
  0,   0,   0, 120, 119, 126, 112, 143, 130, 117, 136, 130, 104,  86, 134, 128, 133, 126, 105, 136, 100, 117, 180, 211, 179, 163, 145, 157, 178, 179, 202, 211, 206, 211, 211, 211, 188, 172, 199, 211, 195, 193, 203, 201, 180, 178, 164, 183, 191, 185, 193, 180, 140, 109, 109,  88, 136, 185, 176, 157, 154, 143, 112,  99, 109, 160, 157, 136, 128,  73,   0,   0, 
  0,   0,   0, 105, 120, 119, 131, 126, 131, 110, 119, 120, 130, 110, 136, 148, 134, 155, 149, 134, 163, 158, 163, 206, 206, 169, 185, 192, 211, 211, 211, 211, 192, 211, 211, 211, 211, 186, 208, 211, 211, 203, 193, 183, 170, 161, 166, 170, 186, 189, 191, 197, 157, 119,  95,  66, 155, 178, 130, 164, 152, 166, 122,  92, 119, 131, 137, 136, 123,   0,   0,   0, 
  0,   0,   0,   0, 126, 130, 119, 130, 123, 104, 126, 137, 146, 139, 136, 154, 153, 143, 143, 154, 167, 182, 166, 178, 211, 203, 196, 209, 211, 211, 211, 211, 211, 211, 211, 211, 211, 206, 199, 208, 196, 180, 164, 175, 160, 161, 179, 195, 208, 211, 203, 172, 128, 146, 137, 119, 140, 142, 143, 148, 126, 133,  97, 112, 133, 137, 133, 123,  86,   0,   0,   0, 
  0,   0,   0,   0, 105, 128, 123, 119, 130,  84, 102, 133, 125, 131, 146, 157, 164, 152, 137, 137, 164, 173, 172, 178, 202, 209, 208, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 205, 192, 178, 175, 173, 178, 167, 195, 192, 198, 211, 211, 195, 166, 154, 166, 170, 185, 140, 133, 149, 136, 137, 102, 102, 104, 120, 110, 126, 115, 119,  34,   0,   0,   0, 
  0,   0,   0,   0,   0, 125, 120, 115, 123, 119, 107, 125, 120, 105, 133, 160, 166, 157, 169, 166, 148, 166, 189, 185, 208, 209, 211, 211, 211, 211, 211, 211, 211, 209, 211, 211, 211, 201, 193, 185, 173, 176, 179, 195, 211, 208, 186, 186, 182, 186, 182, 182, 175, 164, 154, 126, 158, 145, 133, 128,  77, 136, 143, 115, 110, 120, 122,  79,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,  84, 120, 126, 107, 130, 131, 114, 122, 104, 131, 142, 152, 163, 152, 157, 167, 179, 179, 199, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 205, 211, 203, 191, 196, 199, 203, 189, 211, 211, 191, 166, 179, 183, 173, 188, 195, 183, 175, 154, 152, 183, 158, 157, 158, 130, 120, 167, 155, 122, 117, 110, 117,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,  97, 137, 134, 107, 125, 128, 115, 102, 122, 126, 139, 158, 160, 157, 157, 179, 183, 196, 211, 192, 211, 202, 209, 211, 211, 211, 211, 211, 211, 208, 199, 211, 208, 202, 203, 211, 205, 195, 182, 198, 196, 185, 173, 182, 172, 161, 163, 155, 169, 176, 179, 178, 166, 148, 151, 160, 131, 117, 115, 123,  73,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0, 119, 137, 115, 110, 126, 120, 109, 112, 119, 133, 158, 167, 151, 151, 176, 191, 199, 211, 192, 211, 211, 195, 211, 211, 211, 211, 211, 211, 211, 202, 201, 193, 185, 170, 179, 173, 173, 178, 185, 189, 175, 164, 164, 164, 179, 172, 167, 164, 179, 186, 182, 179, 146, 149, 148, 126, 119, 120,  93,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,  71, 117, 120, 109, 133, 131, 120, 104, 130, 130, 145, 154, 151, 157, 164, 163, 193, 211, 202, 198, 195, 202, 211, 211, 211, 211, 211, 199, 211, 206, 183, 180, 172, 196, 193, 167, 167, 176, 169, 173, 164, 169, 160, 167, 195, 172, 176, 169, 183, 202, 198, 192, 166, 166, 149, 126, 117, 115,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0, 100, 120, 117, 119, 133, 126,  93, 115, 139, 142, 146, 142, 155, 170, 166, 199, 199, 211, 211, 208, 211, 211, 211, 211, 211, 211, 211, 211, 196, 195, 205, 203, 186, 193, 185, 167, 166, 164, 163, 164, 160, 158, 172, 172, 169, 157, 169, 201, 211, 205, 186, 178, 163, 148, 123, 102,  34,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0, 105, 125, 126, 126, 143, 131, 102, 131, 139, 148, 146, 152, 172, 205, 189, 196, 211, 211, 211, 211, 211, 211, 211, 211, 206, 205, 203, 182, 176, 206, 206, 175, 192, 193, 195, 192, 178, 185, 178, 167, 170, 172, 169, 175, 175, 183, 211, 211, 205, 186, 155, 154, 136, 114,  50,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 130, 148, 131, 139, 157, 139, 139, 151, 145, 148, 158, 183, 183, 169, 202, 211, 211, 198, 206, 211, 211, 211, 211, 208, 203, 180, 164, 160, 173, 172, 175, 193, 179, 164, 166, 158, 175, 173, 163, 166, 160, 158, 154, 183, 199, 191, 211, 211, 167, 169, 136, 115,  97,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 134, 143, 142, 149, 158, 163, 166, 145, 136, 169, 176, 157, 185, 202, 198, 201, 203, 203, 208, 191, 211, 211, 206, 199, 196, 185, 169, 164, 164, 176, 173, 163, 160, 155, 172, 178, 183, 173, 167, 169, 161, 164, 188, 188, 188, 193, 164, 154, 140, 110,  93,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 134, 143, 158, 160, 151, 158, 149, 155, 169, 169, 170, 185, 211, 192, 186, 189, 203, 192, 192, 211, 203, 192, 189, 191, 185, 186, 176, 163, 164, 164, 180, 189, 186, 170, 172, 178, 179, 176, 179, 176, 179, 164, 170, 148, 137, 128, 123, 114,  92,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 137, 137, 145, 149, 157, 164, 157, 154, 179, 169, 175, 206, 196, 208, 209, 195, 189, 185, 191, 179, 182, 180, 172, 172, 173, 176, 175, 166, 167, 176, 186, 196, 178, 179, 191, 188, 175, 166, 154, 134, 126, 146, 136, 137, 120, 100,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 125, 139, 163, 175, 166, 155, 153, 163, 176, 186, 211, 211, 211, 183, 176, 176, 183, 182, 192, 176, 169, 173, 182, 186, 179, 178, 175, 175, 167, 167, 178, 188, 199, 196, 173, 160, 148, 123, 131, 128, 115, 119, 117,  79,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  93, 126, 173, 179, 164, 153, 155, 166, 182, 208, 205, 209, 188, 180, 178, 180, 179, 193, 191, 183, 180, 182, 176, 178, 166, 169, 180, 179, 176, 172, 169, 161, 142, 128, 131, 128, 125, 130, 123, 102,  81,  55,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 117, 161, 158, 160, 164, 149, 158, 186, 196, 193, 186, 185, 185, 180, 176, 183, 180, 179, 176, 170, 166, 169, 164, 172, 185, 164, 170, 169, 146, 142, 149, 143, 140, 137, 125, 123,  97,  64,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  99, 142, 154, 160, 160, 160, 178, 183, 182, 180, 172, 182, 173, 188, 191, 169, 167, 173, 170, 158, 161, 167, 166, 161, 151, 152, 155, 131, 128, 146, 128, 128, 115,  93,  62,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 105, 119, 155, 163, 173, 186, 180, 185, 185, 183, 189, 192, 180, 179, 172, 176, 169, 160, 158, 166, 158, 155, 158, 155, 145, 142, 130, 110,  79,  77,  57,  29,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  86, 126, 152, 167, 179, 198, 211, 206, 199, 189, 191, 183, 179, 173, 169, 164, 173, 183, 166, 160, 149, 146, 151, 146, 117,  81,  50,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  86, 139, 163, 175, 186, 186, 188, 182, 166, 173, 167, 155, 169, 167, 166, 158, 146, 130, 119, 105,  82,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  41, 112, 112, 134, 154, 134, 125, 120, 117, 112,  99,  84,  62,  48,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
};

#define MOON_WIDTH  72
#define MOON_HEIGHT 72

inline static float sq(float x) { return x*x; }

// sin and cos, for floats, using sin/cos_lookup
// angle: 1.0f == π
static float sin_f(float angle) {
  return ((float) sin_lookup((int32_t) (angle*TRIG_MAX_ANGLE)))/TRIG_MAX_RATIO;
}
static float cos_f(float angle) {
  return ((float) cos_lookup((int32_t) (angle*TRIG_MAX_ANGLE)))/TRIG_MAX_RATIO;
}

// static int16_t moon_pixel(uint16_t radius, float phase, float rotation, int16_t x, int16_t y) {
//   if (x*x + y*y > radius*radius) return -1;
//   else {
//     float p = cos_f(phase);
//
//     float sr = sin_f(-rotation);
//     float cr = cos_f(-rotation);
//
//     double xr = x*cr - y*sr;
//     double yr = x*sr + y*cr;
//
//     float e = sq(xr/(p*radius)) + sq(yr/radius);
//
//     if (phase < 0.25 && (xr < 0 || e < 1)) return -1;
//     else if ((phase >= 0.25 && phase < 0.5) && (xr < 0 && e > 1)) return -1;
//     else if ((phase >= 0.5 && phase < 0.75) && (xr > 0 && e > 1)) return -1;
//     else if (phase >= 0.75 && (xr > 0 || e < 1)) return -1;
//     else {
//       int16_t xp = (int16_t) (xr*MOON_WIDTH/(radius*2)) + MOON_WIDTH/2;
//       int16_t yp = (int16_t) (yr*MOON_HEIGHT/(radius*2)) + MOON_HEIGHT/2;
//       if (xp >= 0 && xp < MOON_WIDTH && yp >= 0 && yp < MOON_HEIGHT) {
//         return MOON[yp*MOON_WIDTH + xp];
//       } else {
//         return -1;
//       }
//     }
//   }
// }

// Pre-computed values used in looking up pixels:
typedef struct {
  uint16_t r;
  uint16_t rSq;
  uint16_t regime;
  float sr;
  float cr;
  float oneOverR;
  float oneOverPR;
} RenderParams;

static void init_params(RenderParams* params, uint16_t radius, float phase, float rotation) {
  params->r = radius;
  params->rSq = radius*radius;

  if (phase < 0.25) params->regime = 0;
  else if (phase < 0.5) params->regime = 1;
  else if (phase < 0.75) params->regime = 2;
  else params->regime = 3;

  float p = cos_f(phase);
  params->sr = sin_f(-rotation);
  params->cr = cos_f(-rotation);
  params->oneOverR = 1.0f/radius;
  params->oneOverPR = 1.0/(p * radius);
}

static int16_t moon_pixel2(RenderParams* params, int16_t x, int16_t y) {
  // APP_LOG(APP_LOG_LEVEL_DEBUG, "size: %d", params->size);
  if (x*x + y*y > params->rSq) return -1;
  else {
    double xr = x*params->cr - y*params->sr;
    double yr = x*params->sr + y*params->cr;

    float e = sq(xr * params->oneOverPR) + sq(yr * params->oneOverR);

    if (params->regime == 0 && (xr < 0 || e < 1)) return -1;
    else if (params->regime == 1 && (xr < 0 && e > 1)) return -1;
    else if (params->regime == 2 && (xr > 0 && e > 1)) return -1;
    else if (params->regime == 3 && (xr > 0 || e < 1)) return -1;
    else {
      int16_t xp = (int16_t) (xr*MOON_WIDTH/(params->r * 2)) + MOON_WIDTH/2;
      int16_t yp = (int16_t) (yr*MOON_HEIGHT/(params->r * 2) + MOON_HEIGHT/2);

      if (xp >=0 && xp < MOON_WIDTH && yp >= 0 && yp < MOON_HEIGHT) {
        return MOON[yp*MOON_WIDTH + xp];
      } else {
        return -1;
      }
    }
  }
}

// Set/clear a single pixel anywhere in the bitmap, without bounds checking.
// True <=> black
static void set_pixel(const GBitmap *bitmap, uint16_t x, uint16_t y, GColor color) {
#ifdef PBL_PLATFORM_APLITE
  unsigned char* bits = bitmap->addr;
  
  uint16_t byte_num = y*(bitmap->row_size_bytes) + (x >> 3);
  uint16_t bit_num = x & 0x07;
  if (color == GColorBlack) {
    bits[byte_num] &= ~(1 << bit_num);
  }
  else {
    bits[byte_num] |= 1 << bit_num;
  }
#else
  // TODO: check bitmap format
  uint8_t *bits = gbitmap_get_data(bitmap);
  uint16_t row_size_bytes = gbitmap_get_bytes_per_row(bitmap);
  uint16_t byte_num = y*row_size_bytes + x;
  bits[byte_num] = color.argb;
#endif
}

#define BLACK        0
#define DARK_GRAY   85
#define LIGHT_GRAY 170
#define WHITE      255

#define THRESHOLD1 (BLACK + DARK_GRAY)/2
#define THRESHOLD2 (DARK_GRAY + LIGHT_GRAY)/2
#define THRESHOLD3 (LIGHT_GRAY + WHITE)/2

/*
Render the (rotated, masked) moon image into a bitmap, using Atkinson dithering.
*/
void pm_moon_render(const GBitmap* bitmap, float phase, float rotation, bool isDay) {
  // APP_LOG(APP_LOG_LEVEL_DEBUG, "Rendering moon...");

#ifdef PBL_PLATFORM_APLITE
  GRect bounds = bitmap->bounds;
#else
  GRect bounds = gbitmap_get_bounds(bitmap);
#endif
  uint16_t width = bounds.size.w;
  uint16_t height = bounds.size.h;

  RenderParams params;
  init_params(&params, width/2, phase, rotation);

  int16_t buf1[width+2];
  int16_t buf2[width+2];
  
  int16_t* nextRow = buf1;
  int16_t* secondRow = buf2;
  memset(nextRow, 0, (width+2)*sizeof(int16_t));
  
  for (uint16_t y = 0; y < height; y++) {
    // APP_LOG(APP_LOG_LEVEL_DEBUG, "  %d", y);

    int16_t err0 = nextRow[0];
    int16_t err1 = nextRow[1];
    nextRow[0] = nextRow[1] = 0;
    
    for (uint16_t x = 0; x < width; x++) {
      int16_t h = x - width/2;
      int16_t v = y - height/2;
      int16_t value = moon_pixel2(&params, h, v);
      
      if (value < 0) {
        set_pixel(bitmap, x, y, UI_BG(isDay));

        nextRow[x+2] = 0;
        secondRow[x] = 0;
      }
      else {
        // Reduce the contrast with the background a bit:
        // uint16_t clampLow = isDay ?  63 :   0;
        // uint16_t clampHi  = isDay ? 255 : 191;
        // uint16_t clampLow = 0;
        // uint16_t clampHi = 127;
        // value = value*(clampHi - clampLow)/255 + clampLow;
      
        int16_t corrected = value - err0;
      
        int16_t pix;
        GColor color;
#ifdef PBL_PLATFORM_BASALT
        if (corrected < THRESHOLD1)      { pix = BLACK;      color = GColorBlack;     }
        else if (corrected < THRESHOLD2) { pix = DARK_GRAY;  color = GColorDarkGray;  }
        else if (corrected < THRESHOLD3) { pix = LIGHT_GRAY; color = GColorLightGray; }
        else                             { pix = WHITE;      color = GColorWhite;     }
#else
        if (corrected < THRESHOLD2)      { pix = BLACK;      color = GColorBlack;     }
        else                             { pix = WHITE;      color = GColorWhite;     }
#endif
        set_pixel(bitmap, x, y, color);

        // Error in the current pixel, divided by 8:
        int16_t error = (pix - corrected) >> 3;

        int16_t err2 = nextRow[x + 2];
        nextRow[x+2] = 0;
        secondRow[x] = 0;

        // Diffuse the error to 6 neighboring pixels:
        err1 += error;
        // err1 += error*2;  // deviate from Atkinson to preserve the original contrast
        err2 += error;
        if (x > 0) nextRow[x-1] += error;
        nextRow[x] += error;
        // nextRow[x] += error*2;  // deviate from Atkinson to preserve the original contrast
        nextRow[x+1] += error;
        secondRow[x] += error;
      
        err0 = err1;
        err1 = err2;
      }
    }
    
    int16_t* tmp = nextRow;
    nextRow = secondRow;
    secondRow = tmp;
  }

  // free(params);

  APP_LOG(APP_LOG_LEVEL_DEBUG, "...done");
}