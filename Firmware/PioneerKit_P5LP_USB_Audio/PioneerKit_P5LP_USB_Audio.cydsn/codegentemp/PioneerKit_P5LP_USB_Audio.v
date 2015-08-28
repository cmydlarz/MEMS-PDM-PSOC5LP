// ======================================================================
// PioneerKit_P5LP_USB_Audio.v generated from TopDesign.cysch
// 08/28/2015 at 18:40
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_PSOC4A 2
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PANTHER 3
`define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1
`define CYDEV_CHIP_REV_PANTHER_ES1 1
`define CYDEV_CHIP_REV_PANTHER_ES0 0
`define CYDEV_CHIP_DIE_PSOC5LP 4
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_EXPECT 4
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 4
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_MEMBER_4A 2
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_MEMBER_5A 3
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_5B 4
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 4
`define CYDEV_CHIP_REVISION_USED 0
// Component: I2S_v2_40
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\I2S_v2_40"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\I2S_v2_40\I2S_v2_40.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\I2S_v2_40"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\I2S_v2_40\I2S_v2_40.v"
`endif

// Component: cydff_v1_30
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30\cydff_v1_30.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cydff_v1_30\cydff_v1_30.v"
`endif

// Component: not_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`endif

// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// Component: B_AudioClkGen_v0_83
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "..\..\CyDigitalAudio.cylib\B_AudioClkGen_v0_83"
`include "..\..\CyDigitalAudio.cylib\B_AudioClkGen_v0_83\B_AudioClkGen_v0_83.v"
`else
`define CY_BLK_DIR "\\psf\Home\Desktop\USB-Audio-PSOC5LP\Firmware\PioneerKit_P5LP_USB_Audio\CyDigitalAudio.cylib\B_AudioClkGen_v0_83"
`include "\\psf\Home\Desktop\USB-Audio-PSOC5LP\Firmware\PioneerKit_P5LP_USB_Audio\CyDigitalAudio.cylib\B_AudioClkGen_v0_83\B_AudioClkGen_v0_83.v"
`endif

// AudioClkGen_v0_83(Enable_I2Sclk=true, Enable_Mclk=true, Enable_Sync=true, CY_COMPONENT_NAME=AudioClkGen_v0_83, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=AudioClkGen, CY_INSTANCE_SHORT_NAME=AudioClkGen, CY_MAJOR_VERSION=0, CY_MINOR_VERSION=83, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=AudioClkGen, )
module AudioClkGen_v0_83_0 (
    clk,
    sync,
    clkout,
    Mclk,
    I2Sclk);
    input       clk;
    input       sync;
    output      clkout;
    output      Mclk;
    output      I2Sclk;


          wire  Net_29;
          wire  Net_10;
          wire  Net_17;
          wire  Net_15;
          wire  Net_44;
          wire  Net_43;


	cy_clock_v1_0
		#(.id("6bd9c2a6-a0e0-4df8-bb96-a3ac99682977/4FEFF826-FE73-4552-BC78-338363449A6B"),
		  .source_clock_id("39D5E4C2-EBFC-44ab-AE3D-19F9BBFD674D"),
		  .divisor(4),
		  .period("0"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_SCK
		 (.clock_out(Mclk));



	cy_clock_v1_0
		#(.id("6bd9c2a6-a0e0-4df8-bb96-a3ac99682977/baf38f3a-cd74-45c7-b485-e0c519eead2a"),
		  .source_clock_id("39D5E4C2-EBFC-44ab-AE3D-19F9BBFD674D"),
		  .divisor(8),
		  .period("0"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_I2S
		 (.clock_out(I2Sclk));



    assign Net_29 = ~Net_10;


    assign clkout = ~Net_29;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_44 = sync;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_43));

    B_AudioClkGen_v0_83 UDB_ACG (
        .clk(clk),
        .sync_sof(Net_44),
        .clkout(Net_10));



endmodule

// Component: OneTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`endif

// Component: or_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`endif

// I2C_v3_30(Address_Decode=1, BusSpeed_kHz=400, ClockInputVisibility=false, CtlModeReplacementString=SyncCtl, EnableWakeup=false, ExternalBuffer=false, Externi2cIntrHandler=false, ExternTmoutIntrHandler=false, FF=true, Hex=false, I2C_Mode=2, I2cBusPort=0, Implementation=1, InternalUdbClockToleranceMinus=25, InternalUdbClockTolerancePlus=5, NotSlaveClockMinusTolerance=25, NotSlaveClockPlusTolerance=5, PrescalerEnabled=false, PrescalerPeriod=3, Psoc3ffSelected=false, Psoc5AffSelected=false, Psoc5lpffSelected=true, RemoveI2cff=false, RemoveI2cUdb=true, RemoveIntClock=true, RemoveTimeoutTimer=true, SclTimeoutEnabled=false, SdaTimeoutEnabled=false, Slave_Address=8, SlaveClockMinusTolerance=5, SlaveClockPlusTolerance=50, TimeoutEnabled=false, TimeoutImplementation=0, TimeOutms=25, TimeoutPeriodff=39999, TimeoutPeriodUdb=39999, UDB_MSTR=false, UDB_MULTI_MASTER_SLAVE=false, UDB_SLV=false, UdbInternalClock=false, UdbRequiredClock=6400, UdbSlaveFixedPlacementEnable=false, CY_COMPONENT_NAME=I2C_v3_30, CY_CONTROL_FILE=I2C_Slave_DefaultPlacement.ctl, CY_FITTER_NAME=I2C_Master, CY_INSTANCE_SHORT_NAME=I2C_Master, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=30, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=I2C_Master, )
module I2C_v3_30_1 (
    sda_o,
    scl_o,
    sda_i,
    scl_i,
    iclk,
    bclk,
    reset,
    clock,
    scl,
    sda,
    itclk);
    output      sda_o;
    output      scl_o;
    input       sda_i;
    input       scl_i;
    output      iclk;
    output      bclk;
    input       reset;
    input       clock;
    inout       scl;
    inout       sda;
    output      itclk;


          wire  sda_x_wire;
          wire  sda_yfb;
          wire  udb_clk;
          wire  Net_970;
          wire  Net_971;
          wire  Net_969;
          wire  bus_clk;
          wire  Net_968;
          wire  Net_972;
          wire  scl_yfb;
          wire  Net_973;
          wire  Net_974;
          wire  Net_975;
          wire  timeout_clk;
          wire  Net_697;
          wire  Net_1045;
          wire [1:0] Net_1109;
          wire [5:0] Net_643;
          wire  scl_x_wire;

	// Vmux_sda_out (cy_virtualmux_v1_0)
	assign sda_x_wire = Net_643[1];


	cy_isr_v1_0
		#(.int_type(2'b00))
		I2C_IRQ
		 (.int_signal(Net_697));


    cy_psoc3_i2c_v1_0 I2C_FF (
        .clock(bus_clk),
        .scl_in(Net_1109[0]),
        .sda_in(Net_1109[1]),
        .scl_out(Net_643[0]),
        .sda_out(Net_643[1]),
        .interrupt(Net_643[2]));
    defparam I2C_FF.use_wakeup = 0;

	// Vmux_interrupt (cy_virtualmux_v1_0)
	assign Net_697 = Net_643[2];

	// Vmux_scl_out (cy_virtualmux_v1_0)
	assign scl_x_wire = Net_643[0];

    OneTerminal OneTerminal_1 (
        .o(Net_969));

    OneTerminal OneTerminal_2 (
        .o(Net_968));

	// Vmux_clock (cy_virtualmux_v1_0)
	assign udb_clk = clock;


	cy_clock_v1_0
		#(.id("6f2d57bd-b6d0-4115-93da-ded3485bf4ed/5ece924d-20ba-480e-9102-bc082dcdd926"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		BusClock
		 (.clock_out(bus_clk));



    assign bclk = bus_clk | Net_973;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_973));


    assign iclk = udb_clk | Net_974;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_974));

	// Vmux_scl_in (cy_virtualmux_v1_0)
	assign Net_1109[0] = scl_yfb;

	// Vmux_sda_in (cy_virtualmux_v1_0)
	assign Net_1109[1] = sda_yfb;

	wire [0:0] tmpOE__Bufoe_scl_net;

	cy_bufoe
		Bufoe_scl
		 (.x(scl_x_wire),
		  .y(scl),
		  .oe(tmpOE__Bufoe_scl_net),
		  .yfb(scl_yfb));

	assign tmpOE__Bufoe_scl_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{Net_969} : {Net_969};

	wire [0:0] tmpOE__Bufoe_sda_net;

	cy_bufoe
		Bufoe_sda
		 (.x(sda_x_wire),
		  .y(sda),
		  .oe(tmpOE__Bufoe_sda_net),
		  .yfb(sda_yfb));

	assign tmpOE__Bufoe_sda_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{Net_968} : {Net_968};

	// Vmux_timeout_clock (cy_virtualmux_v1_0)
	assign timeout_clk = clock;


    assign itclk = timeout_clk | Net_975;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_975));


    assign scl_o = scl_x_wire;

    assign sda_o = sda_x_wire;


endmodule

// SleepTimer_v3_20(EnableInt=true, Interval=3, CY_COMPONENT_NAME=SleepTimer_v3_20, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=SystemTickTimer, CY_INSTANCE_SHORT_NAME=SystemTickTimer, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=20, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=SystemTickTimer, )
module SleepTimer_v3_20_2 (
    interrupt);
    output      interrupt;




	cy_gsref_v1_0
		#(.guid("0335EFD7-9943-4db5-B556-454A5AD8A118"))
		gsRef_1
		 (.sig_out(interrupt));




endmodule

// Component: ByteSwap_v1_10
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "..\..\Byte_Swap_Component.cylib\ByteSwap_v1_10"
`include "..\..\Byte_Swap_Component.cylib\ByteSwap_v1_10\ByteSwap_v1_10.v"
`else
`define CY_BLK_DIR "\\psf\Home\Desktop\USB-Audio-PSOC5LP\Firmware\PioneerKit_P5LP_USB_Audio\Byte_Swap_Component.cylib\ByteSwap_v1_10"
`include "\\psf\Home\Desktop\USB-Audio-PSOC5LP\Firmware\PioneerKit_P5LP_USB_Audio\Byte_Swap_Component.cylib\ByteSwap_v1_10\ByteSwap_v1_10.v"
`endif

// Component: cy_sync_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_sync_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_sync_v1_0\cy_sync_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_sync_v1_0"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_sync_v1_0\cy_sync_v1_0.v"
`endif

// DFB_v1_20(AssemblyCodeString=initialize:\r\n    acu(setmod,setmod) dmux(sa,sa) alu(set0) mac(clra)\r\n    acu(clear,clear) dmux(sa,sa) alu(hold) mac(hold) jmp(eob, WaitForInput)\r\n\r\nWaitForInput:\r\n	acu(hold,hold) dmux(sa,sa) alu(hold) mac(hold) jmpl(in1,in2,channelAStore)\r\n\r\nchannelAStore:\r\n    acu(hold,hold) dmux(sa,sa) alu(hold) mac(hold) jmpslr(eob,StoreFirstSampleA,channelBStore)\r\n\r\nchannelBStore:\r\n    acu(decr,hold) dmux(sa,sa) alu(hold) mac(hold) \r\n	acu(write,clear) addr(ChA_Fir_START) dmux(sa,sa) alu(hold) mac(hold) jmpslr(eob, StoreFirstSampleB, WaitForSecondInput)\r\n\r\nWaitForSecondInput:\r\n	acu(hold,hold) dmux(sa,sa) alu(hold) mac(hold) jmpl(in1,in2,channelACompute)\r\n	\r\nchannelACompute:\r\n	acu(decr,hold) dmux(sa,sa) alu(hold) mac(hold) \r\n	acu(write,clear) addr(ChB_Fir_START) dmux(sa,sa) alu(hold) mac(hold) jmpslr(eob, StoreFirstSampleA, ChA_Fir_fir)\r\n	\r\nchannelBCompute:\r\n	acu(hold,hold) dmux(sa,sa) alu(hold) mac(hold) jmpslr(eob, StoreFirstSampleB, ChB_Fir_fir)\r\n\r\nStoreFirstSampleA:\r\n    acu(loadm, loadm) addr(ChA_Fir_MAX) dmux(sa,sa) alu(hold) mac(hold)\r\n    acu(loadl, loadl) addr(ChA_Fir_MIN) dmux(sa,sa) alu(hold) mac(hold) \r\n    acu(hold, hold) addr(1) dmux(ba,sa) alu(hold) mac(hold) \r\n    acu(read, clear) addr(ChA_Fir_START) dmux(sra,sra) alu(setb) mac(clra) write(da) jmpret(eob)\r\n\r\nChA_Fir_fir:\r\n    acu(incr,incr) dmux(sra,srm) alu(setb) mac(macc) jmpl(eob,acubeq, ChA_Fir_firFinish)\r\n\r\nChA_Fir_firFinish:\r\n    acu(write, clear) addr(ChA_Fir_START) dmux(sa, srm) alu(setb) mac(hold)\r\n    acu(hold, hold) dmux(sa, sa) alu(hold) mac(hold)\r\n    // Move ACU to be at the correct value and write to ram.  \r\n    acu(hold, hold) addr(1) dmux(sa, sa) alu(hold) mac(hold) jmp(eob, ChA_Bq_init)\r\n\r\narea acu\r\n    ChA_Fir_MAX:   dw ChA_Fir_LAST,  ChA_Fir_LAST\r\n    ChA_Fir_MIN:   dw ChA_Fir_FIRST, ChA_Fir_FIRST\r\n    ChA_Fir_START: dw ChA_Fir_FIRST, ChA_Fir_FIRST\r\n\r\n\r\nChA_Bq_init:\r\nacu(setmod, setmod) dmux(sa, sa) alu(hold) mac(hold)\r\nacu(loadl, loadl) addr(ChA_Bq_MIN) dmux(sa, sa) alu(hold) mac(hold)\r\nacu(loadm, loadm) addr(ChA_Bq_MAX) dmux(sa, sa) alu(hold) mac(hold)\r\nacu(loadf, loadf) addr(ChA_Bq_FREG) dmux(sa, sa) alu(hold) mac(hold)\r\nacu(clear, clear)  dmux(sa, sa) alu(hold) mac(hold) jmp(eob, ChA_Bq_biquad)\r\n\r\nChA_Bq_biquad:\r\nacu(write, write) addr(TEMP) dmux(sa, sa) alu(hold) mac(hold)\r\nacu(read, read) addr(ROUND) dmux(sra, sra) alu(hold) mac(clra)\r\nacu(read, read) addr(TEMP) dmux(sa, sra) alu(hold) mac(macc)\r\nacu(incr, incr) dmux(sra, sra) alu(seta) mac(macc)\r\nacu(hold, hold) dmux(sa, sa) alu(hold) mac(hold)write(da)\r\nacu(incr, incr) dmux(sra, sra) alu(hold) mac(macc)\r\nacu(hold, hold) dmux(sa, sa) alu(hold) mac(hold)write(da)\r\nacu(incr, incr) dmux(sra, sra) alu(hold) mac(macc)\r\nacu(incr, incr) dmux(sra, sra) alu(hold) mac(macc)\r\nacu(subf, incr) dmux(srm, srm) alu(add) mac(hold) jmpl(acubeq, ChA_Bq_finish)\r\n\r\nChA_Bq_finish:\r\nacu(hold, hold) dmux(sa, sa) alu(hold) mac(hold) shift(L, 1)\r\nacu(incr, hold) addr(1) dmux(sra, sa) alu(seta) mac(hold)write(bus)\r\nacu(hold, hold) dmux(sra, sra) alu(seta) mac(hold)write(da)\r\nacu(incr, hold) dmux(sa, sa) alu(hold) mac(hold) write(da) jmp(eob, ChA_Bq_EXIT)\r\n\r\n\r\narea acu\r\n\r\nChA_Bq_MAX:  dw ChA_Bq_LAST, ChA_Bq_LAST\r\nChA_Bq_MIN:  dw ChA_Bq_FIRST, ChA_Bq_FIRST\r\nChA_Bq_FREG: dw 0x0202\r\n\r\n\r\n\r\narea data_b\r\n\r\nChA_Fir_FIRST: dw 16773779\r\ndw 16772782\r\ndw 3317\r\ndw 6925\r\ndw 16772611\r\ndw 16765084\r\ndw 6506\r\ndw 19133\r\ndw 16769036\r\ndw 16748071\r\ndw 10153\r\ndw 42370\r\ndw 16765462\r\ndw 16717071\r\ndw 13022\r\ndw 83619\r\ndw 16763950\r\ndw 16661909\r\ndw 11795\r\ndw 159210\r\ndw 16770514\r\ndw 16553131\r\ndw 16770617\r\ndw 330800\r\ndw 44095\r\ndw 16231920\r\ndw 16584373\r\ndw 1207314\r\ndw 2036228\r\ndw 1207314\r\ndw 16584373\r\ndw 16231920\r\ndw 44095\r\ndw 330800\r\ndw 16770617\r\ndw 16553131\r\ndw 16770514\r\ndw 159210\r\ndw 11795\r\ndw 16661909\r\ndw 16763950\r\ndw 83619\r\ndw 13022\r\ndw 16717071\r\ndw 16765462\r\ndw 42370\r\ndw 10153\r\ndw 16748071\r\ndw 16769036\r\ndw 19133\r\ndw 6506\r\ndw 16765084\r\ndw 16772611\r\ndw 6925\r\ndw 3317\r\ndw 16772782\r\nChA_Fir_LAST: dw 16773779\r\n\r\n\r\nChA_Bq_FIRST: dw  5113629\r\ndw 11663587\r\ndw        0\r\ndw  4186077\r\nChA_Bq_LAST: dw        0\r\n\r\nStoreFirstSampleB:\r\n    acu(loadm, loadm) addr(ChB_Fir_MAX) dmux(sa,sa) alu(hold) mac(hold)\r\n    acu(loadl, loadl) addr(ChB_Fir_MIN) dmux(sa,sa) alu(hold) mac(hold) \r\n    acu(hold, hold) addr(0) dmux(ba,sa) alu(hold) mac(hold) \r\n    acu(read, clear) addr(ChB_Fir_START) dmux(sra,sra) alu(setb) mac(clra) write(da) jmpret(eob)\r\n\r\nChB_Fir_fir:\r\n    acu(incr,incr) dmux(sra,srm) alu(setb) mac(macc) jmpl(eob,acubeq, ChB_Fir_firFinish)\r\n\r\nChB_Fir_firFinish:\r\n    acu(write, clear) addr(ChB_Fir_START) dmux(sa, srm) alu(setb) mac(hold)\r\n    acu(hold, hold) dmux(sa, sa) alu(hold) mac(hold)\r\n    // Move ACU to be at the correct value and write to ram.  \r\n    acu(hold, hold) addr(0) dmux(sa, sa) alu(hold) mac(hold) jmp(eob, ChB_Bq_init)\r\n\r\narea acu\r\n    ChB_Fir_MAX:   dw ChB_Fir_LAST,  ChB_Fir_LAST\r\n    ChB_Fir_MIN:   dw ChB_Fir_FIRST, ChB_Fir_FIRST\r\n    ChB_Fir_START: dw ChB_Fir_FIRST, ChB_Fir_FIRST\r\n\r\n\r\nChB_Bq_init:\r\nacu(setmod, setmod) dmux(sa, sa) alu(hold) mac(hold)\r\nacu(loadl, loadl) addr(ChB_Bq_MIN) dmux(sa, sa) alu(hold) mac(hold)\r\nacu(loadm, loadm) addr(ChB_Bq_MAX) dmux(sa, sa) alu(hold) mac(hold)\r\nacu(loadf, loadf) addr(ChB_Bq_FREG) dmux(sa, sa) alu(hold) mac(hold)\r\nacu(clear, clear)  dmux(sa, sa) alu(hold) mac(hold) jmp(eob, ChB_Bq_biquad)\r\n\r\nChB_Bq_biquad:\r\nacu(write, write) addr(TEMP) dmux(sa, sa) alu(hold) mac(hold)\r\nacu(read, read) addr(ROUND) dmux(sra, sra) alu(hold) mac(clra)\r\nacu(read, read) addr(TEMP) dmux(sa, sra) alu(hold) mac(macc)\r\nacu(incr, incr) dmux(sra, sra) alu(seta) mac(macc)\r\nacu(hold, hold) dmux(sa, sa) alu(hold) mac(hold)write(da)\r\nacu(incr, incr) dmux(sra, sra) alu(hold) mac(macc)\r\nacu(hold, hold) dmux(sa, sa) alu(hold) mac(hold)write(da)\r\nacu(incr, incr) dmux(sra, sra) alu(hold) mac(macc)\r\nacu(incr, incr) dmux(sra, sra) alu(hold) mac(macc)\r\nacu(subf, incr) dmux(srm, srm) alu(add) mac(hold) jmpl(acubeq, ChB_Bq_finish)\r\n\r\nChB_Bq_finish:\r\nacu(hold, hold) dmux(sa, sa) alu(hold) mac(hold) shift(L, 1)\r\nacu(incr, hold) addr(1) dmux(sra, sa) alu(seta) mac(hold)write(bus)\r\nacu(hold, hold) dmux(sra, sra) alu(seta) mac(hold)write(da)\r\nacu(incr, hold) dmux(sa, sa) alu(hold) mac(hold) write(da) jmp(eob, ChB_Bq_EXIT)\r\n\r\n\r\narea acu\r\n\r\nChB_Bq_MAX:  dw ChB_Bq_LAST, ChB_Bq_LAST\r\nChB_Bq_MIN:  dw ChB_Bq_FIRST, ChB_Bq_FIRST\r\nChB_Bq_FREG: dw 0x0202\r\n\r\narea data_b\r\n\r\nChB_Fir_FIRST: dw 16773779\r\ndw 16772782\r\ndw 3317\r\ndw 6925\r\ndw 16772611\r\ndw 16765084\r\ndw 6506\r\ndw 19133\r\ndw 16769036\r\ndw 16748071\r\ndw 10153\r\ndw 42370\r\ndw 16765462\r\ndw 16717071\r\ndw 13022\r\ndw 83619\r\ndw 16763950\r\ndw 16661909\r\ndw 11795\r\ndw 159210\r\ndw 16770514\r\ndw 16553131\r\ndw 16770617\r\ndw 330800\r\ndw 44095\r\ndw 16231920\r\ndw 16584373\r\ndw 1207314\r\ndw 2036228\r\ndw 1207314\r\ndw 16584373\r\ndw 16231920\r\ndw 44095\r\ndw 330800\r\ndw 16770617\r\ndw 16553131\r\ndw 16770514\r\ndw 159210\r\ndw 11795\r\ndw 16661909\r\ndw 16763950\r\ndw 83619\r\ndw 13022\r\ndw 16717071\r\ndw 16765462\r\ndw 42370\r\ndw 10153\r\ndw 16748071\r\ndw 16769036\r\ndw 19133\r\ndw 6506\r\ndw 16765084\r\ndw 16772611\r\ndw 6925\r\ndw 3317\r\ndw 16772782\r\nChB_Fir_LAST: dw 16773779\r\n\r\n\r\nChB_Bq_FIRST: dw  5113629\r\ndw 11663587\r\ndw        0\r\ndw  4186077\r\nChB_Bq_LAST: dw        0\r\n\r\n\r\narea acu\r\nTEMP: dw 0x7E7E\r\nROUND:dw 0x7F7F\r\n\r\narea data_a\r\norg 127\r\ndw 2048\r\n\r\narea data_b\r\norg 127\r\ndw 2048\r\n\r\nChA_Bq_EXIT = channelBCompute\r\nChB_Bq_EXIT = WaitForInput\r\n, Bus1_data=0x100000\r\n0x200000\r\n0x300000\r\n0x400000\r\n0x500000\r\n0x600000\r\n0x700000\r\n0x800000\r\n\r\n, Bus2_data=0x100000\r\n0x200000\r\n0x300000\r\n0x400000\r\n0x500000\r\n0x600000\r\n0x700000\r\n0x800000\r\n, CustomizerLayout=CYXML_v_1_0<?xml version="1.0" encoding="utf-16"?>\r\n<!--\r\n\r\n  Actipro UIStudio Dock Controls\r\n  Copyright (c) 2001-2006 Actipro Software LLC.  All rights reserved.\r\n  http://www.ActiproSoftware.com/Products/DotNet/\r\n\r\n-->\r\n<ToolWindowLayout Version="1.0">\r\n  <LayoutData>\r\n    <HostContainerControl>\r\n      <ToolWindowContainer Dock="Right" Size="209, 437" SelectedToolWindowGuid="780c93d9-70e6-4c8c-a38b-67f5bef98a6b">\r\n        <ToolWindow Key="Bus1Data" Guid="fb826cdf-3b29-4298-bb4e-f41d6f1102d7" DockedSize="205, 200" ImageIndex="-1" Text="Bus1">\r\n          <AutoHideStateInfo RootDock="Right" />\r\n          <DockedInsideHostStateInfo RootDock="Right" IsAttached="True">\r\n            <AttachedToBefore Guid="780c93d9-70e6-4c8c-a38b-67f5bef98a6b" />\r\n            <AttachedToBefore Guid="00647fda-6101-4571-8181-36ab1fe2ff39" />\r\n            <DockedBy Guid="0bf5e9cb-d108-449a-85fe-d465f811b2b8" RootDock="Bottom" DockOperationType="TopOuter" IsTopMost="True" />\r\n            <DockedBy Guid="0b51483c-0ac1-4a05-b7cd-1eb3cc0efd5b" RootDock="Bottom" DockOperationType="TopOuter" IsTopMost="True" />\r\n          </DockedInsideHostStateInfo>\r\n          <DockedOutsideHostStateInfo IsAttached="False" />\r\n        </ToolWindow>\r\n        <ToolWindow Key="Bus2Data" Guid="780c93d9-70e6-4c8c-a38b-67f5bef98a6b" DockedSize="205, 200" ImageIndex="-1" Text="Bus2">\r\n          <AutoHideStateInfo RootDock="Right" />\r\n          <DockedInsideHostStateInfo RootDock="Right" IsAttached="True">\r\n            <AttachedToBefore Guid="00647fda-6101-4571-8181-36ab1fe2ff39" />\r\n            <AttachedToAfter Guid="fb826cdf-3b29-4298-bb4e-f41d6f1102d7" />\r\n            <DockedBy Guid="0bf5e9cb-d108-449a-85fe-d465f811b2b8" RootDock="Bottom" DockOperationType="TopOuter" IsTopMost="True" />\r\n            <DockedBy Guid="0b51483c-0ac1-4a05-b7cd-1eb3cc0efd5b" RootDock="Bottom" DockOperationType="TopOuter" IsTopMost="True" />\r\n          </DockedInsideHostStateInfo>\r\n          <DockedOutsideHostStateInfo IsAttached="False" />\r\n        </ToolWindow>\r\n        <ToolWindow Key="SimulationProperties" Guid="00647fda-6101-4571-8181-36ab1fe2ff39" DockedSize="205, 200" ImageIndex="-1" Text="Simulation Properties">\r\n          <AutoHideStateInfo RootDock="Right" />\r\n          <DockedInsideHostStateInfo RootDock="Right" IsAttached="True">\r\n            <AttachedToAfter Guid="fb826cdf-3b29-4298-bb4e-f41d6f1102d7" />\r\n            <AttachedToAfter Guid="780c93d9-70e6-4c8c-a38b-67f5bef98a6b" />\r\n            <DockedBy Guid="0bf5e9cb-d108-449a-85fe-d465f811b2b8" RootDock="Bottom" DockOperationType="TopOuter" IsTopMost="True" />\r\n            <DockedBy Guid="0b51483c-0ac1-4a05-b7cd-1eb3cc0efd5b" RootDock="Bottom" DockOperationType="TopOuter" IsTopMost="True" />\r\n          </DockedInsideHostStateInfo>\r\n          <DockedOutsideHostStateInfo IsAttached="False" />\r\n        </ToolWindow>\r\n      </ToolWindowContainer>\r\n      <ToolWindowContainer Dock="Bottom" Size="1107, 170" SelectedToolWindowGuid="0bf5e9cb-d108-449a-85fe-d465f811b2b8">\r\n        <ToolWindow Key="Output" Guid="0bf5e9cb-d108-449a-85fe-d465f811b2b8" DockedSize="200, 166" ImageIndex="-1" Text="Output">\r\n          <AutoHideStateInfo RootDock="Bottom" />\r\n          <DockedInsideHostStateInfo RootDock="Bottom" IsAttached="True">\r\n            <AttachedToBefore Guid="0b51483c-0ac1-4a05-b7cd-1eb3cc0efd5b" />\r\n          </DockedInsideHostStateInfo>\r\n          <DockedOutsideHostStateInfo IsAttached="False" />\r\n        </ToolWindow>\r\n        <ToolWindow Key="ErrorList" Guid="0b51483c-0ac1-4a05-b7cd-1eb3cc0efd5b" DockedSize="200, 166" ImageIndex="-1" Text="Error List: 0 Errors    0 Warnings    0 Notes">\r\n          <AutoHideStateInfo RootDock="Bottom" />\r\n          <DockedInsideHostStateInfo RootDock="Bottom" IsAttached="True">\r\n            <AttachedToAfter Guid="0bf5e9cb-d108-449a-85fe-d465f811b2b8" />\r\n          </DockedInsideHostStateInfo>\r\n          <DockedOutsideHostStateInfo IsAttached="False" />\r\n        </ToolWindow>\r\n      </ToolWindowContainer>\r\n    </HostContainerControl>\r\n    <AutoHide Dock="Left" />\r\n    <AutoHide Dock="Right" />\r\n    <AutoHide Dock="Top" />\r\n    <AutoHide Dock="Bottom" />\r\n    <TabbedDocuments Orientation="Horizontal" />\r\n    <FloatingContainers />\r\n    <Hidden />\r\n  </LayoutData>\r\n  <CustomData />\r\n</ToolWindowLayout>, InitialDMAMode=1, InitialInterruptMode=0, InitialOutput1Source=0, InitialOutput2Source=0, OptimizeAssembly=false, ShowDMA1=true, ShowDMA2=false, ShowIn1=false, ShowIn2=false, ShowOut1=false, ShowOut2=false, CY_COMPONENT_NAME=DFB_v1_20, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=Droop_Filter, CY_INSTANCE_SHORT_NAME=Droop_Filter, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=20, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=Droop_Filter, )
module DFB_v1_20_3 (
    out_2,
    out_1,
    in_2,
    in_1,
    interrupt,
    dma_req_a,
    dma_req_b);
    output      out_2;
    output      out_1;
    input       in_2;
    input       in_1;
    output      interrupt;
    output      dma_req_a;
    output      dma_req_b;


          wire  Net_38;

    cy_psoc3_dfb_v1_0 DFB (
        .in_1(in_1),
        .out_1(out_1),
        .out_2(out_2),
        .interrupt(interrupt),
        .in_2(in_2),
        .clock(Net_38),
        .dmareq_1(dma_req_a),
        .dmareq_2(dma_req_b));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_38));



endmodule

// Component: LUT_v1_50
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\LUT_v1_50"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\LUT_v1_50\LUT_v1_50.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\LUT_v1_50"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\LUT_v1_50\LUT_v1_50.v"
`endif

// Component: PDM_Integrator_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "..\PDM_Integrator_v1_0"
`include "..\PDM_Integrator_v1_0\PDM_Integrator_v1_0.v"
`else
`define CY_BLK_DIR "\\psf\Home\Desktop\USB-Audio-PSOC5LP\Firmware\PioneerKit_P5LP_USB_Audio\PioneerKit_P5LP_USB_Audio.cydsn\PDM_Integrator_v1_0"
`include "\\psf\Home\Desktop\USB-Audio-PSOC5LP\Firmware\PioneerKit_P5LP_USB_Audio\PioneerKit_P5LP_USB_Audio.cydsn\PDM_Integrator_v1_0\PDM_Integrator_v1_0.v"
`endif

// Component: PDM_Comb_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "..\PDM_Comb_v1_0"
`include "..\PDM_Comb_v1_0\PDM_Comb_v1_0.v"
`else
`define CY_BLK_DIR "\\psf\Home\Desktop\USB-Audio-PSOC5LP\Firmware\PioneerKit_P5LP_USB_Audio\PioneerKit_P5LP_USB_Audio.cydsn\PDM_Comb_v1_0"
`include "\\psf\Home\Desktop\USB-Audio-PSOC5LP\Firmware\PioneerKit_P5LP_USB_Audio\PioneerKit_P5LP_USB_Audio.cydsn\PDM_Comb_v1_0\PDM_Comb_v1_0.v"
`endif

// Component: CyControlReg_v1_70
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_70"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_70\CyControlReg_v1_70.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_70"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_70\CyControlReg_v1_70.v"
`endif

// Component: CyStatusReg_v1_80
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_80"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_80\CyStatusReg_v1_80.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_80"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_80\CyStatusReg_v1_80.v"
`endif

// Component: cy_constant_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`endif

// Component: PulseConvert_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\PulseConvert_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\PulseConvert_v1_0\PulseConvert_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\PulseConvert_v1_0"
`include "C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\PulseConvert_v1_0\PulseConvert_v1_0.v"
`endif

// PDM_CIC_v2_0(ClockingFactor=0, ConfigureCombClock=false, DebugMode=false, DecimationRate=32, InterruptOnFifoOverflow=true, Left_Remove=false, MicrophoneChannel=2, ShiftCount=3, ShiftDirection=0, CY_COMPONENT_NAME=PDM_CIC_v2_0, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=PDM_CIC, CY_INSTANCE_SHORT_NAME=PDM_CIC, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=PDM_CIC, )
module PDM_CIC_v2_0_4 (
    clk_comb,
    pdm_data,
    bus_clk,
    clk_int,
    pdm_clk,
    data_ready_l,
    interrupt_ov,
    data_ready_r,
    dbg_enable);
    input       clk_comb;
    input       pdm_data;
    input       bus_clk;
    input       clk_int;
    output      pdm_clk;
    output      data_ready_l;
    output      interrupt_ov;
    output      data_ready_r;
    output      dbg_enable;

    parameter ClockingFactor = 0;
    parameter ConfigureCombClock = 0;
    parameter DecimationRate = 32;
    parameter InterruptOnFifoOverflow = 1;
    parameter Left_Remove = 0;
    parameter MicrophoneChannel = 2;
    parameter ShiftCount = 3;
    parameter ShiftDirection = 0;

          wire  Net_2931;
          wire  Net_2932;
          wire  wire_idle_l;
          wire  Net_2933;
          wire  Net_2934;
          wire  Net_2935;
          wire  Net_2936;
          wire  Net_2937;
          wire  Net_2938;
          wire  Net_2939;
          wire  Net_3099;
          wire  wire_idle_r;
          wire  Net_3100;
          wire  Net_3101;
          wire  Net_3102;
          wire  wire_int_clk;
          wire  Net_3103;
          wire  Net_3104;
          wire  Net_3105;
          wire  Net_3106;
          wire  Net_3088;
          wire  Net_3089;
          wire  Net_3090;
          wire  Net_3091;
          wire  Net_3092;
          wire  Net_3093;
          wire  wire_bus_clk;
          wire  Net_3094;
          wire  Net_3095;
          wire  Net_3096;
          wire  Net_2957;
          wire  Net_2958;
          wire  Net_2959;
          wire  Net_2960;
          wire  Net_2961;
          wire  Net_2962;
          wire  wire_comb_ov_l;
          wire  Net_2963;
          wire  Net_2964;
          wire  Net_2965;
          wire  Net_2966;
          wire  Net_2967;
          wire  Net_2968;
          wire  Net_2969;
          wire  Net_2970;
          wire [7:0] Net_2971;
          wire  Net_3097;
          wire  Net_3098;
          wire  Net_2974;
          wire  Net_2975;
          wire  Net_3007;
          wire  Net_3010;
          wire  Net_2567;
          wire  Net_2669;
          wire  Net_2664;
          wire  Net_2665;
          wire  Net_2666;
          wire  wire_int_en;
          wire  Net_2680;
          wire  Net_2670;
          wire  wire_comb_en;
          wire  Net_2651;
          wire  wire_comb_clk;
          wire  Net_2654;
          wire  Net_2625;
          wire  Net_2548;
          wire  Net_2537;
          wire  Net_2583;
          wire  Net_2608;
          wire  Net_2386;
          wire  Net_2385;
          wire  Net_2384;
          wire  wire_comb_ov_r;
          wire  Net_2383;
          wire  Net_2175;
          wire  wire_int_ready_r;
          wire  wire_int_ready_l;

    // -- LUT LUT_DmaThrottle_R start --
    if (1)
    begin : LUT_DmaThrottle_R
        reg [0:0] tmp__LUT_DmaThrottle_R_reg;
        wire [2:0] tmp__LUT_DmaThrottle_R_ins;
        assign tmp__LUT_DmaThrottle_R_ins = {Net_2670,wire_idle_r,wire_int_ready_r};
        always @(posedge wire_bus_clk)
        begin
            case (tmp__LUT_DmaThrottle_R_ins)
                3'b000 :  tmp__LUT_DmaThrottle_R_reg = 1'b0;
                3'b001 :  tmp__LUT_DmaThrottle_R_reg = 1'b0;
                3'b010 :  tmp__LUT_DmaThrottle_R_reg = 1'b0;
                3'b011 :  tmp__LUT_DmaThrottle_R_reg = 1'b1;
                3'b100 :  tmp__LUT_DmaThrottle_R_reg = 1'b0;
                3'b101 :  tmp__LUT_DmaThrottle_R_reg = 1'b0;
                3'b110 :  tmp__LUT_DmaThrottle_R_reg = 1'b1;
                3'b111 :  tmp__LUT_DmaThrottle_R_reg = 1'b1;
            endcase
        end
        assign {Net_2670} = tmp__LUT_DmaThrottle_R_reg;
    end
    // -- LUT LUT_DmaThrottle_R end --

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign wire_comb_clk = wire_int_clk;

    PDM_Integrator_v1_0 Integrator (
        .pdm_data(pdm_data),
        .enable(wire_int_en),
        .clock(wire_int_clk),
        .pdm_clk(pdm_clk),
        .data_ready_l(wire_int_ready_l),
        .fifo_ov_l(Net_3007),
        .data_ready_r(wire_int_ready_r),
        .fifo_ov_r(Net_3010));
    defparam Integrator.ClockingFactor = 0;
    defparam Integrator.DecimationRate = 32;
    defparam Integrator.MicrophoneChannel = 2;

    PDM_Comb_v1_0 Comb_R (
        .input_avail(Net_2664),
        .enable(wire_comb_en),
        .clock(wire_comb_clk),
        .data_ready(data_ready_r),
        .fifo_ov(wire_comb_ov_r),
        .d0_done(Net_2665),
        .d0_update(Net_2666),
        .idle_sts(wire_idle_r));
    defparam Comb_R.ApplyNoShift = 0;
    defparam Comb_R.ShiftCount = 3;
    defparam Comb_R.ShiftDirection = 0;

    // -- LUT LUT_DmaThrottle_L start --
    if (1)
    begin : LUT_DmaThrottle_L
        reg [0:0] tmp__LUT_DmaThrottle_L_reg;
        wire [2:0] tmp__LUT_DmaThrottle_L_ins;
        assign tmp__LUT_DmaThrottle_L_ins = {Net_2583,wire_idle_l,wire_int_ready_l};
        always @(posedge wire_bus_clk)
        begin
            case (tmp__LUT_DmaThrottle_L_ins)
                3'b000 :  tmp__LUT_DmaThrottle_L_reg = 1'b0;
                3'b001 :  tmp__LUT_DmaThrottle_L_reg = 1'b0;
                3'b010 :  tmp__LUT_DmaThrottle_L_reg = 1'b0;
                3'b011 :  tmp__LUT_DmaThrottle_L_reg = 1'b1;
                3'b100 :  tmp__LUT_DmaThrottle_L_reg = 1'b0;
                3'b101 :  tmp__LUT_DmaThrottle_L_reg = 1'b0;
                3'b110 :  tmp__LUT_DmaThrottle_L_reg = 1'b1;
                3'b111 :  tmp__LUT_DmaThrottle_L_reg = 1'b1;
            endcase
        end
        assign {Net_2583} = tmp__LUT_DmaThrottle_L_reg;
    end
    // -- LUT LUT_DmaThrottle_L end --


	cy_dma_v1_0
		#(.drq_type(2'b00))
		DMA_CombD0Update_R
		 (.drq(Net_2666),
		  .trq(1'b0),
		  .nrq(Net_2669));



	cy_dma_v1_0
		#(.drq_type(2'b00))
		DMA_CombD0Update_L
		 (.drq(Net_2537),
		  .trq(1'b0),
		  .nrq(Net_2651));


	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign wire_comb_en = wire_int_en;

    CyControlReg_v1_70 Int_Ctrl_Reg (
        .control_1(Net_2959),
        .control_2(Net_2960),
        .control_3(Net_2961),
        .control_0(wire_int_en),
        .control_4(Net_2962),
        .control_5(Net_2963),
        .control_6(Net_2964),
        .control_7(Net_2965),
        .clock(wire_int_clk),
        .reset(1'b0));
    defparam Int_Ctrl_Reg.Bit0Mode = 1;
    defparam Int_Ctrl_Reg.Bit1Mode = 1;
    defparam Int_Ctrl_Reg.Bit2Mode = 0;
    defparam Int_Ctrl_Reg.Bit3Mode = 0;
    defparam Int_Ctrl_Reg.Bit4Mode = 0;
    defparam Int_Ctrl_Reg.Bit5Mode = 0;
    defparam Int_Ctrl_Reg.Bit6Mode = 0;
    defparam Int_Ctrl_Reg.Bit7Mode = 0;
    defparam Int_Ctrl_Reg.BitValue = 0;
    defparam Int_Ctrl_Reg.BusDisplay = 0;
    defparam Int_Ctrl_Reg.ExtrReset = 1;
    defparam Int_Ctrl_Reg.NumOutputs = 1;

    PDM_Comb_v1_0 Comb_L (
        .input_avail(Net_2548),
        .enable(wire_comb_en),
        .clock(wire_comb_clk),
        .data_ready(data_ready_l),
        .fifo_ov(wire_comb_ov_l),
        .d0_done(Net_2654),
        .d0_update(Net_2537),
        .idle_sts(wire_idle_l));
    defparam Comb_L.ApplyNoShift = 0;
    defparam Comb_L.ShiftCount = 3;
    defparam Comb_L.ShiftDirection = 0;

    CyStatusReg_v1_80 Status_Reg (
        .status_0(Net_2383),
        .status_1(Net_2384),
        .status_2(Net_2385),
        .status_3(Net_2386),
        .clock(wire_bus_clk),
        .status_4(1'b0),
        .status_5(1'b0),
        .status_6(1'b0),
        .status_7(1'b0),
        .intr(interrupt_ov),
        .status_bus(8'b0));
    defparam Status_Reg.Bit0Mode = 1;
    defparam Status_Reg.Bit1Mode = 1;
    defparam Status_Reg.Bit2Mode = 1;
    defparam Status_Reg.Bit3Mode = 1;
    defparam Status_Reg.Bit4Mode = 0;
    defparam Status_Reg.Bit5Mode = 0;
    defparam Status_Reg.Bit6Mode = 0;
    defparam Status_Reg.Bit7Mode = 0;
    defparam Status_Reg.BusDisplay = 0;
    defparam Status_Reg.Interrupt = 1;
    defparam Status_Reg.MaskValue = 15;
    defparam Status_Reg.NumInputs = 4;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign Net_2383 = Net_3007;

	// VirtualMux_4 (cy_virtualmux_v1_0)
	assign Net_2384 = Net_3010;

	// VirtualMux_5 (cy_virtualmux_v1_0)
	assign Net_2385 = wire_comb_ov_l;

	// VirtualMux_6 (cy_virtualmux_v1_0)
	assign Net_2386 = wire_comb_ov_r;

    assign Net_3097 = 1'h0;

    assign Net_3098 = 1'h0;

    assign Net_2608 = 1'h0;

    assign Net_2567 = 1'h0;

    PulseConvert_v1_0 PulseConvert_IntDmaNrq_L (
        .p_in(Net_2625),
        .p_out(Net_2548),
        .sample_clk(wire_bus_clk),
        .out_clk(wire_comb_clk));

    PulseConvert_v1_0 PulseConvert_D0DmaNrq_L (
        .p_in(Net_2651),
        .p_out(Net_2654),
        .sample_clk(wire_bus_clk),
        .out_clk(wire_comb_clk));


	cy_dma_v1_0
		#(.drq_type(2'b00))
		DMA_IntOut_L
		 (.drq(Net_2583),
		  .trq(1'b0),
		  .nrq(Net_2625));


    PulseConvert_v1_0 PulseConvert_IntDmaNrq_R (
        .p_in(Net_2680),
        .p_out(Net_2664),
        .sample_clk(wire_bus_clk),
        .out_clk(wire_comb_clk));


	cy_dma_v1_0
		#(.drq_type(2'b00))
		DMA_IntOut_R
		 (.drq(Net_2670),
		  .trq(1'b0),
		  .nrq(Net_2680));


    PulseConvert_v1_0 PulseConvert_D0DmaNrq_R (
        .p_in(Net_2669),
        .p_out(Net_2665),
        .sample_clk(wire_bus_clk),
        .out_clk(wire_comb_clk));


    assign wire_int_clk = clk_int;

    assign wire_bus_clk = bus_clk;

    assign dbg_enable = wire_int_en;


endmodule

// USBFS_v2_50(AudioDescriptors=<?xml version="1.0" encoding="utf-16"?> <Tree xmlns:CustomizerVersion="2_50">   <Tree_x0020_Descriptors>     <DescriptorNode Key="Audio">       <Nodes>         <DescriptorNode Key="Interface1630">           <Value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>ALTERNATE</bDescriptorType>             <bLength>0</bLength>             <DisplayName>MacPCAudioControlOutInWithIntStat</DisplayName>           </Value>           <Nodes>             <DescriptorNode Key="USBDescriptor1631">               <Value d8p1:type="CyAudioInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">                 <bDescriptorType>INTERFACE</bDescriptorType>                 <bLength>9</bLength>                 <iwInterface>1858</iwInterface>                 <bInterfaceClass>1</bInterfaceClass>                 <bNumEndpoints>1</bNumEndpoints>                 <bInterfaceSubClass>1</bInterfaceSubClass>                 <bInterfaceProtocol>0</bInterfaceProtocol>                 <iInterface>12</iInterface>                 <sInterface>Cypress Digital Audio DVK</sInterface>               </Value>               <Nodes>                 <DescriptorNode Key="USBDescriptor1633">                   <Value d10p1:type="CyACHeaderDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">                     <bDescriptorType>AUDIO</bDescriptorType>                     <bLength>9</bLength>                     <bDescriptorSubtype>HEADER</bDescriptorSubtype>                     <bcdADC>256</bcdADC>                     <wTotalLength>30</wTotalLength>                     <bInCollection>1</bInCollection>                     <baInterfaceNr>AQ==</baInterfaceNr>                   </Value>                   <Nodes />                 </DescriptorNode>                 <DescriptorNode Key="USBDescriptor1637">                   <Value d10p1:type="CyACInputTerminalDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">                     <bDescriptorType>AUDIO</bDescriptorType>                     <bLength>12</bLength>                     <iwChannelNames>0</iwChannelNames>                     <iwTerminal>50</iwTerminal>                     <bDescriptorSubtype>INPUT_TERMINAL</bDescriptorSubtype>                     <bTerminalID>4</bTerminalID>                     <wTerminalType>513</wTerminalType>                     <bNrChannels>2</bNrChannels>                     <wChannelConfig>3</wChannelConfig>                     <iChannelNames>0</iChannelNames>                     <iTerminal>4</iTerminal>                     <sTerminal>Microphone</sTerminal>                   </Value>                   <Nodes />                 </DescriptorNode>                 <DescriptorNode Key="USBDescriptor1638">                   <Value d10p1:type="CyACOutputTerminalDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">                     <bDescriptorType>AUDIO</bDescriptorType>                     <bLength>9</bLength>                     <iwTerminal>52</iwTerminal>                     <bDescriptorSubtype>OUTPUT_TERMINAL</bDescriptorSubtype>                     <bTerminalID>5</bTerminalID>                     <wTerminalType>257</wTerminalType>                     <bSourceID>4</bSourceID>                     <iTerminal>6</iTerminal>                     <sTerminal>USB Streaming</sTerminal>                   </Value>                   <Nodes />                 </DescriptorNode>                 <DescriptorNode Key="USBDescriptor1639">                   <Value d10p1:type="CyAudioEndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">                     <bDescriptorType>ENDPOINT</bDescriptorType>                     <bLength>9</bLength>                     <DoubleBuffer>false</DoubleBuffer>                     <bInterval>30</bInterval>                     <bEndpointAddress>134</bEndpointAddress>                     <bmAttributes>3</bmAttributes>                     <wMaxPacketSize>2</wMaxPacketSize>                   </Value>                   <Nodes />                 </DescriptorNode>               </Nodes>             </DescriptorNode>           </Nodes>         </DescriptorNode>         <DescriptorNode Key="Interface1661">           <Value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>ALTERNATE</bDescriptorType>             <bLength>0</bLength>             <DisplayName>MacPCAudioStreamingIn</DisplayName>           </Value>           <Nodes>             <DescriptorNode Key="USBDescriptor1662">               <Value d8p1:type="CyAudioInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">                 <bDescriptorType>INTERFACE</bDescriptorType>                 <bLength>9</bLength>                 <iwInterface>1858</iwInterface>                 <bInterfaceClass>1</bInterfaceClass>                 <bInterfaceNumber>1</bInterfaceNumber>                 <bNumEndpoints>0</bNumEndpoints>                 <bInterfaceSubClass>2</bInterfaceSubClass>                 <bInterfaceProtocol>0</bInterfaceProtocol>                 <iInterface>12</iInterface>                 <sInterface>Cypress Digital Audio DVK</sInterface>               </Value>               <Nodes />             </DescriptorNode>             <DescriptorNode Key="USBDescriptor1667">               <Value d8p1:type="CyAudioInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">                 <bDescriptorType>INTERFACE</bDescriptorType>                 <bLength>9</bLength>                 <iwInterface>947</iwInterface>                 <bInterfaceClass>1</bInterfaceClass>                 <bAlternateSetting>1</bAlternateSetting>                 <bInterfaceNumber>1</bInterfaceNumber>                 <bNumEndpoints>1</bNumEndpoints>                 <bInterfaceSubClass>2</bInterfaceSubClass>                 <bInterfaceProtocol>0</bInterfaceProtocol>                 <iInterface>8</iInterface>                 <sInterface>Active 16 bit</sInterface>               </Value>               <Nodes>                 <DescriptorNode Key="USBDescriptor1669">                   <Value d10p1:type="CyASGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">                     <bDescriptorType>AUDIO</bDescriptorType>                     <bLength>7</bLength>                     <bDescriptorSubtype>AS_GENERAL</bDescriptorSubtype>                     <bTerminalLink>5</bTerminalLink>                     <bDelay>1</bDelay>                     <wFormatTag>1</wFormatTag>                   </Value>                   <Nodes />                 </DescriptorNode>                 <DescriptorNode Key="USBDescriptor1670">                   <Value d10p1:type="CyASFormatType1Descriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">                     <bDescriptorType>AUDIO</bDescriptorType>                     <bLength>14</bLength>                     <bDescriptorSubtype>FORMAT_TYPE</bDescriptorSubtype>                     <bFormatType>FORMAT_TYPE_1</bFormatType>                     <bSamFreqType>2</bSamFreqType>                     <tSamFreq>                       <unsignedInt>44100</unsignedInt>                       <unsignedInt>48000</unsignedInt>                     </tSamFreq>                     <bNrChannels>2</bNrChannels>                     <bSubframeSize>2</bSubframeSize>                     <bBitResolution>16</bBitResolution>                   </Value>                   <Nodes />                 </DescriptorNode>                 <DescriptorNode Key="USBDescriptor1671">                   <Value d10p1:type="CyAudioEndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">                     <bDescriptorType>ENDPOINT</bDescriptorType>                     <bLength>9</bLength>                     <DoubleBuffer>false</DoubleBuffer>                     <bInterval>1</bInterval>                     <bEndpointAddress>130</bEndpointAddress>                     <bmAttributes>13</bmAttributes>                     <wMaxPacketSize>192</wMaxPacketSize>                   </Value>                   <Nodes>                     <DescriptorNode Key="USBDescriptor1672">                       <Value d12p1:type="CyASEndpointDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">                         <bDescriptorType>CS_ENDPOINT</bDescriptorType>                         <bLength>7</bLength>                         <bDescriptorSubtype>EP_GENERAL</bDescriptorSubtype>                         <bmAttributes>1</bmAttributes>                         <bLockDelayUnits>1</bLockDelayUnits>                         <wLockDelay>1</wLockDelay>                       </Value>                       <Nodes />                     </DescriptorNode>                   </Nodes>                 </DescriptorNode>               </Nodes>             </DescriptorNode>           </Nodes>         </DescriptorNode>       </Nodes>     </DescriptorNode>   </Tree_x0020_Descriptors> </Tree>, CDCDescriptors=<?xml version="1.0" encoding="utf-16"?> <Tree xmlns:CustomizerVersion="2_50">   <Tree_x0020_Descriptors>     <DescriptorNode Key="CDC">       <Nodes />     </DescriptorNode>   </Tree_x0020_Descriptors> </Tree>, DeviceDescriptors=<?xml version="1.0" encoding="utf-16"?> <Tree xmlns:CustomizerVersion="2_50">   <Tree_x0020_Descriptors>     <DescriptorNode Key="Device">       <Nodes>         <DescriptorNode Key="USBDescriptor1735">           <Value d6p1:type="DeviceDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>DEVICE</bDescriptorType>             <bLength>18</bLength>             <iwManufacturer>7</iwManufacturer>             <iwProduct>1858</iwProduct>             <sManufacturer>Cypress Semiconductor</sManufacturer>             <sProduct>Cypress Digital Audio DVK</sProduct>             <bDeviceClass>0</bDeviceClass>             <bDeviceSubClass>0</bDeviceSubClass>             <bDeviceProtocol>0</bDeviceProtocol>             <bMaxPacketSize0>0</bMaxPacketSize0>             <idVendor>1204</idVendor>             <idProduct>50432</idProduct>             <bcdDevice>4096</bcdDevice>             <iManufacturer>1</iManufacturer>             <iProduct>12</iProduct>             <iSerialNumber>0</iSerialNumber>             <bNumConfigurations>1</bNumConfigurations>             <bMemoryMgmt>0</bMemoryMgmt>             <bMemoryAlloc>0</bMemoryAlloc>           </Value>           <Nodes>             <DescriptorNode Key="USBDescriptor1736">               <Value d8p1:type="ConfigDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">                 <bDescriptorType>CONFIGURATION</bDescriptorType>                 <bLength>9</bLength>                 <iwConfiguration>1740</iwConfiguration>                 <sConfiguration>Mac</sConfiguration>                 <wTotalLength>137</wTotalLength>                 <bNumInterfaces>3</bNumInterfaces>                 <bConfigurationValue>0</bConfigurationValue>                 <iConfiguration>10</iConfiguration>                 <bmAttributes>128</bmAttributes>                 <bMaxPower>50</bMaxPower>               </Value>               <Nodes>                 <DescriptorNode Key="Interface1630">                   <Value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">                     <bDescriptorType>ALTERNATE</bDescriptorType>                     <bLength>0</bLength>                     <DisplayName>MacPCAudioControlOutInWithIntStat</DisplayName>                   </Value>                   <Nodes>                     <DescriptorNode Key="USBDescriptor1631">                       <Value d12p1:type="CyAudioInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">                         <bDescriptorType>INTERFACE</bDescriptorType>                         <bLength>9</bLength>                         <iwInterface>1858</iwInterface>                         <bInterfaceClass>1</bInterfaceClass>                         <bNumEndpoints>1</bNumEndpoints>                         <bInterfaceSubClass>1</bInterfaceSubClass>                         <bInterfaceProtocol>0</bInterfaceProtocol>                         <iInterface>12</iInterface>                         <sInterface>Cypress Digital Audio DVK</sInterface>                       </Value>                       <Nodes>                         <DescriptorNode Key="USBDescriptor1633">                           <Value d14p1:type="CyACHeaderDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">                             <bDescriptorType>AUDIO</bDescriptorType>                             <bLength>9</bLength>                             <bDescriptorSubtype>HEADER</bDescriptorSubtype>                             <bcdADC>256</bcdADC>                             <wTotalLength>30</wTotalLength>                             <bInCollection>1</bInCollection>                             <baInterfaceNr>AQ==</baInterfaceNr>                           </Value>                           <Nodes />                         </DescriptorNode>                         <DescriptorNode Key="USBDescriptor1637">                           <Value d14p1:type="CyACInputTerminalDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">                             <bDescriptorType>AUDIO</bDescriptorType>                             <bLength>12</bLength>                             <iwChannelNames>0</iwChannelNames>                             <iwTerminal>50</iwTerminal>                             <bDescriptorSubtype>INPUT_TERMINAL</bDescriptorSubtype>                             <bTerminalID>4</bTerminalID>                             <wTerminalType>513</wTerminalType>                             <bNrChannels>2</bNrChannels>                             <wChannelConfig>3</wChannelConfig>                             <iChannelNames>0</iChannelNames>                             <iTerminal>4</iTerminal>                             <sTerminal>Microphone</sTerminal>                           </Value>                           <Nodes />                         </DescriptorNode>                         <DescriptorNode Key="USBDescriptor1638">                           <Value d14p1:type="CyACOutputTerminalDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">                             <bDescriptorType>AUDIO</bDescriptorType>                             <bLength>9</bLength>                             <iwTerminal>52</iwTerminal>                             <bDescriptorSubtype>OUTPUT_TERMINAL</bDescriptorSubtype>                             <bTerminalID>5</bTerminalID>                             <wTerminalType>257</wTerminalType>                             <bSourceID>4</bSourceID>                             <iTerminal>6</iTerminal>                             <sTerminal>USB Streaming</sTerminal>                           </Value>                           <Nodes />                         </DescriptorNode>                         <DescriptorNode Key="USBDescriptor1639">                           <Value d14p1:type="CyAudioEndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">                             <bDescriptorType>ENDPOINT</bDescriptorType>                             <bLength>9</bLength>                             <DoubleBuffer>false</DoubleBuffer>                             <bInterval>30</bInterval>                             <bEndpointAddress>134</bEndpointAddress>                             <bmAttributes>3</bmAttributes>                             <wMaxPacketSize>2</wMaxPacketSize>                           </Value>                           <Nodes />                         </DescriptorNode>                       </Nodes>                     </DescriptorNode>                   </Nodes>                 </DescriptorNode>                 <DescriptorNode Key="Interface1661">                   <Value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">                     <bDescriptorType>ALTERNATE</bDescriptorType>                     <bLength>0</bLength>                     <DisplayName>MacPCAudioStreamingIn</DisplayName>                   </Value>                   <Nodes>                     <DescriptorNode Key="USBDescriptor1662">                       <Value d12p1:type="CyAudioInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">                         <bDescriptorType>INTERFACE</bDescriptorType>                         <bLength>9</bLength>                         <iwInterface>1858</iwInterface>                         <bInterfaceClass>1</bInterfaceClass>                         <bInterfaceNumber>1</bInterfaceNumber>                         <bNumEndpoints>0</bNumEndpoints>                         <bInterfaceSubClass>2</bInterfaceSubClass>                         <bInterfaceProtocol>0</bInterfaceProtocol>                         <iInterface>12</iInterface>                         <sInterface>Cypress Digital Audio DVK</sInterface>                       </Value>                       <Nodes />                     </DescriptorNode>                     <DescriptorNode Key="USBDescriptor1667">                       <Value d12p1:type="CyAudioInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">                         <bDescriptorType>INTERFACE</bDescriptorType>                         <bLength>9</bLength>                         <iwInterface>947</iwInterface>                         <bInterfaceClass>1</bInterfaceClass>                         <bAlternateSetting>1</bAlternateSetting>                         <bInterfaceNumber>1</bInterfaceNumber>                         <bNumEndpoints>1</bNumEndpoints>                         <bInterfaceSubClass>2</bInterfaceSubClass>                         <bInterfaceProtocol>0</bInterfaceProtocol>                         <iInterface>8</iInterface>                         <sInterface>Active 16 bit</sInterface>                       </Value>                       <Nodes>                         <DescriptorNode Key="USBDescriptor1669">                           <Value d14p1:type="CyASGeneralDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">                             <bDescriptorType>AUDIO</bDescriptorType>                             <bLength>7</bLength>                             <bDescriptorSubtype>AS_GENERAL</bDescriptorSubtype>                             <bTerminalLink>5</bTerminalLink>                             <bDelay>1</bDelay>                             <wFormatTag>1</wFormatTag>                           </Value>                           <Nodes />                         </DescriptorNode>                         <DescriptorNode Key="USBDescriptor1670">                           <Value d14p1:type="CyASFormatType1Descriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">                             <bDescriptorType>AUDIO</bDescriptorType>                             <bLength>14</bLength>                             <bDescriptorSubtype>FORMAT_TYPE</bDescriptorSubtype>                             <bFormatType>FORMAT_TYPE_1</bFormatType>                             <bSamFreqType>2</bSamFreqType>                             <tSamFreq>                               <unsignedInt>44100</unsignedInt>                               <unsignedInt>48000</unsignedInt>                             </tSamFreq>                             <bNrChannels>2</bNrChannels>                             <bSubframeSize>2</bSubframeSize>                             <bBitResolution>16</bBitResolution>                           </Value>                           <Nodes />                         </DescriptorNode>                         <DescriptorNode Key="USBDescriptor1671">                           <Value d14p1:type="CyAudioEndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">                             <bDescriptorType>ENDPOINT</bDescriptorType>                             <bLength>9</bLength>                             <DoubleBuffer>false</DoubleBuffer>                             <bInterval>1</bInterval>                             <bEndpointAddress>130</bEndpointAddress>                             <bmAttributes>13</bmAttributes>                             <wMaxPacketSize>192</wMaxPacketSize>                           </Value>                           <Nodes>                             <DescriptorNode Key="USBDescriptor1672">                               <Value d16p1:type="CyASEndpointDescriptor" xmlns:d16p1="http://www.w3.org/2001/XMLSchema-instance">                                 <bDescriptorType>CS_ENDPOINT</bDescriptorType>                                 <bLength>7</bLength>                                 <bDescriptorSubtype>EP_GENERAL</bDescriptorSubtype>                                 <bmAttributes>1</bmAttributes>                                 <bLockDelayUnits>1</bLockDelayUnits>                                 <wLockDelay>1</wLockDelay>                               </Value>                               <Nodes />                             </DescriptorNode>                           </Nodes>                         </DescriptorNode>                       </Nodes>                     </DescriptorNode>                   </Nodes>                 </DescriptorNode>                 <DescriptorNode Key="Interface1764">                   <Value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">                     <bDescriptorType>ALTERNATE</bDescriptorType>                     <bLength>0</bLength>                     <DisplayName />                   </Value>                   <Nodes>                     <DescriptorNode Key="USBDescriptor1765">                       <Value d12p1:type="InterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">                         <bDescriptorType>INTERFACE</bDescriptorType>                         <bLength>9</bLength>                         <iwInterface>1762</iwInterface>                         <bInterfaceClass>3</bInterfaceClass>                         <bInterfaceNumber>2</bInterfaceNumber>                         <bNumEndpoints>1</bNumEndpoints>                         <bInterfaceSubClass>0</bInterfaceSubClass>                         <bInterfaceProtocol>0</bInterfaceProtocol>                         <iInterface>11</iInterface>                         <sInterface>PlaylistControl</sInterface>                       </Value>                       <Nodes>                         <DescriptorNode Key="USBDescriptor1766">                           <Value d14p1:type="EndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">                             <bDescriptorType>ENDPOINT</bDescriptorType>                             <bLength>7</bLength>                             <DoubleBuffer>false</DoubleBuffer>                             <bInterval>40</bInterval>                             <bEndpointAddress>132</bEndpointAddress>                             <bmAttributes>3</bmAttributes>                             <wMaxPacketSize>1</wMaxPacketSize>                           </Value>                           <Nodes />                         </DescriptorNode>                         <DescriptorNode Key="USBDescriptor1767">                           <Value d14p1:type="HIDDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">                             <bDescriptorType>HID</bDescriptorType>                             <bLength>9</bLength>                             <bReportIndex>1</bReportIndex>                             <wReportIndex>1744</wReportIndex>                             <bcdHID>0</bcdHID>                             <bCountryCode>0</bCountryCode>                             <bNumDescriptors>1</bNumDescriptors>                             <bDescriptorType1>34</bDescriptorType1>                             <wDescriptorLength>23</wDescriptorLength>                           </Value>                           <Nodes />                         </DescriptorNode>                       </Nodes>                     </DescriptorNode>                   </Nodes>                 </DescriptorNode>               </Nodes>             </DescriptorNode>           </Nodes>         </DescriptorNode>       </Nodes>     </DescriptorNode>   </Tree_x0020_Descriptors> </Tree>, EnableCDCApi=false, EnableMidiApi=false, endpointMA=0, endpointMM=2, extern_cls=false, extern_vnd=false, extJackCount=0, HIDReportDescriptors=<?xml version="1.0" encoding="utf-16"?> <Tree xmlns:CustomizerVersion="2_50">   <Tree_x0020_Descriptors>     <DescriptorNode Key="HIDReport">       <Nodes>         <DescriptorNode Key="USBDescriptor1744">           <Value d6p1:type="HIDReportDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>HID_REPORT</bDescriptorType>             <bLength>2</bLength>             <Name>AudioPlaybackControl</Name>             <wLength>23</wLength>           </Value>           <Nodes>             <DescriptorNode Key="USBDescriptor1745">               <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">                 <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>                 <bLength>1</bLength>                 <Item Code="4" Size="1" Type="USAGE_PAGE">                   <Description>(Consumer Devices)</Description>                   <Value>                     <unsignedByte>5</unsignedByte>                     <unsignedByte>12</unsignedByte>                   </Value>                   <Kind>List</Kind>                 </Item>               </Value>               <Nodes />             </DescriptorNode>             <DescriptorNode Key="USBDescriptor1746">               <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">                 <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>                 <bLength>1</bLength>                 <Item Code="8" Size="1" Type="USAGE">                   <Description>(Consumer Control)</Description>                   <Value>                     <unsignedByte>9</unsignedByte>                     <unsignedByte>1</unsignedByte>                   </Value>                   <Kind>List</Kind>                 </Item>               </Value>               <Nodes />             </DescriptorNode>             <DescriptorNode Key="USBDescriptor1747">               <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">                 <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>                 <bLength>1</bLength>                 <Item Code="160" Size="1" Type="COLLECTION">                   <Description>(Application)</Description>                   <Value>                     <unsignedByte>161</unsignedByte>                     <unsignedByte>1</unsignedByte>                   </Value>                   <Kind>List</Kind>                 </Item>               </Value>               <Nodes />             </DescriptorNode>             <DescriptorNode Key="USBDescriptor1748">               <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">                 <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>                 <bLength>1</bLength>                 <Item Code="20" Size="1" Type="LOGICAL_MINIMUM">                   <Description>(0)</Description>                   <Value>                     <unsignedByte>21</unsignedByte>                     <unsignedByte>0</unsignedByte>                   </Value>                   <Kind>Int</Kind>                 </Item>               </Value>               <Nodes />             </DescriptorNode>             <DescriptorNode Key="USBDescriptor1749">               <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">                 <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>                 <bLength>1</bLength>                 <Item Code="36" Size="1" Type="LOGICAL_MAXIMUM">                   <Description>(1)</Description>                   <Value>                     <unsignedByte>37</unsignedByte>                     <unsignedByte>1</unsignedByte>                   </Value>                   <Kind>Int</Kind>                 </Item>               </Value>               <Nodes />             </DescriptorNode>             <DescriptorNode Key="USBDescriptor1750">               <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">                 <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>                 <bLength>1</bLength>                 <Item Code="116" Size="1" Type="REPORT_SIZE">                   <Description>(1)</Description>                   <Value>                     <unsignedByte>117</unsignedByte>                     <unsignedByte>1</unsignedByte>                   </Value>                   <Kind>Int</Kind>                 </Item>               </Value>               <Nodes />             </DescriptorNode>             <DescriptorNode Key="USBDescriptor1751">               <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">                 <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>                 <bLength>1</bLength>                 <Item Code="148" Size="1" Type="REPORT_COUNT">                   <Description>(1)</Description>                   <Value>                     <unsignedByte>149</unsignedByte>                     <unsignedByte>1</unsignedByte>                   </Value>                   <Kind>Int</Kind>                 </Item>               </Value>               <Nodes />             </DescriptorNode>             <DescriptorNode Key="USBDescriptor1752">               <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">                 <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>                 <bLength>1</bLength>                 <Item Code="8" Size="1" Type="USAGE">                   <Description>(Play/Pause)</Description>                   <Value>                     <unsignedByte>9</unsignedByte>                     <unsignedByte>205</unsignedByte>                   </Value>                   <Kind>List</Kind>                 </Item>               </Value>               <Nodes />             </DescriptorNode>             <DescriptorNode Key="USBDescriptor1755">               <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">                 <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>                 <bLength>1</bLength>                 <Item Code="128" Size="1" Type="INPUT">                   <Description>(Var)</Description>                   <Value>                     <unsignedByte>129</unsignedByte>                     <unsignedByte>2</unsignedByte>                   </Value>                   <Kind>Bits</Kind>                 </Item>               </Value>               <Nodes />             </DescriptorNode>             <DescriptorNode Key="USBDescriptor1756">               <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">                 <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>                 <bLength>1</bLength>                 <Item Code="148" Size="1" Type="REPORT_COUNT">                   <Description>(7)</Description>                   <Value>                     <unsignedByte>149</unsignedByte>                     <unsignedByte>7</unsignedByte>                   </Value>                   <Kind>Int</Kind>                 </Item>               </Value>               <Nodes />             </DescriptorNode>             <DescriptorNode Key="USBDescriptor1757">               <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">                 <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>                 <bLength>1</bLength>                 <Item Code="128" Size="1" Type="INPUT">                   <Description>(Con)</Description>                   <Value>                     <unsignedByte>129</unsignedByte>                     <unsignedByte>1</unsignedByte>                   </Value>                   <Kind>Bits</Kind>                 </Item>               </Value>               <Nodes />             </DescriptorNode>             <DescriptorNode Key="USBDescriptor1758">               <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">                 <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>                 <bLength>1</bLength>                 <Item Code="192" Size="0" Type="END_COLLECTION">                   <Description />                   <Value>                     <unsignedByte>192</unsignedByte>                   </Value>                   <Kind>None</Kind>                 </Item>               </Value>               <Nodes />             </DescriptorNode>           </Nodes>         </DescriptorNode>       </Nodes>     </DescriptorNode>   </Tree_x0020_Descriptors> </Tree>, max_interfaces_num=3, MidiDescriptors=<?xml version="1.0" encoding="utf-16"?> <Tree xmlns:CustomizerVersion="2_50">   <Tree_x0020_Descriptors>     <DescriptorNode Key="Midi">       <Nodes />     </DescriptorNode>   </Tree_x0020_Descriptors> </Tree>, Mode=false, mon_vbus=false, out_sof=true, pfsusb=true, Pid=F232, rm_arb_int=false, rm_dma_1=true, rm_dma_2=false, rm_dma_3=true, rm_dma_4=false, rm_dma_5=true, rm_dma_6=false, rm_dma_7=true, rm_dma_8=true, rm_dp_int=false, rm_ep_isr_0=false, rm_ep_isr_1=true, rm_ep_isr_2=false, rm_ep_isr_3=true, rm_ep_isr_4=false, rm_ep_isr_5=true, rm_ep_isr_6=false, rm_ep_isr_7=true, rm_ep_isr_8=true, rm_ord_int=false, rm_sof_int=false, rm_usb_int=false, StringDescriptors=<?xml version="1.0" encoding="utf-16"?> <Tree xmlns:CustomizerVersion="2_50">   <Tree_x0020_Descriptors>     <DescriptorNode Key="String">       <Nodes>         <DescriptorNode Key="LANGID">           <Value d6p1:type="StringZeroDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>4</bLength>             <wLANGID>1033</wLANGID>           </Value>           <Nodes />         </DescriptorNode>         <DescriptorNode Key="USBDescriptor7">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>44</bLength>             <snType>USER_ENTERED_TEXT</snType>             <bString>Cypress Semiconductor</bString>             <bUsed>false</bUsed>           </Value>           <Nodes />         </DescriptorNode>         <DescriptorNode Key="USBDescriptor9">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>40</bLength>             <snType>USER_ENTERED_TEXT</snType>             <bString>CypressAudioControl</bString>             <bUsed>false</bUsed>           </Value>           <Nodes />         </DescriptorNode>         <DescriptorNode Key="USBDescriptor10">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>28</bLength>             <snType>USER_ENTERED_TEXT</snType>             <bString>ZeroBandwidth</bString>             <bUsed>false</bUsed>           </Value>           <Nodes />         </DescriptorNode>         <DescriptorNode Key="USBDescriptor50">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>22</bLength>             <snType>USER_ENTERED_TEXT</snType>             <bString>Microphone</bString>             <bUsed>false</bUsed>           </Value>           <Nodes />         </DescriptorNode>         <DescriptorNode Key="USBDescriptor51">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>16</bLength>             <snType>USER_ENTERED_TEXT</snType>             <bString>Speaker</bString>             <bUsed>false</bUsed>           </Value>           <Nodes />         </DescriptorNode>         <DescriptorNode Key="USBDescriptor52">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>28</bLength>             <snType>USER_ENTERED_TEXT</snType>             <bString>USB Streaming</bString>             <bUsed>false</bUsed>           </Value>           <Nodes />         </DescriptorNode>         <DescriptorNode Key="USBDescriptor63">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>14</bLength>             <snType>USER_ENTERED_TEXT</snType>             <bString>Active</bString>             <bUsed>false</bUsed>           </Value>           <Nodes />         </DescriptorNode>         <DescriptorNode Key="USBDescriptor947">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>28</bLength>             <snType>USER_ENTERED_TEXT</snType>             <bString>Active 16 bit</bString>             <bUsed>false</bUsed>           </Value>           <Nodes />         </DescriptorNode>         <DescriptorNode Key="USBDescriptor948">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>28</bLength>             <snType>USER_ENTERED_TEXT</snType>             <bString>Active 24 bit</bString>             <bUsed>false</bUsed>           </Value>           <Nodes />         </DescriptorNode>         <DescriptorNode Key="USBDescriptor1740">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>8</bLength>             <snType>USER_ENTERED_TEXT</snType>             <bString>Mac</bString>             <bUsed>false</bUsed>           </Value>           <Nodes />         </DescriptorNode>         <DescriptorNode Key="USBDescriptor1762">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>32</bLength>             <snType>USER_ENTERED_TEXT</snType>             <bString>PlaylistControl</bString>             <bUsed>false</bUsed>           </Value>           <Nodes />         </DescriptorNode>         <DescriptorNode Key="USBDescriptor1858">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>52</bLength>             <snType>USER_ENTERED_TEXT</snType>             <bString>Cypress Digital Audio DVK</bString>             <bUsed>false</bUsed>           </Value>           <Nodes />         </DescriptorNode>       </Nodes>     </DescriptorNode>     <DescriptorNode Key="SpecialString">       <Nodes>         <DescriptorNode Key="Serial">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>2</bLength>             <snType>SILICON_NUMBER</snType>             <bUsed>true</bUsed>           </Value>           <Nodes />         </DescriptorNode>         <DescriptorNode Key="EE">           <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">             <bDescriptorType>STRING</bDescriptorType>             <bLength>16</bLength>             <snType>USER_ENTERED_TEXT</snType>             <bString>MSFT100</bString>             <bUsed>false</bUsed>           </Value>           <Nodes />         </DescriptorNode>       </Nodes>     </DescriptorNode>   </Tree_x0020_Descriptors> </Tree>, Vid=04B4, CY_COMPONENT_NAME=USBFS_v2_50, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=USBFS, CY_INSTANCE_SHORT_NAME=USBFS, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=50, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=USBFS, )
module USBFS_v2_50_5 (
    sof);
    output      sof;


          wire [7:0] dma_req;
          wire [8:0] ept_int;
          wire  Net_1020;
          wire  Net_1019;
          wire  Net_1018;
          wire  Net_1017;
          wire  Net_1016;
          wire  Net_1015;
          wire  Net_1014;
          wire  Net_1013;
          wire  Net_79;
          wire  Net_81;
          wire  Net_95;
    electrical  Net_1000;
    electrical  Net_597;
          wire  Net_1010;
          wire  Net_824;

    cy_psoc3_usb_v1_0 USB (
        .dp(Net_1000),
        .dm(Net_597),
        .sof_int(sof),
        .arb_int(Net_79),
        .usb_int(Net_81),
        .ept_int(ept_int[8:0]),
        .ord_int(Net_95),
        .dma_req(dma_req[7:0]),
        .dma_termin(Net_824));


	cy_isr_v1_0
		#(.int_type(2'b10))
		sof_int
		 (.int_signal(sof));



	cy_isr_v1_0
		#(.int_type(2'b10))
		arb_int
		 (.int_signal(Net_79));



	cy_isr_v1_0
		#(.int_type(2'b10))
		bus_reset
		 (.int_signal(Net_81));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_0
		 (.int_signal(ept_int[0:0]));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_2
		 (.int_signal(ept_int[2:2]));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_4
		 (.int_signal(ept_int[4:4]));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_6
		 (.int_signal(ept_int[6:6]));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ord_int
		 (.int_signal(Net_95));


	wire [0:0] tmpOE__Dm_net;
	wire [0:0] tmpFB_0__Dm_net;
	wire [0:0] tmpIO_0__Dm_net;
	wire [0:0] tmpINTERRUPT_0__Dm_net;
	electrical [0:0] tmpSIOVREF__Dm_net;

	cy_psoc3_pins_v1_10
		#(.id("a3642a82-391b-436c-950f-ff2ba5f0c7f4/8b77a6c4-10a0-4390-971c-672353e2a49c"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .vtrip(2'b10),
		  .width(1))
		Dm
		 (.oe(tmpOE__Dm_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Dm_net[0:0]}),
		  .analog({Net_597}),
		  .io({tmpIO_0__Dm_net[0:0]}),
		  .siovref(tmpSIOVREF__Dm_net),
		  .interrupt({tmpINTERRUPT_0__Dm_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Dm_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Dp_net;
	wire [0:0] tmpFB_0__Dp_net;
	wire [0:0] tmpIO_0__Dp_net;
	electrical [0:0] tmpSIOVREF__Dp_net;

	cy_psoc3_pins_v1_10
		#(.id("a3642a82-391b-436c-950f-ff2ba5f0c7f4/618a72fc-5ddd-4df5-958f-a3d55102db42"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b10),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		Dp
		 (.oe(tmpOE__Dp_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Dp_net[0:0]}),
		  .analog({Net_1000}),
		  .io({tmpIO_0__Dp_net[0:0]}),
		  .siovref(tmpSIOVREF__Dp_net),
		  .interrupt({Net_1010}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Dp_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b10))
		dp_int
		 (.int_signal(Net_1010));



	cy_dma_v1_0
		#(.drq_type(2'b10))
		ep2
		 (.drq(dma_req[1:1]),
		  .trq(Net_824),
		  .nrq(Net_1019));



	cy_dma_v1_0
		#(.drq_type(2'b10))
		ep4
		 (.drq(dma_req[3:3]),
		  .trq(Net_824),
		  .nrq(Net_1017));



	cy_dma_v1_0
		#(.drq_type(2'b10))
		ep6
		 (.drq(dma_req[5:5]),
		  .trq(Net_824),
		  .nrq(Net_1015));




endmodule

// top
module top ;

    electrical  Net_3600;
    electrical  Net_3599;
    electrical  Net_3598;
    electrical  Net_3597;
    electrical  Net_3596;
    electrical  Net_3595;
    electrical  Net_3594;
    electrical  Net_3593;
    electrical  Net_3592;
    electrical  Net_3591;
    electrical  Net_3590;
    electrical  Net_3589;
    electrical  Net_3588;
    electrical  Net_3587;
    electrical  Net_3586;
          wire  Net_3546;
          wire  Net_3525;
          wire  Net_3607;
          wire  Net_3515;
          wire  Net_3555;
          wire  Net_3459;
          wire  Net_3456;
          wire  Net_3138;
          wire  Net_3137;
          wire  Net_3136;
          wire  Net_3135;
          wire  Net_3134;
          wire  Net_3133;
          wire  Net_3458;
          wire  Net_3129;
          wire  Net_3128;
          wire  Net_3513;
          wire  Net_3125;
          wire  Net_3124;
          wire  Net_3444;
          wire  I2Sclk;
          wire  Net_3526;
          wire  Net_3112;
          wire  Net_3512;
          wire  Net_3103;
          wire  Net_3102;
          wire  Net_3362;
          wire  Net_3089;
          wire  Net_3088;
          wire  Net_3116;
          wire  GenClock;
          wire  Net_3100;
          wire  Net_3443;
          wire  Net_3442;
          wire  Net_3441;
          wire  Net_3440;
          wire  Net_3439;
          wire  Net_3438;
          wire  Net_3437;
          wire  Net_3436;
          wire  Net_3435;
          wire  Net_3434;
          wire  Net_3433;
          wire  Net_3511;
          wire  Net_3510;
          wire  Net_3115;
          wire  Net_3092;
          wire  Net_3091;
          wire  Net_3099;
          wire  Net_3114;
          wire  Net_3113;
          wire  Net_3093;
          wire  Net_3096;
          wire  Net_3095;
          wire  Net_3087;
          wire  Net_3086;
          wire  Net_3085;
          wire  Net_3084;
          wire  Net_3083;
          wire  Net_3082;
          wire  Net_3097;
    electrical  Net_3585;
    electrical  Net_3584;
    electrical  Net_3583;
    electrical  Net_3582;
    electrical  Net_3581;
          wire  Net_85;
          wire  Net_3528;
          wire  Net_3506;
          wire  Net_3495;
          wire  Net_3533;
          wire  Net_2837;
          wire  Net_2731;
          wire  Net_2986;
          wire  Net_2611;
          wire  Net_2599;
          wire  Net_2161;
          wire  Net_2586;
          wire  Net_2585;
          wire  Net_3491;
          wire  Net_55;

	wire [0:0] tmpOE__PSOC_I2S_SCLK_net;
	wire [0:0] tmpFB_0__PSOC_I2S_SCLK_net;
	wire [0:0] tmpIO_0__PSOC_I2S_SCLK_net;
	wire [0:0] tmpINTERRUPT_0__PSOC_I2S_SCLK_net;
	electrical [0:0] tmpSIOVREF__PSOC_I2S_SCLK_net;

	cy_psoc3_pins_v1_10
		#(.id("f7d2f3aa-d23d-4113-af4d-7ad57d266155"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("PSOC_I2S_SCLK"),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		PSOC_I2S_SCLK
		 (.oe(tmpOE__PSOC_I2S_SCLK_net),
		  .y({Net_2585}),
		  .fb({tmpFB_0__PSOC_I2S_SCLK_net[0:0]}),
		  .io({tmpIO_0__PSOC_I2S_SCLK_net[0:0]}),
		  .siovref(tmpSIOVREF__PSOC_I2S_SCLK_net),
		  .interrupt({tmpINTERRUPT_0__PSOC_I2S_SCLK_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PSOC_I2S_SCLK_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    I2S_v2_40 I2S (
        .clock(I2Sclk),
        .sdi(1'b0),
        .sck(Net_2585),
        .ws(Net_2586),
        .sdo(Net_2161),
        .rx_dma0(Net_3083),
        .rx_dma1(Net_3084),
        .tx_dma0(Net_3491),
        .tx_dma1(Net_3085),
        .rx_interrupt(Net_3086),
        .tx_interrupt(Net_3087));
    defparam I2S.DataBits = 24;
    defparam I2S.Direction = 2;
    defparam I2S.InterruptSource = 0;
    defparam I2S.RxDataInterleaving = 1;
    defparam I2S.RxDMA_present = 1;
    defparam I2S.TxDataInterleaving = 1;
    defparam I2S.TxDMA_present = 1;
    defparam I2S.WordSelect = 64;

    // -- DFF Start --
    reg  cydff_1;
    always @(posedge Net_3096)
    begin
        cydff_1 <= GenClock;
    end
    assign Net_3095 = cydff_1;
    // -- DFF End --

    AudioClkGen_v0_83_0 AudioClkGen (
        .clk(Net_3093),
        .sync(Net_3097),
        .clkout(GenClock),
        .Mclk(Net_55),
        .I2Sclk(I2Sclk));


	cy_clock_v1_0
		#(.id("e6671276-928b-43c3-9ec6-182c8cabd129"),
		  .source_clock_id("CEF43CFB-0213-49b9-B980-2FFAB81C5B47"),
		  .divisor(1),
		  .period("0"),
		  .is_direct(0),
		  .is_digital(1))
		AudioClkGen_Ref
		 (.clock_out(Net_3093));



	cy_clock_v1_0
		#(.id("558cc633-7774-4147-a97d-c1456e6976c2"),
		  .source_clock_id("315365C3-2E3E-4f04-84A2-BB564A173261"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		ClkGenOut_Sync
		 (.clock_out(Net_3096));


	wire [0:0] tmpOE__PSOC_CODEC_RST_net;
	wire [0:0] tmpFB_0__PSOC_CODEC_RST_net;
	wire [0:0] tmpIO_0__PSOC_CODEC_RST_net;
	wire [0:0] tmpINTERRUPT_0__PSOC_CODEC_RST_net;
	electrical [0:0] tmpSIOVREF__PSOC_CODEC_RST_net;

	cy_psoc3_pins_v1_10
		#(.id("c1dfc243-c1c4-407d-ba37-2456232eae7b"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("PSOC_CODEC_RST"),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		PSOC_CODEC_RST
		 (.oe(tmpOE__PSOC_CODEC_RST_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__PSOC_CODEC_RST_net[0:0]}),
		  .io({tmpIO_0__PSOC_CODEC_RST_net[0:0]}),
		  .siovref(tmpSIOVREF__PSOC_CODEC_RST_net),
		  .interrupt({tmpINTERRUPT_0__PSOC_CODEC_RST_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PSOC_CODEC_RST_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_dma_v1_0
		#(.drq_type(2'b01))
		TxDMA
		 (.drq(Net_2986),
		  .trq(1'b0),
		  .nrq(Net_2611));



	cy_isr_v1_0
		#(.int_type(2'b10))
		isr_TxDMADone
		 (.int_signal(Net_2611));


	wire [0:0] tmpOE__PSOC_I2S_SDTO_net;
	wire [0:0] tmpFB_0__PSOC_I2S_SDTO_net;
	wire [0:0] tmpIO_0__PSOC_I2S_SDTO_net;
	wire [0:0] tmpINTERRUPT_0__PSOC_I2S_SDTO_net;
	electrical [0:0] tmpSIOVREF__PSOC_I2S_SDTO_net;

	cy_psoc3_pins_v1_10
		#(.id("3312e0d1-b0a2-4761-9233-a556b3401f39"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("PSOC_I2S_SDTO"),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		PSOC_I2S_SDTO
		 (.oe(tmpOE__PSOC_I2S_SDTO_net),
		  .y({Net_2161}),
		  .fb({tmpFB_0__PSOC_I2S_SDTO_net[0:0]}),
		  .io({tmpIO_0__PSOC_I2S_SDTO_net[0:0]}),
		  .siovref(tmpSIOVREF__PSOC_I2S_SDTO_net),
		  .interrupt({tmpINTERRUPT_0__PSOC_I2S_SDTO_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PSOC_I2S_SDTO_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b10))
		isr_InDMADone
		 (.int_signal(Net_2599));



	cy_dma_v1_0
		#(.drq_type(2'b10))
		USBInDMA
		 (.drq(1'b0),
		  .trq(1'b0),
		  .nrq(Net_2599));



	cy_clock_v1_0
		#(.id("ce04e8f0-4581-4db1-9e4c-5a43b7a885fe"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		SyncClock_Tx
		 (.clock_out(Net_2837));


	wire [0:0] tmpOE__PSOC_I2S_MCLK_net;
	wire [0:0] tmpFB_0__PSOC_I2S_MCLK_net;
	wire [0:0] tmpIO_0__PSOC_I2S_MCLK_net;
	wire [0:0] tmpINTERRUPT_0__PSOC_I2S_MCLK_net;
	electrical [0:0] tmpSIOVREF__PSOC_I2S_MCLK_net;

	cy_psoc3_pins_v1_10
		#(.id("8843558f-8028-4242-b419-20e93446a62f"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("PSOC_I2S_MCLK"),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		PSOC_I2S_MCLK
		 (.oe(tmpOE__PSOC_I2S_MCLK_net),
		  .y({Net_55}),
		  .fb({tmpFB_0__PSOC_I2S_MCLK_net[0:0]}),
		  .io({tmpIO_0__PSOC_I2S_MCLK_net[0:0]}),
		  .siovref(tmpSIOVREF__PSOC_I2S_MCLK_net),
		  .interrupt({tmpINTERRUPT_0__PSOC_I2S_MCLK_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PSOC_I2S_MCLK_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_clock_v1_0
		#(.id("98516190-ad4b-4900-934a-2fc3baba0706"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_1
		 (.clock_out(Net_3510));


    I2C_v3_30_1 I2C_Master (
        .sda(Net_3433),
        .scl(Net_3434),
        .clock(1'b0),
        .reset(1'b0),
        .bclk(Net_3437),
        .iclk(Net_3438),
        .scl_i(1'b0),
        .sda_i(1'b0),
        .scl_o(Net_3441),
        .sda_o(Net_3442),
        .itclk(Net_3443));

	wire [0:0] tmpOE__SCL_net;
	wire [0:0] tmpFB_0__SCL_net;
	wire [0:0] tmpINTERRUPT_0__SCL_net;
	electrical [0:0] tmpSIOVREF__SCL_net;

	cy_psoc3_pins_v1_10
		#(.id("02f2cf2c-2c7a-49df-9246-7a3435c21be3"),
		  .drive_mode(3'b100),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("I2C_SCL"),
		  .pin_mode("B"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		SCL
		 (.oe(tmpOE__SCL_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__SCL_net[0:0]}),
		  .io({Net_3434}),
		  .siovref(tmpSIOVREF__SCL_net),
		  .interrupt({tmpINTERRUPT_0__SCL_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SCL_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_clock_v1_0
		#(.id("de3529db-ffe7-41ec-9b56-87e7285a8018"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		ByteSwapClock_Tx
		 (.clock_out(Net_3100));



	cy_dma_v1_0
		#(.drq_type(2'b10))
		USBOutDMA
		 (.drq(1'b0),
		  .trq(1'b0),
		  .nrq(Net_3362));


	wire [0:0] tmpOE__PSOC_SW_net;
	wire [0:0] tmpFB_0__PSOC_SW_net;
	wire [0:0] tmpIO_0__PSOC_SW_net;
	wire [0:0] tmpINTERRUPT_0__PSOC_SW_net;
	electrical [0:0] tmpSIOVREF__PSOC_SW_net;

	cy_psoc3_pins_v1_10
		#(.id("1425177d-0d0e-4468-8bcc-e638e5509a9b"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("PLAYBACK_SW"),
		  .pin_mode("I"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		PSOC_SW
		 (.oe(tmpOE__PSOC_SW_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__PSOC_SW_net[0:0]}),
		  .io({tmpIO_0__PSOC_SW_net[0:0]}),
		  .siovref(tmpSIOVREF__PSOC_SW_net),
		  .interrupt({tmpINTERRUPT_0__PSOC_SW_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PSOC_SW_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__PSOC_STATUS_LED_net;
	wire [0:0] tmpFB_0__PSOC_STATUS_LED_net;
	wire [0:0] tmpIO_0__PSOC_STATUS_LED_net;
	wire [0:0] tmpINTERRUPT_0__PSOC_STATUS_LED_net;
	electrical [0:0] tmpSIOVREF__PSOC_STATUS_LED_net;

	cy_psoc3_pins_v1_10
		#(.id("8f03eb16-8645-4ee8-94d5-5667785fdbee"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("PSOC_STATUS"),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		PSOC_STATUS_LED
		 (.oe(tmpOE__PSOC_STATUS_LED_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__PSOC_STATUS_LED_net[0:0]}),
		  .io({tmpIO_0__PSOC_STATUS_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__PSOC_STATUS_LED_net),
		  .interrupt({tmpINTERRUPT_0__PSOC_STATUS_LED_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PSOC_STATUS_LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    SleepTimer_v3_20_2 SystemTickTimer (
        .interrupt(Net_3528));


	cy_isr_v1_0
		#(.int_type(2'b10))
		isr_Tick
		 (.int_signal(Net_3528));


	wire [0:0] tmpOE__SDA_net;
	wire [0:0] tmpFB_0__SDA_net;
	wire [0:0] tmpINTERRUPT_0__SDA_net;
	electrical [0:0] tmpSIOVREF__SDA_net;

	cy_psoc3_pins_v1_10
		#(.id("22863ebe-a37b-476f-b252-6e49a8c00b12"),
		  .drive_mode(3'b100),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("I2C_SDA"),
		  .pin_mode("B"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		SDA
		 (.oe(tmpOE__SDA_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__SDA_net[0:0]}),
		  .io({Net_3433}),
		  .siovref(tmpSIOVREF__SDA_net),
		  .interrupt({tmpINTERRUPT_0__SDA_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SDA_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__PSOC_I2S_LRCLK_net;
	wire [0:0] tmpFB_0__PSOC_I2S_LRCLK_net;
	wire [0:0] tmpIO_0__PSOC_I2S_LRCLK_net;
	wire [0:0] tmpINTERRUPT_0__PSOC_I2S_LRCLK_net;
	electrical [0:0] tmpSIOVREF__PSOC_I2S_LRCLK_net;

	cy_psoc3_pins_v1_10
		#(.id("f110f600-1aee-49c0-bbad-738496221ccc"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("PSOC_I2S_LRCLK"),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		PSOC_I2S_LRCLK
		 (.oe(tmpOE__PSOC_I2S_LRCLK_net),
		  .y({Net_2586}),
		  .fb({tmpFB_0__PSOC_I2S_LRCLK_net[0:0]}),
		  .io({tmpIO_0__PSOC_I2S_LRCLK_net[0:0]}),
		  .siovref(tmpSIOVREF__PSOC_I2S_LRCLK_net),
		  .interrupt({tmpINTERRUPT_0__PSOC_I2S_LRCLK_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PSOC_I2S_LRCLK_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_dma_v1_0
		#(.drq_type(2'b01))
		I2S_Tx_DMA
		 (.drq(Net_3491),
		  .trq(1'b0),
		  .nrq(Net_3103));


	wire [0:0] tmpOE__PSOC_PDM_DataIn_net;
	wire [0:0] tmpIO_0__PSOC_PDM_DataIn_net;
	wire [0:0] tmpINTERRUPT_0__PSOC_PDM_DataIn_net;
	electrical [0:0] tmpSIOVREF__PSOC_PDM_DataIn_net;

	cy_psoc3_pins_v1_10
		#(.id("4c15b41e-e284-4978-99e7-5aaee19bd0ce"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("PDM_DATA"),
		  .pin_mode("I"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		PSOC_PDM_DataIn
		 (.oe(tmpOE__PSOC_PDM_DataIn_net),
		  .y({1'b0}),
		  .fb({Net_3512}),
		  .io({tmpIO_0__PSOC_PDM_DataIn_net[0:0]}),
		  .siovref(tmpSIOVREF__PSOC_PDM_DataIn_net),
		  .interrupt({tmpINTERRUPT_0__PSOC_PDM_DataIn_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PSOC_PDM_DataIn_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    ByteSwap_v1_10 ByteSwap_Tx (
        .Clock(Net_3100),
        .InDMA(Net_2731),
        .OutDMA(Net_3112));

    cy_sync_v1_0 TX_Sync (
        .s_in(Net_2731),
        .clock(Net_2837),
        .s_out(Net_2986));
    defparam TX_Sync.SignalWidth = 1;


	cy_clock_v1_0
		#(.id("348f384c-e486-4fca-8edd-5218df4eedac"),
		  .source_clock_id("39D5E4C2-EBFC-44ab-AE3D-19F9BBFD674D"),
		  .divisor(2),
		  .period("0"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_CIC
		 (.clock_out(Net_3495));



	cy_dma_v1_0
		#(.drq_type(2'b01))
		CICOut_L
		 (.drq(Net_85),
		  .trq(1'b0),
		  .nrq(Net_3125));



	cy_isr_v1_0
		#(.int_type(2'b01))
		isr_CICOverflow
		 (.int_signal(Net_3513));



	cy_dma_v1_0
		#(.drq_type(2'b01))
		CICOut_R
		 (.drq(Net_3506),
		  .trq(1'b0),
		  .nrq(Net_3129));


	wire [0:0] tmpOE__PSOC_PDM_ClkOut_net;
	wire [0:0] tmpFB_0__PSOC_PDM_ClkOut_net;
	wire [0:0] tmpIO_0__PSOC_PDM_ClkOut_net;
	wire [0:0] tmpINTERRUPT_0__PSOC_PDM_ClkOut_net;
	electrical [0:0] tmpSIOVREF__PSOC_PDM_ClkOut_net;

	cy_psoc3_pins_v1_10
		#(.id("290d805b-147c-4325-9daf-32135f4cc796"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("PDM_CLOCK"),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		PSOC_PDM_ClkOut
		 (.oe(tmpOE__PSOC_PDM_ClkOut_net),
		  .y({Net_3458}),
		  .fb({tmpFB_0__PSOC_PDM_ClkOut_net[0:0]}),
		  .io({tmpIO_0__PSOC_PDM_ClkOut_net[0:0]}),
		  .siovref(tmpSIOVREF__PSOC_PDM_ClkOut_net),
		  .interrupt({tmpINTERRUPT_0__PSOC_PDM_ClkOut_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PSOC_PDM_ClkOut_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    DFB_v1_20_3 Droop_Filter (
        .interrupt(Net_3133),
        .in_1(1'b0),
        .in_2(1'b0),
        .out_1(Net_3136),
        .out_2(Net_3137),
        .dma_req_a(Net_3533),
        .dma_req_b(Net_3138));


	cy_dma_v1_0
		#(.drq_type(2'b10))
		RxDMA
		 (.drq(Net_3533),
		  .trq(1'b0),
		  .nrq(Net_3555));



	cy_isr_v1_0
		#(.int_type(2'b10))
		isr_RxDMADone
		 (.int_signal(Net_3555));


	wire [0:0] tmpOE__PSOC_PDM_LR_SEL_net;
	wire [0:0] tmpFB_0__PSOC_PDM_LR_SEL_net;
	wire [0:0] tmpIO_0__PSOC_PDM_LR_SEL_net;
	wire [0:0] tmpINTERRUPT_0__PSOC_PDM_LR_SEL_net;
	electrical [0:0] tmpSIOVREF__PSOC_PDM_LR_SEL_net;

	cy_psoc3_pins_v1_10
		#(.id("f52a568d-72ba-4243-acda-5d6586ce9c05"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("PDM_LR_SELECT"),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		PSOC_PDM_LR_SEL
		 (.oe(tmpOE__PSOC_PDM_LR_SEL_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__PSOC_PDM_LR_SEL_net[0:0]}),
		  .io({tmpIO_0__PSOC_PDM_LR_SEL_net[0:0]}),
		  .siovref(tmpSIOVREF__PSOC_PDM_LR_SEL_net),
		  .interrupt({tmpINTERRUPT_0__PSOC_PDM_LR_SEL_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PSOC_PDM_LR_SEL_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    PDM_CIC_v2_0_4 PDM_CIC (
        .pdm_data(Net_3512),
        .bus_clk(Net_3510),
        .clk_int(Net_3495),
        .pdm_clk(Net_3458),
        .data_ready_l(Net_85),
        .interrupt_ov(Net_3513),
        .data_ready_r(Net_3506),
        .dbg_enable(Net_3515),
        .clk_comb(Net_3495));
    defparam PDM_CIC.ClockingFactor = 0;
    defparam PDM_CIC.ConfigureCombClock = 0;
    defparam PDM_CIC.DecimationRate = 32;
    defparam PDM_CIC.InterruptOnFifoOverflow = 1;
    defparam PDM_CIC.Left_Remove = 0;
    defparam PDM_CIC.MicrophoneChannel = 2;
    defparam PDM_CIC.ShiftCount = 3;
    defparam PDM_CIC.ShiftDirection = 0;

    cy_annotation_universal_v1_0 PWR_1 (
        .connect({
            Net_3584
        })
    );
    defparam PWR_1.comp_name = "Power_v1_0";
    defparam PWR_1.port_names = "T1";
    defparam PWR_1.width = 1;

    cy_annotation_universal_v1_0 PDM_Mic (
        .connect({
            Net_3581,
            Net_3590,
            Net_3591,
            Net_3592,
            Net_3593,
            Net_3594,
            Net_3595,
            Net_3596,
            Net_3597,
            Net_3598,
            Net_3599,
            Net_3582,
            Net_3600,
            Net_3583,
            Net_3584,
            Net_3585,
            Net_3586,
            Net_3587,
            Net_3588,
            Net_3589
        })
    );
    defparam PDM_Mic.comp_name = "Connector20_v1_0";
    defparam PDM_Mic.port_names = "T1, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T2, T20, T3, T4, T5, T6, T7, T8, T9";
    defparam PDM_Mic.width = 20;

    cy_annotation_universal_v1_0 GND_1 (
        .connect({
            Net_3585
        })
    );
    defparam GND_1.comp_name = "Gnd_v1_0";
    defparam GND_1.port_names = "T1";
    defparam GND_1.width = 1;

    USBFS_v2_50_5 USBFS (
        .sof(Net_3097));


    cy_psoc3_digital_sentinel_v1_0 GenClock__sentinel (.watch(GenClock));

endmodule

