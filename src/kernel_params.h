#include "ap_fixed.h"
#include "defines.h"

//how many consecutive sets of inputs to run over per kernel execution

#define IN_STREAM_LEN  (N_INPUT_1_1*N_INPUT_2_1)
#define OUT_STREAM_LEN  1

#define DATA_SIZE_IN  N_INPUT_3_1
#define DATA_SIZE_OUT  1

typedef ap_fixed<16,9> bigdata_t;
