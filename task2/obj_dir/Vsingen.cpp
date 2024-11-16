// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsingen.h"
#include "Vsingen__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vsingen::Vsingen(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsingen__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , en{vlSymsp->TOP.en}
    , dout1{vlSymsp->TOP.dout1}
    , dout2{vlSymsp->TOP.dout2}
    , offset{vlSymsp->TOP.offset}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsingen::Vsingen(const char* _vcname__)
    : Vsingen(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsingen::~Vsingen() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vsingen___024root___eval_initial(Vsingen___024root* vlSelf);
void Vsingen___024root___eval_settle(Vsingen___024root* vlSelf);
void Vsingen___024root___eval(Vsingen___024root* vlSelf);
#ifdef VL_DEBUG
void Vsingen___024root___eval_debug_assertions(Vsingen___024root* vlSelf);
#endif  // VL_DEBUG
void Vsingen___024root___final(Vsingen___024root* vlSelf);

static void _eval_initial_loop(Vsingen__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vsingen___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vsingen___024root___eval_settle(&(vlSymsp->TOP));
        Vsingen___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vsingen::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsingen::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsingen___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vsingen___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vsingen::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vsingen::final() {
    Vsingen___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsingen::hierName() const { return vlSymsp->name(); }
const char* Vsingen::modelName() const { return "Vsingen"; }
unsigned Vsingen::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vsingen::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vsingen___024root__trace_init_top(Vsingen___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsingen___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsingen___024root*>(voidSelf);
    Vsingen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vsingen___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vsingen___024root__trace_register(Vsingen___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsingen::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vsingen___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
