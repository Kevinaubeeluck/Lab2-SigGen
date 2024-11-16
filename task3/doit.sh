#!/bin/sh

# Initialise Vbuddy connection
~/Documents/iac/lab0-devtools/tools/attach_usb.sh

# cleanup
rm -rf obj_dir
rm -f counter.vcd

# run Verilator to translate Verilog into C++ including C++ testbench
verilator -Wall --cc --trace sigdelay.sv counter.sv dualram.sv --exe sigdelay_tb.cpp

# build C++ project via make automatically generated by Verilator
make -j -C obj_dir/ -f Vsigdelay.mk Vsigdelay  # Capital 'V' in 'Vsigdelay.mk'

# run executable simulation file
obj_dir/Vsigdelay  # Capital 'V' in 'Vsigdelay'

#source ./doit.sh