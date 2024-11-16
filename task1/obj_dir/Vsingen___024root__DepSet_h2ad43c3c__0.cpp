// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsingen.h for the primary calling header

#include "verilated.h"

#include "Vsingen___024root.h"

VL_INLINE_OPT void Vsingen___024root___sequent__TOP__0(Vsingen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsingen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsingen___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->dout = vlSelf->singen__DOT__Myrom__DOT__rom_array
        [vlSelf->count];
}

VL_INLINE_OPT void Vsingen___024root___sequent__TOP__1(Vsingen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsingen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsingen___024root___sequent__TOP__1\n"); );
    // Init
    CData/*7:0*/ __Vdly__count;
    // Body
    __Vdly__count = vlSelf->count;
    if (vlSelf->rst) {
        __Vdly__count = 0U;
    } else if (vlSelf->en) {
        __Vdly__count = (0xffU & ((IData)(vlSelf->count) 
                                  + (IData)(vlSelf->incr)));
    }
    vlSelf->count = __Vdly__count;
}

void Vsingen___024root___eval(Vsingen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsingen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsingen___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vsingen___024root___sequent__TOP__0(vlSelf);
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vsingen___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vsingen___024root___eval_debug_assertions(Vsingen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsingen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsingen___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
