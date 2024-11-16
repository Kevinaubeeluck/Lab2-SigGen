// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsingen.h for the primary calling header

#include "verilated.h"

#include "Vsingen__Syms.h"
#include "Vsingen___024root.h"

void Vsingen___024root___ctor_var_reset(Vsingen___024root* vlSelf);

Vsingen___024root::Vsingen___024root(Vsingen__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsingen___024root___ctor_var_reset(this);
}

void Vsingen___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vsingen___024root::~Vsingen___024root() {
}
