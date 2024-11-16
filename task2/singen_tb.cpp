#include "Vsingen.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env) {
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    Vsingen* top = new Vsingen;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("top.vcd");

    if (vbdOpen() != 1) return (-1);
    vbdHeader("Lab 2: Counter");
    vbdSetMode(1);

    top->clk = 1;
    top->rst = 1;
    top->en = 1;
    //top->count = 1;

    for (i = 0; i < 1000000; i++) {
        for (clk = 0; clk < 2; clk++) {
            tfp->dump(2 * i + clk);
            top->clk = !top->clk;
            top->eval();
        }

        top->offset = (vbdValue() * 64) / 256;
        top->rst = vbdFlag();

        vbdPlot(top->dout1,0,300);
        vbdPlot(top->dout2,0,300);

        //qtop->rst = (i < 2) | (i == 15);


        if (Verilated::gotFinish() || (vbdGetkey()== 'q')) exit(0);
    }

    vbdClose();
    tfp->close();   
    exit(0);
}