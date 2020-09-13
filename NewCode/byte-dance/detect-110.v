reg input;
reg output;
// always @(posedge clk) input <=
parameter IDEL = 4'b0001, S1 = 4'b0010, S2 = 4'0100, S3 = 4'b1000;
reg current_state;
reg next_state;

always @ (posedge clk or negedge reset) begin
    if(!reset)
      current_state <= IDEL;
    else
      current_state <= next_state;
end

    always @ (*) begin
        if(!reset)
          next_state = IDEL;
        else begin
            case(current_state)
                IDLE: if(input == 1'b1) next_state = S1;
                S1: if(input == 1'b1) next_state = S2; else next_state = IDLE;
                S2: if(input == 1'b0) next_state = S3; else next_state = IDLE:
                                                                         S3: if(input == 1'b1) next_state = S1; else next_state = IDLE;
                default: next_state = IDEL;
            end
    end

    always @ (*) begin
        if(reset)
             output = 1'b0;
        else if(next_state == S3)
                  output = 1'b1;
        else
             output = 1'b0;
    end
