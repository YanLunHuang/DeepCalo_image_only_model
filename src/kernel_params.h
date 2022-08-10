#include "ap_fixed.h"
#include "defines.h"

//This parameter is used in alveo_hls4ml.cpp & host.cpp
#define IN_STREAM_LEN  (N_INPUT_1_1*N_INPUT_2_1)
#define OUT_STREAM_LEN  1

#define DATA_SIZE_IN  N_INPUT_3_1
#define DATA_SIZE_OUT  1

typedef ap_fixed<16,6> bigdata_t;

#define NW1 9216
#define NW2 18432
#define NW3 36864
#define NW4 73728
#define NW5 147456
#define NW6 294912
#define NW7 589824
#define NW8 589824
#define NW9 65536