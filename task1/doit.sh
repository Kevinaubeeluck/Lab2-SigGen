#!/bin/sh

# Initialise Vbuddy connection
~/Documents/iac/lab0-devtools/tools/attach_usb.sh

# cleanup
rm -rf obj_dir
rm -f counter.vcd

# run Verilator to translate Verilog into C++ including C++ testbench
verilator -Wall --cc --trace singen.sv counter.sv rom.sv --exe singen_tb.cpp

# build C++ project via make automatically generated by Verilator
make -j -C obj_dir/ -f Vsingen.mk Vsingen  # Capital 'V' in 'Vsingen.mk'

# run executable simulation file
obj_dir/Vsingen  # Capital 'V' in 'Vsingen'
