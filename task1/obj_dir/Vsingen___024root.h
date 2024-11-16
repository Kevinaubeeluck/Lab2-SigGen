// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsingen.h for the primary calling header

#ifndef VERILATED_VSINGEN___024ROOT_H_
#define VERILATED_VSINGEN___024ROOT_H_  // guard

#include "verilated.h"

class Vsingen__Syms;

class Vsingen___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(en,0,0);
    VL_OUT8(dout,7,0);
    VL_OUT8(count,7,0);
    VL_IN8(incr,7,0);
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    VlUnpacked<CData/*7:0*/, 256> singen__DOT__Myrom__DOT__rom_array;

    // INTERNAL VARIABLES
    Vsingen__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsingen___024root(Vsingen__Syms* symsp, const char* name);
    ~Vsingen___024root();
    VL_UNCOPYABLE(Vsingen___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
