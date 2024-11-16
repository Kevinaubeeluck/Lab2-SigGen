module singen #(
    parameter WIDTH = 8
)(
    input logic                 clk,
    input logic                 rst,
    input logic                 en,
    output logic [WIDTH-1:0]    dout,
    input logic  [WIDTH-1:0]    count,
    // input logic  [WIDTH-1:0]    incr // Challenge
);



counter Mycounter (
    .clk(clk),
    .rst(rst),
    .en(en),
    .count(count),
    //.incr(incr) //Challenge
);

rom Myrom(
    .clk(clk),
    .addr(count),
    .dout(dout)
);

endmodule
