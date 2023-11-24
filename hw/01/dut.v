module dut (
    input A, B, clk,
    output reg X, Z
);
    always@(posedge clk) begin
        X <= B;
        Z <= (Z & X) | A;
    end
endmodule
