module singen #(
    parameter WIDTH = 8
)(
    input logic                 clk,
    input logic                 rst,
    input logic                 en,
    output logic [WIDTH-1:0]    dout1,
    output logic [WIDTH-1:0]    dout2,
    //input logic  [WIDTH-1:0]    count,
    input logic [WIDTH-1:0]     offset
    // input logic  [WIDTH-1:0]    incr // Challenge
);

logic  [WIDTH-1:0]    count;

counter Mycounter (
    .clk(clk),
    .rst(rst),
    .en(en),
    .count(count)
    //.incr(incr) //Challenge
);

dualrom Myrom(
    .clk(clk),
    .addr1(count),
    .addr2(offset + count),
    .dout1(dout1),
    .dout2(dout2)
);

endmodule
