-- Copyright (C) 2016  Intel Corporation. All rights reserved.
-- Your use of Intel Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Intel Program License 
-- Subscription Agreement, the Intel Quartus Prime License Agreement,
-- the Intel MegaCore Function License Agreement, or other 
-- applicable license agreement, including, without limitation, 
-- that your use is for the sole purpose of programming logic 
-- devices manufactured by Intel and sold by Intel or its 
-- authorized distributors.  Please refer to the applicable 
-- agreement for further details.

-- ***************************************************************************
-- This file contains a Vhdl test bench template that is freely editable to   
-- suit user's needs .Comments are provided in each section to help the user  
-- fill out necessary details.                                                
-- ***************************************************************************
-- Generated on "06/06/2017 17:49:36"
                                                            
-- Vhdl Test Bench template for design  :  sumAdder
-- 
-- Simulation tool : ModelSim-Altera (VHDL)
-- 

LIBRARY ieee;                                               
USE ieee.std_logic_1164.all;                                

ENTITY sumAdder_vhd_tst IS
END sumAdder_vhd_tst;
ARCHITECTURE sumAdder_arch OF sumAdder_vhd_tst IS
-- constants                                                 
-- signals                                                   
SIGNAL A : STD_LOGIC;
SIGNAL A0 : STD_LOGIC;
SIGNAL B : STD_LOGIC;
SIGNAL B0 : STD_LOGIC;
SIGNAL carryCanBe0 : STD_LOGIC;
SIGNAL carryCanBe1 : STD_LOGIC;
SIGNAL carryIN : STD_LOGIC;
SIGNAL carryOUt : STD_LOGIC;
SIGNAL sum0 : STD_LOGIC;
SIGNAL sum1 : STD_LOGIC;
COMPONENT sumAdder
	PORT (
	A : IN STD_LOGIC;
	A0 : IN STD_LOGIC;
	B : IN STD_LOGIC;
	B0 : IN STD_LOGIC;
	carryCanBe0 : IN STD_LOGIC;
	carryCanBe1 : IN STD_LOGIC;
	carryIN : IN STD_LOGIC;
	carryOUt : OUT STD_LOGIC;
	sum0 : OUT STD_LOGIC;
	sum1 : OUT STD_LOGIC
	);
END COMPONENT;
BEGIN
	i1 : sumAdder
	PORT MAP (
-- list connections between master ports and signals
	A => A,
	A0 => A0,
	B => B,
	B0 => B0,
	carryCanBe0 => carryCanBe0,
	carryCanBe1 => carryCanBe1,
	carryIN => carryIN,
	carryOUt => carryOUt,
	sum0 => sum0,
	sum1 => sum1
	);
init : PROCESS                                               
-- variable declarations                                     
BEGIN                                                        
	
	-- carryIN  wird immer auf null gesetzt, sowie carryCanBe0 und carryCanBe1   
	-- 
	
	carryIN <= '0';
	A0 <= '0';
	B0 <= '0';
	A <= '0';
	B <= '0';
	carryCanBe0 <= '0';
	carryCanBe1 <= '1';
	wait for 20 ns;
	
	carryIN <= '0';
	A0 <= '1';
	B0 <= '0';
	A <= '0';
	B <= '0';
	carryCanBe0 <= '0';
	carryCanBe1 <= '1';
	wait for 20 ns;
	
	carryIN <= '0';
	A0 <= '0';
	B0 <= '1';
	A <= '0';
	B <= '0';
	carryCanBe0 <= '0';
	carryCanBe1 <= '1';
	wait for 20 ns;
	
	carryIN <= '0';
	A0 <= '1';
	B0 <= '1';
	A <= '0';
	B <= '0';
	carryCanBe0 <= '0';
	carryCanBe1 <= '1';
	wait for 20 ns;
	
	carryIN <= '0';
	A0 <= '0';
	B0 <= '0';
	A <= '1';
	B <= '0';
	carryCanBe0 <= '0';
	carryCanBe1 <= '1';
	wait for 20 ns;
	
	carryIN <= '0';
	A0 <= '1';
	B0 <= '0';
	A <= '1';
	B <= '0';
	carryCanBe0 <= '0';
	carryCanBe1 <= '1';
	wait for 20 ns;
	
	carryIN <= '0';
	A0 <= '0';
	B0 <= '1';
	A <= '1';
	B <= '0';
	carryCanBe0 <= '0';
	carryCanBe1 <= '1';
	wait for 20 ns;
	
	carryIN <= '0';
	A0 <= '1';
	B0 <= '1';
	A <= '1';
	B <= '0';
	carryCanBe0 <= '0';
	carryCanBe1 <= '1';
	wait for 20 ns;
	
	carryIN <= '0';
	A0 <= '0';
	B0 <= '0';
	A <= '0';
	B <= '1';
	carryCanBe0 <= '0';
	carryCanBe1 <= '1';
	wait for 20 ns;
	
	carryIN <= '0';
	A0 <= '1';
	B0 <= '0';
	A <= '0';
	B <= '1';
	carryCanBe0 <= '0';
	carryCanBe1 <= '1';
	wait for 20 ns;
	
	carryIN <= '0';
	A0 <= '0';
	B0 <= '1';
	A <= '0';
	B <= '1';
	carryCanBe0 <= '0';
	carryCanBe1 <= '1';
	wait for 20 ns;
	
	carryIN <= '0';
	A0 <= '1';
	B0 <= '1';
	A <= '0';
	B <= '1';
	carryCanBe0 <= '0';
	carryCanBe1 <= '1';
	wait for 20 ns;
	
	carryIN <= '0';
	A0 <= '0';
	B0 <= '0';
	A <= '1';
	B <= '1';
	carryCanBe0 <= '0';
	carryCanBe1 <= '1';
	wait for 20 ns;
	
	carryIN <= '0';
	A0 <= '1';
	B0 <= '0';
	A <= '1';
	B <= '1';
	carryCanBe0 <= '0';
	carryCanBe1 <= '1';
	wait for 20 ns;
	
	carryIN <= '0';
	A0 <= '1';
	B0 <= '1';
	A <= '1';
	B <= '1';
	carryCanBe0 <= '0';
	carryCanBe1 <= '1';
	wait for 20 ns;
		  
WAIT;                                                       
END PROCESS init;                                           
always : PROCESS                                              
-- optional sensitivity list                                  
-- (        )                                                 
-- variable declarations                                      
BEGIN                                                         
        -- code executes for every event on sensitivity list  
WAIT;                                                        
END PROCESS always;                                          
END sumAdder_arch;
