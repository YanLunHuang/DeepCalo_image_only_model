#include "ap_fixed.h"
#include "defines.h"

//how many consecutive sets of inputs to run over per kernel execution
#define DATA_SET 5

#define IN_STREAM_LEN  (N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1)
#define OUT_STREAM_LEN  1

#define DATA_SIZE_IN  1
#define DATA_SIZE_OUT  1

typedef ap_fixed<16,6> bigdata_t;
typedef ap_ufixed<32,16,AP_RND,AP_SAT> bigdata_t2;

struct input_group{
    bigdata_t layer[4];
};