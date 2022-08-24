# hls4ml on Alveo U50 (HLS C/C++ Kernel)
## Vitis version 2019.2
## Compile project
```bash
make check TARGET=sw_emu DEVICE=xilinx_u50_xdma_201920_1 all  # software emulation
make check TARGET=hw_emu DEVICE=xilinx_u50_xdma_201920_1 all  # hardware emulation
make TARGET=hw DEVICE=xilinx_u50_xdma_201920_1 all # build
```
## Run project
```bash
XCL_EMULATION_MODE=sw_emu ./host ./build_dir.sw_emu.xilinx_u50_xdma_201920_1/alveo_hls4ml.xclbin  # software emulation
XCL_EMULATION_MODE=hw_emu ./host ./build_dir.hw_emu.xilinx_u50_xdma_201920_1/alveo_hls4ml.xclbin  # hardware emulation
./host alveo_hls4ml.xclbin  # run on U50
```
## Some detail
```bash
This version uses single stream & new pooling layer so that it can solve the routing congestion problem.
It also uses dense_ss to reduce the latency and save the resource utilization.
The pragma on " layer_in " all have been uncommented. 
I also modified upsampling layer & normalize layer.
I adjusted the clock period: 5 -> 4 ns.

The pooling layer is a little different, and it saved a lot of latency on 4th pooling layer.
The latency is about 0.9 ms.
```
