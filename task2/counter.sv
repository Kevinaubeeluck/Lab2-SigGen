module counter #(
    parameter WIDTH = 8
)(
    // Interface signals 
    input  logic             clk,    //clock
    input  logic             rst,    //reset 
    input  logic             en,     //counter enable
    output logic [WIDTH-1:0] count   //count output
    // input logic [WIDTH-1:0]   incr // Controls freq
);

always_ff @ (posedge clk, posedge rst)
    if (rst)    count <= {WIDTH{1'b0}};
    else      count <= count + {{WIDTH-1{1'b0}}, en};

endmodule 
